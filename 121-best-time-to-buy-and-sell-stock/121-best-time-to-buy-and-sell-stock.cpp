class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int maxProfit = 0;
        int minValue = prices[0];
        for(int i = 0; i < prices.size(); i++)
        {
            minValue = min(prices[i],minValue);
            maxProfit = max(maxProfit,prices[i] - minValue);
        }
        return maxProfit;
    }
};