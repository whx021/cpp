// variadic templates 数量不定的模板参数

void print(void) {

}

// variadic templates 数量不定的模板参数
// 将模板参数分为一个或一包(pack)(模板参数包)
template<typename T, typename... Types>
void print (const T& firstArgument, const Types&... arguments) {
    cout << firstArgument << endl;
    print(arguments);   // recursion
    
    // in variadic templates, yield the number of arguments
    // 计算模板参数包中的参数数量 
    sizeof...(arguments); 
}