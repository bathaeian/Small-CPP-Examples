#include <iostream>
#include<vector>
#include<algorithm>
int main()
{
    std::vector<int> v={1,2,3,4};
    std::cout<<"\nv\n";
    std::for_each(v.cbegin(),v.cend(),[](int a){std::cout<<a<<"*";});
    //copy constructor
    std::vector<int> v2(v);
    std::cout<<"\nv2\n";
    std::for_each(v2.cbegin(),v2.cend(),[](int a){std::cout<<a<<"*";});
    //=
    std::vector<int> v3=v;
    std::cout<<"\nv3\n";
    std::for_each(v3.cbegin(),v3.cend(),[](int a){std::cout<<a<<"*";});
    //relational
    std::cout<<"\n"<<(v2==v3);
    //size
    std::cout<<"\n"<<v.size()<<"***"<<v.max_size();
    //empty
    std::cout<<"\n"<<v.empty();
    //iterator
    std::cout<<"\n"<<*v.begin()<<"*"<<*(v.end()-1)<<"*"<<*v.rbegin()<<"*"<<*(v.rend()-1);
    //insert
    v.insert(v.begin()+2,19);
    v.insert(v.cbegin(),v2.cbegin(),v2.cend());
    std::cout<<"\ninsert to v\n";
    std::for_each(v.cbegin(),v.cend(),[](int a){std::cout<<a<<"*";});
    //swap
    v.swap(v2);
    std::cout<<"\nv\n";
    std::for_each(v.cbegin(),v.cend(),[](int a){std::cout<<a<<"*";});
    std::cout<<"\nv2\n";
    std::for_each(v2.cbegin(),v2.cend(),[](int a){std::cout<<a<<"*";});
    //erase, clear
    v.erase(v.cbegin()+2);
    std::cout<<"\n"<<v.size()<<"*"<<v.capacity();
    v.clear();
    std::cout<<"\n"<<v.size()<<"*"<<v.capacity();
    return 0;
}