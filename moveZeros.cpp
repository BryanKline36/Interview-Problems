/*

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:

    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.

*/

class Solution 
{

    public:
    
    void moveZeroes(vector<int>& nums) 
    {
        int index, size = nums.size(), counter = 0;

        for(index = 0; index < size; index++)
        {
            if(nums[index] == 0)
            {
                nums.erase(nums.begin() + index);
                index--;
                counter++;
            }
        }
        
        for(index = 0; index < counter; index++)
        {
            nums.push_back(0);   
        }
    }
};
