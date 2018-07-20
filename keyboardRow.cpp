/*

Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.

American keyboard

Example 1:

Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]

Note:

    You may use one character in the keyboard more than once.
    You may assume the input string will only contain letters of alphabet.


*/

class Solution 
{
    public:
    
        vector<string> findWords(vector<string>& words) 
        {
            int vectorCounter, vectorSize = words.size();
            vector<string> output;
            
            for(vectorCounter = 0; vectorCounter < vectorSize; vectorCounter++)
            {
                if(checkRow(words[vectorCounter]))
                {
                    output.push_back(words[vectorCounter]);
                }
            }
            
            return output;
        }
    
        bool checkRow(string word)
        {
            int stringCounter, stringSize = word.size();
            char row, tempChar = word[0];
            
            if(tempChar > 64 && tempChar < 91)
            {
                tempChar +=32;
            }
            row = findRow(tempChar);
            
            for(stringCounter = 1; stringCounter < stringSize; stringCounter++)
            {
                tempChar = word[stringCounter];
                if(tempChar > 64 && tempChar < 91)
                {
                    tempChar +=32;
                }
                
                if(findRow(tempChar) != row)
                {
                    return false;
                }
            }   
        
            return true;        
        }
            
        char findRow(char letter)
        {
            int index;
            
            char topRow[10] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};     
            char midRow[9] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
            char bottomRow[7] = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};        
            
            for(index = 0; index < 10; index++)
            {
                if(letter == topRow[index])
                {
                    return 't';
                }    
                if(index < 9 && letter == midRow[index])
                {
                    return 'm';
                } 
                if(index < 7 && letter == bottomRow[index])
                {
                    return 'b';
                } 
            }    
            
            return 'z';
        }    
};
