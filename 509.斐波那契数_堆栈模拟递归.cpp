/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if (n==0) return 0;
        if (n==1) return 1;
        stack<int> stack;
        stack.push(0);
        stack.push(1);
        int temp1,temp2,res;
        for (int i = 0;i<= n-2;i++){
            temp1 = stack.top();
            stack.pop();
            temp2 = stack.top();
            res = temp1 + temp2;
            stack.push(temp1);
            stack.push(res);   
        }
        return res;
    }
};
// @lc code=end

