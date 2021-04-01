use crate::str_to_str_segs;
use crate::is_number;
// use crate::CharacterType;

// mod charater_type_createion {
//     use crate::CharacterType;

//     #[test]
//     fn number_createion() {
//         assert_eq!(CharacterType::new('1'), CharacterType::new)
//     }

//     fn empty_creation() {
//         assert_eq!()
//     }
// }

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
fn is_num_test (){
    for i in 0..10 {
        assert!(is_number(format!("{}", i).chars().next().unwrap()))
    }
    assert!(!is_number('a'));
    assert!(!is_number(':'));
    assert!(!is_number('/'));
}