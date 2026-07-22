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
 
    This is a brute forcee
*/

class Solution {
private:
    vector<int> data;

public:
    void helper(TreeNode *root){
        if (!root)
            return;
        
        helper(root->left);
        data.push_back(root->val);
        helper(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        helper(root);
        if (k <= data.size())
            return data[k-1];
        return -1;
    }
};