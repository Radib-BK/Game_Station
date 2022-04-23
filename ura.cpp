

int URAmain()
{

	homelogo();
	return 0;

}


void showCards(int *array_cards, int siz)
{
    setcursor(0,0);
	// card 'visuals' - no suits => infinite decks
    char ace[]="\n*************\
				\n* A         *\
		    	\n*           *\
				\n*           *\
				\n*           *\
				\n*     *     *\
				\n*           *\
				\n*           *\
				\n*           *\
				\n*         A *\
				\n*************\n\n";

    char two[]="\n*************\
				\n* 2         *\
		    	\n*           *\
				\n*     *     *\
				\n*           *\
				\n*           *\
				\n*           *\
				\n*     *     *\
				\n*           *\
				\n*         2 *\
				\n*************\n\n";

    char three[]="\n*************\
				\n* 3         *\
		    	\n*           *\
				\n*     *     *\
				\n*           *\
				\n*     *     *\
				\n*           *\
				\n*     *     *\
				\n*           *\
				\n*         3 *\
				\n*************\n\n";

    char four[]="\n*************\
				\n* 4         *\
		   		\n*           *\
				\n*  *     *  *\
				\n*           *\
				\n*           *\
				\n*           *\
				\n*  *     *  *\
				\n*           *\
				\n*         4 *\
				\n*************\n\n";

    char five[]="\n*************\
				\n* 5         *\
			    \n*           *\
				\n*  *     *  *\
				\n*           *\
				\n*     *     *\
				\n*           *\
				\n*  *     *  *\
				\n*           *\
				\n*         5 *\
				\n*************\n\n";

    char six[]="\n*************\
				\n* 6         *\
			    \n*           *\
				\n*  *     *  *\
				\n*           *\
				\n*  *     *  *\
				\n*           *\
				\n*  *     *  *\
				\n*           *\
				\n*         6 *\
				\n*************\n\n";

    char seven[]="\n*************\
				\n* 7         *\
			    \n*           *\
				\n*  *     *  *\
				\n*     *     *\
				\n*  *     *  *\
				\n*           *\
				\n*  *     *  *\
				\n*           *\
				\n*         7 *\
				\n*************\n\n";

    char eight[]="\n*************\
				\n* 8         *\
			    \n*           *\
				\n*  *     *  *\
				\n*     *     *\
				\n*  *     *  *\
				\n*     *     *\
				\n*  *     *  *\
				\n*           *\
				\n*         8 *\
				\n*************\n\n";

	const char nine[]="\n*************\
				\n* 9         *\
			    \n*  *     *  *\
				\n*           *\
				\n*  *     *  *\
				\n*     *     *\
				\n*  *     *  *\
				\n*           *\
				\n*  *     *  *\
				\n*         9 *\
				\n*************\n\n";

    char ten[]="\n*************\
				\n* 10        *\
	   			\n*  *     *  *\
				\n*     *     *\
				\n*  *     *  *\
				\n*           *\
				\n*  *     *  *\
				\n*     *     *\
				\n*  *     *  *\
				\n*        10 *\
				\n*************\n\n";

    char jack[]=
	           "\n*************\
				\n* J         *\
	   			\n*           *\
				\n*  J A C K  *\
				\n*    | |    *\
				\n*    | |    *\
				\n*    | |    *\
				\n*           *\
				\n*           *\
				\n*         J *\
				\n*************\n\n";

    char queen[]=
	           "\n*************\
				\n* Q         *\
	   			\n*           *\
				\n*  Q U EE N *\
				\n*    + +    *\
				\n*    + +    *\
				\n*    + +    *\
				\n*           *\
				\n*           *\
				\n*         Q *\
				\n*************\n\n";

	char king[]=
	           "\n*************\
				\n* K         *\
	   			\n*           *\
				\n*  K I N G  *\
				\n*    /\\     *\
				\n*   /  \\    *\
				\n* .vv   vv. *\
				\n* . . . . . *\
				\n*   \\  /    *\
				\n*    \\/   K *\
				\n*************\n\n";



	int c;
	for (c = 0; c < siz; c++)
	{
		switch(array_cards[c])
		{
			case(1):
				printf("%s", ace);
				break;
			case(2):
				printf("%s", two);
				break;
			case(3):
				printf("%s", three);
				break;
			case(4):
				printf("%s", four);
				break;
			case(5):
				printf("%s", five);
				break;
			case(6):
				printf("%s", six);
				break;
			case(7):
				printf("%s", seven);
				break;
			case(8):
				printf("%s", eight);
				break;
			case(9):
				printf("%s", nine);
				break;
			case(10):
				printf("%s", ten);
				break;
			case(11):
				printf("%s", jack);
				break;
			case(12):
				printf("%s", queen);
				break;
			case(13):
				printf("%s", king);
				break;
		}
	}
}


