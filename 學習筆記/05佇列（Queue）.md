## 佇列（Queue）
### 一、定義
#### 佇列（Queue）是一種線性資料結構，遵循 FIFO（First In, First Out，先進先出）
### 二、基本概念
- Rear（尾端）：新增元素的位置
- Front（前端）：刪除元素的位置
#### 主要操作：
- Enqueue：加入元素
- Dequeue：移除元素
- Front / Peek：查看最前端元素
### 三、特性
- 只能從前端(Front) 刪除、尾端(Rear)新增
- 無法隨機存取
### 四、優缺點
#### 優點
- Enqueue / Dequeue 時間複雜度為 O(1)
#### 缺點
- 不適合搜尋資料
### 五、時間複雜度
```
操作	時間複雜度
Enqueue	O(1)
Dequeue	O(1)
Peek	O(1)
Search	O(n)
```







