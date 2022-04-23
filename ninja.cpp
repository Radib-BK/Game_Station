int NImain()
{
    setcursor(0, 0);
    do
    {
        system("cls");
        system("color 02");
        gotoxy(42, 9);
        std::cout << " -------------------------- ";
        gotoxy(42, 10);
        std::cout << " |  >> NINJA  SHOOTER <<  | ";
        gotoxy(42, 11);
        std::cout << " --------------------------";
        gotoxy(45, 13);
        std::cout << "1. START GAME";
        gotoxy(45, 15);
        std::cout << "2. Instructions";
        gotoxy(45, 17);
        std::cout << "3. QUIT";
        gotoxy(45, 21);
        std::cout << "Select an Option- ";
        char op = getch();

        if (op == '1')
            playNinja();
        else if (op == '2')
            instructionsNinja();
        else if (op == '3')
        {
            system("color 7");
            system("cls");
            mainMenu();
        }
    } while (1);
    return 0;
}

int playNinja()
{
    system("cls");
    char mv;
    char repeat = 'y';
    int highscore = 0;
    while (repeat == 'y')
    {
        srand(time(0));
        system("cls");
        system("color 6");
        gotoxy(36, 15);
        std::cout << "\tPress Any Key To Start...";
        getch();
        system("color 2");
        int shoot;
        int shotleft, shotright, shotup, shotdown;
        int xtemp, ytemp;
        int change = 0;
        int scoreNS = 0, check = 0;
        time_t start = time(NULL);
        bool isBool = true;
        int x = 12, y = 25;
        int scrnCol[3];
        int scrnRow[3];

        for (int i = 0; i < 3; i++)             // used for determing the positon of the targets
        {
            scrnRow[i] = (rand() % 20) + 3;
            scrnCol[i] = (rand() % 45) + 3;
        }

        std::string grid[25][50];
        for (int i = 0; i < 25; i++)            // creates the outer border
        {
            for (int j = 0; j < 50; j++)
            {
                if (i == 0 || i == 24 || j == 49 || j == 0)
                    grid[i][j] = 240;
                else
                    grid[i][j] = " ";
            }
        }
        while (isBool == true)                 // creates the beeping color
        {
            change++;                          // if wanted altering color
            if (change % 2 == 0)
                system("color 6");
            else
                system("color 6");

            for (int i = 0; i < 3; i++)        // new positon of the targets when hit
            {
                if (check == 1)
                {
                    for (int j = 0; j < 3; j++)
                        grid[scrnRow[j]][scrnCol[j]] = " ";

                    scrnRow[i] = (rand() % 20) + 3;
                    scrnCol[i] = (rand() % 45) + 3;
                }
            }
            for (int i = 0; i < 3; i++)         //prints the targets
            {
                grid[scrnRow[i]][scrnCol[i]] = "O";
            }
            check = 0;
            grid[x][y] = " ";
            if (kbhit())                        // moving and shooting
            {
                mv = getch();
                if (mv == 72)
                    x = x - 1;
                else if (mv == 80)
                    x = x + 1;
                else if (mv == 75)
                    y = y - 1;
                else if (mv == 77)
                    y = y + 1;
                else if (mv == 'a' && shoot != 1)
                {
                    shotleft = 1;
                    shoot = 1;
                    xtemp = x;
                    ytemp = y;
                }
                else if (mv == 's' && shoot != 1)
                {
                    shotdown = 1;
                    shoot = 1;
                    xtemp = x;
                    ytemp = y;
                }
                else if (mv == 'd' && shoot != 1)
                {
                    shotright = 1;
                    shoot = 1;
                    xtemp = x;
                    ytemp = y;
                }
                else if (mv == 'w' && shoot != 1)
                {
                    shotup = 1;
                    shoot = 1;
                    xtemp = x;
                    ytemp = y;
                }
                else if (mv == 27)
                {
                    updatescoreNinja(scoreNS);
                    gameoverNinja(scoreNS);
                }
            }

            if (shotleft == 1)                  //shooting left
            {
                ytemp = ytemp - 3;
                if (grid[xtemp][ytemp] == "O" || grid[xtemp][ytemp + 1] == "O" || grid[xtemp][ytemp + 2] == "O")
                    check = 1;
                if (ytemp > 0)
                    grid[xtemp][ytemp] = "*";
                grid[xtemp][ytemp + 3] = " ";
                if (ytemp <= 1 || check == 1)
                {
                    if (ytemp > 0)
                    {
                        grid[xtemp][ytemp] = " ";
                        grid[xtemp][ytemp+1] = " ";
                        grid[xtemp][ytemp+2] = " ";
                    }
                    shoot = 0;
                    shotleft = 0;
                }
            }
            if (shotright == 1)                 // shooting right
            {
                ytemp = ytemp + 3;
                if (grid[xtemp][ytemp] == "O" || grid[xtemp][ytemp - 1] == "O" || grid[xtemp][ytemp - 2] == "O")
                    check = 1;
                if (ytemp < 48)
                    grid[xtemp][ytemp] = "*";
                grid[xtemp][ytemp - 3] = " ";
                if (ytemp >= 48 || check == 1)
                {
                    if (ytemp < 48)
                    {
                        grid[xtemp][ytemp] = " ";
                        grid[xtemp][ytemp-1] = " ";
                        grid[xtemp][ytemp-2] = " ";
                    }
                    shoot = 0;
                    shotright = 0;
                }
            }
            if (shotdown == 1)                  // shooting down
            {
                xtemp++;
                if (grid[xtemp][ytemp] == "O")
                    check = 1;
                grid[xtemp][ytemp] = "*";
                grid[xtemp - 1][ytemp] = " ";
                if (xtemp == 23 || check == 1)
                {
                    grid[xtemp][ytemp] = " ";
                    shoot = 0;
                    shotdown = 0;
                }
            }
            if (shotup == 1)                    // shooting up
            {
                xtemp--;
                if (grid[xtemp][ytemp] == "O")
                    check = 1;
                grid[xtemp][ytemp] = "*";
                grid[xtemp + 1][ytemp] = " ";
                if (xtemp == 1 || check == 1)
                {
                    grid[xtemp][ytemp] = " ";
                    shoot = 0;
                    shotup = 0;
                }
            }

            if (x > 23) x = 23;             // ninja cant cross the borders
            if (x < 1) x = 1;
            if (y > 48) y = 48;
            if (y < 1) y = 1;

            grid[x][y] = "X";                   // our ninja

                if (check == 1){
                     Beep(6059, 80);
                    scoreNS = scoreNS + 5;     // increase score
                }


            for (int i = 0; i < 25; i++)        // prints the entire screen again
            {
                for (int j = 0; j < 50; j++)
                {
                    std::cout << grid[i][j];
                }
                std::cout << std::endl;
            }

            std::cout << "\n\tSCORE : " << scoreNS << "\tTIME LEFT : " << 120-(time(NULL)-start) << "s" <<std::endl;

            if ((time(NULL) - start) > 119)     // game end conditions
                isBool = false;

            //Sleep(180);
            delay(60000000);
            system("cls");
        }
        updatescoreNinja(scoreNS);
        gameoverNinja(scoreNS);
    }
    system("color 7");
    system("cls");
    return 0;
}

