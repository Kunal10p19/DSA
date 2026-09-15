class Solution {
    private:
    long long func(vector<int> piles, int k) {
        long long sum = 0;
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            sum = sum + ceil((double)(piles[i]) / (double)(k));
        }
        return sum;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while (low <= high) {
            int mid = (low + high) / 2;
            if (func(piles, mid) <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};