#pragma once
#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70
#define MENU_WIDTH 20
#define GAP_SIZE 7
#define Aliens_DIF 45
#define SCREEN_WIDTH_ES 95
#define SCREEN_HEIGHT_ES 26
#define WIN_WIDTH_ES 74
#define r_border_vertical 23   //(racket) Vertical frame
#define r_border_horizon 56   // (racket) Horizontal frame


HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;



void delay(int num);
void gotoxy(int x, int y);
void setcursor(bool visible, DWORD size); // set bool visible = 0(invisible), bool visible = 1(visible)
void highscore(void);

//jetpack
int JTmain();
int playJetPack();
int serialJP(int x, FILE *fpRB);
int deserialJP(int x, FILE *fpRB);
void instructionsJetPack();
void updatescoreJetPack(int scoreJP);
void gameoverJetPack(int scoreJP);

//roll ball
int RLmain();
int playRollBall();
int serialRB(int x, FILE *fpRB);
int deserialRB(int x, FILE *fpRB);
void instructionsRollBall();
void updatescoreRollBall(int scoreRB);
void gameoverRollBall(int scoreRB);

//super jump

int SJmain();
int playSJ();
int serialDJ(int x, FILE *fpDJ);
int deserialDJ(int x, FILE *fpDJ);
void instructionsSJ();
void updatescoreSJ(int scoreDJ);
void gameoverSJ(int scoreDJ);

//ninja
int NImain();
int playNinja();
int serialNS(int x, FILE *fpNS);
int deserialNS(int x, FILE *fpNS);
void instructionsNinja();
void updatescoreNinja(int scoreNS);
void gameoverNinja(int scoreNS);


//Alien Hunter
int AHmain();
void drawBorderAH();
void genAliens(int ind);
void drawAliens(int ind);
void eraseAliens(int ind);
void resetAliens(int ind);
void genBullet();
void moveBullet();
void drawBullets();
void eraseBullets();
void eraseBullet(int i);
void drawShip();
void eraseShip();
int bulletHit();
void gameoverAH();
void updateScoreAH();
void instructionsAH();
void playAH();
int serialAH(int x, FILE *fpAH);
int deserialAH(int x, FILE *fpAH);

//escape
int ESmain();
void drawBorderES();
void genMissile(int ind);
void drawMissile(int ind);
void eraseMissile(int ind);
void resetMissile(int ind);
void drawMan();
void eraseMan();
int collisionES();
void gameoverES();
void updatescoreES();
void instructionsES();
void playES();
int serialES(int x, FILE *fpES);
int deserialES(int x, FILE *fpES);

//Racket
int RAmain();
void loop_racket(char cell[r_border_vertical][r_border_horizon], int p_ini, int p_final, int cpuini, int cpufinal, int px, int py);
void edge_racket(char cell[r_border_vertical][r_border_horizon]);
void player_racket(char cell[r_border_vertical][r_border_horizon], int p_ini, int p_final);
void cpu_racket(char cell[r_border_vertical][r_border_horizon], int cpuini, int cpufinal);
void ball_racket(char cell[r_border_vertical][r_border_horizon], int py, int px);
void gameloop_racket(char cell[r_border_vertical][r_border_horizon], int p_ini, int p_final, int cpuini, int cpufinal, int px, int py, int modx, int mody, int modia);
void draw_racket(char cell[r_border_vertical][r_border_horizon]);
void show_racket(char cell[r_border_vertical][r_border_horizon]);
void input_racket(char cell[r_border_vertical][r_border_horizon], int *p_ini, int *p_final, int *cpuini, int *cpufinal, int *px, int *py, int *modx, int *mody, int *modia, int *gol);
void update_racket(char cell[r_border_vertical][r_border_horizon], int p_ini, int p_final, int cpuini, int cpufinal, int py, int px);
int playRA();
void instructionsRA();
int deserialRA(int x, FILE *fpRA);
int serialRA(int x, FILE *fpRA);
void gameoverRA();
void updatescoreRA();

//hand cricket
int HCmain();
int bat(void);
int bowl(void);
void mainmenu(void);
void startplay(void);


//portal rush
int PRmain();
int rd();
void displaychart(int curp, char player[4]);
int welcomescreen(void);
void mainMenu(void);

//space combat
int SCmain();
int playSpace();
int serialSC(int x, FILE *fpSC);
int deserialSC(int x, FILE *fpSC);
void instructionsSpace();
void updatescoreSpace(int scoreSC);
void gameoverSpace(int scoreSC);

//URA 31
void instructionsURA();
void endline();
void playURA();
void knock(char hit, int noob_size, int noob_cards[15]);
void check();
void deal();
int CheckAce(int draw);
int Check14(int s);
int Summ(int draw, int sum);
void showCards(int *array_cards, int siz);
void homelogo();
void kn_stand();
void card_loop();





//Find the Ace
void showCards_GA(int *a_cards, int siz);
void guessCards(int *a_cards, int siz, int aceNum);
void lucky(int aceNum);
int playGA();
int mainGA();








//alien hunter
int AliensY[3];
int AliensX[3];
int AliensFlag[3];

// shape of ship
char Ship[3][5] = {'+', '-', 4, '-', '+',
                   '[', ']',4, '[', ']',
                   '=', 4, 4, 4, '='};
int ShipPos = WIN_WIDTH / 2;
int scoreAH = 0;
int bullets[22][4];
int bulletsLife[20];
int bIndex = 0;

//escape
int missileY[3];
int missileX[3];
int missileFlag[3];
char man[4][3] = {' ', ' ', ' ',
                  ' ', ' ', ' ',
                  ' ', '|', ' ',
                  '=', '-', '='};
int manPos = WIN_WIDTH_ES / 2;
int scoreES;

//hand cricket
int score = 0, score1 = 0;

//racket
int scoreRA=0;
int lifeRA=2;
int player_racketwin = 0;
int cpuwin = 0;
int gol;



//Find The ACE
int optkey;


//URA 31

int URAmain();
char key,hit,answerAce;
int noob_cards[15],rr,dealer_cards[15];
int rand1 = rand() % 13 + 1;
int rand2 = rand() % 13 + 1;
int newAce,countAces,sum_Y ,sum_P ,dealer_size ;
int flagAceN ,flagAceDD ,countAcesDD ,noob_size ;
bool bust = false , N_14 = Check14(sum_Y),D_14 = Check14(sum_P);


