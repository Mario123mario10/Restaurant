#pragma once
#include <iostream>
using std::cout;	using std::cerr;	using std::endl;

#include <string>
using std::string;

class Kwota
{
  private:
    int zlote;
    int grosze;
  public:
    Kwota();
    Kwota(int zlote, int grosze);

    operator string();

    Kwota& operator+= (const Kwota&  inna_kwota)      ;
    Kwota  operator+  (const Kwota&  inna_kwota) const;
    Kwota& operator-= (const Kwota&  inna_kwota)      ;
    Kwota  operator-  (const Kwota&  inna_kwota) const;

    Kwota& operator+= (int liczba)        ;
    Kwota  operator+  (int liczba)   const;
    Kwota& operator-= (int liczba)        ;
    Kwota  operator-  (int liczba)   const;
    Kwota& operator*= (int mnoznik)       ;
    Kwota  operator*  (int mnoznik)  const;
    Kwota& operator/= (int dzielnik)      ;
    Kwota  operator/  (int dzielnik) const;

    bool operator== (const Kwota&  inna_kwota) const;
    bool operator!= (const Kwota&  inna_kwota) const;
    bool operator<  (const Kwota&  inna_kwota) const;
    bool operator>  (const Kwota&  inna_kwota) const;
    bool operator<= (const Kwota&  inna_kwota) const;
    bool operator>= (const Kwota&  inna_kwota) const;

    bool operator== (int liczba) const;
    bool operator!= (int liczba) const;

    int daj_zlote () const;
    int daj_grosze() const;
    void ustaw_zlote(int nowe_zlote);
    void ustaw_grosze(int nowe_grosze);
    int jako_grosze() const;
    friend std::ostream& operator<<(std::ostream& os, Kwota& Kwota);
};

// Point& Point::operator++()
// {
//    _x++;
//    _y++;
//    return *this;
// }
