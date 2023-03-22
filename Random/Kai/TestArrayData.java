import java.util.Random;



class ArrayData
{
    private int rows;
    private int columns;
    // private int grid[][];
	private int[][] grid;
    private int rowData[];
    private int colData[];

    
	public ArrayData()
    {
        rows = 10; 
        columns = 10;
        int rowData[] = new int [rows];
        int colData[] = new int[columns];
        int grid[][] = new int [rows][columns];
        //Setting arrays sizes to 10
        
        for(int i = 0; i < 10; i++)
        {
            rowData[i] = 0;
            colData[i] = 0;
        }

        for(int r = 0; r < 10; r++) 
        {
            for(int c = 0; c < 10; c++)
            {
                grid[r][c] = 0;
            }
        }//Initializing arrays to default value 0
    }
    

    public ArrayData(int size)
    {
        rows=columns=size;
        int rowData[] = new int[size];
        int colData[] = new int[size];
        int grid[][] = new int [size][size];
        //Setting arrays sizes to variable size
        
        for(int i = 0; i < 10; i++)
        {
            rowData[i] = 0;
            colData[i] = 0;
        }

        for(int r = 0; r < 10; r++) 
        {
            for(int c = 0; c < 10; c++)
            {
                grid[r][c] = 0;
            }
        }//Initializing arrays to default value 0
    }


    public ArrayData(int size, int startingValue)
    {
        rows=columns=size;
        int rowData[] = new int[size];
        int colData[] = new int[size];
        int grid[][] = new int [size][size];
         //Setting arrays sizes to size

        for(int i = 0; i < 10; i++)
        {
            rowData[i] = startingValue;
            colData[i] = startingValue;
        }
        for(int r = 0; r < 10; r++) 
        {
            for(int c = 0; c < 10; c++)
            {
                grid[r][c] = c;//startingValue;
            }
        }//Initializing arrays to startingvalue
    }
    


    public void populate(int newValue, int totalInstances)
    {
        Random rand = new Random();
        for( int i = 0; i < totalInstances; i++)// loops a total of totalInstance times
        {
            grid[rand.nextInt(10)][rand.nextInt(10)] = newValue;
        }// sets random positon in grid array to newValue
    }


    public void reverse( int rowNum, int start)
    {
            int store[] = new int[10];
            for(int i = 0; i <= start; i++)
            {
                store[i] = grid[rowNum][i];
                if( i == start)
                {
                    for(int j = 9; j > start; j--)
                    {
                        store[i] = grid[rowNum][j];
                    }
                }
            }
            for(int i = 0; i < 10; i++)
            {
                grid[rowNum][i] = store[i];

                System.out.println(grid[rowNum][i]);
            }
    }


    public void sum(int inc)
    {
        for(int r = 0; r < 10; r++)
        {
            for(int c = 0; c < 10; c++)
            {
                int rowSum = 0; //Sum of row
                int colSum = 0; //Sum of column
                
                if( grid[r][c] % 2 == 0 )//Identifying even values in rows
                {    
                    rowSum += grid[r][c] + inc;
                    rowData[r] = rowSum;
                }
                else{
                    rowSum +=  grid[r][c];
                    rowData[r] = rowSum;
                }//Sum of columns for rolData[]
                
                
                if( grid[c][r] % 2 == 0 )//Identifying even values in columns
                {    
                    colSum += grid[c][r] + inc;
                    colData[r] = colSum;
                }
                else{
                    colSum += grid[c][r];
                    colData[r] = colSum;
                }//Sum of columns for colData[]
            }
        }    
    }


    public void occurrence(int num)
    {
        for(int r = 0; r < 10; r++)
        {
            for(int c = 0; c < 10; c++)
            {
                int numSum = 0;//Variable for sum of num occurences
                if( grid[r][c] == num || grid[r][c] % num == 0 )
                {//Identifying num and multiples of num in rows
                    numSum++;
                    rowData[r] = numSum;
                }//Place number of times num occurs in rows into rowData[]

                if( grid[c][r] == num || grid[c][r] % num == 0 )
                {//Identifying num and multiples of num in columns
                    numSum++;
                    colData[r] = numSum;
                }//Place number of times num occurs in colums into colData[]
            }
        }
    }


/*    public void standardDeviation()
    {
        /*for(int r = 0; r < 10; r++)
        {  
            int rowSum = 0; //Sum of row
            int rowAvg; //Average of row
            int X[] = new int[10]; // To record integer values in rows
            int preSqrt; // To be squared rooted to find standard deviation
        
            
            for(int c = 0; c < 10; c++)
            {
                rowSum += grid[r][c];//Calculating Sum
                rowData[r] = rowSum;//Temporarily placing Sum of row in rowData[]
                X[c]= grid[r][c];//Recording integer values in each position in row
            }

            rowAvg = rowData[r] / 10;// Finding Average of row
            
            for(int i = 0; i < 10; i++)
            {//Distributing values in X[] for Standard Deviation equation
                preSqrt  = (rowData[r] * ((X[i] - rowAvg) * (X[i] - rowAvg))) / 10 - 1;
                java.lang.Math.sqrt(preSqrt);// %.f
            }
        }
    }
*/
    public void Sum(int rowSum)
    {
        for(int r = 0; r < 10; r++)
        {
            for(int c = 0; c < 10; c++)
            {
                rowSum +=  grid[r][c];
            }
        }
    }

    


    public void swap(int rowNum1,int rowNum2)
    {
        int store[] = new int[10];
        for(int r = 0; r < 10; r++)
        {
            for (int c = 0; c < 10; c++)
            {
                store[c] = grid[rowNum1][c];
                grid[rowNum1][c] = grid[rowNum2][c];
                grid[rowNum2][c] = store[c];
            }
        }
    }

    public int product(int rowNum, int colNum)
    {

        return colNum;
    }


    public void print()
    {   
        int rowSum = 0;//Sum of rows for rowData[]
        int colSum = 0;//Sum of columns for colData[]

        for(int r = 0; r < 10; r++)
        {
            for (int c = 0; c < 10; c++)
            { 
                rowSum += grid[r][c];
                rowData[r] = rowSum;

                colSum += grid[c][r];
                colData[r] = colSum;
                
                System.out.print(grid[r][c] + " | ");    
            }
            
            System.out.print("||" + rowData[r] + "/n");
        }

        for(int i = 0; i < 10; i++)
        {
            System.out.print(colData[i] + " | ");
        }
    }

    
    public void print(int rows, int columns)
    {
        int rowSum = 0; //Sum of rows for rowData[]
        int colSum = 0; //Sum of columns for colData[]
        
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < columns; r++)
            {
                rowSum += grid[r][c];
                rowData[r] = rowSum;

                colSum += grid[c][r];
                colData[r] = colSum;
                
                System.out.print(grid[r][c] + " | ");  
            }
            
            System.out.print("||" + rowData[r] + "/n");
        }

        for(int i = 0; i < columns; i++)
        {
            System.out.print(colData[i] + " | ");
        }
    }
}//ArrayData

public class TestArrayData
{
    public static void main(String args[])
    {
        ArrayData s = new ArrayData(10,0);

        // s.populate(5,10);
        s.sum(2);
        s.print();

        s.product(2,4);
        s.sum(2);
        s.print();
        
        s.reverse(3,4);
        s.print();

        s.occurrence(5);
        s.print();

        s.print(10,10);

        s.swap(3,4);
        s.print();


    }//main
}//TestArrayData