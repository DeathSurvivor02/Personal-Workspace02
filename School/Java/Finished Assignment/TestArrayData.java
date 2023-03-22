

import java.util.Random; // Imports the random number generator function/method from

class ArrayData {
	
	//variable names
	private int rows = 10; // initial number for the rows
	private int columns = 10; // initial number for the columns
	private int temp; // temporary variable
	private int[][] grid; // declaration for the grid array

	
	private int[] rowData;
	private int[] colData;
	

	/** 
	 * @function ArrayData calls the function/method genArrayData  with the 2 variables passed through it which initializes the values of the row and column variables as well as the values of the rowData and colData arrays 
	 */
	public ArrayData() {
		genArrayData(10, 0); // calls the function genArrayData with 10 and 0 within the parameters
	}

	/**
	 * ArrayData(int size)  takes in a variable  called size then calls the function/method genArrayData with the size of the the array being used for the row and colum variables and  the default value of 0 given to the rowData and colData arrays
	 * 
	 * @param size: give the size of both the row and column 
	 */
	public ArrayData(int size) {
		genArrayData(size, 0); // calls the method/function genArrayData with size and 0 as the parameters
	}

	/**
	 * @function ArrayData(int size, int startingValue) : takes in 2 variables called size and starting value which is then used to initialize the rows and columns integers and then initializes the rowData and columnData arrays
	 *  @variables size : the number given to the rows and columns integers
	 *  @startingValue : the number given to the rowData and columnData arrays starting
	 */
	public ArrayData(int size, int startingValue) {
		genArrayData(size, startingValue); // calls the genArrayData method/function with the 2 varibales; size and startingValue as the parameters
	}

	/**
	 * @function reverse: takes in 2 variables  called rowNum and start which is then used to reverse a group of numbers after the 'start' variable within a specific row (rowNum)
	 *	@param start: this variable takes in the position of the first number that is to be 'reversed'
	 * 	@param rowNum : this variable takes in the position of the row to be reversed
	 * 
	 */




	public void reverse(int rowNum, int start) {
		for (int i = start; i < columns; i++) { // for loop to start the reversing of the specific row
			temp = grid[rowNum][i]; //stores the current variable able in the temp (temporary variable)
			grid[rowNum][i] = grid[rowNum][columns - i - 1]; //stores the last variable in the array that hasn't been reversed yet
			grid[rowNum][columns - i - 1] = temp; //stores the value of the temp (the first variable in the array) to the last unchanged variable

		}
	}


/**
 * @function genArrayData: This function declares the length of the row and column variables as well as call the 
 * @param length
 * @param initialize
 */

	public void genArrayData(int length, int initialize) {
		rows = length;
		columns = length;
		grid = new int[rows][columns];
		rowData = new int[rows];
		colData = new int[columns];
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) 
			{
				grid[i][j] = initialize;
			}
			rowData[i] = initialize;
			colData[i] = initialize;
		}
	}

	public void populate(int newValue, int totalInstances) 
	{
		Random rand = new Random(10);
		for (int i = 0; i < totalInstances; i++) 
		{
			grid[rand.nextInt(rows)][rand.nextInt(columns)] = newValue;
		}
	}

	public void sum(int inc) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (grid[i][j] % 2 == 0) {
					rowData[i] += inc * grid[i][j];
				} else {
					rowData[i] += grid[i][j];
				}
				if (grid[j][i] % 2 == 0) {
					colData[i] += inc * grid[j][i];
				} else {
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
	/**
	 *
	* @function: This method will calculate the standard deviation of the integers in each row and column.
	*/
	public void standardDeviation() 
	{
		int total = 0;
		double average = 0.0;
		double deviation = 0.0;
		for (int i = 0; i < rows; i++)
		{
			total = 0;
			for (int j = 0; j < columns; j++)
			{
				total += grid[i][j];
			}
			average = (double) total/(double) rows;
			for(int j = 0; j < columns; j++)
			{
				deviation = Math.sqrt((total * (((double)grid[i][j] - average) * ((double)grid[i][j] - average)))/rows-1);
				rowData[i] = (int)deviation;
				// System.out.print(rowData[i]);
			}
		}
	}

	/**
	 * @function: this function takes in two parameters and uses them to swap the location of two rows
	* @param rowNum1
	* @param rowNum2
	*/
	public void swap(int rowNum1, int rowNum2) 
	{
		int temp;
		for (int i = 0;i < columns;i++) 
		{ // this loops the function
			temp = grid[rowNum1][i]; //temp holds a value of the first row that is used
			grid[rowNum1][i] = grid[rowNum2][i]; // the second row value is placed into the first row value
			grid[rowNum2][i] = temp; //the value of temp (the first row value) is placed in to the second row value
		}
	}

	public int product(int rowNum, int colNum) 
	{
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
			System.out.print(grid[i][j] + " | ");
			}
			System.out.print(" || " + rowData[i]);
			System.out.print("\n");
		}
		for (int i = 0; i < rows; i++) 
		
		{
			System.out.print(colData[i] + " | ");
		}
	}

	public void print(int rows, int columns) 
	{
		for (int i = 0; i < rows; i++) 
		
		{
			for (int j = 0; j < columns; j++) 
				
			{
					System.out.print(grid[i][j] + " | ");
				}
			System.out.print(" || " + rowData[i]);
			System.out.print("\n");
		}
		for (int i = 0; i < rows; i++) 
		{
			System.out.print(colData[i] + " | ");
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
		s.print();
		s.standardDeviation();
		s.print();
	} // main
} // TestArrayData
