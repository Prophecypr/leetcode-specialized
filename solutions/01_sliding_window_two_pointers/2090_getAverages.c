/*
 * 2090. K Radius Subarray Averages
 * 定长滑动窗口 · 基础 ⭐ [难题]
 *
 * 思路：
 *   窗口大小为 2k+1（中心 + 左右各 k）。
 *   用右指针 i 遍历，窗口覆盖 [i-2k, i] → 中心为 i-k。
 *   当 i >= 2k 时窗口已满，计算中心位置 i-k 的平均值。
 *   边缘位置（距两端不足 k）填 -1。
 *
 * 关键技巧：
 *   - 窗口对齐：右指针 i 对应窗口右端，中心在 i-k，左端在 i-2k
 *   - 这种"滞后中心"写法避免了单独维护双指针，代码更紧凑
 *   - long long 防溢出：窗口内最多 2k+1 个元素，和可能超 int
 *
 * 复杂度：
 *   时间 O(n) 空间 O(n)
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getAverages(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize;
    long long sum = 0;
    int* avgs = (int*)malloc(sizeof(int) * numsSize);
    int windowSize = 2 * k + 1;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];                     // 右边界入窗

        int left = i - 2 * k;               // 窗口左端 = i - 2k
        if (left < 0) continue;             // 窗口未满，继续

        avgs[i - k] = sum / windowSize;     // 计算中心 i-k 的平均值

        sum -= nums[left];                  // 滑出左边界
    }

    // 边缘位置（距两端不足 k 个元素）填 -1
    for (int i = 0; i < k && i < numsSize; i++) {
        avgs[i] = -1;
    }
    for (int i = numsSize - k; i < numsSize; i++) {
        if (i >= 0) avgs[i] = -1;
    }

    return avgs;
}
