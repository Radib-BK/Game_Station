int JTmain()
{
    setcursor(0, 0);
    do
    {
        system("cls");
        system("color 02");
        gotoxy(42, 9);
        std::cout << " -------------------------- ";
        gotoxy(42, 10);
        std::cout << " |   >> JETPACK  RIDE <<  | ";
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
            playJetPack();
        else if (op == '2')
            instructionsJetPack();
        else if (op == '3')
        {
            system("color 7");
            system("cls");
            mainMenu();
        }
    } while (1);
    return 0;
}

int playJetPack()
{
    system("cls");
    srand(time(0));
    char mv;
    char repeat = 'y';
    int highscore = 0;
    while (repeat == 'y')
    {
        system("cls");
        system("color 6");
        gotoxy(36, 15);
        std::cout << "\tPress Any Key To Start The Game...";
        getch();
        system("color 2");
        int scoreJP = 0;
        bool isBool = true;
        int x = 9;
        int scrnRow[3];
        int scrnCol[3];
        scrnCol[0] = 13;            //three initial positions for the bars
        scrnCol[1] = 26;
        scrnCol[2] = 38;
        for (int i = 0; i < 3; i++)
        {
            scrnRow[i] = (rand() % 12 ) + 2;        //used for determing the gap in bars
        }

        char grid[20][40];

        //string grid[20][40];

        for (int i = 0; i < 20; i++)            //creates the outer border
        {
            for (int j = 0; j < 40; j++)
            {
                if (i == 0 || i == 19 || j == 39 || j == 0)
                    grid[i][j] = 240;
                else
                    grid[i][j] = ' ';
            }
        }
        while (isBool == true)
        {
            for (int i = 0; i < 3; i++)         //remove the bars
            {
                for (int j = 1; j < 19; j++)
                {
                    grid[j][scrnCol[i]] = ' ';
                }
            }
            for (int i = 0; i < 3; i++)         //changes the position of the bars closer
            {
                scrnCol[i]--;
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 1; j < 19; j++)        //generates the bars
                {
                    grid[j][scrnCol[i]] = '|';
                }
            }
            for (int i = 0; i < 3; i++)         //generates gaps in the bars
            {
                grid[scrnRow[i]][scrnCol[i]] = ' ' ;
                grid[scrnRow[i] + 1][scrnCol[i]] = ' ';
                grid[scrnRow[i] + 2][scrnCol[i]] = ' ';
                grid[scrnRow[i] + 3][scrnCol[i]] = '*';
                //grid[scrnRow[i] + 4][scrnCol[i]] = "*";
            }
            for (int i = 0; i < 3; i++)     //pushes back a bar at the end when its nearest
            {
                if (scrnCol[i] == 1)
                {
                    scrnCol[i] = 38;
                    scrnRow[i] = (rand() % 12 ) + 2;
                }
            }

            grid[x][3] = ' ';
            grid[x][4] = ' ';

            if (kbhit())            //makes jump
            {
                mv = getch();
                x = x - 3;
                if (mv == 27)
                {
                    updatescoreJetPack(scoreJP);
                    gameoverJetPack(scoreJP);
                }
            }
            x++;
            if (x < 1) x = 1;
            for (int i = 0; i < 3; i++)         //points add
            {
                if (scrnCol[i] == 3 || scrnCol[i] == 4)
                    if (grid[x][4] == '*' || grid[x][3] == '*')
                    {
                        Beep(700, 80);
                        scoreJP = scoreJP + 1;
                    }

                if (grid[x][3] == '|' || grid[x][4] == '|' || x >= 19 || x <= 1)      //die conditions
                    isBool = false;
            }

            grid[x][3] = 'C';               //jetpack player
            grid[x][4] = 2;

            for (int i = 1; i < 19; i++)        //removes the bar at nearest
            {
                grid[i][1] = ' ' ;
            }
            
            for (int i = 0; i < 20; i++)        //prints the entire screen again
            {
                for (int j = 0; j < 40; j++)
                {
                    std::cout << grid[i][j];
                }
                std::cout << std::endl;
            }
            std::cout <<"\n\t\tScore = " << scoreJP;        //prints score
            delay(60000000);
            system("cls");
        }
        updatescoreJetPack(scoreJP);
        gameoverJetPack(scoreJP);
    }
    system("color 7");
    system("cls");
    return 0;
}

void delay(int num)
{
    for (int i = 0; i < num; i++)
    {
    }
}

void instructionsJetPack()
{

    system("cls");
    gotoxy(43, 9);
    system("color 0B");
    std::cout << "Instructions";
    gotoxy(41, 10);
    std::cout << "________________\n\n";
    gotoxy(30, 13);
    std::cout << ">> Avoid touching the border and the trees ";
    gotoxy(30, 15);
    std::cout << ">> Press 'SPACE' to thrust up";
    gotoxy(30, 17);
    std::cout << ">> Collect the coins to score points";
    gotoxy(30, 19);
    std::cout << ">> Press 'escape' to exit\n\n";
    gotoxy(30, 23);
    std::cout << "Press any key to go back to menu";
    getch();
}

void gameoverJetPack(int scoreJP)
{
    Beep(6059, 80);
    system("cls");
    system("color C");
    char ch;
    std::cout << std::endl;
    gotoxy(44, 10);
    std::cout << "---->>>> Game Over <<<<----" << std::endl;
    gotoxy(44, 11);
    std::cout << "___________________________" ;

    FILE *fpRB = fopen("jetpack.txt", "r");
    int hs = deserialJP(scoreJP, fpRB);

    gotoxy(45, 14);
    std::cout << "Your Score :" << scoreJP << std::endl;
    gotoxy(45, 15);
    std::cout << "High Score :" << hs << std::endl;
    gotoxy(45, 18);
    std::cout << "RETRY? (y/n) = "; // if wannna play again
    std::cin >> ch;
    ch = tolower(ch);
    if (ch == 'y')
    {
        playJetPack();
    }
    else
    {
        system("color 7");
        system("cls");
        mainMenu();
    }
    getch();
}

void updatescoreJetPack(int scoreJP) // print score
{
    //Beep(700, 80);
    FILE *fpRB = fopen("jetpack.txt", "a+");
    serialJP(scoreJP, fpRB);
}

int serialJP(int x, FILE *fpRB)
{
    fpRB = fopen("jetpack.txt", "a+");
    fprintf(fpRB, "%d ", x);
    fclose(fpRB);
    return 0;
}

int deserialJP(int x, FILE *fpRB)
{
    int i = 0;
    int num[10000];
    char ch;

    fpRB = fopen("jetpack.txt", "r");

    while (!feof(fpRB))
    {
        fscanf(fpRB, "%d ", &num[i]);
        i++;
    }
    remove("jetpack.txt");
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

    FILE *fpRB1 = fopen("jetpack.txt", "w");
    for (int k = 0; k < i; k++)
    {
        fprintf(fpRB1, "%d ", num[k]);
    }

    fclose(fpRB1);
    return num[0];
}
