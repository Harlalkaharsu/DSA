class Solution {
public:
    void backtrack(vector<int> &nums, vector<vector<int>> &res, vector<int> &combi, int n, int c) {
        res.push_back(combi);

        for (int i = c; i < n; i++) {
            // Skip duplicates
            if (i > c && nums[i] == nums[i - 1]) continue;

            combi.push_back(nums[i]);
            backtrack(nums, res, combi, n, i + 1);
            combi.pop_back(); // backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> combi;
        sort(nums.begin(), nums.end());
        backtrack(nums, res, combi, n, 0);
        return res;
    }
};