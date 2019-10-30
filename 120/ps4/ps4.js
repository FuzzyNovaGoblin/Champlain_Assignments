const cashRegister = (cart) => {
   let total = 0;
   let items = Object.values(cart);
   for (let i = 0; i < items.length; i++){
      total += Number(items[i]);
   }
   return total;
}

const validateCreditCard = (cardNumber) => {
   cardNumber = cardNumber.toString();
   let cardNumberArr = cardNumber.split("");

   if (cardNumber.length != 16) return false;

   let differentVals = false;
   let sum = 0;

   for (let i = 0; i < 16; i++){
      if (cardNumber.charCodeAt(i) < 48 || cardNumber.charCodeAt(i) > 57) return false;

      cardNumberArr[i] = Number(cardNumberArr[i]);

      if (cardNumberArr[i] != cardNumberArr[0]) differentVals = true;

      sum += cardNumberArr[i];
   }

   if (cardNumberArr[15] % 2 != 0 || !differentVals || sum < 16) return false;

   return true;
}