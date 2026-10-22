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

        brute force method,     
 */
class Solution {
public:
    bool helper(TreeNode* r1, TreeNode* r2) {
        if (!r1 && !r2){
            return true;
        }

        if (r1 && r2 && r1->val == r2->val){
            return helper(r1->left, r2->left) && helper(r1->right, r2->right);
        }

        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root || !subRoot){
            return false;
        }

        if (root->val == subRoot->val) {
            if (helper(root, subRoot))
                return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
    }
};