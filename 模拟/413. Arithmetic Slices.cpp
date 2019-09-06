#include<iostream>

int main() {
    std::string str;
    std::cin >> str;
    int len = str.length();
    for (int i = 0; i <= len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            std::cout << "NOT!";
            return 0;
        }
    }

    std::cout << "YES!";
    return 0;
}