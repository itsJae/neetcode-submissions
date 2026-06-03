class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = 0;
        int left = 0;
        int right = heights.size() - 1;

        while (left < right) {
            int curr_volume = (right - left) * min(heights[left], heights[right]);

            if (curr_volume > max) 
                max = curr_volume;

            if (heights[left] < heights[right])
                ++left;
            else
                --right;
        }

        return max;        
    }
};
