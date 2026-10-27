
class Solution {
public:
    int count(ListNode* head, int limit) {
        int cnt = 0;

        while (head != nullptr && cnt < limit) {
            cnt++;
            head = head->next;
        }

        return cnt;
    }

    ListNode* reverse(ListNode* head, int cnt) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (cnt--) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* left = head;
        ListNode* right = nullptr;
        ListNode* nextleft = nullptr;
        ListNode* prevleft = nullptr;

        int grpsize = 1;

        while (left != nullptr) {
            int cnt = count(left, grpsize);

            right = left;

            for (int i = 1; i < cnt; i++) {
                right = right->next;
            }

            nextleft = right->next;

            if (cnt % 2 == 0) {
                right = reverse(left, cnt);

                if (prevleft != nullptr) {
                    prevleft->next = right;
                } else {
                    head = right;
                }

                left->next = nextleft;
                prevleft = left;
            } else {
                prevleft = right;
            }

            left = nextleft;
            grpsize++;
        }

        return head;
    }
};
