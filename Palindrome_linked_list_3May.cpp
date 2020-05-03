//Problem 3
//https://leetcode.com/problems/palindrome-linked-list/

// The code just below has been optimised.
// Initial accepted submission has been commented below.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL||head->next==NULL)
            return true;
        
        ListNode* sptr, *fptr, *prev, *temp;
        prev = NULL;
        sptr=fptr=head;
        while(fptr!=NULL&&fptr->next!=NULL)
        {
            fptr= fptr->next->next;
            
            temp = sptr->next;
            sptr->next = prev;
            prev = sptr;
            sptr = temp;
            
        }
        if(fptr!=NULL)
        {
            sptr = sptr->next;
        }
        
        while (prev->val == sptr->val){
            if (sptr->next==NULL)
            {
                return true;
            }
            prev = prev->next;
            sptr = sptr->next;
        }
        return false; 
    }
};

/*

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL||head->next==NULL)
            return true;
        if(head->next->next==NULL)
        {
            if(head->val==head->next->val)
                return true;
            else
                return false;
        }
        
        ListNode* sptr, *fptr, *prev;
        sptr=fptr=head;
        while(fptr!=NULL&&fptr->next!=NULL)
        {
            fptr= fptr->next->next;
            prev=sptr;
            sptr=sptr->next;
        }
        if(fptr!=NULL)
        {
            prev=prev->next;
            sptr=sptr->next;
        }
        ListNode* t1, *t2, *t3;
        t1=sptr;
        t2=sptr->next;
        if(t2==NULL)
        {
            if(sptr->val==head->val)
                return true;
            else
                return false;
        }
        t3=t2->next;
        t1->next=NULL;
        while(t3!=NULL)
        {
            t2->next = t1;
            t1 = t2;
            t2=t3;
            t3=t3->next;
        }
        t2->next = t1;
        prev->next = t2;
        
        fptr=sptr=head;
        while(fptr!=NULL&&fptr->next!=NULL)
        {
            fptr= fptr->next->next;
            sptr=sptr->next;
        }
        if(fptr==NULL)
            t1 = sptr;
        else
            t1 = sptr->next;
        t2 = head;
        while(t1!=NULL)
        {
            //cout<<t1->val<<' '<<fptr->val<<endl;
            if(t1->val!=t2->val)
                return false;
            t1=t1->next;
            t2=t2->next;
        }
        
        return true;
        
        
        
    }
};

*/
