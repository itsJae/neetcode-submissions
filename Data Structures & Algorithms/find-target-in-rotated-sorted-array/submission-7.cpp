class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = midpoint(left, right);

            if (nums[mid] == target) {
                return mid;
            }
            
            // When left half is sorted in ascending order.
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) 
                    right = mid - 1;
                else 
                    left = mid + 1;
            // When right half is sorted in ascending order.
            } else {
                if (nums[mid] < target && target <= nums[right]) 
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return -1;
    }
};
