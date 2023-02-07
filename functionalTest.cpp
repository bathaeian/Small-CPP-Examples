#include<iostream>
#include<algorithm>
#include<vector>

class Point{
    friend bool operator<(const Point &, const Point &);
    private: int x,y;
    public: 
        Point(int a=0,int b=0):x(a),y(b){}
        std::string toString(){return "x="+std::to_string(x)+" y="+std::to_string(y)+"\n";}
};
bool operator<(const Point &p1,const Point &p2){return p1.x<p2.x;}
        
int main(){
    std::vector<Point> ps;
    for(int i=0;i<10;i++){
        Point p1(rand()%10,rand()%10);
        ps.push_back(p1);
    }
    std::cout<<"\nbefore sort\n";
    std::for_each(ps.cbegin(),ps.cend(),[](Point p1){std::cout<<p1.toString();});
    std::sort(ps.begin(),ps.end(),std::less<Point>());
    std::cout<<"\nafter sort\n";
    std::for_each(ps.cbegin(),ps.cend(),[](Point p1){std::cout<<p1.toString();});

}