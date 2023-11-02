#include <iostream>
#include <vector>

template <typename T> class Queue
{
    public: 
        bool isEmpty() 
        {
            if (queue.size() == 0) { return true ; }
            else { return false ; }
        }

        void Insert(T element)
        {
            queue.push_back(element) ;
        }

        void Delete()
        {
            if (!isEmpty()) { queue.erase(queue.begin()) ; }
            else { throw "Queue is Empty!" ; }
        }

        void Front()
        {
            if (!isEmpty()) { std::cout << "Front: " << queue.front() << std::endl ; }
            //              { std::cout << "Front: " << queue[0] << std::endl ; }
            else { throw "Queue is Empty!" ; }
        }

        void Display()
        {
            std::cout << "The elements of the queue: " << std::endl ;
            for (int i = 0 ; i < queue.size() ; i++)
            {
                std::cout << queue[i] << " " ;
            }
            std::cout << std::endl ;

        }

    private :
        std::vector<T> queue ;
} ;

int main()
{
    Queue<int> queue1 ;
    queue1.Insert(1) ;
    queue1.Insert(2) ;
    queue1.Insert(3) ;

    queue1.Display() ;

    try { queue1.Front() ; }
    catch (const char* msg) { std::cout << msg << std::endl ; }

    try { queue1.Delete() ; }
    catch (const char* msg) { std::cout << msg << std::endl ; }

    queue1.Display() ;

    try { queue1.Front() ; }
    catch (const char* msg) { std::cout << msg << std::endl ; }

    try { queue1.Delete() ; }
    catch (const char* msg) { std::cout << msg << std::endl ; }

    queue1.Display() ;

    return 0 ;
}