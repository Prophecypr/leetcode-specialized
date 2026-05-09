/*
 * 2379. Minimum Recolors to Get K Consecutive Black Blocks
 * 定长滑动窗口 · 基础
 *
 * 思路：
 *   窗口大小固定为 k。每个窗口中 'W' 的数量就是需要重涂的次数。
 *   滑动窗口，维护 check_w（窗口内 'W' 个数），取所有窗口的最小值。
 *
 * 要点：
 *   - 只关心 'W'，不关心 'B'（check_b 维护了但未使用，可删）
 *   - 求最小值 → 初始值用 INT_MAX（类似 643 的教训）
 *   - 宏定义 MIN 也需要外层括号：
 *     #define MIN(a,b) ((a)>(b)?(b):(a))
 *
 * 复杂度：
 *   时间 O(n) 空间 O(1)
 */

#include <limits.h>

#define MIN(a,b) ((a)>(b) ? (b) : (a))

int minimumRecolors(char* blocks, int k) {
    int ans = INT_MAX, cntW = 0;

    for (int i = 0; blocks[i] != '\0'; i++) {
        if (blocks[i] == 'W') cntW++;       // 右边界入窗

        int left = i - k + 1;
        if (left < 0) continue;             // 窗口未满，继续

        ans = MIN(ans, cntW);               // 更新最小重涂次数
        if (ans == 0) break;                // 早停：0 次已经最优

        if (blocks[left] == 'W') cntW--;    // 滑出左边界
    }

    return ans;
}
