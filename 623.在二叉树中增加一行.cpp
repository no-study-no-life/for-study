/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
 */

// @lc code=start
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* cur = new TreeNode(val);
            cur -> left = root;
            return cur;
        }
        int step = 1;
        queue<TreeNode*> que;
        que.push(root);
        while(step < depth - 1){
            for(int i = que.size(); i > 0; --i){
                TreeNode* cur = que.front();
                que.pop();
                if(cur -> left)que.push(cur -> left);
                if(cur -> right)que.push(cur -> right);
            }
            ++step;
        }
        while(!que.empty()){
            TreeNode* cur = que.front(), *left = cur -> left, *right = cur -> right;
            que.pop();
            cur -> left = new TreeNode(val, left, nullptr);
            cur -> right = new TreeNode(val, nullptr, right);
        }
        return root;

    }
};
// @lc code=end

