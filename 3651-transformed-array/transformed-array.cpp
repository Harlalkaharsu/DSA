class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            // Formula to handle circular movement for both + and - values
            int targetIndex = (i + nums[i] % n + n) % n;
            result[i] = nums[targetIndex];
        }
        
        return result;
    }
};
