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
    TreeNode * ans;
    int maxDepth(TreeNode* root) {
        if(!root)
        return 0; 
        return max(maxDepth(root->left),maxDepth(root->right))+1;    
    }
    bool dfs(TreeNode *root,int lvl,int h)
    {
        if(!root)
        return 0;
        if(lvl==h)
        {
            ans = root;
            return 1;
        }
        bool l = dfs(root->left,lvl+1,h);
        bool r = dfs(root->right,lvl+1,h);
        if(l && r)
        ans = root;
        if(l || r)
        return 1;
        return 0;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int h = maxDepth(root);
        dfs(root,1,h);
        return ans;
    }
};