class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) 
            return false;

        unordered_map<int, int> m;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto x : hand) 
            ++m[x];
        
        for (auto& [k, v] : m)
            pq.push(k);

        while (!pq.empty()) {
            int minVal = pq.top();
            int target = minVal;

            for (int i = 0; i < groupSize; ++i) {
                if (m.count(target) == 0) 
                    return false;
                    
                --m[target];
                
                if (m[target] == 0) {
                    int popped = pq.top();
                    pq.pop();

                    if (popped != target)
                        return false;
                }

                ++target;
            }
        }

        return true;
    }
};
