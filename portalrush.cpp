int rd()
{
    int rem;
    srand(time(NULL));
    do
    {
        rem = rand() % 7;
    }while(rem == 0);
    return rem;
}

void displayboard(int curp, char player[4])
{
    int i, j, t, c, line = 0, posnum, pos1, pos2;

    if (curp == 100)
    {
        printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
        printf("\xba                     !!!!   CONGRATULATIONS   !!!!                      \xba\n");
        printf("\xba                                                                        \xba\n");
        printf("\xba                       >>>  PLAYER %s WINS  <<<                       \xba\n", player);
        printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
        getch();
        mainMenu();
    }

    for (i = 10; i > 0; i--)
    {
        t = i - 1;
        if ((line % 2) == 0)
        {
            c = 0;
            for (j = 10; j >= 1; j--)
            {
                posnum = (i * j) + (t * c++);
                if (curp == posnum)
                    printf("%s\t", player);
                else
                    printf("%d\t", posnum);
            }
            line++;
        }
        else
        {
            c = 9;
            for (j = 1; j <= 10; j++)
            {
                posnum = (i * j) + (t * c--);
                if (curp == posnum)
                    printf("%s\t", player);
                else
                    printf("%d\t", posnum);
            }
            line++;
        }
        printf("\n");
    }
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
}
int PRmain()
{
    system("cls");
    system("color 7");
    int i, dice, cur_pos1 = 0, cur_pos2 = 0, count = 0;
    while (1)
    {
        printf("PORTALS : | 10 to 30 | 15 to 35 | 20 to 40 | 25 to 50 | 30 to 60 | 40 to 65 |\nPORTALS : | 50 to 70 | 55 to 75 | 60 to 80 | 65 to 85 | 70 to 90 | 75 to 95 |\n");

        count++;
        if (count % 2 == 1)
        {
            Beep(2080, 40);
            printf("\n\t\t    >>> This is player 1's turn <<<\n\n");
        }
        else
        {
            Beep(2080, 40);
            printf("\n\t\t    >>> This is player 2's turn <<<\n\n");
        }

        printf("Choose your option\n");
        printf("[1] Press 'Space' To Play \n");
        printf("[2] Press 'Esc' To Exit");

        char ch = getch();
        if (count % 2 == 1)
        {
            system("color 2");
            dice = rd();
            system("cls");
            printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            printf("\t\t\t  |||  PORTAL RUSH  |||\n");
            printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            cur_pos1 = dice + cur_pos1;
            if (cur_pos1 < 101)
            {
                if (cur_pos1 == 10)
                {
                    cur_pos1 = 30;
                    displayboard(30, "-P1-"); // portal
                }
                else if (cur_pos1 == 15)
                {
                    cur_pos1 = 35;
                    displayboard(35, "-P1-"); // portal
                }
                else if (cur_pos1 == 20)
                {
                    cur_pos1 = 40;
                    displayboard(40, "-P1-"); // portal
                }
                else if (cur_pos1 == 25)
                {
                    cur_pos1 = 50;
                    displayboard(50, "-P1-"); // portal
                }
                else if (cur_pos1 == 30)
                {
                    cur_pos1 = 60;
                    displayboard(60, "-P1-"); // portal
                }
                else if (cur_pos1 == 40)
                {
                    cur_pos1 = 65;
                    displayboard(65, "-P1-"); // portal
                }
                else if (cur_pos1 == 50)
                {
                    cur_pos1 = 70;
                    displayboard(70, "-P1-"); // portal
                }
                else if (cur_pos1 == 55)
                {
                    cur_pos1 = 75;
                    displayboard(75, "-P1-"); // portal
                }
                else if (cur_pos1 == 60)
                {
                    cur_pos1 = 80;
                    displayboard(80, "-P1-"); // portal
                }
                else if (cur_pos1 == 65)
                {
                    cur_pos1 = 85;
                    displayboard(85, "-P1-"); // portal
                }
                else if (cur_pos1 == 70)
                {
                    cur_pos1 = 90;
                    displayboard(90, "-P1-"); // portal
                }
                else if (cur_pos1 == 75)
                {
                    cur_pos1 = 95;
                    displayboard(95, "-P1-"); // portal
                }
                else
                {
                    displayboard(cur_pos1, "-P1-");
                }
                printf("\t\t\t\tDice = %d\n", dice);
                printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            }
            else
            {
                cur_pos1 = cur_pos1 - dice;
                displayboard(cur_pos1, "-P1-");
                printf("\t\t\t\tDice = %d\n", dice);
                printf("\t\t      Range exceeded of Player 1.\n");
                printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            }
            printf("\t\t\tPlayer 2 position is %d\n\n", cur_pos2);
        }

        else
        {
            system("color 6");
            dice = rd();
            system("cls");
            printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            printf("\t\t\t  |||  PORTAL RUSH  |||\n");
            printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            cur_pos2 = dice + cur_pos2;
            if (cur_pos2 < 101)
            {
                if (cur_pos2 == 10)
                {
                    cur_pos2 = 30;
                    displayboard(30, "-P2-"); // portal
                }
                else if (cur_pos2 == 15)
                {
                    cur_pos2 = 35;
                    displayboard(35, "-P2-"); // portal
                }
                else if (cur_pos2 == 20)
                {
                    cur_pos2 = 40;
                    displayboard(40, "-P2-"); // portal
                }
                else if (cur_pos2 == 25)
                {
                    cur_pos2 = 50;
                    displayboard(50, "-P2-"); // portal
                }
                else if (cur_pos2 == 30)
                {
                    cur_pos2 = 60;
                    displayboard(60, "-P2-"); // portal
                }
                else if (cur_pos2 == 40)
                {
                    cur_pos2 = 65;
                    displayboard(65, "-P2-"); // portal
                }
                else if (cur_pos2 == 50)
                {
                    cur_pos2 = 70;
                    displayboard(70, "-P2-"); // portal
                }
                else if (cur_pos2 == 55)
                {
                    cur_pos2 = 75;
                    displayboard(75, "-P2-"); // portal
                }
                else if (cur_pos2 == 60)
                {
                    cur_pos2 = 80;
                    displayboard(80, "-P2-"); // portal
                }
                else if (cur_pos2 == 65)
                {
                    cur_pos2 = 85;
                    displayboard(85, "-P2-"); // portal
                }
                else if (cur_pos2 == 70)
                {
                    cur_pos2 = 90;
                    displayboard(90, "-P2-"); // portal
                }
                else if (cur_pos2 == 75)
                {
                    cur_pos2 = 95;
                    displayboard(95, "-P2-"); // portal
                }
                else
                {
                    displayboard(cur_pos2, "-P2-");
                }
                printf("\t\t\t\tDice = %d\n", dice);
                printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            }

            else
            {
                cur_pos2 = cur_pos2 - dice;
                displayboard(cur_pos2, "-P2-");
                printf("\t\t\t\tDice = %d\n", dice);
                printf("\t\t      Range exceeded of Player 2.\n");
                printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            }
            printf("\t\t\tPlayer 1 position is %d\n\n", cur_pos1);
        }
        if (ch == 27)
        {
            system("cls");
            mainMenu();
        }
    }
}
