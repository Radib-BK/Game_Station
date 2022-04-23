int ESmain()
{
    setcursor(0, 0);
    srand((unsigned)time(NULL));

    do
    {
        system("cls");
        system("color 5");
        gotoxy(43, 9);
        std::cout << " -------------------------- ";
        gotoxy(43, 10);
        std::cout << " |   >>Dare to Escape<<   | ";
        gotoxy(43, 11);
        std::cout << " --------------------------";
        gotoxy(45, 13);
        std::cout << "1. START GAME";
        gotoxy(45, 15);
        std::cout << "2. INSTRUCTIONS";
        gotoxy(45, 17);
        std::cout << "3. QUIT";
        gotoxy(45, 19);
        std::cout << "Select an Option- ";
        char op = getch();

        if (op == '1')
        {
            Beep(1459, 105);
            playES();
        }
        else if (op == '2')
        {
            Beep(1459, 105);
            instructionsES();
        }

        else if (op == '3')
        {
            system("cls");
            system("color 1");

            Beep(1459, 105);
            mainMenu();
        }
    } while (1);
    return 0;
}

// input coordinate
void gotoxy(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}
// set bool visible = 0(invisible), bool visible = 1(visible)
void setcursor(bool visible, DWORD size)
{
    if (size == 0)
        size = 20; // size is 0 to 20

    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}
