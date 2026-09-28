class Solution {
public:

    int exsist(int r,int n,int m,vector<int>& houses, vector<int>& heaters){
        int i=0,j=0;
        while(i<n && j<m){
            if(abs(houses[i]-heaters[j])<=r) i++;
            else
            j++;
            if(j==m) return false;
        }
        return i==n;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n= houses.size(), m = heaters.size();

        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int ans=-1;
        int left =0, right =1e9, mid;
        while(left <=right){
            mid = (left+right)/2;
            if(exsist(mid,n, m,houses, heaters)) {
                ans =mid;
                right = mid-1;
            }else left = mid +1;
        }
        return ans;
    }
};