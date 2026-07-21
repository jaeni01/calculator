# calculator

새 프로그래밍 언어를 배울 때마다 같은 사양의 사칙연산 CLI 계산기를 만들어 추가하는 저장소입니다.
같은 문제를 여러 언어로 풀어보면 문법이 아니라 **언어의 철학 차이**가 보입니다.

배운 순서: **Python → C → C++ → C# → Rust**

## 공통 사양

- `3 + 4` 형태로 입력 → `= 7` 출력 (반복 입력 루프)
- 지원 연산: `+` `-` `*` `/`
- `q` 입력 시 종료
- 오류 처리: 잘못된 입력 형식, 0으로 나누기, 지원하지 않는 연산자
- 숫자는 64비트 부동소수점(double / f64)으로 처리

## 구조 및 실행

| 폴더 | 언어 | 실행 |
|------|------|------|
| [`python/`](python) | Python | `python calculator.py` |
| [`c/`](c) | C | `cl /utf-8 calculator.c` 또는 `gcc calculator.c -o calculator` |
| [`cpp/`](cpp) | C++ | `cl /utf-8 /EHsc calculator.cpp` 또는 `g++ calculator.cpp -o calculator` |
| [`csharp/`](csharp) | C# | `dotnet run` |
| [`rust/`](rust) | Rust | `cargo run` |

```
계산기 (예: 3 + 4, 종료: q)
> 3 + 4
= 7
> 10 / 3
= 3.33333
> 5 / 0
0으로 나눌 수 없습니다
> q
```

## 언어 비교

각 언어에서 **무엇을 썼고 왜 썼는지**, 장단점, 공통점과 차이점 정리:
→ **[docs/comparison.md](docs/comparison.md)**

요약: 다섯 구현의 로직은 같지만 **"오류를 어떻게 다루게 강제하는가"**가 다르다 —
C는 개발자 재량, Python/C#은 런타임 보호, Rust는 컴파일 타임 강제.

## License

[MIT](LICENSE)
