/*******************************************************
 **                     Algorithm 1                   **
 ** Amanda Shohdy, Jasmine Rodriguez, Edwin Rodriguez **
 *******************************************************/

#include <iostream>
#include <vector>

using std::cin ; 
using std::cout ; 
using std::endl ;
using std::vector ; 

int main() 
{
    int numSwaps = 0 ;  // total number of swaps needed to connect pairs
    vector<int> list ;  // container for individuals
    cout << "Enter -1 when finished inputing numbers..." << endl ; 
    int input ;         // INT - individual to be added to the end of list 
    cin >> input ; 
    while (input != -1)
    {
        list.push_back(input) ;    // insert individual at the end of the list
        cin >> input ;             // take in next input
    }

    // output the original list
    cout << endl ; 
    for (int i : list) { cout << i << " " ; }
    cout << endl ;
    
    // for each individual in the list
    for (int i = 0 ; i < list.size() ; i++)
    {
        bool found = false ;    // individual being searched for is found

        // if the current individual is an even number
        if (list[i] % 2 == 0)  
        {   
            // if the next individual is not the current individual + 1
            if (list[i+1] != list[i] + 1)
            {
                // for the rest of the individuals in the list until desired individual is found
                for (int j = i+2 ; j < list.size() && !found ; j++) 
                {
                    // if the individual at index j is the desired individual
                    if (list[j] == list[i] + 1)
                    {
                        int temp = list[i+1] ; 
                        list[i+1] = list[j] ;   // swap the individual at i+1 with the individual at j
                        list[j] = temp ;
                        found = true ; 
                        numSwaps++ ;            // increment numSwaps

                        // output updated list
                        for (int i : list) { cout << i << " " ; }
                        cout << endl ; 
                    }
                }
            }
            else { i++ ; }      // if the couple is already paired, move to the next pair
        }

        // if the current individual is an odd number
        else if (list[i] % 2 != 0)
        {
            // if the next individual is not the current individual - 1
            if (list[i+1] != list[i] - 1)
            {
                // for the rest of the individuals in the list until desired individual is found
                for (int j = i+2 ; j < list.size() && !found ; j++)
                {
                    // if the individual at index j is the desired individual
                    if (list[j] == list[i] - 1)
                    {
                        int temp = list[i+1] ; 
                        list[i+1] = list[j] ;   // swap the individual at i+1 with the individual at j
                        list[j] = temp ;
                        found = true ; 
                        numSwaps++ ;            // increment numSwaps

                        // output updated list
                        for (int i : list) { cout << i << " " ; }
                        cout << endl ; 
                    }
                }
            }
            else { i++ ; }      // if the couple is already paired, move to the next pair
        }
    }

    cout << endl << "Number of Swaps: " << numSwaps << endl ;   // output number of swaps needed

    // output final list 
    for (int i : list) { cout << i << " " ; }
    cout << endl ; 

    return 0 ; 
}
