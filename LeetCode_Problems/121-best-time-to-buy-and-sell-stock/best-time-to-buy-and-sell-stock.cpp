class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int diff=0;
        int buy=0;
        int n=prices.size();
        int sell=prices[n-1];
        for(int i=n-2;i>=0;i--){
            buy=prices[i];
            if(sell>buy){
                diff=max(diff,sell-buy);
            }
            else{
                sell=buy;
            }
        }
        return diff;
    }
};