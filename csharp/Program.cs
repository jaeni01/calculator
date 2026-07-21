// 사칙연산 계산기 (C#)
// 실행: dotnet run
// 사용: 3 + 4 형태로 입력, q 입력 시 종료

Console.WriteLine("계산기 (예: 3 + 4, 종료: q)");

while (true)
{
    Console.Write("> ");
    string? line = Console.ReadLine();
    if (line is null || line.Trim().ToLower() == "q")
        break;

    string[] parts = line.Split(' ', StringSplitOptions.RemoveEmptyEntries);
    if (parts.Length != 3
        || !double.TryParse(parts[0], out double a)
        || !double.TryParse(parts[2], out double b))
    {
        Console.WriteLine("입력 형식 오류 (예: 3 + 4)");
        continue;
    }

    switch (parts[1])
    {
        case "+": Console.WriteLine($"= {a + b}"); break;
        case "-": Console.WriteLine($"= {a - b}"); break;
        case "*": Console.WriteLine($"= {a * b}"); break;
        case "/":
            if (b == 0)
                Console.WriteLine("0으로 나눌 수 없습니다");
            else
                Console.WriteLine($"= {a / b}");
            break;
        default:
            Console.WriteLine($"지원하지 않는 연산자: {parts[1]}");
            break;
    }
}
