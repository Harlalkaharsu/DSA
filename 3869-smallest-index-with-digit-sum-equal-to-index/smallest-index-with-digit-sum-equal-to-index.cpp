class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n =nums.size();
        // int ans = INT_MAX;
        for(int i=0; i<n; i++){
            int temp = nums[i];
            int sum =0;
            while(temp > 0){
                sum += temp%10;
                temp = temp/10;
            }
            if(sum == i){
                // ans= min(ans, sum);
                return i;
            }
        }
        // if(ans == INT_MAX) return -1;
        return -1;
    }
};