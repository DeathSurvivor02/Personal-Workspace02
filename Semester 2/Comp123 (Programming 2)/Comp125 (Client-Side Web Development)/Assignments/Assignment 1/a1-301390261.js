document.getElementById("CalcButn").addEventListener("click", calculateInterest);

function calculateInterest() {
  //Description: Retrieve input values
	const iniBal = parseFloat(document.getElementById("IniBal").value);
	const intRate = parseFloat(document.getElementById("IntRate").value);
	const period = parseFloat(document.getElementById("Period").value);

  // Description: Validate input
	if (isNan(iniBal) || isNaN(intRate) || isNaN(period)) 
	{
    	document.getElementById("output").textContent = "Enter a valid number";
    	return;
	}

  // Description: Calculate simple interest
  const simInt = (iniBal * intRate * period) / 100;
  const finBal = iniBal + simInt;

  //Description: shows the results
  document.getElementById("output").textContent = `Simple Interest: ${simInt.toFixed(2)}\nFinal Balance: ${finBal.toFixed(2)}`;
}
