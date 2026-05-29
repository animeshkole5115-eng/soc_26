class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy=0;
        int sell=0; 
        int maxprofit=0;
        for(int i=0;i<n;i++){
            if(prices[i]<prices[buy]){
                buy=i;
            }
            else{
               sell=i;
            }

            if(sell>=buy){
                maxprofit=max(maxprofit,prices[sell]-prices[buy]);
            }
        }
        return maxprofit;
    }
};