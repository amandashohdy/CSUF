#include <iostream>

//functional templates 
template <typename T>
T max(T val1, T val2)
{
    if (val1 > val2) return val1 ;
    else return val2 ;
}

//class templates
template <typename T>
class vector
{
    int size ;
    public :
        T* vect ;
        vector(int s)
        {
            size = s ;
            vect = new T[size] ;
        }
        void display()
        {
            for (int i = 0 ; i < size ; i++)
            {
                std::cout << vect[i] << std::endl ;
            }
        }
} ;

int main()
{
    std::cout << "The maximum between two numbers = " << max(4, 6) << std::endl ;
    std::cout << "The maximum between two numbers = " << max(4.333, 5.234) << std::endl ;

    vector<int> v1(4) ;
    v1.vect[0] = 2 ;
    v1.vect[1] = 3 ;
    v1.vect[2] = 4 ;
    v1.vect[3] = 5 ;

    vector<double> v2(4) ;
    v2.vect[0] = 3.0 ;
    v2.vect[1] = 4.2 ;
    v2.vect[2] = 5.4 ;
    v2.vect[3] = 6.2 ;

    v1.display() ;
    v2.display() ;

    return 0 ;
}
