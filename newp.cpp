#include <iostream>
#include <new>
#include <memory>
void funiq(){
    std::unique_ptr<double[]> p[50];
    for ( size_t i = 0; i < 50; ++i ){
            p[i]= std::unique_ptr<double[]>(new double[50000000]);
            std::cout << "p[" << i << "] points to 50,000,000 new doubles\n";
    } 
}
void fnew(){
    double *ptr[ 50 ];
    size_t i;
    try{
        for (  i= 0; i < 50; ++i ){
            ptr[ i ] = new double[ 50000000 ];
            std::cout << "ptr[" << i << "] points to 50,000,000 new doubles\n";
        } 
    } 
    catch ( std::bad_alloc &e){
        std::cerr << "Exception occurred: "<<e.what() << "\n";
        delete[](ptr[i-1]);
    } 
}
int main(){
    /////unique_ptr
    try{
        funiq(); 
    }
    catch(std::bad_alloc &e){
        std::cout<<"eeee:"<<e.what()<<"\n";
    }   
    //   new
    fnew();

    std::cout<<"\n bye";   
} 