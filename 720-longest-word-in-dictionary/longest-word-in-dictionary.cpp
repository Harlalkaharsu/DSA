class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> seen;
        for(auto const& word : words){
            seen.insert(word);
        }

        string ans = "";
        for(auto x : words){
            if(x.size() > ans.size() || (x.size() == ans.size() && x < ans)){
                bool found = true;
                for(int i = 1; i < x.size(); i++){
                    if(seen.count(x.substr(0, i)) == 0){
                        found = false;
                    }
                }
                if(found){                
                    ans = x;
                }
            }
        }

        return ans;
    }
};