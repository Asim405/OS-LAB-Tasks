#include <iostream>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main() {
    cout << "Initial Main Process PID: " << getpid() << endl;
    cout << "------------------------------------" << endl;

    // First fork
    pid_t pid1 = fork();

    // Second fork
    pid_t pid2 = fork();

    // Print process information for every active process created
    cout << "Process ID (PID): " << getpid() 
         << " | Parent Process ID (PPID): " << getppid() << endl;

    return 0;
}