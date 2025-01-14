/*  CalculateGravitationalForce - 9 marks
	   * 	“Newton's law of universal gravitation states that every point mass in the 
	   * 	universe attracts every other point mass with a force that is directly 
	   * 	proportional to the product of their masses and inversely proportional to 
	   * 	the square of the distance between them.” 
	   * 	
	   * Write a method with the following specifications:static double CalculateGravitationalAttraction()
{
  ^Constants: Mass of Earth, Moon, and the distance between them
  double massEarth = 5.972e24;
  double massMoon = 7.348e22;
  double distance = 3.844e8;
  double G = 6.673e-11; // Gravitational constant

  Calculate gravitational force
  double force = G * (massEarth * massMoon) / (distance * distance);

  ^Display values in the required format
  Console.WriteLine("\n\n********** Begin Question 3 **********");
  Console.WriteLine($"Mass of earth: {massEarth:e6}kg");
  Console.WriteLine($"Mass of the moon: {massMoon:e6}kg");
  Console.WriteLine($"The distance between them: {distance:e6}m");
  Console.WriteLine($"The force of attraction: {force:e6}N");
  Console.WriteLine("\n********** End Question 3 **********\n\n");

  return force;
}
	   * Name     : CalculateGravitationalAttraction
	   * Parameter: 
	   * 	          A double representing the mass of the first body
	   * 	          A double representing the mas of the second body
	   * 	          A double representing the distance between them. 
	   * Returns  : a double representing the attractive force between the bodies
	   * Displays : Nothing
	   * Task     : Calculate and return the force of attraction between them. 
	   * 	[F=G (m_1 m_2)/d^2  , where G = 6.673e-11]. See word file for equation
	   */

double CalculateGravitationalAttraction(double mass1, double mass2, double distance)
{
  double G = 6.673e-11; // Gravitational constant
  double force = G * (mass1 * mass2) / (distance * distance);
  return force;
}
/* Driver for question 3 - 6 marks
 * 
 * Write the statements to call the above method with the masses of the earth, 
 * moon and the distance between them and display the resulting force. 
 * 
 * 	Mass of Earth = 5.972E24, moon = 7.348E22, Distance = 3.844E8.
 * 	[Answer 1.99e020]
 * 	You should use E as a format specifier in your output
 */

const double massEarth = 5.972e24;
const double massMoon = 7.348e22;
const double distance = 3.844e8;
const double G = 6.673e-11;

// double force = G * (massEarth * massMoon) / (distance * distance);

Console.WriteLine("\n\n********** Begin Question 3 **********");
Console.WriteLine($"Mass of earth: {massEarth:e6}kg");
Console.WriteLine($"Mass of the moon: {massMoon:e6}kg");
Console.WriteLine($"The distance between them: {distance:e6}m");
Console.WriteLine($"The force of attraction: {CalculateGravitationalAttraction(massEarth, massMoon, distance)}N");
Console.WriteLine("\n********** End Question 3 **********\n\n");
