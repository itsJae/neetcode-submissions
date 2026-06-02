class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        stack<int> st;
        int i = 0;

        while (i < temperatures.size()){
            if (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                result[st.top()] = i - st.top();
                st.pop();
            } else {
                st.push(i);
                i++;
            }
        }

        return result;
    }
};
