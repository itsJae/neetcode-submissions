class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_buy = prices[0];

        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] - min_buy > max_profit) 
                max_profit = prices[i] - min_buy;
            
            if (min_buy > prices[i]) 
                min_buy = prices[i];
        }

        return max_profit;
    }
};
