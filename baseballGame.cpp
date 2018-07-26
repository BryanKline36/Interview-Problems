/*

 You're now a baseball game point recorder.

Given a list of strings, each string can be one of the 4 following types:

    Integer (one round's score): Directly represents the number of points you get in this round.
    "+" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points.
    "D" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.
    "C" (an operation, which isn't a round's score): Represents the last valid round's points you get were invalid and should be removed.

Each round's operation is permanent and could have an impact on the round before and the round after.

You need to return the sum of the points you could get in all the rounds.

Example 1:

Input: ["5","2","C","D","+"]
Output: 30
Explanation: 
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get 2 points. The sum is: 7.
Operation 1: The round 2's data was invalid. The sum is: 5.  
Round 3: You could get 10 points (the round 2's data has been removed). The sum is: 15.
Round 4: You could get 5 + 10 = 15 points. The sum is: 30.

Example 2:

Input: ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation: 
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get -2 points. The sum is: 3.
Round 3: You could get 4 points. The sum is: 7.
Operation 1: The round 3's data is invalid. The sum is: 3.  
Round 4: You could get -4 points (the round 3's data has been removed). The sum is: -1.
Round 5: You could get 9 points. The sum is: 8.
Round 6: You could get -4 + 9 = 5 points. The sum is 13.
Round 7: You could get 9 + 5 = 14 points. The sum is 27.

Note:
The size of the input list will be between 1 and 1000.
Every integer represented in the list will be between -30000 and 30000.

*/

class Solution 
{
    public:

        struct DataPoint
        {
            int points;
            int index;
            char type;
            bool valid;              
        };
    
        int calPoints(vector<string>& ops) 
        {
            populateList(ops);
            return calculateTotal();   
        }
    
        void populateList(vector<string>& input)
        {
            int index, size = input.size();
            DataPoint temp;
            
            for(index = 0; index < size; index++)
            {
                if(input[index] == "C" || input[index] == "c")
                {
                    temp.points = 0;
                    temp.type = 'C';
                    temp.valid = false;
                }
                else if(input[index] == "D" || input[index] == "d")
                {
                    temp.points = 0;
                    temp.type = 'D';
                    temp.valid = true;
                }
                else if(input[index] == "+")
                {
                    temp.points = 0;
                    temp.type = '+';
                    temp.valid = true;    
                }
                else
                {
                    temp.points = atoi(input[index].c_str());
                    temp.type = 'I';
                    temp.valid = true;  
                }    
                temp.index = index;
                
                structList.push_back(temp);
            }    
        }    
    
        int calculateTotal()
        {
            int total = 0;
            int index, size = structList.size();
            DataPoint* lastValid = NULL;
            DataPoint* beforeLastValid = NULL;
            
            for(index = 0; index < size; index++) 
            {
                if(index > 0 && structList[index].type == 'C')
                {
                    lastValid = getLastValid(index - 1);
                    lastValid->valid = false;
                }  
                if(index > 0 && structList[index].type == 'D')
                {
                    lastValid = getLastValid(index - 1);
                    structList[index].points = lastValid->points * 2;
                } 
                if(index > 0 && structList[index].type == '+')
                {
                    lastValid = getLastValid(index - 1);
                    beforeLastValid = getLastValid(lastValid->index - 1);
                    structList[index].points = lastValid->points + beforeLastValid->points;
                } 
            }    
                        
            for(index = 0; index < size; index++) 
            {
                if(structList[index].valid)
                {    
                    total += structList[index].points;
                }        
            }   
            
            return total; 
        }    
    
        DataPoint* getLastValid(int current)
        {
            int index = current;
            DataPoint* lastValid = &structList[index];
            
            while(lastValid != NULL && index > 0 && !lastValid->valid) 
            {
                index--;
                lastValid = &structList[index];
            }     
            
            return lastValid;
        }
    
    
        vector<DataPoint> structList;
};
