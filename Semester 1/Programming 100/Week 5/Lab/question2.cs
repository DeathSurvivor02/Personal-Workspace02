/*
 * Name: Ean Bynoe 
 *Student Number: 301390261
 *Date: October 10, 2024
 * @brief: The program is to check the length of the 'password' they input
 * @param: string password, int length
 * restriction: The password length needs to be 6 or more characters long.
 */

//Variables:
string password;
int length;

//Input
Console.WriteLine("Enter new password: ");
password = Console.ReadLine();
length = password.Length; //!Length is not a function with '()' but rather a function that is imbeded in to the language itself
if (length >= 6)

    Console.WriteLine("Password accepted.");
else
    Console.WriteLine($"Password length is {length}, Rejected.");
