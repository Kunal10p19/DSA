

class Solution {
public:
void f(vector<int>& candidates, vector<vector<int>>& ans, vector<int> temp,
        int target, int i){
            //base case
       if(i==candidates.size()){
           if(target == 0) ans.push_back(temp);
           return;
       }
       // call
       if(candidates[i]<=target){
            temp.push_back(candidates[i]);
            f(candidates, ans, temp, target - candidates[i], i);
            temp.pop_back();
       }
       f(candidates, ans, temp, target, i+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        f(candidates, ans, temp, target, 0);
        return ans;
    }
};