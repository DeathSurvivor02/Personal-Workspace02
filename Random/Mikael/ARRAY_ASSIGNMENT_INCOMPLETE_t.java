import java.util.Random;


public class ArrayData
{
private int rows = 10; // contains total number of rows
private int columns = 10; // contains total number of columns
private int[][] grid; //contains integers use by the class
private int rowData[];//contains the sum(or operations) of the integers in each row of the grid array
private int colData[];//contains the sum(or operations) of the integers in each column of the grid array
private int count = 0; 
private int tempNum;
private float rowAvg; 
private float colAvg;
private double sigmaRow = 0.0;
private double sigmaCol = 0.0;
private double sigmaTotalRow;
private double sigmaTotalCol;
// private int grid = 0; //correction 


/* 
This array contains
*/
	public ArrayData()
	{
		rowData = new int[rows];// create an array of integers with the same number of elements as 'rows'
		colData = new int[columns];//create an array of integers with the same number of elements as 'columns'
	    // error 
		/* not defined */ grid = new int[rows][columns];//create a 2 dimentsional array with dimensions 'rows' x 'columns'
	    //grid here suppose to be grid

		for(int i = 0; i<rows;i++)
		{
		for (int j = 0; j < columns; j++)
			{
				grid[i][j] = 0;//should be grid
			}
		}

		for(int i = 0; i < 10;i++)
		{
			rowData[i] = 0;
		}

		for(int i =0; i < 10 ;i++)
		{
			colData[i] = 0;
		}
	}

	public ArrayData(int size)
	{ 
		for(int i= 0 ;i< size; i++)
		{
			for(int j = 0;j<size;j++)
			{
				grid[i][j] = 0;
			}
		}

		for(int i=0; i<size; i++)
		{
			rowData[i] = 0;
		}
		for(int i = 0;i<size;i++)
		{
			colData[i]=0;
		}
	}


	public ArrayData(int size, int startingValue)
	{
			for(int i= 0 ;i< size; i++)
		{
			for(int j = 0;j<size;j++)//change (i)s here to j
			{
				grid[i][j] = startingValue;
			}
		}
		for(int i=0; i<size; i++)
		{
			rowData[i] = startingValue;
			for(int j = 0;j<size;j++)//change (i)s here to j
			{
				colData[j]= startingValue;//change (i)s here to j 
			}
		}
	}



	public void populate(int newValue, int totalInstances)
	{



	    // int count=0;
		Random rand = new Random();
		// int count = 0;
	
			while (count < totalInstances )//i think u mean to change t to count
			{
			
			count++;//should be count++;
			grid[rand.nextInt(rows)][rand.nextInt(columns)] = newValue;
			}
		
	}

public void reverse(int rowNum, int start)//this function wrong
{
    for(int i = 0; i < columns / 2; i++)
    {
        int cur = grid[rowNum][i];//idk cur suppose to be but something here wrong\
        grid[rowNum][i] = grid[rowNum][columns - i -1];
        int temp;
		grid[rowNum][columns - i - 1] = temp;
    }
}


public void sum(int inc)
{
    int size;
	for(int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; i++)
        {
            if(grid[i][j] % 2 == 0)
            {
                rowData[i] += inc * grid[i][j];
            }
            else
            {
                rowData[i] += grid[i][j];
            }
            if(grid[j][i] % 2 == 0)
            {
                colData[i] += inc * grid[j][i];
            }
            else
            {
                colData[i] += inc* grid[j][i];
            }
        }
    }
}


public void occurrence(int num)
{
    for(int i = 0;i<rows;i++)//forgot for loop for j
    
	for (int j = 0; j < columns; j++)
	{

		{//should have for loop for 1-10 so it can multiply num
            if(grid[i][j] == num || grid[i][j] % i == 0)
			{
				//forgot{} & should be value[i][j]
        	    occur++; //define this
        	    row[i]= occur; //uhh idk what u doing this
        	}
		}
	}
}


public void standardDeviation()
{
    Sigma(rows,columns);
		sigmaTotalRow = Deviation(rows);
		sigmaTotalCol = Deviation(columns);

if(grid[i] == size)
{
    return java.lang.Math.sqrt(((sigmaRow)/(grid[i]-1)));
}
else
{
    return java.lang.Math.sqrt(((sigmaCol)/(grid[i]-1)))
}
    for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                sumRow += (grid[i][j] - rowAvg);
                sumCol += (grid[j][i] - colAvg);
            }
        }

    rowAvg = sumRow/size;//average of the row
    colAvg = sumCol/size;//average of the column

    for(int i = 0;i< size; i++)
    {
        for(int j = 0;j < size ; j++)
        {
            sigmaRow = sigmaRow + java.lang.Math.pow((grid[i][j] - rowAvg),2);
            sigmaCol = sigmaCol + java.lang.Math.pow((grid[j][i]-colAvg),2)
        }
    }
}



public void swap(int rowNum1, int rowNum2)
{
    int tempNum;
    for(int i = 0; i < size; i++)
    {
        tempNum = grid[rowNum1][i];
        grid[rowNum1][i] = grid[rowNum2][i];
        grid[rowNUm2][i] = tempNum;
    }
}

public int product(int rowNum, int colNum)//forgot the rowstemp part
{
    if (rowNum > colNum)
    {
        rowNum = colNum;
    }
    else if(colNum > rowNum)
    {
        colNum = rowNow;
    }

    int result = 0;
    for(int i = 0; i < rows; i++)
    {
        result += grid[rowNum][i] * grid[i][colNum];
    }
    return result
};

public void print()//forgot colData
{
    for(int i = 0; i < rowNum;i++)
    {
            for(int j = 0; j < colNum;j++)
            {
                system.out.print(" || " + rowData[i]);
                system.out.print(" || " + colData[j]) 
            }
            System.out.print(" || " + rowData[i]);
            system.out.print("\n");
    }
}
public void print(int rows, int columns)//dont really understand this function but looks right
{
    for(int i = 0; i < rows; i++)
    {
        System.out.print ( grid[i][j] + " | ");
    }
    System.out.print(" || " + rowData[i]);
    System.out.print("\n");
}
    for (int i = 0; i < rows; i++) 
		{
			System.out.print (colData + " | ");
		}

}


{
    for (int i = 0;i>10;i++)
        i += [i]
}

{

    for (int i = 0;i>10;i++)
        i += [i]
}
}


public class TestArrayData
{
    Public static void main( string args [] )
    {
        ArrayData s = new ArrayData();

        s.populate(5,10);
        s.sum();
        s.print();

        s.product(2,4);
        s.sum();
        s.print();

        s.occurence(2);
        s.print();

        s.print(4,2);
    } //main
}// TestArrayData