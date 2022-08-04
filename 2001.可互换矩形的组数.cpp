/*
 * @lc app=leetcode.cn id=2001 lang=cpp
 *
 * [2001] 可互换矩形的组数
 */

// @lc code=start
# include <vector>
# include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
    int gcd(int x, int y){
        int tmp;
        while(y > 0){
            tmp = y;
            y = x % y;
            x = tmp;
        }
        return x;
    }
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<long long, int> mem;
        long long ans = 0, tmp;
        for(auto& r: rectangles){
            int x = r[0], y = r[1];
            int t = gcd(x, y);
            x /= t; y /= t;
            tmp = x;
            tmp = (tmp << 32) | y;
            ++mem[tmp];
        }
        tmp = 0;
        for(auto it = mem.begin(); it != mem.end(); ++it){
            tmp = it -> second;
            ans += (tmp - 1) * tmp / 2;
        }
        return ans;
    }
};
// @lc code=end

