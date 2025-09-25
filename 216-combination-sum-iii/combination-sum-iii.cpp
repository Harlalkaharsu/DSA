class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> index;
        backtrack(ans, index, k, n, 1);
        return ans; 
    }
    void backtrack(vector<vector<int>>& ans, vector<int>&index, int k, int target, int idx){
        if(target == 0 && k == 0){
            ans.push_back(index);
            return;
        }
        for(int i = idx; i<=9; i++){
            if (i > target || k <= 0) break;
            index.push_back(i);
            backtrack(ans, index,k - 1, target - i, i + 1);
            index.pop_back();
        }
    }
};