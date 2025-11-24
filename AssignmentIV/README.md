## a. 環境說明 (Execution Environment)
- 作業系統環境 (Operating System): Windows
- 編譯器/工具 (Compiler/Tools):OnlineGDB
## b. Hash Function 設計概念及其虛擬碼 (Integer + String)
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
- B: Rabin-Karp 捲動雜湊（Rolling Hash） 或多項式雜湊（Polynomial Hash） 設計，並使用模數 m 進行壓縮
#### int myHashString(const std::string& str, int m) {
  ####  unsigned long hash = 5381;
   #### for (char c : str) {
   ####     hash =(hash * 33 + c) % m; 
 ####   }
   #### return static_cast<int>(hash );
#### }
- C: A加B看會發生什麼事
  
#### int myHashString(const std::string& str, int m) {
 ####   unsigned long hash = 5381;
   ####  const int p = 13;
   #### unsigned long p_pow = 1;
  ####  for (char c : str) {
  ####      hash =((hash * 33 + c)* p_pow) % m; 
   ####     p_pow = (p_pow * p) % m;
 ####   }
####    return static_cast<int>(hash );
#### }
## c.Results: 觀察key與index間的關係，觀察index與table size (m)間的關係

d.Compilation, build, execution and output
Windows: 於Makefile.bat所在目錄直接執行 Makefile.bat; Makefile.bat all; Makefile.bat c; Makefile.bat cxx; Makefile.bat clean, 藉此去觀察產生出來的檔案

Output: 這部分必須要有截圖的部分，只要是證明確實程式是可以執行的。
output, 這邊指的就是index value，因此基於key, table size (m)與index value間的關係進行觀察與分析 
Analysis
基於README.md template作為指引去發展你的討論軸線，這部分得靠同學們去發揮。如果只有課堂上的範例，參考的數據有限，會局限這部分的討論。建議可以找2種以上的方法會比較有幫助。

另外，不管是透過Google或是Copilot所查找到的設計靈感，請將參考資料或是網路連結給附上，以避免抄襲的可能。
請同學們務必多花點心思了解撰寫這部分，第一次或許會難一點，做過一次後面就會比較理解你會了什麼。

Reflation

透過所列出的3項作為指引，盡可能去發揮思考hash function的設計特性該如何去拿捏，例如是什麼樣的設計有機會讓collison的次數減少，及其原因。

請同學們務必多花點心思了解撰寫這部分，第一次或許會難一點，做過一次後面就會比較理解你會了什麼
