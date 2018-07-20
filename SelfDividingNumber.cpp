/*

 A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

Also, a self-dividing number is not allowed to contain the digit zero.

Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.

Example 1:

Input: 
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]

Note:
The boundaries of each input argument are 1 <= left <= right <= 10000.

*/

class Solution 
{
    public:
    vector<int> selfDividingNumbers(int left, int right) 
    {
        int i;
        unsigned int j;
        vector<int> result;
        vector<int> digitList;
        bool notDivisible;
        for(i = left; i <= right; i++)
        {
            numberParser(digitList, i);    
            notDivisible = false;
            for(j = 0; j < digitList.size(); j++)
            {
                if(digitList[j] == 0 || i % digitList[j] != 0)
                {
                    notDivisible = true;
                }    
            }   
            
            if(!notDivisible)
            {
                result.push_back(i);
            }    
            
            digitList.clear();
        }   
        
        return result;
    }
    
    void numberParser(vector<int> &list, int number)
    {
        int i = 0;
        
        while(number > 0)
        {
            list.push_back(number % 10);
            number /= 10;
        }    
        
    }    
};
