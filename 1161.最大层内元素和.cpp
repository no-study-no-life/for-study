/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> que;
        int ans = 0, val = INT_MIN, step = 0, cur;
        que.push(root);
        while(!que.empty()){
            ++step;
            cur = 0;
            for(int size = que.size(); size > 0; --size){
                TreeNode* tmp = que.front();
                que.pop();
                cur += tmp -> val;
                if(tmp -> left)que.push(tmp -> left);
                if(tmp -> right)que.push(tmp -> right);
            }
            if(cur > val){
                val = cur;
                ans = step;
            }
        }
        return ans;
    }
};
// @lc code=end

