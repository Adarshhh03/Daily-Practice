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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder){
     if(!inorder.empty()){
     int n=postorder.size();
     int val=postorder[n-1];
     postorder.pop_back();
     TreeNode* root=new TreeNode(val);

     auto it = find(inorder.begin(), inorder.end(), val);
     int idx = it - inorder.begin();

     vector<int> leftInorder(inorder.begin(), inorder.begin() + idx);
     vector<int> rightInorder(inorder.begin() + idx + 1, inorder.end());

    root->right = solve(rightInorder, postorder);
    root->left = solve(leftInorder, postorder);

     return root;
     }
    return nullptr;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(inorder,postorder);
    }
};