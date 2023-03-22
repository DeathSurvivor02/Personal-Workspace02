/* 
class: Store 
Represents the retail store being simulated. 

*/

public class Store
{
	int totalItemsSold;
	double moneyMade;
	int totalAmount;

	// set functions:
		void setTotalItemsSold(int amount)
		{
			this.totalItemsSold = amount;
		}
		void setMoneyMade(double amount)
		{
			this.moneyMade = amount;
		}
		void setTotalAmount(int amount)
		{
			this.totalAmount = amount;
		}

	// get functions:
		int getTotalItemsSold()
		{
			return totalItemsSold;
		}
		double getMoneyMade()
		{
			return moneyMade;
		}
	
		int getTotalAmount() {
			return totalAmount;
		}

	Store()
	{
		setTotalItemsSold(0);
		setMoneyMade(0);
		setTotalAmount(0);
	}
}


