/*

Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]

Solved with and without iterators 

*/

// Solution without iterators

class Solution 
{
    public:

        vector<int> findDuplicates(vector<int>& nums) 
        {
            int index, size = nums.size();
            unordered_map<int, int> integers;
            vector<int> result;
            
            for(index = 0; index < size; index++)    
            {
                integers[nums[index]]++;

                if(integers[nums[index]] == 2)
                {
                    result.push_back(nums[index]);
                }
            }
            
            return result;
        }
};

// Solution with iterator 

class Solution 
{
    public:
    
        vector<int> findDuplicates(vector<int>& nums) 
        {
            unordered_map<int, int> integers;
            vector<int> result;
            int size = nums.size();
            int index;

            for(index = 0; index < size; index++)
            {
               integers[nums[index]]++;
            }

            unordered_map<int, int>:: iterator it = integers.begin();
            //auto automatically infers type
            //auto it = integers.begin();

            size = integers.size();
            for(index = 0; index < size; index++)
            {
               
               if(it->second == 2)
                   result.push_back(it->first);
               
               it++;
            }

            return result;

        }
};
