class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int kadaneSum = 0;
        int currSum = 0;
        int totalSum = 0;

        for (int i = 0; i < n; ++i) {
            totalSum += nums[i];
            currSum += nums[i];

            if (currSum < 0) currSum = 0;
            else if(currSum > kadaneSum) kadaneSum = currSum;
        }

        int minSum = INT_MAX;
        currSum = 0;

        for (int i = 0; i < n; ++i) {
            currSum += nums[i];

            if (currSum > 0) currSum = 0;
            else if (currSum < minSum) minSum = currSum;
        }

        if (kadaneSum == 0)
            kadaneSum = *max_element(nums.begin(), nums.end());

        cout << kadaneSum << endl;
        cout << minSum << endl;

        if (totalSum == minSum) return kadaneSum;

        return totalSum - minSum > kadaneSum ? totalSum - minSum : kadaneSum;
    }
};