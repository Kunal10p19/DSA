class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* temp = nullptr;
        ListNode* curr = head;

        while(curr != nullptr){
            temp = curr->next;

            curr->next = prev;

            prev = curr;
            curr = temp;
        }
        return prev;
    }
};