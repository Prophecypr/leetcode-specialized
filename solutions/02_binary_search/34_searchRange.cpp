/*
 * 34. Find First and Last Position of Element in Sorted Array
 * 二分查找 · 基础
 *
 * 思路：
 *   用 lower_bound 找到第一个 ≥ target 的位置 as start。
 *   若 start 不存在或 nums[start] != target → 返回 {-1, -1}。
 *   否则 end = lower_bound(nums, target + 1) - 1。
 *   即：第一个 ≥ target+1 的前一个位置 = 最后一个 target。
 *
 * 关键（手写 lower_bound）：
 *   - 闭区间 [left, right]
 *   - 循环不变量：nums[left-1] < target, nums[right+1] >= target
 *   - 出循环时 left = right+1，left 就是第一个 >= target 的位置
 *
 * 复杂度：
 *   时间 O(log n) 空间 O(1)
 */

#include <vector>

class Solution {
    // lower_bound 返回第一个 ≥ target 的下标
    int lower_bound(std::vector<int>& nums, int target) {
        int left = 0, right = (int)nums.size() - 1; // 闭区间 [left, right]
        while (left <= right) {
            int mid = left + (right - left) / 2;     // 防溢出
            if (nums[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left; // left = right+1，即第一个 ≥ target 的位置
    }

public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int start = lower_bound(nums, target);
        if (start == nums.size() || nums[start] != target)
            return {-1, -1};

        int end = lower_bound(nums, target + 1) - 1; // 第一个 ≥ target+1 的前一个 = 最后一个 target
        return {start, end};
    }
};
