/*
 * @lc app=leetcode.cn id=1177 lang=cpp
 *
 * [1177] 构建回文串检测
 */

// @lc code=start

# include <vector>
# include <string>
using std::vector;
using std::string;

class Solution {
public:
    int count_bits(int x){
        // n & (n - 1)快速去除一位;
        int cnt = 0;
        while(x){
            x &= x - 1;
            ++cnt;
        }
        return cnt;
    }
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        // 每次选一个片段再计算长度会超时
        // 需要预先处理字符出现次数;
        // 利用前缀数组, 用一个整型26位, 记录每一个字母的状态;
        // 用异或运算可以得出目标片段的改变情况; 
        int n = queries.size(), m = s.length(), check;
        vector<bool> ans(n);
        vector<int> prix(m + 1);
        int loc = 0;
        for(int i = 0; i < m; ++i){
            loc = s[i] - 'a';
            prix[i + 1] = prix[i] ^ (1 << loc);
        }
        for(int i = 0; i < n; ++i){
            int left = queries[i][0], right = queries[i][1], k = queries[i][2];
            check = (prix[left] ^ prix[right + 1]);
            ans[i] = count_bits(check) / 2 <= k;
        }
        return ans;
    }
};
// @lc code=end

