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

public class Solution {
    
    public string ToLowerCase(string str) {
        int index, size = str.Length;
        string temp = "";
        
        for(index = 0; index < size; index++){
            temp += (char) (((int)str[index]) | 0x20);
        }
        
        return temp;
    }
}
