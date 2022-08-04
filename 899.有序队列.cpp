/*
 * @lc app=leetcode.cn id=899 lang=cpp
 *
 * [899] 有序队列
 */

// @lc code=start
# include <string>

using std::string;

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1){
            string ans(s), cur(s);
            for(int i = 0; i < s.length() - 1; ++i){
                cur = cur.substr(1) + cur[0];
                if(cur < ans)ans = cur;
            }
            return ans;
        }else{
            int cnt[26] = {0};
            for(char c: s){
                ++cnt[c - 'a'];
            }
            string ans;
            for(int i = 0; i < 26; ++i){
                if(cnt[i]) ans += string(cnt[i], 'a' + i);
            }
            return ans;
        }

    }
};
// @lc code=end

