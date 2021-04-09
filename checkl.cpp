#include "stdio.h"
#include "conio.h"
#include "windows.h"
#include <unistd.h>
#define GREEN 10
void textcolor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void gotoxy(short x, short y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {x, y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void PR(int xgoc, int ygoc, int xdich, int ydich, char *xau = "Khanh", int tre = 15, int mau = GREEN, int cach = 1)
{
    int i, j = 0;
    textcolor(mau);
    if (xgoc == xdich && ygoc > ydich && cach == 1)
    {
        for (j = 0; j <= strlen(xau); j++)
        {
            if (xau[j] != 32)
                for (i = ygoc; i >= ydich; i--)
                {
                    gotoxy(xgoc, i);
                    putch(xau[j]);
                    gotoxy(xgoc, i + 1);
                    putch(' ');
                    Sleep(tre);
                }
            else
            {
                gotoxy(xgoc, ydich);
                putch(' ');
            }
            xgoc++;
        }
    }

    if (ydich == ygoc && xgoc > xdich && cach == 1)
    {
        for (j = 0; j <= strlen(xau); j++)
        {
            if (xau[j] != 32)
                for (i = xgoc; i >= xdich; i--)
                {
                    gotoxy(i, ygoc);
                    printf("%c ", xau[j]);
                    Sleep(tre);
                }
            else
            {
                gotoxy(xgoc, ydich);
                putch(' ');
            }
            xdich++;
        }
    }
}
main()
{
    PR(38, 4, 38, 3, "Ban Dang Lo Lang Ve Suc Khoe ?", 10);
    sleep(2);
    system("cls");
    PR(38, 4, 38, 3, "Ban Dang Tu Ti Ve Chiec Bung Mo Cua Ban Than ?", 10);
    sleep(2);
    system("cls");
    PR(38, 4, 38, 3, "Dung Lo Lang. Vi :");
    sleep(1);
    system("cls");
    PR(38, 4, 38, 3, "Da Co Phong Gym Ngoc Khanh.", 10);
    sleep(1);
    system("cls");
    PR(38, 4, 38, 3, "Phong Gym Ngoc Khanh Voi Cac Thiet Bi Duoc Nhap Khau Tu Han Quoc", 10);
    sleep(1);
    system("cls");
    PR(38, 4, 38, 3, "Ket Hop Voi Doi Ngu Huan Luyen Vien Nhieu Kinh Nghiem", 10);
    sleep(1);
    system("cls");
    PR(38, 4, 38, 3, "Tu Tin Se cho Ban Trai Nghiem Tuyet Voi Nhat Khi Den Voi Chung Toi", 10);
    sleep(1);
    system("cls");
    PR(38, 4, 38, 3, "DAC BIET ", 10);
    sleep(1);
    system("cls");
    PR(38, 4, 38, 3, "SIEU UU DAI GIAM 90% ", 10);
    sleep(1);
    system("cls");
    PR(38, 4, 38, 3, "SIEU UU DAI GIAM 90% ", 10);
    sleep(1);
    system("cls");
    PR(38, 4, 38, 3, "CO HOI DUY NHAT CHI CO TAI PHONG GYM NGOC KHANH", 10);
    sleep(1);
    system("cls");
    PR(38, 4, 38, 3, "Thoi Gian Dien Ra Su Kien Tu 09/04 - 30/04", 10);
    sleep(1);
    system("cls");
    PR(38, 4, 38, 3, "Dung Bo Lo Nhe", 10);
    sleep(1);
    system("cls");


    PR(2,2,2,1,"Tang Ngoc Khanh",2);

    PR(46,2,46,1," Chao Mung Ban Den Voi Chuong Trinh Quan Li Phong Gym ",10);
    // PR(40,4,40,2,"Phong Gym Ngoc Khanh Voi Cac Thiet Bi Duoc Nhap Khau Tu Han Quoc",10);
    // PR(40,6,40,3,"Ket Hop Voi Doi Ngu Huan Luyen Vien Nhieu Kinh Nghiem",10);
    getch();
}