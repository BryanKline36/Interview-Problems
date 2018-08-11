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
        int index, size;
        ListNode* ptr = head;
        vector<ListNode*> ptrVector;

        if(ptr == NULL)
        {
            return NULL;
        }
        else
        {
            while(ptr != NULL)
            {
                ptrVector.push_back(ptr);
                ptr = ptr->next;
            }

            size = ptrVector.size();
            for(index = size - 1; index > 0; index--)
            {
                ptrVector[index]->next = ptrVector[index - 1]; 
            }

            ptrVector[index]->next = NULL;

            return ptrVector[size - 1]; 
        }
    }    
};
