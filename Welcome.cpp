void mainMenu(void) // function decleration
{
    while (1)
    {
        setcursor(0,0);
        Beep(2080,40);
        system("cls");
        system("color 3");
        int choose;

    printf("\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t\t\xba                                                                           \xba\n");
    printf("\t\t\xba                       !! >>>>> MAIN   MENU <<<<< !!                       \xba\n");
    printf("\t\t\xba                                                                           \xba\n");
    printf("\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n\n");

        printf("\n\t\t\t 1. JetPack Ride\t\t\t8. Portal Rush\n");
        printf("\n\t\t\t 2. Roll Ball\t\t\t\t9. Racket\n");
        printf("\n\t\t\t 3. Super Jump\t\t\t\t10. Space Combat\n");
        printf("\n\t\t\t 4. Ninja Shooter\t\t\t11. Find The Ace\n");
        printf("\n\t\t\t 5. Alien Hunter\t\t\t12. URA 31\n");
        printf("\n\t\t\t 6. Escape\t\t\t\t13. High Score Board\n");
        printf("\n\t\t\t 7. Hand Cricket\t\t\t14. Exit the Station\n\n\n");

        printf("\n\t\t\t\t\tChoose from 1 to 14 : ");
        scanf("%d", &choose);



        switch (choose) // switch to different case
        {
        case 1:
            JTmain();
            break;
        case 2:
            RLmain();
            break;
        case 3:
            SJmain();
            break;
        case 4:
            NImain();
            break;
        case 5:
            AHmain();
            break;
        case 6:
            ESmain();
            break;
        case 7:
            HCmain();
            break;
        case 8:
            PRmain();
            break;
        case 9:
            RAmain();
            break;
        case 10:
            SCmain();
            break;
        case 11:
            mainGA();
            break;
        case 12:
            URAmain();
            break;
        case 13:
            highscore();
            break;
        case 14:
            system("cls");
            system("color 7");
            exit(0);

        default:
            system("color 4");
            printf("\n\n\t\t\t\t\t >>> INVALID ENTRY <<<\n\n\t\t\t\t      PLEASE ENTER A VALID OPTION\n");
            getch();
            fflush(stdin);

            mainMenu();
        }
    }
}

int welcomescreen(void) // function for welcome screen
{
    setcursor(0,0);

    system("cls");
    system("color 02");
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
    printf("\t\t\t\xba                                                                           \xba\n");
    printf("\t\t\t\xba                 !! >>>>> WELCOME TO GAME STATION <<<<< !!                 \xba\n");
    printf("\t\t\t\xba                                                                           \xba\n");
    printf("\t\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");



    printf("\n\n\n\n\n\n\t\t\t\t\t    PRESS ANY KEY TO CONTINUE\n\n\n");
    getch(); // Use to hold screen for some seconds

    printf("\n\n\t\t\t\t\t\tLOADING");
    for (int i = 0; i < 4; i++)
    {
        Sleep(600);
        printf("...");
    }

    system("cls"); // Use to clear the screen
    mainMenu();
    return 0;
}
