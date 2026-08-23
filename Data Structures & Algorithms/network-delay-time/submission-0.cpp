class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            pair<int, int> minV = pq.top();
            pq.pop();

            for (int i = 0; i < times.size(); ++i) {
                if (times[i][0] == minV.second) {
                    int u = times[i][0];
                    int v = times[i][1];
                    int weight = times[i][2];
                
                    if (dist[v] > dist[u] + weight) {
                        dist[v] = dist[u] + weight;
                        pq.push({dist[v], v});
                    }
                }
            }
        }

        int max = 0;
        for (int i = 1; i < dist.size(); ++i) {
            if (dist[i] == INT_MAX) return -1;
            if (dist[i] > max) {
                max = dist[i];
            }
        }

        return max;
    }
};
