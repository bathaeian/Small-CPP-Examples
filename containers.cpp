#include<iostream>
#include<algorithm>
#include<list>
#include<set>
#include<map>
class AA{private:int x;
    public:AA(int a):x(a){};
    int getX()const{return x;}};
class BB{friend std::ostream& operator<<(std::ostream& , const BB&);
    private:int y; AA a;
    public:BB(int b,int c):y(b),a(c){};
    bool operator==(const BB &q)const{return a.getX()==q.a.getX();}
    bool operator<(const BB &q)const{return a.getX()<q.a.getX();}
    };
std::ostream& operator<<(std::ostream& c, const BB& b){
    c<<"("<<b.a.getX()<<","<<b.y<<")";
    return c;
}
int main(){
    std::list<BB> l;
    std::set<BB,std::less<const BB &>> s;
    std::map<int,BB,std::less<int>> m;
    BB w(1,2),r(3,4),t(5,6);
    l.push_back(w);
    l.push_front(r);
    l.insert(l.cbegin(),t);
    std::cout<<"\nlist:";
    std::for_each(l.cbegin(),l.cend(),[](BB a){std::cout<<a;});
    s.insert(w);
    s.insert(w);
    std::cout<<"\nset:";
    std::for_each(s.cbegin(),s.cend(),[](BB a){std::cout<<a<<"*****";});
    m.insert({10,w});
    m.insert(std::make_pair(20,r));
    //m[15]=t;
    std::cout<<"\nmap:";
    std::for_each(m.cbegin(),m.cend(),[](std::pair<int,BB> a){std::cout<<a.first<<"*"<<a.second<<"**";});





}
