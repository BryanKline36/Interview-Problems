/*

 Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:

    Each element in the result must be unique.
    The result can be in any order.

*/

class Solution 
{

    public:
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        int index, sizeNums1 = nums1.size(), sizeNums2 = nums2.size(), setSize;
        map<int, int> hashMap;
        set<int> resultSet;
        set<int>::iterator setIterator;
        vector<int> result;
        
        for(index = 0; index < sizeNums1; index++)
        {
            hashMap[nums1[index]]++;
        }
        
        for(index = 0; index < sizeNums2; index++)
        {
            if(hashMap[nums2[index]] > 0)
            {
                resultSet.insert(nums2[index]);
            }
        }
        
        setIterator = resultSet.begin();
        while(setIterator != resultSet.end())
        {
            result.push_back(*setIterator);   
            setIterator++;
        }
                
        return result;
    }
};
