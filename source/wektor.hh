#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <math.h>

template<typename Typ, int Siz >
class Wektor {
    Typ Tab[Siz];

public:
    Wektor() { for (Typ& Wsp : Tab) Wsp = 0; };
    Typ operator[] (int i) const { return Tab[i]; }
    Typ& operator[] (int i) { return Tab[i]; }


    Wektor<Typ, Siz> operator +(Wektor<Typ, Siz> W);
    Wektor<Typ, Siz> operator -(Wektor<Typ, Siz> W);
    Typ operator *(Wektor<Typ, Siz> W);
    Wektor<Typ, Siz> operator /(Typ skalar);
    Wektor<Typ, Siz> operator *(Typ skalar) ;
    double dlugosc();

};
template<class Typ, int Siz>
double Wektor<Typ,Siz>::dlugosc(){
double dlugosc = 0;

for(int i=0; i <Siz ; i++){
    dlugosc += pow(this->Tab[i],2);
}
return sqrt(dlugosc);
}


template<class Typ, int Siz >
std::istream& operator >> (std::istream& Strm, Wektor<Typ, Siz>& Wek)
{
    for (int i = 0; i < Siz; i++)
        Strm >> Wek[i];

    return Strm;
}



template<class Typ, int Siz >
std::ostream& operator << (std::ostream& Strm, const Wektor<Typ, Siz>& Wek)
{
    for (unsigned int i = 0; i < Siz; i++)
        Strm << Wek[i] << " ";

    return Strm;
}


template<class Typ, int Siz >
Wektor<Typ, Siz> Wektor<Typ, Siz>::operator +(Wektor<Typ, Siz>  W) 
{
    Wektor<Typ, Siz> Wynik;
    for (int i = 0; i < Siz; i++)
        Wynik[i] = Tab[i] + W[i];
    return Wynik;
}

template<class Typ, int Siz >
Wektor<Typ, Siz> Wektor<Typ, Siz>::operator -(Wektor<Typ, Siz> W) 
{
    Wektor<Typ, Siz> Wynik;
    for (int i = 0; i < Siz; i++)
        Wynik[i] = Tab[i] - W[i];
    return Wynik;
}

template<class Typ, int Siz >
Typ Wektor<Typ, Siz>::operator *(Wektor<Typ, Siz> W) 
{
    Typ Wynik;
    Wynik = 0;
    for (int i = 0; i < Siz; i++)
        Wynik = Tab[i] * W[i] + Wynik;
    return Wynik;
}

template<class Typ, int Siz >
Wektor<Typ, Siz> Wektor<Typ, Siz>::operator /(Typ skalar) 
{
    Typ pom;
    pom = 0;
    if (skalar == pom)
    {
        std::cerr << "skalar musi byc rozny !=0";
        std::exit(EXIT_FAILURE);
    }
    else {
        Wektor<Typ, Siz> Wynik;
        for (int i = 0; i < Siz; i++)
            Wynik[i] = Tab[i] / skalar;
        return Wynik;
    }
}

template<class Typ, int Siz >
Wektor<Typ, Siz> Wektor<Typ, Siz>::operator *(Typ skalar) 
{

    Wektor<Typ, Siz> Wynik;
    for (int i = 0; i < Siz; i++)
        Wynik[i] = Tab[i] * skalar;
    return Wynik;
}

#endif
