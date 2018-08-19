/*

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: "III"
Output: 3

Example 2:

Input: "IV"
Output: 4

Example 3:

Input: "IX"
Output: 9

Example 4:

Input: "LVIII"
Output: 58
Explanation: C = 100, L = 50, XXX = 30 and III = 3.

Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

*/

class Solution 
{

    public:
    
    int romanToInt(string s) 
    {
        int index, size, result = 0;
    
        s = formatNumeral(s);
        size = s.size();
        
        for(index = 0; index < size; index++)    
        {
            result += checkValue(s[index]);
        }
        
        return result;
    }
    
    int checkValue(char input)
    {
        int output = 0;
        
        switch(input)
        {
            case 'I':
                output = 1;
            break;    
                
            case '4':
                output = 4;
            break; 
                
            case 'V':
                output = 5;
            break; 
                
            case '9':
                output = 9;
            break; 
                
            case 'X':
                output = 10;
            break; 
                
            case '!':
                output = 40;
            break; 
                
            case 'L':
                output = 50;
            break; 
                
            case '@':
                output = 90;
            break; 
                
            case 'C':
                output = 100;
            break; 
                
            case '#':
                output = 400;
            break; 
                
            case 'D':
                output = 500;
            break; 
                
            case '$':
                output = 900;
            break; 
                
            case 'M':
                output = 1000;
            break; 
        }
        
        return output;
    }
    
    string formatNumeral(string s)
    {
        size_t position;
        
        position = s.find("IV");
        if(position != string::npos)
        {
            s.replace(position, 2, "4");
        }
        
        position = s.find("IX");
        if(position != string::npos)
        {
            s.replace(position, 2, "9");
        }
        
        position = s.find("XL");
        if(position != string::npos)
        {
            s.replace(position, 2, "!");
        }
        
        position = s.find("XC");
        if(position != string::npos)
        {
            s.replace(position, 2, "@");
        }
        
        position = s.find("CD");
        if(position != string::npos)
        {
            s.replace(position, 2, "#");
        }
        
        position = s.find("CM");
        if(position != string::npos)
        {
            s.replace(position, 2, "$");
        }
        
        return s;
    }
    
};
