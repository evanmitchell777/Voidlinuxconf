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

    return 0;
}
