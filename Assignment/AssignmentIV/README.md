## 環境說明 (Execution Environment)
- 作業系統環境 (Operating System): Windows
- 編譯器/工具 (Compiler/Tools):OnlineGDB
## Hash Function 設計概念及其虛擬碼 (Integer + String)
1. Integer Key 的 Hash Function 設計
除法取餘法 (Division Method):h(k) = k (mod m)
2. String Key 的 Hash Function 設計
- A: 將一個長度不固定的字串 (string) 轉換為一個長度固定的整數 (integer) 索引
 #### int myHashString(const std::string& str, int m) {
  #### const int p = 13;
  ####  unsigned long hash = 0;
  ####  // p_pow 用於儲存 p 的當前冪次 (p^i)，迭代更新以避免昂貴的求冪運算。
  ####  unsigned long p_pow = 1;
  ####  // 遍歷字串中的每個字符
  ####  for (char c : str) {
   #### hash = (hash + ((unsigned long)c * p_pow)) % m;
 ####       p_pow = (p_pow * p) % m;
   #### }
   #### return static_cast<int>(hash);
#### }
- B:Rabin-Karp 捲動雜湊（Rolling Hash） 或多項式雜湊（Polynomial Hash） 設計，並使用模數 m 進行壓縮
#### int myHashString(const std::string& str, int m) {
  ####  unsigned long hash = 5381;
   #### for (char c : str) {
   ####     hash =(hash * 33 + c) % m; 
 ####   }
   #### return static_cast<int>(hash );
#### }
- C-1 Simple Additive Hash
#### int myHashString(const std::string& str, int m) {
 ####   unsigned long hash = 0;
   ####  for (char c : str) {
   ####   hash += c;}
  ####   
  ####  return hash % m;
 ####   }
- C-2  
## Results: 觀察key與index間的關係，觀察index與table size (m)間的關係
 #### 整數Hash皆沒有改 
#### m = 10:10 組碰撞,分佈高度重複
 #### m = 11:8 組碰撞
#### m = 37:3 組碰撞,大於鍵值之間的差距,使得哈希值分佈更為均勻
#### 結論（整數）：表格越大（特別是與鍵數不接近的質數），碰撞越少
#### 字串Hash
#### m=10  A1:4  A2:4 B:4 C1:4 C2:4
#### m=11  A1:5  A2:4 B:4 C1:4 C2:4
#### m=37  A1:1  A2:2 B:2 C1:2 C2:0
#### 字串鍵：在小表格（m=10、m=11）各組碰撞數相差不大；在較大的 m（37）差異放大：C2 的字串雜湊在 m=37 效果最好（0 碰撞），A1 在 m=11 表現最差（5 次碰撞）。
## 參考
- https://yuihuang.com/hash/
- https://ithelp.ithome.com.tw/m/articles/10326781
- https://www.hello-algo.com/zh-hant/chapter_hashing/hash_algorithm/#634
- https://medium.com/@fchern/%E8%A8%AD%E8%A8%88%E9%AB%98%E6%95%88%E8%83%BD%E7%9A%84hash-table-%E4%B8%80-303d9713abab
- https://gist.github.com/MohamedTaha98/ccdf734f13299efb73ff0b12f7ce429f
