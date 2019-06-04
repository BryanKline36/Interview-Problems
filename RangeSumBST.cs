/*

Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

The binary search tree is guaranteed to have unique values.

Example 1:

Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
Output: 32

Example 2:

Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
Output: 23

Note:

    The number of nodes in the tree is at most 10000.
    The final answer is guaranteed to be less than 2^31.

*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */

public class Solution 
{
    public int RangeSumBST(TreeNode root, int L, int R) 
    {
        int result = 0;
        
        if(root != null)
        {
            if(!(root.val < L) && root.left != null)
            {
                result += RangeSumBST(root.left, L, R);
            }
            
            if(!(root.val > R) && root.right != null)
            {
                result += RangeSumBST(root.right, L, R);
            }
            
            if(root.val >= L && root.val <= R)
            {
                result += root.val;
            }
        }
        
        return result;
    }    
}
