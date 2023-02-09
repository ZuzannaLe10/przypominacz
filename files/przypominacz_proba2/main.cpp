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
  int czas_pow_min;  
  int dzien;         // zmienna przechowująca początkową date powiadomienia
  int miesiac;
  int rok;
  string tresc;    // zmienna przechowująca treść powiadomienia
  string czas_waz; // zmienna przechowująca ważność powiadomienia w (gg-mm)
  string data_waz; // zmienna przechowująca ważność powiadomienia w (dd-mm-yyyy)
};

int i;          // zmienna przechowuje ilosc powiadomien
Task task[200]; // 200 elementowa tablica struktur

// funkcja dodająca
void Dodaj()
{
  cout << "[40;35mPodaj godzine powiadomienia ([40;36mhh[40;35m):[97m" << endl;
  cin >> task[i].czas_pow_godz;

  cout << "[40;35mPodaj minuty powiadomienia ([40;36mmm[40;35m):[97m" << endl;
  cin >> task[i].czas_pow_min;

  cout << "[40;35mPodaj dzien powiadomienia([40;36mdd[40;35m):[97m" << endl;
  cin >> task[i].dzien;

  cout << "[40;35mPodaj miesiec powiadomienia([40;36mmm[40;35m):[97m" << endl;
  cin >> task[i].miesiac;

  cout << "[40;35mPodaj rok powiadomienia([40;36myyyy[40;35m):[97m" << endl;
  cin >> task[i].rok;

  cout << "[40;35mPodaj tresc powiadomienia:[97m" << endl;
  cin >> task[i].tresc;

  cout << "[40;35mPodaj waznosc powiadomienia ([40;36mgg-mm[40;35m):[97m" << endl;
  cin >> task[i].czas_waz;

  cout << "[40;35mPodaj waznosc powiadomienia ([40;36mdd-mm-yyyy[40;35m):[97m" << endl;
  cin >> task[i].data_waz;

  cin.ignore();

  i++;

  cout << ". [40;36mWcisnij ENTER aby zakonczyc dzialanie funkcji![97m";
  getchar();
}

// funkcja pozwalająca na sprawdzanie wartości
void Zobacz()
{
  for (int j = 0; j < i; j++) // j jest indeksem umozliwiajacym wypisywanie kolejnych elementow. Wypisuje od 0 do i
  {                             // j<i wyswietlanie prawidlowej wartosci   i = j-1
    if (i != 0)
    {
      cout << "_________________________________________________________________" << endl;
      cout << "--> Task nr " << j + 1 << ": " << endl;
      cout << "--> Czas powiedomienia: " << task[j].czas_pow_godz << ":" << task[j].czas_pow_min << endl;
      cout << "--> Data powiedomienia: " << task[j].dzien << "/" << task[j].miesiac << "/" << task[j].rok << endl;
      cout << "--> Tresc powiadomienia: " << task[j].tresc << endl;
      cout << "--> Czas waznosci: " << task[j].czas_waz << endl;
      cout << "--> Data waznosci: " << task[j].data_waz << endl;
      cout << "_________________________________________________________________" << endl;
    }
    else
      cout << "[40;36mNie ma podanego powiadomienia w bazie![97m";
  }

  cout << "[40;36mNacisnij ENTER, aby zakonczyc dzialanie funkcji[97m";

  getchar();
}

// funkcja zapisująca dane w pliku tekstowym
void Zapisz()
{
  ofstream plik;
  plik.open("tasks.txt");

  plik << i << endl;

  for (int j = 0; j < i; j++)
  {
    // zapisywanie wartości w pliku tekstowym
    plik << task[j].czas_pow_godz << ":" << task[j].czas_pow_min << " || " << task[j].dzien << "/" << task[j].miesiac << "/" << task[j].rok << " || " << task[j].tresc << " || " << task[j].tresc << " || " << task[j].czas_waz << " || " << task[j].data_waz << endl;
  }

  cout << "[40;36mDane zostaly zapisane!. Wcisnij ENTER, aby zakonczyc dzialanie funkcji[97m";

  getchar();
}

// funkcja usuwająca powiadomienia
void Usun()
{
  int kogo; //zmienna przechowująca id danego powiadomienia

  if (i != 0)
  {
    cout << "[40;36mPodaj numer powiadomienia do usuniecia:[97m";
    cin >> kogo;
    cin.ignore();

    if (kogo > i)
      cout << "[40;31mOperacja nie powiodla sie. Brak powiadomienia o takim numerze[97m";
    else
    {
      for (int k = kogo; k < i; k++)
      {
        task[k - 1].czas_pow_godz = task[k].czas_pow_godz; // polega na zastąpieniu elementu , elementem następnym,  na nastepnie i--
        task[k - 1].czas_pow_min = task[k].czas_pow_min;
        task[k - 1].dzien = task[k].dzien;
        task[k - 1].miesiac = task[k].miesiac;
        task[k - 1].rok = task[k].rok;
        task[k - 1].tresc = task[k].tresc;
        task[k - 1].czas_waz = task[k].czas_waz;
        task[k - 1].data_waz = task[k].data_waz;
      }
      i--;

      cout << "[40;32mOperacja zakonczyla sie sukcesem![40;36m Powiadomienie o numerze " << kogo << "[40;36m zostalo zmienione![97m";
      Zapisz();
    }
  }
  else
  {
    cout << "[40;36mNie ma powiadomienia w bazie! Wcisnij ENTER, aby zakonczyc dzialanie funkcji![97m";
    getchar();
  }
}

