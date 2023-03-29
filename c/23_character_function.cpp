/*
 * 1.编写一个函数，计算数组中的最大元素及其下标，数组以指针方式传递。 
 * 2.编写一个程序，在一个已排序列的字符串数组中，插入输入的一个字符串，使该数组的元素仍然有序。
 * 3.编写一个程序，输入若干个字符串，采用冒泡排序法对这些字符串按词典顺序进行排序并输出。 
 * 4.分别编写下列字符串处理函数
 *（1）char *strcat1(char *s,const char *ct);  
 * 将串ct接到串s的后面，形成一个长串。 
 *（2）int strlen1(const char * s);
 * 求字符串长度的函数，返回串长（不包括串结束符）。
 *（3）char * reverse (char *);
 * 反置字符串s，即可将“break”成为“kaerb”。
 *（4）char * strchr( const char *cs,char c);   
 * 查找字符c在串cs中第一次出现的位置，返回指向该字符的指针，若没有出现则返回NULL。
 *（5）char *strstr (const char *cs1,const char *cs2);
 * 返回串cs2作为子串在cs1中第一次出现的位置，若没有出现则返回NULL。
 */

#include <iostream>
#include <cstring>

// question 1
void findMaximum(const int* arr, const int& length, int& maximum, int& maxIndex) {
    for (int i = 0; i < length; ++i) {
        if (maximum < arr[i]) {
            maximum = arr[i];
            maxIndex = i;
        }
    }
}

// question 2
void insertElem(char* str, int& length, const int& index, const char& ch) {
    if (index < 0 || index > length) {
        cerr << "error : insert failure" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < length - index; ++i) {
        str[length - i] = str[length - i - 1]; 
    }
    str[index] = ch;
    ++length;
}

// question 3
#define MAXSIZE 100
typedef struct {
    char str[MAXSIZE];
    int length;
} Word;

int compare(const Word& word_1, const Word& word_2) {
    for (int i = 0; i < word_1.length && i < word_2.length; ++i) {
        if (word_1.str[i] != word_2.str[i]) {
            return word_1.str[i] - word_2.str[i];
        }
    }
    return word_1.length - word_2.length;
}

void printWord(Word word) {
    int i = 0;
    while (word.str[i] != '\0') {
        cout << word.str[i];
        ++i;
    }
    cout << endl;
} 

void sortString(void) {
    int num;
    cin >> num;
    Word words[num];
    for (int i = 0; i < num; ++i) {
        cin >> words[i].str;
        words[i].length = sizeof(words[i]) / sizeof(char) - 1;  
    }
    Word temp;
    for (int i = 0; i < num - 1; ++i) {
        bool flag = false;
        for (int j = 0; j < num - 1 - i; ++j) {
            if (compare(words[j], words[j + 1]) > 0) {
                temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
                flag = true;
            }
        } 
        if (flag == false) {
            break;
        }
    }
    for (int i = 0; i < num; ++i) {
        printWord(words[i]);
    }
}

// question 4 (1)
char *strcat1(char *s,const char *ct) {
    int i = 0;
    while (s[i] != '\0') {
        ++i;
    }
    int j = 0;
    while (ct[i + j] != '\0') {
        s[i + j] = ct[j];
        ++j;
    }
    s[i + j] = '\0';
    return s;
}

// question 4 (2)
int strlen1(const char * s) {
    int i = 0;
    while (s[i] != '\0') {
        ++i;
    }
    return i;
}

// question 4 (3)
char * reverse (char *s) {
    int len = strlen1(s);
    char temp;
    for (int i = 0, j = len - 1; i < j; ++i, --j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    return s;
}

// question 4 (4)
char * strchr( const char *cs,char c) {
    int i = 0;
    while (cs[i] != '\0') {
        if (cs[i] == c) {
            const char* p = &cs[i];
            return (char*)p;
        }
    }
    return nullptr;
}

// question 4 (5)
char *strstr (const char *cs1,const char *cs2) {
    int len_cs_2 = strlen1(cs2);
    int i = 0; 
    int j = 0;
    while (cs1[i] != '\0' && cs2[j] != '\0') {
        if (cs1[i] == cs2[j]) {
            ++i;
            ++j;
        }
        else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j == '\0') {
        const char* p = &cs1[i - len_cs_2];
        return (char*)p;
    }
    else {
        return nullptr;
    }
}