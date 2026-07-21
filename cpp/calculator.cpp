// 사칙연산 계산기 (C++)
// 사용: 3 + 4 형태로 입력, q 입력 시 종료
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::cout << "계산기 (예: 3 + 4, 종료: q)\n";

    std::string line;
    while (true) {
        std::cout << "> ";
        if (!std::getline(std::cin, line))
            break;

        if (line == "q" || line == "Q")
            break;

        std::istringstream iss(line);
        double a, b;
        char op;
        if (!(iss >> a >> op >> b)) {
            std::cout << "입력 형식 오류 (예: 3 + 4)\n";
            continue;
        }

        switch (op) {
        case '+': std::cout << "= " << a + b << "\n"; break;
        case '-': std::cout << "= " << a - b << "\n"; break;
        case '*': std::cout << "= " << a * b << "\n"; break;
        case '/':
            if (b == 0)
                std::cout << "0으로 나눌 수 없습니다\n";
            else
                std::cout << "= " << a / b << "\n";
            break;
        default:
            std::cout << "지원하지 않는 연산자: " << op << "\n";
        }
    }
    return 0;
}
