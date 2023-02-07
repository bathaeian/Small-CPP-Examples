#include <iostream>
#include<iterator>
#include<vector>
#include<array>

//using namespace std;


int main()
{
    std::istream_iterator<int> i1;
    std::istream_iterator<int> i3;
    std::ostream_iterator<int> i2(std::cout,"*");
    i1=std::cin;
    i3=i1;
    /*for(int i=0;i<5;  i++){
        int x=*i1;
        i2=x;
        i1=std::cin;
    }*/
    std::vector<int>::iterator i4;
    std::vector<int> v1(0);//size
    std::vector<int> v2={1,2,3,4};
    std::vector<int> v3(v2);
    int a[4]={5,6,7,8};
    std::vector<int> v4(a,a+4);
    std::copy(v1.cbegin(),v1.cend(),i2);
    std::copy(v2.cbegin(),v2.cend(),i2);
    std::copy(v3.cbegin(),v3.cend(),i2);
    std::copy(v4.cbegin(),v4.cend(),i2);
    std::vector<int> v5(4);
    std::array<int,4> b={12,13,14,15};
    std::copy(b.cbegin(),b.cend(),v5.begin());
    std::copy(v5.cbegin(),v5.cend(),i2);
    return 0;
}
