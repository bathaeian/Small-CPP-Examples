#include<iostream>
#include<algorithm>
#include<fstream>
#include<map>
class User{private:int point;std::string name;
    public:User(std::string n="",int a=0):point(a),name(n){};
    int getPoint()const{return point;}
    std::string getName()const{return name;}};

int main(){
    std::map<std::string,User> m;
    std::string n;
        int p;
    std::fstream userFile{"user.txt",std::ios::in};
    if(userFile){
        userFile>>n>>p;
        while(!userFile.eof()){
            User u(n,p);
            m.insert(std::make_pair(n,u));
            userFile>>n>>p;
        }
    }
    userFile.close();
    std::cout<<"\nnew user?";
    std::cin>>n;
    User u(n);
    //play game
    m[n]=u;
    std::cout<<"\nmap:";
    std::for_each(m.cbegin(),m.cend(),[](auto a){std::cout<<a.first<<"*"<<a.second.getPoint()<<"**";});
    userFile.open("user.txt",std::ios::out);
    if(userFile){
        std::for_each(m.cbegin(),m.cend(),[&userFile](auto a){userFile<<a.first<<' '<<a.second.getPoint()<<"\n";});
    }
}