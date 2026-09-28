class Solution {
public:
    int maxDepth(string s) {
        int mx = 0;
        int current_depth = 0;
        
        for(char x : s) {
            if(x == '(') {
                current_depth++;
                mx = max(mx, current_depth); 
            } 
            else if(x == ')') {
                if (current_depth > 0) {
                    current_depth--;
                }
            }
        }
        return mx;
    }
};
