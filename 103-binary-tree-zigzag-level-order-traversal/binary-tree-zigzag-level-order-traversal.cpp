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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        deque<TreeNode*> q;
        q.push_back(root);
        bool reverse = false;
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i = 0; i< size; i++){
                if(!reverse){
                    TreeNode* root = q.front(); q.pop_front();
                    level.push_back(root->val);
                    if(root->left) q.push_back(root->left);
                    if(root->right) q.push_back(root->right);
                }else{
                    TreeNode* root = q.back(); q.pop_back();
                    if(root->right) q.push_front(root->right);
                    if(root->left) q.push_front(root->left);
                    level.push_back(root->val);
                }
            }
            ans.push_back(level);
            reverse = !reverse;
        }
        return ans;
    }
};