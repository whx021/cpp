# STL

## STL诞生
+ C++==面向对象==和==范性编程==思想目的：复用性提升
+ 建立数据结构和算法标准：==STL==

## STL基本概念
+ STL(Standard Template Library)，标准模板库
+ STL广义分为：==容器(container)==、==算法(algorithm)==、==迭代器(iterator)==
+ 容器和算法之间通过迭代器进行无缝链接
+ STL几乎所有技术都采用==类模板==和==函数模板==

## STL六大组件
==容器==、==算法==、==迭代器==、==仿函数==、==适配器==、==空间配置器==

1. ==容器==：各种数据结构（vector list deque set map等）
2. ==算法==：各种常用的算法（sort find copy for_each等）
3. ==迭代器==：容器和算法之间通过迭代器进行无缝链接
4. ==仿函数==：行为类似函数，可以作为算法的某种策略
5. ==适配器==：一种用来修饰||仿函数||迭代器接口的东西
6. ==空间适配器==：负责空间的配置与管理
## STL中的容器、算法、迭代器
### 容器
实现：数组、链表、树、栈、队列、集合、映射的数据结构
#### 序列式容器
每个元素有固定位置
#### 关联式容器
每个元素没有固定顺序关系

### 算法(algorithms)
实现：
#### 质变算法
运算过程中会更该区间内元素的内容
#### 非质变算法
运算过程中不会更该区间内元素的内容

### 迭代器
提供一种方法，使之能够依序寻访某个容器中的所含的各个元素，而又无需暴露该容器的内部表示方式
每个容器都有自己专属的迭代器
#### 迭代器种类
|种类|功能|支持运算|
|:---:|:---:|:---:|
|输入迭代器|对数据的只读访问|只读，支持++、==、！=|
|输出迭代器|对数据的只写访问|只写，支持++|
|前向迭代器|对写操作，并能向前推进迭代器|读写，支持++、==、！=|
|双向迭代器|读写操作，并能向前向后操作|读写，支持++、--|
随机访问迭代器|读写操作，可以一跳跃式方式访问任何数据|读写，支持++、--、[n]、-n、<、<=、>、>=
常用容器中的迭代器为==双向迭代器==、==随机访问迭代器==