#[cfg(test)]
mod tests;

#[derive(Debug, PartialEq)]
pub enum TokenType {
    Operator,
    Value,
    Variable,
    Method,
    Arguments,
    FUNCTION,
}

// impl CharacterType {
//     pub fn new(c: char) -> CharacterType {
//         CharacterType::Empty
//     }

//     pub fn new_empty() -> CharacterType {
//         CharacterType::Empty
//     }
// }

fn is_number(c: char) -> bool {
    c >= '0' && c <= '9'
}
fn is_letter(c: char) -> bool {
    (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
}
fn same_type(c1: char, c2: char) -> bool {
    (is_number(c1) && is_number(c2)) || (is_letter(c1) && is_letter(c2))
}

pub fn str_to_str_segs(line: String) -> Vec<String> {
    let mut parts: Vec<&str> = Vec::new();

    {
        let indicies = line
            .chars()
            .zip(line.chars().skip(1))
            .zip(0..line.len())
            .map(|((c, n), i)| if !same_type(c, n) { Some(i) } else { None });

        let mut index = 0;
        for i in indicies {
            if let Some(v) = i {
                parts.push(&line[index..v + 1]);
                index = v + 1;
            }
        }
        parts.push(&line[index..]);
    }

    let mut ret = Vec::new();
    for s in parts {
        if s.trim().len() > 0 {
            ret.push(String::from(s));
        }
    }
    ret
}
