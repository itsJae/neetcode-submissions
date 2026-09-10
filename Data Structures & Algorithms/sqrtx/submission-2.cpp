class Solution {
public:
    int mySqrt(int x) {
        long long l = 0;
        long long r = x;
        long long maxVal = 0;

        while (l <= r) {
            long long mid = (l + r) / 2;
            long long sqr = mid * mid;

            if (sqr == x) {
                return mid;
            } else if (sqr > x) {
                r = mid - 1;
            } else {
                if (sqr > maxVal) {
                    maxVal = mid;
                }

                l = mid + 1;
            }
        }

        return maxVal;
    }
};