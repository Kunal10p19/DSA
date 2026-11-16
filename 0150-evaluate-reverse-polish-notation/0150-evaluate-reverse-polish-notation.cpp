
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {
            string ch = tokens[i];

            // If token is an operator
            if (ch == "+" || ch == "-" || ch == "*" || ch == "/") {

                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                if (ch == "+") {
                    st.push(a + b);
                }
                else if (ch == "-") {
                    st.push(a - b);
                }
                else if (ch == "*") {
                    st.push(a * b);
                }
                else if (ch == "/") {
                    st.push(a / b);
                }
            }
            else {
                // Convert string number to integer
                st.push(stoi(ch));
            }
        }

        return st.top();
    }
};
