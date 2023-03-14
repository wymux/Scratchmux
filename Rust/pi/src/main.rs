fn main() {
    let iterations = 100000;
    let mut pi: f64 = 0.0;
    let mut sign: f64 = 1.0;
    for i in 0..iterations {
        pi += sign / (2.0 * i as f64 + 1.0);
        sign = -sign;
    }
    pi *= 4.0;
    println!("π ≈ {}", pi);
}
