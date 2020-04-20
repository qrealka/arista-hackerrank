#include <algorithm>
#include <iostream>
#include <string>

std::string FormatString(std::string S) {
    S.erase(std::remove_if(S.begin(), S.end(), [](auto c){
        return isspace(c) || c == '-';
    }), S.end());

    auto tailSize = S.size() % 3;
    int i = 0;
    for (auto it = S.begin(); it != S.end();)
    {
        if (i && ((i % 3) == 0)) {
            i = -1;
            it = S.insert(it, ' ');
        } else {
            ++i;
            ++it;
        }
    }
    if (tailSize == 1) {
        auto it = S.rbegin() + tailSize;
        if (*it == ' ') {
            std::swap(*next(it), *it);
        }
    }
    return std::move(S);
}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
