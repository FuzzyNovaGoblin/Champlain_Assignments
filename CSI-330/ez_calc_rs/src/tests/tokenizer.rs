use crate::string_segmenter::str_to_str_segs;

mod str_to_str_segs_tests {
    use super::*;

    #[test]
    fn default() {
        let tokens = str_to_str_segs("1 + 3 * 4".into());
        assert_eq!(
            tokens,
            vec![
                String::from("1"),
                "+".into(),
                "3".into(),
                "*".into(),
                "4".into()
            ]
        );
    }
    #[test]
    fn no_space() {
        let tokens = str_to_str_segs("1+3*4".into());
        assert_eq!(
            tokens,
            vec![
                String::from("1"),
                "+".into(),
                "3".into(),
                "*".into(),
                "4".into()
            ]
        );
    }
    #[test]
    fn longer_nums() {
        let tokens = str_to_str_segs("132+343*34".into());
        assert_eq!(
            tokens,
            vec![
                String::from("132"),
                "+".into(),
                "343".into(),
                "*".into(),
                "34".into()
            ]
        );
    }
    #[test]
    fn parenths_and_commas() {
        let tokens = str_to_str_segs("132+(3,4,3)*34".into());
        assert_eq!(
            tokens,
            vec![
                String::from("132"),
                "+".into(),
                "(".into(),
                "3".into(),
                ",".into(),
                "4".into(),
                ",".into(),
                "3".into(),
                ")".into(),
                "*".into(),
                "34".into()
            ]
        );
    }

    #[test]
    fn methods() {
        let tokens = str_to_str_segs("root(24, 2) +7".into());
        assert_eq!(
            tokens,
            vec![
                String::from("root"),
                "(".into(),
                "24".into(),
                ",".into(),
                "2".into(),
                ")".into(),
                "+".into(),
                "7".into()
            ]
        );
    }
    #[test]
    fn parenths_and_commas2() {
        let tokens = str_to_str_segs("132+((3,,4,3)*34".into());
        assert_eq!(
            tokens,
            vec![
                String::from("132"),
                "+".into(),
                "(".into(),
                "(".into(),
                "3".into(),
                ",".into(),
                ",".into(),
                "4".into(),
                ",".into(),
                "3".into(),
                ")".into(),
                "*".into(),
                "34".into()
            ]
        );
    }
}
#[test]
fn wrapped_tokens() {
    use crate::token_wrapper;
    use crate::TokenType::*;

    let tokens = token_wrapper(str_to_str_segs("132+((3,,4,3)*34".into()));
    assert_eq!(
        tokens,
        vec![
            Value(132_f64),
            Operator('+'),
            Paren(1),
            Paren(2),
            Value(3_f64),
            Value(4_f64),
            Value(3_f64),
            Paren(2),
            Operator('*'),
            Value(34_f64)
        ]
    );
}

mod calc_math {
    pub use crate::evaluate;

    #[test]
    fn add() {
        assert_eq!(evaluate(String::from("43+3")), "46")
    }

    #[test]
    fn sub() {
        assert_eq!(evaluate(String::from("43-3")), "40")
    }

    #[test]
    fn mult() {
        assert_eq!(evaluate(String::from("3*3")), "9")
    }

    #[test]
    fn div() {
        assert_eq!(evaluate(String::from("100   /5")), "20")
    }

    #[test]
    fn modulus() {
        assert_eq!(evaluate(String::from("43%3")), "1")
    }

    #[test]
    fn div_by_0() {
        assert_eq!(evaluate(String::from("20/0")), "inf")
    }

    mod pemdas {
        use crate::evaluate;

        #[test]
        fn mult_then_add() {
            assert_eq!(evaluate(String::from("5+3 *6")), "23");
            assert_eq!(evaluate(String::from("6*5+3")), "23");
        }

        #[test]
        fn parens_first() {
            assert_eq!(evaluate(String::from("5+(3 -6)")), "2")
        }
    }
}

#[test]
fn is_num_test() {
    use crate::string_segmenter::*;
    for i in 0..10 {
        assert!(is_number(format!("{}", i).chars().next().unwrap()))
    }
    assert!(!is_number('a'));
    assert!(!is_number(':'));
    assert!(!is_number('/'));
}
