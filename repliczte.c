#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define BOX_X_START 10
#define BOX_X_END 70
#define BOX_Y_START 10
#define BOX_Y_END 30

int length;

void Print();
void load();
void gotoxy(int x, int y);
void Boarder();
void GotoXY(int x, int y);
void makeBall();
void run();
void update();
void delay();

struct coordinate{
    int x;
    int y;
};
struct speed_struct{
    int x;
    int y;
};

// why we have to typedef sturcture in global to use... and not in int main?
typedef struct coordinate coordinate;
typedef struct speed_struct speed_struct;

coordinate ball={20,20};
coordinate ballold={20,20};
speed_struct speed={0,0};

int main(){
    // Print();
    // load();
    Boarder();
    run();
    return 0;
}

// welcome msg
void Print()
{
    GotoXY(10,12);
    printf("\tWelcome to the mini Snake game.(press any key to continue)\n");
    getch();
    system("cls");
    printf("\tGame instructions:\n");
    printf("\n-> Use arrow keys to move the snake.\n\n-> You will be provided foods at the several coordinates of the screen which you have to eat. Everytime you eat a food the length of the snake will be increased by 1 element and thus the score.\n\n-> Here you are provided with three lives. Your life will decrease as you hit the wall or snake's body.\n\n-> YOu can pause the game in its middle by pressing any key. To continue the paused game press any other key once again\n\n-> If you want to exit press esc. \n");
    printf("\n\nPress any key to play game...");
    if(getch()==27)
        exit(0);
    system("cls");
}

// set cursor to x and y
void gotoxy(int x, int y)
{

    COORD c;
    c.X = x;
    c.Y = y;
 
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);

}

// clear the screen and make borders
void Boarder(){
   system("cls");
    int i;
    for(i=BOX_X_START; i<=BOX_X_END; i++)
    {
        GotoXY(i,10);
        printf("-");
        GotoXY(i,30);
        printf("!");
    }
    for(i=BOX_Y_START; i<= BOX_Y_END; i++)
    {
        GotoXY(10,i);
        printf("!");
        GotoXY(70,i);
        printf("!");
    }
}

// loading animation 
void load(){

    int row,col,r,c,q;
    gotoxy(36,14);
    printf("loading...");
    gotoxy(30,15);
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++); //to display the character slowly

        printf("%c",177); // ascii 117 is ▒
    }
    getch();
}

// gotoxy + fast output
void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
}

// changing ball's coordinate and reflections
void update(){
    ballold.x = ball.x;
    ballold.y = ball.y;
    if(
        (ball.x>=BOX_X_END-1 && speed.x>0)  ||
        (ball.x<=BOX_X_START+1 && speed.x<0)
    ) speed.x = speed.x *(-1);
    if(
        (ball.y>=BOX_Y_END-1 && speed.y>0)  ||
        (ball.y<=BOX_Y_START+1 && speed.y<0)
    ) speed.y = speed.y *(-1);


    ball.x = ball.x + speed.x;
    ball.y = ball.y + speed.y;
}

// make ball in map
void makeBall(){
    GotoXY(ballold.x,ballold.y);
    printf(" ");
    GotoXY(ball.x,ball.y);
    printf("o");
    GotoXY(5,5);
}

void run(){
    while(!kbhit()){
        delay();
        // Boarder();
        update();
        makeBall();
    }
    char a = getch();
    if(a==UP){
        speed.y--;
        run();
    } else if(a==DOWN){
        speed.y++;
        run();
    } else if( a==LEFT){
        speed.x--;
        run();
    } else if( a==RIGHT){
        speed.x++;
        run();
    } else run();
}

void delay(){
    Sleep(50);
    // long double i;
    // for(i=0; i<=(10000000); i++);
}