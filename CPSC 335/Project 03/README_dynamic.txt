Amanda Shohdy | amandashohdy@csu.fullerton.edu 

Dynamic Programming Implementation 
==================================

Overview:
This algorithm determines the number of safe passages from one end of a stationary opponent-filled field
to the other end dynamically. If the starting location (the top left corner) or the ending location (the
bottom right corner) are occupied, there are no safe passages. 
A safe space is represented by a '.' and an unsafe space is represented by an 'X'.
This program takes in how many rows and columns are present in the grid, then takes in the value of each space in the grid. 

Running the Program:
Navigate to the directory containint the program files and start the program.
Enter the number of rows in the grid.
Enter the number of columns in the grid.
Enter the values of each position in the grid. 

================
Console Example:
================

Enter number of rows: 8
Enter number of columns: 9

Enter the grid:

......X.X
X........
...X...X.
..X....X.
.X....X..
....X....
..X.....X
.........

Number of Paths: 102

Dynamic execution of grid size 72 took 0 microseconds