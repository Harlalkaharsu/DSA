class Solution {
public:
    bool issubsequence(string s, string t){
        int l=0, r=0;
        int n=s.size(), m=t.size();
        while(l<n && r<m){
            if(s[l] == t[r]) r++;l++;
        }
        return r==m;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count =0;
        unordered_map<string,int> mp;
        for(string str:words){
            if(mp[str] == 2) {
                count++;
                continue;
            }
            else if(mp[str] == 1) continue;
            else mp[str]=1;
            if(issubsequence(s,str)) {
                mp[str] = 2;
                count++;}
        }
        return count;
    }
};