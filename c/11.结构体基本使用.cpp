// 74.结构体基本使用

typedef struct Person {
    char name[64];
    int age;
} myPerson;  // myPerson 为结构体数据类型

struct Person2 {
    char name[64];
    int age;
} myPerson2; // myPerson2 为结构体变量

// 匿名结构体
struct {
    char name[64];
    int age;
} myPerson3; // myPerson2 为结构体变量, 且该结构体的数据类型仅能定义一个变量