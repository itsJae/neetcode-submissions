class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;

        int maxCnt = 0;
        int l = 0;
        int r = 1;

        while (r < n) {
            if (arr[r - 1] == arr[r]) {
                maxCnt = max(maxCnt, 1);
                l = r;
                ++r;
                continue;
            }
            
            if (arr[r - 1] < arr[r]) {
                if (r - 2 >= 0 && arr[r - 2] < arr[r - 1]) {
                    l = r - 1;
                }
            } else {
                if (r - 2 >= 0 && arr[r - 2] > arr[r - 1]) {
                    l = r - 1;
                }
            }

            if (r - l + 1 > maxCnt) {
                maxCnt = r - l + 1;
            }

            ++r;
        }
        
        return maxCnt;
    }
};