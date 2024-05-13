import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter task (1, 2, 3): ");
        char task = scanner.nextLine().charAt(0);

        switch (task) {
            case '1':
                task1();
                break;
            case '2':
                task2();
                break;
            case '3':
                task3();
                break;
            default:
                System.out.println("Error");
                break;
        }
    }

    static void task1() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter string: ");
        String entStr = scanner.nextLine();

        List<Character> realStr = new ArrayList<>();
        realStr.add(entStr.charAt(0));

        int counterSymbolStr = 1;
        int counterAddSymbol = 0;

        for (int i = 1; i < entStr.length(); i++) {
            if (entStr.charAt(i) == entStr.charAt(i - 1)) {
                if (counterSymbolStr == 2) {
                    counterSymbolStr = 1;
                    realStr.add((char) (entStr.charAt(i) + 1));
                    realStr.add(entStr.charAt(i));
                    counterAddSymbol++;
                } else {
                    counterSymbolStr++;
                    realStr.add(entStr.charAt(i));
                }
            } else {
                counterSymbolStr = 1;
                realStr.add(entStr.charAt(i));
            }
        }

        System.out.print("Result: " + counterAddSymbol + " = ");
        for (char ch : realStr) {
            System.out.print(ch);
        }
    }

    static void task2() {
        Scanner scanner = new Scanner(System.in);
        Map<Character, String> morseCode = new HashMap<>();
        morseCode.put('A', "*-");
        morseCode.put('B', "-***");
        morseCode.put('W', "*--");
        morseCode.put('G', "--*");
        morseCode.put('D', "-**");
        morseCode.put('E', "*");
        morseCode.put('V', "***-");
        morseCode.put('Z', "--**");
        morseCode.put('I', "**");
        morseCode.put('J', "*---");
        morseCode.put('K', "-*-");
        morseCode.put('L', "*-**");
        morseCode.put('M', "--");
        morseCode.put('N', "-*");
        morseCode.put('O', "---");
        morseCode.put('P', "*--*");
        morseCode.put('R', "*-*");
        morseCode.put('S', "***");
        morseCode.put('T', "-");
        morseCode.put('U', "**-");
        morseCode.put('F', "**-*");
        morseCode.put('H', "****");
        morseCode.put('C', "-*-*");
        morseCode.put('Q', "--*-");
        morseCode.put('Y', "-*--");
        morseCode.put('X', "-**-");
        morseCode.put('1', "*----");
        morseCode.put('2', "**---");
        morseCode.put('3', "***--");
        morseCode.put('4', "****-");
        morseCode.put('5', "*****");
        morseCode.put('6', "-****");
        morseCode.put('7', "--***");
        morseCode.put('8', "---**");
        morseCode.put('9', "----*");
        morseCode.put('0', "-----");

        System.out.print("Enter string: ");
        String entStr = scanner.nextLine();

        if (entStr.length() < 1 || entStr.length() > 100) {
            System.out.println("Error");
            return;
        }

        String[] words = entStr.split(" ");

        Map<String, Integer> mapWordMorse = new HashMap<>();

        for (String word : words) {
            if (word.length() >= 1 && word.length() <= 12) {
                wordMorseCombinations(word, mapWordMorse, morseCode);
                System.out.println();
            }
        }

        long uniqueWordCounter = mapWordMorse.values().stream().filter(v -> v == 1).count();
        System.out.println("Result: " + uniqueWordCounter);
    }

    static void wordMorseCombinations(String word, Map<String, Integer> mapWordMorse, Map<Character, String> morseCode) {
        List<String> uniquePermutations = getUniquePermutations(word);

        for (String permutation : uniquePermutations) {
            String morseResult = morseTranslation(permutation, morseCode);
            System.out.println(" " + permutation + "  =  " + morseResult);

            mapWordMorse.merge(morseResult, 1, Integer::sum);
        }
    }

    static String morseTranslation(String word, Map<Character, String> morseCode) {
        StringBuilder wordMorse = new StringBuilder();
        for (char ch : word.toCharArray()) {
            wordMorse.append(morseCode.getOrDefault(Character.toUpperCase(ch), ""));
        }
        return wordMorse.toString();
    }

    // Method to get unique permutations of characters in the list
    public static List<String> getUniquePermutations(String word) {
        List<String> permutations = new ArrayList<>();
        getUniquePermutationsHelper(word.toCharArray(), 0, word.length() - 1, permutations);
        return new ArrayList<>(new HashSet<>(permutations));
    }

    // Recursive method to generate unique permutations
    private static void getUniquePermutationsHelper(char[] list, int k, int m, List<String> result) {
        if (k == m) {
            result.add(new String(list));
        } else {
            for (int i = k; i <= m; i++) {
                swap(list, k, i);
                getUniquePermutationsHelper(list, k + 1, m, result);
                swap(list, k, i);
            }
        }
    }

    // Method to swap two characters using XOR operation
    private static void swap(char[] list, int a, int b) {
        if (list[a] == list[b]) return; // No need to swap if the characters are the same

        list[a] ^= list[b]; // XOR operation to swap characters
        list[b] ^= list[a];
        list[a] ^= list[b];
    }

    static void task3() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of numbers: ");
        int amountNumbers = Integer.parseInt(scanner.nextLine());

        //List<Integer> vectorOddNumbers = new ArrayList<>();

        for (int i = 0; i < amountNumbers; i++) {
            System.out.print("Enter number: ");
            int entNumbers = Integer.parseInt(scanner.nextLine());
            System.out.print("Number of odd digits: " + counterOddNumbers(entNumbers) + "\n");
          //  vectorOddNumbers.add(counterOddNumbers(entNumbers));
        }

        // for (int oddNumbers : vectorOddNumbers) {
        //     System.out.print(oddNumbers + " ");
        // }
    }

    static int counterOddNumbers(int number) {
        int counterOddNumbers = 0;

        while (number != 0) {
            if ((number % 10) % 2 != 0) {
                counterOddNumbers++;
            }
            number /= 10;
        }

        return counterOddNumbers;
    }
}
