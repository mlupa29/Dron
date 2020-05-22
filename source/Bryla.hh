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
    double kat_sm;
    double kat_wz;
    Macierz3x3 Ma;
    Macierz3x3 MoX;
      Macierz3x3 MoY;
    std::shared_ptr<drawNS::Draw3DAPI> &api;
    Wektor3D srodek;
    int id;
    public:
/*!
* \brief konstruktor obiektow klasy Bryla

*/
Wektor3D get_srodek()
{
    return przes;
}
    Wektor3D set_srodek(Wektor3D srodek)
    {
        this->srodek=srodek;
    }
    Bryla(std::shared_ptr<drawNS::Draw3DAPI> &api):api(api)
    {

    }
    
/*!
* \brief virtualna metoda odpowiadajaca za zmiane polozenia

*/






virtual void przesun(Wektor3D przesuniecie)
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
    Wektor3D get_wirz(int i,int j){return kop_krzywa[i][j];}

/*!
* \brief virtualna metoda odpowiadajaca za ruch w plaszczyznie

*/
   virtual void ruch(double przesuniecie, double kat_obr)
    {
        Wektor3D przesun;
        przesun[0]=przesuniecie;
        kat+=kat_obr;
        macierzX();
          
        macierz();
        przes=przes+(Ma*(przesun));
        for(uint i=0; i<krzywa.size(); i++)
        {
            for(uint j=0; j<krzywa.at(i).size(); j++)
            {
                kop_krzywa[i][j]=Ma*(MoX*(krzywa[i][j]-srodek))+przes+srodek;
            } 
        }

    }
/*!
* \brief virtualna metoda odpowiadajaca za ruch w pionie

*/
   virtual void pion(double przesuniecie, double kat_obr)
    {
        Wektor3D przesun;
        przesun[0]=przesuniecie;
        kat_wz=kat_obr;
        macierzX();
        macierzY();
        macierz();
        przes=przes+Ma*(MoY*przesun);
        for(uint i=0; i<krzywa.size(); i++)

        {
            for(uint j=0; j<krzywa.at(i).size(); j++)
            {
                kop_krzywa[i][j]=Ma*(MoX*(krzywa[i][j]-srodek))+przes+srodek;
            } 
        }

    }


 virtual void osx(double przesuniecie, double kat_obr)
    {
        Wektor3D przesun;
        przesun[0]=przesuniecie;
        kat_sm+=kat_obr;
        macierzX();
        macierz();
        //cout<<MoX[1]<<endl;
        for(uint i=0; i<krzywa.size(); i++)
        {
            for(uint j=0; j<krzywa.at(i).size(); j++)
            {
                kop_krzywa[i][j]=Ma*(MoX*(krzywa[i][j]-srodek))+przes+srodek;
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


     void macierzY()
    {
        MoY[0][0]=cos(kat_wz*M_PI/180);
         MoY[0][2]=sin(kat_wz*M_PI/180);
          MoY[1][1]=1;
           MoY[2][0]=-sin(kat_wz*M_PI/180);
            MoY[2][2]=cos(kat_wz*M_PI/180);
    }

     void macierzX()
    {
        MoX[0][0]=1;
         MoX[1][2]=-sin(kat_sm*M_PI/180);
          MoX[1][1]=cos(kat_sm*M_PI/180);
           MoX[2][1]=sin(kat_sm*M_PI/180);
            MoX[2][2]=cos(kat_sm*M_PI/180);
    }

/*!
* \brief virtualna metoda odpowiadajaca za rysowanie obiektow klasy bryla

*/

  virtual  void rysuj()
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