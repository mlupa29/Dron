#ifndef BRYLA_HH
#define BRYLA_HH
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

/*!
* \brief klasa bazowa dla figur

*/

//Powinnien byc podzial na piliki ale dla wygodny narazie tego nie robilem 

class Bryla
{

protected:
    vector<vector<Wektor3D>> krzywa;
    vector<vector<Wektor3D>> kop_krzywa;
    Wektor3D przes;
    double kat;
    Macierz3x3 Ma;
    std::shared_ptr<drawNS::Draw3DAPI> &api;
    int id;
    public:
/*!
* \brief konstruktor obiektow klasy Bryla

*/
    Bryla(std::shared_ptr<drawNS::Draw3DAPI> &api):api(api)
    {

    }
    
/*!
* \brief virtualna metoda odpowiadajaca za zmiane polozenia

*/

 void przesun(Wektor3D przesuniecie)
    {
      
        przes=przes+(przesuniecie);
        for(uint i=0; i<krzywa.size(); i++)
        {
            for(uint j=0; j<krzywa.at(i).size(); j++)
            {
                kop_krzywa[i][j]=(krzywa[i][j])+przes;
            } 
        }

    }

Wektor3D get_przsuniecie(){
    return przes;
}
    Wektor3D get_wirz(int i,int j){return krzywa[i][j];}

/*!
* \brief virtualna metoda odpowiadajaca za ruch w plaszczyznie

*/
   void ruch(double przesuniecie, double kat_obr)
    {
        Wektor3D przesun;
        przesun[0]=przesuniecie;
        kat+=kat_obr;
        macierz();
        przes=przes+(Ma*przesun);
        for(uint i=0; i<krzywa.size(); i++)
        {
            for(uint j=0; j<krzywa.at(i).size(); j++)
            {
                kop_krzywa[i][j]=(Ma*krzywa[i][j])+przes;
            } 
        }

    }
/*!
* \brief virtualna metoda odpowiadajaca za ruch w pionie

*/
    void pion(double przesuniecie, double kat_obr)
    {
        Wektor3D przesun;
        przesun[2]=przesuniecie;
        kat+=kat_obr;
        macierz();
        przes=przes+(Ma*przesun);
        for(uint i=0; i<krzywa.size(); i++)
        {
            for(uint j=0; j<krzywa.at(i).size(); j++)
            {
                kop_krzywa[i][j]=(Ma*krzywa[i][j])+przes;
            } 
        }

    }
/*!
* \brief macierz obrotu

*/

    void macierz()
    {
        Ma[0][0]=cos(kat*M_PI/180);
         Ma[0][1]=-sin(kat*M_PI/180);
          Ma[1][0]=sin(kat*M_PI/180);
           Ma[1][1]=cos(kat*M_PI/180);
            Ma[2][2]=1;
   

    }

/*!
* \brief virtualna metoda odpowiadajaca za rysowanie obiektow klasy bryla

*/

    void rysuj()
    {
          api->erase_shape(id); 
         vector<vector<Point3D>> proste;
               for(uint i=0; i<krzywa.size(); i++)
        {
            vector<Point3D> punkty;
            for(uint j=0; j<krzywa.at(i).size(); j++)
            {
                Point3D punkt(kop_krzywa[i][j][0],kop_krzywa[i][j][1],kop_krzywa[i][j][2]);
                punkty.push_back(punkt);
            }
            proste.push_back(punkty);
        }
        
 id=api->draw_polyhedron(proste,"red");
    }




};
#endif