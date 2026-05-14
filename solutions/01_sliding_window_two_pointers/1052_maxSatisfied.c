/*
 * 1052. Grumpy Bookstore Owner
 * 定长滑动窗口 · 进阶 ⭐ [双累加器技巧]
 *
 * 思路：
 *   用 s2[2] 双累加器，利用 grumpy[i] 作为下标分类统计：
 *     s2[0] = 不生气时的顾客（永远满意，全量累加，不参与滑动）
 *     s2[1] = 生气时的顾客（仅在窗口内才满意，需滑动维护）
 *   滑动窗口（大小 = minutes）跟踪 s2[1] 的最大值。
 *   答案 = s2[0] + max(s2[1] in window)
 *
 * 关键洞察：
 *   用 s2[grumpy[i]] 一行完成分类累加，无需 if-else 分支。
 *   出窗时只处理 grumpy=1 的部分：s2[1] -= out（grumpy=0 的出窗不影响 s2[1]）。
 *
 * 复杂度：
 *   时间 O(n) 空间 O(1)
 */

#define MAX(a,b) ((a)>(b) ? (a) : (b))

int maxSatisfied(int* customers, int customersSize, int* grumpy,
                 int grumpySize, int minutes) {
    int ans = 0, sum = 0;
    int s2[2] = {0};        // s2[0]=永远满意, s2[1]=窗口内生气顾客

    for (int i = 0; i < customersSize; i++) {
        s2[grumpy[i]] += customers[i];      // 双路累加：grumpy 做下标

        int left = i - minutes + 1;
        if (left < 0) continue;

        ans = MAX(s2[1], ans);              // 跟踪窗口内生气顾客的最大值

        // 滑出左边界：只有 grumpy 才减少 s2[1]
        if (grumpy[left]) s2[1] -= customers[left];
    }

    return ans + s2[0];                     // 永远满意 + 窗口内最大满意生气顾客
}
