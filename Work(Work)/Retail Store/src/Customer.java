/* 
class: Customer
Represents a customer

*/


import java.util.Random;
public class Customer
{
	String customerName;
	double budget;
	Random rand = new Random(963852741);
	boolean Member;
	int totalBought;


	Customer[] customer;

	// set functions

	void setCustomerName(String name)
	{
		customerName = name;
	}
	void setBudget(double amount)
	{
		this.budget = amount;
	}	
	void setMember(boolean result)
	{
		this.Member = result;
	}
	void setTotalBought(int amount)
	{
		this.totalBought = amount;
	}

	// get functions
	String getCustomerName()
	{
		return customerName;
	}
	double getBudget()
	{
		return budget;
	}
	boolean getMember()
	{
		return Member;
	}
	int getTotalBought()
	{
		return totalBought;
	}

	// Customer constructor
	Customer()
	{
		
		setBudget(rand.nextInt(4000)+1000);
		setMember(rand.nextBoolean());
		setTotalBought(rand.nextInt(20));
	}


	

	// Customer Customer =  new Customer();


}