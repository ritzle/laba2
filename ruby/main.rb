def main
  print "Enter task (1, 2, 3): "
  task = gets.chomp

  case task
  when '1'
    task1
  when '2'
    task2
  when '3'
    task3
  else
    puts "Error"
  end
end

def task1
  print "Enter string: "
  ent_str = gets.chomp

  real_str = [ent_str[0]]
  counter_symbol_str = 1
  counter_add_symbol = 0

  (1...ent_str.length).each do |i|
    if ent_str[i] == ent_str[i - 1]
      if counter_symbol_str == 2
        counter_symbol_str = 1
        real_str << (ent_str[i].ord + 1).chr
        real_str << ent_str[i]
        counter_add_symbol += 1
      else
        counter_symbol_str += 1
        real_str << ent_str[i]
      end
    else
      counter_symbol_str = 1
      real_str << ent_str[i]
    end
  end

  print "Result: #{counter_add_symbol} = "
  puts real_str.join
end

def task2
  morse_code = {
    'A' => "*-",
    'B' => "-***",
    'W' => "*--",
    'G' => "--*",
    'D' => "-**",
    'E' => "*",
    'V' => "***-",
    'Z' => "--**",
    'I' => "**",
    'J' => "*---",
    'K' => "-*-",
    'L' => "*-**",
    'M' => "--",
    'N' => "-*",
    'O' => "---",
    'P' => "*--*",
    'R' => "*-*",
    'S' => "***",
    'T' => "-",
    'U' => "**-",
    'F' => "**-*",
    'H' => "****",
    'C' => "-*-*",
    'Q' => "--*-",
    'Y' => "-*--",
    'X' => "-**-",
    '1' => "*----",
    '2' => "**---",
    '3' => "***--",
    '4' => "****-",
    '5' => "*****",
    '6' => "-****",
    '7' => "--***",
    '8' => "---**",
    '9' => "----*",
    '0' => "-----"
  }

  print "Enter string: "
  ent_str = gets.chomp

  if ent_str.length < 1 || ent_str.length > 100
    puts "Error"
    return
  end

  words = ent_str.split(' ')

  map_word_morse = {}

  words.each do |word|
    if word.length >= 1 && word.length <= 12
      word_morse_combinations(word, map_word_morse, morse_code)
      puts
    end
  end

  unique_word_counter = map_word_morse.count { |_, v| v == 1 }
  puts "Result: #{unique_word_counter}"
end

def word_morse_combinations(word, map_word_morse, morse_code)
  unique_permutations = get_unique_permutations(word)

  unique_permutations.each do |permutation|
    morse_result = morse_translation(permutation, morse_code)
    puts " #{permutation}  =  #{morse_result}"

    map_word_morse[morse_result] ||= 0
    map_word_morse[morse_result] += 1
  end
end

def morse_translation(word, morse_code)
  word_morse = ''
  word.each_char do |ch|
    word_morse += morse_code[ch.upcase]
  end
  word_morse
end

def get_unique_permutations(word)
  word.chars.permutation.map(&:join).uniq
end

def task3
  print "Enter the number of numbers: "
  amount_numbers = gets.chomp.to_i


  amount_numbers.times do
    print "Enter number: "
    ent_numbers = gets.chomp.to_i
    print "Number of odd digits: #{counter_odd_numbers(ent_numbers)} \n"
  end

end

def counter_odd_numbers(number)
  counter_odd_numbers = 0

  while number != 0
    if (number % 10) % 2 != 0
      counter_odd_numbers += 1
    end
    number /= 10
  end

  counter_odd_numbers
end

main
