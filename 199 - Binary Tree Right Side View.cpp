/*
** https://leetcode.com/problems/binary-tree-right-side-view/submissions/
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
    int height(TreeNode* root) {
        if(root == NULL)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }
   
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> sol;
        if(root == NULL)
            return sol;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            while(n-- > 0) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left != NULL)
                    q.push(curr->left);
                if(curr->right != NULL)
                    q.push(curr->right);
                if(n==0)
                    sol.push_back(curr->val);
            }
        }
        return sol;
    }
};