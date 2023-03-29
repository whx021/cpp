//3、vector容器嵌套容器

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void test(void)
{
    vector<vector<int>> v;

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    for (int i = 0; i < 4; ++i)
    {
        v1.push_back(i + 1);
        v1.push_back(i + 2);
        v1.push_back(i + 3);
        v1.push_back(i + 4);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); ++it)
    {
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); ++vit)
        {
            cout << *vit << "\t";
        }
        cout << endl; 
    }
}

int main(void)
{
    test();


    return EXIT_SUCCESS;
}