class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for (int i = 0; i < operations.size(); ++i) {
            string op = operations[i];

            if (op == "+") {
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                st.push(b);
                st.push(a);
                st.push(a + b);
            } else if (op == "C") {
                st.pop();
            } else if (op == "D") {
                st.push(st.top() * 2);
            } else {
                int toPush = stoi(operations[i]);
                st.push(toPush);
            }
            // cout << "curr: " << op << ", top: " << st.top() << endl;
        }

        int sum = 0;
        while (!st.empty()) {
            // cout << "adding: " << st.top() << endl;
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};