void homelogo()
{
    system("cls");
    system("Color 9");

    printf("\t\t\t\t  .--,-``-.    \t           \n\
			\t /   /     '.  \t     ,---, \n\
			\t/ ../        ; \t  ,`--.' | \n\
			\t\\ ``\\  .`-    '\t /    /  : \n\
			\t \\___\\/   \\   :\t:    |.' ' \n\
			\t      \\   :   |\t`----':  | \n\
			\t      /  /   / \t   '   ' ; \n\
			\t      \\  \\   \\ \t   |   | | \n\
			\t  ___ /   :   |\t   '   : ; \n\
			\t /   /\\   /   :\t   |   | ' \n\
			\t/ ,,/  ',-    .\t   '   : | \n\
			\t\\ ''\\        ; \t   ;   |.' \n\
			\t \\   \\     .'  \t   '---'   \n\
			\t  `--`-,,-'    \t           \n\
			\t               \t           \n\
			\t			   \t		  \n");






    Sleep(300);
	printf("\t\t\t\t   HI!! I AM MR.PUTIN\n\n\t\t  Lets play the URA 31 card game!!! YOU against ME  ");

	Sleep(790);
	printf("\n\n\t\t\t\n\n\t\tGet Ready");

	for(int i=0; i<5;i++)
    {
        Sleep(280);
        printf(" .");
    }

    Sleep(500);
	printf("\n\n\t\tPress '1' to Play");
	printf("\n\t\tPress '2' for the Rules");
	printf("\n\t\tPress '3' to Quit\t");

    key=getch();

	if(key =='1')

    {
       playURA();
    }





	if (key == '2')
	{
		system("cls");
		instructionsURA();
	}

	if (key == '3')

    mainMenu();

}



void playURA()
{
    setcursor(0,0);
    system("cls");
    system("color 06");

            newAce = 0;
            countAces = 0;
            sum_Y = 0;
            sum_P = 0;
            dealer_size = 2;
            flagAceN = 0;
            flagAceDD = 0;
            countAcesDD = 0;
            noob_size = 2;


	//deck array
	int deck[13];
	int c;
	for (c = 0; c < 13; c++ ) {
      deck[c] =  c + 1;
   	}


//Game loop for rolling cards

	while (key == '1'){
		system("cls");
		Sleep(600);
		printf("\n\tI am MR.PUTIN\n\tI am the dealer..Lets go.\n\n");
		Sleep(600);

		 printf("\n\tRolling cards...\n");
		Sleep(600);

		srand((unsigned)time(NULL));



		printf("\n..My 2nd card is hidden.\n");


        Sleep(1000);


		printf("\n..My 1st card:\n");

         Sleep(1200);


		// reveal the smallest card although NOT the ace :P
		if ((rand1 > rand2 && rand2 != 1 ) || (rand1 == 1))
		{
			int temp = rand1;
			rand1 = rand2;
			rand2 = temp;
		}
		dealer_cards[0] = rand1;
		dealer_cards[1] = rand2;

		showCards(dealer_cards, 1);
		Sleep(1200);


		sum_P = Summ(rand1, sum_P);
		sum_P = Summ(rand2, sum_P);


		int rand3 = rand() % 13 + 1;
		int rand4 = rand() % 13 + 1;



		noob_cards[0] = rand3;
		noob_cards[1] = rand4;

        Sleep(500);
		system("cls");

		printf("\nYour Two cards:\n");

        Sleep(1300);

		showCards(noob_cards, noob_size);
        Sleep(700);




		// ACESFUNC1
			// 0 = ace is still 1 - 1 = ace has changed to 11 --- combined with countAces

		if (CheckAce(rand3) && CheckAce(rand4))
		{
			sum_Y = Summ(10, sum_Y);
			countAces = 2;

		}
		else if (CheckAce(rand3) || CheckAce(rand4))
		{
			countAces = 1;


		}
		Sleep(900);






		// ACESFUNC3-DEALER


		if (CheckAce(rand1) && CheckAce(rand2))
		{
			sum_P = Summ(10, sum_P);
			countAcesDD = 2;

		}
		else if (CheckAce(rand1) || CheckAce(rand2))
			countAcesDD = 1; // flagAceDD = 0 and check later





		sum_Y = Summ(rand3, sum_Y);
		sum_Y = Summ(rand4, sum_Y);


		if (rand3 == rand4 && rand3 == 2)
		{
			sum_Y = 14;
			N_14 = 1;
		}
		if (N_14)
		{
			printf("\n\nYou have 14! I need 31.\n\n");
			Sleep(900);
            deal();
		}



		//players turn

		printf("\nYour Sum: %d\n",sum_Y);
		printf("\nHit or stand (h/s)?: ");


		check();


  }
}


