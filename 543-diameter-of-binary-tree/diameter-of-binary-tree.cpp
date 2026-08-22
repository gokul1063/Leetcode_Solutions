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

private:
    int helper2 (TreeNode *root){
        if (!root)
            return 0;

        int left_height = helper2(root->left);
        int right_height = helper2(root->right);

        answer = max(answer, left_height + right_height);

        return 1 + max(left_height , right_height);

        
    }
public:
    int answer = 0;
    
    int diameterOfBinaryTree(TreeNode* root) {
        helper2(root);
        return answer;
    }
};