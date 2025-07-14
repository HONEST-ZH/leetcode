/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //排序的二维矩阵满足性质：向左减小，向下扩大；向左旋转45度，等价于根在右上角的一颗二叉搜索树
        //if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0, col = n - 1;

        // 从右上角开始向左下查找
        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                --col;  // 目标更小 → 向左走
            } else {
                ++row;  // 目标更大 → 向下走
            }
        }
        return false;
    }
};
// @lc code=end

