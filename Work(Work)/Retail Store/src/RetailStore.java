import java.util.Random;

public class RetailStore
{
	Random rand = new Random();
	public final int DEFAULT_TOTAL_ITERATIONS = 50;
	Customer[] customer = new Customer[200];
	Items Chairs = new Items() ;
	Items Stoves = new Items() ;
	Items Fridges = new Items() ;
	Items Tables = new Items() ;
	Store store = new Store() ;
	private int totalIterations;
	int RemainingStoves = 100;
	int RemainingFridges = 500;
	int RemainingTables = 200;
	int RemainingChairs = 400;
	int finalPrice;
	
	public RetailStore()
	{
		totalIterations = DEFAULT_TOTAL_ITERATIONS;
	}
	
	public void run()
	{
		for(int i = 0; i < totalIterations; i++){
			// perform simulation actions.

			for (int j = 0; j< 200; j++)
			{
				customer[j] = new Customer();
				customer[j].setCustomerName("Customer"+i);
				// check to see if getTotalBought is larger than Item
				int bought = customer[j].getTotalBought();
				double chairCost = Chairs.getCost(); 
				double tableCost = Tables.getCost();
				double frightCost = Fridges.getCost();
				double stoveCost = Stoves.getCost();
				
				if (customer[j].Member == false && (bought * 4) < 10 )
				{

				
					if(bought < RemainingChairs )
					{
						finalPrice += bought*chairCost; 
					}
					else if (bought > RemainingChairs && RemainingChairs != 0)
					{
						finalPrice += bought * chairCost;
					}
					else 
					{
						finalPrice += 0;
					}

					if(bought < RemainingTables )
					{
						finalPrice += bought*tableCost; 
					}
					else if (bought > RemainingTables && RemainingTables != 0)
					{
						finalPrice += bought * tableCost;
					}
					else 
					{
						finalPrice += 0;
					}

					if(bought < RemainingStoves )
					{
						finalPrice += bought*stoveCost; 
					}
					else if (bought > RemainingStoves && RemainingStoves != 0)
					{
						finalPrice += bought * stoveCost;
					}
					else 
					{
						finalPrice += 0;
					}

					if(bought < RemainingFridges )
					{
						finalPrice += bought*frightCost; 
					}
					else if (bought > RemainingFridges && RemainingFridges != 0)
					{
						finalPrice += bought * frightCost;
					}
					else 
					{
						finalPrice += 0;
					}
				}
				else 
				{
					if(bought < RemainingChairs )
					{
						finalPrice += bought*chairCost -  Chairs.getDiscountValue(); 
					}
					else if (bought > RemainingChairs && RemainingChairs != 0)
					{
						finalPrice += bought * chairCost - Chairs.getDiscountValue();
					}
					else 
					{
						finalPrice += 0;
					}

					if(bought < RemainingTables )
					{
						finalPrice += bought*tableCost -  Tables.getDiscountValue(); 
					}
					else if (bought > RemainingTables && RemainingTables != 0)
					{
						finalPrice += bought * tableCost -  Tables.getDiscountValue();
					}
					else 
					{
						finalPrice += 0;
					}

					if(bought < RemainingStoves )
					{
						finalPrice += bought*stoveCost -  Stoves.getDiscountValue(); 
					}
					else if (bought > RemainingStoves && RemainingStoves != 0)
					{
						finalPrice += bought * stoveCost -  Stoves.getDiscountValue() ;
					}
					else 
					{
						finalPrice += 0;
					}

					if(bought < RemainingFridges )
					{
						finalPrice += bought*frightCost -  Fridges.getDiscountValue(); 
					}
					else if (bought > RemainingFridges && RemainingFridges != 0)
					{
						finalPrice += bought * frightCost -  Fridges.getDiscountValue();
					}
					else 
					{
						finalPrice += 0;
					}
				}
				if (finalPrice > customer[j].budget)
				{
					break;
				}
				else 
				{
					customer[j].budget -= finalPrice;
				}
				Stoves.totalStoves -= bought;
				Tables.totalTables -= bought;
				Fridges.totalFridges -= bought;
				Chairs.totalChairs -= bought;

				store.totalItemsSold += (bought * 4);
				store.moneyMade += finalPrice;

			}
		}
		if (Stoves.totalStoves == 0)
		{
			Stoves.totalStoves = rand.nextInt(500)+100;
		}
		if (Tables.totalTables == 0)
		{
			Tables.totalTables = rand.nextInt(500)+100;
		}
		if (Chairs.totalChairs == 0)
		{
			Chairs.totalChairs = rand.nextInt(500)+100;
		}
		if (Fridges.totalFridges == 0)
		{
			Fridges.totalFridges = rand.nextInt(500)+100;
		}
		System.out.println("Total items bought "+(Fridges.totalFridges+Chairs.totalChairs+Tables.totalTables+Stoves.totalStoves));
		System.out.println("Total amount of money made "+ finalPrice );
	}

	public void setTotalIterations( int value )
	{
		if( value > 0 )
			totalIterations = value;
	}
}