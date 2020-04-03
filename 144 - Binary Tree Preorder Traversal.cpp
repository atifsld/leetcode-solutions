/*
 * https://leetcode.com/problems/binary-tree-preorder-traversal/submissions/
 */

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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> solution;
        if(root == NULL)
            return solution;
        st.push(root);
        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            solution.push_back(curr->val);
            if(curr->right != NULL)
                st.push(curr->right);
            if(curr->left != NULL)
                st.push(curr->left);
        }
        return solution;
    }
};