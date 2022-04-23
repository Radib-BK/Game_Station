int AHmain()
{
    setcursor(0, 0);
    srand((unsigned)time(NULL));
    do
    {
        system("cls");
        system("color 5");
        gotoxy(43, 9);
        std::cout << " --------------------- ";
        gotoxy(43, 10);
        std::cout << " |    ALIEN HUNTER   |     ";
        gotoxy(43, 11);
        std::cout << " ---------------------";
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
            playAH();
        }
        else if (op == '2')
        {
            Beep(1459, 105);
            instructionsAH();
        }

        else if (op == '3')
        {
            system("cls");
            system("color 7");
            Beep(1459, 105);
            mainMenu();
        }
    } while (1);

    return 0;
}
void drawBorderAH()
{


    for (int i = 22; i <= SCREEN_WIDTH; i++)
    {
        gotoxy(i, SCREEN_HEIGHT + 2);
        printf("%c", 193);
    }

    for (int i = 2; i <= SCREEN_HEIGHT + 1; i++)
    {
        gotoxy(22, i);
        printf("%c", 208);

        gotoxy(SCREEN_WIDTH, i);
        printf("%c", 208);
    }
    for (int i = 2; i <= SCREEN_HEIGHT + 1; i++)
    {
        gotoxy(WIN_WIDTH, i);

        printf("%c", 208);
    }
}
void genAliens(int ind)                         // generate alien
{
    AliensX[ind] = 23 + rand() % (42);
}
void drawAliens(int ind)                        // Alien Shape
{
    if (AliensFlag[ind] == true)
    {
        gotoxy(AliensX[ind], AliensY[ind] + 1);
        std::cout << "---";
        gotoxy(AliensX[ind], AliensY[ind] + 2);
        printf("%c%c%c", 92, 32, 47);

        gotoxy(AliensX[ind], AliensY[ind] + 3);
        printf("%c%c%c", 234, 232, 234);

        gotoxy(AliensX[ind], AliensY[ind] + 4);

        printf(" %c", 157);
    }
}
void eraseAliens(int ind)                   // vanish Alien
{
    if (AliensFlag[ind] == true)
    {
        gotoxy(AliensX[ind], AliensY[ind] + 1);
        std::cout << "    ";
        gotoxy(AliensX[ind], AliensY[ind] + 2);
        std::cout << "    ";
        gotoxy(AliensX[ind], AliensY[ind] + 3);
        std::cout << "    ";
        gotoxy(AliensX[ind], AliensY[ind] + 4);
        std::cout << "    ";
    }
}
void resetAliens(int ind)
{
    eraseAliens(ind);
    AliensY[ind] = 4;
    genAliens(ind);
}
void genBullet()
{
    bullets[bIndex][0] = 25;
    bullets[bIndex][1] = ShipPos;
    bullets[bIndex][2] = 25;
    bullets[bIndex][3] = ShipPos + 4;
    bIndex++;
    if (bIndex == 10)
        bIndex = 0;
}
void moveBullet()
{
    for (int i = 0; i < 20; i++)
    {
        if (bullets[i][0] > 2)
            bullets[i][0]--;
        else
            bullets[i][0] = 0;

        if (bullets[i][2] > 2)
            bullets[i][2]--;
        else
            bullets[i][2] = 0;
    }
}
void drawBullets()
{
    for (int i = 0; i < 20; i++)
    {
        if (bullets[i][0] > 1)
        {
            gotoxy(bullets[i][1], bullets[i][0]);
            std::cout << "^";
            gotoxy(bullets[i][3], bullets[i][2]);
            std::cout << "^";
        }
    }
}
void eraseBullets()
{
    for (int i = 0; i < 20; i++)
    {
        if (bullets[i][0] >= 0)
        {
            gotoxy(bullets[i][1], bullets[i][0]);
            std::cout << " ";
            gotoxy(bullets[i][3], bullets[i][2]);
            std::cout << " ";
        }
    }
}
void eraseBullet(int i)
{
    gotoxy(bullets[i][1], bullets[i][0]);
    std::cout << " ";
    gotoxy(bullets[i][3], bullets[i][2]);
    std::cout << " ";
}
void drawShip()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            gotoxy(j + ShipPos, i + 25);
            std::cout << Ship[i][j];
        }
    }
}
void eraseShip()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            gotoxy(j + ShipPos, i + 25);
            std::cout << " ";
        }
    }
}
int collision()
{
    if (AliensY[0] + 2 >= 23)  // border height 26


    {
        // 35 is the half of width

        if (AliensX[0] + 4 - ShipPos >= 0 && AliensX[0] + 4 - ShipPos <18)
        {
            return 1;
        }
    }
    return 0;
}
int bulletHit()
{

    //for alien 1

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 4; j += 2)
        {
            if (bullets[i][j] != 0)
            {
                if (bullets[i][j] >= AliensY[0] && bullets[i][j] <= AliensY[0] + 4)
                {
                    if (bullets[i][j + 1] >= AliensX[0] && bullets[i][j + 1] <= AliensX[0] + 4)
                    {
                        Beep(6059, 80);
                        eraseBullet(i);
                        bullets[i][j] = 0;
                        resetAliens(0);
                        return 1;
                    }
                }


         //foe alien 2

                if (bullets[i][j] >= AliensY[1] && bullets[i][j] <= AliensY[1] + 4)
                {
                    if (bullets[i][j + 1] >= AliensX[1] && bullets[i][j + 1] <= AliensX[1] + 4)
                    {
                        Beep(6059, 80);
                        eraseBullet(i);
                        resetAliens(1);
                        bullets[i][j] = 0;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
void gameoverAH()
{
    Beep(700, 80);
    system("cls");
    system("color C");
    char ch;


    std::cout << std::endl;
    std::cout << std::endl;
    gotoxy(44, 10);
    std::cout << "---->>>> Game Over <<<<----" <<std::endl;
    gotoxy(44, 11);
    std::cout << "___________________________";

    FILE *fpAH = fopen("hunter.txt", "r");
    int hs = deserialAH(scoreAH, fpAH);

    gotoxy(45, 14);
    std::cout << "Your score :" << scoreAH << std::endl;
    gotoxy(45, 15);
    std::cout << "High score :" << hs << std::endl;
    gotoxy(45, 18);
    std::cout << "Retry?(y/n) = "; // if wannna playAH agian
    std::cin >> ch;
    ch = tolower(ch);
    if (ch == 'y')
    {
        playAH();
    }
    else
    {
        system("color 7");
        mainMenu();
    }
}
void updateScoreAH()
{

    FILE *fpAH = fopen("hunter.txt", "a+");
    serialAH(scoreAH, fpAH);
}
void instructionsAH()
{

    system("cls");
    gotoxy(43, 9);
    system("color D");
    std::cout << "INSTRUCTION";
    gotoxy(41, 10);
    std::cout << "----------------";
    gotoxy(30, 13);
    std::cout << "1. Shoot aliens by tapping space bar ";
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
void playAH()
{

    system("cls");
    system("color 6");

    ShipPos = 10 + WIN_WIDTH / 2;
    scoreAH = 0;
    AliensFlag[0] = 1;
    AliensFlag[1] = 1;
    AliensY[0] = AliensY[1] = 1;

    for (int i = 0; i < 20; i++)
    {
        bullets[i][0] = bullets[i][1] = 0;
    }

    system("cls");
    drawBorderAH();
    genAliens(0);
    genAliens(1);
    genAliens(2);

    gotoxy(WIN_WIDTH + 5, 13);
    std::cout << "Control ";
    gotoxy(WIN_WIDTH + 5, 14);
    std::cout << "-------- ";
    gotoxy(WIN_WIDTH + 5, 15);
    std::cout << "<- Key - Left";
    gotoxy(WIN_WIDTH + 5, 16);
    std::cout << "-> Key - Right";

    gotoxy(36, 13);
    std::cout << "Press any key to start";
    getch();
    gotoxy(36, 13);
    std::cout << "                      ";

    while (1)
    {
        if (kbhit())
        {
            char ch = getch();
            if (ch == 75)
            {
                if (ShipPos > 26)
                    ShipPos -= 5;
            }
            if (ch == 77)
            {
                if (ShipPos < 62)
                    ShipPos += 5;
            }
            if (ch == 32)
            {
                genBullet();
                // drawBullets();
            }
            if (ch == 27)
            {
                updateScoreAH();
                gameoverAH();
            }
        }
        gotoxy(WIN_WIDTH + 5, 10);
        std::cout << "score: " << scoreAH << std::endl;
        drawShip();
        drawAliens(0);
        drawAliens(1);
        drawAliens(2);
        drawBullets();
        if (collision() == 1)
        {
            updateScoreAH();
            gameoverAH();
            return;
        }
        if (bulletHit() == 1)
        {
            scoreAH++;
        }
        Sleep(108);

        eraseShip();
        eraseAliens(0);
        eraseAliens(1);

        eraseBullets();
        moveBullet();

        if (AliensFlag[0] == 1)
            AliensY[0] += 1;

        if (AliensFlag[1] == 1)
            AliensY[1] += 1;

        if (AliensY[0] > SCREEN_HEIGHT - 4)
        {
            resetAliens(0);
        }
        if (AliensY[1] > SCREEN_HEIGHT - 4)
        {
            resetAliens(1);
        }
    }
}
int serialAH(int x, FILE *fpAH)
{
    fpAH = fopen("hunter.txt", "a+");
    fprintf(fpAH, "%d ", x);
    fclose(fpAH);
}
int deserialAH(int x, FILE *fpAH)         // show data
{
    int i = 0;
    int num[100];
    char ch;

    fpAH = fopen("hunter.txt", "r");

    while (!feof(fpAH))
    {
        fscanf(fpAH, "%d ", &num[i]);

        i++;
    }
    remove("hunter.txt");
    fclose(fpAH);

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

    FILE *fpAH1 = fopen("hunter.txt", "w");
    for (int k = 0; k < i; k++)
    {
        fprintf(fpAH1, "%d ", num[k]);
    }

    fclose(fpAH1);
    return num[0];
}
