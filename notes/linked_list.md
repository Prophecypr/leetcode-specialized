# Linked List — 链表

## 常用技巧

### 哑节点（Dummy Node）
```c
struct ListNode dummy;
dummy.next = head;
struct ListNode* cur = &dummy;
```

### 快慢指针
```c
// 找中点
struct ListNode *slow = head, *fast = head;
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
}
// slow 现在是中点
```

### 反转链表（迭代）
```c
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *prev = NULL, *cur = head, *next;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
```

## 常见题目模式

| 模式 | 技巧 | 代表题 |
|------|------|--------|
| 反转 | 逐个翻转指针 | 206. 反转链表 |
| K 组翻转 | 先反转前 K 个，递归处理剩余 | 25. K 个一组翻转 |
| 环检测 | 快慢指针 | 141. 环形链表 |
| 相交 | 先对齐长度，再同步走 | 160. 相交链表 |
| 回文 | 找中点 → 反转后半 → 比较前半 | 234. 回文链表 |
| 合并 K 链表 | 优先队列 / 分治 | 23. 合并 K 链表 |

## 易错点
- C 语言手动 `malloc` 节点后要记得 `free`
- 操作指针顺序：先存 `next`，再改指向
- 链表题画图！不画图容易断链
