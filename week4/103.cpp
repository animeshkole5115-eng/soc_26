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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> ans;
        int i = 0;
        vector<vector<int>> out;

        if(root == NULL)
        return {};

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == NULL){
                if(i % 2 != 0)
                reverse(ans.begin(),ans.end());
                out.push_back(ans);
                ans.clear();
                if(q.empty()){
                    break;
                }
                else{
                    q.push(NULL);
                    i++;
                    continue;
                }
            }
            ans.push_back(curr->val);
            
                if(curr->left != NULL)
                q.push(curr->left);
                
                if(curr->right != NULL)
                q.push(curr->right);


            
        }
        return out;
    }
};