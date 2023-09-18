#include <iostream>
#include <string>
#include <unistd.h>
#include <thread>

void run_palera1n() {
    const char* command = "sudo palera1n";
    system(command);
}

void usbmuxd() {
    const char* command = "sudo usbmuxd -f -p";
    system(command);
}

int main() {
    std::thread thread1(run_palera1n);
    std::thread thread2(usbmuxd);

    thread1.join();
    thread2.join();

    std::cout << "Enter the PID to kill: ";
    int pid;
    std::cin >> pid;

    // Construct the kill command
    std::string kill_command = "sudo kill -9 " + std::to_string(pid);

    // Run the kill command
    int kill_result = system(kill_command.c_str());

    if (kill_result == 0) {
        std::cout << "Process with PID " << pid << " successfully killed." << std::endl;
    } else {
        std::cout << "Failed to kill process with PID " << pid << ". Error code: " << kill_result << std::endl;
    }

    return 0;
}
