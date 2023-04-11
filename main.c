#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <allegro.h>
struct border
{
    int number;
    int minx;
    int miny;
    int maxx;
    int maxy;
};
const int sizeXY = 8;
const int board = 64;
const int forward = 1;
const int back = -1;

int getX(int x)
{
    printf("Podaj pozycje X skoczka: ");
    scanf("%d",&x);
    return x;
}
int getY(int x)
{
    printf("Podaj pozycje Y skoczka: ");
    scanf("%d",&x);
    return x;
}
bool horseonBoard(int x, int y)
{
    if(x < 8 && y < 8 && x > -1 && y > -1)
        return true;
    return false;
}
void fillBoard(struct border tablica[8][8])
{
    int i,j;
    for(i = 0; i < 8; ++i)
        for(j = 0; j < 8; ++j)
            tablica[i][j].number = 0;
}
void fillMovelist(int *tab)
{
    int i;
    for(i = 0; i < 64; ++i)
        tab[i] = 0;
}
bool checkPos(int x, int y, struct border tablica[8][8])
{
    if(x > -1 && x < sizeXY && y >-1 && y < sizeXY && tablica[x][y].number == 0)
        return true;

    return false;
}
void move(int *x, int *y, int bufor, int param)
{
    switch(param)
    {
    case 0:
        *x += 1 * bufor;
        *y -= 2 * bufor;
        break;
    case 1:
        *x -= 2 * bufor;
        *y += 1 * bufor;
        break;
    case 2:
        *x -= 2 * bufor;
        *y -= 1 * bufor;
        break;
    case 3:
        *x -= 1 * bufor;
        *y -= 2 * bufor;
        break;

    case 4:
        *x -= 1 * bufor;
        *y += 2 * bufor;
        break;
    case 5:
        *x += 2 * bufor;
        *y -= 1 * bufor;
        break;
    case 6:
        *x += 2 * bufor;
        *y += 1 * bufor;
        break;

    case 7:
        *x += 1 * bufor;
        *y += 2 * bufor;
        break;
    }
}
bool checkParam(int i, int *moveList)
{
    if(moveList[i] == 7)
        return true;
    return false;
}
void printboard(struct border tablica[8][8])
{
    int i, j;
    for(i = 0; i < 8; ++i)
    {
        for(j = 0; j < 8; ++j)
            printf("%3d",tablica[i][j].number);
        puts("");
    }
}

int numberOfsquares(int x, int y, int number, struct border tablica[8][8])
{
    number = 0;
    if(checkPos(x+1,y-2,tablica))
        number++;
    if(checkPos(x-2,y+1,tablica))
        number++;
    if(checkPos(x-2,y-1,tablica))
        number++;
    if(checkPos(x-1,y-2,tablica))
        number++;
    if(checkPos(x-1,y+2,tablica))
        number++;
    if(checkPos(x+2,y-1,tablica))
        number++;
    if(checkPos(x+2,y+1,tablica))
        number++;
    if(checkPos(x+1,y+2,tablica))
        number++;
    return number;
}
void checkNumber(int number, int *bufor, int moveList, int *lowestnumber)
{

        *lowestnumber = number;
        *bufor = moveList;

}
bool checkIfLower(int number, int lowest)
{
    if(number < lowest)
        return true;
    return false;
}
void setCords(struct border tablica[8][8])//Ustawia koordynaty
{
    int x =0 , y = 0;
    int maxx =120 , maxy = 120;
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            tablica[i][j].minx =x;
            tablica[i][j].miny =y;
            tablica[i][j].maxx = maxx;
            tablica[i][j].maxy = maxy;
            x = maxx;
            maxx += 120;
        }
        x = 0;
        maxx = 120;
        y += 120;
        maxy += 120;
    }
}



int main()
{

    struct border tablica[8][8];
    //Zmienne

    int animTab[8][8];
    int horseX = 0,horseY = 0;
    int bufor = 0;
    int i,j;
    int moveList[64];
    int number;
    int lowestNumber;
    int numberBufor;

    if(!horseonBoard(horseX,horseY))
    {
        printf("Skoczek poza tablica!");
        return 0;
    }

    fillBoard(tablica);
    fillMovelist(moveList);
    setCords(tablica);
    for(i = 0; i < 8; ++i)
    {
        for(j = 0; j < 8; ++j)
        {
            printf("Dla tablicy o numerze %d %d, minY: %d minX: %d, maxY: %d, maxX: %d \n",i,j,tablica[i][j].miny,tablica[i][j].minx,tablica[i][j].maxy,tablica[i][j].maxx);
        }
    }

bool programRun = true;

    allegro_init();
    install_keyboard();
    FONT *fontDef;
    fontDef;
    fontDef = load_font("font2.pcx",default_palette, NULL);
     set_color_depth( 16 );
    set_gfx_mode( GFX_AUTODETECT_WINDOWED, 960, 960, 0, 0 );
    clear_to_color( screen, makecol( 128, 128, 128 ) );
    BITMAP *background = NULL;
    background = load_bmp("board.bmp",default_palette);
    blit( background, screen, 0, 0, 0, 0, background->w, background->h );
    install_mouse();
    show_mouse(screen);
    bool choose = false;
    while(choose == false)
    {
        int mouseX,mouseY;
        if(mouse_b)
        {
            mouseX = mouse_x;
            mouseY = mouse_y;
            for(i = 0; i < 8; ++i)
            {
                for(j = 0; j < 8; ++j)
                {
                    if(mouseX > tablica[i][j].minx && mouseX < tablica[i][j].maxx && mouseY > tablica[i][j].miny && mouseY < tablica[i][j].maxy)
                    {
                        horseX = i;
                        horseY = j;
                        choose = true;
                    }
                }
            }

        }
    }

    for(i = 1; i < 65; ++i)
    {

        tablica[horseX][horseY].number = i;
        lowestNumber = 8;
        bufor = 0;
        for(moveList[i-1] = 0; moveList[i-1] < 8; moveList[i-1]++)
        {
            move(&horseX, &horseY, forward, moveList[i-1]);
            if(checkPos(horseX,horseY,tablica))
            {
                number = numberOfsquares(horseX,horseY,numberBufor,tablica);
                if(checkIfLower(number,lowestNumber))
                {
                    checkNumber(number,&bufor,moveList[i-1],&lowestNumber);
                }
            }

            move(&horseX, &horseY, back, moveList[i-1]);
        }


        moveList[i-1] = bufor;
        move(&horseX, &horseY, forward, moveList[i-1]);

    }
    printf("Kolejnosc ruchu: \n");
    printboard(tablica);

    int x = 0 ,y = 0;
    for(i = 0; i < 8; ++i)
    {
        for(j = 0; j < 8; ++j)
        {
         
             textprintf_ex(background,fontDef,tablica[i][j].maxx-70,tablica[i][j].maxy-70,makecol(255, 0, 0),-1,"%d",tablica[i][j].number);
        }
    }
    blit( background, screen, 0, 0, 0, 0, background->w, background->h );
    readkey();
    destroy_bitmap(background);


}
END_OF_MAIN();
