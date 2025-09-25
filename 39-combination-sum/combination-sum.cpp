class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> index;
        create(candidates, ans, index, target, 0, 0 );
        return ans;
    }
    void create(vector<int>& candidates,vector<vector<int>>& ans,vector<int>& index,int target, int total , int idx ){
        if(total == target){
            ans.push_back(index);
            return;
        }
        if(total > target || idx >= candidates.size())return;

        index.push_back(candidates[idx]);
        create(candidates, ans, index, target, total+candidates[idx], idx);
        index.pop_back();
        create(candidates, ans, index, target, total, idx+1);
    }
};