//Putin's turn

void deal()
{
       setcursor(0,0);

    // dealers turn
		printf("\nMy cards:\n");
		showCards(dealer_cards, dealer_size);
		Sleep(900);


		if ((rand1 == rand2 && rand1 == 2) || (rand1 == 3 && rand2 == 1) || (rand1 == 1 && rand2 == 3))
		{
			sum_P = 14;
			D_14 = 1;
		}
		if (D_14)
		{
			if (N_14)
				printf("\n\nLooks like I have 14 too :I am the winner!!.\n\n");
			else if (sum_Y < 31)
			{



                printf("\n\nYour Sum :%d ",sum_Y);

				printf("\nLooks like I have 14 and you don't have the sum of 31... I am the winner!!.\n\n");


			}
			else if (sum_Y == 31)
				printf("\nReally, now? Okay, fine, you won...\n\n");
			else if (bust)
				printf("\nI WON!\n");


			endline();
		}


		printf("\nMy Sum: %d\n",sum_P);
		Sleep(900);

		if (N_14)

        card_loop();

		while (sum_P < sum_Y && !bust)
		{
			card_loop();



			if (N_14 && sum_P < 31 )
                card_loop();

		}



		// we have a winner

		printf("\nSum of my cards: %d\nSum of your cards: %d", sum_P, sum_Y);
		Sleep(900);

		if ((sum_P >= sum_Y && sum_P <= 31) || bust) printf("\nI WON!\n");
		else printf("\nYou won...lame.\n");
		Sleep(900);

		endline();


}

//showing dealer's card
void card_loop(){

    int rr1 = rand() % 13 + 1;

			dealer_size++;
			dealer_cards[dealer_size-1] = rr;

			printf("\nMy cards: ");
			showCards(dealer_cards, dealer_size);
			Sleep(500);



			int newAceDD = 0;

			// ACESFUNC4-DEALER
			if (CheckAce(rr1))
			{
				countAcesDD++;
				newAceDD = 1;
			}
			if (countAcesDD == 1)
			{
				if ( flagAceDD == 0 && (Summ(rr1, sum_P) + 10 <= 31) && (Summ(rr1, sum_P) != 14) )
				{
					sum_P = Summ(10, sum_P);
					flagAceDD = 1;
				}
				else if ( (flagAceDD == 1 && (Summ(rr1, sum_P) > 31)) || (flagAceDD == 1 && (Summ(rr1, sum_P) - 10 == 14)) )
				{
					sum_P = Summ(-10, sum_P);
					flagAceDD = 0;
				}

			}
			if (countAcesDD > 1)
			{
				if (newAceDD = 1)
				{
					sum_P = Summ(10, sum_P);
					newAceDD = 0;
				}


				if ( flagAceDD == 0 && (Summ(rr1, sum_P) + 10 <= 31) && (Summ(rr1, sum_P) != 14) )
				{
					sum_P = Summ(10, sum_P);
					flagAceDD = 1;
				}
				else if ( (flagAceDD == 1 && (Summ(rr1, sum_P) > 31)) || (flagAceDD == 1 && (Summ(rr1, sum_P) - 10 == 14)) )
				{
					sum_P = Summ(-10, sum_P);
					flagAceDD = 0;
				}

			}



			sum_P = Summ(rr1, sum_P);
			printf("\nMy Sum: %d\n",sum_P);
			Sleep(300);

			D_14 = Check14(sum_P);
			if (D_14)
			{
				if (N_14)
					printf("\n\nHA HA!! I have 14 too  I am the winner!!.\n\n");
				else if (sum_Y < 31)
					printf("\n\nLooks like I have 14 and you don't have the sum of 31 (%d).. I am the winner!!.\n\n", sum_Y);
				else if (sum_Y == 31)
					printf("\nReally, now? Okay, fine, you won...\n\n");
				else if (bust)
					printf("\nI WON!\n");




				endline();
			}
}
void check()
{

			hit = toupper(getch());
			if(hit=='X' )
            {
                system("cls");
                mainMenu();
            }
			if (hit != 'H' && hit != 'S')
			{
                    check();
			}
			knock(hit,noob_size,noob_cards);
			deal() ;

}

