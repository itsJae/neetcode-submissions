class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> st;
        vector<pair<int, int>> cars;

        for (int i = 0; i < position.size(); ++i) 
            cars.push_back({position[i], speed[i]});

        sort(cars.begin(), cars.end(), greater<pair<int, int>>());

        for (auto &p : cars) {
            double time = static_cast<double>(target - p.first) / p.second;

            if (st.empty() || st.top() < time)
                st.push(time);
        }

        return st.size();
    }
};
