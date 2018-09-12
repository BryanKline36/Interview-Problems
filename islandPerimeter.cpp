/*

You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16

*/ 

class Solution 
{
    public:
        int islandPerimeter(vector<vector<int>>& grid) 
        {
            int i, j, temp, result = 0;
            int height = grid.size();
            int width = grid[0].size();
            
            for(i = 0; i < height; i++)
            {
                for(j = 0; j < width; j++)
                {
                    temp = 4;    
                    if(grid[i][j] == 1)
                    {
                        if(((i - 1) >= 0) && grid[i - 1][j] == 1)
                        {
                            temp--;
                        }
                        if(((j + 1) < width) && grid[i][j + 1] == 1)
                        {
                            temp--;
                        }
                        if(((i + 1) < height) && grid[i + 1][j] == 1)
                        {
                           temp--; 
                        }
                        if(((j - 1) >= 0) && grid[i][j - 1] == 1)
                        {
                           temp--; 
                        }
                        
                        result += temp;
                    }    
                } 
            }    
            
            return result;
        }
};
