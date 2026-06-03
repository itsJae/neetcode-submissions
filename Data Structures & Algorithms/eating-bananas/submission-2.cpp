class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int left = 0;
        int right = piles.back();
        int min_rate = piles.back();

        while (left <= right) {
            int mid = midpoint(left, right);
            int total_hour = 0;

            if (mid == 0) return min_rate;

            for (int pile : piles) {
                total_hour += ceil(static_cast<double>(pile) / mid);
            }

            if (total_hour <= h) {
                if (min_rate > mid) 
                    min_rate = mid;
                
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return min_rate;
    }
};
