/*

Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

Example 1:

Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].

Note:

    The range of node's value is in the range of 32-bit signed integer.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode 
 * {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct NodeData
{
    int depth = -1;
    int data = -1;
};

bool compareNodeData(const NodeData& left, const NodeData& right)
{
    return (left.depth < right.depth);
}

class Solution 
{
    public:
    
    vector<double> averageOfLevels(TreeNode* root) 
    {
        int index, size, nodeCount = 0, currentDepth = 0;
        double tempResult = 0.0;
        vector<double> result;
        buildDataVector(root, currentDepth);
        
        sort(treeData.begin(), treeData.end(), compareNodeData);
        size = treeData.size();
        for(index = 0; index < size; index++)
        {
            if(currentDepth != treeData[index].depth)
            {
                tempResult /= nodeCount;
                result.push_back(tempResult);
                
                tempResult = 0.0;
                nodeCount = 0;
                currentDepth++;
            }
            
            tempResult += treeData[index].data;
            cout << tempResult <<  ":" << treeData[index].data << endl;
            nodeCount++;
            
            if(index == size - 1)
            {
                tempResult /= nodeCount;
                result.push_back(tempResult);  
            } 
        }
        
        return result;
    }
    
    private:
    
    void buildDataVector(TreeNode* nodePointer, int depth)
    {
        NodeData tempNodeData;
        
        if(nodePointer != NULL)
        {
            tempNodeData.depth = depth;
            tempNodeData.data = nodePointer->val;
            treeData.push_back(tempNodeData);
            
            buildDataVector(nodePointer->left, depth + 1);
            buildDataVector(nodePointer->right, depth + 1);
        }
    }
    
    vector<NodeData> treeData;
};
