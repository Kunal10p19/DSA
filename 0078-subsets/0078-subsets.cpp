class Solution {
public:

    vector<vector<int>> Ans;
    int n;
    void Helper(vector<int> &op,vector<int> &nums,int startIndex){

        // base case(s)
        if(startIndex == n){
            Ans.push_back(op);
            return;
        }

        // recurisve case(s)

        // choice 1: you take the current element
        op.push_back(nums[startIndex]);
        Helper(op,nums,startIndex + 1);

        // backtracking step
        op.pop_back();

        // choice 2: you neglect the current element;
        Helper(op,nums,startIndex + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums){
        
        vector<int> op;
        n = nums.size();

        // call the helper function
        Helper(op,nums,0);

        return Ans;
    }
};