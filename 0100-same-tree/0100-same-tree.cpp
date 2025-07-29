class Solution {
public:
    bool flag = true;

    void solve(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return;

        if (p == nullptr || q == nullptr) {
            flag = false;
            return;
        }

        
        if (p->val != q->val) {
            flag = false;
            return;
        }

        solve(p->left, q->left);
        solve(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        solve(p, q);
        return flag;
    }
};
