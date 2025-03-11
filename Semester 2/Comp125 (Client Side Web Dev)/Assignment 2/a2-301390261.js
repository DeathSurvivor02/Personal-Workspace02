document.getElementById("create_table").addEventListener("click", (e) => {
	e.preventDefault(); // Prevent form submission
  
	let rows = parseInt(document.getElementById("Rows").value);
	let columns = parseInt(document.getElementById("Columns").value);
  
	// Build the entire table as a string before updating innerHTML
	let tableHTML = "<table border='1'>";
  
	for (let i = 0; i < rows; i++) {
	  tableHTML += "<tr>";
  
	  for (let j = 0; j < columns; j++) {
		tableHTML += "<td>" + ((i + 1) * (j + 1)) + "</td>";
	  }
  
	  tableHTML += "</tr>";
	}
  
	tableHTML += "</table>";

	// Set the final table in one go
	document.getElementById("tableContainer").innerHTML = tableHTML;
});
