// import java.lang.reflect.GenericDeclaration;
import java.util.Random;
// package methods;
class ArrayData {
	
/* 	private int rows = 10;
	private int columns = 10;
	private int temp;
	private int grid[][];
	private float muRow;
	private float muCol;

	// private int sum;
	private double sigmaTotalRow;
	private double sigmaTotalCol;
	private int sumRow = 0;
	private int sumCol= 0;
	private double sigmaRow = 0.0f;
	private double sigmaCol = 0.0f;
	
	private int rowData[]; //todo
	private int colData[]; //todo
	 */
	  // functions

	  private int rows = 10;
	  private int columns = 10;
	  private int temp;
	  private int[][] grid;
	  private float muRow;
	  private float muCol;
	  private double sigmaTotalRow;
	  private double sigmaTotalCol;
	  private int sumRow = 0;
	  private int sumCol = 0;
	  private double sigmaRow = 0.0;
	  private double sigmaCol = 0.0;
	  
	  private int[] rowData;
	  private int[] colData;
	  
	  public ArrayData() {
		  genArrayData(10, 0);
	  }
  
	  public ArrayData(int size) {
		  genArrayData(size, 0);
	  }
  
	  public ArrayData(int size, int startingValue) {
		  genArrayData(size, startingValue);
	  }
  
	  public void reverse(int rowNum, int start) {
		  for (int i = start; i < columns / 2; i++) {
			  temp = grid[rowNum][i];
			  grid[rowNum][i] = grid[rowNum][columns - i - 1];
			  grid[rowNum][columns - i - 1] = temp;
		  }
	  }
  
	  public void genArrayData(int length, int initialize) {
		  rows = length;
		  columns = length;
		  grid = new int[rows][columns];
		  rowData = new int[rows];
		  colData = new int[columns];
		  for (int i = 0; i < rows; i++) {
			  for (int j = 0; j < columns; j++) {
				  grid[i][j] = initialize;
			  }
			  rowData[i] = initialize;
			  colData[i] = initialize;
		  }
	  }
  
	  public void populate(int newValue, int totalInstances) {
		  Random rand = new Random();
		  for (int i = 0; i < totalInstances; i++) {
			  grid[rand.nextInt(rows)][rand.nextInt(columns)] = newValue;
		  }
	  }


/* 	public ArrayData() 
	{
		genArrayData(10, 0);
	}

	public ArrayData(int size) 
	{
		genArrayData(size, 0);
	}

	public ArrayData(int size, int startingValue) {
	genArrayData(size, startingValue);
	}

	public void reverse(int rowNum, int start) 
	{
		for (int i = start; i < columns - 1; i++) 
		{
			temp = grid[rowNum][i];
			grid[rowNum][i] = grid[rowNum][columns - i];
			grid[rowNum][columns - i] = temp;
		}
	}

	public void genArrayData(int length, int initialize) 
	{
		rows = length;
		columns = length;
		for (int i = 0; i < rows; i++) 
		{
			for (int j = 0; j < columns; j++) {
			grid[i][j] = initialize;
		}
		rowData[i] = initialize;
		colData[i] = initialize;
		}
	}

	public void populate(int newValue, int totalInstanes)
	{
		Random rand = new Random();
		for (int i = 0; i < totalInstanes; i++)
		{
			grid[rand.nextInt(rows)][rand.nextInt(columns)] = newValue;
		}
	}

 */ 	public void sum(int inc) { 
	//checkover: make sure to ask sir if the inc is only for the row or both the row and column
		for (int i = 0; i < rows; i++) 
		{
			rowData[i] = 0;
			colData[i] = 0;
		}
		for (int i = 0; i < rows; i++) 
		{
			for (int j = 0; j < columns; j++) 
				{
					if (grid[i][j] % 2 == 0) 
					{
	    		    	rowData[i] += (inc * grid[i][j]);
					} 
					else {
						rowData[i] += grid[i][j];
					}
					if (grid[j][i] % 2 == 0) 
					{
						colData[i] = grid[j][i];
					} 
					else 
					{
						colData[i] += grid[j][i];
					}
				}
		}
	} 

	public void occurrence(int num) 
	{
		for (int i = 0; i < rows; i++) 
		{
			rowData[i] = 0;
		}
		for (int i = 0; i < rows; i++) 
		{
			for (int j = 0; j < columns; j++) 
			{
				if ((grid[i][j] % num == 0) && (grid[i][j] != 0))
				{
					rowData[i] += 1; 
				}
				if ((grid[j][i] % num == 0) && (grid[j][i] != 0))
				{
					colData[i] += 1; 
				}
			}
		}
	}

	public void standardDeviation()
	{
		Sigma(rows,columns);
		sigmaTotalRow = Deviation(rows);
		sigmaTotalCol = Deviation(columns);
	}

	public double Deviation (int position)
	{
		if (position == rows)
		{
			return java.lang.Math.sqrt(((sigmaRow) / (position -1)));
		}
		else
		{
			return java.lang.Math.sqrt(((sigmaCol) / (position - 1 )));
		}
	}
	
	public void Sigma(int rowPos,int colPos)
	{

		for (int i = 0;  i < rowPos; i++ )
		{
			for (int j = 0; j < colPos; j++)
			{
		
				sumRow += (grid[i][j] - muRow);
				sumCol += (grid[j][i]-  muCol);

			}

			
		}
		muRow = sumRow/rowPos; //average of the row
		muCol = sumCol/colPos; //average of the column
		for (int i = 0; i < rowPos; i++)
		{
			for (int j = 0; j < colPos; j++)
			{
				sigmaRow = sigmaRow + java.lang.Math.pow((grid[i][j] - muRow),2);
				sigmaCol = sigmaCol + java.lang.Math.pow((grid[j][i] - muCol),2);
			}
		}
		
	}
	public void swap(int rowNum1, int rowNum2) 
	{
		int temp;
		for (int i = 0; i < columns; i++)
		{
			temp = grid[rowNum1][i];
			grid[rowNum1][i] = grid[rowNum2][i];
			grid[rowNum2][i] = temp;
		}
	}
	public int product (int rowNum, int colNum)
	{
		//error
		//checkover the doocument to understand the problem more
	/* 	int rowValue;
		int colValue;
		for (int i = 0; i < row; i++)
		{
			rowValue = grid[rowNum][i];
		} */
		
		// IDEA: From ChatGPT
		
		if (rows > columns) 
		{
			rows = columns;
		}
		else if (columns > rows) 
		{
			columns = rows;
		}

		int result = 0;
		for (int i = 0; i < rows; i++) 
		{
			result += grid[rowNum][i] * grid[i][colNum];
		}
	
		return result;
	}

	public void print()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				System.out.println (grid[i][j] + " | ");
			}
			System.out.println (" || " + rowData[i]);
			System.out.println("\n");

		}
		for (int i = 0; i < rows; i++) 
		{
			System.out.println (colData + " | ");
		}
	}
	public void print (int rows, int columns)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				System.out.println (grid[i][j] +" | ");
			}
			System.out.println (" || " + rowData[i]);
			System.out.println("\n");

		}
		for (int i = 0; i < rows; i++) 
		{
			System.out.println (colData + " | ");
		}
	}

}


// Testing methods 

public class TestArrayData
{
	public static void main( String args[] )
	{	
		ArrayData s = new ArrayData();
		s.populate( 5, 10 );
		s.sum(10);
		s.print();
		s.product( 2, 4 );
		s.sum(6);
		s.print();
		s.occurrence( 2 );
		s.print();
		s.print( 4, 2 );
	} // main
} // TestArrayData
