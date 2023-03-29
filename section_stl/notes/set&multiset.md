# set/multiset容器
#### 简介：
所有元素都会在插入时被自动排序。

#### 本质：
set/multiset属于==关联式容器==，底层结构是用二叉树实现。

#### set和multiset区别：
+ set不允许容器中有重复的元素。
+ multiset允许容器中有重复的元素。
+ set不可以插入重复数据，而multiset可以
+ set插入数据的同时会返回插入结果，表示插入是否成功
+ multiset不会检测数据，因此可以插入重复数据

## set容器——构建和赋值
```cpp
//构建
set<T> st;
set(const set& st);

//赋值
set& operator = (const set& st);
```
## set容器——大小和交换
```cpp
size();
empty();
swap(st);
```
## set容器——插入和删除
```cpp
insert(elem);
clear();
erase(pos);        //删除pos迭代器所指的元素，返回下一个元素迭代器
erase(beg, end);   //删除区间[ beg, end )的所有元素，返回下一个元素迭代器
erase(elem);    
```
## set容器——查找和统计
对set容器进行查找数据以及统计数据
```cpp
find(key);    //返回迭代器
count(key);   //返回（对于set容器，返回0或1）
```
