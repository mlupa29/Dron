#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include "Bryla.hh"

class Przeszkoda
{


public:

Przeszkoda(){};
virtual bool czy_kolizja(Wektor3D srodek,double promien_drona,double przesuniecie)=0;


};



#endif