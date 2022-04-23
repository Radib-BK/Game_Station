int RAmain()
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
		std::cout << " |     >>  Racket  <<     | ";
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
			playRA();
		}
		else if (op == '2')
		{
			Beep(1459, 105);
			instructionsRA();
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
int serialRA(int x, FILE *fpRA) // store data
{
	fpRA = fopen("racket.txt", "a+");
	fprintf(fpRA, "%d ", x);
	fclose(fpRA);
	return 0;
}
int deserialRA(int x, FILE *fpRA) // show data
{
	int i = 0;
	int num[100000];
	char ch;

	fpRA = fopen("racket.txt", "r");
	while (!feof(fpRA))
	{
		fscanf(fpRA, "%d ", &num[i]);
		i++;
	}
	remove("racket.txt");
	fclose(fpRA);

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

	FILE *fpRA1 = fopen("racket.txt", "w");
	for (int k = 0; k < i; k++)
	{
		fprintf(fpRA1, "%d ", num[k]);
	}
	fclose(fpRA1);
	return num[0];
}

void instructionsRA()
{

	system("cls");
	gotoxy(43, 9);
	system("color 0B");
	std::cout << "INSTRUCTIONS";
	gotoxy(41, 10);
	std::cout << "----------------";
	gotoxy(30, 13);
	std::cout << ">> Hit ball by moving the racket. ";
	gotoxy(30, 15);
	std::cout << ">> Press 'up & down key' to move up & down.";
	gotoxy(30, 17);
	std::cout << ">> Player will have 2 life.";
	gotoxy(30, 19);
	std::cout << ">> Press 'escape' to exit.";
	gotoxy(30, 23);
	std::cout << "Press any key to go back to menu";
	getch();
}

void gameoverRA()
{
	lifeRA = 2;
	system("cls");
	system("color C");
	char ch;
	std::cout << std::endl;
	gotoxy(44, 10);
	std::cout << "---->>>> Game Over <<<<----" << std::endl;
	gotoxy(44, 11);
	std::cout << "___________________________";
	FILE *fpRA = fopen("racket.txt", "r");
	int hsRA = deserialRA(scoreRA, fpRA);
	gotoxy(45, 14);
	std::cout << "Your score :" << scoreRA << std::endl;
	gotoxy(45, 15);
	std::cout << "High score :" << hsRA << std::endl;
	gotoxy(45, 18);
	std::cout << "Retry?(y/n) = "; // if wannna playES agian
	std::cin >> ch;
	ch = tolower(ch);
	if (ch == 'y')
	{
		scoreRA = 0;
		playRA();
		player_racketwin = 0;
		cpuwin = 0;
		gol = 0;
	}

	else
	{
		system("color 7");
		mainMenu();
	}
}

void updatescoreRA()
{
	FILE *fpRA = fopen("racket.txt", "a+");
	serialRA(scoreRA, fpRA);
}

int playRA()
{

	system("cls");
	system("color E");

	char cell[r_border_vertical][r_border_horizon];

	// initialized cell
	int p_ini, p_final, cpuini, cpufinal, py, px;

	p_ini = 8;
	p_final = 12;

	cpuini = 8;
	cpufinal = 12;

	py = 9;	 // initial ball_racket coordinate
	px = 37; // initial ball_racket coordinate

	// movement
	int modx = -1;
	int mody = -1;
	int modia = -1;

	loop_racket(cell, p_ini, p_final, cpuini, cpufinal, px, py);
	gameloop_racket(cell, p_ini, p_final, cpuini, cpufinal, px, py, modx, mody, modia);

	if (player_racketwin == 1)
	{
		gotoxy(70, 10);
		printf("   !!! HURRAH...BONUS !!!\n");
		scoreRA += 10;
		player_racketwin = 0;
		getch();
		playRA();
	}

	if (cpuwin == 1)
	{
		cpuwin = 0;
		lifeRA -= 1;
		// gotoxy(69,12);
		// system("pause");
		if (lifeRA == 0)
		{
			updatescoreRA();
			gotoxy(70, 10);
			printf("    !!! You Lose !!!\n");
			getch();
			gameoverRA();
		}
		else
			playRA();
	}

	return 0;
}

void loop_racket(char cell[r_border_vertical][r_border_horizon], int p_ini, int p_final, int cpuini, int cpufinal, int py, int px)
{

	edge_racket(cell);
	player_racket(cell, p_ini, p_final);
	cpu_racket(cell, cpuini, cpufinal);
	ball_racket(cell, px, py);
}

void edge_racket(char cell[r_border_vertical][r_border_horizon]) //  Game border
{
	int i, j;
	for (i = 0; i < r_border_vertical; i++)
	{
		for (j = 0; j < r_border_horizon; j++)
		{
			if (i == 0 || i == r_border_vertical - 1)
			{
				cell[i][j] = 189;
			}
			else if (j == 0 || j == r_border_horizon - 1)
			{
				cell[i][j] = 182;
			}
			else
			{
				cell[i][j] = ' ';
			}
		}
	}
}

void show_racket(char cell[r_border_vertical][r_border_horizon]) // print game border
{
	int i, j;
	for (i = 0; i < r_border_vertical; i++)
	{
		for (j = 0; j < r_border_horizon; j++)
		{
			printf("%c", cell[i][j]);
		}
		printf("\n");
	}
}

void player_racket(char cell[r_border_vertical][r_border_horizon], int p_ini, int p_final) // player_racket racket draw_racket
{
	int i, j;
	for (i = p_ini; i < p_final; i++)
	{
		for (j = 2; j <= 3; j++)
		{
			cell[i][j] = '[';
		}
	}
}

void cpu_racket(char cell[r_border_vertical][r_border_horizon], int cpuini, int cpufinal) // computer racket draw_racket
{
	int i, j;
	for (i = cpuini; i < cpufinal; i++)
	{
		for (j = r_border_horizon - 4; j <= r_border_horizon - 3; j++)
		{
			cell[i][j] = ']';
		}
	}
}

void ball_racket(char cell[r_border_vertical][r_border_horizon], int py, int px) // ball_racket draw_racket
{
	cell[py][px] = 'O';
}

void gameloop_racket(char cell[r_border_vertical][r_border_horizon], int p_ini, int p_final, int cpuini, int cpufinal, int px, int py, int modx, int mody, int modia)
{
	gol = 0;
	do
	{
		draw_racket(cell);
		input_racket(cell, &p_ini, &p_final, &cpuini, &cpufinal, &px, &py, &modx, &mody, &modia, &gol);
		update_racket(cell, p_ini, p_final, cpuini, cpufinal, px, py);
		Sleep(50);
	} while (gol == 0);
}

void draw_racket(char cell[r_border_vertical][r_border_horizon])
{
	setcursor(0, 0);
	gotoxy(0, 0); // function for border draw_racket
	show_racket(cell);
}

void input_racket(char cell[r_border_vertical][r_border_horizon], int *p_ini, int *p_final, int *cpuini, int *cpufinal, int *px, int *py, int *modx, int *mody, int *modia, int *goal)
{
	int i;
	char key;
	char key2;

	if (*py == 1 || *py == r_border_vertical - 2) // logic for changing direction when about to touch the border
	{
		// If touch, change direction of ball_racket
		*mody *= -1;
	}

	if (*px == 1) // after crossing boundary the while loop_racket stops
	{
		// Verify GOL
		cpuwin = 1; // computer wins
		*goal = 1;
	}

	if (*px == r_border_horizon - 2) // ball_racket passed computer side
	{
		player_racketwin = 1;
		*goal = 1; // game stops
	}

	if (*px == 4) // player_racket racket is placed 4 cell in x axis
	{
		for (i = (*p_ini); i <= (*p_final); i++)
		{
			if (i == (*py))
			{
				scoreRA += 1;
				Beep(790, 250);
				*modx *= -1; // first *modx= -1, multiplying with -1 will change *modx= 1, vice versa
			}
		}
	}

	if (*px == r_border_horizon - 5) // computer racket is placed horizontal-5 cell in x axis
	{
		for (i = (*cpuini); i <= (*cpufinal); i++)
		{
			if (i == (*py))
			{
				Beep(790, 250);
				*modx *= -1; // first *modx= -1, multiplying with -1 will change *modx= 1, vice versa
			}
		}
	}

	if (*cpuini == 1 || *cpufinal == r_border_vertical - 1)
	{
		*modia *= -1; // logic for computer racket movement
	}

	// ball_racket movement
	if (*goal == 0)
	{
		*px += (*modx);
		*py += (*mody);
		// computer racket movement:
		*cpuini += (*modia);
		*cpufinal += (*modia);


		gotoxy(17, 23);
		std::cout << "  Life : " << lifeRA << "  Score : " << scoreRA << std::endl;

		// take input_racket
		if (kbhit())
		{
			key = getch();
			if (key == 27)
			{
				updatescoreRA();
				gameoverRA();
			}

			if (key == 72)
			{
				if (*p_ini != 1)
				{
					*p_ini -= 1;
					*p_final -= 1;
				}
			}

			if (key == 80)
			{
				if (*p_ini != r_border_vertical - 5)
				{
					*p_ini += 1;
					*p_final += 1;
				}
			}
		}
	}
}

void update_racket(char cell[r_border_vertical][r_border_horizon], int p_ini, int p_final, int cpuini, int cpufinal, int py, int px) // generate logic and border

{
	edge_racket(cell);
	player_racket(cell, p_ini, p_final);
	cpu_racket(cell, cpuini, cpufinal);
	ball_racket(cell, px, py);
}
