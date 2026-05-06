/*
 * 643. Maximum Average Subarray I
 * 定长滑动窗口 · 基础
 *
 * 思路：
 *   固定窗口大小为 k，维护窗口内元素和 aver。
 *   每步更新 ans 为窗口最大和，最后返回 ans/k。
 *
 * 易错点（踩坑记录）：
 *   - ans 必须初始化为 INT_MIN 而非 0。
 *     若数组全为负数，任何子数组和均为负，ans=0 会永远返回 0，导致错误。
 *   - 宏定义 MAX 外层缺少括号：
 *     #define MAX(a,b) (a>b) ? (a) : (b)
 *     在复杂表达式中优先级可能出问题，正确写法：
 *     #define MAX(a,b) ((a)>(b) ? (a) : (b))
 *     但在本解法 ans=MAX(ans,aver) 的赋值场景下未触发，因为赋值优先级低于三元。
 *
 * 复杂度：
 *   时间 O(n) 空间 O(1)
 */

#include <limits.h>

#define MAX(a,b) ((a)>(b) ? (a) : (b))

double findMaxAverage(int* nums, int numsSize, int k) {
    int ans = INT_MIN, sum = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];                     // 右边界入窗

        int left = i - k + 1;
        if (left < 0) continue;             // 窗口未满，继续

        ans = MAX(ans, sum);                // 更新最大和

        sum -= nums[left];                  // 滑出左边界
    }

    return (double) ans / k;
}
