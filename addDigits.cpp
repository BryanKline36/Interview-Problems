/*

Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.

*/

class Solution 
{
    public:
    
    int addDigits(int num) 
    {
        int temp, result = num;
        
        while(result > 9)
        {
            temp = 0;
            while(result > 0)
            {
                temp += result % 10;
                result /= 10;
            }
            
            result = temp;
        }
        
        return result;
    }
};
