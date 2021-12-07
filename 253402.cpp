#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <functional>
#include <time.h>
#include <fstream>
#include <limits>


using namespace std;

int 
main () 
{
for (int i = 0; i < 50; i++)
cout << "*";
cout << endl << "\tKryptografia 2 - projekt";
cout << endl << "\tAutor: Darek Szymula";
cout << endl << "\tNumer indeksu: 253402";
cout << endl;
cout << endl << "Co chcesz zrobic?";
cout << endl;
cout << endl << "1. Zakoduj tekst i zapisz do pliku";
cout << endl << "2. Rozkoduj tekst z pliku";
cout << endl << "3. Wyjscie";
cout << endl << endl;
for (int i = 0; i < 50; i++)
cout << "*";
  
int opcja = 0;

for (;;)
    {
cout << endl << "Wybierz opcje: ";
cin >> opcja;
 
if (cin.fail () || (opcja < 1 || opcja > 3))
	{
cin.clear ();
cin.ignore (numeric_limits < streamsize >::max (), '\n');

cout << endl << "to nie liczba\n";
cout << endl << "Wybierz opcje: ";
}
      else
break;
}
  
if (opcja == 3)
return 0;
  
string tekst;
int dzien = 0;
char tekst_t[1024];
char zaszyfrowany[1024];
int dl_tekst = 0;

if (opcja == 1)
    {
    cout << endl << "Podaj tekst do zaszyfrowania: ";
      
	cin.clear ();
    cin.ignore ();
    getline (cin, tekst);
    
    dl_tekst = tekst.length ();
    strcpy (tekst_t, tekst.c_str ());

time_t czas;
time (&czas);
struct tm *st_czas;
st_czas = localtime (&czas);
dzien = st_czas->tm_mday;

for (int i = 0; i < dl_tekst; i++)
	{

char ascii = tekst_t[i];
int value = (int) ascii;
value = ((value + dzien) % 95) + 32;
zaszyfrowany[i] = value;
} 
 
cout << "Podaj nazwe pliku: ";
string nazwa;
cin >> nazwa;
 
fstream plik;
plik.open (nazwa.c_str (), ios::out);
if (plik.good () == true)
	{
for (int i = 0; i < dl_tekst; i++)
plik << zaszyfrowany[i];
plik.close ();
}
       else
	{
cout << "Blad - nie mozna utworzyc pliku.";
cin.clear ();
cin.ignore ();
cin.get();
return 1;
}

cout <<"Program zakonczyl dzialanie i zapisal wynik pracy w pliku " <<nazwa;
cin.clear ();
cin.ignore ();
cin.get();
return 0;
}
 
if (opcja == 2)
    {
cout << "Podaj nazwe pliku: ";
string nazwa;
cin.clear ();
cin.ignore ();
cin >> nazwa;
fstream plik;
plik.open (nazwa.c_str (), ios::in);

if (plik.good () == true)
	{

char zaszyfrowany[1024];
int i = 0;

while (plik)
	    {
plik.get (zaszyfrowany[i]);
i++;
}

int dl_zaszyfrowany = i - 1;
cin.sync ();
string haslo;
char haslo_t[1024];
int licznik=0;
for (;;)
    {
cout << endl << "Podaj klucz: ";
cin >> haslo;
int dl_haslo = haslo.length();
strcpy (haslo_t, haslo.c_str ());

for (int i=0;i<dl_haslo;i++)
{
if (isdigit(haslo[i]))
	{
	   licznik++;
}

}
if (licznik==dl_haslo)
break;

cout << endl << "To nie liczba\n";
}

int inthaslo = stoi (haslo);

for (int i = 0; i < dl_zaszyfrowany; i++)
	    {
int value = zaszyfrowany[i];
value = value + 95 - 32 - inthaslo;
if (value > 126)
value -= 95;
char ascii = (char) value;
tekst_t[i] = ascii;
} 
cout << "Tekst odszyfrownay: " << tekst_t;
plik.close ();
cin.clear ();
cin.ignore ();
cin.get();
return 0;
}
      else
	{
cout << "Blad - nie mozna otworzyc pliku.";
cin.clear ();
cin.ignore ();
cin.get();
return 2;
}
}
system("PAUSE");
}


 
 
 
 
 
 
