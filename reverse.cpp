#include <iostream>
void reverse(char *str)
{
    char *end = str;
    while (*end)
    {
        ++end;
    }
    --end;
    while (str < end)
    {
        char temp = *str;
        *str = *end;
        *end = temp;
        ++str;
        --end;
    }
}

int main()
{
    const int MAX = 100;
    char str[MAX] = {0};
    std::cout << "请输入一个字符串" << std::endl;
    std::cin.getline(str, MAX);
    reverse(str);
    std::cout << "输出相反字符串为：" << str << std::endl;
    return 0;
}