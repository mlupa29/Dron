
#ifndef PLASZCZYNA_HH
#define PLASZCZYNA_HH
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

    Plaszczyzna(std::shared_ptr<drawNS::Draw3DAPI> &api):api(api)
    {

    }

 
    void rysuj()
    {  
       
         vector<vector<Point3D>> proste;
               for(int i=0; i<krzywa.size(); i++)
        {
            vector<Point3D> punkty;
            for(int j=0; j<krzywa.at(i).size(); j++)
            {
                Point3D punkt(kop_krzywa[i][j][0],kop_krzywa[i][j][1],kop_krzywa[i][j][2]);
                punkty.push_back(punkt);
            }
            proste.push_back(punkty);
        }
        
 api->draw_surface(proste,"blue");
    }






};

#endif