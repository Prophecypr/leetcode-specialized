/*
 * 2461. Maximum Sum of Distinct Subarrays With Length K
 * 定长滑动窗口 · 基础 ⭐ [进阶]
 *
 * 思路：
 *   固定窗口大小 k，结合频率数组维护窗口内元素是否互异。
 *   滑动窗口的同时维护 distinct（窗口内不同元素的个数）。
 *   当 distinct == k 时，窗口内全部为不同元素，更新最大和。
 *
 * 关键点：
 *   - 需要 O(1) 判断重复 → 用计数数组 cnt[] 记录频率
 *   - cnt[nums[i]] 从 0→1 时 distinct++，从 1→0 时 distinct--
 *   - 值范围 [1, 10^5] → 可静态开数组，无需 hash map
 *   - long long 防溢出（和最大 10^5 * 10^5 = 10^10 > int）
 *   - ans=0 为默认值（若无合法子数组返回 0）
 *
 * 复杂度：
 *   时间 O(n) 空间 O(U)  U = max(nums[i])
 */

#include <stdlib.h>

#define MAX(a,b) ((a)>(b) ? (a) : (b))

long long maximumSubarraySum(int* nums, int numsSize, int k) {
    long long ans = 0, sum = 0;
    int distinct = 0;
    int* cnt = (int*)calloc(100001, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        // 右边界入窗
        sum += nums[i];
        if (cnt[nums[i]] == 0) distinct++;
        cnt[nums[i]]++;

        int left = i - k + 1;
        if (left < 0) continue;             // 窗口未满，继续

        // 窗口内元素全部不同 → 更新最大和
        if (distinct == k) {
            ans = MAX(ans, sum);
        }

        // 滑出左边界
        int out = nums[left];
        sum -= out;
        cnt[out]--;
        if (cnt[out] == 0) distinct--;
    }

    free(cnt);
    return ans;
}
