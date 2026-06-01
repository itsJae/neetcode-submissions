class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '[' ||
                c == '(' ||
                c == '{') 
            {
                st.push(c);
                std::cout << "pushing" << c << std::endl;
            } else {
                if (st.size() > 0) {
                    if (st.top() == '[' && c == ']' ||
                        st.top() == '(' && c == ')' ||
                        st.top() == '{' && c == '}') 
                    {
                        st.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};
