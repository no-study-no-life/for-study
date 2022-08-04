/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 */

// @lc code=start
// 求两个字符串的最大公共子串, 且要求ascii值最大
// arr[i][j]表示s1[:i]与s2[:j]的最大ascii值
# include <string>
# include <algorithm>
# include <vector>

using std::max;
using std::string;
using std::vector;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        int total = 0, maxval = 0;
        vector<vector<int>> arr(m + 1, vector<int>(n + 1));
        for(int i = 0; i < m; ++i){
            total += s1[i];
        }
        for(int i = 0; i < n; ++i){
            total += s2[i];
        }
        if(m == 0 || n == 0)return total;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(s1[i] == s2[j]){
                    arr[i + 1][j + 1] = arr[i][j] + s1[i];
                }else{
                    arr[i + 1][j + 1] = max(arr[i][j + 1], arr[i + 1][j]);
                }
                maxval = max(maxval, arr[i + 1][j + 1]);
            }
        }
        return total - 2 * maxval;
    }
};
// @lc code=end

