#include <iostream>
#include <vector>

using std::cout ;
using std::endl ;

// Stacks are last in first out
template <typename T> class vectorStack
{
    public :
        // add element to top of the stack (end of the vector)
        void push(T v) { stack.push_back(v) ; }

        // remove first element of the stack (last element of the vector)
        void pop() { stack.pop_back() ; }

        // access first element of the stack (last element of the vector)
        void top() { cout << endl << "Top: " << stack[stack.size() - 1] << endl ; }

        void display()
        {   // display stack by outputing the vector backwards
            cout << endl << "Stack: " << endl ;
            for (int i = stack.size() - 1 ; i >= 0 ; i--)
            {
                cout << stack[i] << endl ;
            }
        }

    private :
        std::vector<T> stack ;
} ;

int main()
{
    vectorStack<int> v1 ;
    v1.push(5) ;
    v1.push(4) ;
    v1.push(3) ;
    v1.push(2) ;
    v1.push(1) ;

    v1.display() ;

    v1.pop() ;
    v1.display() ;
    v1.pop() ;
    v1.display() ;
    v1.pop() ;
    v1.display() ;

    v1.top() ;

    v1.display() ;

    return 0 ;
}
