class Solution {
private:
    int possible(vector<int>& arr, int m, int k, int day){
        int n = arr.size();
        int cnt = 0;
        int noOfbuf = 0;
        for(int i = 0; i<n;i++){
            if(arr[i] <= day) cnt++;
            else{
                noOfbuf += (cnt/k);
                cnt=0;
            }
        }
        noOfbuf += (cnt/k);
        return noOfbuf >= m;
    }
public:
    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size();
        int low=*min_element(arr.begin(),arr.end()), high =*max_element(arr.begin(),arr.end());
        long long val = m * 1ll * k * 1ll;
        if( n < val) return -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(possible(arr, m, k, mid)){
                high = mid-1;
            }
            else low =mid+1;
        }
        return low;  
    }
};