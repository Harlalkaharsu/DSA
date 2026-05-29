class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i =0; i< n; i++){
            int sum =0, temp = nums[i];
            while(temp != 0){
                sum += (temp%10);
                temp /= 10;
            }
            ans[i]= sum;
        }
        int min = *min_element(ans.begin(), ans.end());
        return min;
    }
};