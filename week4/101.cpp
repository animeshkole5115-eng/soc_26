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
    
    bool similar(TreeNode* head1 , TreeNode* head2){
        if(head1 == NULL || head2 == NULL){
            if(head1 == NULL && head2 == NULL)
            return true;
            else 
            return false;
        }
        if(head1->val != head2->val )
        return false;
        return(similar(head1->left , head2->right) && similar(head1->right , head2->left));
    }

    bool isSymmetric(TreeNode* root) {
        return(similar(root->left , root->right));
    }
};