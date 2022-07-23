/*
 * @lc app=leetcode.cn id=1658 lang=c
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

// @lc code=start


int minOperations(int* nums, int numsSize, int x){
    // 计算前缀和与后缀和, 根据和去计算所需操作数;
    int cur = 0, left = 0, right = numsSize - 1, ans = numsSize + 1;
    // 先找出左侧第一个大于等于x的位置
    while(left < numsSize && cur < x){
        cur += nums[left++];
    }
    if(cur == x)ans = left;
    if(left == numsSize && cur < x)return -1;
    // 其次逐步用右侧值替换左侧值
    while(left > 0){
        cur -= nums[--left];
        while(cur < x && right >= left){
            cur += nums[right--];
        }
        if(cur == x){
            ans = ans < (left + numsSize - right - 1) ? ans : (left + numsSize - right - 1);
        }
    }
    if(ans == numsSize + 1)return -1;
    return ans;

}
// @lc code=end

