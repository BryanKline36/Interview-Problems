/*

Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.

Example:
Input: 
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.

Note:

    1 <= paragraph.length <= 1000.
    1 <= banned.length <= 100.
    1 <= banned[i].length <= 10.
    The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
    paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
    Different words in paragraph are always separated by a space.
    There are no hyphens or hyphenated words.
    Words only consist of letters, never apostrophes or other punctuation symbols.\

*/

class Solution 
{

    public:
    
    string mostCommonWord(string paragraph, vector<string>& banned) 
    {
        int index, max = 0, size;
        vector<string> splitParagraph;
        map<string, int> hashMap;
        map<string, int>::iterator mapIterator;
        map<string, int>::iterator greatest;
        
        paragraph = format(paragraph);
        splitParagraph = split(paragraph);
        
        
        size = splitParagraph.size();
        for(index = 0; index < size; index++)
        {
            hashMap[splitParagraph[index]]++;
        }
        
        size = banned.size();
        for(index = 0; index < size; index++)
        {
            hashMap[banned[index]] = -1;
        }
        
        mapIterator = greatest = hashMap.begin();
        while(mapIterator != hashMap.end())
        {
            if(mapIterator->second > max)
            {
                greatest = mapIterator;
                max = mapIterator->second;
            }
            
            mapIterator++;
        }
        
        return greatest->first;
    }
    
    string format(string input)
    {
        int index, size = input.size();
        
        for(index = 0; index < size; index++)
        {
            input[index] |= 0x20;
            
            if(input[index] > ' ' && input[index] < 'a')
            {
                input.erase(input.begin() + index);
                index--;
            }
        }
        
        return input;
    }
    
    vector<string> split(string input)
    {
        vector<string> output;
        string temp;
        stringstream stream(input);
        
        while(stream >> temp)
        {
            output.push_back(temp);
        }
        
        return output;
    }

};
