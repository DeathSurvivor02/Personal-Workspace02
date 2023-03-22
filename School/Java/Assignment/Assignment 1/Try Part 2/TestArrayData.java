/**
 * @file ArrayData
 * @author Ean Bynoe (eanbynoe@gmail.com)
 * @brief:
 * @version 1.3.5
 * @date 2022-10-05 07:36:28
 *
 * @copyright Copyright (c) 2023
 *
 */

//imports

// import java.util.Math;
import java.util.Random;

class ArrayData {

	private int rows; 
	private int columns;
	private int[][] grid;
	private int rowData[];
	private int colData[];
	private int temp;

	// private double sigmaRow;
	// private double sigmaCol;
	// private double sigmaTotalRow;
	// private double sigmaTotalCol;
	// private int sumRow;
	// private int sumCol;
	// private float muRow;
	// private float muCol;

  //genArray Function Missing

	public void genArrayData(int length, int initialize) 
	{
		rows = length;
		columns = length;
		grid[rows][columns] = 0;
		rowData = new int[rows];
		colData = new int[columns];
    	genDataArray(initialize); //calls the genDataArray function to  initialize the values within the rowData and columnData arrays
	}

	//genDataArray Function Missing place where the data is initialized to zero

	public void genDataArray(int initialValue) 
	{
		for (int i = 0; i < rows; i++) 
		{
			rowData[i] = initialValue;
		}
		for (int i = 0; i < columns; i++) 
		{
			colData[i] = initialValue;
		}
	}

	public ArrayData() 
	{
		rows = 10;
		columns = 10;

		for (int i = 0; i < rows; i++) 
		{
			for (int j = 0; j < columns; j++) 
			{
				grid[i][j] = 0;
			}
			genDataArray(0);
		}
	}

	public ArrayData(int size) 
	{
		rows = size;
		for (int i = 0; i < rows; i++) 
		{
			for (int j = 0; j < columns; j++) 
			{
				grid[i][j] = 0;
			}
		}
		genDataArray(0);
	}

	public ArrayData(int size, int startingValue) 
	{
		rows = size;
		columns = size;
		for (int i = 0; i < rows; i++) 
		{
			for (int j = 0; j < columns; j++) 
			{
				grid[i][j] = startingValue;
			}
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

	public void reverse(int rowNum, int start) 
	{
		for (int i = start; i < columns / 2; i++) 
		{
			temp = grid[rowNum][i];
			grid[rowNum][i] = grid[rowNum][columns - i - 1];
			grid[rowNum][columns - i - 1] = temp;
		}
	}

	public void sum(int inc) 
	{
		for (int i = 0; i < rows; i++) 
		{
			genDataArray(0);
			for (int j = 0; j < columns; j++) 
			{
				if (grid[i][j] % 2 == 0) 
				{
					rowData[i] += inc * grid[i][j];
				} 
				else 
				{
					rowData[i] += grid[i][j];
				}
				if (grid[j][i] % 2 == 0) 
				{
					colData[i] += inc * grid[j][i];
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
	
		genDataArray(0);
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
				deviation = Math.sqrt((total * ((grid[i][j] - average) * (grid[i][j] - average)))/rows-1);
				rowData[i] = (int)deviation;
				// System.out.print(rowData[i]);
			}
		}
	}



	/**
	 * @function swap: this function takes in two parameters and uses them to swap the location of two rows
	* @param rowNum1 : position of the first row
	* @param rowNum2 : position of the second row
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



	/**
	 * @function prodcut: finds the product of a row and column by taking in the location of the row and the location of the column 
	 * @param rowNum
	 * @param colNum
	 * @return returns the result of the product
	 */

	public int product(int rowNum, int colNum) 
	{

		int result = 0; //contains the result of the product
		// checks to see if the columns and rows variables are the same size and changes the bigger value to the smaller one
		if (rows > columns) 
		{
			rows = columns;
		} 
		else if (columns > rows) 
		{
			columns = rows;
		}

		for (int i = 0; i < rows; i++) //loops the amount of times for the rows/columns to find the total 
		{
			result += grid[rowNum][i] * grid[i][colNum]; //adds the value in the row * column and result
		}

		return result;
	}



/**
 * @function print: this function prints the grid 
 * 
 * 
 */
	public void print() 
	{
		for (int i = 0; i < rows; i++) //loops the amount of times for the rows
		
		{
			for (int j = 0; j < columns; j++) //loops the amount of times for the columns 
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

	/**
	 * @function print: this function takes in two parameters and uses them to print the total amount of rows and columns
	 * @param rows : uses the values for the number of rows
	 * @param columns : uses the values for the number of columns
	 */

	
	public void print(int rows, int columns) 
	{
		for (int i = 0; i < rows; i++) //loops the amount of times for the rows
		{
			for (int j = 0; j < columns; j++)  //loops the amount of times for the columns
				
			{
					System.out.print(grid[i][j] + " | "); //prints the grid of location i , j then places a space
				}
			System.out.print(" || " + rowData[i]); //prints rowData  
			System.out.print("\n");
		}
		for (int i = 0; i < rows; i++) 
		{
			System.out.print(colData[i] + " | ");
		}
	}
}

	class TestArrayData 
{

	public static void main(String args[]) {
	ArrayData s = new ArrayData();
	s.populate(5, 10);
	s.sum(10);
	s.print();
	s.product(2, 4);
	s.sum(6);
	s.print();
	s.occurrence(2);
	s.print();
	s.print(4, 2);
	s.standardDeviation();
	s.print();
	} // main
} // TestArrayData
