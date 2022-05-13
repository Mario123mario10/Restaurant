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
    Kwota(int grosze);
    Kwota(int zlote, int grosze);
    Kwota(string kwota);
    // Kwota(float kwota);

    operator string();

    Kwota& operator+= (const Kwota&  inna_kwota)      ;
    Kwota  operator+  (const Kwota&  inna_kwota) const;
    Kwota& operator-= (const Kwota&  inna_kwota)      ;
    Kwota  operator-  (const Kwota&  inna_kwota) const;
    Kwota& operator*= (const Kwota&  inna_kwota)      ;
    Kwota  operator*  (const Kwota&  inna_kwota) const;
    Kwota& operator/= (const Kwota&  inna_kwota)      ;
    Kwota  operator/  (const Kwota&  inna_kwota) const;
    Kwota& operator%= (const Kwota&  inna_kwota)      ;
    Kwota  operator%  (const Kwota&  inna_kwota) const;
    Kwota& operator++ ();
    Kwota  operator++(int);
    Kwota& operator-- ();
    Kwota  operator--(int);

    bool operator== (const Kwota&  inna_kwota) const;
    bool operator!= (const Kwota&  inna_kwota) const;
    bool operator<  (const Kwota&  inna_kwota) const;
    bool operator>  (const Kwota&  inna_kwota) const;
    bool operator<= (const Kwota&  inna_kwota) const;
    bool operator>= (const Kwota&  inna_kwota) const;

    int daj_zlote () const;
    int daj_grosze() const;
    void ustaw_zlote(int nowe_zlote);
    void ustaw_grosze(int nowe_grosze);

    friend std::ostream& operator<<(std::ostream& os, Kwota& Kwota);
};

// Point& Point::operator++()
// {
//    _x++;
//    _y++;
//    return *this;
// }
