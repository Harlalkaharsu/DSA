class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>index;
        combo(ans,target,index,0,0,candidates);
        return ans;
    }
private:
    void combo(vector<vector<int>>&ans, int target,vector<int>&index, int idx, int total, vector<int>&candidates){
        if(total == target){
            ans.push_back(index);
            return;
        }
        if (total > target || idx >= candidates.size()) {
            return;
        }
        index.push_back(candidates[idx]);
        combo(ans,target,index,idx,total + candidates[idx],candidates);
        index.pop_back();
        combo(ans,target,index,idx+1,total,candidates);
    }
};