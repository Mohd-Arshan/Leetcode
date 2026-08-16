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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1 = list1;
        ListNode* p2 = list2;

        ListNode* ans = new ListNode(INT_MIN);
        ListNode* head = ans;

        while(p1 && p2){

            if(p1->val < p2-> val){
                ans->next = p1;
                p1 = p1->next;
            }
            else{
                ans->next = p2;
                p2 = p2->next;
            }
            ans = ans ->next;
        }

        while(p1){
            ans->next = p1;
            p1 = p1->next;

            ans = ans->next;
        }

        while(p2){
            ans->next = p2;
            p2 = p2->next;

            ans = ans->next;
        }

        return head->next;

    }
};