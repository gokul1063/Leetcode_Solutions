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
    int answer = 0;
    int helper(TreeNode *root, int depth){
        if (!root)
            return depth;
        return max( helper(root->left, depth + 1),
                    helper(root->right, depth + 1));
        
    }
    void helper2(TreeNode *root){
        if (!root)
            return;
        answer = max(answer, helper(root->left, 0) + 
                             helper(root->right,0));
        helper2(root->left);
        helper2(root->right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        helper2(root);
        return answer;
    }
};