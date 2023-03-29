//11、vector容器——预留空间

#include <iostream>
#include <vector>
using namespace std;

void test(void)
{
    vector<int> v;

    //vector重新开辟空间需要耗费时间（开辟、拷贝）
    //如果数据量较大，可以一开始利用reserve预留空间，减少vector开辟空间次数
    v.reserve(100000);

    int num = 0;
    int* p = NULL;

    for (int i = 0; i < 100000; ++i)
    {
        v.push_back(i);

        //计算vector开辟空间次数
        if (p != &v[0])
        {
            p = &v[0];
            ++num;
        }
    }

    cout << "vector开辟空间次数：" << num << endl;
}

int main(void)
{
    test();


    return EXIT_SUCCESS;
}