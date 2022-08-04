/*
 * @lc app=leetcode.cn id=1840 lang=cpp
 *
 * [1840] 最高建筑高度
 */

// @lc code=start
# include <vector>
# include <algorithm>

using std::vector;
using std::sort;
using std::max;
using std::min;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        /*
            初始设想从0开始一直往后递增判断, 当到达一个限制区域时计算这区间内的最高值;
            因此限制区间需要按建筑序号排序;
            由于可能先增后减, 以及有可能达不到限制高度, 其最高高度为:
              以两个限制点为起点分别向另一端出发, 能获得的最高值的较小值;
            即使O(n)时间也会超时(n <= 10^9), 因此不能暴力遍历;
            可以使用数学方法直接计算得出可能的最大高度;
        */
        auto&& r = restrictions;
        r.push_back({1, 0});
        sort(r.begin(), r.end());
        if(r.back()[0] != n){
            r.push_back({n, n - 1});
        }
        int m = r.size();
        // 从左向右增长
        for(int i = 1; i < m; ++i){
            r[i][1] = min(r[i][1], r[i - 1][1] + r[i][0] - r[i - 1][0]);
        }
        // 从右向左增长
        for(int i = m - 2; i >= 0; --i){
            r[i][1] = min(r[i][1], r[i + 1][1] + r[i + 1][0] - r[i][0]);
        }
        // 计算限制高度间建筑的最大高度
        int ans = 0;
        for(int i = 1; i < m; ++i){
            int cur = (r[i][1] + r[i - 1][1] + r[i][0] - r[i - 1][0]) / 2;
            ans = max(ans, cur);
        }
        return ans;
    }
};
// @lc code=end

