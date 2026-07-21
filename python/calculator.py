# 사칙연산 계산기 (Python)
# 실행: python calculator.py
# 사용: 3 + 4 형태로 입력, q 입력 시 종료

def main():
    print("계산기 (예: 3 + 4, 종료: q)")

    while True:
        try:
            line = input("> ")
        except EOFError:
            break

        if line.strip().lower() == "q":
            break

        parts = line.split()
        if len(parts) != 3:
            print("입력 형식 오류 (예: 3 + 4)")
            continue

        try:
            a, op, b = float(parts[0]), parts[1], float(parts[2])
        except ValueError:
            print("입력 형식 오류 (예: 3 + 4)")
            continue

        if op == "+":
            print(f"= {a + b:g}")
        elif op == "-":
            print(f"= {a - b:g}")
        elif op == "*":
            print(f"= {a * b:g}")
        elif op == "/":
            if b == 0:
                print("0으로 나눌 수 없습니다")
            else:
                print(f"= {a / b:g}")
        else:
            print(f"지원하지 않는 연산자: {op}")


if __name__ == "__main__":
    main()
