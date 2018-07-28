/*

Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1

Example 2:

Input: [4,1,2,1,2]
Output: 4


*/

class Solution 
{
    public:
        int singleNumber(vector<int>& nums) 
        {
            int i, size = nums.size(), lastNumber;
            sort(nums.begin(), nums.end());
            
            for(i = 0; i < size; i++)
            {
                if(i % 2 == 0)
                {
                    lastNumber = nums[i];
                }    
                else
                {
                    if(lastNumber != nums[i])
                    {
                        break;
                    }    
                }    
            }   
            
            return lastNumber;
        }
};
