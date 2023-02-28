//tictactoe.cc – DO alter this file.  
//Add your functions above runGame().
//NOTE that I have commented out the functions so it will compile.  You
//MUST uncomment these as you complete them for the game to work and for
//testing.

#include <stdio.h>
#include "tictactoe.h"

/*
 This is my clearBoard() method which takes a pointer to a
 gameData_t structure. It will then loop through the array
 and set all the indexes to a spce(' ').
 */
void clearBoard(gameData_t* clearPtr) {

    //Enter the outter loop.
    for (int i = 0; i < 3; i++) {

        //Enter the inner loop.
        for (int j = 0; j < 3; j++) {

            //Here I set each index of board to a space(' ').
            clearPtr->board[i][j] = ' ';

        }
    }

    return;
}

/*
 This is my getPlayerInfo() method that takes a pointer to a
 gameData_t structure and sets the player's names and
 ages for the game.
*/
void getPlayerInfo(gameData_t* gamePtr) {

    //Here I get player 1's name and age for the game.
    printf("Player 1 enter your name: ");
    scanf("%s", gamePtr->name1);
    printf("Player 1 enter your age: ");
    scanf("%d", &gamePtr->age1);

    printf("\n");
    printf("\n");

    //Here I get player 2's name and age for the game.
    printf("Player 2 enter your name: ");
    scanf("%s", gamePtr->name2);
    printf("Player 2 enter your age: ");
    scanf("%d", &gamePtr->age2);

    return;
}

/*
 This is my printPlayerInfo method that will print
 each of the players info for the game.
 */
void printPlayerInfo(gameData_t helper) {

    //Print player ones info.
    printf("Player 1 is %s age %d and will be Xs\n", helper.name1, helper.age1);

    //Print player twos info.
    printf("Player 2 is %s age %d and will be Os", helper.name2, helper.age2);

    return;
}

/*
 Here is the printTurnHeader() method that dispays
 which player is up next and their symbol.
 */
void printTurnHeader(gameData_t gameVar, char turnVar) {

    //start by printing the top lines.
    for (int i = 0; i < 50; i++) {
        if (i != 49) {
            printf("-");
        }
        else {
            printf("-\n");
        }

    }

    //Print the middle section with the player one's info
    //if 'X' is the value of turn
    if (turnVar == 'X') {
        printf("---------- %s's Turn --------------------\n", gameVar.name1);
        printf("---------- You are Xs --------------------\n");
    }

    //Print the middle section with the player two's info
    //if the 'O' is the value of turn
    else {
        printf("---------- %s's Turn --------------------\n", gameVar.name2);
        printf("---------- You are Os --------------------\n");
    }


    //Finally print the last line.
    for (int i = 0; i < 50; i++) {
        if (i != 49) {
            printf("-");
        }
        else {
            printf("-\n");
        }

    }

    return;
}


/*
 Here is my printBoard() method that prints the board.
 */
void printBoard(gameData_t gameVar) {


    //Here I simply print out the board passing the
    //characters that need to be printed.
    printf("    C1  C2  C3\n");
    printf("R1  %c | %c | %c \n", gameVar.board[0][0], gameVar.board[0][1], gameVar.board[0][2]);
    printf("   -----------\n");
    printf("R2  %c | %c | %c \n", gameVar.board[1][0], gameVar.board[1][1], gameVar.board[1][2]);
    printf("   -----------\n");
    printf("R3  %c | %c | %c \n", gameVar.board[2][0], gameVar.board[2][1], gameVar.board[2][2]);

    return;
}

/*
 Here is the getMove() method that takes a pointer to gameData_t
 structure and a char parameter for turn.
 */
void getMove(gameData_t* movePtr, char turnVar) {

    //Create a helper array to store the user input.
    char helper0[5];

    //Create a variable to act as a boolean.
    int test = 1;

    //If the turnVar is at 'X'.... being that it's player one's
    //turn to go.
    if (turnVar == 'X') {

        //Get user input for move.
        printf("%s, please enter your move in the form RXCY: \n", movePtr->name1);
        scanf("%4s", helper0);

        //Start the while loop that continues to check if the
        //user input is valid.
        while (test) {

            //Checks if the user input had the letter 'r' and 'c' in there...
            //Can be upper case as well.
            if ((helper0[0] != 'R' && helper0[0] != 'r') || (helper0[2] != 'C' && helper0[2] != 'c')) {

                //If its not an 'r' or a 'c' display error message.
                printf("Result must be in the form RxCy. Try again: ");

            }

            //If the user input is out of range... aka -> (x < 1 || X > 3)
            //I have to subtract 48 due to hex formatting.
            else if (((helper0[1] - 48) < 1 || (helper0[1] - 48) > 3) || ((helper0[3] - 48) < 1 || (helper0[3] - 48) > 3)) {

                //If the input is out of range display an error message.
                printf("The row and the column must be in the range 1 to 3. Try again: ");
            }

            //If the position that the user selected is already taken.
            else if (movePtr->board[helper0[1] - 49][helper0[3] - 49] != ' ') {

                //If the position is already taken print an error message.
                printf("That space is taken. Try again: ");
            }

            //If we enter this conditional then the user input was valid...
            //and I store that input in the board[][] array.
            else {

                //Here I store the values in the board[][] array.
                movePtr->board[helper0[1] - 49][helper0[3] - 49] = 'X';

                //Then I set test to 0 stoping the while loop.
                test = 0;
            }

            //Here we check to see if we have gotten a valid input...
            //If it is not valid 'test' will be 1 and we need to listen for
            //the new user input... Otherwise 'test' will be a 0 and this
            //won't be checked at all.
            if (test == 1) {

                //Scan for new user input.
                scanf("%4s", helper0);
            }
        }
    }

    //Here I do the same thing as above just for player 2.
    else {

        //Double check to make sure turnVar == 'O'.
        if (turnVar == 'O') {

            //Get user input for move.
            printf("%s, please enter your move in the form RXCY: \n", movePtr->name2);

            //Scan the user input.
            scanf("%4s", helper0);

            //Start the while loop that continues to check if the
            //user input is valid.
            while (test) {

                //Checks if the user input had the letter 'r' and 'c' in there...
                //Can be upper case as well.
                if ((helper0[0] != 'R' && helper0[0] != 'r') || (helper0[2] != 'C' && helper0[2] != 'c')) {

                    //If the input if not an 'r' or a 'c' (upper case too) display error message.
                    printf("Result must be in the form RxCy. Try again: ");

                }

                //If the user input is out of range... aka -> (x < 1 || X > 3)
                //I have to subtract 48 due to hex formatting.
                else if (((helper0[1] - 48) < 1 || (helper0[1] - 48) > 3) || ((helper0[3] - 48) < 1 || (helper0[3] - 48) > 3)) {

                    //If the user input is out of range display error message.
                    printf("The row and the column must be in the range 1 to 3. Try again: ");
                }

                //If the position that the user selected is already taken.
                else if (movePtr->board[helper0[1] - 49][helper0[3] - 49] != ' ') {

                    //If the position is already taken then I need to display an error message.
                    printf("That space is taken. Try again: ");
                }

                //If we enter this conditional then the user input was valid...
                //and I store that input in the board[][] array.
                else {

                    //Here I store the an 'O' in the selected position.
                    movePtr->board[helper0[1] - 49][helper0[3] - 49] = 'O';

                    //Set test to 0 because we are done and need
                    //to get out of the loop.
                    test = 0;
                }

                //Here we check to see if we have gotten a valid input...
                //If it is not valid 'test' will be 1 and we need to listen for
                //the new user input... Otherwise 'test' will be a 0 and this
                //won't be checked at all.
                if (test == 1) {

                    //Scan for user input.
                    scanf("%4s", helper0);
                }
            }
        }
    }
}

