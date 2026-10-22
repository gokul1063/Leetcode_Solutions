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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> st;

        st.push(root);

        vector<vector<int>> res; 

        int n = st.size();

        while (st.size() > 0) {
            vector<int> curr; 
            for (int i = 0 ; i < n ; i++) {
                TreeNode* temp = st.front();

                if (temp) {
                    curr.push_back(temp->val);
                    st.push(temp->left);
                    st.push(temp->right);
                }
                st.pop();
            }
            if (curr.size() > 0) 
                res.push_back(curr);
            n = st.size();
        }

        return res;

        
    }
};