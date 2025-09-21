/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void bfs(TreeNode* root,unordered_map<int,multiset<pair<int,int>>>&mp,int &mini,int &maxi){
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});

        while(!q.empty()){
            int sz=q.size();

            for(int i=0;i<sz;i++){
                auto itr=q.front();
                q.pop();
                TreeNode* node=itr.first;
                int row=itr.second.first;
                int col=itr.second.second;
                mp[col].insert({row,node->val});
                maxi=max(maxi,col);
                mini=min(mini,col);

                if(node->left)q.push({node->left,{row+1,col-1}});
                if(node->right)q.push({node->right,{row+1,col+1}});
            }
        }
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int,multiset<pair<int,int>>>mp;
        int mini=INT_MAX,maxi=INT_MIN;
        vector<vector<int>>ans;

        bfs(root,mp,mini,maxi);
        for(int i=mini;i<=maxi;i++){
            if(mp.find(i)==mp.end())continue;
            vector<int>tmp;
            for(auto x:mp[i])tmp.push_back(x.second);
            ans.push_back(tmp);
        }
        return ans;
    }
};