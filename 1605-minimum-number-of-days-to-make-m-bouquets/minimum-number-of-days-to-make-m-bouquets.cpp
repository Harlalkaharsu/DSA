class Solution {
public:

    int possible(vector<int>& arr, int m, int k, int day){
        int n = arr.size();
        int cnt =0;
        int noofbuq =0;
        for(int i=0; i<n; i++){
            if(arr[i] <= day) cnt++;
            else{
                noofbuq += cnt/k;
                cnt =0;
            }
        }
        noofbuq += cnt/k;
        return noofbuq >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        long long val = m * 1LL * k * 1LL;
        if(n < val) return -1;
        while(low<= high){
            int mid = low + (high - low)/2;
            if(possible(bloomDay, m, k, mid)) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};