/*

Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.

Example 1:

Input: "UD"
Output: true

Example 2:

Input: "LL"
Output: false


*/

class Solution 
{
    public:
        
        bool judgeCircle(string moves) 
        {
            int length = moves.length();
            int counter = 0, upMoves = 0, downMoves = 0, leftMoves = 0, rightMoves = 0;

            while(counter < length)
            {
                if(moves[counter] == 'U')
                {
                    upMoves++;
                }    
                else if(moves[counter] == 'D')
                {
                    downMoves++;
                } 
                else if(moves[counter] == 'L')
                {
                    leftMoves++;
                }                 
                else if(moves[counter] == 'R')
                {
                    rightMoves++;
                } 
                
                counter++;
            } 
            
            if(upMoves == downMoves && leftMoves == rightMoves)
            {
                return true;
            }    
            
            return false;
        }
};  
