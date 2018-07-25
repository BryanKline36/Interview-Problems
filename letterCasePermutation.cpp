/*

Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]

Note:

    S will be a string with length at most 12.
    S will consist only of letters or digits.

*/

class Solution 
{
    public:
    
    set<string> permutations;
    int inputSize;
    
    vector<string> letterCasePermutation(string S) 
    {
        inputSize = S.size();
        
        S = toLower(S);
        permutator(S, 0);
        
        vector<string> result(permutations.begin(), permutations.end());
        
        if(result.empty())
        {
            result.push_back("");
        }    
        
        return result;
    }
    
    void permutator(string S, int index)
    {
        if(index < inputSize)
        {
            permutations.insert(S);
            permutator(S, index + 1);
            if(S[index] >= 'a' && S[index] <= 'z')
            {
                S[index] &= 0xDF;
            }
            permutations.insert(S);
            permutator(S, index + 1);   
        }    

    }
    
    string toLower(string S)
    {
        int index;
        
        for( index = 0; index < inputSize; index++)
        {
            if( S[index] >= 'A' && S[index] <= 'Z' )
            {
                S[index] |= 0x20;
            }
        }
        
        return S;
    }
};
