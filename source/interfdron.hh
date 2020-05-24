#pragma once 
//Nie aktywna 
#include <iostream>
#include <unistd.h>
#include "Dr3D_gnuplot_api.hh"
#include "Prostopadloscian.hh"
#include "Graniastoslup.hh"
using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using namespace std;


 class IDron {
public:
virtual void inicjuj();
virtual void przod();
virtual void obrot(); 
virtual void goradol();
 
 };