#include <iostream>
#include<vector>
#include<algorithm>
#include<ctime>


int main()
{
    std::vector<int> v={1,2,3,4,5,5,4,3,2,0};
    std::vector<int> v2(10);
    std::vector<int> v3;
    std::cout<<"\noriginal vector:\n";
    std::for_each(v.cbegin(),v.cend(),[](int a){std::cout<<a<<"*****";});
    std::fill(v.begin()+5,v.end(),100);
    std::cout<<"\nafter filling with 100:\n";
    std::for_each(v.cbegin(),v.cend(),[](int a){std::cout<<a<<"*****";});
    std::generate(v.begin()+5,v.end(),[](){static int a=1; return ++a;});
    std::cout<<"\nafter generating:\n";
    std::for_each(v.cbegin(),v.cend(),[](int a){std::cout<<a<<"*****";});
    std::srand(time(0));
    std::random_shuffle(v.begin(),v.end());
    std::cout<<"\nafter shuffling:\n";
    std::for_each(v.cbegin(),v.cend(),[](int a){std::cout<<a<<"*****";});
    std::vector<int>::const_iterator f=std::find(v.cbegin(),v.cend(),1);
    if ( f != v.cend() )std::cout << "\n\nFound 1 at location " << ( f - v.cbegin() );
    else std::cout << "\n\n1 not found";
    std::transform(v.cbegin(),v.cend(),v2.begin(),[](int a){return a*a;});
    std::cout<<"\nafter transforming to v2:\n";
    std::for_each(v2.cbegin(),v2.cend(),[](int a){std::cout<<a<<"*****";});
    std::sort(v2.begin(),v2.end());
    std::cout<<"\nafter sorting v2:\n";
    std::for_each(v2.cbegin(),v2.cend(),[](int a){std::cout<<a<<"*****";});
    std::reverse(v2.begin(),v2.end());
    std::cout<<"\nafter reversing of v2:\n";
    std::for_each(v2.cbegin(),v2.cend(),[](int a){std::cout<<a<<"*****";});
    std::merge(v.cbegin(),v.cend(),v2.cbegin(),v2.cend(),std::back_inserter(v3));
    std::cout<<"\nafter merging to v3:\n";
    std::for_each(v3.cbegin(),v3.cend(),[](int a){std::cout<<a<<"*****";});

return 0;
}
