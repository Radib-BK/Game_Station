int HCmain()
{
    mainmenu();
    return 0;
}

int bat(void)
{
    int comp, player;
    srand(time(0));
    do
    {
        fflush(stdin);
        printf(" Enter a number (1-6)\t: ");
        scanf("%d", &player);
    } while ((player < 1) || player > 6);

    comp = 1 + (rand() % 6);
    printf("\n Computer\t\t: %d \n Player\t\t\t: %d", comp, player);
    if (comp != player)
    {
        system("color 2");
        score = score + player;
        printf("\n\n\n\n Score\t\t\t: %d", score);
        getch();
        system("color 7");
        system("cls");
        return 1;
    }
    else
    {
        system("color 4");
        printf("\n\n\t!!! OUT !!! ");
        printf("\n\n\n\n Score\t\t\t: %d", score);
        getch();
        system("color 7");
        system("cls");
        return 0;
    }
}

int bowl(void)
{
    int player1, comp1;
    srand(time(0));
    do
    {
        fflush(stdin);
        printf(" Enter a number (1-6)\t: ");
        scanf("%d", &player1);
    } while ((player1 < 1) || player1 > 6);
    comp1 = 1 + (rand() % 6);
    printf("\n Computer\t\t: %d \n Player\t\t\t: %d", comp1, player1);
    if (comp1 != player1)
    {
        system("color 2");
        score1 = score1 + comp1;
        printf("\n\n\n\n Score\t\t\t: %d", score1);
        getch();
        system("cls");
        return 1;
    }
    else
    {
        system("color 4");
        printf("\n\n\t!!! OUT !!! ");
        printf("\n\n\n\n Score\t\t\t: %d", score1);
        getch();
        system("cls");
        return 0;
    }
}

void mainmenu(void)
{
    int choice;
    system("cls");
    printf("\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t\t\xba                                                                           \xba\n");
    printf("\t\t\xba             !! >>> WELCOME TO THE GAME OF HAND CRICKET <<< !!             \xba\n");
    printf("\t\t\xba                                                                           \xba\n");
    printf("\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n\n");
    printf("\n\n <<**********>> MAIN MENU <<**********>>\n\n\n");
    printf("\n 1 - Play Now  \n\n 2 - How To Play \n\n 3 - Exit Game \n\n\n\n");
    printf("\n Enter Your Choice : ");
    scanf("%d", &choice);
    system("cls");
    switch (choice)
    {
    case 1:
        startplay();
        mainmenu();
        break;

    case 2:
        system("color 3");
        printf("\n\n\t<<**********>> How to Play <<**********>>\n\n");
        printf("\n> Enter any numbers from 1 to 6\n");
        printf("\n> If your number and the computers number matches then- you are out\n");
        printf("\n> If not then that number will be added to your score\n");
        printf("\n> Score as much as you can when you are batting first and set a target\n");
        printf("\n> If the player batting second can score more then they will win!\n");
        printf("\n\n\n\t_______________HAVE FUN______________\n\n\n");
        getch();
        system("cls");
        system("color 7");
        mainmenu();
        break;

    case 3:
        system("color 7");
        mainMenu();

    default:
        system("color 4");
        printf("Enter a Valid Option....");
        fflush(stdin);
        getch();
        system("color 7");
        mainmenu();
        break;
    }
}

