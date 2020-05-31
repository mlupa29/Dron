#include "Bryla.hh"
using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;




 void Bryla::przesun(Wektor3D przesuniecie)
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

    


    void Bryla::ruch(double przesuniecie, double kat_obr)
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

    void Bryla::pion(double przesuniecie, double kat_obr)
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


     void Bryla::osx(double przesuniecie, double kat_obr)
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





    void Bryla::macierz()
    {
        Ma[0][0]=cos(kat*M_PI/180);
         Ma[0][1]=-sin(kat*M_PI/180);
          Ma[1][0]=sin(kat*M_PI/180);
           Ma[1][1]=cos(kat*M_PI/180);
            Ma[2][2]=1;
    }


     void Bryla::macierzY()
    {
        MoY[0][0]=cos(kat_wz*M_PI/180);
         MoY[0][2]=sin(kat_wz*M_PI/180);
          MoY[1][1]=1;
           MoY[2][0]=-sin(kat_wz*M_PI/180);
            MoY[2][2]=cos(kat_wz*M_PI/180);
    }

     void Bryla::macierzX()
    {
        MoX[0][0]=1;
         MoX[1][2]=-sin(kat_sm*M_PI/180);
          MoX[1][1]=cos(kat_sm*M_PI/180);
           MoX[2][1]=sin(kat_sm*M_PI/180);
            MoX[2][2]=cos(kat_sm*M_PI/180);
    }



    void Bryla::rysuj()
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




