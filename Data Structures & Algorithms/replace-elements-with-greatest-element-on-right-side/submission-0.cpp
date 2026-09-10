class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int currMax = -1;

        for (int i = n - 1; i >= 0; --i) {
            int tmp = arr[i];
            arr[i] = currMax;

            currMax = max(currMax, tmp); 
        }

        return arr;
    }
};