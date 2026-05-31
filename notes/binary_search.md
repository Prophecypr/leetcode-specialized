# Binary Search — 二分查找

## 标准模板（C++）

### lower_bound — 第一个 >= target 的位置（闭区间）
```cpp
int lower_bound(vector<int>& nums, int target) {
    int left = 0, right = (int)nums.size() - 1;  // 闭区间 [left, right]
    while (left <= right) {
        int mid = left + (right - left) / 2;      // 防溢出
        if (nums[mid] >= target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;  // 第一个 >= target 的位置
}
```

### lower_bound — 第一个 >= target 的位置（开区间）
```cpp
int lower_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size();            // 开区间 [left, right)
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;  // 第一个 >= target 的位置
}
```

## 区间选择

| 区间 | 循环条件 | 更新方式 | 适用场景 |
|------|---------|---------|---------|
| `[left, right]` | `left <= right` | `left=mid+1, right=mid-1` | 精确查找 |
| `[left, right)` | `left < right` | `left=mid+1, right=mid` | 查找边界、插入位置 |

## 踩坑提醒
- `mid = left + (right - left) / 2` 防溢出，不要写 `(left+right)/2`
- 边界 `[left, right]` vs `[left, right)` 对应不同的更新逻辑，别混用
- 旋转数组二分：先判断哪半边有序，再判断 target 在哪半边

## 例题笔记

### 34. 在排序数组中查找元素的第一个和最后一个位置

> 二分查找 · 基础 · lower_bound 双调用

**思路：**
- `start = lower_bound(target)` — 第一个 ≥ target 的索引
- 若不存在 → 返回 `{-1, -1}`
- `end = lower_bound(target + 1) - 1` — 第一个 ≥ target+1 的前一个位置 = 最后一个 target
- **只用 lower_bound 一种方法，通过改变 target 完成两种查找**

**学到什么：**
- 不写两个函数，在 target 上做文章：`lower_bound(target+1)` 实现 upper_bound 效果
- 闭区间 `[left, right]` 的循环不变量：`nums[left-1] < target, nums[right+1] >= target`
- 出循环时 `left = right + 1`，left 恰好是答案
