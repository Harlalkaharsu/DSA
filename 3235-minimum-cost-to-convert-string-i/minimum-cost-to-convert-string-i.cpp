class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int INF = 1e9;
        vector<vector<long long>> dist(26, vector<long long>(26, INF));
        
        for (int i = 0; i < 26; ++i) dist[i][i] = 0;
        for (int i = 0; i < original.size(); ++i)
            dist[original[i] - 'a'][changed[i] - 'a'] = min(dist[original[i] - 'a'][changed[i] - 'a'], (long long)cost[i]);
        
        // Floyd–Warshall
        for (int k = 0; k < 26; ++k)
            for (int i = 0; i < 26; ++i)
                for (int j = 0; j < 26; ++j)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        
        long long total = 0;
        for (int i = 0; i < source.size(); ++i) {
            if (source[i] == target[i]) continue;
            long long c = dist[source[i] - 'a'][target[i] - 'a'];
            if (c >= INF) return -1;
            total += c;
        }
        return total;
    }
};