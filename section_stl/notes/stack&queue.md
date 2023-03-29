# stack容器
## 构造函数
```cpp
stack<T> stk;
stack(const stack& stk);
```
## 赋值操作
```cpp
stack& operator = (const stack& stk);
```
## 数据存取
```cpp
push(elem);
pop();
top();
```
## 大小操作	
```cpp
empty();
size();
```
# queue容器
## 构造函数
```cpp
queue<T> que;
queue<const queue& que>;
```
## 赋值操作
```cpp
queue& operator = (const queue& stk);
```
## 数据存取
```cpp
push(elem);
pop();
front();
back();
```
## 大小操作
```cpp
empty();
size();
```