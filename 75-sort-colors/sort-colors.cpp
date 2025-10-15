class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> mp;
        for(int x: nums){
            mp[x]++;
        }
        int index = 0;
        for (auto it : mp) {        
            int value = it.first;
            int count = it.second;
            while (count--) {
                nums[index++] = value;
            }
        }
    }
};