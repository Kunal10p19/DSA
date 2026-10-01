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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = head;
        int count = 0;

        while (temp != nullptr) {
            temp = temp->next;
            count++;
        }

        int ans = count - n + 1;

        if (ans == 1) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* current = head;
        ListNode* prev = nullptr;

        for (int i = 1; i < ans; i++) {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
        delete current;

        return head;
    }
};