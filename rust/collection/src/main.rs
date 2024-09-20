use std::collections::HashMap;

fn main() {
    let field_name = String::from("Favorite color");
    let field_value = String::from("Blue");

    let mut map = HashMap::new();
    map.insert(field_name, field_value);

    let name = String::from("Favorite color");
    let score = map.get(&name);
    println!("{:?}", score);
}
