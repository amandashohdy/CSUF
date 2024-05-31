/*********************************
 ** Project 3: Exhautive Search **
 **        Amanda Shohdy        **
 *********************************/

#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
using std::vector ; 
using std::cout ; 
using std::cin ; 
using std::endl ; 
using std::pow ; 
using namespace std::chrono ;

// function to count the amount of paths
long long int pathCounter(vector<vector<char>> &grid)  ; 

int main() 
{
    int numRows ;
    cout << "Enter number of rows: " ; 
    cin >> numRows ;
    
    int numCols ;
    cout << "Enter number of columns: " ;
    cin >> numCols ; 
    cout << endl ; 

    vector<vector<char>> grid(numRows, vector<char>(numCols)) ; 
    
    cout << "Enter the grid: " << endl << endl ; 
    // iterate through grid
    for (int r = 0 ; r < numRows ; r++) 
    {
        for (int c = 0 ; c < numCols ; c++) 
        {
            cin >> grid[r][c] ; 
        }
    }

    // start time of exhaustive execution
    auto start = high_resolution_clock::now() ;

    long long int result = pathCounter(grid) ; 

    // stop time of exhautive execution 
    auto stop = high_resolution_clock::now() ;

    // duration of exhaustive execution 
    auto duration = duration_cast<seconds>(stop - start) ;

    // output results
    cout << endl << "Number of Paths: " << result << endl << endl ; 

    // output duration of exhaustive execution 
    cout << "Exhaustive execution of grid size " << numRows * numCols << " took " << duration.count() << " seconds" << endl << endl ; 


    return 0 ;
}

long long int pathCounter(vector<vector<char>> &grid) 
{
    int numRows = grid.size() ; 
    int numCols = grid[0].size() ;
    int len = numRows + numCols - 2 ;  // total moves 
    int counter = 0 ; 

    // if starting position or ending position are blocked, there are no paths
    if (grid[0][0] == 'X' || grid[numRows-1][numCols-1] == 'X') { return 0 ; }

    // for all possible sequences
    for (int bits = 0 ; bits < pow(2, len) ; bits++)
    {
        vector<char> candidate ; 
        for (int k = 0 ; k < len ; k++)
        {
            int bit = (bits >> k) & 1 ; 
            if (bit == 1) { candidate.push_back('>') ; }  // move right
            else { candidate.push_back('v') ; }  // move down
        }

        int rowIndex = 0 ; 
        int colIndex = 0 ;
        bool valid = true ; 
        
        // for each move in the candidate while the candidate is still valid
        for (int i = 0 ; i < candidate.size() && valid ; i++)
        {
            // if the candidate moves right and is still on the grid
            if (candidate[i] == '>' && colIndex < numCols - 1) { colIndex++ ; }
            // if the candidate moves down and is still on the grid
            else if (candidate[i] == 'v' && rowIndex < numRows - 1) { rowIndex++ ; }

            // if the move lands on an unsafe space, eliminate the candidate
            if (grid[rowIndex][colIndex] == 'X') { valid = false ; }
        }
        // if the candidate is valid and lands on the goal space 
        if (valid && rowIndex == numRows - 1 && colIndex == numCols - 1) { counter++ ; }
    }

    return counter ; 
}