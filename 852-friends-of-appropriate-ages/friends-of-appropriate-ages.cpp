class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n =ages.size();
        sort(ages.begin(), ages.end());
        int ans=0, left=0, right=0;
        for(int i =0; i<n; i++){
            int age= ages[i];
            if(age<15) continue;
            while(left< n && ages[left] <= 0.5 *age+7)left++;
            while(right+1<n && ages[right+1] <= age) right++;
            ans += right-left;
        }
        return ans;
    }
};