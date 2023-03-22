public class Store {
	// declared variables
	int totalNumberOfItemsSold;
	int totalMoneyOfItemsSold;
	int totalItemsSold;
	int[] Customer;	
	
	Store() //function: constructor  for the store class
	{

		totalNumberOfItemsSold = 0;
		totalMoneyOfItemsSold = 0;
		totalItemsSold = 0; 
		for(int i =0; i < 200; i++){
			Customer[i] = new Customer();
	}
}