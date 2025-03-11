using System;

public class Complex
{
    // Properties
    public int Real { get; } // Auto-implemented property with public getter and no setter
    public int Imaginary { get; } // Auto-implemented property with public getter and no setter

    // Computed properties
    public double Modulus => Math.Sqrt(Real * Real + Imaginary * Imaginary); // Modulus calculation
    public double Argument => Math.Atan2(Imaginary, Real); // Argument calculation

    // Static factory property
    public static Complex Zero => new Complex(0, 0);

    // Constructor
    public Complex(int real = 0, int imaginary = 0)
    {
        Real = real;
        Imaginary = imaginary;
    }

    // Override ToString method
    public override string ToString()
    {
        return $"({Real}, {Imaginary})";
    }

    // Operator overloading for +
    public static Complex operator +(Complex lhs, Complex rhs)
    {
        int real = lhs.Real + rhs.Real;
        int imaginary = lhs.Imaginary + rhs.Imaginary;
        return new Complex(real, imaginary);
    }

    // Operator overloading for -
    public static Complex operator -(Complex lhs, Complex rhs)
    {
        int real = lhs.Real - rhs.Real;
        int imaginary = lhs.Imaginary - rhs.Imaginary;
        return new Complex(real, imaginary);
    }

    // Operator overloading for ==
    public static bool operator ==(Complex lhs, Complex rhs)
    {
        return lhs.Real == rhs.Real && lhs.Imaginary == rhs.Imaginary;
    }

    // Operator overloading for !=
    public static bool operator !=(Complex lhs, Complex rhs)
    {
        return !(lhs == rhs);
    }

    // Operator overloading for *
    public static Complex operator *(Complex lhs, Complex rhs)
    {
        int real = lhs.Real * rhs.Real - lhs.Imaginary * rhs.Imaginary;
        int imaginary = lhs.Real * rhs.Imaginary + lhs.Imaginary * rhs.Real;
        return new Complex(real, imaginary);
    }

    // Operator overloading for unary -
    public static Complex operator -(Complex c)
    {
        return new Complex(-c.Real, -c.Imaginary);
    }

    // Override Equals and GetHashCode for proper equality comparison
    public override bool Equals(object obj)
    {
        if (obj is Complex other)
        {
            return this == other;
        }
        return false;
    }

    public override int GetHashCode()
    {
        return Real.GetHashCode() ^ Imaginary.GetHashCode();
    }
}

class Program
{
    static void Main()
    {
        Complex c0 = new Complex(-2, 3);
        Complex c1 = new Complex(-2, 3);
        Complex c2 = new Complex(1, -2);

        Console.WriteLine($"{c0}");
        Console.WriteLine(c1);
        Console.WriteLine(c2);

        Console.WriteLine($"{c1} + {c2} = {c1 + c2}");
        Console.WriteLine($"{c1} - {c2} = {c1 - c2}");

        Complex c3 = c1 + c2;

        Console.WriteLine($"{c3} in polar form is {c3.Modulus:f2}cis({c3.Argument:f2})");

        Console.WriteLine($"{c0} {(c0 == c1 ? "=" : "!=")} {c1}");
        Console.WriteLine($"{c0} {(c0 == c2 ? "=" : "!=")} {c2}");

        // Testing multiplication operator
        Complex c4 = c1 * c2;
        Console.WriteLine($"{c1} * {c2} = {c4}");

        // Testing unary negation operator
        Complex c5 = -c0;
        Console.WriteLine($"-{c0} = {c5}");
    }
}