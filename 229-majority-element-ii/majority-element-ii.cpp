class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ceil_val = ceil(n/3);
        vector<int> ans;
        unordered_map<int,int>mpp;
        for(auto x: nums){
            mpp[x]++;
        }
        for(auto& pair : mpp){
            if(pair.second > ceil_val){
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};