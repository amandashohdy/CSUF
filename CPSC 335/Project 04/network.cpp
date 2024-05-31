/*************************************
 *** Problem 2: Network Delay Time ***
 ***         Amanda Shohdy         ***
 *************************************/

#include <iostream>
#include <vector> 
#include <algorithm>

using std::cin ; 
using std::cout ; 
using std::endl ;
using std::vector ;
using std::sort ; 

int signal(vector<vector<int>> times, int k, int n) ; 

int main()
{
    vector<vector<int>> times ; 
    int k ; 
    int n ; 

    cout << "How many nodes: " ; 
    cin >> n ; 
    cout << "What is the source node: " ; 
    cin >> k ; 

    vector<int> temp ;
    int input = 0 ;
    cout << endl << "Enter -1 -1 -1 when finished." << endl ; 
    cout << "Enter travel time data separated by a space. " << endl ; 
    while (input > -1)
    { 
        cout << "                                           : " ;
        for (int i = 0 ; i < 3 ; i++)
        {
            cin >> input ; 
            temp.push_back(input) ; 
        }
        if (temp[0] != -1) { times.push_back(temp) ; }
        for (int i = 0 ; i < 3 ; i++) { temp.erase(temp.begin()) ; }
    }

    cout << "The minimum time for all nodes to receive the signal is " << signal(times, k, n) << "." << endl << endl ; 
}

int signal(vector<vector<int>> times, int k, int n) 
{
    // if there is no path that starts with the source node, there is no path
    bool valid = false ; 
    for (int i = 0 ; i < times.size() ; i++)
    {
        if (times[i][0] == k) { valid = true ; }
    }
    if (!valid) { return -1 ; }

    int minTime = 0 ; 

    // track each node that has been visited
    vector<int> nodesVisited ;
    nodesVisited.push_back(k) ;     // add the source node

    // track all different paths around  network
    vector<vector<int>> paths ;  
    paths.push_back({k, 0}) ;   // start at source node with length 0

    int index = 0 ; 
    bool newPath ; 
    while (times.size() > 0)     // while options have not been tested
    {
        for (int i = 0 ; i < paths.size() ; i++)    // for each path option
        {
            newPath = true ; 
            // if current option starts at the current path start 
            if (times[index][0] == paths[i][0] && newPath == true) 
            { 
                paths[i][0] = times[index][1] ;     // move to the next node
                paths[i][1] += times[index][2] ;    // add time taken to total time
                times.erase(times.begin()) ;        // remove path from options
                newPath = false ;                   // do not create a new path from starting node

                nodesVisited.push_back(paths[i][0]) ; // add node to nodesVisited
            }
        }
        if (newPath) { paths.push_back({k, 0}) ; }    // if not option was found, create a new path from the start and test again
    }

    // sort and test that each possible node has been visited 
    sort(nodesVisited.begin(), nodesVisited.end()) ; 
    for (int i = 1, j = 0 ; i <= k, j < nodesVisited.size() ; i++, j++)
    {
        if (nodesVisited[j] != i) { return -1 ; }   // if a node is skipped, return -1
    }

    // longest amount of time taken for a path is the min time
    for (int i = 0 ; i < paths.size() ; i++)
    {
        if (paths[i][1] > minTime) { minTime = paths[i][1] ; }
    }

    return minTime ;
}