#include <iostream>
using std::cin ;
using std::cout ;
using std::endl ;

int factorial(int n) ;

int main()
{
    int num ;
    cout << "Enter a number: " ;
    cin >> num ; 
    cout << num << "! = " << factorial(num) << endl ;
}

int factorial(int n)
{
    if (n <= 1) 
    {
        return 1 ;
    }
    else
    {
        return factorial(n-1) * n ;
    }
}