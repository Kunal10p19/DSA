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
    void reverse(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (k--) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }

public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* left = head;
        ListNode* right;
        ListNode* prevleft = nullptr;
        ListNode* res = nullptr;

        int k = 2;

        while (true) {
            right = left;

            for (int i = 0; i < k - 1; i++) {
                if (right == nullptr) {
                    break;
                }
                right = right->next;
            }

            if (right) {
                ListNode* nextleft = right->next;

                reverse(left, k);
                left->next = nextleft;  // Reconnect remaining list

                if (prevleft) {
                    prevleft->next = right;
                }

                if (res == nullptr) {
                    res = right;
                }

                prevleft = left;
                left = nextleft;
            } else {
                if (prevleft) {
                    prevleft->next = left;
                }

                if (res == nullptr) {
                    res = left;
                }
                break;
            }
        }

        return res;
    }
};
