class Circle {
	private int x, y, radius;

	public Circle(int x, int y, int radius) {
		this.x = x;
		this.y = y;
		this.radius = radius;
	}

	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}

	public int getRadius() {
		return radius;
	}

	public void setRadius(int radius) {
		this.radius = radius;
	}
}

class DrawDemo {
	public static void main(String[] args) {
		Circle c1 = new Circle(5, 10, 15);
		Circle c2 = new Circle(20, 30, 10);

		c1.setX(10);
		c1.setY(20);
		c1.setRadius(25);

		System.out.println("Circle 1 - X: " + c1.getX() + " Y: " + c1.getY() + " Radius: " + c1.getRadius());
		System.out.println("Circle 2 - X: " + c2.getX() + " Y: " + c2.getY() + " Radius: " + c2.getRadius());
	}
}
