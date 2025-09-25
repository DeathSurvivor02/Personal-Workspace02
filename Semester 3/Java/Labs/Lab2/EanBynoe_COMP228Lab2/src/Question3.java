public class Question3 {

    //Function: First overloaded method
    static void Output1(int a, int b){
        int sum = a + b;
        System.out.println("The sum of the two integers is: " + sum);

    }
    //Function: Second overloaded method
    static void Output1(double a, double b){
        double sum = a + b;
        System.out.println("The sum of the two doubles is: " + sum);
    }
    //Function: Third overloaded method
    static void Output1(String a, String b){
        String sum = a + b;
        System.out.println("The concatenated string is: " + sum);
    }


    static void Question3() {

        //Calling the overloaded methods
        Output1(5, 10); // Calls the first method
        Output1(5.5, 10.5); // Calls the second method
        Output1("Hello, ", "World!"); // Calls the third method
    }
    
}
