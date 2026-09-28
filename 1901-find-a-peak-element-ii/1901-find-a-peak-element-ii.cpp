class Solution {
public:
    int maxRowElement(vector<vector<int>> &mat , int n, int col)
    {
        int max = mat[0][col];
        int index = 0;
        for(int i=0 ; i<n ; i++)
            if(mat[i][col] > max)
            {
                max=mat[i][col];
                index=i;
            }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0 , high = m-1;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            int maxRowIndex = maxRowElement(mat ,n ,mid);
            int left = mid - 1 >= 0 ? mat[maxRowIndex][mid-1] : -1;
            int right = mid + 1 < m ? mat[maxRowIndex][mid+1] : -1;
            if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right)
                return {maxRowIndex,mid};
            else if(mat[maxRowIndex][mid] < left)
                high = mid-1;
            else
                low = mid+1;
        }
        return {-1,-1};
    }
};