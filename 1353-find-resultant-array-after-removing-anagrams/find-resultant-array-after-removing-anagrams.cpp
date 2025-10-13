class Solution {
public:
    bool isanagram(string s, string t){
        if(s.size()!=t.size()) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        for(int i=0; i < words.size(); i++){
            string a=words[i], b=ans.back();
            if(!isanagram(a,b)) ans.push_back(words[i]);
        }
        return ans;
    }
};