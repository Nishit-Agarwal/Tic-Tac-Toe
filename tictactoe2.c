#include <stdio.h>
#include<conio.h>
char square[10] = { '0','1', '2', '3', '4', '5', '6', '7', '8', '9' };
int checkwin();
void board();
void resetSquare();
void main()
{
    int player = 1, i, choice,again,PvP;
    char p1[10],p2[10],mark,ch;
    printf("press 1 for single player(in easy mode) and press 2 for double players\n");
    scanf("%d",&PvP);
    if(PvP ==2)
    {
        scanf("%c",&ch);
        printf("Enter the name of the first player -: ");
        gets(p1);
        printf("Enter the name of the second player -: ");
        gets(p2);
            do
            {
                board();
                player = (player % 2) ? 1 : 2;
                if(player == 1)
                    printf("%s turn\n",p1);
                else
                    printf("%s turn\n",p2);
                printf("enter a number:  ");
                scanf("%d", &choice);

                mark = (player == 1) ? 'X' : 'O';

                if (choice == 1 && square[1] == '1')
                    square[1] = mark;
                else if (choice == 2 && square[2] == '2')
                    square[2] = mark;
                else if (choice == 3 && square[3] == '3')
                    square[3] = mark;
                else if (choice == 4 && square[4] == '4')
                    square[4] = mark;
                else if (choice == 5 && square[5] == '5')
                    square[5] = mark;
                else if (choice == 6 && square[6] == '6')
                    square[6] = mark;
                else if (choice == 7 && square[7] == '7')
                    square[7] = mark;
                else if (choice == 8 && square[8] == '8')
                    square[8] = mark;
                else if (choice == 9 && square[9] == '9')
                    square[9] = mark;
                else
                {
                    printf("Invalid move ");
                    player--;
                    getch();
                }
                i = checkwin();
                player++;
                }while (i ==  - 1);
            board();
            if (i == 1)
            {
                player --;
                if(player == 1)
                    printf("Player %s WIN",p1);
                else
                    printf("Player %s WIN",p2);
            }
            else
                printf("==>\aGame draw");
        printf("\ndo you want to play again if yes press 1 or press 0\n");
        scanf("%d",&again);
        if(again == 1)
        {
            resetSquare();
            main();
        }

        else
            exit(1);
    }
    else
    {
        scanf("%c",&ch);
        printf("Enter the name of the first player -: ");
        gets(p1);
            do
            {
                board();
                player = (player % 2) ? 1 : 2;
                if(player == 1)
                {
                    printf("%s turn\n",p1);
                    printf("enter a number:  ");
                    scanf("%d", &choice);
                }
                else
                {
                    printf("%s computer turn\n",p2);
                    int lower=1 , upper =9;
                    printf("%d",rand());
                    choice = (rand() % (upper - lower +1))+lower;
                }



                mark = (player == 1) ? 'X' : 'O';

                if (choice == 1 && square[1] == '1')
                    square[1] = mark;
                else if (choice == 2 && square[2] == '2')
                    square[2] = mark;
                else if (choice == 3 && square[3] == '3')
                    square[3] = mark;
                else if (choice == 4 && square[4] == '4')
                    square[4] = mark;
                else if (choice == 5 && square[5] == '5')
                    square[5] = mark;
                else if (choice == 6 && square[6] == '6')
                    square[6] = mark;
                else if (choice == 7 && square[7] == '7')
                    square[7] = mark;
                else if (choice == 8 && square[8] == '8')
                    square[8] = mark;
                else if (choice == 9 && square[9] == '9')
                    square[9] = mark;
                else
                {
                    printf("Invalid move ");
                    player--;
                }
                i = checkwin();
                player++;
                }while (i ==  - 1);
            board();
            if (i == 1)
            {
                player --;
                if(player == 1)
                    printf("Player %s WIN",p1);
                else
                    printf("Computer Wins");
            }
            else
                printf("==>\aGame draw");
        printf("\ndo you want to play again if yes press 1 or press 0\n");
        scanf("%d",&again);
        if(again == 1)
        {
            resetSquare();
            main();
        }

        else
            exit(1);
    }



getch();
}

void resetSquare()
{
    square[1] ='1';
    square[2]='2';
    square[3] ='3';
    square[4]='4';
    square[5] ='5';
    square[6]='6';
    square[7] ='7';
    square[8]='8';
    square[9] ='9';
}

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}
void board()
{
    system("cls");
    printf("\n\n\tTic Tac Toe\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}
