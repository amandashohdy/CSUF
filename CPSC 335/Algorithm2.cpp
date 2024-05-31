/*******************************************************
 **                     Algorithm 2                   **
 ** Jasmine Rodriguez, Amanda Shohdy, Edwin Rodriguez **
 *******************************************************/

#include <iostream>
#include <vector>

using std::cin ; 
using std::cout ; 
using std::endl ;
using std::vector ; 

// Function declaration 
int greedyHamiltonian(vector<int> fuel, vector<int> city_distances, const int mpg) ;

int main() 
{
    vector<int> city_distances ;    // vector of distances between cities
    vector<int> fuel ;              // vector of fuel available at each city 
    int mpg ;                       // miles per gallon

    int input ;                     // user input
    cout << "Enter the distances between the cities " << endl ;
    cout << "   Enter -1 when finished: " << endl ; 
    cin >> input ; 
    while (input != -1)         // end input loop by entering -1 
    { 
        city_distances.push_back(input) ;   // add input to the end of distances vector
        cin >> input ;                      // take in input
    }

    cout << "Enter the fuel available at each city " << endl ;
    cout << "   Enter -1 when finished: " << endl ; 
    cin >> input ; 
    while (input != -1)         // end input loop by entering -1
    { 
        fuel.push_back(input) ;             // add input to the end of fuel vector
        cin >> input ;                      // take in input
    }

    cout << "Enter the mpg: " ;
    cin >> input ;                          // enter mpg
    mpg = input ; 
    cout << endl << endl ; 

    cout << "The preferred starting city for the sample above is city " << greedyHamiltonian(fuel, city_distances, mpg) << endl ; // output preferred starting city

    return 0 ; 
}

/*********************************************************************************
 * Function to determine the preferred starting city.
 *
 * vector<int> city_distances :   vector of distances between cities
 * vector<int> fuel           :   vector of fuel available at each city 
 * const int mpg              :   miles per gallon
 *
 * return starting_city :   preferred starting city
 *********************************************************************************/
int greedyHamiltonian(vector<int> fuel, vector<int> city_distances, const int mpg)
{  
    // for each possible starting city
    for (int starting_city = 0 ; starting_city < fuel.size() ; starting_city++)
    {
        int fuel_available = 0 ;    // start with empty tank
        bool correct = true ;       // assume correct city

        // for each index (city) while starting city is still valid
        for (int i = 0 ; i < fuel.size() && correct ; i++)
        {
            // traverse the vectors
            int j = (starting_city + i) % fuel.size() ;
            fuel_available += (fuel[j] * mpg) - city_distances[j] ;   // fuel available = fuel available + (fuel at current city * mpg - distance)
            
            // if fuel available is below 0, current starting city is not correct 
            if (fuel_available < 0) { correct = false ; }
        }

        if (correct) { return starting_city ; }
    }
    return -1 ;
}