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
    TreeNode* recoverFromPreorder(string pre) {
        int n = pre.size();
        unordered_map<int,TreeNode*> m;
        int i = 0;
        TreeNode * root ;
        while(i<n)
        {
            int depth = 0;
            int no = 0;
            while(i<n && pre[i]=='-')
            {
                depth++;
                i++;
            }
            while(i<n && pre[i]!='-')
            {
                no = no*10+(pre[i]-'0');
                i++;
            }
            cout<<depth<<" "<<no<<endl;
            TreeNode * node = new TreeNode(no);
            m[depth] = node;
            if(depth==0)
            root = node;
            else
            {
                TreeNode * par = m[depth-1];
                if(par->left==nullptr) par->left = node;
                else if(par->right==nullptr) par->right = node;
            }
        }
        return root;
    }
};