void startplay(void)
{
    int decision, toss, tossCheck, check = 1;
    score = 0;
    score1 = 0;
    srand(time(0));
    system("color 6");
    printf("\t>>> TOSS TIME <<<\n");
    printf("________________________________\n\n");
    printf("    ??? 'HEAD' or 'TAIL' ???\n\n\n");
    printf("If 'HEAD' press '1'- \n\nIf 'TAIL' press '2'- \n\n\n\nEnter Your Choice : ");
    scanf("%d", &toss);
    tossCheck = 1 + (rand() % 2);
    system("cls");
    system("color 7");
    if (tossCheck == toss)
    {
        printf("\n\n>>>  You WON The Toss  <<<\n\n\n");
        printf(">> '1' for BATTING \n\n>> '2' for BOWLING \n\nEnter Your Choice -> ");
        scanf("%d", &decision);
        system("cls");
    }
    else
    {
        decision = 2;
        Beep(6059, 80);
        printf("\n\n  You LOST The Toss....\n\n Opponent Elected to BAT First");
        getch();
        system("cls");
    }
    if (decision == 1)
    {
        Beep(6059, 80);
        do
        {
            printf("\t>---YOU ARE BATTING NOW---<\n\n");
            check = bat();
        } while (check != 0);
        printf("\n\n\n\t>>>> TARGET : %d <<<<\n\n",score+1);
        do
        {
            printf("\t>---YOU ARE BOWLING NOW---<\n\n");
            check = bowl();
            printf("\n\n\n\t>>>> TARGET : %d <<<<\n\n",score+1);
        } while (score1 <= score && check != 0);

        if (score1 < score)
        {
            system("cls");
            system("color A");
            printf("\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            printf("\t\t\xba                      !!!!   CONGRATULATIONS   !!!!                        \xba\n");
            printf("\t\t\xba                                                                           \xba\n");
            printf("\t\t\xba                 >>>>>>> YOU HAVE WON THE MATCH <<<<<<<                    \xba\n");
            printf("\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            getch();
            system("cls");
            system("color 7");
        }
        else if (score1 == score)
        {
            system("cls");
            system("color 6");
            printf("\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            printf("\t\t\xba                         !!!!   GOOD GAME    !!!!                          \xba\n");
            printf("\t\t\xba                                                                           \xba\n");
            printf("\t\t\xba                 >>>>>>> CLOSE CALL ! MATCH TIED <<<<<<<                   \xba\n");
            printf("\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            getch();
            system("cls");
            system("color 7");
        }
        else
        {
            system("cls");
            system("color 4");
            printf("\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            printf("\t\t\xba                           !!!!   OH NO    !!!!                            \xba\n");
            printf("\t\t\xba                                                                           \xba\n");
            printf("\t\t\xba                 >>>>>>> YOU HAVE LOST THE MATCH <<<<<<<                   \xba\n");
            printf("\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            getch();
            system("cls");
            system("color 7");
        }
    }
    else
    {
        do
        {
            printf("\t>---YOU ARE BOWLING NOW---<\n\n");
            check = bowl();
        } while (check != 0);

        printf("\n\n\n\t>>>> TARGET : %d <<<<\n\n",score1+1);
        do
        {
            printf("\t>---YOU ARE BATTING NOW---<\n\n");
            check = bat();
            printf("\n\n\n\t>>>> TARGET : %d <<<<\n\n",score1+1);
        } while (score <= score1 && check != 0);

        if (score1 < score)
        {
            system("cls");
            system("color A");
            printf("\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            printf("\t\t\xba                      !!!!   CONGRATULATIONS   !!!!                        \xba\n");
            printf("\t\t\xba                                                                           \xba\n");
            printf("\t\t\xba                 >>>>>>> YOU HAVE WON THE MATCH <<<<<<<                    \xba\n");
            printf("\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            getch();
            system("cls");
            system("color 7");
        }
        else if (score1 == score)
        {
            system("cls");
            system("color 6");
            printf("\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            printf("\t\t\xba                         !!!!   GOOD GAME    !!!!                          \xba\n");
            printf("\t\t\xba                                                                           \xba\n");
            printf("\t\t\xba                 >>>>>>> CLOSE CALL ! MATCH TIED <<<<<<<                   \xba\n");
            printf("\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            getch();
            system("cls");
            system("color 7");
        }
        else
        {
            system("cls");
            system("color 4");
            printf("\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            printf("\t\t\xba                           !!!!   OH NO    !!!!                            \xba\n");
            printf("\t\t\xba                                                                           \xba\n");
            printf("\t\t\xba                 >>>>>>> YOU HAVE LOST THE MATCH <<<<<<<                   \xba\n");
            printf("\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            printf("\t\t-----------------------------------------------------------------------------");
            getch();
            system("cls");
            system("color 7");
        }
    }
}
