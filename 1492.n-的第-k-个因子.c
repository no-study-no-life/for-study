/*
 * @lc app=leetcode.cn id=1492 lang=c
 *
 * [1492] n 的第 k 个因子
 */

// @lc code=start


int kthFactor(int n, int k){
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        if(n % i == 0)++cnt;
        if(cnt == k)return i;
    }
    return -1;
}
// @lc code=end

