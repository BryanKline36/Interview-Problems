/*

Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]

*/

class Solution 
{
    public:
        vector<string> fizzBuzz(int n) 
        {
            int index;
            vector<string> output;
            string temp;
            char buffer[100];
            
            for(index = 1; index <= n; index++)
            {
                temp = "";
                
                if(index % 3 == 0)
                {
                    temp += "Fizz";
                }    
                if(index % 5 == 0)
                {
                    temp += "Buzz";
                }   
                if(index % 3 != 0 && index % 5 != 0)
                {    
                    temp = to_string(index);
                }
                
                output.push_back(temp);
                
            }    
            return output;
        }
};
