use ez_calc_rs::evaluate;

pub fn main() {
    let v = evaluate("132+343*34".into());
    println!("{:#?}", v);
}
