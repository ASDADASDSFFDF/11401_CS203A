## 樹（Tree）
### 一、定義
#### 樹（Tree）是一種非線性資料結構，由多個節點（Node）與邊（Edge）組成，用來表示具有階層關係的資料。
- 最上層節點稱為 Root（根節點）
- 每個節點可有 0 個或多個子節點
- 樹中不存在循環（Cycle）
### 二、基本名詞
- Root：根節點
- Parent / Child：父節點 / 子節點
- Sibling：兄弟節點
- Level / Depth：節點所在層級
- Height：樹的最大深度
### 三、Tree 的基本性質
- 若樹有 n 個節點，則邊數為 n − 1
- 任兩節點間只有唯一一條路徑
- 子樹（Subtree）本身也是一棵樹
### 四、Binary Tree（二元樹）
#### 定義
##### 每個節點最多只有兩個子節點，分為：Left Child和Right Child
### 五、常見 Binary Tree 類型
#### Full Binary Tree（滿二元樹）:每個節點要嘛有 0 個子節點，要嘛有 2 個
#### Complete Binary Tree（完全二元樹）:除最後一層外，其餘層皆滿，最後一層由左向右填滿
#### Perfect Binary Tree（完美二元樹）:所有層皆滿
### 六、Binary Search Tree（BST）
#### 性質
- 左子樹所有值 < 根節點
- 右子樹所有值 > 根節點
- 中序走訪（Inorder）結果為遞增序列
### 七、時間複雜度（BST）
```
操作	平衡情況	最壞情況
Search	O(log n)	O(n)
Insert	O(log n)	O(n)
Delete	O(log n)	O(n)
```

















