class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int t;
        queue<pair<int, int>> q;
        map<pair<int, int>, bool> visited;
        // BFS
        q.push({0, 0});
        while(q.size()) {
            auto [jug1, jug2] = q.front();
            q.pop();
            visited[{jug1, jug2}] = true;
            if(jug1 == targetCapacity || jug2 == targetCapacity || jug1 + jug2 == targetCapacity)
                return true;
            // Fill any of the jugs
            if(!visited[{jug1Capacity, jug2}])
                q.push({jug1Capacity, jug2});
            if(!visited[{jug1, jug2Capacity}])
                q.push({jug1, jug2Capacity});
            // Empty any of the jugs
            if(!visited[{0, jug2}])
                q.push({0, jug2});
            if(!visited[{jug1, 0}])
                q.push({jug1, 0});
            // Pour water into other
            t = min(jug1Capacity, jug1 + min(jug2Capacity, jug2));
            if(!visited[{t, jug1 + jug2 - t}])
                q.push({t, jug1 + jug2 - t});
            t = min(jug2Capacity, jug2 + min(jug1Capacity, jug1));
            if(!visited[{jug1 + jug2 - t, t}])
                q.push({jug1 + jug2 - t, t});
        }
        return false;
    }
};

/* Operations 
    * jug1 = jug1Capacity
    * jug2 = jug2Capacity
    * jug1 = 0
    * jug2 = 0
    * jug1 = min(jug1Capacity, jug1 + min(jug2Capacity, jug2))
    * jug2 = min(jug2Capacity, jug2 + min(jug1Capacity, jug1))
*/