# Sliding Window — 滑动窗口

## 模板（C）

```c
// 固定窗口大小
int left = 0;
for (int right = 0; right < n; right++) {
    // 更新窗口状态（加入 right）
    window[arr[right]]++;
    
    if (right - left + 1 > k) {
        // 移除 left
        window[arr[left]]--;
        left++;
    }
    // 处理窗口结果
}

// 可变窗口大小（求满足条件的最小/最大窗口）
int left = 0;
for (int right = 0; right < n; right++) {
    window[arr[right]]++;
    
    while (窗口不满足条件) {
        window[arr[left]]--;
        left++;
    }
    // 此时 [left, right] 是满足条件的最小窗口
    更新答案;
}
```

## 例题笔记

### 1456. 定长子串中元音的最大数目

> 定长滑动窗口 · 基础题

**思路拆解：**
1. 右指针 `i` 遍历字符串，新字符是元音则 `vowel++`
2. 窗口未满 `k` 时（`i - k + 1 < 0`）继续扩大，不更新答案
3. 窗口满 `k` 后更新 `ans = max(ans, vowel)`
4. 若 `ans == k`（已达理论最大值），直接 `break` 早停
5. 滑出左边界字符：若是元音则 `vowel--`

**学到什么：**
- 定长窗口的典型写法：`left = i - k + 1` 定位左边界
- 元音判断条件长冗余 → 可考虑用位掩码或 `strchr("aeiou", c)` 简化
- **早停优化**：当 ans 达到 k 时不可能更大，直接返回，常数级优化但在某些 case 有效
- 先更新答案再滑出左边界（先判断后移除，顺序不能反）

**模板对照：**
```c
// 与本 repo 模板的对应关系
int left = 0;                                      // 这里的 left 变量实际上由 i-k+1 隐式表示
for (int right = 0; right < n; right++) {
    // 更新窗口状态（加入 right）
    if (isVowel(s[right])) vowel++;
    
    if (right - left + 1 > k) {                     // 等同 left < 0 的判断逻辑
        // 移除 left
        if (isVowel(s[left])) vowel--;
        left++;
    }
    if (right - left + 1 == k) {
        更新答案;
    }
}
```

## 常见类型

| 类型 | 特点 | 代表题 |
|------|------|--------|
| 固定大小 | `right-left+1 == k` 时更新答案 | 239. 滑动窗口最大值 |
| 最长子串 | `while` 缩小直到满足条件 | 3. 无重复最长子串 |
| 最小覆盖 | `while` 缩小直到不满足，取上一次结果 | 76. 最小覆盖子串 |
| 前缀和+窗口 | 用前缀和数组快速计算区间和 | 209. 长度最小子数组 |

## 易错点
- `while` 不是 `if`：窗口可能需要持续收缩
- 移除 left 时注意边界：先减再移，还是先移再减
- 字符串题注意 `strlen` 和数组下标的对应
