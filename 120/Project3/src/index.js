import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import * as serviceWorker from './serviceWorker';
import 'bootstrap/dist/css/bootstrap.min.css';
import MainPage from "./pages/mainpage.js";
import App from "./App.js";




ReactDOM.render(<App />, document.getElementById('root'));


if (typeof (localStorage['pokemon']) != typeof ({})) {
   localStorage['pokemon'] = "NO DATA";
   fetch("https://pokeapi.co/api/v2/pokemon?limit=965")
      .then((data) => data.json())
      .then((data) => {
         localStorage.setItem('pokemon', JSON.stringify(data));
         // this.setState({ pokemon: JSON.parse(localStorage['pokemon'])});
      })
   .then(() => ReactDOM.render(<MainPage />, document.getElementById('root')))
}



// If you want your app to work offline and load faster, you can change
// unregister() to register() below. Note this comes with some pitfalls.
// Learn more about service workers: https://bit.ly/CRA-PWA
serviceWorker.unregister();
