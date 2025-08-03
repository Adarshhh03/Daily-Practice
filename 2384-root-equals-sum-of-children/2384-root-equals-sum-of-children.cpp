class Solution {
public:
    bool checkTree(TreeNode* root) {
        if (root == nullptr || (!root->left && !root->right)) {
            return true;
        }
        //first we check at the current level whether it holds the property, if not we reverse from their we return false and thus it is traversed to the top and return null. 
        int sum = 0;
        if (root->left) sum += root->left->val;
        if (root->right) sum += root->right->val;

        if (root->val != sum) return false;

        return checkTree(root->left) && checkTree(root->right);
    }
};
