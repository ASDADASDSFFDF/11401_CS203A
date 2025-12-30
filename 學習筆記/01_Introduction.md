# 簡介
## 資料結構
資料結構（DS）是一種組織資料以便有效利用資料的方式。
## 一、資料結構的分類
### 線性結構（Linear Structures）
#### 資料呈一條線的關係，每個元素前後最多各有一個相鄰元素
- 陣列（Array）：固定長度、可隨索引快速存取。
- 鏈結串列（Linked List）：長度可變、插入刪除方便。
- 堆疊（Stack）：後進先出（LIFO），如：Undo功能。
- 佇列（Queue）：先進先出（FIFO），如：排隊系統。
- 雙端佇列（Deque）：可從兩端加入或移除。
### 非線性結構（Non-linear Structures）
#### 資料呈樹狀或網狀關係
- 樹（Tree）：像家譜結構，用於階層式資料（例如檔案系統）。
  - 特殊樹：二元樹（Binary Tree）、二元搜尋樹（BST）、AVL樹、堆積（Heap）。
- 圖（Graph）：節點之間可有任意連線，用於社群網路、路線圖等。
## 二、資料結構操作
### 1.陣列（Array）
### 操作：
- Access (存取)：透過索引讀取或寫入資料 A[i]  O(1)
- Insert (插入)：在特定位置插入新元素（可能需要位移其他元素） O(n)
- Delete (刪除)：刪除特定位置的元素（同樣需位移） O(n)
- Search (搜尋)：尋找特定值（線性搜尋O(n)或二分搜尋）O(log n)
### 優缺點：
- 優點：快速存取（O(1)）
- 缺點：插入刪除慢（O(n)）
### 2.鏈結串列（Linked List）
### 核心操作：
- Insert：在開頭、結尾或指定節點後插入新節點 O(1)（若節點已知）   O(n)（若需搜尋目標）
- Delete：移除特定節點  O(1)（若節點已知）   O(n)（若需搜尋目標）
- Search：逐節點搜尋資料 O(n)
- Traverse：依序走訪所有節點 O(n)
### 優缺點
- 優點：插入、刪除快速（O(1)）
- 缺點：存取慢（O(n)），無法隨機存取
### 3.堆疊（Stack）
### 核心操作：
- Push：把元素放入堆疊頂端
- Pop：移除堆疊頂端的元素
- Peek/Top：查看頂端元素但不移除
- IsEmpty：檢查堆疊是否為空
### 優缺點
- 優點：結構簡單、操作容易實作。
- 缺點：只能存取頂端元素，無法直接存取中間或底部資料
### 4.佇列（Queue）
### 核心操作：
- Enqueue：將元素放入佇列尾端
- Dequeue：移除佇列前端的元素
- Front：查看前端元素
- IsEmpty：檢查是否為空
### 優缺點
- 優點：可避免資料競爭
- 缺點:存取不靈活
### 5.樹（Tree）
### 核心操作：
- Insert：插入新節點
- Delete：刪除節點
- Search：搜尋特定節點
- Traversal：走訪所有節點
- -  前序 (Preorder)
- -  中序 (Inorder)
- -  後序 (Postorder)
### 優缺點
- 優點：階層關係明確
- 缺點：記憶體開銷大
### 6.雜湊表（Hash Table）
### 核心操作：
- 插入（Insert）(key, value)：加入鍵值對
- Search(key)：依鍵查找
- Delete(key)：刪除鍵值對
### 優缺點
- 優點：搜尋、插入、刪除都非常快（平均 O(1)）,很適合大量資料存取
- 缺點：嚴重依賴雜湊函數品質,最壞情況可能變 O(n)
### 7.堆(Heap)
### 核心操作：
- 插入（Insert）:
- 1.將新元素放到樹的最底層、最右側
- 2.進行 向上調整（Heapify Up / Sift Up）
- 時間複雜度：O(log n)（樹高）
- 取出(Extract):
- 1.取出根節點
- 2.用最後一個節點補到根
- 3.進行 向下調整
- 時間複雜度：O(log n)
- 取得最值（Peek）:直接回傳根節點
- 時間複雜度:O(1)
### 優缺點
- 優點：插入與刪除效率穩定: Insert / Extract 都是 O(log n)
- 缺點：不適合搜尋任意元素: 搜尋特定值：O(n)
### 8.圖(Graph)




### Asymptotic Notation

Asymptotic notation is used to describe the behavior of an algorithm's time or space complexity as the input size grows. The three main notations are:

- **Big-O (O)**: Represents the *upper bound* or *worst-case* complexity.  
f(n) = O(g(n)) iff there exist positive constant C and n0 such that, 0 <= f(n) <= Cg(n) for all n, n >= n0. 
- **Omega (Ω)**: Represents the *lower bound* or *best-case* complexity.  
f(n) = Ω(g (n)) iff there exists positive constant C and (n0) such that  0 <= Cg(n) <= f(n) for all n, n >= n0.
- **Theta (θ)**: Represents the *tight bound* or *average-case* complexity.  
f(n) = Θ(g(n)) iff f(n) = O(g(n)) and f(n) = Ω(g(n)), for all n, n >= n0. 

Both time complexity and space complexity can be expressed using asymptotic notation

### Terminology
| Time Complexity | Description       | Example                                                                    |
|-----------------|-------------------|----------------------------------------------------------------------------|
| O(1)            | Constant time     | Fetching the first element form a set of data                              |
| O(log n)        | Logarithmic time  | Splitting a set of data in half, then splitting the halves in half, etc    |
| O(n)            | Linear time       | Traversing a set of data                                                   |
| O(n log n)      | Linearithmic time | Splitting a set of data in half repeatedly and traversing each half        |
| O(n²)           | Quadratic time    | Traversing a set of data once for each member of another set of equal size |
| O(n³)           | Cubic time        | Calculating the product of two n x n matrices using a triple nested loop      |
| O(2n)           | Exponential time  | Generating all possible subsets of a set of data                           |
| O(n!)           | Factorial time    | Generating all possible permutations of a set of data                      |
