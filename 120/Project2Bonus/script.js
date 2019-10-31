
let myGame = null;

class Game {
   currentPlayer;
   spaces;
   won;

   constructor() {
      this.currentPlayer = 'x';
      this.won = false;
      this.spaces = [
         ["null", "null", "null"],
         ["null", "null", "null"],
         ["null", "null", "null"]
      ];
   }


   tileClick = (x, y) => {
      if (!this.won) {
         if (this.spaces[x][y] == "null") {
            console.log("here");
            this.spaces[x][y] = this.currentPlayer;
            this.currentPlayer = (this.currentPlayer == 'x') ? 'o' : 'x';
            rebuildBoard();
         }
         this.checkWin();
      }
   }

   checkWin = () => {
      for (let i = 0; i < 3; i++) {
         if (this.spaces[i][0] != "null" && this.spaces[i][0] == this.spaces[i][1] && this.spaces[i][0] == this.spaces[i][2]) {
            this.win(this.spaces[i][0]);
            return;
         }
         else if (this.spaces[0][i] != "null" && this.spaces[0][i] == this.spaces[1][i] && this.spaces[0][i] == this.spaces[2][i]) {
            this.win(this.spaces[0][i]);
            return;
         }
      }
      if (this.spaces[0][0] != "null" && this.spaces[0][0] == this.spaces[1][1] && this.spaces[0][0] == this.spaces[2][2]) {
         this.win(this.spaces[0][0]);
         return;
      }
      else if (this.spaces[2][0] != "null" && this.spaces[2][0] == this.spaces[1][1] && this.spaces[2][0] == this.spaces[0][2]) {
         this.win(this.spaces[0][0]);
         return;
      }

      for (let i = 0; i < 3; i++) {
         for (let j = 0; j < 3; j++) {
            if (this.spaces[i][j] == "null") {
               return;
            }
         }
      }
      this.win("null");
   }

   win = (who) => {
      this.won = true;
      if (who == "null") {
         let boardHolder = document.getElementById('gameHolder');
         boardHolder.innerHTML = `
             <div class="row">
               <div class=col></div>
               <div class="col-md-auto">
                  <img class="img-fluid" id="curentPlayer" src="draw.png"></img>
               </div>
               <div class=col></div>
            </div>

             <div class="row">
         <div class=col></div>
         <div class="col">
            <table>
               <tr>
                  <td class="" onclick="myGame.tileClick(0,0)"><img class="img-fluid" id="00" src="${myGame.spaces[0][0]}.png"></img>
                  </td>
                  <td class="vert " onclick="myGame.tileClick(0,1)"><img class="img-fluid" id="01" src="${myGame.spaces[0][1]}.png"></img>
                  </td>
                  <td class=" " onclick="myGame.tileClick(0,2)"><img class="img-fluid" id="02" src="${myGame.spaces[0][2]}.png"></img>
                  </td>
               </tr>
               <tr>
                  <td class=" hor" onclick="myGame.tileClick(1,0)"><img class="img-fluid" id="10" src="${myGame.spaces[1][0]}.png"></img>
                  </td>
                  <td class="vert hor" onclick="myGame.tileClick(1,1)"><img class="img-fluid" id="11" src="${myGame.spaces[1][1]}.png"></img>
                  </td>
                  <td class=" hor" onclick="myGame.tileClick(1,2)"><img class="img-fluid" id="12" src="${myGame.spaces[1][2]}.png"></img>
                  </td>
               </tr>
               <tr>
                  <td class="" onclick="myGame.tileClick(2,0)"><img class="img-fluid" id="20" src="${myGame.spaces[2][0]}.png"></img>
                  </td>
                  <td class="vert" onclick="myGame.tileClick(2,1)"><img class="img-fluid" id="21" src="${myGame.spaces[2][1]}.png"></img>
                  </td>
                  <td class="" onclick="myGame.tileClick(2,2)"><img class="img-fluid" id="22" src="${myGame.spaces[2][2]}.png"></img>
                  </td>
               </tr>
            </table>
         </div>
         <div class=col></div>
      </div>
            `;
      }
      else {
         let boardHolder = document.getElementById('gameHolder');
         boardHolder.innerHTML = `
            <div class="container container-fluid">
               <div class="row justify-content-center">
                  <div>
                     <p>Winner!</p>
                     <img class="img-fluid"src="${who}.png" width=200></img>
                  </div>
               </div>
            </div>

             <div class="row">
         <div class=col></div>
         <div class="col">
            <table>
               <tr>
                  <td class="" onclick="myGame.tileClick(0,0)"><img class="img-fluid" id="00" src="${myGame.spaces[0][0]}.png"></img>
                  </td>
                  <td class="vert " onclick="myGame.tileClick(0,1)"><img class="img-fluid" id="01" src="${myGame.spaces[0][1]}.png"></img>
                  </td>
                  <td class=" " onclick="myGame.tileClick(0,2)"><img class="img-fluid" id="02" src="${myGame.spaces[0][2]}.png"></img>
                  </td>
               </tr>
               <tr>
                  <td class=" hor" onclick="myGame.tileClick(1,0)"><img class="img-fluid" id="10" src="${myGame.spaces[1][0]}.png"></img>
                  </td>
                  <td class="vert hor" onclick="myGame.tileClick(1,1)"><img class="img-fluid" id="11" src="${myGame.spaces[1][1]}.png"></img>
                  </td>
                  <td class=" hor" onclick="myGame.tileClick(1,2)"><img class="img-fluid" id="12" src="${myGame.spaces[1][2]}.png"></img>
                  </td>
               </tr>
               <tr>
                  <td class="" onclick="myGame.tileClick(2,0)"><img class="img-fluid" id="20" src="${myGame.spaces[2][0]}.png"></img>
                  </td>
                  <td class="vert" onclick="myGame.tileClick(2,1)"><img class="img-fluid" id="21" src="${myGame.spaces[2][1]}.png"></img>
                  </td>
                  <td class="" onclick="myGame.tileClick(2,2)"><img class="img-fluid" id="22" src="${myGame.spaces[2][2]}.png"></img>
                  </td>
               </tr>
            </table>
         </div>
         <div class=col></div>
      </div>
             `;
      }
   }
}



