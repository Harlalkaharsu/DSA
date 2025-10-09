class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        unordered_set<string>res;
        res.insert("");
        string ans="";
        for(auto &w:words){
            if(res.count(w.substr(0,w.size()-1))){
                res.insert(w);
                if(w.size()>ans.size()){
                    ans=w;
                }
            }
        }
        return ans;
    }
};