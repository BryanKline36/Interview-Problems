'''
We are given a matrix with R rows and C columns has cells with integer coordinates (r, c), where 0 <= r < R and 0 <= c < C.

Additionally, we are given a cell in that matrix with coordinates (r0, c0).

Return the coordinates of all cells in the matrix, sorted by their distance from (r0, c0) from smallest distance to largest distance.  Here, the distance between two cells (r1, c1) and (r2, c2) is the Manhattan distance, |r1 - r2| + |c1 - c2|.  (You may return the answer in any order that satisfies this condition.)

 

Example 1:

Input: R = 1, C = 2, r0 = 0, c0 = 0
Output: [[0,0],[0,1]]
Explanation: The distances from (r0, c0) to other cells are: [0,1]

Example 2:

Input: R = 2, C = 2, r0 = 0, c0 = 1
Output: [[0,1],[0,0],[1,1],[1,0]]
Explanation: The distances from (r0, c0) to other cells are: [0,1,1,2]
The answer [[0,1],[1,1],[0,0],[1,0]] would also be accepted as correct.

Example 3:

Input: R = 2, C = 3, r0 = 1, c0 = 2
Output: [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
Explanation: The distances from (r0, c0) to other cells are: [0,1,1,2,2,3]
There are other answers that would also be accepted as correct, such as [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]].

 

Note:

    1 <= R <= 100
    1 <= C <= 100
    0 <= r0 < R
    0 <= c0 < C

'''

class Solution(object):
    
    def allCellsDistOrder(self, R, C, r0, c0):
        
        output = [[r0, c0]]
        counter = 1
        
        while self.checkDistance(counter, R, C, r0, c0):
            distances = self.getDistances(counter, R, C, r0, c0)
            
            for distance in distances:
                output.append(distance)
                
            counter += 1
                
        return output
    
    def checkDistance(self, counter, R, C, r0, c0):
        
        distances = self.getPossibleDistances(counter, r0, c0)
        
        for distance in distances:
            if (distance[0] >= 0 and distance[0] < R) and (distance[1] >= 0 and distance[1] < C):
                return True
        
        return False
        
    def getDistances(self, counter, R, C, r0, c0):

        output = []
        distances = self.getPossibleDistances(counter, r0, c0)
        
        for distance in distances:
            if (distance[0] >= 0 and distance[0] < R) and (distance[1] >= 0 and distance[1] < C):
                output.append(distance)
        
        return output
        
    def getPossibleDistances(self, counter, r0, c0):
    
        stepCounter = 0
        distances = []
        steps = []
        
        while stepCounter <= counter:
            coordinate = [counter - stepCounter, stepCounter]
            steps.append(coordinate)
            stepCounter += 1
        
        for step in steps:
            upperLeft = (r0 - step[0], c0 - step[1])
            distances.append(upperLeft)
            upperRight = (r0 + step[0], c0 - step[1])
            distances.append(upperRight)
            lowerLeft = (r0 - step[0], c0 + step[1])
            distances.append(lowerLeft)
            lowerRight = (r0 + step[0], c0 + step[1])
            distances.append(lowerRight)
            
        tempSet = set(distances)
        distances = list(tempSet)
            
        return distances
    
