#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;

int main() {
    char sourceFile[100];
    char destFile[100];

    cout << "Enter source file name: ";
    cin >> sourceFile;

    cout << "Enter destination file name: ";
    cin >> destFile;

    // Open source file in read-only mode
    int srcFd = open(sourceFile, O_RDONLY);
    if (srcFd < 0) {
        cerr << "Error opening source file!" << endl;
        return 1;
    }

    // Open/create destination file in write-only mode
    int destFd = open(destFile, O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (destFd < 0) {
        cerr << "Error creating destination file!" << endl;
        close(srcFd);
        return 1;
    }

    char buffer[512];
    int bytesRead;

    // Copy contents from source to destination
    while ((bytesRead = read(srcFd, buffer, sizeof(buffer))) > 0) {
        write(destFd, buffer, bytesRead);
    }

    cout << "File copied successfully from " << sourceFile << " to " << destFile << endl;

    close(srcFd);
    close(destFd);
    return 0;
}