int SJmain()
{
    using namespace std;
    setcursor(0, 0);
    do
    {
        system("cls");
        system("color 02");
        gotoxy(42, 9);
        std::cout << " -------------------------- ";
        gotoxy(42, 10);
        std::cout << " |   >>> SUPER JUMP <<<   | ";
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
            playSJ();
        else if (op == '2')
            instructionsSJ();
        else if (op == '3')
        {
            system("color 7");
            system("cls");
            mainMenu();
        }
    } while (1);
    return 0;
}
int playSJ()
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
        std::cout << "\tPress Any Key To Start The Game...";
        getch();
        system("color 6");
        int scoreDJ = 0;
        bool isBool = true;
        int check=0;
        int x = 18;
        int scrnRow[3];
        int scrnCol[3];

        scrnCol[0] = 13;            //three initial positions for the bars
        scrnCol[1] = 38;
        scrnCol[2] = 26;

        scrnRow[0] = (rand() % 4 ) + 13;        //used for determing the height of the bars
        scrnRow[1] = (rand() % 4 ) + 13;        //used for determing the height of the bars
        scrnRow[2] = (rand() % 6 ) + 13;        //used for plastd::cing the coin

        std::string grid[20][40];

        for (int i = 0; i < 20; i++)            //creates the outer border
        {
            for (int j = 0; j < 40; j++)
            {
                if (i == 0 || i == 19 || j == 39 || j == 0)
                    grid[i][j] = 240;
                else
                    grid[i][j] = " ";
            }
        }
        while (isBool == true)
        {
            for (int i = 0; i < 3; i++)         //remove the bars
            {
                for (int j = 1; j < 19; j++)
                {
                    grid[j][scrnCol[i]] = " ";
                }
            }
            for (int i = 0; i < 3; i++)         //changes the position of the bars closer
            {
                scrnCol[i]--;
            }
            for (int i = 0; i < 2 ; i++)
            {
                for (int j = 1; j < 19; j++)        //generates the bars
                {
                    grid[j][scrnCol[i]] = "#";
                }
            }
            for (int i = 0; i < 2; i++)         //generates gaps in the bars
            {
                for (int j = 1; j <= scrnRow[i]; j++)
                {
                grid[j][scrnCol[i]] = " ";
                }
            }

            grid[scrnRow[2]][scrnCol[2]] = "0"; //generates the coin

            for (int i = 0; i < 2; i++)     //pushes back a bar at the end when its nearest
            {
                if (scrnCol[i] == 1)
                {
                    scrnCol[i] = 38;
                    scrnRow[i] = (rand() % 4 ) +13;
                }
            }

            if (scrnCol[2] == 1)
                {
                    scrnCol[2] = 38;
                    scrnRow[2] = (rand() % 6 ) +13;
                }

            grid[x-1][3] = " ";
            grid[x][3] = " ";
            if(check < 4)
            {
                if (kbhit())            //makes jump
                {
                    mv = getch();
                    if (mv == 27)
                    {
                        updatescoreSJ(scoreDJ);
                        gameoverSJ(scoreDJ);
                    }
                    x = x - 3;
                    check++;
                }
            }

            if (x==18)
            {
                check=0;
            }

            x++;
            if (x > 18)
                x = 18;

            if (grid[x][3] == "0" || grid[x-1][3] == "0" || grid[x-2][3] == "0" ||
                grid[x+1][3] == "0" ||grid[x][2] == "0" || grid[x-1][2] == "0" ||
                grid[x-2][2] == "0" || grid[x+1][2] == "0") {

                 Beep(2080, 40);
                 scoreDJ = scoreDJ + 1;

                }                        //increase score

            if (grid[x][3] == "#" || grid[x-1][3] == "#" || grid[x][2] == "#" || grid[x-1][2] == "#")      //die conditions
                isBool = false;

            grid[x-1][3] = "o";
            grid[x][3] = "^";                   //SJ player
            for (int i = 1; i < 19; i++)        //removes the bar at nearest
            {
                grid[i][1] = " ";
            }
            for (int i = 0; i < 20; i++)        //prints the entire screen again
            {
                for (int j = 0; j < 40; j++)
                {
                    std::cout << grid[i][j];
                }
                std::cout << std::endl;
            }
            std::cout <<"\n\t\tScore = " << scoreDJ;        //prints score
            delay(55000000);
            system("cls");
        }
        updatescoreSJ(scoreDJ);
        gameoverSJ(scoreDJ);
    }
    system("color 7");
    system("cls");
    return 0;
}

void instructionsSJ()
{

    system("cls");
    gotoxy(43, 9);
    system("color 0B");
    std::cout << "Instructions";
    gotoxy(41, 10);
    std::cout << "________________\n\n";
    gotoxy(30, 13);
    std::cout << ">> Avoid touching the pile of rocks ";
    gotoxy(30, 15);
    std::cout << ">> Press 'SPACE' to thrust up. You can trust 3 more times while on air.";
    gotoxy(30, 17);
    std::cout << ">> Collect the coins to score points";
    gotoxy(30, 19);
    std::cout << ">> Press 'escape' to exit\n\n";
    gotoxy(30, 23);
    std::cout << "Press any key to go back to menu";
    getch();
}

void gameoverSJ(int scoreDJ)
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

    FILE *fpDJ = fopen("SJ.txt", "r");
    int hs = deserialDJ(scoreDJ, fpDJ);

    gotoxy(45, 14);
    std::cout << "Your Score :" << scoreDJ << std::endl;
    gotoxy(45, 15);
    std::cout << "High Score :" << hs << std::endl;
    gotoxy(45, 18);
    std::cout << "RETRY? (y/n) = "; // if wannna play again
    std::cin >> ch;
    ch = tolower(ch);
    if (ch == 'y')
    {
        playSJ();
    }
    else
    {
        system("color 7");
        system("cls");
        mainMenu();
    }
    getch();
}
void updatescoreSJ(int scoreDJ) // print score
{
    //Beep(700, 80);
    FILE *fpDJ = fopen("SJ.txt", "a+");
    serialDJ(scoreDJ, fpDJ);
}
int serialDJ(int x, FILE *fpDJ)
{
    fpDJ = fopen("SJ.txt", "a+");
    fprintf(fpDJ, "%d ", x);
    fclose(fpDJ);
    return 0;
}
int deserialDJ(int x, FILE *fpDJ)
{
    int i = 0;
    int num[10000];
    char ch;

    fpDJ = fopen("SJ.txt", "r");

    while (!feof(fpDJ))
    {
        fscanf(fpDJ, "%d ", &num[i]);
        i++;
    }
    remove("SJ.txt");
    fclose(fpDJ);

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

    FILE *fpDJ1 = fopen("SJ.txt", "w");
    for (int k = 0; k < i; k++)
    {
        fprintf(fpDJ1, "%d ", num[k]);
    }

    fclose(fpDJ1);
    return num[0];
}
