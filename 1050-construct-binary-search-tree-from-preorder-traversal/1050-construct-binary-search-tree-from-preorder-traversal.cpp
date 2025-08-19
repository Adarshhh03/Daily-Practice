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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
         if (preorder.empty()) return NULL;

    int rootVal = preorder[0];
    TreeNode* root = new TreeNode(rootVal);

    vector<int> leftPart, rightPart;
    for (int i = 1; i < preorder.size(); i++) {
        if (preorder[i] < rootVal)
            leftPart.push_back(preorder[i]);
        else
            rightPart.push_back(preorder[i]);
    }

  
    root->left = bstFromPreorder(leftPart);
    root->right = bstFromPreorder(rightPart);

    return root;
    }
};