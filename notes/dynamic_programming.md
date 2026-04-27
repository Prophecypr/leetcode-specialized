# Dynamic Programming — 动态规划

## 思考框架

```
1. 定义状态: dp[i] 或 dp[i][j] 代表什么?
2. 状态转移: dp[i] 从哪些子状态推导?
3. 初始化:   dp[0] 或边界条件
4. 遍历顺序: 从前往后 / 从小到大
5. 返回值:   dp[n] 或 dp[n-1]
```

## 常见模型（C 伪代码）

### 一维 DP
```c
int dp[n + 1];
dp[0] = 初始值;
for (int i = 1; i <= n; i++) {
    dp[i] = 从 dp[0..i-1] 中选最优;
}
```

### 二维 DP
```c
int dp[m][n];
// 初始化第一行第一列
for (int i = 1; i < m; i++)
    for (int j = 1; j < n; j++)
        dp[i][j] = 从 dp[i-1][j-1], dp[i-1][j], dp[i][j-1] 推导;
```

### 0-1 背包
```c
int dp[w + 1]; memset(dp, 0, sizeof(dp));
for (int i = 0; i < n; i++)
    for (int j = w; j >= weight[i]; j--)  // 倒序！
        dp[j] = fmax(dp[j], dp[j - weight[i]] + value[i]);
```

### 完全背包
```c
for (int i = 0; i < n; i++)
    for (int j = weight[i]; j <= w; j++)  // 正序
        dp[j] = fmax(dp[j], dp[j - weight[i]] + value[i]);
```

## 常见类型

| 类型 | 状态定义 | 代表题 |
|------|---------|--------|
| 线性 DP | dp[i] = 以 i 结尾的最优解 | 70. 爬楼梯, 198. 打家劫舍 |
| 子序列 | dp[i] = 考虑前 i 个元素 | 300. LIS, 1143. LCS |
| 背包 | dp[j] = 容量 j 的最大价值 | 322. 零钱兑换, 416. 分割等和 |
| 路径 | dp[i][j] = 到 (i,j) 的最优值 | 62. 不同路径, 64. 最小路径和 |
| 区间 | dp[i][j] = 区间 [i,j] 的最优解 | 5. 最长回文子串 |
| 状态机 | dp[i][0/1] = 第 i 天持有/不持有 | 121, 122, 123. 买卖股票 |

## 易错点
- 0-1 背包容量必须**倒序**遍历，完全背包**正序**
- `memset(dp, 0, sizeof(dp))` 只能初始化 0 或 -1（按字节）
- 注意 `int` 溢出，Long Long 可能必要
