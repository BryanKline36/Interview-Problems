/*

Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh". 

*/

class Solution 
{
    public:
        string reverseString(string s) 
        {
            int front = 0, back = s.length() - 1;
            int mid =  (back + 1) >> 1;
            char temp;
            
            while(front <  back)
            {
                temp = s[back];
                s[back] = s[front];
                s[front] = temp;
                
                front++;
                back--;
            }
            
            return s;
        }
};
