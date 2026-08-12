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
    void rec(TreeNode* curr,int level, vector<vector<int>> &res ){
        if(curr==nullptr) return;
        if(res.size()>level){
            res[level].push_back(curr->val);
        }
        else {
            res.push_back({curr->val});
        }
        rec(curr->left,level+1,res);
        rec(curr->right,level+1,res);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>> res;
       
       rec(root,0,res);
      
       return res;
    }
};
