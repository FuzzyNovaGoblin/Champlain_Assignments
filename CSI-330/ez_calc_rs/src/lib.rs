use std::fmt::Display;

use string_segmenter::str_to_str_segs;

#[cfg(test)]
mod tests;

#[derive(Debug, PartialEq)]
enum TokenType {
    Operator(char),
    Value(f64),
    Method(String),
    Paren(u8),
    Empty,
}

impl Display for TokenType {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            TokenType::Operator(v) => write!(f, "{}", *v),
            TokenType::Value(v) => write!(f, "{}", v),
            TokenType::Method(v) => write!(f, "{}", v),
            TokenType::Paren(v) => write!(f, "{}", v),
            TokenType::Empty => write!(f, "Empty",),
        }
    }
}

mod string_segmenter {
    pub fn is_number(c: char) -> bool {
        c >= '0' && c <= '9'
    }

    fn is_letter(c: char) -> bool {
        (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
    }

    fn same_type(c1: char, c2: char) -> bool {
        (is_number(c1) && is_number(c2)) || (is_letter(c1) && is_letter(c2))
    }

    pub fn str_to_str_segs(line: String) -> Vec<String> {
        let parts = string_first_pass(&line);

        parts
            .iter()
            .filter(|s| s.trim().len() > 0)
            .map(|s| String::from(*s))
            .collect()
    }

    fn string_first_pass(line: &str) -> Vec<&str> {
        let line_chars: Vec<char> = line.chars().collect();

        let indicies = (1..line.len()).into_iter().map(|i| {
            if !same_type(line_chars[i - 1], line_chars[i]) {
                Some(i)
            } else {
                None
            }
        });

        let mut index = 0;
        let mut parts = Vec::new();
        for i in indicies {
            if let Some(v) = i {
                parts.push(&line[index..v]);
                index = v;
            }
        }
        parts.push(&line[index..]);

        parts
    }
}

fn token_wrapper(segs: Vec<String>) -> Vec<TokenType> {
    use string_segmenter::is_number;
    use TokenType::*;
    let mut paren_count = 0;

    segs.iter()
        .map(|seg| {
            if seg == "(" {
                paren_count += 1;
                Paren(paren_count)
            } else if seg == ")" {
                let ret = Paren(paren_count);
                paren_count += 1;
                ret
            } else if seg.len() == 1 {
                let c = seg.chars().next().unwrap();
                if is_number(c) {
                    match seg.parse() {
                        Ok(v) => Value(v),
                        Err(_) => Empty,
                    }
                } else {
                    Operator(c)
                }
            } else {
                if let Ok(v) = seg.parse() {
                    Value(v)
                } else {
                    Method(seg.clone())
                }
            }
        })
        .filter(|v| match v {
            Operator(c_op) => *c_op != ',',
            _ => true,
        })
        .collect()
}

fn preform_op(operator: char, num1: f64, num2: f64) -> TokenType {
    match operator {
        '+' => TokenType::Value(num1 + num2),
        '-' => TokenType::Value(num1 - num2),
        '*' => TokenType::Value(num1 * num2),
        '/' => TokenType::Value(num1 / num2),
        '%' => TokenType::Value(num1 % num2),
        _ => TokenType::Empty,
    }
}

fn token_eval(mut tokens: Vec<TokenType>) -> Result<f64, u32> {
    use TokenType::*;

    if tokens.len() < 1 {
        return Err(line!());
    }
    if tokens.len() == 1 {
        if let Value(v) = tokens.get(0).unwrap() {
            return Ok(*v);
        } else {
            return Err(line!());
        }
    }

    let mut op_index = None;
    for (i, t) in tokens.iter().enumerate() {
        if let Operator(_) = t {
            op_index = Some(i);
            if i == 0 || i == tokens.len() - 1 {
                return Err(line!());
            }
        }
    }
    let op_index = match op_index {
        Some(v) => v,
        None => return Err(line!()),
    };

    let o_v_v: (char, f64, f64) = (
        match tokens[op_index] {
            Operator(v) => v,
            _ => return Err(line!()),
        },
        match tokens[op_index - 1] {
            Value(v) => v,
            _ => return Err(line!()),
        },
        match tokens[op_index + 1] {
            Value(v) => v,
            _ => return Err(line!()),
        },
    );

    tokens.splice(
        op_index - 1..op_index + 2,
        vec![preform_op(o_v_v.0, o_v_v.1, o_v_v.2)],
    );

    token_eval(tokens)
}

pub fn evaluate(data: String) -> String {
    let ans = token_eval(token_wrapper(str_to_str_segs(data)));
    match ans {
        Ok(v) => {
            format!("{}", v)
        }
        Err(_) => format!("{:?}", ans),
    }
}
