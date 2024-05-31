/**************************
 *** Problem 1: Rentals ***
 ***   Amanda Shohdy    ***
 **************************/

#include <iostream>
#include <vector>
#include <utility> 
#include <algorithm> 

using std::cin ; 
using std::cout ; 
using std::endl ;
using std::vector ;
using std::pair ; 
using std::make_pair ;  
using std::sort ; 

int main() 
{
    vector<pair<int, int>> intervals ;

    cout << "Enter -1 -1 when finished entering intervals." << endl << endl ; 

    int start ; 
    int end ;
    pair<int, int> interval ; 

    cout << "Enter the start and end time separated by a space: " ;
    cin >> start ; 
    cin >> end ;

    while (start > -1 && end > -1) 
    { 
        interval = make_pair(start, end) ; 
        intervals.push_back(interval) ; 
                
        cout << "                                                 : " ; 
        cin >> start ; 
        cin >> end ; 
    }

    // sort intervals by starting time
    sort(intervals.begin(), intervals.end()) ;

    // vector to store number of laptops and the current rental interval of each
    vector<pair<int, int>> laptops ; 
    laptops.push_back(intervals[0]) ;      // first laptop rented for first interval  
    intervals.erase(intervals.begin()) ;   // remove accounted for interval

    // while there are still intervals unaccounted for
    while (intervals.size() > 0)
    {
        // for each laptop option, while a laptop has not been selected for the current interval
        bool updated = false ; 
        for (int i = 0 ; i < laptops.size() && (!updated) ; i++)    
        {
            // if the current interval starts after the laptop being rented is free
            if (intervals[0].first >= laptops[i].second) 
            {
                updated = true ;                        // laptop is selected
                laptops[i] = intervals[0] ;             // rental interval is updated
                intervals.erase(intervals.begin()) ;    // remove accounted for interval
            }
        }
        // if interval is not accounted for
        if (!updated)
        {
            laptops.push_back(intervals[0]) ;       // need an additional laptop
            intervals.erase(intervals.begin()) ;    // remove accounted for interval
        }
    }

    cout << endl << "The minimum number of laptops needed for each student to have access is " << laptops.size() << " laptops." << endl << endl ; 
}