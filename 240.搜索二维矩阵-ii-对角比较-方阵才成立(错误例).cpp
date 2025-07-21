/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
using namespace std;
#include <vector>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //matrix[m][n]>target则对所有x>=m，y>=n，matix[x][y]>target
        //按照对角线，找到i行 i列之中第一个大于target的数
        int i;
        if (matrix[matrix.size()-1][matrix.size()-1] < target) return false;
        for (i=0;i<=matrix.size();i++){
            if (matrix[i][i] == target) return true;
            if (matrix[i][i] > target) break;
        };
        int temp = i;
        //对于matrix[temp][temp]右下角的数不用再查(一定大于target)
        //对于matrix[temp-1][temp-1]左上角的也不用查（一定小于target）
        //此时问题规约为在matirx[0][temp]到matrix[temp][temp]和matrix[temp][0]到matrix[temp][temp]之间求解
        for (i=0;i<=temp;i++){
            if (matrix[i][temp] == target)
                return true;//输出对应位置
            if (matrix [temp][i] == target)
                return true;//输出对应位置
        }
        //若在这一段没找到，矩阵中没有
        return false;
       
    }
};
//错误例，不一定是方阵！ 方阵时时间复杂度n+n+n=o(n)，常数项系数差于二叉搜索树
// @lc code=end

