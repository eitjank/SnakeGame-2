#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <ctime>
using namespace std;
bool gameOver;
const int width = 50;
const int height = 20;
int x, y, fruitX, fruitY, score, scoreAdd=10;
int tailX[500],tailY[500];
int nTail;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy( int x, int y )
{
    COORD p = { short(x), short(y) };
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );
}

void Setup()
{
    SetConsoleTextAttribute(hConsole, 0x88);
    for(int i = 0; i < width+2; i++)
    {
        gotoxy(i,0);
        cout<<"#";
        gotoxy(i,height);
        cout<<"#";
    }
    for(int i = 1; i < height; i++)
    {
        gotoxy(0,i);
        cout<<"#";
        gotoxy(width+1,i);
        cout<<"#";
    }
    gameOver = false;
    dir = STOP;
    x = width/2;
    y = height/2;
    srand(time(0));
    fruitX = rand()%(width)+1;
    fruitY = rand()%(height-1)+1;


    score = 0;
    gotoxy(0,height+1);
    SetConsoleTextAttribute(hConsole, 0x02);
    cout<<"Score: "<<score;
}
void Draw()
{
    SetConsoleTextAttribute(hConsole, 0x0A);
    gotoxy(x,y);
    cout<<"O";

    for(int k = 0; k < nTail; k++)
    {
        gotoxy(tailX[k],tailY[k]);
        cout<<"o";
    }
    gotoxy(tailX[nTail],tailY[nTail]);
    cout<<" ";

    SetConsoleTextAttribute(hConsole, 0x44);
    gotoxy(fruitX,fruitY);
    cout<<"F";
    gotoxy(width+1,height);
    SetConsoleTextAttribute(hConsole, 0x0F);
}
void Input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
        case 'a':
            if(dir != RIGHT)dir = LEFT;
            break;

        case 'd':
            if(dir != LEFT)dir = RIGHT;
            break;

        case 'w':
            if(dir != DOWN)dir = UP;
            break;

        case 's':
            if(dir != UP)dir = DOWN;
            break;

        case 'x':
            gameOver = true;
            break;
        }
    }
}
void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for(int i = 1; i <= nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch(dir)
    {
    case LEFT:
        x--;
        break;

    case RIGHT:
        x++;
        break;

    case UP:
        y--;
        break;

    case DOWN:
        y++;
    break;

    default:
        break;
    }
    //Game with walls
    if(x > width || x <= 0 || y > height-1 || y <= 0) gameOver = true;

    //Game without walls
    //if(x >= width + 1)x = 1; else if(x <= 0)x = width;
    //if(y >= height)y = 1; else if(y <= 0)y = height - 1;

    for(int i = 0; i < nTail; i++)
        if(tailX[i] == x && tailY[i] == y)
            gameOver = true;

    if(x == fruitX && y == fruitY)
    {
        score += scoreAdd;
        fruitX = rand()%(width-1)+1;
        fruitY = rand()%(height-1)+1;
        nTail++;
        gotoxy(7,height+1);
        SetConsoleTextAttribute(hConsole, 0x02);
        cout<<score;
    }

}
int main()
{
    Setup();
    while(!gameOver)
    {
        Draw();
        Input();
        Logic();
        if(dir!= UP && dir != DOWN)Sleep(80);
        else Sleep(110);
    }
    gotoxy(21,height+2);
    cout<<"GAME OVER"<<endl;
    //Game over sound
    Beep(220,200);
    Beep(190,200);
    Beep(160,200);
    Beep(135,400);
    Sleep(1000);
    return 0;
}
