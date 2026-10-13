class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]}); //{destination. price}
        }

        vector<int> dist(n , INT_MAX);
        queue<pair<int,pair<int,int>>> q;  // {stops, {node, cost}}
        
        dist[src] = 0;
        q.push({0, {src, 0}});  // Start: 0 stops, at src, cost 0

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;

            // Explore all neighbors
            for(auto iter: adj[node]) {
                int adjNode = iter.first;
                int currentprice = iter.second; 

                if(cost + currentprice < dist[adjNode] && stops <= k) {
                    dist[adjNode] = cost + currentprice;
                    q.push({stops + 1, {adjNode, cost + currentprice}});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};