#include <iostream>
#include <fstream>
#include <errno.h>
// extern int errno;

using namespace std;

void getSource(char* source) {
    printf("Path of source: ");
    scanf("%119s", source);
}

void getDestination(char* dest) {
    printf("Path of destination: ");
    scanf("%119s", dest);
}

int main() {
    char data;
    char source[120], dest[120];
    ifstream sourceStream;
    ofstream destinationStream;

    getSource(source);
    sourceStream.open(source, ios::in);

    if(!sourceStream) {
        perror("Couldn't open file for reading");
        return 1;
    }

    getDestination(dest);
    destinationStream.open(dest, ios::out);

    if(!destinationStream) {
        perror("Couldn't open file for writing");
        return 1;
    }

    while(!sourceStream.eof()) {
        sourceStream >> noskipws >> data;
        destinationStream << data;
    }

    sourceStream.close();
    destinationStream.close();
    
 

    printf("Program Completed.\n");
    return 0;
}