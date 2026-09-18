class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<string> ans;
        
        // Track the first and last occurrence of each character
        vector<int> leftmost(26, n);
        vector<int> rightmost(26, -1);
        for (int i = 0; i < n; ++i) {
            leftmost[s[i] - 'a'] = min(leftmost[s[i] - 'a'], i);
            rightmost[s[i] - 'a'] = i;
        }

        int lastRight = -1;
        for (int i = 0; i < n; ++i) {
            // A valid substring must start at the very first occurrence of its character
            if (i == leftmost[s[i] - 'a']) {
                int r = rightmost[s[i] - 'a'];
                bool isValid = true;
                
                // Expand the right boundary to include all inner characters completely
                for (int j = i; j <= r; ++j) {
                    if (leftmost[s[j] - 'a'] < i) {
                        isValid = false; // An inner character started before 'i'
                        break;
                    }
                    r = max(r, rightmost[s[j] - 'a']);
                }
                
                if (isValid) {
                    // If it overlaps with the previous one, we overwrite it 
                    // because the new one is smaller/strictly embedded inside
                    if (i > lastRight) {
                        ans.push_back("");
                    }
                    ans.back() = s.substr(i, r - i + 1);
                    lastRight = r;
                }
            }
        }
        return ans;
    }
};
