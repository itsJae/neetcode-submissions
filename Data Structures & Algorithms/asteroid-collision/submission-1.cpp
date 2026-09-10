class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;

        st.push(asteroids[0]);

        for (int i = 1; i < asteroids.size(); ++i) {
            int curr = asteroids[i];
            // cout << "top: " << st.top() << ", curr: " << curr << endl;

            if (st.empty() || (curr < 0 && st.top() < 0) || curr > 0) {
                st.push(curr);
                continue;
            }

            cout << "collision" << endl;

            while (true) {
                if (st.empty()) {
                    st.push(curr);
                    break;
                }

                int top = st.top();

                if ((top < 0 && curr < 0) || (top > 0 && curr > 0)) {
                    st.push(curr);
                    break;
                }

                if (top == abs(curr)) {
                    st.pop();
                    break;
                } else if (top < abs(curr)) {
                    st.pop();
                } else {
                    break;
                }
            }
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};