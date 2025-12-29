# 作業四：雜湊函數設計與觀察（C/C++ 版本）
本次作業重點在於使用 C/C++ 設計和觀察雜湊函數。

開發者：[張景翔]

信箱：[ben950810@gmail.com]
## 我的哈希函數
### 整數鍵
- 公式/偽代碼：
 ### a-1
```
=== Table Size m = 10 ===
Key     Index
-----------------
21      4
22      7
23      0
24      3
25      6
26      9
27      2
28      5
29      8
30      1
51      4
52      7
53      0
54      3
55      6
56      9
57      2
58      5
59      8
60      1
```
```
=== Table Size m = 11 ===
Key     Index
-----------------
21      9
22      0
23      2
24      4
25      6
26      8
27      10
28      1
29      3
30      5
51      3
52      5
53      7
54      9
55      0
56      2
57      4
58      6
59      8
60      10
```
```
=== Table Size m = 37 ===
Key     Index
-----------------
21      25
22      1
23      14
24      27
25      3
26      16
27      29
28      5
29      18
30      31
51      8
52      21
53      34
54      10
55      23
56      36
57      12
58      25
59      1
60      14
```
 ### a-2

```
=== Table Size m = 10 ===
Key     Index
-----------------
21      6
22      9
23      2
24      5
25      8
26      1
27      4
28      7
29      0
30      3
51      6
52      9
53      2
54      5
55      8
56      1
57      4
58      7
59      0
60      3
```
```
=== Table Size m = 11 ===
Key     Index
-----------------
21      0
22      2
23      4
24      6
25      8
26      10
27      1
28      3
29      5
30      7
51      5
52      7
53      9
54      0
55      2
56      4
57      6
58      8
59      10
60      1
```
```
=== Table Size m = 37 ===
Key     Index
-----------------
21      27
22      3
23      16
24      29
25      5
26      18
27      31
28      7
29      20
30      33
51      10
52      23
53      36
54      12
55      25
56      1
57      14
58      27
59      3
60      16
```
 ### b
```
=== Table Size m = 10 ===
Key     Index
-----------------
21      0
22      7
23      4
24      1
25      8
26      5
27      2
28      9
29      6
30      3
51      0
52      7
53      4
54      1
55      8
56      5
57      2
58      9
59      6
60      3
```
```
=== Table Size m = 11 ===
Key     Index
-----------------
21      7
22      2
23      8
24      3
25      9
26      4
27      10
28      5
29      0
30      6
51      0
52      6
53      1
54      7
55      2
56      8
57      3
58      9
59      4
60      10
```
```
=== Table Size m = 37 ===
Key     Index
-----------------
21      0
22      17
23      34
24      14
25      31
26      11
27      28
28      8
29      25
30      5
51      29
52      9
53      26
54      6
55      23
56      3
57      20
58      0
59      17
60      34
```
 ### c-1
```
=== Table Size m = 10 ===
Key     Index
-----------------
21      0
22      9
23      8
24      7
25      6
26      5
27      4
28      3
29      2
30      1
51      0
52      9
53      8
54      7
55      6
56      5
57      4
58      3
59      2
60      1
```
```
=== Table Size m = 11 ===
Key     Index
-----------------
21      3
22      0
23      8
24      5
25      2
26      10
27      7
28      4
29      1
30      9
51      1
52      9
53      6
54      3
55      0
56      8
57      5
58      2
59      10
60      7
```
```
=== Table Size m = 37 ===
Key     Index
-----------------
21      3
22      22
23      4
24      23
25      5
26      24
27      6
28      25
29      7
30      26
51      18
52      0
53      19
54      1
55      20
56      2
57      21
58      3
59      22
60      4
```
 ### c-2
```
=== Table Size m = 10 ===
Key     Index
-----------------
21      2
22      1
23      0
24      9
25      8
26      7
27      6
28      5
29      4
30      3
51      2
52      1
53      0
54      9
55      8
56      7
57      6
58      5
59      4
60      3
```
```
=== Table Size m = 11 ===
Key     Index
-----------------
21      5
22      2
23      10
24      7
25      4
26      1
27      9
28      6
29      3
30      0
51      3
52      0
53      8
54      5
55      2
56      10
57      7
58      4
59      1
60      9
```
```
=== Table Size m = 37 ===
Key     Index
-----------------
21      5
22      24
23      6
24      25
25      7
26      26
27      8
28      27
29      9
30      28
51      20
52      2
53      21
54      3
55      22
56      4
57      23
58      5
59      24
60      6
```

原理：將一個 key轉換運算到雜湊表

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




