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
        .collect()
}

pub fn evaluate(data: String) -> String {
    format!("{:?}", token_wrapper(str_to_str_segs(data)))
}
