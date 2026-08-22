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
    int helper (TreeNode* root) {
        if (!root)
            return 0;
        if (!res)
            return 0;
        int left = helper(root->left);
        int right = helper(root->right);

        res = res &&  (abs(left - right) <= 1); 

        return 1 + max(left, right); 
    }

    bool res = true;

    bool isBalanced(TreeNode* root) {
        helper(root);
        return res;
        
    }
};