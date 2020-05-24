#ifndef PLASZ_HH
#define PLASZ_HH
#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "Macierz3x3.hh"
#include "Wektor3D.hh"
#include <vector>
#include <cmath>
using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;




class Plaszczyzna
{

protected:
    vector<vector<Wektor3D>> krzywa;
    vector<vector<Wektor3D>> kop_krzywa;
std::shared_ptr<drawNS::Draw3DAPI> &api;
int id;
    public:
/*!
* \brief Modeluje pojecie klasy Plaszczyzna

*/
    Plaszczyzna(std::shared_ptr<drawNS::Draw3DAPI> &api):api(api)
    {

    }

 /*!
* \brief virtualna metoda odpowiadajaca za rysowanie obiektow klasy Plaszczyzna

*/

   virtual void rysuj();
    





};

#endif