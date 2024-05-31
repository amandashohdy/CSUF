/********************************
 ** Project 3: Dynamic Program **
 **        Amanda Shohdy       **
 ********************************/

 #include <iostream>
 #include <vector>
 #include <chrono>
 using std::vector ; 
 using std::cout ; 
 using std::cin ; 
 using std::endl ; 
 using namespace std::chrono ; 

// function to count the amount of paths
 long long int pathCounter(vector<vector<char>> &grid) ; 

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

    // start time of dynamic execution
    auto start = high_resolution_clock::now() ;

    long long int result = pathCounter(grid) ; 

    // stop time of dynamic execution 
    auto stop = high_resolution_clock::now() ;

    // duration of dynamic execution 
    auto duration = duration_cast<microseconds>(stop - start) ;

    // output results
    cout << endl << "Number of Paths: " << result << endl << endl ; 

    // output duration of dynamic execution 
    cout << "Dynamic execution of grid size " << numRows * numCols << " took " << duration.count() << " microseconds" << endl << endl ; 


    return 0 ; 
 }

 long long int pathCounter(vector<vector<char>> &grid) 
 {
    int numRows = grid.size() ; 
    int numCols = grid[0].size() ; 

    vector<vector<long long int>> paths(numRows, vector<long long int>(numCols, 0)) ; 

    // if starting position or ending position are blocked, there are no paths
    if (grid[0][0] == 'X' || grid[numRows-1][numCols-1] == 'X') { return 0 ; }

    // base case
    int val = 0 ; 
    if (grid[0][0] == '.') { val = 1 ; }
    paths[0][0] = val ; 

    for (int r = 0 ; r < numRows ; r++)
    {
        for (int c = 0 ; c < numCols ; c++)
        {   
            // if grid at current location is unsafe
            if (grid[r][c] == 'X') { paths[r][c] = 0 ; }
            else 
            {
                long long int above = 0 ; 
                long long int left = 0 ; 

                if (r > 0 && grid[r-1][c] == '.') { above = paths[r-1][c] ; }
                if (c > 0 && grid[r][c-1] == '.') { left  = paths[r][c-1] ; }

                paths[r][c] += above + left ;  // possibilities at current index
            }
        }
    }
    
    return paths[numRows-1][numCols-1] ;  
 }