class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        // (a)x + (b)y = (c)gcd(x, y)
        // or BFS
        // add x ; add y ; subtract x ; subtract y
        int mx = x+y;
        vector<bool>vis(1000, false);
        queue<int>Q;
        Q.push(0);
        vis[0] = true;

        while(!Q.empty()){
            int e = Q.front(); 
            Q.pop();
            if(e == target) return true;

            if(e+x <= mx && !vis[e+x]){
                Q.push(e+x);
                vis[e+x] = true;
            }
            if(e+y <= mx && !vis[e+y]){
                Q.push(e+y);
                vis[e+y] = true;
            }
            if(e-x >= 0 && !vis[e-x]){
                Q.push(e-x);
                vis[e-x] = true;
            }
            if(e-y >= 0 && !vis[e-y]){
                Q.push(e-y);
                vis[e-y] = true;
            }
        }
        return false;


    }
};