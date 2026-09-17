class Solution {
public:
    bool helperFunction(vector<int> &nums, int threshold, int d)
    {
        long long sum = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            sum += ((nums[i] + d - 1) / d);
        }

        return (sum <= threshold);
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int ans = INT_MAX;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;

            if(helperFunction(nums, threshold, mid))
            {
                ans = min(ans, mid);
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return ans;
    }
};