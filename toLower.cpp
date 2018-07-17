/*

Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

 

Example 1:

Input: "Hello"
Output: "hello"

Example 2:

Input: "here"
Output: "here"

Example 3:

Input: "LOVELY"
Output: "lovely"

*/

class Solution 
{
    public:
        
        string toLowerCase(string str) 
        {
            int index, size = str.length();
            
            for(index = 0; index < size; index++)
            {
                if(str[index] >= 'A' && str[index] <= 'Z')
                {
                    str[index] += 32;
                }    
            }    
            
            return str;
        }
};
