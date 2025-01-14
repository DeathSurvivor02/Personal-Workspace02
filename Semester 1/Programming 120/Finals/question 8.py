def calculate_pay(hours_worked, hourly_rate):
	# Calculate gross pay
	gross_pay = hours_worked * hourly_rate
	
	# Calculate tax deduction (10% of gross pay)
	tax_deduction = gross_pay * 0.10
	
	# Calculate net pay
	net_pay = gross_pay - tax_deduction
	
	return gross_pay, net_pay

def main():
	# Input hours worked and hourly rate
	hours_worked = float(input("Enter hours worked: "))
	hourly_rate = float(input("Enter hourly rate: "))
	
	# Calculate gross and net pay
	gross_pay, net_pay = calculate_pay(hours_worked, hourly_rate)
	
	# Display the results
	print(f"Gross Pay: ${gross_pay:.2f}")
	print(f"Net Pay: ${net_pay:.2f}")

if __name__ == "__main__":
	main()