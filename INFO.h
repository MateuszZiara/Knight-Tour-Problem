#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <allegro.h>
int getX(int x);
/**@brief
*Fukcja daje mozliwosc usawienia X skoczka
*
*@retval Zwraca wartosc X

*/
int getY(int x);
/**@brief
*Fukcja daje mozliwosc usawienia Y skoczka
*
*@retval Zwraca wartosc Y

*/
bool horseonBoard(int x, int y);
/**@brief
*Sprawdza czy skoczek po ruchu znajduje sie na tablicy
*
*@retval Zwraca TRUE jezeli tak
*@retval Zwraca FALSE jezeli wypadl poza plansze


*/
void fillBoard(struct border tablica[8][8]);
/**@brief
*Wypelnia tablice wartosciami 0
*
*@retval Zwraca tablice
*/
void fillMovelist(int *tab)
/**@brief
*Wypelnia tablice ruchow skoczka wartosciami 0
*
*@retval Zwraca tablice ruchow skoczka
*/
bool checkPos(int x, int y, struct border tablica[8][8]);
/**@brief
*Dziala podobnie jak horseonBoard ale sprawdza czy pole jest rowne 0
*
*@retval Zwraca TRUE jezeli mozna skoczyc oraz uzytkownik nie odwiedzil pola
*@retval Zwraca FALSE jezeli nie mozna skoczyc lub uzytkownik odwiedzil pole

*/
void move(int *x, int *y, int bufor, int param);
/**@brief
*Funkcja ruchu skoczka


*/

bool checkParam(int i, int *moveList);
/**@brief
*Sprawdza parametr ruchu skoczka
*@retval Zwraca TRUE jezeli parametr jest rowny 7
*@retval Zwraca FALSE jezeli nie jest rowny 7


*/
void printboard(struct border tablica[8][8]);
/**@brief
*Wypisuje tablice na ekranie



*/
int numberOfsquares(int x, int y, int number, struct border tablica[8][8]);
/**@brief
*Sprawdza ilosc mozliwych przyszlych ruchow skoczka
*@retval Zwraca ilosc przyszlych ruchow


*/
void checkNumber(int number, int *bufor, int moveList, int *lowestnumber);
/**@brief
*Ustawia parametry dla najmniejszych wartosci mozliwych przyszlych ruchow


*/
bool checkIfLower(int number, int lowest);
/**@brief
*Porownuje dwa parametry i wybiera mniejszy


*/
void setCords(struct border tablica[8][8]);
/**@brief
*Ustawia minimalne oraz maksymalne wartosci X oraz Y dla kazdego kwadratu na tablicy. Potrzebne w Allegro do wypisywania liczb


*/
