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
        int col_start = 0, col_end = matrix[0].size() - 1;
        for (int i = 0;i<= matrix.size() - 1;i++){
            if (binary_search(matrix[i], col_start, col_end, target))
                return true;
        }
        return false;
    }
private:
    //bool binary_search(vector<int> array,int start ,int end,int target){ 
    //传参进来以后复制了数组导致超时
    // ps c++中存在三种传参方式；按值传参（深拷贝），按指针传参（复制指针，可用于修改），按引用传参（常量引用）
    bool binary_search(const vector<int>& array,int start ,int end,int target){
        if (start > end) {
                return false;
        }
        int mid = (start+end)/2;
        if (array[mid] > target){
            return binary_search(array,start,mid-1,target);
        }
        else if (array[mid] < target){
            return binary_search(array,mid+1,end,target);
        }        
        else {
            return true;
        }
    }
};
// @lc code=end