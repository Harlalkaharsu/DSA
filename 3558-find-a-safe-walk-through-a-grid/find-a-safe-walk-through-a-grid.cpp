class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        int delrow[] = {0, -1, 0, 1};
        int delcol[] = {-1, 0, 1, 0};
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> vis(m, vector<int>(n, -1));
        if(grid[0][0] == 0) {
            q.push({health, {0, 0}});
            vis[0][0] = health; 
        }
        else if(health > 1) {
            q.push({health-1, {0, 0}});
            vis[0][0] = health - 1; 
        }
        else {
            return false; 
        }
        while(!q.empty()) {
            int r = q.front().second.first;
            int c = q.front().second.second;
            int h = q.front().first;
            cout << r << " " << c << " " << h << endl;
            q.pop();
            if(r == m-1 && c == n-1 && h>=1) return true;
            if( h < vis[r][c]) continue;
            for(int i=0; i<4; i++) {
                int nr = r+delrow[i];
                int nc = c+delcol[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if(nr == m-1 && nc == n-1 && h > 1) return true;
                    // h = current_health - grid[nr][nc];
                    if(grid[nr][nc] == 0) {
                        if(h > vis[nr][nc]){
                            q.push({h, {nr, nc}});
                            vis[nr][nc] = h;
                        }
                    }
                    else if(h>1){
                        if(h - 1 > vis[nr][nc]) { 
                            vis[nr][nc] = h - 1;
                            q.push({h-1, {nr, nc}});
                        }
                    }
                }
            }
        }
        return false;
    }
};
 