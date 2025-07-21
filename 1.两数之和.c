/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct item{
    int value; // 数值
    int index; // 原数组的索引
} item;
//qsort可以对结构体数组进行排序，可以使用自定义的比较函数。cmp在a<b时返回负数，a>b时返回正数，a==b时返回0。
int cmp(const void* a, const void* b) {
    return ((item*)a)->value - ((item*)b)->value;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // 排序原来的数组使其变为一个有序的数组，这里使用nlogn的排序算法对数组排序。
    // C标准库具有qsort()函数可以进行快速排序，但由于其会改变在原数组中的位置，需要使用一个结构体数组实现，数组应该具有值和其在原数组中的索引信息。
    item* increase = (item*)malloc(numsSize * sizeof(item));
    memset(increase, 0, numsSize * sizeof(item));
    for (int i = 0; i < numsSize; i++) {
        increase[i].value = nums[i];
        increase[i].index = i;
    }
    qsort(increase, numsSize, sizeof(item), cmp);
    // 然后使用双指针的方式，左指针从头开始，右指针从尾部开始，从两端向中间遍历。
    // 若两指针的和大于目标，则右指针向左移动，若小于目标，则左指针向右移动。
    int left = 0, right = numsSize - 1;
    for (int i = 0; i< numsSize; i++){
        if (increase[left].value + increase[right].value > target) {
            // 右指针向左移动
            right--;
        }
        else if (increase[left].value + increase[right].value < target) {
            // 左指针向右移动
            left++;
        } 
        else {
            // 找到目标值，返回原数组中的索引
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = increase[left].index;
            result[1] = increase[right].index;
            *returnSize = 2;
            free(increase);
            return result;
        }
    }
    *returnSize = 0;
    return NULL;
    //时间复杂度分析：创建原数组复制n + 排序数组nlogn + 双指针遍历n = O(nlogn)
}
// @lc code=end

