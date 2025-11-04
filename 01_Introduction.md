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
### 堆疊（Stack）

## Type of Data Structures
### Primitive Data Structures
- Primitive data types correspond to primitive data structures. 
- The primitive data structures that can store a single value are int, char, float, double, and pointer.

### Non- Primitive Data Structures
- The non-primitive data structures are of two types:
    - Linear Data Structures – The data items are ordered in a linear or sequential order in a linear data structure, with each item being directly connected to its neighbors before and after. Some of its examples are – lists, queues, stacks, etc. 
    - Non-Linear Data Structures – This data structure is the opposite of the linear one. Here the data or the elements are arranged in many-one, one-many, or many-many dimensions. It is not single-dimension data like its counterpart. Some examples of non-linear data structures are tables, trees, and graphs.



## Performance Analysis
### Time complexity
Time complexity quantifies the amount of time an algorithm takes to complete its execution as a function of the input size.
### Space complexity
Space complexity quantifies the amount of memory space an algorithm requires during its execution as a function of the input size.

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
