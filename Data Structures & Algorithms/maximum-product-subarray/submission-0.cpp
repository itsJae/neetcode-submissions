class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> minArr(n);
        vector<int> maxArr(n);
        minArr[0] = nums[0];
        maxArr[0] = nums[0];
        
        for (int i = 1; i < n; ++i) {
            int curr = nums[i];
            int a = curr * maxArr[i - 1];            
            int b = curr * minArr[i - 1];

            maxArr[i] = max({a, b, curr});            
            minArr[i] = min({a, b, curr});            
        }

        return *max_element(maxArr.begin(), maxArr.end());
    }
};
