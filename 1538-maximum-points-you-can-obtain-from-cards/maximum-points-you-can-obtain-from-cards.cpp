class Solution {
public:
    int maxScore(vector<int>& cardpoints, int k) {
        int n = cardpoints.size();
        int ans =0;

        for(int i =0; i< k; i++) ans += cardpoints[i];

        int curr = ans;
        for(int i = k-1 ; i>= 0; i--){
            curr -= cardpoints[i];
            curr += cardpoints [ n - k+i];

            ans = max(ans, curr);
        }
        return ans;
    }
};