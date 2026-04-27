# Tree — 二叉树遍历

## 递归三要素
```c
void traverse(struct TreeNode* root) {
    if (!root) return;           // 终止条件
    // 前序位置（进入节点时）
    traverse(root->left);        // 递归左子树
    // 中序位置（左子树遍历完）
    traverse(root->right);       // 递归右子树
    // 后序位置（左右子树都遍历完）
}
```

## 迭代遍历（C + 栈）

### 前序 / 中序
```c
// 前序：根→左→右
struct TreeNode* stack[10000];
int top = -1;
struct TreeNode* cur = root;
while (cur || top >= 0) {
    while (cur) {
        // 前序：在这里访问 cur（记录值）
        stack[++top] = cur;
        cur = cur->left;
    }
    cur = stack[top--];
    // 中序：在这里访问 cur
    cur = cur->right;
}
```

### 层序遍历（BFS）
```c
struct TreeNode* queue[10000];
int front = 0, rear = 0;
queue[rear++] = root;
while (front < rear) {
    int size = rear - front;     // 当前层节点数
    for (int i = 0; i < size; i++) {
        struct TreeNode* node = queue[front++];
        // 处理 node
        if (node->left) queue[rear++] = node->left;
        if (node->right) queue[rear++] = node->right;
    }
}
```

## 常见套路

| 问题 | 技巧 | 题号 |
|------|------|------|
| 最大深度 | 递归 max(left, right) + 1 | 104 |
| 翻转 | 后序交换左右子树 | 226 |
| 最近公共祖先 | 后序：左右分别找，都找到则当前是 LCA | 236 |
| 路径和 | 前序累加，后序减去 | 437, 112 |
| 最大路径和 | 后序：左+右+root，取 max | 124 |
| 直径 | 后序：左高+右高，取 max | 543 |
| BST 验证 | 传递 (min, max) 范围 | 98 |
| 序列构造 | 前序第一个是根，中序划分左右 | 105 |

## C 语言注意
- LeetCode 中 `struct TreeNode` 已定义：`int val; struct TreeNode *left, *right;`
- 数组模拟栈/队列，注意大小（10000 通常够用）
- 层序遍历用 `size = rear - front` 隔离每一层
