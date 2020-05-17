

#include <iostream>
#include <algorithm>
#include "wektor.hh"

template<typename Typ, int Siz >
class Macierz {

    Wektor<Typ, Siz> Tab[Siz];

public:
    Macierz(); 
    Wektor<Typ, Siz> operator[] (int i) const { return Tab[i]; }
    Wektor<Typ, Siz>& operator[] (int i) { return Tab[i]; }

    Typ Wyznacznik() const;
    void Transpozycja(Macierz& Mc);


    Wektor<Typ, Siz>  operator * (const Wektor<Typ, Siz>& W);


};

template<typename Typ, int Siz >
Macierz<Typ, Siz>::Macierz()
{

}


template<typename Typ, int Siz >
std::istream& operator >> (std::istream& Strm, Macierz<Typ, Siz>& Mac)
{
    for (int i = 0; i < Siz; i++)
        Strm >> Mac[i];

    return Strm;
}

template<typename Typ, int Siz >
std::ostream& operator << (std::ostream& Strm, const Macierz<Typ, Siz>& Mac)
{
    for (int i = 0; i < Siz; i++)
        Strm << Mac[i] << std::endl;

    return Strm;
}

template<typename Typ, int Siz >
Wektor<Typ, Siz>  Macierz<Typ, Siz>::operator * (const Wektor<Typ, Siz>& W)
{
   
    Wektor<Typ, Siz> wynik;
    for (int i = 0; i < Siz; i++)
        wynik[i] = Tab[i] * W;

    return wynik;

}

template<typename Typ, int Siz >
Typ Macierz<Typ, Siz>::Wyznacznik() const
{
    Typ pom;
    pom = 0;
    Macierz<Typ, Siz> kop = *this;
    int p = 0;
    for (int i = 0; i < Siz; i++)
    {
        for (int j = i + 1; j < Siz; j++)
        {
            if (kop[i][i] == pom)
            {
                p++;
                std::swap(kop[i], kop[j]);
            }
        }
        if (kop[i][i] == pom)
            return pom;
        for (int j = i + 1; j < Siz; j++)
        {
            kop[j] = kop[j] - kop[i] * kop[j][i] / kop[i][i];
        }
    }
    pom = 1;
    Typ wyznacznik = pom;
    for (int i = 0; i < Siz; i++)
    {
        wyznacznik = wyznacznik * kop[i][i];
    }
    if (p % 2 == 0)
    {
        return wyznacznik;
    }
    return wyznacznik * -1;
}

template<typename Typ, int Siz >
void Macierz<Typ, Siz>::Transpozycja(Macierz<Typ, Siz>& Mc) {
    Macierz<Typ, Siz> P;
    P = Mc;
    for (int i = 0; i < Siz; i++) {
        for (int j = 0; j < Siz; j++) {
            (Mc[j])[i] = (P[i])[j];
        }
    }
}




