class Solution {
private:
    int sumer(vector<int>& nums, int mid){
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ceil((double)(nums[i]) / (double)(mid));
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int req) {
        int n = nums.size();
        int low = 1, high = *max_element(nums.begin(),nums.end());
        if (n > req) return -1;
        while(low<=high){
            int mid = low + (high - low)/2;
            
            if(sumer(nums, mid) <= req){
                high = mid-1;
            }
            else low = mid +1;
        }
        return low;
    }
};