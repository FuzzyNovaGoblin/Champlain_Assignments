let myGame = null;

class Game {
//   rows;
//   cols;
//
//   spaces;
//   moves;
//   complete;
//   playing;
//   grids = [];
//   answerMap = {};

    constructor(cols, rows) {
	this.emptyPosition = { x: 0, y: 0 };
	this.grids = [];
	this.answerMap = {};
      this.moves = 0;
      this.playing = false;
      this.complete = false;
      this.rows = Number(rows);
      this.cols = Number(cols);
      this.spaces = Array(cols);
      let count = 1;
      for (let i = 0; i < this.spaces.length; i++) {
         this.spaces[i] = Array(rows);
      }
      for (let i = 0; i < this.spaces[0].length; i++) {
         for (let j = 0; j < this.spaces.length; j++) {
            this.answerMap[count] = { x: j, y: i };
            this.spaces[j][i] = count++;
         }
      }

      this.spaces[cols - 1][rows - 1] = "";


      for (let i = 0; i < this.spaces.length; i++) {
         let canBreak = false;
         for (let j = 0; j < this.spaces[i].length; j++) {
            if (this.spaces[i][j] == "") {
               this.emptyPosition.x = i;
               this.emptyPosition.y = j;
               break;
            }
         }
         if (canBreak) break;
      }

      this.shuffle();
      this.moves = 0;
      this.buildGame();
      this.playing = true;
   }

   //generates the html based on the state of the board
   buildGame() {
      let gameHolder = document.getElementById('game-holder');
      let table = document.createElement('table');
      for (let i = 0; i < this.spaces[0].length; i++) {
         let tmpRow = document.createElement('tr');
         for (let j = 0; j < this.spaces.length; j++) {
            tmpRow.innerHTML += `
            <td>
               <span class="badge badge-secondary game_tile" style="width: 100px" onclick="myGame.tileClick(${j + ', ' + i})">${this.spaces[j][i]}</span>
            </td>`;
         }
         table.appendChild(tmpRow);
      }
      gameHolder.innerHTML = "<table class='centerTable' align='center'>" + table.innerHTML + "</table>";
   }

   tileClick(x, y) {
      if (
         (this.emptyPosition.x - 1 == x && this.emptyPosition.y == y) ||
         (this.emptyPosition.x + 1 == x && this.emptyPosition.y == y) ||
         (this.emptyPosition.y - 1 == y && this.emptyPosition.x == x) ||
         (this.emptyPosition.y + 1 == y && this.emptyPosition.x == x)) {

         this.spaces[this.emptyPosition.x][this.emptyPosition.y] = this.spaces[x][y];
         this.spaces[x][y] = "";
         this.emptyPosition.x = x;
         this.emptyPosition.y = y;
      }
      this.moves++;
      this.buildGame();
      this.checkCorect() && this.playing && alert("You won in " + this.moves + " moves");
   }

   checkCorect() {
      let count = 1;
      for (let i = 0; i < this.spaces[0].length; i++) {
         for (let j = 0; j < this.spaces.length; j++) {
            if (Number(this.rows) * Number(this.cols) == count) return true;
            if (this.spaces[j][i] != count) return false;
            count++;
         }
      }
   }


   //preforms random moves so the board becomes shuffled but is always solvable
   shuffle() {
      let i = this.spaces.length * this.spaces[0].length * 50;
      while (i > 0) {
         switch (Math.floor(Math.random() * 4)) {
            case 0: //up
               if (this.emptyPosition.y == 0) break;
               this.tileClick((Number(this.emptyPosition.x)), (Number(this.emptyPosition.y) - 1));
               i--;
               break;
            case 1: //down
               if (this.emptyPosition.y == Number(this.rows) - 1) break;
               this.tileClick((Number(this.emptyPosition.x)), (Number(this.emptyPosition.y) + 1));
               i--;
               break;
            case 2: //left
               if (this.emptyPosition.x == 0) break;
               this.tileClick((Number(this.emptyPosition.x) - 1), (Number(this.emptyPosition.y)));
               i--;
               break;
            case 3: //right
               if (this.emptyPosition.x == Number(this.cols) - 1) break;
               this.tileClick((Number(this.emptyPosition.x) + 1), (Number(this.emptyPosition.y)));
               i--;
               break;
         }
      }
   }

