// 사칙연산 계산기 (Rust)
// 실행: cargo run   (또는 rustc src/main.rs -o calculator)
// 사용: 3 + 4 형태로 입력, q 입력 시 종료
use std::io::{self, BufRead, Write};

fn main() {
    println!("계산기 (예: 3 + 4, 종료: q)");

    let stdin = io::stdin();
    loop {
        print!("> ");
        io::stdout().flush().unwrap();

        let mut line = String::new();
        if stdin.lock().read_line(&mut line).unwrap_or(0) == 0 {
            break; // EOF
        }

        let line = line.trim();
        if line.eq_ignore_ascii_case("q") {
            break;
        }

        let parts: Vec<&str> = line.split_whitespace().collect();
        if parts.len() != 3 {
            println!("입력 형식 오류 (예: 3 + 4)");
            continue;
        }

        let (a, op, b) = match (parts[0].parse::<f64>(), parts[1], parts[2].parse::<f64>()) {
            (Ok(a), op, Ok(b)) => (a, op, b),
            _ => {
                println!("입력 형식 오류 (예: 3 + 4)");
                continue;
            }
        };

        match op {
            "+" => println!("= {}", a + b),
            "-" => println!("= {}", a - b),
            "*" => println!("= {}", a * b),
            "/" => {
                if b == 0.0 {
                    println!("0으로 나눌 수 없습니다");
                } else {
                    println!("= {}", a / b);
                }
            }
            _ => println!("지원하지 않는 연산자: {}", op),
        }
    }
}
