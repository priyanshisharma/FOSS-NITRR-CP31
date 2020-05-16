
// Problem 24
// https://leetcode.com/problems/design-linked-list/

class Node
{
    public:
    int val;
    Node* next;
    Node(int x)
    {
        val=x;
        next=NULL;
    }
}*head = NULL, *rear = NULL;
int sze = 0;

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        
        head = rear = NULL;
        sze = 0;
           
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        
        if(index<0||index>sze-1)
            return -1;
        
        Node* np = head;
        int i=0;
        for(int i=0;i<index;i++)
            np = np->next;
             
        return np->val;
        
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        
        Node* add = new Node(val);
        
        if(head==NULL)
        {
            head = rear = add;
        }
        else
        {
            add->next = head;
            head = add;
            /*Node* save = head->next;
            head->next = add;
            add->next = save;*/
        }
        sze++;
        
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        
        Node* add = new Node(val);
        if(rear==NULL)
            head = rear = add;
        else
        {
            rear->next = add;
            rear = add;
        }
        sze++;
        
        
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        
        if(index<0||index>sze)
            return;
        Node* add = new Node(val);
        Node*np = head;
        
        if(index==0)
        {
            add->next = head;
            head = add;
            if(rear==NULL)
                rear = add;
            sze++;
            return;
        }
        
        for(int i=0;i<index-1;i++)
            np = np->next;
        
        Node* save = np->next;
        np->next = add;
        add->next = save;
        
        if(index == sze)
            rear = rear->next;
        
        sze++;
        
        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        
        if(index<0||index>sze-1)
            return;
        
        Node*np = head;
        
        if(index==0)
        {
            head=head->next;
            
            if(sze==1)
                rear=head;
            
            sze--;
            
            delete(np);
            return;
        }
        
        for(int i=0;i<index-1;i++)
            np = np->next;
        
        Node* save=np->next;
        np->next=save->next;
        delete(save);
        
        if(index==sze-1)
            rear=np;
        sze--;
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
