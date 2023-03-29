#include "55.附加1mystring.h"

// 重载"<<"左移运算符，实现自定义字符串的输出
ostream& operator<<(ostream& cout, MyString& myString) {
	cout << myString.pString;
	return cout;
}

// 重载">>"右移运算符，实现自定义字符串的输入
istream& operator>>(istream& cin, MyString& myString) {
	//先判断原堆区是否数据，如果有先清空
	if (myString.pString != NULL) {
		delete[] myString.pString;
		myString.pString = NULL;
	}

	char buffer[1024] = { 0 };
	cin >> buffer;
	
	myString.pString = new char[strlen(buffer) + 1];
	strcpy(myString.pString, buffer);
	myString.member_length = strlen(buffer);

	return cin;
}

// 重载"="赋值运算符，使用深拷贝防止浅拷贝的问题
MyString& MyString::operator=(const char* str) {
	if (this->pString != NULL) {
		delete[] this->pString;
		this->pString = NULL;
	}

	this->pString = new char[strlen(str) + 1];
	strcpy(this->pString, str);
	this->member_length = strlen(str);

	return *this;
}

// 重载"="赋值运算符，使用深拷贝防止浅拷贝的问题
MyString& MyString::operator=(const MyString& myString) {
	if (this->pString != NULL) {
		delete[] this->pString;
		this->pString = NULL;
	}

	// this->pString = new char[myString.member_length + 1];		//与下句效果相同
	this->pString = new char[strlen(myString.pString) + 1];
	strcpy(this->pString, myString.pString);
	this->member_length = strlen(myString.pString);
	// this->member_length = myString.member_length;		//与上句效果相同

	return *this;
}

// 重载"[]"，访问单个元素
char& MyString::operator[](int index) {
	return this->pString[index];
}

// 存在问题
// 重载'+'运算符，实现字符串拼接
MyString MyString::operator+(const char* str) {
	int newSize = this->member_length + strlen(str) + 1;
	char* temp = new char[newSize];

	memset(temp, 0, newSize);
	strcat(temp, this->pString);
	strcat(temp, str);

	// 调用有参构造
	MyString newString(temp);
	delete[] temp;
	return newString;
}

// 重载'+'运算符，实现字符串拼接
MyString MyString::operator+(const MyString& myString) {
	int newSize = this->member_length + strlen(myString.pString) + 1;
	char* temp = new char[newSize];

	memset(temp, 0, newSize);
	strcat(temp, this->pString);
	strcat(temp, myString.pString);

	// 调用有参构造
	MyString newString(temp);
	delete[] temp;
	return newString;
}


// 重载"=="比较运算符，进行字符串的比较
bool MyString::operator==(const char* str) {
	if ((strcmp(this->pString, str)) == 0) {
		return true;
	}
	else {
		return false;
	}
}

// 重载"=="比较运算符，进行字符串的比较
bool MyString::operator==(const MyString& myString) {
	if ((strcmp(this->pString, myString.pString)) == 0) {
		return true;
	}
	else {
		return false;
	}
}

// 有参构造（深拷贝）
MyString::MyString(const char* str) {
	// cout << "MyString有参构造函数调用" << endl;

	// +1保存'\0'字符串结束符，ASCII码中	(int)'\0' == 0;		(char)0 == '\0'
	this->pString = new char[strlen(str) + 1];
	strcpy(this->pString, str);
	this->member_length = strlen(str);
}

// 拷贝构造（深拷贝）
MyString::MyString(const MyString& str) {
	// cout << "MyString有参拷贝构造函数调用" << endl;

	// this->pString = new char[str.member_length + 1];	// 与下句效果相同
	this->pString = new char[strlen(str.pString) + 1];
	strcpy(this->pString, str.pString);
	this->member_length = strlen(str.pString);
	// this->member_length = str.member_length;	// 与上句效果相同
}

// 析构
MyString::~MyString() {
	// cout << "MyString析构函数调用" << endl;

	if (this->pString != NULL) {
		delete[] this->pString;
		this->pString = NULL;
	}
}