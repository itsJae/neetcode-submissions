class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int l = 0;
        int r = k;

        while (r < arr.size()) {
            if (abs(arr[r] - x) > abs(arr[l] - x) || 
                (abs(arr[r] - x) == abs(arr[l] - x) && arr[r] > arr[l])
            ) {
                break;
            }

            ++l;
            ++r;
        }

        for (int i = l; i < r && i < arr.size(); ++i) {
            ans.push_back(arr[i]);
        }
        
        return ans;
    }
};