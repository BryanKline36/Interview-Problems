/*

Given a matrix A, return the transpose of A.

The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.

 

Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]

Example 2:

Input: [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]

    1 <= A.length <= 1000
    1 <= A[0].length <= 1000

*/

class Solution 
{
    public:
    
    vector<vector<int>> transpose(vector< vector<int> >& A) 
    {
        int row, column, rowSize = A.size(), columnSize = A[0].size();
        vector< vector<int> > result;
        vector<int> temp;
        
        for(column = 0; column < columnSize; column++)
        {
            for(row = 0; row < rowSize; row++)
            {
                temp.push_back(A[row][column]);
            }
            
            result.push_back(temp);
            temp.clear();
        }
        
        return result;
    }
    
};


