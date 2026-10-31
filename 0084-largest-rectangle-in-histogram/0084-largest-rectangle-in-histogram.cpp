class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int n = heights.size();

       vector<int> left(n);
       vector<int> right(n);
       stack<int> st;

       // right smaller
       for(int i=n-1; i>=0; i--){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }

        if(st.empty()){
            right[i] = n;
        }
        else{
            right[i] = st.top();
        }
        st.push(i);
       }

       while(!st.empty()){
        st.pop();
       }

       //left smaller
       for(int i=0; i<n; i++){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }

        if(st.empty()){
            left[i] = -1;
        }
        else{
            left[i] = st.top();
        }
        st.push(i);
       }

       int ans = 0;

       for(int i=0; i<n; i++){
        int width = right[i] - left[i] - 1;
        int area = heights[i] * width;
        ans = max(ans, area);
       }

       return ans;
    }
};