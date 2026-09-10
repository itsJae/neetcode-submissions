class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long long l = *max_element(weights.begin(), weights.end());
        long long r = accumulate(weights.begin(), weights.end(), 0);
        int ans = INT_MAX;

        while (l <= r) {
            int cnt = 0;
            int sum = 0;
            int mid = (l + r) / 2;
            int i = 0;

            while (i < weights.size()) {
                sum += weights[i];

                if (sum > mid) {
                    ++cnt;
                    sum = 0;
                    continue;
                }

                ++i;
            }

            if (sum <= mid) 
                ++cnt;

            if (cnt <= days) {
                ans = min(ans, mid);
                r = mid - 1;
            } else if (cnt > days) {
                l = mid + 1;
            }
        }

        return ans;
    }
};