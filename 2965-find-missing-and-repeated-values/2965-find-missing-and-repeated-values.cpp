class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int l=grid.size()*grid.size();
    vector<int> a(l+1);
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            a[grid[i][j]]+=1;
        }
    }
    int missing, repeated;
    for(int i=1;i<a.size();i++){
        if(a[i]==0){
            missing=i;
        }
        if(a[i]==2){
            repeated=i;
        }
    }
    return {repeated, missing};
}
};