/*
 Here is my checkWin() method that checks if a
 player has won.
 */
int checkWin(gameData_t gameVar, char turnVar) {

    //Create our winning variable.
    int win = 0;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///Here I check to see if a player has captured a full row of the board.//////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Check to see if a player has gotten all of the first row.
    if (gameVar.board[0][0] == turnVar && gameVar.board[0][1] == turnVar && gameVar.board[0][2] == turnVar) {
        win = 1;
    }

    //Check to see if a player has gotten all of the second row.
    else if (gameVar.board[1][0] == turnVar && gameVar.board[1][1] == turnVar && gameVar.board[1][2] == turnVar) {
        win = 1;
    }

    //Check to see if a player has gotten all of the third row.
    else if (gameVar.board[2][0] == turnVar && gameVar.board[2][1] == turnVar && gameVar.board[2][2] == turnVar) {
        win = 1;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///Here I check to see if a player has captured a full column of the board.//////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Check to see if a player has gotten all of the first column.
    else if (gameVar.board[0][0] == turnVar && gameVar.board[1][0] == turnVar && gameVar.board[2][0] == turnVar) {
        win = 1;
    }

    //Check to see if a player has gotten all of the second column.
    else if (gameVar.board[0][1] == turnVar && gameVar.board[1][1] == turnVar && gameVar.board[2][1] == turnVar) {
        win = 1;
    }

    //Check to see if a player has gotten all of the third column.
    else if (gameVar.board[0][2] == turnVar && gameVar.board[1][2] == turnVar && gameVar.board[2][2] == turnVar) {
        win = 1;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///Here I check to see if a player has captured a full diagnal across.///////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Check to see if a player has gotten a full diagnal from [0][0] -> [2][2].
    else if (gameVar.board[0][0] == turnVar && gameVar.board[1][1] == turnVar && gameVar.board[2][2] == turnVar) {
        win = 1;
    }

    //Check to see if a player has gotten a full diagnal from [0][2] -> [2][0].
    else if (gameVar.board[0][2] == turnVar && gameVar.board[1][1] == turnVar && gameVar.board[2][0] == turnVar) {
        win = 1;
    }

    //Return the value of win.
    return win;
}

/*
 Here is my checkTie() method that checks if a tie has occured.
 */
int checkTie(gameData_t gameVar) {

    int helper = 0;

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            if (gameVar.board[i][j] == ' ') {
                helper++;
            }
        }
    }

    if (helper == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

void runGame() {

    gameData_t gameData;

    int win = 0;
    int tie = 0;
    char turn = 'X';

    //Set board to all spaces.
    clearBoard(&gameData);

    //Get both players name and age
    getPlayerInfo(&gameData);

    //Show the player info
    printf("\n");
    printPlayerInfo(gameData);
    printf("\n");

    while (!win && !tie) {
        int count = 0;

        printTurnHeader(gameData, turn);
        printBoard(gameData);
        getMove(&gameData, turn);

        //Check for win
        win = checkWin(gameData, turn);
        if (win == 1) {
            printf("--------------------------------------------------\n");
            if (turn == 'X') {
                printf("---------- %s WINS! --------------------\n", gameData.name1);
            }
            else {
                printf("---------- %s WINS! --------------------\n", gameData.name2);
            }
            printf("--------------------------------------------------\n");
            printBoard(gameData);
            printf("\n");
        }
        else {
            tie = checkTie(gameData);
            if (tie == 1) {
                printf("--------------------------------------------------\n");
                printf("---------- TIE GAME! --------------------\n");
                printf("--------------------------------------------------\n");
                printBoard(gameData);
            }
        }

        //Toggle turn so other player goes next.
        if (turn == 'X') turn = 'O';
        else turn = 'X';
    }
}
