/*
 * @lc app=leetcode.cn id=1689 lang=c
 *
 * [1689] 十-二进制数的最少数目
 */

// @lc code=start


int minPartitions(char * n){
    char ans = '0';
    while(*n != '\0'){
        ans = ans < *n ? *n : ans;
        ++n;
    }
    return ans - '0';
}
// @lc code=end

