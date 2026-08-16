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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL, *cur = head, *next;

        while(cur){
            // next 
            next = cur -> next;
            //reverse the pointers direction
            cur->next = prev;
            //store previous pointer
            prev = cur;

            //upadate curr
            cur = next;
        }

        return prev;
    }
};