   solve() {
      this.grids.push(new BoardState(this.spaces, [], this.emptyPosition, "", []));
      // console.log(this.grids[0]);
      // while (this.grids[0].heuristic != 0) {
      for (let t = 0; this.grids[0].heuristic != 0; t++) {

         this.grids.push(...this.grids[0].makeMoves());
         this.grids.splice(0, 1);
         this.grids.sort(compareBoardStates);
         // console.log(this.grids[0].heuristic);
         // console.log('t: ' + t);
      }
      console.log(this.grids[0]);
      preformSolve(this.grids[0].moves);


      //last bit
      this.grids = [];
   }

}



//this holds the state the board could be in for implementing my solve algorithem
class BoardState {
//   lastMove;
//   heuristic;
//   matrix;
//   emptyPosition = { x: 0, y: 0 };
//   pastMoves = [];

    constructor(arr, moves, empty, lastMove, pastMoves) {
      this.moves = [];
      this.up = true;
      this.down = true;
      this.left = true;
      this.right = true;
      this.pastMoves = pastMoves;
      this.lastMove = lastMove;
      this.matrix = arr.slice();
      this.moves = moves;
      this.emptyPosition = empty;
      this.heuristic = 0;

      if (empty.y == 0 || lastMove == "down") this.up = false;
      if (empty.y == arr.length - 1 || lastMove == "up") this.down = false;
      if (empty.x == 0 || lastMove == "right") this.left = false;
      if (empty.x == arr[0].length - 1 || lastMove == "left") this.right = false;
      this.calcHeuristic();
   }

   calcHeuristic() {
      for (let i = 0; i < this.matrix.length; i++) {
         for (let j = 0; j < this.matrix[i].length; j++) {
            let aPos;
            if (this.matrix[i][j] == "") {
               continue;
               aPos = myGame.answerMap[this.matrix.length * this.matrix[i].length];
            }
            else {
               aPos = myGame.answerMap[this.matrix[i][j]];
            }
            this.heuristic += Math.abs(aPos.x - i);
            this.heuristic += Math.abs(aPos.y - j);
         }
      }
   }

   makeMoves() {
      let replacementStates = [];
      if (this.up) {
         let tmpArray = [...copy2DArray(this.matrix)];
         tmpArray[this.emptyPosition.x][this.emptyPosition.y] = tmpArray[this.emptyPosition.x][this.emptyPosition.y - 1];
         tmpArray[this.emptyPosition.x][this.emptyPosition.y - 1] = "";
         if (!matrixInPast(tmpArray, this.pastMoves))
            replacementStates.push(new BoardState(tmpArray, [...this.moves, "up"], { x: this.emptyPosition.x, y: this.emptyPosition.y - 1 }, "up", [...copy3DArray(this.pastMoves), copy2DArray(this.matrix)]));
      }
      if (this.down) {
         let tmpArray = copy2DArray(this.matrix);
         tmpArray[this.emptyPosition.x][this.emptyPosition.y] = tmpArray[this.emptyPosition.x][this.emptyPosition.y + 1];
         tmpArray[this.emptyPosition.x][this.emptyPosition.y + 1] = "";
         if (!matrixInPast(tmpArray, this.pastMoves))
            replacementStates.push(new BoardState(tmpArray, [...this.moves, "down"], { x: this.emptyPosition.x, y: this.emptyPosition.y + 1 }, "down", [...copy3DArray(this.pastMoves), copy2DArray(this.matrix)]));
      }
      if (this.right) {
         let tmpArray = copy2DArray(this.matrix);
         tmpArray[this.emptyPosition.x][this.emptyPosition.y] = tmpArray[this.emptyPosition.x + 1][this.emptyPosition.y];
         tmpArray[this.emptyPosition.x + 1][this.emptyPosition.y] = "";
         if (!matrixInPast(tmpArray, this.pastMoves))
            replacementStates.push(new BoardState(tmpArray, [...this.moves, "right"], { x: this.emptyPosition.x + 1, y: this.emptyPosition.y }, "right", [...copy3DArray(this.pastMoves), copy2DArray(this.matrix)]));
      }
      if (this.left) {
         let tmpArray = copy2DArray(this.matrix);
         tmpArray[this.emptyPosition.x][this.emptyPosition.y] = tmpArray[this.emptyPosition.x - 1][this.emptyPosition.y];
         tmpArray[this.emptyPosition.x - 1][this.emptyPosition.y] = "";
         if (!matrixInPast(tmpArray, this.pastMoves))
            replacementStates.push(new BoardState(tmpArray, [...this.moves, "left"], { x: this.emptyPosition.x - 1, y: this.emptyPosition.y }, "left", [...copy3DArray(this.pastMoves), copy2DArray(this.matrix)]));
      }
      return replacementStates;
   }
}

