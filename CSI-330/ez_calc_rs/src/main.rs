use ez_calc_rs::str_to_str_segs;


pub fn main(){
    let v = str_to_str_segs("21+25*4".into());
    println!("{:#?}", v);
}