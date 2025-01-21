// Function to calculate interest and display results
document.getElementById('calculate-button').addEventListener('click', function () {
	// Input values
	const initialBalance = parseFloat(document.getElementById('IniBal').value);
	const interestRate = parseFloat(document.getElementById('IntRate').value);
	const period = parseFloat(document.getElementById('Period').value);
	const currency = document.querySelector('input[name="currency"]:checked')?.value;

	// Validate inputs
	if (isNaN(initialBalance) || isNaN(interestRate) || isNaN(period) || !currency) {
		alert("Please fill in all fields correctly.");
		return;
	}

	// Calculations
	const totalInterest = (initialBalance * interestRate * period) / 100; // Simple interest
	const finalBalance = initialBalance + totalInterest;

	// Display results
	document.getElementById('total-interest').textContent = `Total Interest (Simple): ${totalInterest.toFixed(2)} ${currency}`;
	document.getElementById('final-balance').textContent = `Final Balance: ${finalBalance.toFixed(2)} ${currency}`;
});
