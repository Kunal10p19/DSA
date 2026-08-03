class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos;
        vector<int> neg;

        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }

        int index = 0;
        int j = 0;
        int k = 0;
        bool flag = true;

        while(index < n){
            if(flag == true){
                nums[index++] = pos[j++];
                flag = false;
            }
            else{
                nums[index++] = neg[k++];
                flag = true;
            }
        }

        return nums;
    }
};