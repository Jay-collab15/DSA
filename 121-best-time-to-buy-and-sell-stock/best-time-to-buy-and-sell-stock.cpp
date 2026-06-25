class Solution {
public:
    //Jay
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0],profit=0;
        for(int i=1;i<n;i++)
        {
            int sell=prices[i]-mini;
            profit=max(profit,sell);
            mini=min(mini,prices[i]);
        }   
        return profit;
    }
};