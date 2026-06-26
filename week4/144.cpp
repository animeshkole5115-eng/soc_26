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
// class Solution {
// public:
//     vector<int> out;
//     void pre(TreeNode* root){
//         if(root == NULL){
//             return;
//         }
//         out.push_back(root->val);
//         pre(root->left);
//         pre(root->right);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         pre(root);
//       return out;
//     }
// };

class Solution {
public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        vector<int> out;
        if(root == NULL)
        return {};
        while(!s.empty()){
            TreeNode* curr = s.top();
            out.push_back(curr->val);
            s.pop();
            if(curr->right != NULL){
                s.push(curr->right);
            }
            if(curr->left != NULL){
                s.push(curr->left);
            }
        }
        return out;
    }
};