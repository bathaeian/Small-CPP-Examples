#include <iostream>
#include <stdexcept> 
class Divide0Exception :public std::runtime_error
{
public:
Divide0Exception()
: std::runtime_error( "attempted to divide by zero" ){}
 };
double quotient( int numerator, int denominator ){
    if ( denominator == 0 ){
        throw Divide0Exception();
    }
    return static_cast< double >( numerator ) / denominator;
}

int main(){
    int n1,n2;
    std::cout << "Enter two integers ";
    std::cin >> n1 >> n2;
    try{
        double result = quotient( n1, n2 );
        std::cout << "The quotient is: " << result << "\n";
    }catch(std::exception &e){
        std::cout<<e.what();
    }
}