class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int y = st.top();
                st.pop();
                
                int x = st.top();
                st.pop();

                if (token == "+") st.push(x + y);
                else if (token == "-") st.push(x - y);
                else if (token == "*") st.push(x * y);
                else st.push(x / y);
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
