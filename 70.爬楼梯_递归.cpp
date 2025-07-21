/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 3;
        return  climbStairs(n-1) + climbStairs(n-2);
    }
};
// @lc code=end

