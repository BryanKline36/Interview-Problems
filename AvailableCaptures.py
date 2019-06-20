'''
On an 8 x 8 chessboard, there is one white rook.  There also may be empty squares, white bishops, and black pawns.  These are given as characters 'R', '.', 'B', and 'p' respectively. Uppercase characters represent white pieces, and lowercase characters represent black pieces.

The rook moves as in the rules of Chess: it chooses one of four cardinal directions (north, east, west, and south), then moves in that direction until it chooses to stop, reaches the edge of the board, or captures an opposite colored pawn by moving to the same square it occupies.  Also, rooks cannot move into the same square as other friendly bishops.

Return the number of pawns the rook can capture in one move.

Example 1:

Input: [
[".",".",".",".",".",".",".","."],
[".",".",".","p",".",".",".","."],
[".",".",".","R",".",".",".","p"],
[".",".",".",".",".",".",".","."],
[".",".",".",".",".",".",".","."],
[".",".",".","p",".",".",".","."],
[".",".",".",".",".",".",".","."],
[".",".",".",".",".",".",".","."]]

Output: 3
Explanation: 
In this example the rook is able to capture all the pawns.

Note:

    board.length == board[i].length == 8
    board[i][j] is either 'R', '.', 'B', or 'p'
    There is exactly one cell with board[i][j] == 'R'
'''

class Solution(object):
    
    def numRookCaptures(self, board):
        
        rookPosition = self.getRookPosition(board)
        
        if rookPosition != (-1, -1):
            return self.checkDirection(board, rookPosition, 'e') + self.checkDirection(board, rookPosition, 'w') + self.checkDirection(board, rookPosition, 'n') + self.checkDirection(board, rookPosition, 's') 
        else:
            return 0
        
    def getRookPosition(self, board):
        
        i = 0
        for row in board:
            j = 0
            for column in row:
                if column == 'R':
                    return (i, j)
                j += 1
            i += 1
            
        return (-1, -1)
    
    def checkDirection(self, board, rookPosition, direction):
    
        index = 0
        constant = 1
        edge = 0
    
        if direction == 'e':
            index = 1
            constant = 0
            edge = len(board[0]) - 1
        elif direction == 'w':
            index = 1
            constant = 0
        elif direction == 's':
            edge = len(board) - 1
        
        rookIndex = rookPosition[index]
            
        while not self.checkEdge(rookIndex, edge, direction):
            if self.checkPosition(board, rookIndex, rookPosition[constant], direction) == 'p':
                return 1  
             
            if self.checkPosition(board, rookIndex, rookPosition[constant], direction) == 'B':
                return 0
              
            rookIndex = self.advancePosition(rookIndex, direction)
              
        return 0       
              
              
    def checkEdge(self, rookIndex, edge, direction):
        
        if direction == 'e' or direction == 's':
            return rookIndex > edge
        else:
            return rookIndex < edge
              
    def checkPosition(self, board, rookIndex, rookConstant, direction):
        
        if direction == 'e' or direction == 'w':
            return board[rookConstant][rookIndex]
        else:
            return board[rookIndex][rookConstant]
              
    def advancePosition(self, rookIndex, direction):

        if direction == 'e' or direction == 's':
            return rookIndex + 1
        else:
            return rookIndex - 1
