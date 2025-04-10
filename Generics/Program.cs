class Program
{
    static void Main()
    {
        Console.WriteLine("Testing stack with integers:");
        TestIntStack();

        Console.WriteLine("\n\nTesting stack with strings:");
        TestStringStack();
    }

    static void TestIntStack()
    {
        GenericStack<int> stack = new GenericStack<int>();
        Console.WriteLine("Pushing values 0 to 14 onto the stack...");
        for (int i = 0; i < 15; i++)
        {
            stack.Push(i);
        }
        Console.WriteLine("Popping values from the stack...");
        while (!stack.IsEmpty)
        {
            Console.Write($"{stack.Pop()} ");
        }
    }

        static void TestStringStack()
        {
            GenericStack<string> stack = new GenericStack<string>();
            Console.WriteLine("Pushing words onto the stack...");
            string[] words = { "Hello", "world", "this", "is", "a", "test" };
            foreach (var word in words)
            {
                stack.Push(word);
            }
            Console.WriteLine("Popping words from the stack...");
            while (!stack.IsEmpty)
            {
                Console.Write($"{stack.Pop()} ");
            }
        }
    }
