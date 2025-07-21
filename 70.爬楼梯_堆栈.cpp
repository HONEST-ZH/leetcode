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
        //climbStairs(n) = climbStairs(n-1) + climbStairs(n-2);斐波那契
        stack<int> stack;
        stack.push(1);
        stack.push(2);
        stack.push(3);
        int temp1,temp2,res;
        for (int i = 3;i<n;i++){
            temp1 = stack.top();
            stack.pop();
            temp2 = stack.top();
            res = temp1 + temp2;
            stack.push(temp1);
            stack.push(res);
        }
        return  res;
    }
};
// @lc code=end

