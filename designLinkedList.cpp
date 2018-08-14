/*

Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

    get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
    addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
    addAtTail(val) : Append a node of value val to the last element of the linked list.
    addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
    deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.

Example:

MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
linkedList.get(1);            // returns 2
linkedList.deleteAtIndex(1);  // now the linked list is 1->3
linkedList.get(1);            // returns 3

Note:

    All values will be in the range of [1, 1000].
    The number of operations will be in the range of [1, 1000].
    Please do not use the built-in LinkedList library.

*/

class MyLinkedList 
{

    public:

    struct ListNode
    {
        int val;
        ListNode* next;
        
        ListNode(int x) : val(x), next(NULL) {}
    };
    
    /** Initialize your data structure here. */
    MyLinkedList() 
    {
        head = NULL;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) 
    {
        ListNode* temp = getNodeAtIndex(index);
        
        if(temp == NULL)
        {
            return -1;
        }
        else
        { 
            return temp->val;
        }
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) 
    {
        ListNode* temp;
        
        temp = new ListNode(val);
        temp->next = head;
        head = temp;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) 
    {
        ListNode* node;
        
        if(size == 0 || head == NULL)
        {
            addAtHead(val);
        }
        else
        {
            node = getNodeAtIndex(size - 1);
            node->next = new ListNode(val);
            (node->next)->next = NULL;
            size++;
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) 
    {
        ListNode* node;
        ListNode* previousNode;
        
        if(index == 0)
        {
            addAtHead(val);
        }
        else if(index > 0 && index <= size)
        {
            previousNode = getNodeAtIndex(index - 1);
            node = getNodeAtIndex(index);
            previousNode->next = new ListNode(val);
            (previousNode->next)->next = node;
            size++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) 
    {
        ListNode* node;
        ListNode* previousNode;
        
        if(index == 0)
        {
            node = head;
            head = head->next;
            delete node;
            size--;
        }
        else if(index > 0 && index < size)
        {
            previousNode = getNodeAtIndex(index - 1);
            node = getNodeAtIndex(index);
            
            if(node != NULL && previousNode != NULL)
            {
                previousNode->next = node->next;
                delete node;
                size--;
            }    
        }
    }
    
    private:
    
    ListNode* getNodeAtIndex(int index)
    {
        int counter = 0;
        ListNode* temp = head;
        
        if(index > size - 1 || index < 0 || head == NULL)
        {
            return NULL;
        }
        else
        {
            while(temp != NULL && counter < index)
            {
                temp = temp->next;
                counter++;
            }
            
            return temp;
        }
    }
    
};
