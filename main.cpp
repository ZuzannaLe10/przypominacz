#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <winbase.h>

using namespace std;

struct Task
{
  int czas_pow_godz; // zmienna przechowująca początkowy czas powiadomienia
  int czas_pow_min;  // zmienna przechowująca początkowy czas powiadomienia
  string data_pow;   // zmienna przechowująca początkową date powiadomienia
  string tresc;      // zmienna przechowująca treść powiadomienia
  string czas_waz;   // zmienna przechowująca ważność powiadomienia w (gg-mm)
  string data_waz;   // zmienna przechowująca ważność powiadomienia w (dd-mm-yyyy)
};

int i;          // zmienna przechowuje ilosc powiadomien
Task task[200]; // 200 elementowa tablica struktur

// funkcja dodająca
void Dodaj()
{
  cout << "Podaj godzine powiadomienia (hh):" << endl;
  cin >> task[i].czas_pow_godz;

  cout << "Podaj minuty powiadomienia (mm):" << endl;
  cin >> task[i].czas_pow_min;

  cout << "Podaj date powiadomienia (dd-mm-yyyy):" << endl;
  cin >> task[i].data_pow;

  cout << "Podaj tre\230\206 powiadomienia: " << endl;
  cin >> task[i].tresc;

  cout << "Podaj wa\276no\230\206 powiadomienia (gg-mm): " << endl;
  cin >> task[i].czas_waz;

  cout << "Podaj wa\276no\230\206 powiadomienia (dd-mm-yyyy): " << endl;
  cin >> task[i].data_waz;

  cin.ignore();

  i++;

  cout << ". Wcisnij ENTER aby zako\344czy\206 dzia\210anie funkcji!";
  getchar();
}

// funkcja pozwalająca na sprawdzanie wartości
void Zobacz()
{
  for (short j = 0; j < i; j++) // j jest indeksem umozliwiajacym wypisywanie kolejnych elementow. Wypisuje od 0 do i
  {                             // j<i wyswietlanie prawidlowej wartosci   i = j-1
    if (i != 0)
    {
      cout << "_________________________________________________________________" << endl;
      cout << "--> Task nr " << j + 1 << ": " << endl;
      cout << "--> Czas powiedomienia: " << task[j].czas_pow_godz << ":" << task[j].czas_pow_min << endl;
      cout << "--> Data powiedomienia: " << task[j].data_pow << endl;
      cout << "--> Tresc powiadomienia: " << task[j].tresc << endl;
      cout << "--> Czas wa\276no\230ci: " << task[j].czas_waz << endl;
      cout << "--> Data wa\276no\230ci: " << task[j].data_waz << endl;
      cout << "_________________________________________________________________" << endl;
    }
    else
      cout << "Nie ma podanego powiadomienia w bazie!!";
  }

  cout << "Nacisnij ENTER, aby zakon\344czy\206 dzia\210anie funkcji";

  getchar();
}

// funkcja zapisująca dane w pliku tekstowym
void Zapisz()
{
  ofstream plik;
  plik.open("tasks.txt");

  plik << i << endl;

  for (short j = 0; j < i; j++)
  {
    // zapisywanie wartości w pliku tekstowym
    plik << task[j].czas_pow_godz << ":" << task[j].czas_pow_min << " || " << task[j].data_pow << " || " << task[j].tresc << " || " << task[j].czas_waz << " || " << task[j].data_waz << endl;
  }

  cout << "Dane zostaly zapisane!. Wcisnij ENTER, aby zakon\344czy\206 dzia\210anie funkcji";

  getchar();
}

// funkcja usuwająca powiadomienia
void Usun()
{
  short kogo;

  if (i != 0)
  {
    cout << "Podaj numer powiadomienia do usuni\251cia: ";
    cin >> kogo;
    cin.ignore();

    if (kogo > i)
      cout << "Operacja nie powiodla sie. Brak powiadomienia o takim numerze";
    else
    {
      for (short k = kogo; k < i; k++)
      {
        task[k - 1].czas_pow_godz = task[k].czas_pow_godz; // polega na zastąpieniu elementu , elementem następnym,  na nastepnie i--
        task[k - 1].czas_pow_min = task[k].czas_pow_min;
        task[k - 1].data_pow = task[k].data_pow;
        task[k - 1].tresc = task[k].tresc;
        task[k - 1].czas_waz = task[k].czas_waz;
        task[k - 1].data_waz = task[k].data_waz;
      }
      i--;

      cout << "Operacja zakonczyla sie sukcesem! Powiadomienie o numerze " << kogo << " zosta\210o zmienione!";
      Zapisz();
    }
  }
  else
  {
    cout << "Nie ma powiadomienia w bazie! Wcisnij ENTER, aby zakon\344czy\206 dzia\210anie funkcji!";
    getchar();
  }
}

