class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n=deck.size();
        queue<int> q;
        for(int i=0; i< deck.size(); i++){
            q.push(i);
        }
        vector<int> ans(n,0);
        vector<int> temp;
        while(!q.empty()){
            temp.push_back(q.front());
            q.pop();
            q.push(q.front());
            q.pop();
        }
        for(int i=0; i<deck.size();i++){
            ans[temp[i]] = deck[i];
        }
        return ans;
    }
};