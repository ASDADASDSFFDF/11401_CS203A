# 作業四：雜湊函數設計與觀察（C/C++ 版本）
本次作業重點在於使用 C/C++ 設計和觀察雜湊函數。

開發者：[張景翔]

信箱：[ben950810@gmail.com]
## 我的哈希函數
### 整數鍵
- 公式/偽代碼：
  int myHashInt(int key, int m) {
   return key % m ;  // 確保正值
 ```
[=== Table Size m = 10 ===]
Key     Index
-----------------
21      1
22      2
23      3
24      4
25      5
26      6
27      7
28      8
29      9
30      0
51      1
52      2
53      3
54      4
55      5
56      6
57      7
58      8
59      9
60      0

=== Table Size m = 11 ===
Key     Index
-----------------
21      10
22      0
23      1
24      2
25      3
26      4
27      5
28      6
29      7
30      8
51      7
52      8
53      9
54      10
55      0
56      1
57      2
58      3
59      4
60      5

=== Table Size m = 37 ===
Key     Index
-----------------
21      21
22      22
23      23
24      24
25      25
26      26
27      27
28      28
29      29
30      30
51      14
52      15
53      16
54      17
55      18
56      19
57      20
58      21
59      22
60      23]
  ```
- 原理：[把 key 均勻映射到 0~m-1 範圍。 ]

### 非整數鍵
- 公式/偽代碼：
```
A-1
int myHashString(const std::string& str, int m) {
const int p = 13;
    unsigned long hash = 0;
    // p_pow 用於儲存 p 的當前冪次 (p^i)，迭代更新以避免昂貴的求冪運算。
    unsigned long p_pow = 1;
    // 遍歷字串中的每個字符
    for (char c : str) {
        hash = (hash + ((unsigned long)c * p_pow)) % m;
        p_pow = (p_pow * p) % m;
    }
    return static_cast<int>(hash);
}
```
```
A-2
int myHashString(const std::string& str, int m) {
const int p = 31;
    unsigned long hash = 0;
    // p_pow 用於儲存 p 的當前冪次 (p^i)，迭代更新以避免昂貴的求冪運算。
    unsigned long p_pow = 1;
    // 遍歷字串中的每個字符
    for (char c : str) {
        hash = (hash + ((unsigned long)c * p_pow)) % m;
        p_pow = (p_pow * p) % m;
    }
    return static_cast<int>(hash);
}
```
```
B
int myHashString(const std::string& str, int m) {
    unsigned long hash = 5381;
    for (char c : str) {
        hash =(hash * 33 + c) % m; 
       
    }
    return static_cast<int>(hash );
}
```
```
C-1

int myHashString(const std::string& str, int m) {
    unsigned long hash = 5381;
     const int p = 13;
    unsigned long p_pow = 1;
    for (char c : str) {
        hash =((hash * 33 + c)* p_pow) % m; 
        p_pow = (p_pow * p) % m;
    }
    return static_cast<int>(hash );
}
```
```
C-2

int myHashString(const std::string& str, int m) {
    unsigned long hash = 5381;
     const int p = 31;
    unsigned long p_pow = 1;
    for (char c : str) {
        hash =((hash * 33 + c)* p_pow) % m; 
        p_pow = (p_pow * p) % m;
    }
    return static_cast<int>(hash );
}
```
```
A-1
=== String Hash (m = 10) ===
Key     Index
-----------------
cat     4
dog     0
bat     3
cow     3
ant     1
owl     0
bee     0
hen     7
pig     4
fox     5

=== String Hash (m = 11) ===
Key     Index
-----------------
cat     9
dog     8
bat     8
cow     5
ant     0
owl     0
bee     0
hen     9
pig     8
fox     1

=== String Hash (m = 37) ===
Key     Index
-----------------
cat     22
dog     6
bat     21
cow     8
ant     4
owl     4
bee     17
hen     27
pig     14
fox     32
```
```
A-2
=== String Hash (m = 10) ===
Key     Index
-----------------
cat     2
dog     4
bat     1
cow     9
ant     3
owl     8
bee     0
hen     5
pig     0
fox     3

=== String Hash (m = 11) ===
Key     Index
-----------------
cat     6
dog     4
bat     5
cow     1
ant     0
owl     8
bee     3
hen     1
pig     6
fox     8

=== String Hash (m = 37) ===
Key     Index
-----------------
cat     30
dog     34
bat     29
cow     17
ant     24
owl     29
bee     20
hen     17
pig     8
fox     19
```
```
B
=== String Hash (m = 10) ===
Key     Index
-----------------
cat     5
dog     3
bat     6
cow     0
ant     6
owl     1
bee     3
hen     6
pig     3
fox     8

=== String Hash (m = 11) ===
Key     Index
-----------------
cat     6
dog     4
bat     6
cow     9
ant     6
owl     9
bee     2
hen     0
pig     4
fox     10

=== String Hash (m = 37) ===
Key     Index
-----------------
cat     29
dog     13
bat     13
cow     13
ant     19
owl     14
bee     19
hen     13
pig     7
fox     25
```
```
C-1
=== String Hash (m = 10) ===
Key     Index
-----------------
cat     7
dog     7
bat     4
cow     8
ant     4
owl     3
bee     3
hen     2
pig     7
fox     6

=== String Hash (m = 11) ===
Key     Index
-----------------
cat     2
dog     5
bat     2
cow     3
ant     2
owl     3
bee     8
hen     0
pig     5
fox     7

=== String Hash (m = 37) ===
Key     Index
-----------------
cat     34
dog     15
bat     32
cow     16
ant     5
owl     27
bee     11
hen     27
pig     5
fox     6
```
```
C-2
=== String Hash (m = 10) ===
Key     Index
-----------------
cat     5
dog     3
bat     6
cow     0
ant     6
owl     1
bee     3
hen     6
pig     3
fox     8

=== String Hash (m = 11) ===
Key     Index
-----------------
cat     2
dog     5
bat     2
cow     3
ant     2
owl     3
bee     8
hen     0
pig     5
fox     7

=== String Hash (m = 37) ===
Key     Index
-----------------
cat     28
dog     23
bat     6
cow     22
ant     5
owl     31
bee     36
hen     11
pig     24
fox     13
```

- 原理：
- A:不同位置的字元權重不同大幅降低衝突,每個字元對 hash 的影響會被放大
- B:每加入一個字元，整個 hash 值都會被放大 33 倍。
- C:A+B