const myOnload = () => {
   myGame = new Game();
   rebuildBoard();
}


const rebuildBoard = () => {
   let boardHolder = document.getElementById('gameHolder');
   boardHolder.innerHTML = `
      <div class="container container-fluid">
         <div class="row justify-content-center">
            <div>
               <p>Curent Player</p>
               <img class="img-fluid" id="curentPlayer" src="${myGame.currentPlayer}.png"></img>
               <hr/>
            </div>
         </div>
      </div>

      <div class="row">
         <div class=col></div>
         <div class="col">
            <table>
               <tr>
                  <td class="" onclick="myGame.tileClick(0,0)"><img class="img-fluid" id="00" src="${myGame.spaces[0][0]}.png"></img>
                  </td>
                  <td class="vert " onclick="myGame.tileClick(0,1)"><img class="img-fluid" id="01" src="${myGame.spaces[0][1]}.png"></img>
                  </td>
                  <td class=" " onclick="myGame.tileClick(0,2)"><img class="img-fluid" id="02" src="${myGame.spaces[0][2]}.png"></img>
                  </td>
               </tr>
               <tr>
                  <td class=" hor" onclick="myGame.tileClick(1,0)"><img class="img-fluid" id="10" src="${myGame.spaces[1][0]}.png"></img>
                  </td>
                  <td class="vert hor" onclick="myGame.tileClick(1,1)"><img class="img-fluid" id="11" src="${myGame.spaces[1][1]}.png"></img>
                  </td>
                  <td class=" hor" onclick="myGame.tileClick(1,2)"><img class="img-fluid" id="12" src="${myGame.spaces[1][2]}.png"></img>
                  </td>
               </tr>
               <tr>
                  <td class="" onclick="myGame.tileClick(2,0)"><img class="img-fluid" id="20" src="${myGame.spaces[2][0]}.png"></img>
                  </td>
                  <td class="vert" onclick="myGame.tileClick(2,1)"><img class="img-fluid" id="21" src="${myGame.spaces[2][1]}.png"></img>
                  </td>
                  <td class="" onclick="myGame.tileClick(2,2)"><img class="img-fluid" id="22" src="${myGame.spaces[2][2]}.png"></img>
                  </td>
               </tr>
            </table>
         </div>
         <div class=col></div>
      </div>
   `;
}