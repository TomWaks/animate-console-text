#include<ncurses.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#define WYSOKOSC 23
#define SZEROKOSC 65
#define Y (WYSOKOSC+(1))/(2)
#define X (SZEROKOSC+(1))/(2)
#define R 12
#define r 2

typedef struct imie{
	char imie[30];
	int dlugosc;//liczba liter w imieniu
}imie;

int main()
{
	imie Imie;//reprezentuje moje imie
	int t;
	char c = 0;//char do zczytywania imienia z pliku
	strcpy(Imie.imie , "xyz abcdefgh");
	Imie.dlugosc = 18;
	initscr();//inicjalizacja ncurses
	if (has_colors() == TRUE)
	{
		start_color();
		init_pair(1, COLOR_RED, COLOR_BLUE);
		attron(COLOR_PAIR(1));
		while (Imie.dlugosc--)//tyle pelnych okrazen musimy zrobic dlatego 9 razy wywolamy to co w petli
		{
			for (t = 0; t < 62; t++)//jakie bedzie zageszczenie krokow dla pelnego cyklu
			{
				clear();//czyszczenie tego co bylo wczesniej
				mvprintw(Y + (int)((R - r)*cos(t / 10.00) + r*cos((R - r)*t / (10.0*r))), X + (int)((R - r)*sin(t / 10.0) - r*sin((R - r)*t / (10.0*r))), "%s", Imie.imie);//rysowanie w nowym miejscu
				usleep(20000);//spowolnienie
				refresh();//odswierzenie ekranu
			}
			Imie.imie[Imie.dlugosc] = '\0';//znak konca stringu co petle przepisujemy go coraz blizej poczatku w ten sposob skracajac stringa
		}
		clear();//czyszczenie tego co bylo wczesniej
		attroff(COLOR_PAIR(1));
	}
	else
	{
		while (Imie.dlugosc--)//tyle pelnych okrazen musimy zrobic dlatego 9 razy wywolamy to co w petli
		{
			for (t = 0; t < 62; t++)//jakie bedzie zageszczenie krokow dla pelnego cuklu
			{
				clear();//czyszczenie tego co bylo wczesniej
				mvprintw(Y + (int)((R - r)*cos(t / 10.00) + r*cos((R - r)*t / (10.0*r))), X + (int)((R - r)*sin(t / 10.0) - r*sin((R - r)*t / (10.0*r))), "%s", Imie.imie);//rysowanie w nowym miejscu
				usleep(20000);//spowolnienie
				refresh();//odswierzenie ekranu
			}
			Imie.imie[Imie.dlugosc] = '\0';//znak konca stringu co petle przepisujemy go coraz blizej poczatku w ten sposob skracajac stringa
		}
		clear();//czyszczenie tego co bylo wczesniej
	}
	getch();//czeka az cos wcine
	endwin();//koniec ncurses
	return 0;
}
