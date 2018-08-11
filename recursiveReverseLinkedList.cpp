/*

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

*/

/*
 * Definition for singly-linked list.
 * struct ListNode 
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution 
{

    public:
    
    ListNode* reverseList(ListNode* head) 
    {
        if(head == NULL)
        {
            return NULL;
        }
        else
        {
            return reverseListHelper(head);
        }
    }
    
    ListNode* reverseListHelper(ListNode* node) 
    {
        ListNode* ptr;
        
        if(node != NULL && node->next == NULL)
        {
            return node;
        }
        else
        {
            ptr = reverseListHelper(node->next);
            (node->next)->next = node;
            node->next = NULL;
            
            return ptr;
        }
        
    }
};
