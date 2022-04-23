void highscore(void)
{
    int hs1 = 0, hs2 = 0, hs3 = 0, hs4 = 0, hs5 = 0, hs6 = 0, hs7 = 0, hs8 = 0;
    system("cls");
    system("color A");
    std::cout << "\n\n\t\t\t\t\t>>> High Score Board <<<\n";
    std::cout << "\t\t\t\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n\n\n\n";
    // ninja

    FILE *fpNS1 = fopen("ninja.txt", "r");
    if (fpNS1 != (void *)0)
    {
        hs1 = deserialNS(1, fpNS1);
    }

    // alienhunter
    FILE *fpAH1 = fopen("hunter.txt", "r");
    if (fpAH1 != (void *)0)
    {
        hs2 = deserialAH(1, fpAH1);
    }

    // escape
    FILE *fpES1 = fopen("escape.txt", "r");
    if (fpES1 != (void *)0)
    {
        hs6 = deserialES(1, fpES1);
    }

    // jetpack

    FILE *fpJP1 = fopen("jetpack.txt", "r");
    if (fpJP1 != (void *)0)
    {
        hs3 = deserialJP(1, fpJP1);
    }

    // roll
    FILE *fpRB1 = fopen("roll.txt", "r");
    if (fpRB1 != (void *)0)
    {
        hs4 = deserialRB(1, fpRB1);
    }

    // superjump
    FILE *fpDJ1 = fopen("SJ.txt", "r");
    if (fpDJ1 != (void *)0)
    {
        hs5 = deserialDJ(1, fpDJ1);
    }


     // racket
    FILE *fpRA1 = fopen("racket.txt", "r");
    if (fpRA1 != (void *)0)
    {
        hs7 = deserialRA(1, fpRA1);
    }

    //space combat
    FILE *fpSC1 = fopen("SpaceCombat.txt", "r");
    if (fpSC1 != (void *)0)
    {
        hs8 = deserialSC(1, fpSC1);
    }

    std::cout << "\t\t\t\t\t JetPack\t: " << hs3 << std::endl << std::endl;
    std::cout << "\t\t\t\t\t Roll Ball\t: " << hs4 << std::endl << std::endl;
    std::cout << "\t\t\t\t\t Super Jump\t: " << hs5 << std::endl << std::endl;
    std::cout << "\t\t\t\t\t Ninja Shooter\t: " << hs1 << std::endl << std::endl;
    std::cout << "\t\t\t\t\t Alien Hunter\t: " << hs2 << std::endl << std::endl;
    std::cout << "\t\t\t\t\t Escape\t\t: " << hs6 << std::endl << std::endl;
    std::cout << "\t\t\t\t\t Space Combat\t: " << hs8 << std::endl << std::endl;
    std::cout << "\t\t\t\t\t Racket\t\t: " << hs7 << std::endl << std::endl;


    printf("\n\n\t\t\t\t Press Any Key To Go Back To Main Menu ");
    getch();
    system("cls");
    mainMenu();
}
