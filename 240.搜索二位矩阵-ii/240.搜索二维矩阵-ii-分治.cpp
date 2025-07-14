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
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        return search(matrix, target, 0, m - 1, 0, n - 1);
    }

private:
    bool search(vector<vector<int>>& matrix, int target, 
                int rowStart, int rowEnd, int colStart, int colEnd) {
        // 边界检查：子矩阵无效时返回false
        if (rowStart > rowEnd || colStart > colEnd) {
            return false;
        }
        // 计算中心点坐标
        int midRow = (rowStart + rowEnd) / 2;
        int midCol = (colStart + colEnd) / 2;
        int midVal = matrix[midRow][midCol];
        // 找到目标值
        if (midVal == target) {
            return true;
        }
        // 中心点大于目标值：排除右下区域（第四象限）
        if (midVal > target) {
            // 递归搜索左上区域
            bool topLeft = search(matrix, target, rowStart, midRow - 1, colStart, midCol - 1);
            // 递归搜索右上区域
            bool topRight = search(matrix, target, rowStart, midRow - 1, midCol, colEnd);
            // 递归搜索左下区域
            bool bottomLeft = search(matrix, target, midRow, rowEnd, colStart, midCol - 1);
            return topLeft || topRight || bottomLeft;
        }
        // 中心点小于目标值：排除左上区域（第一象限）
        else {
            // 递归搜索右上区域
            bool topRight = search(matrix, target, rowStart, midRow, midCol + 1, colEnd);
            // 递归搜索左下区域
            bool bottomLeft = search(matrix, target, midRow + 1, rowEnd, colStart, midCol);
            // 递归搜索右下区域
            bool bottomRight = search(matrix, target, midRow + 1, rowEnd, midCol + 1, colEnd);
            return topRight || bottomLeft || bottomRight;
        }
    }
};
//双循环的话o(mn),单循环折半查找（利用有序性）o(mlogn)
//递归求解,拆分三个子问题，问题规模m/2*n/2 = 1/4mn,子问题合并复杂度o(1);
//T(mn)= 3T((1/4)*mn) + o(1);主定理 a=3 b=4 ,g(mn)=mn^[log_2(4)]≈0.792,显然有k 使f(mn) = mn ^(log_b(a)-k) 成立。问题以叶节点为主导，时间复杂度T(mn)= O(mn^(0.792))
//和二叉搜索树的mn相比，理论上在表规模极大时性能优于直接遍历的结果，但是差于折半和二叉搜索树
// @lc code=end
