/*

Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:

Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Note: In the string, each word is separated by single space and there will not be any extra space in the string. 

*/

class Solution 
{
    public:
        string reverseWords(string s) 
        {
            int wordCounter = 0, letterCounter;
            string word = s;
            
            while(word[wordCounter] != '\0')
            {
                if(word[wordCounter] == ' ')
                {
                    wordCounter++;  
                }    
                else
                {    
                    letterCounter = wordCounter;
                    while(word[letterCounter + 1] != ' ' && word[letterCounter + 1] != '\0')
                    {
                        letterCounter++;
                    }    

                    reverseSubstring(word, wordCounter, letterCounter);
                    wordCounter = letterCounter + 1;
                }
            }
            
            return word;
        }
    
        void reverseSubstring(string& word, int wordCounter, int letterCounter)
        {
            int midPoint = wordCounter + ((letterCounter - wordCounter) / 2);
            char temp;
            
            while(wordCounter <= midPoint)
            {
                temp = word[wordCounter];
                word[wordCounter] = word[letterCounter];
                word[letterCounter] = temp;
                wordCounter++;
                letterCounter--;
            }    
        }   
};
