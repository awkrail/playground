struct User {
    username: String,
    email: String,
    sign_in_count: u64,
    active: bool
}

fn build_user(email: String, username: String) -> User {
    User {
        email,
        username,
        active: true,
        sign_in_count: 1,
    }
}

fn main() {
    let email = String::from("bob@example.com");
    let username = String::from("bob");
    let user1 = build_user(email, username);

    let user2 = User {
        email: String::from("alice@example.com"),
        username: String::from("alice"),
        ..user1
    };
}
