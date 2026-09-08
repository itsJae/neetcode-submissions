class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> diffs(n);

        for (int i = 0; i < n; ++i) 
            diffs[i] = gas[i] - cost[i];

        int total = accumulate(diffs.begin(), diffs.end(), 0);

        if (total < 0) return -1;
        vector<int> prefixSum(n);
        
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += diffs[i];
            prefixSum[i] = sum;
        }

        int ans = 0;
        int minVal = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (minVal > prefixSum[i]) {
                minVal = prefixSum[i];
                ans = i;
            }
        }

        // int i = startIdx;
        // int sum = diffs[startIdx];
        // ++i;

        // if (i == n) 
        //     i = 0;

        // while (true) {
        //     if (i == startIdx)
        //         return startIdx;
            
        //     sum += diffs[i];
        //     ++i;

        //     if (sum < 0) 
        //         return -1;

        //     if (i == n) 
        //         i = 0;
        // }

        if (ans + 1 == n) return 0;
        return ans + 1;
    }
};
