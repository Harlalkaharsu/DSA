class Solution {
public:
    void backtrack(vector<int>& candidates, vector<vector<int>>& res, vector<int>& combi,
                   int target, int sum, int index, int n) {
        if (sum == target) {
            res.push_back(combi);
            return;
        }
        if (sum > target) return;

        for (int i = index; i < n; i++) {
            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            combi.push_back(candidates[i]);
            backtrack(candidates, res, combi, target, sum + candidates[i], i + 1, n);
            combi.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combi;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, res, combi, target, 0, 0, n);
        return res;
    }
};