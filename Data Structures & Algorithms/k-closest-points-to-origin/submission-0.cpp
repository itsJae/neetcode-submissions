class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
            pair<double, vector<int>>,
            vector<pair<double, vector<int>>>,
            greater<pair<double, vector<int>>>
        > pq;

        for (int i = 0; i < points.size(); ++i) {
            int x = points[i][0];
            int y = points[i][1];
            double dist = sqrt(x * x + y * y);

            // cout << "x: " << x << ", y: " << y << ", dist: " << dist << endl;

            pq.push({dist, points[i]});
        }

        vector<vector<int>> ans;
        for (int i = 0; i < k; ++i) {
            // cout << "dist: " << pq.top().first << endl;
            ans.push_back(pq.top().second);
            pq.pop();
        } 

        return ans;
    }
};
