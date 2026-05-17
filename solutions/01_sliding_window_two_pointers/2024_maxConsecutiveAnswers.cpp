/*
 * 2024. Maximize the Confusion of an Exam
 * 不定长滑动窗口 · 求最长/最大（基础）
 *
 * 思路：
 *   窗口内可以翻转最多 k 个字符使其全同。
 *   等价于：最多允许 k 个 'T' 或 k 个 'F' 存在。
 *   当 cntT > k && cntF > k 时，无论翻哪种都超过预算 → 收缩。
 *   最终 ans = 最长合法窗口。
 *
 * 关键：
 *   收缩条件 cntT > k && cntF > k 是双计数器同时超标，
 *   与之前"只有一种约束"的题不同。
 *
 * 复杂度：
 *   时间 O(n) 空间 O(1)
 */

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = 0, left = 0;
        int cnt[2] = {};        // cnt[0]='F'数, cnt[1]='T'数

        for (int right = 0; right < answerKey.length(); right++) {
            cnt[answerKey[right] == 'T']++;  // true→1(T), false→0(F)

            // 两种都超 k → 窗口不合法（无论翻哪种都救不了）
            while (cnt[0] > k && cnt[1] > k) {
                cnt[answerKey[left] == 'T']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
