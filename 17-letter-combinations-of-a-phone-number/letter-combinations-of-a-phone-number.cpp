class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
        unordered_map<char, string> digit = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        backtrack(digits, 0, "", ans, digit);
        return ans;
    }
    void backtrack(const string& digits, int idx, string comb, vector<string>& ans, const unordered_map<char, string>& digit) {
        if (idx == digits.length()) {
            ans.push_back(comb);
            return;
        }
        
        string letters = digit.at(digits[idx]);
        for (char letter : letters) {
            backtrack(digits, idx + 1, comb + letter, ans, digit);
        }
    }
};