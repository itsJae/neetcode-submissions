class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" ||
                tokens[i] == "-" ||
                tokens[i] == "*" ||
                tokens[i] == "/"
            ) {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();

                // cout << op1 << tokens[i] << op2 << endl;
                if (tokens[i] == "+") {
                    st.push(op1 + op2);
                } else if (tokens[i] == "-") {
                    st.push(op2 - op1);
                } else if (tokens[i] == "*") {
                    st.push(op1 * op2);
                } else {
                    st.push(op2 / op1);
                }
            } else {
                st.push(stoi(tokens[i]));
            }

            // cout << "stack top: " << st.top() << endl;
        }
        
        return st.top();
    }
};