//Taking new card

void knock(char hit, int noob_size, int noob_cards[15])
{



    while (hit == 'H')
		{
            rr = rand() % 13 + 1;
			noob_size++;
			noob_cards[noob_size-1] = rr;
			printf("\nYour cards:\n");
			showCards(noob_cards, noob_size);


			// ACESFUNC2
			if (CheckAce(rr))
			{
				countAces++;
				newAce = 1;
			}

			if (countAces > 1)
			{
				if (newAce = 1)
				{
					sum_Y = Summ(10, sum_Y);
					newAce = 0;
				}

			}
			Sleep(500);






			sum_Y = Summ(rr, sum_Y);

			if (sum_Y > 31)
			{
				Sleep(500);
				printf("\nYOU ARE DOOMED!\n");
				Sleep(500);
				bust = true;
				break;
			}
			if (sum_Y == 31)
			{
				Sleep(500);
				printf("\n--31--\n");
				Sleep(500);
				printf("\n...\n");
				Sleep(500);
				break;
			}
			N_14 = Check14(sum_Y);
			if (N_14)
			{
				printf("\n\nYou have 14! I must go to 31.\n\n");
				Sleep(500);
                deal();
			}

			printf("\nYour Sum: %d\n",sum_Y);

			printf("\nHit or stand (h/s): ");

			kn_stand();


		}


}
//Hit or Stand
void kn_stand()
{
   hit = toupper(getch());
       if(hit=='X' )
            {
                system("cls");
                mainMenu();
            }
   if (hit != 'H' && hit != 'S')
   kn_stand();
   deal();

}


void endline()
{
    char key1;

        printf("\nWanna play again?(Y/N): ");

        fflush(stdin);

		key1 = toupper(getche());

		if (key1 != 'Y' && key1 != 'N')
        {
            endline();
        }


	   if (key1 == 'N')
		{
			system("cls");
			mainMenu();
		}

       if(key1=='Y')
       {

            playURA();
       }

}




void instructionsURA()
{

    system("cls");
    gotoxy(43, 5);
    system("color 0B");
    std::cout << "INSTRUCTIONS";
    gotoxy(41, 6);
    std::cout << "----------------";
    gotoxy(36, 8);
    std::cout << "1. You aim the sum of 31. If you exceed 31 you got doomed. ";
    gotoxy(36, 10);
    std::cout << "2. Aces count as 1. However a player who has more than";
    gotoxy(36,11);
    std::cout<<"   one Ace must count them as 11 except one of them.";
    gotoxy(36, 13);
    std::cout << "3. If neither the player nor the dealer has 31 then";
    gotoxy(36,14);
    std::cout<<"   the one with the bigger sum wins. If tie, MR.PUTIN wins.";
    gotoxy(36, 16);
    std::cout << "4. In case of 14, the opponent must get 31 to win, otherwise ";
    gotoxy(36,17);
    std::cout<<"   the one with the 14 wins. A pair of Twos is worth as 14";
    gotoxy(36,18);
    std::cout<<"   although only if it's not combined with other cards";
    gotoxy(36, 20);
    std::cout<<"5. Card Value : K,Q,J= 10,A= 1 or 11, others have pip value.";
    gotoxy(36, 22);
    std::cout<<"6. Press 'X' to exit the game.";
    gotoxy(36, 25);
    std::cout << "Press any key to go back to menu";
    getch();

    homelogo();
}


// add player's card sum

int Summ(int draw, int sum)
{
	if (draw == 11 || draw == 12 || draw == 13) sum += 10;
	else sum += draw;

	return (sum);
}


int Check14(int s)
{
	if (s == 14) 	return (1);
	else 			return (0);
}

//finds whether the card is ACE

int CheckAce(int draw)
{
	if (draw == 1)
	return (1);
	else
    return (0);
}

