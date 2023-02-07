#include<iostream>
#include<fstream>
int main(){
    std::string n;
    int p;
    std::fstream userFile{"user.txt"};
    if(!userFile){
        std::cerr<<"no file\n";
        return 1;
    }
    while(!userFile.eof()){
        userFile>>n>>p;
        std::cout<<p<<"\n"<<"\n";
        p=p+1;
        userFile.seekp(-3,std::ios::cur);
        userFile<<p<<"\n";
    }
    
    userFile.close();
    return 0;
    }