// funkcja edytujące powiadomienia
void Edytuj()
{
  int kogo;

  if (i != 0)
  {
    cout << "[40;36mPodaj numer powiadomienia ktore chcesz zmienic: [97m";
    cin >> kogo;
    cin.ignore();

    if (kogo > i)
      cout << "[40;31mOperacja nie powiodla sie. Brak powiadomienia o takim numerze[97m";
    else
    {
      // jest -1 bo numeracja powiadomien jest taka jak w wypisaniu. Natiomiast
      //  tablica zaczyna sie od zera.
      cout << "[40;36mPodaj godzine powiadomienia (hh):[97m" << endl;
      cin >> task[kogo - 1].czas_pow_godz; // jest -1 bo zakladam ze numeracja powiadomien jest taka jak w wypisaniu. Natiomiast
      //  tablica zaczyna sie od zera.
      cout << "[40;36mPodaj minuty powiadomienia (mm):[97m" << endl;
      cin >> task[kogo - 1].czas_pow_min;
      cout << "[40;36mPodaj dzien powiadomienia:[97m" << endl;
      cin >> task[kogo - 1].dzien;
      cout << "[40;36mPodaj miesiac powiadomienia:[97m" << endl;
      cin >> task[kogo - 1].miesiac;
      cout << "[40;36mPodaj rok powiadomienia:[97m" << endl;
      cin >> task[kogo - 1].rok;
      cout << "[40;36mPodaj tresc powiadomienia:[97m" << endl;
      cin >> task[kogo - 1].tresc;
      cout << "[40;36mPodaj waznosc powiadomienia (gg-mm):[97m" << endl;
      cin >> task[kogo - 1].czas_waz;
      cout << "[40;36mPodaj waznosc powiadomienia (dd-mm-yyyy):[97m" << endl;
      cin >> task[kogo - 1].data_waz;

      cout << "[40;32mOperacja zakonczyla sie sukcesem! Powiadomienie o numerze [97m" << kogo << " zostalo zmienione![97m";
      Zapisz();
    }
  }
  else
  {
    cout << "[40;33mNie ma powiadomienia w bazie! Wcisnij ENTER, aby zakonczyc dzialanie funkcji![97m";
    getchar();
  }
}

int main()
{
  system("title Przypominacz & color 0f & ping -n 2 0.0.0.0 >nul & cls & @chcp 65001 >nul & if %errorlevel% == 1 echo Error podczas włączania protokołu UTF-8, Error code: Error while switching mode on module '@chcp 65001'! & if %errorlevel% == 0 echo Uruchomiono protokół UTF-8");
  char wybor;
  do
  {
    cout << "[40;35mCo chcesz zrobic?[97m" << endl;
    cout << "[96m1. [40;36mDodaj powiadomienie[97m" << endl;
    cout << "[96m2. [40;36mWyswietl wszystkie powiadomienia[97m" << endl;
    cout << "[96m3. [40;36mZapisz wprowadzone powiadomienia[97m" << endl;
    cout << "[96m4. [40;36mUsun powiadomienie[97m" << endl;
    cout << "[96m5. [40;36mEdytuj powiadomienie[97m" << endl
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

  time_t now = time(nullptr);
  tm *ltm = localtime(&now);

  cout << "[96mAktualna data systemowa to:[97m " << 1900 + ltm->tm_year << "-"
       << 1 + ltm->tm_mon << "-"
       << ltm->tm_mday << " "
       << ltm->tm_hour << ":"
       << ltm->tm_min << endl;

  for (int j = 0; j < i; j++) // j jest indeksem umozliwiajacym wypisywanie kolejnych elementow. Wypisuje od 0 do i
  {                           // j<i wyswietlanie prawidlowej wartosci   i = j-1

    if (((1900 + ltm->tm_year) == task[j].rok) && ((1 + ltm->tm_mon) == task[j].miesiac) && ((ltm->tm_mday) == task[j].dzien) && (ltm->tm_hour == task[j].czas_pow_godz) && (ltm->tm_min == task[j].czas_pow_min))
    {
      cout << "[40;36mPodany czas powiadomienia:[97m " << task[j].czas_pow_godz << ":" << task[j].czas_pow_min << endl;
      cout << "[40;36mPodana data powiadomienia:[97m " << task[j].dzien << "/" << task[j].miesiac << "/" << task[j].rok << endl;
      cout << "[40;37m+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
      cout << "[40;36m--> Tresc powiadomienia:[97m " << task[j].tresc << endl;
      cout << "[40;37m+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++[97m " << endl;
      system("start Reminder.vbs");
      system("timeout 15 /NOBREAK & taskkill /f /im vbscript.exe /t");
      cout << "Pomyślnie zamknięto proces VBSCRIPT odpowiadający za odtwarzanie dźwięku .mp3" << endl;
      system("pause >nul");
    }
    else
    {
      cout << endl;
      cout << "[40;36mBrak powiadomien na podana date![97m" << endl;
      cout << "[40;36mPodany czas powiadomienia:[97m" << task[j].czas_pow_godz << ":" << task[j].czas_pow_min << endl;
      cout << "[40;36mPodana data powiadomienia:[97m" << task[j].dzien << "/" << task[j].miesiac << "/" << task[j].rok << endl
           << endl;
    }
  }
  return 0;
}
