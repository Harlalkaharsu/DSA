class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(),intervals.end(),[](auto &a, auto &b){
            return a[1]<b[1];
        });
        
        int size = intervals.size();
        int lastEnd = intervals[0][1];
        for(int i= 1;i<size;i++){
            if(intervals[i][0] < lastEnd){
                ans++;
            }
            else {
                lastEnd = intervals[i][1];
            }
        }
        return ans;
    }
};