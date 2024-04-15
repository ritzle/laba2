use std::collections::HashMap;
use std::io::{self, BufRead};

fn main() {
    let mut task = String::new();
    println!("Enter task (1, 2, 3): ");
    io::stdin().read_line(&mut task).expect("Failed to read line");
    let task: char = task.trim().chars().next().expect("Empty input");

    match task {
        '1' => task1(),
        '2' => task2(),
        '3' => task3(),
        _ => println!("Error"),
    }
}

fn task1() {
    println!("Enter string: ");
    let mut ent_str = String::new();
    io::stdin().read_line(&mut ent_str).expect("Failed to read line");

    let mut real_str: Vec<char> = Vec::new();
    real_str.push(ent_str.chars().next().unwrap());

    let mut counter_symbol_str = 1;
    let mut counter_add_symbol = 0;

    for (i, c) in ent_str.chars().enumerate().skip(1) {
        if c == ent_str.chars().nth(i - 1).unwrap() {
            if counter_symbol_str == 2 {
                counter_symbol_str = 1;
                real_str.push((c as u8 + 1) as char);
                real_str.push(c);
                counter_add_symbol += 1;
            } else {
                counter_symbol_str += 1;
                real_str.push(c);
            }
        } else {
            counter_symbol_str = 1;
            real_str.push(c);
        }
    }

    print!("Result: {} = ", counter_add_symbol);
    for ch in real_str {
        print!("{}", ch);
    }
}

fn task2() {
    let morse_code: HashMap<char, &str> = [
        ('A', "*-"),
        ('B', "-***"),
        ('W', "*--"),
        ('G', "--*"),
        ('D', "-**"),
        ('E', "*"),
        ('V', "***-"),
        ('Z', "--**"),
        ('I', "**"),
        ('J', "*---"),
        ('K', "-*-"),
        ('L', "*-**"),
        ('M', "--"),
        ('N', "-*"),
        ('O', "---"),
        ('P', "*--*"),
        ('R', "*-*"),
        ('S', "***"),
        ('T', "-"),
        ('U', "**-"),
        ('F', "**-*"),
        ('H', "****"),
        ('C', "-*-*"),
        ('Q', "--*-"),
        ('Y', "-*--"),
        ('X', "-**-"),
        ('1', "*----"),
        ('2', "**---"),
        ('3', "***--"),
        ('4', "****-"),
        ('5', "*****"),
        ('6', "-****"),
        ('7', "--***"),
        ('8', "---**"),
        ('9', "----*"),
        ('0', "-----"),
    ]
    .iter()
    .cloned()
    .collect();

    println!("Enter string: ");
    let mut ent_str = String::new();
    io::stdin().read_line(&mut ent_str).expect("Failed to read line");

    if ent_str.len() < 1 || ent_str.len() > 100 {
        println!("Error");
        return;
    }

    let words: Vec<&str> = ent_str.split_whitespace().collect();
    let mut map_word_morse: HashMap<String, i32> = HashMap::new();

    for word in words {
        if word.len() >= 1 && word.len() <= 12 {
            word_morse_combinations(word, &mut map_word_morse, &morse_code);
            println!();
        }
    }

    let unique_word_counter = map_word_morse.iter().filter(|&(_, &v)| v == 1).count();
    println!("Result: {}", unique_word_counter);
}

fn word_morse_combinations(
    word: &str,
    map_word_morse: &mut HashMap<String, i32>,
    morse_code: &HashMap<char, &str>,
) {
    let unique_permutations = get_unique_permutations(word);

    for permutation in unique_permutations {
        let morse_result = morse_translation(&permutation.to_ascii_uppercase(), morse_code);
        println!("{}  =  {}", permutation, morse_result);

        map_word_morse
            .entry(morse_result)
            .and_modify(|v| *v += 1)
            .or_insert(1);
    }
}

fn morse_translation(word: &str, morse_code: &HashMap<char, &str>) -> String {
    let mut word_morse = String::new();
    for ch in word.chars() {
        word_morse.push_str(morse_code[&ch]);
    }
    word_morse
}

fn get_unique_permutations(word: &str) -> Vec<String> {
    let mut permutations = Vec::new();
    let chars: Vec<char> = word.chars().collect();
    get_unique_permutations_helper(&chars, 0, chars.len() - 1, &mut permutations);
    permutations.sort();
    permutations.dedup();
    permutations
}

fn get_unique_permutations_helper(
    list: &[char],
    k: usize,
    m: usize,
    result: &mut Vec<String>,
) {
    if k == m {
        result.push(list.iter().collect());
    } else {
        for i in k..=m {
            let mut list = list.to_vec();
            list.swap(k, i);
            get_unique_permutations_helper(&list, k + 1, m, result);
        }
    }
}

fn task3() {
    println!("Enter the number of numbers: ");
    let mut amount_numbers = String::new();
    io::stdin()
        .read_line(&mut amount_numbers)
        .expect("Failed to read line");
    let amount_numbers: usize = amount_numbers
        .trim()
        .parse()
        .expect("Please enter a valid number");

    let mut vector_odd_numbers = Vec::new();

    for _ in 0..amount_numbers {
        println!("Enter number: ");
        let mut ent_numbers = String::new();
        io::stdin()
            .read_line(&mut ent_numbers)
            .expect("Failed to read line");
        let ent_numbers: usize = ent_numbers
            .trim()
            .parse()
            .expect("Please enter a valid number");

        vector_odd_numbers.push(counter_odd_numbers(ent_numbers));
    }

    for odd_numbers in vector_odd_numbers {
        print!("{} ", odd_numbers);
    }
}

fn counter_odd_numbers(mut number: usize) -> usize {
    let mut counter_odd_numbers = 0;

    while number != 0 {
        if (number % 10) % 2 != 0 {
            counter_odd_numbers += 1;
        }
        number /= 10;
    }

    counter_odd_numbers
}
