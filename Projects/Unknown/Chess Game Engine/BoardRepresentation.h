#include <string>
#include <
#include <iostream>


// Todo
/* 
	Displays the full representation of the board
 */

// void blacksquare();
// void whitesquare();

#include <iostream>

void board_display() //!should NOT be taking in any parameters
{
    for (char i = 'a'; i <= 'h'; i++) // rows
    {
        for (int j = 1; j <= 8; j++) // columns
        {
            std::cout << i << j << std::endl;
        }
        std::cout << std::endl; // newline after each row
    }
}

