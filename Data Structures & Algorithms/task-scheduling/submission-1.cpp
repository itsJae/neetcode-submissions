class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;
        int cnt = 0;
        
        for (int i = 0; i < tasks.size(); ++i) {
            if (!m.count(tasks[i])) m[tasks[i]] = 1;
            else m[tasks[i]]++;
        } 

        priority_queue<pair<int, char>> pq;
        for (auto& [k, v] : m) 
            pq.push({v, k});

        while (!pq.empty()) {
            vector<pair<int, char>> dqArr;
            pair<int, char> dq = pq.top();
            pq.pop();
            ++cnt;
            
            dq.first--;
            if (dq.first > 0) dqArr.push_back(dq);

            for (int i = 0; i < n; ++i) {
                if (pq.empty()) {
                    if (dq.first == 0) return cnt;
                    ++cnt;
                    continue;
                }

                pair<int, char> tmp = pq.top();
                pq.pop();
                ++cnt;

                tmp.first--;
                if (tmp.first > 0) dqArr.push_back(tmp);
            }

            for (int i = 0; i < dqArr.size(); ++i)
                pq.push(dqArr[i]);
        }

        return cnt;
    }
};
