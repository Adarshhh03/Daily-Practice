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
    int widthOfBinaryTree(TreeNode* root) {
      if(root == NULL)
            return 0;
        
        long long res = 1;
        queue<pair<TreeNode*, long long>> q;
        
       
        q.push({root, 0});    
        
        while(!q.empty())
        {
            long long cnt = q.size();
           
            long long start = q.front().second;
            long long end = q.back().second;
            
            res = max(res,end-start + 1);
            
            for(int i = 0; i <cnt; ++i)
            {
                pair<TreeNode*, int> p = q.front();
                /*We are propagating the difference even if we subtract it with mmin(which is position of first element), because if their is difference it will get propogated and lead us to answer. We could have been also do this using only the cuurent level order position without subtracting but it could overflow sometimes so we subtract*/
                long long idx = p.second - start;
                
                q.pop();
                
        
                if(p.first->left != NULL)
                    q.push({p.first->left, (long long)2 * idx + 1});
                
  
                if(p.first->right != NULL)
                    q.push({p.first->right, (long long) 2 * idx + 2});
            }
        }
        
        return res;  
    }
};