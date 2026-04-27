# Binary Search — 二分查找

## 标准模板（C）

```c
// 查找精确值
int binarySearch(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// 查找左边界（第一个 >= target 的位置）
int lowerBound(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize;  // 注意 right = numsSize
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    return left;
}

// 查找右边界（最后一个 <= target 的位置）
int upperBound(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) left = mid + 1;
        else right = mid;
    }
    return left - 1;
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
