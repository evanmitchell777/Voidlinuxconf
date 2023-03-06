#include <iostream>
#include <cstdlib> 
#include <cstring>
#include <string>

using namespace std;

//this updates everything before the script starts
void system_update(string password){
    string command = "echo \"" + password + "\" | sudo -S xbps-install -Su";
    system(command.c_str());
}

void intsall_polybar_theme(){
    system("git clone --depth=1 https://github.com/adi1090x/polybar-themes.git");
}

//this function will install all the programs I use on my setup.
void install_programs(string password) {
    string command = "echo \"" + password + "\" | sudo -S xbps-install polybar neofetch rxvt-unicode i3-gaps neovim firefox pipewire NetworkManager xclip xorg xorg-server";
    system(command.c_str());
}

//this function will move the config files I use to the correct directory. 
void move_config_files(){
    system("mv /home/abraxas/Downloads/config/.Xresources /home/abraxas");
    system("mv /home/abraxas/Downloads/config/.xinitrc /home/abraxas/.xinitrc");
    system("mv /home/abraxas/Downloads/config/.Xauthority /home/abraxas");
    system("mv /home/abraxas/Downloads/config/.bashrc /home/abraxas");
}

void create_directories(){
    system("mkdir wallpapers");
    system("mkdir .config");
}

void general_setup(string password){
    string command = "echo \"" + password + "\" | sudo ln -s /etc/sv/elogind /var/service";
    system(command.c_str());
    command = "echo \"" + password + "\" | sudo sv up dbus";
    system(command.c_str());
    command = "echo \"" + password + "\" | sudo sv up slogind";
    system(command.c_str());
}

void reboot_system(string password){
    string command = "echo \"" + password + "\" | sudo reboot";
    system(command.c_str());
}

int main(){
    cout<<"Enter your system password: ";
    string password;
    cin>> password;
    system_update(password);
    intsall_polybar_theme();
    install_programs(password);
    move_config_files();
    create_directories();
    general_setup(password);
    reboot_system(password);
    return 0;
}
