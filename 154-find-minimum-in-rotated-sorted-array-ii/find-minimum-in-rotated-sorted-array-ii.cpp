class Solution {
public:
    int findMin(vector<int>& nums) {
        int mn = nums[0];

        for(int x : nums) {
            mn = min(mn, x);
        }

        return mn;
    }
};