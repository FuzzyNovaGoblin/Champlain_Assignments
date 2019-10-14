wordLetters = ['p', 'o', 'l', 'y', 'c', 'h', 'o', 't', 'o', 'm', 'y'];
guessedLetters = ['_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_'];
guessCount = [];
wrongCount = 0;

window.onload = () => {

   console.log('put functions in here');
   squareNumber(5);
   halfNumber(13);
   percentOf(53, 34);
   areaOfCircle(2);
   bigThingy(20);
}

const squareNumber = (num) => {
   let ans = num * num;
   console.log("The result of squaring the number " + num + " is " + ans + ".");
   return ans;
}

const halfNumber = (num) => {
   let ans = num / 2;
   console.log("Half of " + num + " is " + ans + ".");
   return ans;
}

const percentOf = (num1, num2) => {
   let ans = num2 * 100 / num1;
   console.log(`${num2} is ${ans}% of ${num1}.`);
   return ans;
}


const areaOfCircle = (r) => {
   let area = Math.round(Math.PI * r ** 2 * 100) / 100;
   console.log(`The area for a circle with radius ${r} is ${area}`);
   return area;
}

const bigThingy = (num) => {
   let res1 = halfNumber(num);
   let res2 = squareNumber(res1);
   let area = areaOfCircle(res2);
   percentOf(res2, area);
}

const guessLetter = (guess) => {
   if (!guess || !String(guess) || guessCount >= 6 || guess =='_') return false;
   guess = String(guess)[0];
   let found = false;
   let currentWord = "";
   let currentGuesses = "";

   for (let i = 0; i < guessCount.length; i++){
      if (guess == guessCount[i]) {
         return false;
      }
   }
   guessCount.push(guess);

   for (let i = 0; i < wordLetters.length; i++) {
      if (guess == wordLetters[i]) {
         guessedLetters[i] = guess;
         found = true;
      }
      currentWord += guessedLetters[i];
   }
   for (let i = 0; i < guessCount.length; i++){
      currentGuesses += guessCount[i] + " ";
   }
   console.log(currentWord);
   if (found) {
      console.log("Good Job, you found a letter!");
   }
   else {
      wrongCount++;
   }
   printHangman(currentGuesses);

   let remaining = 0;
   for (let i = 0; i < guessedLetters.length; i++) {
      if (guessedLetters[i] == '_') remaining++;
   }
   if (remaining == 0) {
      console.log("Good Job You Won!!!");
   }
   else {
      console.log("There are " + remaining + " letters remaining");
   }
}


const printHangman = (currentGuesses) => {
   switch (wrongCount) {
      case 0:
         console.log(`
         ${currentGuesses}
    _________
    |         |
    |
    |
    |
    |
    |
   `);
         break;
      case 1:
         console.log(`
         ${currentGuesses}
    _________
    |         |
    |         0
    |
    |
    |
    |
   `);
         break;
      case 2:
         console.log(`
         ${currentGuesses}
    _________
    |         |
    |         0
    |         |
    |
    |
    |
   `);
         break;
      case 3:
         console.log(`
         ${currentGuesses}
    _________
    |         |
    |         0
    |        /|
    |
    |
    |
   `);
         break;
      case 4:
         console.log(`
         ${currentGuesses}
    _________
    |         |
    |         0
    |        /|\\
    |
    |
    |
   `);
         break;
      case 5:
         console.log(`
         ${currentGuesses}
    _________
    |         |
    |         0
    |        /|\\
    |        /
    |
    |
   `);
         break;
      case 6:
         console.log(`
         ${currentGuesses}
    _________
    |         |
    |         0
    |        /|\\
    |        / \\
    |
    |
   `);
         console.log("Sorry you lose");
         break;
   }

}