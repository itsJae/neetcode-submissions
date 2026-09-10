class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0;
        int r = k - 1;
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        
        for (int i = l; i < nums.size() && i < k - 1; ++i) {
            pq.push({nums[i], i});
        }

        while (r < nums.size()) {
            // cout << "l: " << l << ", r: " << r << endl;
            pq.push({nums[r], r});
            int maxVal = -1;

            while (true) {
                pair<int, int> dq = pq.top();

                if (dq.second >= l && dq.second <= r) {
                    maxVal = dq.first;                    
                    break;
                } else {
                    pq.pop();
                }
            }

            // cout << "maxVal: " << maxVal << endl;

            ans.push_back(maxVal);
            
            ++l;
            ++r;
        }

        return ans;
    }
};
