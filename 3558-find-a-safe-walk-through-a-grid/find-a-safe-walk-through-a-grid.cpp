class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m= grid[0].size();
        int current_health = health - grid[0][0];
        if(current_health < 1) return false;

        vector<vector<bool>> vis(n , vector<bool>(n, false));
        priority_queue<tuple<int, int, int>> pq;

        pq.push({current_health, 0, 0});
        vector<vector<int>> mem(n, vector<int>(m , 0));

        mem[0][0] = current_health;
        vis[0][0] = true;

        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!pq.empty()){
            auto[h, x, y] = pq.top();
            pq.pop();

            for(int i=0; i< 4; i++){
                int u = x + dir[i][0];
                int v = y + dir[i][1];

                if(u < n && u >= 0 && v < m && v>=0){
                    current_health = h - grid[u][v];

                    if(u == n-1 && v == m-1 && current_health >=1) return true;
                    if(!vis[u][v] || (current_health>mem[u][v])){
                        mem[u][v] = current_health;
                        vis[u][v]= true;

                        pq.push({current_health, u, v});
                    }   
                }
            }
        }
        return false;
        
    }
};