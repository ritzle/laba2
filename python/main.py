from itertools import permutations

def counter_odd_numbers(number):
    counter_odd = 0
    while number:
        if (number % 10) % 2 != 0:
            counter_odd += 1
        number //= 10
    return counter_odd

def task_3():
    amount_numbers = int(input("Enter the number of numbers: "))
    print("\nEnter numbers: ")
    odd_numbers = []
    for _ in range(amount_numbers):
        ent_number = int(input())
        odd_numbers.append(counter_odd_numbers(ent_number))
    for odd_number in odd_numbers:
        print(odd_number, end=" ")

def morse_translation(word, morse_code):
    word_morse = ""
    for char in word:
        word_morse += morse_code[char.upper()]
    return word_morse

def word_morse_combinations(word, map_word_morse, morse_code):
    sorted_word = ''.join(sorted(word))
    for perm in permutations(sorted_word):
        morse_result = morse_translation(perm, morse_code)
        print(f"{perm} = {morse_result}")
        map_word_morse[morse_result] += 1

def task_2():
    morse_code = {
        'A': "*-",
        'B': "-***",
        'W': "*--",
        'G': "--*",
        'D': "-**",
        'E': "*",
        'V': "***-",
        'Z': "--**",
        'I': "**",
        'J': "*---",
        'K': "-*-",
        'L': "*-**",
        'M': "--",
        'N': "-*",
        'O': "---",
        'P': "*--*",
        'R': "*-*",
        'S': "***",
        'T': "-",
        'U': "**-",
        'F': "**-*",
        'H': "****",
        'C': "-*-*",
        'Q': "--*-",
        'Y': "-*--",
        'X': "-**-",
        '1': "*----",
        '2': "**---",
        '3': "***--",
        '4': "****-",
        '5': "*****",
        '6': "-****",
        '7': "--***",
        '8': "---**",
        '9': "----*",
        '0': "-----"
    }
    ent_str = input("Enter string: ")
    if 1 > len(ent_str) or len(ent_str) > 100:
        print("Error")
        return
    words = ent_str.split()
    map_word_morse = {}
    for word in words:
        if 1 <= len(word) <= 12:
            map_word_morse[word] = 0
            word_morse_combinations(word, map_word_morse, morse_code)
            print()
    unique_word_counter = sum(1 for count in map_word_morse.values() if count == 1)
    print("Result:", unique_word_counter)

def task_1():
    ent_str = input("Enter string: ")
    real_str = [ent_str[0]]
    counter_symbol_str = 1
    counter_add_symbol = 0
    for i in range(1, len(ent_str)):
        if ent_str[i] == ent_str[i - 1]:
            if counter_symbol_str == 2:
                counter_symbol_str = 1
                real_str.append(chr(ord(ent_str[i]) + 1))
                real_str.append(ent_str[i])
                counter_add_symbol += 1
            else:
                counter_symbol_str += 1
                real_str.append(ent_str[i])
        else:
            counter_symbol_str = 1
            real_str.append(ent_str[i])
    print("Result:", counter_add_symbol, "=", ''.join(real_str))

if __name__ == "__main__":
    task = input("Enter task (1, 2, 3): ")
    if task == '1':
        task_1()
    elif task == '2':
        task_2()
    elif task == '3':
        task_3()
    else:
        print("Error")
