class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        create(nums, 0, ans, subset);
        return ans;
    }
    void create(vector<int>& nums, int index, vector<vector<int>>&ans, vector<int>&subset){
        if(index == nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        create(nums, index+1, ans, subset);

        subset.pop_back();
        create(nums, index+1, ans, subset);
    }
};