const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function main() {
  rl.question("Enter task (1, 2, 3): ", function (task) {
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
        console.log("Error");
        rl.close();
        break;
    }
  });
}

function task1() {
  rl.question("Enter string: ", function (entStr) {
    let realStr = [entStr[0]];
    let counterSymbolStr = 1;
    let counterAddSymbol = 0;

    for (let i = 1; i < entStr.length; i++) {
      if (entStr[i] === entStr[i - 1]) {
        if (counterSymbolStr === 2) {
          counterSymbolStr = 1;
          realStr.push(String.fromCharCode(entStr[i].charCodeAt(0) + 1));
          realStr.push(entStr[i]);
          counterAddSymbol++;
        } else {
          counterSymbolStr++;
          realStr.push(entStr[i]);
        }
      } else {
        counterSymbolStr = 1;
        realStr.push(entStr[i]);
      }
    }

    process.stdout.write("Result: " + counterAddSymbol + " = ");
    realStr.forEach(ch => process.stdout.write(ch));
    rl.close();
  });
}


function task2() {
  const morseCode = {
    A: '*-',
    B: '-***',
    W: '*--',
    G: '--*',
    D: '-**',
    E: '*',
    V: '***-',
    Z: '--**',
    I: '**',
    J: '*---',
    K: '-*-',
    L: '*-**',
    M: '--',
    N: '-*',
    O: '---',
    P: '*--*',
    R: '*-*',
    S: '***',
    T: '-',
    U: '**-',
    F: '**-*',
    H: '****',
    C: '-*-*',
    Q: '--*-',
    Y: '-*--',
    X: '-**-',
    1: '*----',
    2: '**---',
    3: '***--',
    4: '****-',
    5: '*****',
    6: '-****',
    7: '--***',
    8: '---**',
    9: '----*',
    0: '-----',
  };

  rl.question('Enter string: ', (entStr) => {
    const words = entStr.split(' ')
    const mapWordMorse = {}

    words.forEach((word) => {
      if (word.length >= 1 && word.length <= 12) {
        wordMorseCombinations(word, mapWordMorse, morseCode)
        console.log()
      }
    })

    const uniqueWordCounter = Object.values(mapWordMorse).filter(
      (value) => value === 1
    ).length
    console.log('Result: ' + uniqueWordCounter)
    rl.close()
  })
}

function wordMorseCombinations(word, mapWordMorse, morseCode) {
  const uniquePermutations = getUniquePermutations(word)

  uniquePermutations.forEach((permutation) => {
    const morseResult = morseTranslation(permutation, morseCode)
    console.log(' ' + permutation + '  =  ' + morseResult)

    if (!mapWordMorse.hasOwnProperty(morseResult)) {
      mapWordMorse[morseResult] = 1
    } else {
      mapWordMorse[morseResult]++
    }
  })
}

function morseTranslation(word, morseCode) {
  let wordMorse = ''
  for (let i = 0; i < word.length; i++) {
    wordMorse += morseCode[word[i].toUpperCase()]
  }
  return wordMorse
}

function swap(list, a, b) {
  if (a === b) return; // Нет необходимости менять местами, если индексы одинаковые

  const temp = list[a];
  list[a] = list[b];
  list[b] = temp;
}

function getUniquePermutations(word) {
  const permutations = []
  getUniquePermutationsHelper([...word], 0, word.length - 1, permutations)
  return Array.from(new Set(permutations))
}

function getUniquePermutationsHelper(list, k, m, result) {
  if (k === m) {
    result.push(list.join(''))
  } else {
    for (let i = k; i <= m; i++) {
      swap(list, k, i)
      getUniquePermutationsHelper(list, k + 1, m, result)
      swap(list, k, i)
    }
  }
}



function task3() {
  let inputNumbers = [];
  let totalNumbers;

  const processInput = function(input) {
    const numbers = input.split(' ').map(Number);
    inputNumbers = inputNumbers.concat(numbers);
    
    if (inputNumbers.length >= totalNumbers) {
      const vectorOddNumbers = inputNumbers.map(counterOddNumbers);
      console.log("Result: " + vectorOddNumbers.join(' '));
      rl.close();
    } else {
      rl.question("Enter the next number: ", processInput);
    }
  };

  rl.question("Enter the total number of numbers: ", function (input) {
    totalNumbers = parseInt(input, 10);
    rl.question("Enter the numbers separated by spaces: ", processInput);
  });
}

function counterOddNumbers(number) {
  let counterOddNumbers = 0;

  while (number !== 0) {
    if ((number % 10) % 2 !== 0) {
      counterOddNumbers++;
    }
    number = Math.floor(number / 10);
  }

  return counterOddNumbers;
}

main();
