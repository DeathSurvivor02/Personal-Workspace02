#										 Abstract Data Types

## Abstract Classes

[examples]

abstract public class Ball
	{
		abstract public int getSize();
		abstract public String getColour(); //abstract methods
	}

	Ball b = new Ball();
	b.getSize();

<!-- concrete class -->
	public class  BasketBall extends Ball
	{
		public int getSize()
		{
			return 10;
		}
		public String getColour()
		{
			return "brown";
		}
	}

public interface Ball
{
<!-- interface can only receive abstract types -->
}

<!-- concrete class and interface class do the same thing while, the concrete class can take in normal variables and interface can only receive abstract types -->



## 							Exceptions


throw exceptions