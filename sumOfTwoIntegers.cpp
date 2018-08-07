/*

Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3. 

*/

class Solution 
{

    public:
    
    int getSum(int a, int b) 
    {
        int counter, intSize = sizeof(int) * 8, bitPosition = 0X01;
        int maskA, maskB, sum, carry = 0, result = 0;
        
        for(counter = 0; (counter < intSize); counter++)
        {
            maskA = a & bitPosition;
            maskB = b & bitPosition;
            
            sum = maskA ^ maskB;
            
            if(carry == 0)
            {
                carry = maskA & maskB;
            }
            else
            {
                carry = maskA | maskB;
                sum ^= bitPosition;
            }
                
            result |= sum;
            bitPosition <<= 1;
        }
        
        return result;
    }
};
