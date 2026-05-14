/*
 * 1423. Maximum Points You Can Obtain from Cards
 * 定长滑动窗口 · 基础
 *
 * 思路（反证法）：
 *   从两端取 k 张牌 → 剩下的 n-k 张牌在数组中间必然连续。
 *   因此：max(取的牌和) = total - min(中间 n-k 张的和)
 *   转化为定长滑动窗口求最小子数组和，窗口大小 = n-k。
 *
 * 为什么对：
 *   不论从左边取多少张、从右边取多少张，没被取的牌一定
 *   在中间形成一个连续子数组。最大化取的 = 最小化留下的。
 *
 * 复杂度：
 *   时间 O(n) 空间 O(1)
 */

#include <limits.h>

#define MIN(a,b) ((a)<(b) ? (a) : (b))

int maxScore(int* cardPoints, int cardPointsSize, int k) {
    // 计算总点数
    int total = 0;
    for (int i = 0; i < cardPointsSize; i++) {
        total += cardPoints[i];
    }

    // 特例：取全部牌
    if (k == cardPointsSize) return total;

    int window = cardPointsSize - k;   // 中间留下的连续牌数
    int minSum = INT_MAX, sum = 0;

    // 定长滑动窗口，求长度为 window 的最小和
    for (int i = 0; i < cardPointsSize; i++) {
        sum += cardPoints[i];

        int left = i - window + 1;
        if (left < 0) continue;

        minSum = MIN(minSum, sum);

        sum -= cardPoints[left];
    }

    return total - minSum;
}