const copy2DArray = (arr) => {
   let tmp = Array(arr.length);
   for (let i = 0; i < arr.length; i++) {
      tmp[i] = Array(arr[i].length);
      for (let j = 0; j < arr[i].length; j++) {
         tmp[i][j] = arr[i][j];
      }
   }
   return tmp;
}
const copy3DArray = (arr) => {
   let tmp = Array(arr.length);
   for (let i = 0; i < arr.length; i++) {
      tmp[i] = Array(arr[i].length);
      for (let j = 0; j < arr[i].length; j++) {
         tmp[i][j] = Array(arr[i][j].length);
         for (let k = 0; k < arr[i][j].length; k++)
            tmp[i][j][k] = arr[i][j][k];
      }
   }
   return tmp;
}

const matrixInPast = (matrix, past) => {
   for (let i = 0; i < past.length; i++) {
      let check = true;
      for (let j = 0; j < past[i]; j++) {
         for (let k = 0; k < past[j]; k++) {
            if (past[i][j][k] != matrix[j][k]) check = false;
         }
         if (!check) break;
      }
   }
   return false;
}

//used to sort my array of board states to find wich one should be evaluated next
const compareBoardStates = (a, b) => {
   if (a.heuristic + a.moves.length > b.heuristic + b.moves.length) return 1;
   if (b.heuristic + b.moves.length > a.heuristic + a.moves.length) return -1;
   // if (a.heuristic > b.heuristic) return 1;
   // if (b.heuristic > a.heuristic) return -1;
   // if (a.movesCount > b.movesCount) return 1;
   // if (b.movesCount > a.movesCount) return -1;
   return 0;
}

//this shuffels a 2D array but I don't ever use this
const shuffleArray = (twoDimArray) => {
   let count = 0;
   let array = Array(twoDimArray.length * twoDimArray[0].length);
   for (let i = 0; i < twoDimArray.length; i++) {
      for (let j = 0; j < twoDimArray[i].length; j++) {
         array[count] = twoDimArray[i][j];
         count++;
      }
   }

   let currentIndex = array.length, temporaryValue, randomIndex;

   while (0 !== currentIndex) {

      randomIndex = Math.floor(Math.random() * currentIndex);
      currentIndex -= 1;

      temporaryValue = array[currentIndex];
      array[currentIndex] = array[randomIndex];
      array[randomIndex] = temporaryValue;
   }

   count = 0;
   for (let i = 0; i < twoDimArray.length; i++) {
      for (let j = 0; j < twoDimArray[i].length; j++) {
         twoDimArray[i][j] = array[count];
         count++;
      }
   }
   return twoDimArray;
}

const preformSolve = (moves) => {
   for (let i = 0; i < moves.length; i++){
      setTimeout(() => {
         switch (moves[i]) {
            case "up":
               myGame.tileClick(myGame.emptyPosition.x, myGame.emptyPosition.y - 1);
               break;
            case "down":
               myGame.tileClick(myGame.emptyPosition.x, myGame.emptyPosition.y + 1);
               break;
            case "right":
               myGame.tileClick(myGame.emptyPosition.x + 1, myGame.emptyPosition.y);
               break;
            case "left":
               myGame.tileClick(myGame.emptyPosition.x - 1, myGame.emptyPosition.y);
               break;
         }
      }, i*500);
   }
}


const myOnload = () => {
   let columns = document.getElementById('columnsSelector');
   let rows = document.getElementById('rowsSelector');
   columns.value = 4;
   rows.value = 4;
   startGame();
}

const startGame = () => {
   let columns = document.getElementById('columnsSelector');
   let rows = document.getElementById('rowsSelector');
   if (columns.value < 1) columns.value = 1
   if (rows.value < 1) rows.value = 1

   myGame = new Game(Number(columns.value), Number(rows.value));
}
