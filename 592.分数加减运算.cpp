/*
 * @lc app=leetcode.cn id=592 lang=cpp
 *
 * [592] 分数加减运算
 */

// @lc code=start
# include <string>

using std::string;
using std::to_string;

class Solution {
public:
    int gcd(int a, int b){
        int tmp;
        while(b > 0){
            tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
    long long calc(int a, int b){
        // 获取a, b的最小公倍数
        long long x = a, y = b, tmp = gcd(a, b);
        return x * y / tmp;
    }
    string fractionAddition(string expression) {
        string ans;
        int n = expression.size(), i = 0, d;
        long long cur[2] = {0, 1}, tmp[2] = {0, 1}, val;
        bool flag = true;
        if(expression[0] == '-'){
            flag = false;
            ++i;
        }
        while(i < n){
            d = 0;
            while(i < n && expression[i] != '/'){
                d = d * 10 + expression[i++] - '0';
            }
            tmp[0] = d;
            d = 0;
            ++i;
            while(i < n && expression[i] != '+' && expression[i] != '-'){
                d = d * 10 + expression[i++] - '0';
            }
            tmp[1] = d;
            
            // 通分
            val = calc(tmp[1], cur[1]);

            tmp[0] *= val / tmp[1];
            cur[0] *= val / cur[1];
            cur[1] = val;

            if(flag){
                // 执行+操作
                cur[0] += tmp[0];
            }else{
                // 执行-操作
                cur[0] -= tmp[0];
            }
            // 最简化
            if(cur[0] == 0){
                cur[1] = 1;
            }else{
                if(cur[0] < 0){
                    val = gcd(-cur[0], cur[1]);
                }else val = gcd(cur[0], cur[1]);
                cur[0] /= val;
                cur[1] /= val;
            }
            // 判断下一次的操作类型
            if(i < n){
                if(expression[i] == '+')flag = true;
                else flag = false;
                ++i;
            }
        }
        ans = to_string(cur[0]) + string("/") + to_string(cur[1]);
        return ans;
        
    }
};
// @lc code=end

