import React from 'react';
import {
   Card,
   CardImg,
   CardText,
   CardBody,
   CardTitle,
   CardSubtitle,
   Button
} from 'reactstrap';


const PokeCard = (props) => {
   return (
      <Card>
         <CardBody>
            <CardTitle>
               {props.name}
            </CardTitle>
         </CardBody>
      </Card>
   );
}

export default PokeCard;