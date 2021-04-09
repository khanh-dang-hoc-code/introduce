#include "stdio.h"
#include "conio.h"
#include "windows.h"
 
int a,b,flag;
#define BLACK 0
#define LIGHTGRAY 8
#define BLUE 9
#define GREEN 10
#define RED 12
#define YELLOW 14
#define WHITE 15
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
void textbackground(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
 
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;
 
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void gotoxy(short x,short y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x,y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
void clrscr(int c=BLACK,int top=0,int down=24)
{
    textbackground(c);
    gotoxy(0,top);
    for(int i=top;i<down;i++)
        printf("                                                                                 ");
    gotoxy(0,top);
}
void viet(char *xau="Quang",int tre=15)
{
    int i;
    for ( i=0 ; i<strlen(xau) ; ++i)
    { putch(xau[i]);Sleep(tre);}
}
void gau(int x,int y,int chungloai)
{
    switch (chungloai)
    {
    case 1:
        gotoxy(x,y+1);  printf("   ,^~~~-.         .-~~~~-.^)");
        gotoxy(x,y+2);  printf("   :  .--. \\       /  .--.  \\");
        gotoxy(x,y+3);  printf("   : (    .-`<^~~~-: :    )  :");
        gotoxy(x,y+4);  printf("   `. `-,~            ^- '  .'");
        gotoxy(x,y+5);  printf("     `-:                ,.-~");
        gotoxy(x,y+6);  printf("      .'                  `.");
        gotoxy(x,y+7);  printf("     ,'   @   @            |");
        gotoxy(x,y+8);  printf("     :    __               ;");
        gotoxy(x,y+9);  printf("  ...{   (__)          ,----.");
        gotoxy(x,y+10); printf(" /   `.              ,' ,--. `.");
        gotoxy(x,y+11); printf("|      `.,___   ,      :    : :");
        gotoxy(x,y+12); printf("|     .'    ~~~~       :    : :");
        gotoxy(x,y+13); printf(" \\.. /               `. `--' .'");
        gotoxy(x,y+14); printf("    |      3HGROUP     ~----~");
        gotoxy(x,y+15); printf("    |     QUANGXENG       |");
        break;
 
    case 2:
        gotoxy(x,y+1);  printf(" / _` | | | |/ _` | '_ \\ / _` | \\ \\/ / _ \\ '_ \\ / _` |");
        gotoxy(x,y+2);  printf("| (_| | |_| | (_| | | | | (_| |  >  <  __/ | | | (_| |");
        gotoxy(x,y+3);  printf(" \\__, |\\__,_|\\__,_|_| |_|\\__, | /_/\\_\\___|_| |_|\\__, |");
        gotoxy(x,y+4);  printf("    | |                   __/ |                  __/ |");
        gotoxy(x,y+5);  printf("    |_|                  |___/                  |___/");
        break;
 
    case 3:
        //printf("     ,-.,-\"\`\"\"-./  \\   ");
        //printf("\n       /   \\        \`-.|       ");
        printf("       \\   /           \`-._     .:::.:::. ");         Sleep(30);
        printf("\n         \|               \"=\\    :::::::::");         Sleep(30);
        printf("\n         \|      .==\"    \|o_\|_    ':::::' ");          Sleep(30);
        printf("\n         \|       _o.     \` (_)     ':'  ,;;;,;;;,");  Sleep(30);
        printf("\n         ;                  \\\\          ;;;;;;;;;");  Sleep(30);
        printf("\n         \\             _.    /\|-.        ':::::'");   Sleep(30);
        printf("\n        \\           \` \`'---'/   \\        ':'");       Sleep(30);
        printf("\n     \\       .--._     /-'   |");                    Sleep(30);
        printf("\n   ,-`.    /     `-._(     /");                       Sleep(30);
        printf("\n   `-._`-._\\         `\\   \'\\");                   Sleep(30);
        printf("\n     ( `    `'._  _,   |    \\");                     Sleep(30);
        printf("\n     /    ~-.   `|     |    |");                      Sleep(30);
        printf("\n    /        `;-.|     |    |");                      Sleep(30);
        printf("\n  .'  \\         /|     |    /");                     Sleep(30);
        printf("\n      .'-.   '.      | \\     |  .'");                  Sleep(30);
        printf("\n      `-._     '.    |       /\"` `\\");                Sleep(30);
        printf("\n       /  `\"--.,_'-._\\-.___.'_     ;");               Sleep(30);
        printf("\n      /          `\"\"\";--'     `.   |");              Sleep(30);
        printf("\n     /            .'`            \\ /\"\"-.");          Sleep(30);
        printf("\n    ;            /                \\\"\"-, \\");        Sleep(30);
        printf("\n    |           /                 |    \\ |");          Sleep(30);
        printf("\n    \\           |          '.           |/");          Sleep(30);
        printf("\n     '.          \\         .'`-.        /");           Sleep(30);
        printf("\n       '._        '.,___,.;'    '-.___.'");             Sleep(30);
        printf("\n    `\"\"\"----------'`");                            Sleep(30);
        break;
 
    }
}
void PR( int xgoc , int ygoc , int xdich , int ydich , char *xau="Quang" , int tre=15 , int mau =GREEN, int cach=1)
{
    int i,j=0;
    textcolor(mau);
    if (xgoc==xdich&&ygoc>ydich&&cach==1)
    {
        for (j=0 ; j<=strlen(xau) ; j++)
        {
            if (xau[j]!=32)
                for (i=ygoc ; i>= ydich ; i--)
                {
                    gotoxy(xgoc,i);putch(xau[j]);
                    gotoxy(xgoc,i+1);putch(' ');
                    Sleep(tre);
                }
            else {gotoxy(xgoc,ydich);putch(' ');}
            xgoc++;
        }
    }
 
    if (ydich==ygoc&&xgoc>xdich&&cach==1)
    {
        for (j=0 ; j<=strlen(xau) ; j++)
        {
            if (xau[j]!=32)
                for (i=xgoc ; i>= xdich ; i--)
                {
                    gotoxy(i,ygoc);printf("%c ",xau[j]);
                    Sleep(tre);
                }
            else {gotoxy(xgoc,ydich);putch(' ');}
            xdich++;
        }
 
    }
}
void ancontro()
{
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;
    SetConsoleCursorInfo(hOut,&ConCurInf);
}
void hiencontro()
{
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = TRUE;
    SetConsoleCursorInfo(hOut,&ConCurInf);
}
void tieude(char *xau="quang xeng",int x=0,int y=1)
{
    gotoxy(x,y);
    textbackground(YELLOW);
    textcolor(RED);
    printf(" %s ",xau);
    textbackground(BLUE);
    textcolor(GREEN);
}
void ten(int n)
{
    switch(n)
    {
    case 0:gotoxy(20,2),printf("CHUONG TRINH MO PHONG MENU LENH VOI HAI BIEN A VA B");break;
    case 1:gotoxy(9,5), printf("Nhap vao gia tri moi cho a va b.");if (flag) printf("Hien tai la : %d %d",a,b);break;
    case 2:gotoxy(9,7); if (flag==0) textcolor(8);printf("In ra tong hieu tich thuong cua a va b");textcolor(GREEN);break;
    case 3:gotoxy(9,9); if (flag==0) textcolor(8);printf("Hoan doi gia tri cua a va b");textcolor(GREEN);break;
    case 4:gotoxy(9,11),printf("Thong tin ban quyen");break;
    case 5:gotoxy(35,19),printf(" + Thoat + ");break;
    case 97:gotoxy(34,21),printf("+ Chay lai +"),gotoxy(36,21);break;
    case 98:gotoxy(12,21),printf("+ Tro lai +"),gotoxy(14,21);break;
    case 99:gotoxy(59,21),printf("+ Thoat +"),gotoxy(61,21);break;
    }
}
int lc=1,ct,oldlc=1;
void mainmenu(void);
void luachon(void)
{
    unsigned char nut='a',nutgia='a';
    int tlc,maxlc,i,manglc[40];
    fflush(stdin);
    switch (ct)
    {
    case 0:maxlc=5;for (i=1;i<=7;i++) manglc[i]=i;break;
    case 4:maxlc=2;manglc[1]=98;manglc[2]=99;oldlc=1;break;
    case 1:case 2:case 3:
    case 9:maxlc=3;manglc[1]=97;manglc[2]=98;manglc[3]=99;break;
    }
 
 
    //ban dau
    tlc=lc=oldlc;
    if (ct==9) tlc=lc=1;
    textcolor(WHITE);
    ten(manglc[lc]);
 
 
 
 
    while (nutgia!=0xD)
    {
        // bat phim
        nutgia=getch();
        if (nutgia==224) nut=getch();
 
 
        if (nutgia==0x1B)
            switch (ct)
        {
            case 0:exit(0);
        }
 
        switch (ct)
        {
        case 0: switch (nut)
                {
 
                    case 0x4B:case 0x48: lc--;if (flag==0&&(lc==2||lc==3)) lc=1;  break;
                    case 0x4D:case 0x50: lc++;if (flag==0&&(lc==2||lc==3)) lc=4;  break;
                }
                break;
        case 4: switch(nut)
                {case 0x50:case 0x4D:case 0x48:case 0x4B:lc++;break;}
                break;
        case 1:case 2:case 3:case 9: switch(nut)
                {
                    case 0x50:
                    case 0x4D: if(lc==1)lc=3;else if(lc==3)lc=2;else lc=1;break;
                    case 0x48:
                    case 0x4B: if(lc==1)lc=2;else if(lc==3)lc=1;else lc=3;break;
                }
                break;
 
        }
 
        // gioi han bien lc
        if (lc>maxlc) lc=1;
        if (lc<1) lc=maxlc;
 
        //doi mau chu
        textcolor(GREEN);ten(manglc[tlc]);
        textcolor(WHITE);ten(manglc[lc]);
 
        //chuan bi cho vong lap sau - khoi tao lai gia tri
        tlc=lc;
        nut=0x61;
    }
}
void start(void)
{
    int i;
    SetConsoleTitle("Bui Tan Quang - C Programming Language - Assignment 2");
    ancontro();
    gau(1,0,3);
 
    textcolor(10);
    PR(79,10,42,10,"Tang Ngoc Khanh",2);
    PR(46,16,46,12,"Quan Li Phong Gym ",10);
    Sleep(500);
    clrscr(BLUE);
    gotoxy(0,24);
    textbackground(LIGHTGRAY);
    printf("                                                                                ");
    gotoxy(0,24);
    textcolor(RED);
    printf("   Sinh vien  : ");
    textcolor(BLACK);
    printf(" Bui Tan Quang ");
    textcolor(RED);
    printf("               Yahoo! :");
    textcolor(BLACK);
    printf("  langmaninternet ");
    gotoxy(0,0);
    textbackground(LIGHTGRAY);
    printf("                                                                                ");
    PR( 60,0,25,0,"C Programming Language",1,15,1);
    textbackground(BLUE);
    textcolor(GREEN);
    gau(22,4,1);
    gotoxy(28,21);
    viet("Bat dau",30);
    viet("............",100);
    mainmenu();
}
int nhapso()
{
    char ch='a',xau[10],i=0;
    while(ch!=0xD||i==0)
    {
        ch=getch();
        if (ch==0x8&&i) --i,printf("\b \b");
        if ((!((i==0&&ch=='-')||(ch>='0'&&ch<='9')))||i>6) continue;
        xau[i++]=ch;
        printf("%c",ch);
    }
    xau[i]=NULL;
    return atoi(xau);
}
void item1(void)
{
    ct=1;
    tieude("Lua chon 1 : nhap vao a va b");
    clrscr(BLUE,1,22);
   
    //to do place code here
    hiencontro();
    gotoxy(0,7);printf("Nhap vao so a :  ");
    a=nhapso();
    gotoxy(0,8);printf("Nhap vao so b :  ");
    b=nhapso();
 
 
    ancontro();
    flag=1;
    ten(97);ten(98);ten(99);
    luachon();
    if (lc==3) exit(0);
    else if (lc==2) {oldlc=1;mainmenu();}
    else item1();
}
void item2(void)
{
    ct=2;
    tieude("Lua chon 2 : in ra tong hieu tich thuong cua 2 so : ");
    clrscr(BLUE,1,22);
   
    //to do place code here
    gotoxy(0,7);printf("Tong   2 so la :  %d\nHieu   2 so la :  %d\nTich   2 so la :  %ld\n",a+b,a-b,long(a)*b);
    b?printf("Thuong 2 so la :  %lf",double(a)/b):printf("\nb==0 nen ko thuc hien duoc phep chia");
    flag=1;
    ten(97);ten(98);ten(99);
    luachon();
    if (lc==3) exit(0);
    else if (lc==2) {oldlc=2;mainmenu();}
    else item2();
}
void item3(void)
{
    ct=3;
    tieude("Lua chon 3 : hoan doi gia tri a va b");
    clrscr(BLUE,1,22);
 
    //to do place code here
    gotoxy(0,7);
    printf("Gia tri ban dau          cua a va b la : %7d va %7d\n",a,b);
    a^=b^=a^=b;
    printf("Gia tri sau khi thay doi cua a va b la : %7d va %7d",a,b);
    flag=1;
    ten(97);ten(98);ten(99);
    luachon();
    if (lc==3) exit(0);
    else if (lc==2) {oldlc=3;mainmenu();}
    else item3();
}
void banquyen(void)
{
    ct=4;
    tieude("Thong tin ban quyen");
    clrscr(BLUE,1,22);
    gau(13,1,2);
    PR(23,16,23,14,"Mon hoc       : C Programming Language " ,15,GREEN,1);
    PR(23,17,23,15,"Sinh vien     : Bui Tan Quang" ,15,GREEN,1);
    ten(98);ten(99);
    luachon();
    if (lc==2) exit(0);
    else  {oldlc=4;mainmenu();}
}
void mainmenu(void)
{
    clrscr(BLUE,1,23);
    tieude("Main Menu");
    ct=0;
    for (int i=0;i<7;i++) ten(i);
    luachon();
    switch (lc)
    {
    case 1:item1();break;
    case 2:item2();break;
    case 3:item3();break;
    case 4: banquyen();break;
    case 5: exit(0);break;
    }
}
int main()
{
    start();
    return 1;
}