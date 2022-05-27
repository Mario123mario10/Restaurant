#include <iostream>
#include <string>
using std::string;

#include "../Stolik/Stolik.h"
#include "../Kelner/Kelner.h"
#include "../Akcje/ObsługaZamówienia.h"



class ObslugaWyjsciowa
{
  private:
    string nazwa_pliku_wyjscia;
  public:
    ObslugaWyjsciowa();
    ObslugaWyjsciowa(string nazwa_pliku_wyjscia);

    string daj_nazwe_pliku_wyjscia();
    void ustaw_nazwe_pliku_wyjscia(string nowa_nazwa);

    friend ObslugaWyjsciowa& operator<<(ObslugaWyjsciowa& wyjscie, Kelner& kelner);
		friend ObslugaWyjsciowa& operator<<(ObslugaWyjsciowa& wyjscie, Stolik& stolik);
    friend ObslugaWyjsciowa& operator<<(ObslugaWyjsciowa& wyjscie, ObslugaZamowienia& zamowienie);
		friend ObslugaWyjsciowa& operator<<(ObslugaWyjsciowa& wyjscie, Kwota kwota);
		friend ObslugaWyjsciowa& operator<<(ObslugaWyjsciowa& wyjscie, string napis);

    // friend std::ostream& operator<<(std::ostream& os, ObslugaWyjsciowa& nazwa);

};









// class Liczba
// {
// 	public:
// 		int liczba;
// 		Liczba(int liczba)
// 		{	this -> liczba = liczba		;};
// 		friend ostream& operator<<(ostream& os, Liczba& liczba)
// 		{
// 			os << liczba.liczba;
// 			return os;
// 		};

// };

// class OWyj
// {

// 	public:
// 		OWyj()
// 		{};
// 		friend OWyj& operator<<(OWyj& wyjscie, Liczba& liczba)
// 		{
// 			cout << liczba;
// 			return wyjscie;
// 		};
// 		friend OWyj& operator<<(OWyj& wyjscie, string string)
// 		{
// 			cout << string;
// 			return wyjscie;
// 		};

// };


// int main()
// {
// 	Liczba jakas_liczba(4);
// 	OWyj wyjscie;
// 	// cout << jakas_liczba << endl;
// 	wyjscie << jakas_liczba ;
// 	wyjscie << "\n";

// }

