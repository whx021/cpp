// ifdef条件编译：
// 如果存在C++的编译器在编译这段代码，就会有宏"__cplusplus"
// 则大括号之间的代码使用C的方式去链接
// __cplusplus 

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

void show(void);

#ifdef __cplusplus
}
#endif