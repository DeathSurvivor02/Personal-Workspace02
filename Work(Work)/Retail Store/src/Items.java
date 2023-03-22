/* 
class: Items
Generic term that refers to items for sale
*/

import java.util.Random;

public class Items
{
	double cost;
	double discountValue;
	int totalAmount;

	
	Random rand = new Random();

	public int totalStoves = 100;
	public int totalFridges = 500;
	public int totalTables = 200;;
	public int totalChairs = 400;

// set functions
	void setCost(double amount)
	{
		this.cost = amount;
	}
	void setDiscountValue(double amount)
	{
		this.discountValue = amount;
	}
	void setTotalAmount(int amount)
	{
		this.totalAmount = amount;
	}

// get functions

	double getCost()
	{
		return cost;
	}
	double getDiscountValue()
	{
		return discountValue;
	}
	int getTotalAmount()
	{
		return totalAmount;
	}


	// Items constructor
	Items()
	{
		setCost(rand.nextInt(50)+50);
		setDiscountValue(rand.nextDouble(5.0)+5.0);
	}
	




}