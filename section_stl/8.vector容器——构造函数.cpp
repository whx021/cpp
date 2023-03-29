//8、vector容器——构造函数

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test_1(void)
{
    //默认构造
    vector<int> v1;

    for (int i = 0; i < 10; ++i)
    {
        v1.push_back(i);
    }

    printVector(v1);

    //通过区间方式构造
    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);

    //n个elem的方式构造
    vector<int> v3(10, 100);
    printVector(v3);

    //拷贝构造
    vector<int> v4(v3);
    printVector(v4);
}

int main(void)
{
    test_1();


    return EXIT_SUCCESS;
}