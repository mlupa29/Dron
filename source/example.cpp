#include <iostream>
#include <unistd.h>
#include "Dr3D_gnuplot_api.hh"
#include "Prostopadloscian.hh"
#include "Powierzchnia.hh"
#include "Dno.hh"
#include "Graniastoslup.hh"
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
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-60,60,-60,60,-60,60,5000)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
  //drawNS::Draw3DAPI * api = new APIGnuPlot3D(-5,5,-5,5,-5,5,1000); //alternatywnie zwykły wskaźnik
 
 /******************
 Z TEGO POWINNA BYC KLASA DRONA ALE SZUKANIE PROBLEMOW I ICH ROZWIAZAN JEST TAK DLA MNIE LATWIEJSZE 
 *******************/
 Granaistoslup s1(3,3,3,api);
 Granaistoslup s2(3,3,3,api);
 Prostopadloscian a(10,10,10,api);
 Powierzchnia po(api);
 Dno d(api);


d.rysuj();


 a.ruch(0,0);

 a.rysuj(); 
  s2.przesun(a.get_wirz(0,3));
  s2.ruch(0,0);

 s2.rysuj();
 s1.przesun(a.get_wirz(0,2));
 s1.ruch(0,0);

 s1.rysuj();
 po.rysuj();
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
 cout<<"Podaj przesuniecie"<<endl;
 double przes; 
 cin>>przes;
 for(int i=0; i<przes; i++)
{
  a.ruch(1,0);
  s1.ruch(1,0);
  s1.rysuj();
  s2.ruch(1,0);
  s2.rysuj();
  a.rysuj();
  api->change_ref_time_ms(1000);
  usleep(5000);
 
}
  api->change_ref_time_ms(5000);
  break;

}


case 'g':
{
 cout<<"Podaj przesuniecie"<<endl;
 double przes; 
 cin>>przes;
 if(przes>=0){
 for(int i=0; i<przes; i++)
{
  a.pion(1,0);
  s1.pion(1,0);
  s1.rysuj();
   s2.pion(1,0);
 s2.rysuj();
  a.rysuj();
  api->change_ref_time_ms(1000);
  usleep(5000);
 }
 api->change_ref_time_ms(5000);
  break;
}
  else
  {
    przes = -przes;
     for(int i=0; i<przes; i++)
{
  a.pion(-1,0);
  s1.pion(-1,0);
  s1.rysuj();
  s2.pion(-1,0);
  s2.rysuj();
  a.rysuj();
  api->change_ref_time_ms(1000);
  usleep(5000);
 }
 api->change_ref_time_ms(5000);
  break;
  }

}

case 'o':
{  std::cout<<"Podaj kat"<<std::endl;
  double k;
  std::cin>>k;

   for(int i=0; i<k; i++)
{
    a.ruch(0,1);
      s1.ruch(0,1);
  s1.rysuj();
   s2.ruch(0,1);
   
  s2.rysuj();
  a.rysuj(); 
   api->change_ref_time_ms(1000);
  usleep(5000);
}
 api->change_ref_time_ms(5000);
break;
}
default:
{
  continue;
}
}
}


 
 //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"
  /*int a=api->draw_line(drawNS::Point3D(0,0,0),drawNS::Point3D(2,0,0)); //rysuje linię pomiędzy (0,0,0) a (2,0,0), zapamiętuje id kształtu w zmiennej a 
  //

  cout << endl << "pojawiły się 2 linie: czarna i czerwona" << endl;  
  wait4key();

  api->erase_shape(a); //usuwa kształt o id a
  cout << "czarna linia zniknęła" << endl;


wait4key();
  api->draw_polygonal_chain(vector<Point3D> {drawNS::Point3D(0,0,0),
	drawNS::Point3D(0,4,0),drawNS::Point3D(4,4,0),
	drawNS::Point3D(4,0,0),drawNS::Point3D(4,0,4)},"purple"); //rysuje fioletową łamaną
  cout << "pojawiła się fioletowa łamana" << endl;
  
  wait4key();
  api->change_ref_time_ms(1000);
  int b=api->draw_polygonal_chain(vector<Point3D> {drawNS::Point3D(0,0,0),
	drawNS::Point3D(0,-4,0),drawNS::Point3D(-4,-4,0),
	drawNS::Point3D(-4,0,0),drawNS::Point3D(-4,0,-4)},"green");
  cout << "pojawiła się zielona łamana" << endl;
  
  wait4key();
  api->change_shape_color(b,"yellow");//zmienia kolor
  cout << "zmiana koloru z zielonej na żółtą" << endl;

  wait4key();
  api->change_ref_time_ms(-1);//odświerzanie sceny zmienione na opcję "tylko za pomocą metody redraw()"

  api->draw_polyhedron(vector<vector<Point3D> > {{
	drawNS::Point3D(0,0,0), drawNS::Point3D(0,1,0), drawNS::Point3D(1,1,0)
      },{
	drawNS::Point3D(0,0,3), drawNS::Point3D(0,1,3), drawNS::Point3D(1,2,4)       
	  }},"blue");//rysuje niebieski graniastosłup
  cout << "nie pojawiła się niebieski graniastosłup" << endl;
  
  wait4key();

  api->redraw();//odświerzenie sceny
  cout << "dopiero teraz pojawiła się niebieski graniastosłup" << endl;

  wait4key();
  api->change_ref_time_ms(0);

  api->draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(-4,-2,-4), drawNS::Point3D(-4,0,-4), drawNS::Point3D(-4,2,-4)
	  },{
	drawNS::Point3D(-2,-2,-4), drawNS::Point3D(-2,0,-4), drawNS::Point3D(-2,2,-4)       
	  },{
	drawNS::Point3D(-0,-2,-4), drawNS::Point3D(-0,0,-3), drawNS::Point3D(-0,2,-4)       
	  },{
	drawNS::Point3D(2,-2,-4), drawNS::Point3D(2,0,-4), drawNS::Point3D(2,2,-4)       
	  },{
	drawNS::Point3D(4,-2,-4), drawNS::Point3D(4,0,-4), drawNS::Point3D(4,2,-4)       
	  }},"grey");//rysuje szarą powierzchnie
  cout << "pojawiła się szara powierzchnia" << endl;

  
  wait4key();
  
  */
  //delete api;//dla zwykłych wskaźników musimy posprzątać
}
