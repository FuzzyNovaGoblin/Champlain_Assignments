const getRates = (base) => {
   fetch('https://api.exchangeratesapi.io/latest?base=' + base)
      .then(res => res.json())
      .then(data => {
         let exchanges = document.getElementById('exchanges');
         let exchangeList = '';
         for (let [key, value] of Object.entries(data.rates)) {
            exchangeList += `<li>${key}: ${value}</li>`
         }
         let rate = data.rates;
         exchanges.innerHTML = exchangeList;
      })
}

window.onload = () => {
   console.log('here')
   const curencySelector = document.getElementById('currencySelect');
   curencySelector.addEventListener('change', event => {
      console.log("here");
      const newCurrency = event.target.value;
      getRates(newCurrency);
   })
}