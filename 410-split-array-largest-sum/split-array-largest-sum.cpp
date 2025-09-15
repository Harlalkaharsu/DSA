class Solution {
private:
    int cnt(vector<int>& nums, int k){
        int n = nums.size();
        int parti = 1;
        long long sum = 0;
        for(int i = 0; i<n ; i++){
            if(sum + nums[i] <=  k){
                sum += nums[i];
            }
            else {
                parti++;
                sum = nums[i];
            }
        }
        return parti;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(), 0);
        while(low<=high){
            int mid = low +(high-low) / 2;
            int parti = cnt(nums, mid);
            if(parti <= k){
                high = mid -1;
            }
            else low = mid+1;
        }
        return low;
    }
};