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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> data;

        if (!root)
            return res;
        //res.push_back(root->val);
        data.push(root);

        while (!data.empty()){
            int n = data.size();
            for (int ele = 0 ; ele < n ; ele++){
                TreeNode *temp = data.front();
                data.pop();

                if (ele == 0) {
                    res.push_back(temp->val);
                }
                if (!temp)
                    continue;
                if (temp->right)
                    data.push(temp->right);
                if (temp->left)
                    data.push(temp->left);
            }

        }

        return res;
        
    }
};