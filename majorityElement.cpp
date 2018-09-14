/*

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 
You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3

Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2

*/

class Solution 
{

    public:
    
    int majorityElement(vector<int>& nums) 
    {
        int index, majority, result = 0, size = nums.size();
        map<int, int> hashMap;
        map<int, int>::iterator mapIterator;
        
        majority = size / 2;
     
        for(index = 0; index < size; index++)
        {
            hashMap[nums[index]]++;
        }
        
        mapIterator = hashMap.begin();
        while(mapIterator != hashMap.end())
        {
            if(mapIterator->second > majority)
            {
                result = mapIterator->first;
            }
            mapIterator++;
        }
        
        return result;
    }
};
