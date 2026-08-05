class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> v;
        int n = nums.size();

        for(int i=0; i<n; i++){
            v[nums[i]]++;
        }

        for(int j=0; j<n; j++){
            if(v[nums[j]] > n/2){
                return nums[j];
            }
        }
        return -1;
    }
};