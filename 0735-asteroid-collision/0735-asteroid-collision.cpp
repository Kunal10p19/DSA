class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for(int i=0; i<n; i++){
            int c = asteroids[i];

            if(c > 0){
                st.push(c);
            }
            else{
                while(!st.empty() && st.top() > 0 && st.top() < abs(c)){
                    st.pop();
                }

                if(!st.empty() && st.top() == abs(c)){
                    st.pop();
                }
                else{
                    if(st.empty() || st.top() < 0){
                    st.push(c);
                }
                }
            }
        }

        vector<int> ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};