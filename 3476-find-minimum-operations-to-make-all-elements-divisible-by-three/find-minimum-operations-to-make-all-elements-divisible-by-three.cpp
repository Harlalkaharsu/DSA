class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int count =0;
        for(int nums1 : nums){
            if(nums1 % 3 != 0) count++;
        }
        return count;
    }
};