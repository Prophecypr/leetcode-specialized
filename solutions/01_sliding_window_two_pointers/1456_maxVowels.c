/*
 * 1456. Maximum Number of Vowels in a Substring of Given Length
 * 定长滑动窗口 · 基础
 *
 * 思路：
 *   固定窗口大小为 k，维护窗口内元音字母计数 vowel。
 *   每次右边界扩展时，若新字符是元音则 vowel++。
 *   当窗口大小 >= k 时，更新答案并滑出左边界。
 *
 * 优化：
 *   - 若 ans 已达到 k（最大可能值），直接 break 提前返回。
 *   - 用宏 MAX 简化取最大值。
 *
 * 复杂度：
 *   时间 O(n) 空间 O(1)
 */

#define MAX(a,b) ((a)>(b) ? (a):(b))

int maxVowels(char* s, int k) {
    int ans = 0, vowel = 0;

    for (int i = 0; s[i]; i++) {
        // 1. 右边界入窗
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
            s[i] == 'o' || s[i] == 'u') {
            vowel++;
        }

        int left = i - k + 1;      // 左边界下标
        if (left < 0) continue;    // 窗口尚未达到 k，继续扩大

        // 2. 更新答案
        ans = MAX(ans, vowel);

        // 3. 早停：已达到最大值
        if (ans == k) break;

        // 4. 滑出左边界
        char out = s[left];
        if (out == 'a' || out == 'e' || out == 'i' ||
            out == 'o' || out == 'u') {
            vowel--;
        }
    }

    return ans;
}
