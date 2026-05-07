/*
 * 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
 * 定长滑动窗口 · 基础
 *
 * 思路：
 *   固定窗口大小为 k，维护窗口内元素和 val。
 *   避免浮点运算：threshold * k <= val 等价于 avg >= threshold。
 *   若满足条件则 ans++。
 *
 * 复杂度：
 *   时间 O(n) 空间 O(1)
 */

int numOfSubarrays(int* arr, int arrSize, int k, int threshold) {
    int ans = 0, sum = 0;

    for (int i = 0; i < arrSize; i++) {
        sum += arr[i];                      // 右边界入窗

        int left = i - k + 1;
        if (left < 0) continue;             // 窗口未满，继续

        if (threshold * k <= sum) {          // 避免浮点：用乘法替代除法
            ans++;
        }

        sum -= arr[left];                   // 滑出左边界
    }

    return ans;
}
