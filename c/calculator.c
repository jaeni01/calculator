/* 사칙연산 계산기 (C)
 * 빌드: gcc calculator.c -o calculator
 * 사용: 3 + 4 형태로 입력, q 입력 시 종료
 */
#include <stdio.h>
#include <string.h>

int main(void) {
    char line[256];

    printf("계산기 (예: 3 + 4, 종료: q)\n");

    while (1) {
        printf("> ");
        if (fgets(line, sizeof(line), stdin) == NULL)
            break;

        if (line[0] == 'q' || line[0] == 'Q')
            break;

        double a, b;
        char op;
        if (sscanf(line, "%lf %c %lf", &a, &op, &b) != 3) {
            printf("입력 형식 오류 (예: 3 + 4)\n");
            continue;
        }

        switch (op) {
        case '+': printf("= %g\n", a + b); break;
        case '-': printf("= %g\n", a - b); break;
        case '*': printf("= %g\n", a * b); break;
        case '/':
            if (b == 0)
                printf("0으로 나눌 수 없습니다\n");
            else
                printf("= %g\n", a / b);
            break;
        default:
            printf("지원하지 않는 연산자: %c\n", op);
        }
    }
    return 0;
}
