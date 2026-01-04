## 圖（Graph）
### 基本名詞
- Vertex（頂點）：圖中的節點
- Edge（邊）：節點之間的連線
- Degree（度數）：與頂點相連的邊數
- Path（路徑）：由邊連接的頂點序列
- Cycle（環）：起點與終點相同的路徑
- Connected Graph：任兩頂點皆有路徑
- Disconnected Graph：存在無法連通的頂點
### 三、Graph 的種類
#### 1.無向圖（Undirected Graph）:邊沒有方向
#### 2.有向圖（Directed Graph）:邊有方向
#### 3.無權重圖 (Unweighted Graph)：邊沒有權重（距離、成本） 
#### 4.加權圖（Weighted Graph）:邊具有權重（距離、成本） 
### 四、表示法
#### 1.Adjacency Matrix（鄰接矩陣）
- 空間複雜度：O(V²)
- 查詢邊是否存在：O(1)
#### 2.Adjacency List（鄰接串列）
- 空間複雜度：O(V + E)
### 五、走訪
#### BFS（Breadth-First Search）
- 由近到遠層層擴展
- 常用於：最短路徑（無權重）
#### DFS（Depth-First Search）
- 一路走到底再回溯
- 常用於：Cycle 偵測、拓樸排序
### 六、BFS vs DFS 比較
```
項目	          BFS	                DFS
使用結構	         Queue	                Stack
走訪方式	         由近到遠	            由深到淺
常見應用     	 最短路徑	         Cycle、拓樸排序
```
### 七、時間複雜度（Traversal）
- BFS：O(V + E)
- DFS：O(V + E)















