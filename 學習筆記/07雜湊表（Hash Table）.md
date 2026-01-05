/## 雜湊表（Hash Table）
### 一、定義
#### 雜湊表（Hash Table）是一種非線性資料結構，透過 雜湊函數（Hash Function），將鍵（Key）對應到表格中的索引位置
### 二、基本組成
#### 1.Key：搜尋依據
#### Value：實際儲存的資料
#### Hash Function：將 Key 轉成索引值
#### Table（陣列）：儲存資料的空間
### 三、Hash Function（雜湊函數）
#### 特性
- 計算速度快
- 將 Key 均勻分布到 table 中
- 相同 Key 一定產生相同 Hash 值
#### 常見雜湊方法
- Division Method：h(k) = k mod m
- Multiplication Method
- 字串雜湊（Polynomial Hash、FNV Hash）
### 四、Collision（碰撞）問題
#### 當不同 Key 對應到同一個索引時，稱為碰撞。
#### 碰撞解決方法
#### 1.Chaining（鏈結法）:每個 index 存一條 Linked List
#### 2.Open Addressing（開放定址法）
##### Linear Probing:當兩個鍵衝突，它會依序檢查下一個相鄰的槽位，直到找到空位來存放數據
### 五、時間複雜度（平均 vs 最壞）
```
操作	平均	最壞
Search	O(1)	O(n)
Insert	O(1)	O(n)
Delete	O(1)	O(n)
```
### 六、Hash Table vs BST
```
項目	Hash Table    BST
搜尋速度  O(1)平均	  O(log n)
是否排序    否	      是
資料順序    無	      有
最壞情況  O(n)      O(n)
```



