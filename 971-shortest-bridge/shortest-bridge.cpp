class Solution {
public:
    vector<vector<int>> first,second;
    void dfs(int i,int j, int x, vector<vector<int>>& grid){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]!=1) return;
        grid[i][j]=x;
        if(x==2) first.push_back({i,j});
        else second.push_back({i,j});
        dfs(i+1,j,x,grid);
        dfs(i-1,j,x,grid);
        dfs(i,j+1,x,grid);
        dfs(i,j-1,x,grid);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int count=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(i,j,count,grid);
                    count++;
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<first.size();i++){
            for(int j=0;j<second.size();j++){
                ans=min(abs(first[i][0]-second[j][0])+abs(first[i][1]-second[j][1])-1,ans);
            }
        }
        return ans;
    }
};