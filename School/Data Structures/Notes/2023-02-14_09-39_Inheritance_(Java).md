public class Ball
{
	private int size;
	private string shape;
	private string colour;
[inherited] protect float price;

	public Ball(int size, string shape, string colour, float price)
	{
		this.size = size;
		this.shape = shape;
		this.colour = colour;
		this.price = price;
	}

};


<!-- child class, subclass  -->

public class Basketball extends Ball
{
	private boolean isleather;
}

<!-- Basketball constructor -->
public Basketball(string colour,, float price)
{
	this.price = price;
	set size(12);
	set colour(colour);
	set shape("circles");
}
<!-- super is a way to call a constructor for an inherited class -->
super(12, "circle", colour, price);
99*

public class SoccerBall extends Ball 
{

}