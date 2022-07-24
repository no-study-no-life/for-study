/*
 * @lc app=leetcode.cn id=919 lang=cpp
 *
 * [919] 完全二叉树插入器
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
# include <vector>
using std::vector;

class CBTInserter {
    vector<TreeNode*> mem;
public:
    CBTInserter(TreeNode* root) {
        int last = 0, cur = 0;
        TreeNode* tmp;
        mem.push_back(root);
        last += 1;
        while(cur < last){
            tmp = mem[cur++];
            // 要求输入一定是完全二叉树
            if(tmp -> left){ mem.push_back(tmp -> left); ++last; }
            if(tmp -> right){ mem.push_back(tmp -> right); ++last; }
        }
    }
    
    int insert(int val) {
        int size = mem.size(), index = (size - 1) / 2;
        TreeNode* cur = new TreeNode(val);
        mem.push_back(cur);
        if(size & 1){
            mem[index] -> left = cur;
        }else{
            mem[index] -> right = cur;
        }
        return mem[index] -> val;
    }
    
    TreeNode* get_root() {
        return mem[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end

