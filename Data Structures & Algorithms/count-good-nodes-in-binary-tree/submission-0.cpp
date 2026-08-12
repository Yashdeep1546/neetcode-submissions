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

    int rec(TreeNode* curr,int maxi){
        if(curr==nullptr) return 0;
        maxi=max(maxi,curr->val);
        int flag=0;
        if(maxi==curr->val) flag=1;
        return flag+rec(curr->left,maxi)+rec(curr->right,maxi);

    }
    int goodNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        
        return rec(root,root->val);
    }
};
