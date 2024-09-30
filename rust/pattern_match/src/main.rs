enum Message {
    Hello { id: i32 },
}

fn main() {
    let x = Some(5);
    let y = 10;

    match x {
        Some(50) => println!("Got 50"),
        Some(y) => println!("Matched, y = {:?}", y),
        _ => println!("Default case = {:?}", x),
    }

    let z = 5;
    match z {
        1..=5 => println!("one to five"),
        _ => println!("something else"),
    }

    let robot_name = Some(String::from("Bors"));

    match robot_name {
        Some(ref name) => println!("Found name: {}", name),
        None => (),
    }

    println!("robot_name is {:?}", robot_name);

    let msg = Message::Hello { id: 5 };

    match msg {
        Message::Hello { id: id_variable @ 3..=7 } => {
            println!("Found an id in range: {}", id_variable)
        },
        Message::Hello { id: 10..=12 } => {
            println!("Found an id in another range")
        },
        Message::Hello { id } => {
            println!("Found some other id: {}", id)
        },
    }
}