void instructionsNinja()
{

    system("cls");
    gotoxy(35, 7);
    system("color 0B");
    std::cout << "Instructions";
    gotoxy(25, 8);
    std::cout << "________________________________\n\n";
    gotoxy(11, 12);
    std::cout << ">> Press '^' to move up; 'v' to move down; '>' to move left; '<' to move right.";
    gotoxy(11, 14);
    std::cout << ">> Press 'w' to shoot up; 's' to shoot down; 'd' to shoot left; 'a' to shoot right.";
    gotoxy(11, 16);
    std::cout << ">> Move within the screen to get a good position to shoot.";
    gotoxy(11, 18);
    std::cout << ">> Try to Shoot the targets and hit them.";
    gotoxy(11, 20);
    std::cout << ">> For every successful hit, player will be granted 5 points, and the targets will take new positions";
    gotoxy(11, 22);
    std::cout << ">> Player cannot shoot until their ninja-star hits a target or hits the borders";
    gotoxy(11, 25);
    std::cout << "Press any key to go back to menu";
    getch();
}

void gameoverNinja(int scoreNS)
{
    Beep(6059, 80);
    system("cls");
    system("color C");
    char ch;
    std::cout << std::endl;
    gotoxy(44, 10);
    std::cout << "---->>>> Game Over <<<<----" << std::endl;
    gotoxy(44, 11);
    std::cout << "___________________________";

    FILE *fpNS = fopen("ninja.txt", "r");
    int hs = deserialNS(scoreNS, fpNS);

    gotoxy(45, 14);
    std::cout << "Your Score :" << scoreNS << std::endl;
    gotoxy(45, 15);
    std::cout << "High Score :" << hs << std::endl;
    gotoxy(45, 18);
    std::cout << "RETRY? (y/n) = "; // if wannna play again
    std::cin >> ch;
    ch = tolower(ch);
    if (ch == 'y')
    {
        playNinja();
    }
    else
    {
        system("color 7");
        system("cls");
        mainMenu();
    }
    getch();
}

void updatescoreNinja(int scoreNS) // print score
{
    // Beep(700, 80);
    FILE *fpNS = fopen("ninja.txt", "a+");
    serialNS(scoreNS, fpNS);
}

int serialNS(int x, FILE *fpNS)
{
    fpNS = fopen("ninja.txt", "a+");
    fprintf(fpNS, "%d ", x);
    fclose(fpNS);
    return 0;
}

int deserialNS(int x, FILE *fpNS)
{
    int i = 0;
    int num[10000];
    char ch;

    fpNS = fopen("ninja.txt", "r");

    while (!feof(fpNS))
    {
        fscanf(fpNS, "%d ", &num[i]);
        i++;
    }
    remove("ninja.txt");
    fclose(fpNS);

    for (int k = 0; k < i - 1; k++)
    {
        for (int j = 0; j < i - k - 1; j++)
        {
            if (num[j + 1] > num[j])
            {
                int temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }

    FILE *fpNS1 = fopen("ninja.txt", "w");
    for (int k = 0; k < i; k++)
    {
        fprintf(fpNS1, "%d ", num[k]);
    }

    fclose(fpNS1);
    return num[0];
}
