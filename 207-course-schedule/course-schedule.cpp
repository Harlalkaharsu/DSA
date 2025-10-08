class Solution {
public:

    bool canFinish(int V, vector<vector<int>>& arr) {
        if(arr.size() == 0)   return true;

        list<int> *l;
        l = new list<int>[V];

        for(int i=0; i<arr.size(); i++){
            l[arr[i][1]].push_back(arr[i][0]);
        }

        vector<int> indegree(V, 0);

        for(int i=0; i<V; i++){
            for(int j : l[i]){
                indegree[j]++;
            }
        }

        queue<int> q;

        for(int i=0; i<indegree.size(); i++){
            if(indegree[i] == 0)    q.push(i);
        }

        int cnt = 0;
        while(q.size() > 0){
            int node = q.front();
            q.pop();
            cnt++;

            for(int i : l[node]){
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }

        return cnt == V;
    }
};