/*

We are given two strings, A and B.

A shift on A consists of taking string A and moving the leftmost character to the rightmost position. For example, if A = 'abcde', then it will be 'bcdea' after one shift on A. Return True if and only if A can become B after some number of shifts on A.

Example 1:
Input: A = 'abcde', B = 'cdeab'
Output: true

Example 2:
Input: A = 'abcde', B = 'abced'
Output: false

Note:

    A and B will have length at most 100.

*/

class Solution 
{
 
    public:
    
    bool rotateString(string A, string B) 
    {
        int index, size = A.size();
        
        for(index = 0; index < size + 1; index++)
        {
            if(A == B)
            {
                return true;
            }
            
            A = shift(A, size);
        }
        
        return false;    
    }
    
    string shift(string input, int size)
    {
        int index;
        string output = " ";
        output[0] = input[size - 1];
        
        for(index = 0; index < size - 1; index++)
        {
            output += input[index];
        }
        
        return output;
    }
};
