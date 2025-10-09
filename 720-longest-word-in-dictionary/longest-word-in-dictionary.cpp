class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_map<string, bool> canBuild;
        string res = "";

        for (auto &w : words) {
            if (w.size() == 1 || canBuild[w.substr(0, w.size() - 1)]) {
                canBuild[w] = true;
                if (w.size() > res.size()) {
                    res = w;
                }
            } else {
                canBuild[w] = false;
            }
        }

        return res;
    }
};
