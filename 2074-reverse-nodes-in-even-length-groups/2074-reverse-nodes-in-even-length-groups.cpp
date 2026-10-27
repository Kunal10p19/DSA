class Solution {
public:

    int count(ListNode* head, int limit){
        int cnt = 0;

        while(head != NULL && cnt < limit){
            cnt++;
            head = head->next;
        }

        return cnt;
    }

    ListNode* reverse(ListNode* head, int cnt) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(cnt--){
            ListNode* next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        int grpsize = 1;

        while(curr != NULL){

            // Find actual size of current group
            int cnt = count(curr, grpsize);

            // Find where the next group starts
            ListNode* nxtgrp = curr;

            for(int i = 0; i < cnt; i++)
                nxtgrp = nxtgrp->next;

            // Reverse if actual group size is even
            if(cnt % 2 == 0){

                ListNode* grpstrt = curr;

                curr = reverse(curr, cnt);

                // Connect previous group with reversed group
                if(prev == NULL)
                    head = curr;
                else
                    prev->next = curr;

                // Connect reversed group with next group
                grpstrt->next = nxtgrp;

                // Old start becomes the last node
                prev = grpstrt;

                // Move to next group
                curr = nxtgrp;
            }

            // If group size is odd, don't reverse
            else{

                for(int i = 0; i < cnt; i++){
                    prev = curr;
                    curr = curr->next;
                }
            }

            grpsize++;
        }

        return head;
    }
};