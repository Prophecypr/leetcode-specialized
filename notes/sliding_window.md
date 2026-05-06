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
int left = 0;
for (int right = 0; right < n; right++) {
    if (isVowel(s[right])) vowel++;
    
    if (right - left + 1 > k) {
        if (isVowel(s[left])) vowel--;
        left++;
    }
    if (right - left + 1 == k) {
        更新答案;
    }
}
```

### 643. 子数组最大平均数 I

> 定长滑动窗口 · 基础题 · 踩坑记录 ⭐

**代码对比（第一次 → 第二次）：**

| 行 | 第一次（❌） | 第二次（✅） |
|----|------------|------------|
| 3  | `int ans=0,aver=0;` | `int ans=INT_MIN,aver=0;` |

**Bug 根因：ans 初始值选型错误**
- `ans=0` → 数组全为负数时，任何窗口和均为负，`MAX(0, 负数) = 0` → 返回错误
- `ans=INT_MIN` → 任何实际窗口和都 ≥ INT_MIN，正确

**延伸教训：**
- 求最大值时，初始值用 `INT_MIN`（或 `-inf`），不要想当然用 0
- 求最小值时，初始值用 `INT_MAX`
- 这个错误在滑动窗口、DP 中极其常见，属于**初始化惯性错误**
- 判断依据：**可能取值的下界/上界是什么**，而不是拍脑袋给 0

**次要问题：宏定义**
```c
#define MAX(a,b) (a>b) ? (a) : (b)   // ❌ 缺少外层括号
#define MAX(a,b) ((a)>(b) ? (a):(b)) // ✅
```
第一次的宏在 `ans=MAX(ans,aver)` 赋值场景下未触发优先级 bug（赋值优先级低于三元），但写成复杂表达式时（如 `MAX(a,b) + 1`）会出错。养成习惯：**宏定义整体和每个参数都加括号**。

**模板对照（与 1456 相同）：**
```c
// 唯一区别：初始值用 INT_MIN
int ans = INT_MIN, sum = 0;
for (int i = 0; i < n; i++) {
    sum += nums[i];
    if (i - k + 1 < 0) continue;
    ans = MAX(ans, sum);
    sum -= nums[i - k + 1];
}
return (double) ans / k;
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
- **`ans` 初始值**：求最大用 `INT_MIN`，求最小用 `INT_MAX`，不要惯性写 0（踩坑 643）
- **宏定义的括号**：整体和每个参数都要加括号 `#define MAX(a,b) ((a)>(b)?(a):(b))`
