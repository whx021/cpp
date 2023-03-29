//7、string容器——查找和替换

/*
查找：查找指定字符串是否存在
替换：在指定的位置替换字符串

int find(const string& str, int pos = 0) const; //从pos开始查找，str第一次出现位置
int find(const char* s, int pos = 0) const;     //从pos开始查找，s第一次出现位置
int find(const char* s, int pos, int n) const;  //从pos开始查找，s前n个字符第一次出现位置
int find(const char c, int pos = 0) const;      //从pos开始查找，c第一次出现位置
int rfind(const string& str, int pos = npos) const; //从pos开始查找，str最后一次出现位置
int rfind(const char* s, int pos = npos) const; //从pos开始查找，s最后一次出现位置
int rfind(const char* s, int pos, int n) const; //从pos开始查找，s前n个字符最后一次出现位置
int rfind(const char c, int pos = 0) const;     //从pos开始查找，c最后一次出现位置

string& replace(int pos, int n, const string& str); //从pos开始的n个字符用str替换
string& replace(int pos, int n, const char* s);     //从pos开始的n个字符用s替换


总结：
find查找是从左往右，rfind从右往左
find找到字符串后返回查找的第一个字符位置，找不到返回-1
replace在替换时，要指定从哪个位置起，多少个字符，替换成什么样的字符串
*/