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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        
        ListNode* s = head;
        ListNode* f = head;
        bool cycle = false;
        while (f != NULL && f->next != NULL) {
            s = s->next;
            f = f->next->next;
            if (s == f) {
                cycle = true;
                break;
            }
        }
        
        if (!cycle) {
            return NULL;
        }
        
        s = head;
        while (s != f) {
            s = s->next;
            f = f->next;
        }
        
        return s;
    }
};

