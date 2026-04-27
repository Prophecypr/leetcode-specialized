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
