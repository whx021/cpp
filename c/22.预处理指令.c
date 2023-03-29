// 22.预处理指令
// 文件绝对路径 : __FILE__
// 行号 : __LINE__
// 日期 : __DATE__
// 时间 : __TIME__

#include <stdio.h>

void test_1(void) {
    printf("文件 : %s\n", __FILE__);
    printf("行号 : %d\n", __LINE__);
    printf("日期 : %s\n", __DATE__);
    printf("时间 : %s\n", __TIME__);
}

int main(void) {
    test_1();
    return 0;
}