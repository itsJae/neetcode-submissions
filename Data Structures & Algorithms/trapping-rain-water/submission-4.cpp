class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxLeft = 0;
        int maxRight = height[r];
        int ans = 0;

        while (l <= r) {
            // cout << "left: " << l << ", right: " << r << endl;

            if (maxLeft <= maxRight) {
                int res = maxLeft - height[l];
                // cout << "maxLeft: " << maxLeft << ", res: " << res << endl;
                
                if (res >= 0) 
                    ans += res; 
                
                maxLeft = max(maxLeft, height[l]);
                ++l;
            } else {
                int res = maxRight - height[r];
                // cout << "maxRight: " << maxRight << ", res: " << res << endl;
                if (res >= 0) 
                    ans += res;

                maxRight = max(maxRight, height[r]);
                --r;
            }
        }

        return ans;
    }
    // int trap(vector<int>& height) {
    //     int n = height.size();
    //     vector<pair<int, int>> walls(n);

    //     // Left Max
    //     int maxLeft = 0;
    //     int prev = -1;

    //     for (int i = 0; i < height.size(); ++i) {
    //         if (prev > maxLeft) {
    //             maxLeft = prev;
    //         }

    //         walls[i].first = maxLeft;
    //         prev = height[i];
    //     }

    //     // Right Max
    //     int maxRight = 0;
    //     prev = -1;

    //     for (int i = n - 1; i >= 0; --i) {
    //         if (prev > maxRight) {
    //             maxRight = prev;
    //         }

    //         walls[i].second = maxRight;
    //         prev = height[i];
    //     }

    //     int cnt = 0;
    //     for (int i = 0; i < height.size(); ++i) {
    //         if (min(walls[i].first, walls[i].second) - height[i] < 0) continue;
    //         cnt += min(walls[i].first, walls[i].second) - height[i];
    //     }

    //     return cnt;
    // }
};
