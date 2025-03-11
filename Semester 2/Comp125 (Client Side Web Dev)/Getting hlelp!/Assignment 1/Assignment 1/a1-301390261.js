document.getElementById("myButton").addEventListener('click', e=>{
 //!change the variables to lower case
    let Bal = document.getElementById("Bal").value;
    let Inter = document.getElementById("Int").value;
    let Yrs = document.getElementById("Yrs").value;

   let percent = Inter / 100
   let TotalInterest = Bal * percent
   let IntBal = Bal * percent * Yrs
// todo:

    document.getElementById("TotalInterest").innerHTML = "$" + TotalInterest.toFixed(2) 
    document.getElementById("TotalBalance").innerHTML = "$" + IntBal.toFixed(2) 
});

// document.getElementById("