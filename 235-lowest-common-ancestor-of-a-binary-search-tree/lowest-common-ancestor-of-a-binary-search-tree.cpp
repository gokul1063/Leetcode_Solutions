/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* helper(TreeNode* root, int lower, int upper) {
        if (root->val > lower && root->val > upper)
            return helper(root->left, lower, upper);
        if (root->val < lower && root->val < upper) 
            return helper(root->right, lower, upper);
        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int lower = p->val < q->val ? p->val : q->val;
        int upper = p->val > q->val ? p->val : q->val;

        printf("%d p and %d q", lower, upper);
        return helper(root, lower, upper);
    }
};