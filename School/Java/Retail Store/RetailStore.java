

public class RetailStore {
	public final int DEFAULT_TOTAL_ITERATIONS = 50;

	private int totalIterations;
	
	public RetailStore()
	{
		totalIterations = DEFAULT_TOTAL_ITERATIONS;
	}
	
	public void run()
	{
		for(int i = 0; i < totalIterations; i++){
			// perform simulation actions.
		}
	}

	public void setTotalIterations( int value )
	{
		if( value > 0 )
			totalIterations = value;
	}

	
}
