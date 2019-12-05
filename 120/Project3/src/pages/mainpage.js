import React from 'react';
import PokeCard from "../components/pokeCard";
import { Button, Row } from "reactstrap";

const MainPage = (props) => {
   let pokemon = JSON.parse(localStorage['pokemon'])
   // console.log(localStorage['pokemon'])
   let cards = [<PokeCard name={"t"}></PokeCard>];
   for (let i = 0; i < pokemon.count; i++) {
      cards.push(<PokeCard name={pokemon.results[i]}></PokeCard>);
   }
   // const ccs = [(<PokeCard name="name"></PokeCard>), <PokeCard name="name"></PokeCard>];

   console.log(props);
   return (
      <>
         {cards}
         <Row><Button>Back</Button><Button>Next</Button></Row>
      </>);
}


export default MainPage;