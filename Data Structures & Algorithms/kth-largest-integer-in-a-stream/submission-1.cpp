class KthLargest {
public:
    int k;
    vector<int> nums;
    priority_queue<int> pq;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;

        for (int i = 0; i < nums.size(); ++i) {
            pq.push(nums[i]);
        }
    }
    
    int add(int val) {
        vector<int> vec;
        int cnt = 0;
        pq.push(val);

        while (cnt < k - 1 && !pq.empty()) {
            int dq = pq.top();
            pq.pop();
            vec.push_back(dq);
            ++cnt;
        }

        int ans = pq.top();
        for (int i = 0; i < vec.size(); ++i) 
            pq.push(vec[i]);

        return ans;
    }
};
