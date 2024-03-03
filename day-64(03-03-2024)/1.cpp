/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int len(ListNode *head)
    {
        int l = 0;
        while(head != NULL){
            l++;
            head = head->next;
        }
        return l;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = len(head);
        int t = l - n;
        ListNode *spre,*pre,*temp;
        pre = NULL;
        spre = NULL;
        temp = head;
        if(t == 0)
            return head->next;
        while(t > 0)
        {
            spre = temp;
            temp = temp->next;
            pre = temp;
            t--;
        }
        if(spre != NULL)
        {
            if(pre != NULL)
                spre->next = pre->next;
            return head;
        }
        else
            return pre;
        
        return head;
    }
};