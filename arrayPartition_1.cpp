/*

 Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:

Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).

Note:

    n is a positive integer, which is in the range of [1, 10000].
    All the integers in the array will be in the range of [-10000, 10000].


*/

class Solution 
{
    public:
    int arrayPairSum(vector<int>& nums) 
    {
        int i, result = 0;
        int size = nums.size();
        
        mergeSort(nums, size);
        
        for(i = 0; i < size; i += 2)
        {
            result += nums[i];
        }
        
        return result;
    }
    
    void mergeSort(vector<int>& nums, int size)
    {
        mergeHelper(nums, 0, size -1);   
    }
    
    void mergeHelper(vector<int>& nums, int low, int high)
    {
        int mid;
        
        if(low < high)
        {
            mid = (high + low) / 2;    
            mergeHelper(nums, low, mid);
            mergeHelper(nums, mid + 1, high);
            merge(nums, low, mid, high);
        }    
    }    
    
    void merge(vector<int>& nums, int low, int mid, int high)
    {
        int *temp = new int[high - low + 1];
        int i = low, j = mid + 1, k = 0;

        while(i <= mid && j <= high)
        {
            if(nums[i] <= nums[j])
            {    
                temp[k++] = nums[i++];
            }    
            else
            {    
                temp[k++] = nums[j++];
            }    
        }
        
        while(i <= mid)
        {    
            temp[k++] = nums[i++];
        }
        
        while(j <= high)
        {
            temp[k++] = nums[j++];
        }
        
        for(k = 0, i = low; i <= high; i++, k++)
        {
            nums[i] = temp[k];
        }

        delete []temp;
    }    
};
