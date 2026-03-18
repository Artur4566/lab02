#include <iostream>
#include <string>

int main()
{
    std::string username;
    std::cout << "Введите ваше имя: ";
    std::cin >> username;
    std::cout << "Привет, " << username << "!" << std::endl;
    return 0;
}
