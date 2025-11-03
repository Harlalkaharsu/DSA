class Solution {
public:
    void solve(int n, int sq, int cnt, int& ans) {
        if(n == 0) {
            ans = min(ans, cnt);
            return;
        }
        if((cnt >= ans) || (sq <= 0) || (n < 0)) return;

        // pick
        int square = sq*sq;
        solve(n-square, sq, cnt+1, ans);

        // not pick
        solve(n, sq-1, cnt, ans);
        
    }
    int numSquares(int n) {
        int flr = (sqrt(n));
        int ans = n;
        solve(n, flr, 0, ans);
        return ans;
    }
};