class Solution {
public:
    void problem(int ind, int target, vector<int>& nums,
                 vector<int>& temp, vector<vector<int>>& ans, int n) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        for(int i = ind; i < n; i++) {
            // Skip duplicates at the same recursion level
            if(i > ind && nums[i] == nums[i - 1]) continue;
            if(nums[i] > target) break;
            temp.push_back(nums[i]);
            problem(i + 1, target - nums[i], nums, temp, ans, n);
            // Backtrack
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        problem(0, target, candidates, temp, ans, n);
        return ans;
    }
};