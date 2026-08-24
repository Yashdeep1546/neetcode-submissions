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
    int maxi=INT_MIN;

    int rec(TreeNode* node){
        if(node==nullptr) return 0;

        int l=rec(node->left);
        int r=rec(node->right);
        int v=node->val;
        int curr=max(v,max(v+max(l,r),max(v+l+r,INT_MIN)));

        maxi=max(curr,maxi);
        return max(v,v+max(l,r));
    }
    int maxPathSum(TreeNode* root) {
        

        rec(root);
        return maxi;
    }
};
