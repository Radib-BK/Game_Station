int RLmain()
{
    setcursor(0, 0);
    do
    {
        system("cls");
        system("color 02");
        gotoxy(42, 9);
        std::cout << " -------------------------- ";
        gotoxy(42, 10);
        std::cout << " |   >> ROLL THE BALL <<  | ";
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
            playRollBall();
        else if (op == '2')
            instructionsRollBall();
        else if (op == '3')
        {
            system("color 7");
            system("cls");
            mainMenu();
        }
    } while (1);
    return 0;
}

int playRollBall()
{
    system("cls");
    system("color 1");
    srand(time(0));
    char mv;
    char repeat = 'y';
    int highscore = 0;
    while (repeat == 'y')
    {

        system("cls");
        system("color 6");
        gotoxy(36, 15);
        std::cout << "\tPress Any Key To Start...";
        getch();
        system("color 2");
        time_t start = time(NULL);
        int change = 0;
        int scoreRB, pointRB = 0;
        bool isBool = true;
        int x = 2, y = 20;
        int scrnCol[3];
        int scrnRow[3];
        scrnRow[0] = 8; // three initial positions for the bars
        scrnRow[1] = 14;
        scrnRow[2] = 22;
        for (int i = 0; i < 3; i++)
        {
            scrnCol[i] = (rand() % 27) + 2; // used for determing the gap in bars
        }
        std::string grid[25][40];
        for (int i = 0; i < 25; i++) // creates the outer border
        {
            for (int j = 0; j < 40; j++)
            {
                if (i == 0 || i == 24 || j == 39 || j == 0)
                    grid[i][j] = 240;
                else
                    grid[i][j] = " ";
            }
        }
        while (isBool == true)
        {
            change++;
            if (change % 2 == 0)
                system("color 3");
            else
                system("color 9");

            for (int i = 0; i < 3; i++) // removes the bars
            {
                for (int j = 1; j < 39; j++)
                {
                    grid[scrnRow[i]][j] = " ";
                }
            }
            for (int i = 0; i < 3; i++) // changes the position of the bars closer
            {
                scrnRow[i]--;
            }

            for (int i = 0; i < 3; i++) // generates the bars
            {
                grid[scrnRow[i]][scrnCol[i]] = "_";
                grid[scrnRow[i]][scrnCol[i] + 1] = "_";
                grid[scrnRow[i]][scrnCol[i] + 2] = "_";
                grid[scrnRow[i]][scrnCol[i] + 3] = "_";
                grid[scrnRow[i]][scrnCol[i] + 4] = "_";
                grid[scrnRow[i]][scrnCol[i] + 5] = "_";
                grid[scrnRow[i]][scrnCol[i] + 6] = "_";
                grid[scrnRow[i]][scrnCol[i] + 7] = "_";
                grid[scrnRow[i]][scrnCol[i] + 8] = "_";
                grid[scrnRow[i]][scrnCol[i] + 9] = "_";
            }
            for (int i = 0; i < 3; i++) // pushes back a bar at the end when its nearest
            {
                if (scrnRow[i] == 1)
                {
                    scrnRow[i] = 23;
                    scrnCol[i] = (rand() % 27) + 2;
                }
            }
            if (grid[x][y] != "_")
            {
                grid[x][y] = " "; // clear the ball
            }

            if (kbhit()) // move to the sides
            {
                mv = getch();
                if (mv == 75)
                    y = y - 2;
                else if (mv == 77)
                    y = y + 2;
                else if (mv == 27)
                {
                    updatescoreRollBall(scoreRB);
                    gameoverRollBall(scoreRB);
                }
            }
            if (/* grid[x][y] == "_"  || */ grid[x - 1][y] == "_" )
                x--;
            else
                x++;

            pointRB++;
            scoreRB = pointRB / 5;

            if (x < 2 || x > 23 || y < 2 || y > 38) // die conditions
                isBool = false;

            grid[x][y] = "O";            // ball player
            for (int i = 1; i < 39; i++) // removes the bar at nearest
            {
                grid[1][i] = " ";
            }
            for (int i = 0; i < 25; i++) // prints the entire screen again
            {
                for (int j = 0; j < 40; j++)
                {
                    std::cout << grid[i][j];
                }
                std::cout << std::endl;
            }
            std::cout << "  \nSCORE : " << scoreRB << "\t  TIME SURVIVED : " << (time(NULL)-start) << "s" << std::endl;
            delay(60000000);
            //Sleep(60);
            system("cls");
        }
        updatescoreRollBall(scoreRB);
        gameoverRollBall(scoreRB);
    }
    system("color 7");
    system("cls");
    return 0;
}

void instructionsRollBall()
{

    system("cls");
    gotoxy(43, 9);
    system("color 0B");
    std::cout << "Instructions";
    gotoxy(41, 10);
    std::cout << "________________\n\n";
    gotoxy(30, 13);
    std::cout << ">> Avoid touching the border. Use the bars to stay in the screen. ";
    gotoxy(30, 15);
    std::cout << ">> Press '<-' to move left";
    gotoxy(30, 17);
    std::cout << ">> Press '->' to move right";
    gotoxy(30, 19);
    std::cout << ">> Press 'escape' to exit\n\n";
    gotoxy(30, 23);
    std::cout << "Press any key to go back to menu";
    getch();
}

void gameoverRollBall(int scoreRB)
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

    FILE *fpRB = fopen("roll.txt", "r");
    int hs = deserialRB(scoreRB, fpRB);

    gotoxy(45, 14);
    std::cout << "Your Score :" << scoreRB << std::endl;
    gotoxy(45, 15);
    std::cout << "High Score :" << hs << std::endl;
    gotoxy(45, 18);
    std::cout << "RETRY? (y/n) = "; // if wannna play again
    std::cin >> ch;
    ch = tolower(ch);
    if (ch == 'y')
    {
        playRollBall();
    }
    else
    {
        system("color 7");
        system("cls");
        mainMenu();
    }
    getch();
}

void updatescoreRollBall(int scoreRB) // print score
{
    // Beep(700, 80);
    FILE *fpRB = fopen("roll.txt", "a+");
    serialRB(scoreRB, fpRB);
}

int serialRB(int x, FILE *fpRB)
{
    fpRB = fopen("roll.txt", "a+");
    fprintf(fpRB, "%d ", x);
    fclose(fpRB);
    return 0;
}

int deserialRB(int x, FILE *fpRB)
{
    int i = 0;
    int num[10000];
    char ch;

    fpRB = fopen("roll.txt", "r");

    while (!feof(fpRB))
    {
        fscanf(fpRB, "%d ", &num[i]);
        i++;
    }
    remove("roll.txt");
    fclose(fpRB);

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

    FILE *fpRB1 = fopen("roll.txt", "w");
    for (int k = 0; k < i; k++)
    {
        fprintf(fpRB1, "%d ", num[k]);
    }

    fclose(fpRB1);
    return num[0];
}
