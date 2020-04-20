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
    using namespace std::string_literals;

    for (const auto& s : {"AA-44 BB 55CD 83FG"s, "00-44 48 5555 8361"s, "0   -   22 1985--324"s, "12"s, "123"s, "1234"s, "12345"s}) {
        std::cout << "in: " << s << " to: " << FormatString(s) << "\n";
    }
    return 0;
}
