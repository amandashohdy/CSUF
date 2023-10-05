// Smart Pointers
// no cases of memory leakes
#include <iostream>
#include <memory>  // smart pointer library

template <typename T> class Node
{
    public: 
        T data ;
        std::shared_ptr<Node<T>> nextNode ;
} ;

template <typename T> class LinkedList
{
    public:
        std::shared_ptr<Node<T>> head ;
        std::shared_ptr<Node<T>> tail ;

        void PushFront(T d)  // time complexity O(1)
        {
            // auto stores the value in a register.
            // when storing in a register, retrieval is faster than storing in memory
            auto new_node = std::make_shared<Node<T>>() ;

            if (head == nullptr) 
            {  
                new_node->data = d ;
                new_node->nextNode = nullptr ;
                head = new_node ;
                tail = new_node ;
            }
            else
            {
                new_node->data = d ;
                new_node->nextNode = head ;
                head = new_node ;
            }
        }

        void PushBack(T d)   // time complexity O(1)
        {
            auto new_node = std::make_shared<Node<T>>() ;
            if (head == nullptr) 
            {  
                new_node->data = d ;
                new_node->nextNode = nullptr ;
                head = new_node ;
                tail = new_node ;
            }
            else
            {
                new_node->data = d ;
                new_node->nextNode = nullptr ;
                tail->nextNode = new_node ;
                tail = new_node ;
            }
        }

        void PopFront()
        {
            if (head == nullptr) { throw "Linked list is empty." ; }
            else
            {
                std::shared_ptr<Node<T>> temp ;
                temp = head ;
                head = head->nextNode ;
                std::cout << "Deleted Element = " << temp->data << std::endl ;
            }
        }

        void display()    // time complexity O(n)
        {
            std::shared_ptr<Node<T>> currentPtr = head ;
            while (currentPtr != nullptr)
            {
                std::cout << currentPtr->data << " -> " ;
                currentPtr = currentPtr->nextNode ;
            }
            std::cout << "nullptr" << std::endl ;
        }
} ;

int main()
{
    /*
    // Unique Pointer 
    std::unique_ptr<int> ptr1 ;
    ptr1 = std::make_unique<int>() ;

    // Shared Pointer 
    std::shared_ptr<int> ptr2 ;
    ptr2 = std::make_shared<int>() ;
    */

    LinkedList<int> list1 ;
    int i ;
    do
    {
        std::cin >> i ;
        list1.PushFront(i) ;
    } while (i != -1) ;
    list1.display() ;

    LinkedList<int> list2 ;
    int j ;
    do
    {
        std::cin >> j ;
        list2.PushBack(j) ;
    } while (j != -1) ;
    list2.display() ;

    return 0 ;
}
