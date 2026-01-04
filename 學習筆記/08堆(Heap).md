## 堆（Heap）
### 一、定義
#### 堆（Heap）是一種完全二元樹（Complete Binary Tree），並且滿足堆積性質（Heap Property）的資料結構
### 二、種類
#### min Heap（最小堆）
- 每個節點的值 ≤ 子節點的值
- 根節點為最小值
#### Max Heap（最大堆）
- 每個節點的值 ≥ 子節點的值
- 根節點為最大值
### 三、特性
- 結構：完全二元樹
- 只保證「父子關係」，不保證整體排序
- 常以 Array 實作
### 四、Array 表示法（Index 關係）
#### 若索引從 0 開始：
- Parent(i) = (i − 1) / 2
- Left Child(i) = 2i + 1
- Right Child(i) = 2i + 2
### 五、時間複雜度
```
操作	            說明	                    時間複雜度
Insert	         上濾（Heapify Up）	             O(log n)
Delete Root	     下濾（Heapify Down）	         O(log n)
Find Min / Max	 看根節點	                     O(1)
Build Heap	     自底向上建堆	                 O(n)
```
### 六、Heap vs BST
```
項目	            Heap	            BST
結構	          完全二元樹	         二元搜尋樹
根節點	         最小 / 最大值	       中間值
搜尋任意值       	O(n)	          O(log n)
取最值	            O(1)	          O(log n)
```






