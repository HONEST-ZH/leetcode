/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        return search(matrix, target, 0, 0, matrix.size(), matrix[0].size());
    }

private:
    // 在子矩阵 (row, col) 开始，尺寸为 (rows x cols) 中搜索
    bool search(vector<vector<int>>& matrix, int target, int row, int col, int rows, int cols) {
        // 子矩阵非法
        if (rows <= 0 || cols <= 0) return false;

        // 主对角线的长度 = min(rows, cols)
        int diag = min(rows, cols);
        int low = 0, high = diag - 1;

        // 二分搜索主对角线中 >= target 的位置
        while (low <= high) {
            int mid = (low + high) / 2;
            int val = matrix[row + mid][col + mid];

            if (val == target) return true;
            else if (val < target) low = mid + 1;
            else high = mid - 1;
        }

        // 此时 low 是第一个大于 target 的对角线元素索引
        // 分成两部分：
        // A. 右上区：从 (row, col + low) 开始，大小为 (low x (cols - low))
        // B. 左下区：从 (row + low, col) 开始，大小为 ((rows - low) x low)
        return search(matrix, target, row, col + low, low, cols - low) || 
               search(matrix, target, row + low, col, rows - low, low);
    }
};
// @lc code=end

