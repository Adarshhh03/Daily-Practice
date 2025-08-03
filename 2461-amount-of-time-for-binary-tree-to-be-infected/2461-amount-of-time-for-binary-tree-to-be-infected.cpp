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
    void findParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent,TreeNode* &target,int start){
        if(root==NULL)  return;
        TreeNode* var=root;
        if(var->val==start){
            target=root;
        }

        if(root->left){
            parent[root->left]=root;
            findParent(root->left,parent,target,start);
        }
         if(root->right){
            parent[root->right]=root;
            findParent(root->right,parent,target,start);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent;
        TreeNode* target;
        findParent(root,parent,target,start);
        set<int> st;

        queue<TreeNode*> q;
        q.push(target);
        st.insert(target->val);
        int ans=0;
        while(!q.empty()){
            int size=q.size();

            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();

                if(node->left && !st.count(node->left->val)){
                 q.push(node->left);
                 st.insert(node->left->val);
                }

                if(node->right && !st.count(node->right->val)){
                 q.push(node->right);
                 st.insert(node->right->val);
                }

                if(parent.find(node)!=parent.end() && !st.count(parent[node]->val)){
                    q.push(parent[node]);
                    st.insert(parent[node]->val);
                }
            }
            ans++;
        }

        return ans-1;
    }
};