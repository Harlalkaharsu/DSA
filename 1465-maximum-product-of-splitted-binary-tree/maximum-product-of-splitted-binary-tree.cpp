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
    long maxx = INT_MIN;
    int MOD = 1000000007;
    int maxProduct(TreeNode* root) {
        long sum = totalsum(root);
        dfs(root, sum);
        return (int )(maxx%MOD);
    }
    long dfs(TreeNode* root, long sum){
        if(!root) return 0;
        long left= dfs(root->left, sum);
        long right =dfs(root->right, sum);
        long currsum = left + right + root->val;
        maxx = max(maxx,(sum-currsum)*currsum);
        return currsum;
    }
    long totalsum(TreeNode* root){
        if(!root) return 0;
        long left = totalsum(root->left);
        long right = totalsum(root->right);
        return left+right+root->val;
    }
};