// funkcja edytujące powiadomienia
void Edytuj()
{
  int kogo;

  if (i != 0)
  {
    cout << "Podaj numer powiadomienia kt\242re chcesz zmieni\206: ";
    cin >> kogo;
    cin.ignore();

    if (kogo > i)
      cout << "Operacja nie powiodla sie. Brak powiadomienia o takim numerze";
    else
    {
      // jest -1 bo numeracja powiadomien jest taka jak w wypisaniu. Natiomiast
      //  tablica zaczyna sie od zera.
      cout << "Podaj godzine powiadomienia (hh):" << endl;
      cin >> task[kogo - 1].czas_pow_godz; // jest -1 bo zakladam ze numeracja powiadomien jest taka jak w wypisaniu. Natiomiast
      //  tablica zaczyna sie od zera.
      cout << "Podaj minuty powiadomienia (mm):" << endl;
      cin >> task[kogo - 1].czas_pow_min;
      cout << "Podaj date powiadomienia (dd-mm-yyyy): " << endl;
      cin >> task[kogo - 1].data_pow;
      cout << "Podaj tre\230\206 powiadomienia: " << endl;
      cin >> task[kogo - 1].tresc;
      cout << "Podaj wa\276no\230\206 powiadomienia (gg-mm): " << endl;
      cin >> task[kogo - 1].czas_waz;
      cout << "Podaj wa\276no\230\206 powiadomienia (dd-mm-yyyy): " << endl;
      cin >> task[kogo - 1].data_waz;

      cout << "Operacja zakonczy\210a si\251 sukcesem! Powiadomienie o numerze " << kogo << " zosta\210o zmienione!";
      Zapisz();
    }
  }
  else
  {
    cout << "Nie ma powiadomienia w bazie! Wcisnij ENTER, aby zakon\344czy\206 dzia\210anie funkcji!";
    getchar();
  }
}

int main()
{
  char wybor;
  do
  {
    cout << "Co chcesz zrobi\206?" << endl;
    cout << "1. Dodaj powiadomienie" << endl;
    cout << "2. Wy\230wietl wszystkie powiadomienia" << endl;
    cout << "3. Zapisz wprowadzone powiadomienia " << endl;
    cout << "4. Usun\245\206 powiadomienie" << endl;
    cout << "5. Edytuj powiadomienie" << endl
         << endl;

    wybor = getch();

    switch (wybor)
    {
    case 49:
      Dodaj();
      break;
    case 50:
      Zobacz();
      break;
    case 51:
      Zapisz();
      break;
    case 52:
      Usun();
      break;
    case 53:
      Edytuj();
      break;
    }
    system("cls");

  } while (wybor != 27);

  for (int j = 0; j < i; j++) // j jest indeksem umozliwiajacym wypisywanie kolejnych elementow. Wypisuje od 0 do i
  {                           // j<i wyswietlanie prawidlowej wartosci   i = j-1

    time_t now = time(nullptr);
    tm *time = localtime(&now);

    cout << "Aktualny czas to: "
         << time->tm_hour << " godzin i "
         << time->tm_min << " minut" << endl;

    if ((task[j].czas_pow_godz == time->tm_hour) && (task[j].czas_pow_min == time->tm_min))
    {
      cout << "Podany czas powiadomienia:" << task[j].czas_pow_godz << ":" << task[j].czas_pow_min << endl;
      cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
      cout << "--> Tresc powiadomienia: " << task[j].tresc << endl;
      cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

      system("start Reminder.vbs");
    }
    else
    {
      cout << "Podany czas powiadomienia:" << task[j].czas_pow_godz << ":" << task[j].czas_pow_min << endl;
      cout << "Brak powiadomie\344 na podan\245 date!" << endl;
    }
  }
  return 0;
}