use std::io::stdin;

#[derive(Debug)]
struct Visitor {
    name: String,
    greeting: String,
}

fn what_is_your_name() -> String {
    let mut your_name = String::new();
    stdin()
        .read_line(&mut your_name)
        .expect("Failed to read line");
    your_name
        .trim()
        .to_lowercase()
}

fn main() {
    let mut visitor_list = vec![
        Visitor::new("bert", "Hello bert, enjoy your treehouse."),
        Visitor::new("steve", "Hi Steve. Your milk is in the fridge."),
        Visitor::new("fred", "Wow, you invited Freddie"),
    ];

    loop {
        println!("Hello, what's your name");
        let name = what_is_your_name();
        println!("{:?}", name);

        visitor_list.push(
            Visitor::new("paul", "Enjoy the treehouse Paul.")
        );
    
        let mut allow_them_in = false;
    
        for visitor in &visitor_list {
            if visitor.name == name {
                allow_them_in = true;
            }
        }

        if allow_them_in {
            println!("Welcome to the Treehouse, {}", name);
        } else {
            println!("You are not welcome here.");
        }

        let known_visitor = visitor_list
            .iter()
            .find(|visitor| visitor.name == name);

        match known_visitor {
            Some(visitor) => visitor.greet_visitor(),
            None => {
                if name.is_empty() {
                    break;
                } else {
                    println!("You are not on the visitor list. Please leave");
                    visitor_list.push(Visitor::new(&name, "New friend"));
                }
            
            }
    
        }
    }

    println!("The final list of vistors:");
    println!("{:#?}", visitor_list);

}
 
impl Visitor {
    fn new(name: &str, greeting: &str) -> Self {
        Self {
            name: name.to_lowercase(),
            greeting: greeting.to_string(),
        }
    }

    fn greet_visitor(&self) {
        println!("{}", self.greeting);
    }
    
}
