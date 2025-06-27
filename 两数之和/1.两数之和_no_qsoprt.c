/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//手写快排在最坏情况下会退化为O(n^2)，比qsort的方法慢了很多。3ms--99ms
//时间复杂度需要改进：三值取中、在小区间内部使用插入排序、优先递归较小的区间等。
//不使用qsort的情况下，因为可以记录序号，不需要创建作为原数组复制的结构体数组，在空间有了一些改善（但是不大）9.4MB--8.6MB

#define INSERTION_SORT_THRESHOLD 16

// 交换宏
#define SWAP(a, b) { int tmp = (a); (a) = (b); (b) = tmp; }

// 插入排序
void insertionSort(int* nums, int* index, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = nums[i];
        int keyIdx = index[i];
        int j = i - 1;
        while (j >= left && nums[j] > key) {
            nums[j + 1] = nums[j];
            index[j + 1] = index[j];
            j--;
        }
        nums[j + 1] = key;
        index[j + 1] = keyIdx;
    }
}

// 三数取中法选pivot
int median3(int* nums, int* index, int left, int right) {
    int mid = left + (right - left) / 2;
    if (nums[left] > nums[mid]) { SWAP(nums[left], nums[mid]); SWAP(index[left], index[mid]); }
    if (nums[left] > nums[right]) { SWAP(nums[left], nums[right]); SWAP(index[left], index[right]); }
    if (nums[mid] > nums[right]) { SWAP(nums[mid], nums[right]); SWAP(index[mid], index[right]); }
    // 把pivot放到right-1
    SWAP(nums[mid], nums[right - 1]);
    SWAP(index[mid], index[right - 1]);
    return nums[right - 1];
}

void quickSort(int* nums, int* index, int left, int right) {
    if (right - left + 1 <= INSERTION_SORT_THRESHOLD) {
        insertionSort(nums, index, left, right);
        return;
    }
    int pivot = median3(nums, index, left, right);
    int i = left, j = right - 1;
    while (1) {
        while (nums[++i] < pivot);
        while (nums[--j] > pivot);
        if (i < j) {
            SWAP(nums[i], nums[j]);
            SWAP(index[i], index[j]);
        } else {
            break;
        }
    }
    SWAP(nums[i], nums[right - 1]);
    SWAP(index[i], index[right - 1]);
    // 优先递归较小区间，减少栈深度
    if (i - 1 - left < right - i - 1) {
        quickSort(nums, index, left, i - 1);
        quickSort(nums, index, i + 1, right);
    } else {
        quickSort(nums, index, i + 1, right);
        quickSort(nums, index, left, i - 1);
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *index = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        index[i] = i;
    }
    // 快速排序
    quickSort(nums, index, 0, numsSize - 1);
    // 双指针查找
    int left = 0, right = numsSize - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum > target) {
            right--;
        } else if (sum < target) {
            left++;
        } else {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = index[left];
            result[1] = index[right];
            *returnSize = 2;
            free(index);
            return result;
        }
    }
    *returnSize = 0;
    free(index);
    return NULL;
}
// @lc code=end

