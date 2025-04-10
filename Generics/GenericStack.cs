using System;

public class GenericStack<T>
{
    private const int SIZE = 15; // Constant size of the stack
    private int top; // Index of the last added item
    private T[] data; // Array to store stack elements

    // Constructor
    public GenericStack()
    {
        top = -1; // Stack is empty initially
        data = new T[SIZE]; // Initialize array
    }

    // Property to check if stack is empty
    public bool IsEmpty
    {
        get { return top == -1; }
    }

    // Push method to add an item to the stack
    public void Push(T item)
    {
        if (top >= SIZE - 1) // Stack is full
        {
            throw new InvalidOperationException("Stack Overflow: Cannot push more elements.");
        }
        data[++top] = item;
    }

    // Pop method to remove and return the top item
    public T Pop()
    {
        if (IsEmpty) // Stack is empty
        {
            throw new InvalidOperationException("Stack Underflow: Cannot pop from an empty stack.");
        }
        return data[top--];
    }
}
