class Solution {
public:
    int getCnt(vector<int>& weights,int mid){
        int cnt=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            if (weights[i]>mid)return INT_MAX;
            if (sum+weights[i]>mid) {
                cnt++;
                sum=0;
            }
            sum +=weights[i];
        }
        return cnt;//return number of days for that max weight
    }


    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=weights[i];
        }
        int s=1,e=sum;
        int ans=INT_MAX;
        while(s<=e){
            int mid=s+(e-s)/2;
            int cnt=getCnt(weights,mid);
            if(cnt<=days){
                ans=min(ans,mid);
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};