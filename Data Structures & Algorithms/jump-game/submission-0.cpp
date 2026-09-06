class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int targetIdx = n - 1;

        for (int i = n - 2; i >= 0; --i) {
            // cout << "target: " << targetIdx << endl;
            if (targetIdx - i <= nums[i]) {
                targetIdx = i;
            }
        }

        return targetIdx == 0 ? true : false;
    }
};
