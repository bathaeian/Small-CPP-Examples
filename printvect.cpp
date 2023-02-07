
#include <iostream>
#include<vector>
#include<algorithm>
#include<iterator>

int main()
{
    std::vector<int> v={1,2,3,4,5};
    std::ostream_iterator<int> it(std::cout,"**");
    std::cout<<"\nfor i:\n";
    for(int i=0;i<v.size();i++){std::cout<<v[i]<<"*";}
    std::cout<<"\nostream iterator + copy:\n";
    std::copy(v.cbegin(),v.cend(),it);
    std::cout<<"\nfor: :\n";
    for(int i:v){std::cout<<i<<"***";}
    std::cout<<"\nfor iterator:\n";
    for(std::vector<int>::const_iterator i=v.cbegin();i!=v.cend();i++){std::cout<<*i<<"****";}
    std::cout<<"\nfor_each:\n";
    std::for_each(v.cbegin(),v.cend(),[](int a){std::cout<<a<<"*****";});
    return 0;
}
