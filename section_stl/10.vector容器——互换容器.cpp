// 10、vector容器——互换容器

#include <iostream>
#include <vector>
using namespace std;

//利用swap()收缩内存
void test(void)
{
    vector<int> v;
    for (int i = 0; i < 10000; ++i)
    {
        v.push_back(i);
    }

    cout << "capacity: " << v.capacity() << endl;
    cout << "size: " << v.size() << endl;

    v.resize(3);

    cout << "capacity: " << v.capacity() << endl;
    cout << "size: " << v.size() << endl;

    //收缩内存
    //vector<int>(v)    //匿名对象：当前行执行结束，系统自动回收匿名对象的内存空间
    vector<int>(v).swap(v);

    cout << "capacity: " << v.capacity() << endl;
    cout << "size: " << v.size() << endl;
}

int main(void)
{
    test();

    return EXIT_SUCCESS;
}