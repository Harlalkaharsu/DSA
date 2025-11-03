class Solution {
public:
static bool cmp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
    int findLongestChain(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),cmp);
        int c=1;
        int prev=0;

        for(int i=1;i<p.size();i++){
         if(p[i][0]>p[prev][1]){
             c++;
             prev=i;
         }   
        }
        return c;
    }
};