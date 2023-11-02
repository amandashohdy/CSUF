#include <iostream>
#include <memory>

using std::cout ;
using std::endl ;
using std::shared_ptr ;
using std::make_shared ;

class Node
{
    public :
        int value ;
        shared_ptr<Node> left ;
        shared_ptr<Node> right ;
} ;

class binarySearchTree
{
    public :
        shared_ptr<Node> root ;

        shared_ptr<Node> Insert(shared_ptr<Node> root, int val)
        {
            if (!root)    // if (root == nullptr)
            { 
                root = make_shared<Node>() ; 
                root->value = val ;
                root->left = nullptr ;
                root->right = nullptr ;
            }  

            else if (val < root->value) { root->left = Insert(root->left, val) ; }
            else if (val > root->value) { root->right = Insert(root->right, val) ; }

            return root ;
        }

        void Preorder(shared_ptr<Node> root)    // root, left, right
        {
            if (!root) { return ; }    // if there is no tree, return to function call

            cout << root->value << " " ;
            Preorder(root->left) ;
            Preorder(root->right) ;
        }

        void Inorder(shared_ptr<Node> root)    // left, root, right
        {
            if (!root) { return ; }    // if there is no tree, return to function call

            Inorder(root->left) ;
            cout << root->value << " " ;
            Inorder(root->right) ;
        }

        void Postorder(shared_ptr<Node> root)    // left, right, root
        {
            if (!root) { return ; }    // if there is no tree, return to function call
            
            Postorder(root->left) ;
            Postorder(root->right) ;
            cout << root->value << " " ;
        }
        
        bool Search(shared_ptr<Node> root, int key)
        {
            if (!root) { return false ; }    
            
            if (key < root->value) { return Search(root->left, key) ; }
            else if (key > root->value) { return Search(root->right, key) ; }
            else { return true ; }
        }

        shared_ptr<Node> findMin(shared_ptr<Node> node)
        {
            while (node->left) { node = node->left ; }
            return node ;
        }

        shared_ptr<Node> Delete(shared_ptr<Node> root, int val) 
        {
            if (!root) { return root ; }    // return type must be shared_ptr<Node>
                                            // will return root pointing to nulls
            if (val < root->value) { root->left = Delete(root->left, val) ; }
            else if (val > root->value) { root->right = Delete(root->right, val) ; }
            else 
            { 
                // case 1: The node is a leaf
                // Smart Pointers will delete the node automatically. 

                // case 2: The node has 1 child
                if (!root->left) { return root->right ; }
                else if (!root->right) { return root->left ; }

                // case 3: The node has 2 children
                else 
                { 
                    shared_ptr<Node> successor = findMin(root->right) ; 
                    root->value = successor->value ;
                    root->right = Delete(successor->right, successor->value) ; 
                }  
            }
            return root ;
        }
} ;



int main()
{
    binarySearchTree tree1 ;
    shared_ptr<Node> treeRoot = nullptr ;
    treeRoot = tree1.Insert(treeRoot, 52) ;
    tree1.Insert(treeRoot, 34) ;
    tree1.Insert(treeRoot, 45) ;
    tree1.Insert(treeRoot, 28) ;
    tree1.Insert(treeRoot, 77) ;
    tree1.Insert(treeRoot, 59) ;
    tree1.Insert(treeRoot, 88) ;
    cout << endl ;

    cout << "Preorder: " << endl ;
    tree1.Preorder(treeRoot) ;
    cout << endl << endl ;

    cout << "Inorder: " << endl ;
    tree1.Inorder(treeRoot) ;
    cout << endl <<endl ;

    cout << "Postorder: " << endl ;
    tree1.Postorder(treeRoot) ;
    cout << endl << endl ;

    cout << "Search: " << endl ;
    cout << "searching for 12: " << tree1.Search(treeRoot, 12) << endl ; 
    cout << "searching for 45: " << tree1.Search(treeRoot, 45) << endl ;
    cout << endl ;

    tree1.Delete(treeRoot, 45) ; 

    cout << "Inorder: " << endl ;
    tree1.Inorder(treeRoot) ;
    cout << endl <<endl ;

    return 0 ;
}