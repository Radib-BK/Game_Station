int SCmain()
{
    setcursor(0, 0);
    do
    {
        system("cls");
        system("color 02");
        gotoxy(42, 9);
        std::cout << " -------------------------- ";
        gotoxy(42, 10);
        std::cout << " |  >> SPACE SHOOTER <<   | ";
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
            playSpace();
        else if (op == '2')
            instructionsSpace();
        else if (op == '3')
        {
            system("color 7");
            system("cls");
            mainMenu();
        }
    } while (1);
    return 0;
}

int playSpace()
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
        int scoreSC = 0;
        int shot = 0;
        int check = 0;
        bool isBool = true;
        int x = 18, y = 20;
        int xt,yt;
        int scrnCol[3];
        int scrnRow[3];
        scrnRow[0] = 2;                     // three initial rows for the UFO
        scrnRow[1] = 4;
        scrnRow[2] = 6;
        for (int i = 0; i < 3; i++)
        {
            scrnCol[i] = (rand() % 31) + 2; // used for determing the initial positon of UFO
        }
        std::string grid[20][40];
        for (int i = 0; i < 20; i++)        // creates the outer border
        {
            for (int j = 0; j < 40; j++)
            {
                if (i == 0 || i == 19 || j == 39 || j == 0)
                    grid[i][j] = '|';
                else
                    grid[i][j] = " ";
            }
        }
        while (isBool == true)
        {
            change++;
            if (change % 2 == 0)
                system("color 9");
            else
                system("color 3");

            for (int i = 0; i < 3; i++)             // removes the UFOs
            {
                for (int j = 1; j < 39; j++)
                {
                    grid[scrnRow[i]][j] = " ";
                }
            }
            scrnCol[1]--;
            scrnCol[0]--;
            scrnCol[0]--;
            for (int i = 0; i < 3; i++)         // changes the position of the UFO closer to left border
            {
                scrnCol[i]--;
                if (scrnCol[i] <= 1)
                {
                    scrnCol[i] = 34;
                }
            }

            for (int i = 0; i < 3; i++)         // generates the UFOs
            {
                grid[scrnRow[i]][scrnCol[i]] = "<";
                grid[scrnRow[i]][scrnCol[i] + 1] = "#";
                grid[scrnRow[i]][scrnCol[i] + 2] = ">";
            }

            grid[x][y] = " ";            // removes shooter
            if (kbhit())                 // move to the sides and shoot
            {
                mv = getch();
                if (mv == 75)
                    y = y - 2;
                else if (mv == 77)
                    y = y + 2;
                else if (mv == 72 && shot != 1)
                {
                    shot = 1;
                    xt = x;
                    yt = y;
                }
                else if (mv == 27)
                {
                    updatescoreSpace(scoreSC);
                    gameoverSpace(scoreSC);
                }
            }

            if (shot == 1)                  // point increase
            {
                xt--;
                if (grid[xt][yt] == "#" || grid[xt][yt] == "<" || grid[xt][yt] == ">" || grid[xt][yt + 1] == "<" || grid[xt][yt + 1] == "#" || grid[xt][yt + 1] == ">" || grid[xt + 1][yt] == "<" || grid[xt + 1][yt] == "#" || grid[xt + 1][yt] == ">")
                {
                    Beep(700, 80);
                    system("color 4");
                    check = 1;
                    scoreSC++;
                }
                grid[xt][yt] = "|";
                grid[xt + 1][yt] = " ";
                if (xt == 1 || check == 1)
                {
                    grid[xt][yt] = " ";
                    shot = 0;
                    check = 0;
                }
            }

            if (y>38) y = 38;
            if (y<1) y = 1;

            grid[x][y] = "U";            // the shooter

            for (int i = 0; i < 20; i++) // prints the entire screen again
            {
                for (int j = 0; j < 40; j++)
                {
                    std::cout << grid[i][j];
                }
                std::cout << std::endl;
            }
            std::cout << "\n  SCORE : " << scoreSC << "\tTIME REMAINING : " << 120-(time(NULL)-start) << "s" << std::endl;

            if ((time(NULL) - start) > 119)     // game end conditions
                isBool = false;
            delay(60000000);
            //Sleep(50);
            system("cls");
        }
        updatescoreSpace(scoreSC);
        gameoverSpace(scoreSC);
    }
    system("color 7");
    system("cls");
    return 0;
}

void instructionsSpace()
{

    system("cls");
    gotoxy(43, 9);
    system("color 0B");
    std::cout << "Instructions";
    gotoxy(41, 10);
    std::cout << "________________\n\n";
    gotoxy(30, 13);
    std::cout << ">> Try to shoot the moving targets. Press '^' (up arrow key) to shoot";
    gotoxy(30, 15);
    std::cout << ">> Press '<-' (left arrow key) to move left";
    gotoxy(30, 17);
    std::cout << ">> Press '->' (right arrow key) to move right";
    gotoxy(30, 19);
    std::cout << ">> Shoot down as many UFOs as you can in 120 seconds";
    gotoxy(30, 21);
    std::cout << ">> Press 'escape' to exit\n\n";
    gotoxy(30, 24);
    std::cout << "Press any key to go back to menu";
    getch();
}

void gameoverSpace(int scoreSC)
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

    FILE *fpSC = fopen("SpaceCombat.txt", "r");
    int hs = deserialSC(scoreSC, fpSC);

    gotoxy(45, 14);
    std::cout << "Your Score :" << scoreSC << std::endl;
    gotoxy(45, 15);
    std::cout << "High Score :" << hs << std::endl;
    gotoxy(45, 18);
    std::cout << "RETRY? (y/n) = ";             // if wannna play again
    std::cin >> ch;
    ch = tolower(ch);
    if (ch == 'y')
    {
        playSpace();
    }
    else
    {
        system("color 7");
        system("cls");
        mainMenu();
    }
    getch();
}

void updatescoreSpace(int scoreSC)             // print score
{
    FILE *fpSC = fopen("SpaceCombat.txt", "a+");
    serialSC(scoreSC, fpSC);
}

int serialSC(int x, FILE *fpSC)
{
    fpSC = fopen("SpaceCombat.txt", "a+");
    fprintf(fpSC, "%d ", x);
    fclose(fpSC);
    return 0;
}

int deserialSC(int x, FILE *fpSC)
{
    int i = 0;
    int num[10000];
    char ch;

    fpSC = fopen("SpaceCombat.txt", "r");

    while (!feof(fpSC))
    {
        fscanf(fpSC, "%d ", &num[i]);
        i++;
    }
    remove("SpaceCombat.txt");
    fclose(fpSC);

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

    FILE *fpSC1 = fopen("SpaceCombat.txt", "w");
    for (int k = 0; k < i; k++)
    {
        fprintf(fpSC1, "%d ", num[k]);
    }

    fclose(fpSC1);
    return num[0];
}
