class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpMin(n);
        vector<int> dpMax(n);

        for (auto num : nums) {
            if (num == 0) num = 1;
        }

        dpMin[0] = nums[0];        
        dpMax[0] = nums[0];
        // cout << nums[0] << ", " << nums[0] << endl;

        for (int i = 1; i < n; ++i) {
            int pMin = min(min(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i]), nums[i]);
            int pMax = max(max(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i]), nums[i]);
            
            // cout << pMin << ", " << pMax << endl;

            if (pMin < pMax) {
                dpMin[i] = pMin;
                dpMax[i] = pMax;
            } else {
                dpMin[i] = pMax;
                dpMax[i] = pMin;
            }
        }   

        return *max_element(dpMax.begin(), dpMax.end());
    }
};
