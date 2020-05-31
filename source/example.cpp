#include <iostream>
#include <unistd.h>
#include "Dr3D_gnuplot_api.hh"
#include "Prostopadloscian.hh"
#include "Powierzchnia.hh"
#include "Dno.hh"
#include "Graniastoslup.hh"
#include "Dron.hh"
#include "P_Prostopadloscian.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;
using namespace std;


void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}



int main() {
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-60,60,-60,60,-60,60,0)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
  



 /*!
  *\brief Powstanie powierzchni oraz dna
  * Iniciuje powstanie dna oraz powierzchni
  * 
  */
 Powierzchnia po(api);
 Dno d(api);
 P_Prostopadloscian p(3,4,12,api);
P_Prostopadloscian pplaszczyzna(0,6,15,api);
P_Prostopadloscian pret(0,0,20,api);
P_Prostopadloscian pplasz(10,0,20,api);
d.rysuj();
po.rysuj();
 p.ruch(30,0);
p.rysuj();

pplaszczyzna.ruch(20,140);
pplaszczyzna.rysuj();



pret.ruch(30,298);

pret.rysuj();


pplasz.ruch(30,280);
pplasz.pion(34,90);
pplasz.rysuj();



Dron dron(api);
dron.start();
 
// Dron dron2(api);
// dron2.goradol(&p);

// dron2.start();


/*!
  *\brief Petla wyboru funkcji
  * Pozwala uzytkownikowi na uzycie wybranej przez niego funkcji
  * 
  */

char men = 'h';

while(men!='q'){
cout<<"wybierz opcje:"<<endl;
cout<<"p - przesuniecie"<<endl;
cout<<"o - obrot"<<endl;
cout<<"g - przesuniecie gora/dol"<<endl;
cout<<"q - koniec"<<endl;

  std::cin>>men;

switch(men){


 
case 'p':
{
 dron.przod(&p);
  break;

}


case 'g':
{
 dron.goradol(&p);

  break;


}



case 'o':
{  dron.obrot();

break;
}
default:
{
  continue;
}
}
}
}



 