void drawBorderES()
{

    for (int i = 22; i <= SCREEN_WIDTH_ES; i++)
    {
        gotoxy(i, 1);
        printf("%c", 193);
    }

    for (int i = 22; i <= SCREEN_WIDTH_ES; i++)
    {
        gotoxy(i, SCREEN_HEIGHT_ES + 1);
        printf("%c", 193);
    }

    for (int i = 1; i <= SCREEN_HEIGHT_ES; i++)
    {
        gotoxy(22, i);
        printf("%c", 208);

        gotoxy(SCREEN_WIDTH_ES, i);
        printf("%c", 208);
    }
    for (int i = 1; i <= SCREEN_HEIGHT_ES; i++)
    {
        gotoxy(WIN_WIDTH_ES-5, i);

        printf("%c", 208);
    }
}
// missile fall down
void genMissile(int ind)
{
    missileX[ind] = 25 + rand() % (40);
}
// missile shape
void drawMissile(int ind)
{

    system("color 2");

    if (missileFlag[ind] == true)
    {
        gotoxy(missileX[ind], missileY[ind] + 1);
        std::cout << "|**|";
        gotoxy(missileX[ind], missileY[ind] + 2);
        std::cout << " ||";
        gotoxy(missileX[ind], missileY[ind] + 3);
        printf(" %c%c", 4, 4);
    }
    setcursor(0, 0);
}
// erase missile
void eraseMissile(int ind)
{
    if (missileFlag[ind] == true)
    {

        gotoxy(missileX[ind], missileY[ind] + 1);
        std::cout << "    ";
        gotoxy(missileX[ind], missileY[ind] + 2);
        std::cout << "   ";
        gotoxy(missileX[ind], missileY[ind] + 3);
        printf("   ");
    }
}
void resetMissile(int ind)
{
    Beep(6059, 80);
    eraseMissile(ind);
    missileY[ind] = 1;
    genMissile(ind);
}
// draw man
void drawMan()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            gotoxy(j + manPos, i + 22);
            if (i == 0 && j == 1)
                printf("%c", 2);
            if (i == 1 && j == 0)
                printf("%c", 201);
            if (i == 1 && j == 2)
                printf("%c", 187);

            std::cout << man[i][j];
        }
    }
    setcursor(0, 0);
}
// after colliding
void eraseMan()
{

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            gotoxy(j + manPos, i + 22);
            std::cout << " ";
        }
    }
}
// During collisionES
int collisionES()
{
    system("color 4");
    if (missileY[0] + 3 >= 22)
    {
        if (missileX[0] + 4 - manPos >= 0 && missileX[0] + 4 - manPos < 9)
        {
            return 1;
        }
    }

    return 0;
}
void gameoverES()
{

    //Beep(6059, 80);

    system("cls");
    system("color C");
    char ch;
    std::cout << std::endl;
    gotoxy(44, 10);
    std::cout << "---->>>> Game Over <<<<----" << std::endl;
    gotoxy(44, 11);
    std::cout << "___________________________";
    FILE *fpES = fopen("escape.txt", "r");
    int hs = deserialES(scoreES, fpES);
    gotoxy(45, 14);
    std::cout << "Your score :" << scoreES << std::endl;
    gotoxy(45, 15);
    std::cout << "High score :" << hs << std::endl;
    gotoxy(45, 18);
    std::cout << "Retry?(y/n) = "; // if wannna playES agian
    std::cin >> ch;
    ch = tolower(ch);
    if (ch == 'y')
    {
        playES();
    }

    else
    {
        system("color 7");
        mainMenu();
    }
}
// print scoreES
void updatescoreES()
{
    //Beep(700, 80);
    FILE *fpES = fopen("escape.txt", "a+");
    serialES(scoreES, fpES);
}
void instructionsES()
{

    system("cls");
    gotoxy(43, 9);
    system("color 0B");
    std::cout << "INSTRUCTIONS";
    gotoxy(41, 10);
    std::cout << "----------------";
    gotoxy(30, 13);
    std::cout << "1. Avoid missile by moving left or right. ";
    gotoxy(30, 15);
    std::cout << "2. Press '<-' to move left";
    gotoxy(30, 17);
    std::cout << "3. Press '->' to move right";
    gotoxy(30, 19);
    std::cout << "4. Press 'escape' to exit";
    gotoxy(30, 23);
    std::cout << "Press any key to go back to menu";
    getch();
}
void playES()
{

    system("cls");
    system("color 4");
    manPos = 10 + WIN_WIDTH_ES / 2;
    scoreES = 0;
    missileFlag[0] = 1;
    missileFlag[1] = 0;
    missileY[0] = missileY[1] = 1;

    system("cls");
    drawBorderES();
    updatescoreES();
    genMissile(0);
    genMissile(1);
    genMissile(2);

    gotoxy(WIN_WIDTH_ES + 2, 13);
    std::cout << "Control ";
    gotoxy(WIN_WIDTH_ES + 2, 14);
    std::cout << "-------- ";
    gotoxy(WIN_WIDTH_ES + 2, 15);
    std::cout << "<- Key - Left";
    gotoxy(WIN_WIDTH_ES + 2, 16);
    std::cout << "-> Key - Right";

    gotoxy(36, 13);
    std::cout << "Press Any Key To Start...";
    getch();
    gotoxy(36, 13);
    std::cout << "                              ";

    while (1)
    {
        if (kbhit())
        {
            char ch = getch();
            if (ch == 75) // left arrow ascii 75

            {
                if (manPos > 26) // screen start at 22
                    manPos -= 3;
            }
            if (ch == 77) // right arrow ascii 75
            {
                if (manPos <= 62) // screen width 70
                    manPos += 3;
            }
            if (ch == 27)
            {
                break;
            }
        }
        gotoxy(WIN_WIDTH_ES +2, 10);
        std::cout << "score: " << scoreES << std::endl;
        drawMan();
        drawMissile(0);
        drawMissile(1);
        drawMissile(2);
        if (collisionES() == 1)
        {
            updatescoreES();
            gameoverES();
        }

        Sleep(8);
        eraseMan();
        eraseMissile(0);
        eraseMissile(1);
        eraseMissile(2);

        if (missileY[0] == 5)
            if (missileFlag[1] == 0)
                missileFlag[1] = 1;

        if (missileFlag[0] == 1)
            missileY[0] += 1;

        if (missileFlag[1] == 1)
            missileY[1] += 1;

        if (missileY[0] > SCREEN_HEIGHT_ES - 4)
        {
            resetMissile(0);
            scoreES++;
            gotoxy(WIN_WIDTH_ES + 2, 10);
            std::cout << "score: " << scoreES << std::endl;
        }
        if (missileY[1] > SCREEN_HEIGHT_ES - 4)
        {
            resetMissile(1);
            scoreES++;
            gotoxy(WIN_WIDTH_ES + 2, 10);
            std::cout << "score: " << scoreES << std::endl;
        }
    }
}
int serialES(int x, FILE *fpES) // store data
{
    fpES = fopen("escape.txt", "a+");
    fprintf(fpES, "%d ", x);
    fclose(fpES);
}
int deserialES(int x, FILE *fpES) // show data
{
    int i = 0;
    int num[100000];
    char ch;

    fpES = fopen("escape.txt", "r");

    while (!feof(fpES))
    {
        fscanf(fpES, "%d ", &num[i]);

        i++;
    }
    remove("escape.txt");
    fclose(fpES);

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

    FILE *fpES1 = fopen("escape.txt", "w");
    for (int k = 0; k < i; k++)
    {
        fprintf(fpES1, "%d ", num[k]);
    }

    fclose(fpES1);
    return num[0];
}
