/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
# include <vector>
# include <string>

using std::vector;
using std::string;

class Solution {
public:
    int dirs[3] = {-1, 0, 1};
    bool check(const vector<string>& path, int row, int col){
        // 只用检查之前的位置有无皇后即可
        int n = path.size();
        bool flag = true;
        int step = 1, x, y;
        while(flag){
            flag = false;
            x = row - step;
            for(int i = 0; i < 3; ++i){
                y = col + dirs[i] * step;
                if(x < 0 || y < 0 || x >= n || y >= n)continue;
                flag = true;
                if(path[x][y] == 'Q')return false;
            }
            ++step;
        }
        return true;

    }
    void dfs(vector<vector<string>>& ans, vector<string>& path, int depth){
        if(depth == path.size()){
            ans.push_back(path);
            return ;
        }
        for(int i = 0; i < path.size(); ++i){
            if(path[depth][i] == '.' && check(path, depth, i)){
                path[depth][i] = 'Q';
                dfs(ans, path, depth + 1);
                path[depth][i] = '.';
            }
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> path(n, string(n, '.'));
        dfs(ans, path, 0);
        return ans;
    }
};
// @lc code=end

