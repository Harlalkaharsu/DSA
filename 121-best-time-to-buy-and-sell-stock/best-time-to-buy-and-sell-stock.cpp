class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
         if(n == 0 ){
            return 0;
        }
        int profit = 0;
        int buy = prices[0];
        for(int j = 1;j < n;j++){
            if(prices[j] > buy){
                if(profit < prices[j] - buy)
                    profit = prices[j] - buy;
            }else{
                buy = prices[j];
            }
        }  
        return profit;
    }
};