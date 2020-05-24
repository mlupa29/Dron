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

/*!
 *\file Plik main oraz "Dron"
 *\brief Plik zawiera w sobie plik main oraz skladowe klasy Dron
 *
 *Klasa modeluje pojecie Drona skladajacego sie z Prostopadloscianu oraz 2 srub 
 *o zadanej dlugosci boku.
 *Ruch samego drona oraz jego srub jest animowany oraz odbywa sie na zasadach poruszania 
 *porownywalnych to rzeczywistego ruchu takiego drona w srodowisku wodnym
 *Niestety skladowe modulu drona znajduje sie tutaj poniewaz wystepowal u mnie problem 
 *z redefinicjami klas bazowych drona podczas kompilacji co ja nieumozliwialo :(
 */



int main() {
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-60,60,-60,60,-60,60,0)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
  
 /*!
  *\brief Bazowa budowa Drona
  * Modul modeluje pojecie drona o zadanych figurach o zadanych dlugosciach, szerokosciach , wysokosciach 
  * Iniciuje powstanie zadanych obiektow
  */
 Granaistoslup s1(3,3,3,api);
 Granaistoslup s2(3,3,3,api);
 Prostopadloscian a(10,10,10,api);


 /*!
  *\brief Powstanie powierzchni oraz dna
  * Iniciuje powstanie dna oraz powierzchni
  * 
  */
 Powierzchnia po(api);
 Dno d(api);


/*!
  *\brief Rysowanie elementow w programie graficznym gnuplot
  * Metody rysujace wymienione w wyzszej czesci dokumentacji figury oraz 
  * ma za zadanie ustawienie srub wzgledem drona. 
  * 
  */
po.rysuj();
d.rysuj();

 a.ruch(0,0);
 a.rysuj(); 
  s2.przesun(a.get_wirz(0,3));
  s2.ruch(0,0);
 s2.rysuj();
 s1.przesun(a.get_wirz(0,2));
 s1.ruch(0,0);
 s1.rysuj();

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


  /*!
  *\brief Metoda umozliwiajaca poruszanie sie dronem w przod
  * Metoda umozliwia poruszanie sie dronem na zadana odleglosc do przodu.
  * Ruch drona jest animowany poprzez odpowiedni dobor parametrow spowalniajacych dzialanie 
  * funkcji i sklada sie on z postepujacych po sobie malych przesuniec dla drona wraz z jego
  * srubami ktorych obrot jest skierowany w przeciwnych kierunkach obrotu .
  * 
  * \param[in] przes - liczba mikro ruchow o ktore przesunie sie dron
  */
case 'p':
{
 cout<<"Podaj przesuniecie"<<endl;
 double przes; 
 cin>>przes;
 if(!cin.good()){
   cerr<< "Wprowadzono zla dana"<<endl;
   exit(1);
 }

 for(int i=0; i<przes; i++)
{
  a.ruch(1,0);
  s1.ruch(1,0);
  s1.rysuj();
  s2.ruch(1,0);
  s2.rysuj();
  
  s1.osx(0,10);
  s2.osx(0,-10);
  a.rysuj();
  
  usleep(120000);
 
}
  break;

}
 /*!
  *\brief Metoda umozliwiajaca poruszanie sie dronem w gore lub dol oraz naprzod lub do tylu pod wybranym katem opadania lub wznoszenia
  * Metoda umozliwia poruszanie sie dronem na zadana odleglosc oraz pod wybranym katem.
  * Ruch drona jest animowany poprzez odpowiedni dobor parametrow spowalniajacych dzialanie 
  * funkcji i sklada sie on z postepujacych po sobie malych przesuniecdla drona wraz z jego
  * srubami ktorych obrot jest skierowany w przeciwnych kierunkach obrotu 
  * 
  * \param[in] przesu - liczba mikro ruchow o ktore przesunie sie dron
  * \param[in] kat - liczba stopni okreslajaca kierunek ruchu
  */

case 'g':
{
 cout<<"Podaj przesuniecie"<<endl;
 double przesu; 
 cin>>przesu;
  if(!cin.good()){
   cerr<< "Wprowadzono zla dana"<<endl;
   exit(1);}
 cout<<"Podaj kat"<<endl;
 double kat; 
 cin>>kat;
  if(!cin.good()){
   cerr<< "Wprowadzono zla dana"<<endl;
   exit(1);}
 
 for(int i=0; i<przesu; i++)
{
  a.pion(1,kat);
  s1.pion(1,kat);
  s2.pion(1,kat);
  s1.osx(0,10);
  s2.osx(0,-10);
  s1.rysuj();
 s2.rysuj();
  a.rysuj();
   usleep(100000);
 }

  break;


}

/*!
  *\brief Metoda umozliwiajaca obracanie sie dronem o wybrany kat
  * Metoda umozliwiajaca obrot drona o dany kat.
  * Ruch drona jest animowany poprzez odpowiedni dobor parametrow spowalniajacych dzialanie 
  * funkcji i sklada sie on z postepujacych po sobie malych przesuniec dla drona wraz z jego
  * srubami ktorych obrot jest skierowany w przeciwnych kierunkach obrotu 
  * 
  * \param[in] k - liczba mikro ruchow o ktore obroci sie dron
  */


case 'o':
{  std::cout<<"Podaj kat"<<std::endl;
  double k;
  std::cin>>k;
   if(!cin.good()){
   cerr<< "Wprowadzono zla dana"<<endl;
   exit(1);
   }
   for(int i=0; i<k; i++)
{
    a.ruch(0,1);
    
  s1.przesun(a.get_wirz(0,2));
     s2.przesun(a.get_wirz(0,3));
      s1.ruch(0,1);
       s2.ruch(0,1);

        s1.osx(0,10);
  s2.osx(0,-10);
  s1.rysuj();
 
   
  s2.rysuj();
  a.rysuj(); 
   usleep(60000);
}

break;
}
default:
{
  continue;
}
}
}
}


 
//  //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"
//   /*int a=api->draw_line(drawNS::Point3D(0,0,0),drawNS::Point3D(2,0,0)); //rysuje linię pomiędzy (0,0,0) a (2,0,0), zapamiętuje id kształtu w zmiennej a 
//   //

//   cout << endl << "pojawiły się 2 linie: czarna i czerwona" << endl;  
//   wait4key();

//   api->erase_shape(a); //usuwa kształt o id a
//   cout << "czarna linia zniknęła" << endl;


// wait4key();
//   api->draw_polygonal_chain(vector<Point3D> {drawNS::Point3D(0,0,0),
// 	drawNS::Point3D(0,4,0),drawNS::Point3D(4,4,0),
// 	drawNS::Point3D(4,0,0),drawNS::Point3D(4,0,4)},"purple"); //rysuje fioletową łamaną
//   cout << "pojawiła się fioletowa łamana" << endl;
  
//   wait4key();
//   api->change_ref_time_ms(1000);
//   int b=api->draw_polygonal_chain(vector<Point3D> {drawNS::Point3D(0,0,0),
// 	drawNS::Point3D(0,-4,0),drawNS::Point3D(-4,-4,0),
// 	drawNS::Point3D(-4,0,0),drawNS::Point3D(-4,0,-4)},"green");
//   cout << "pojawiła się zielona łamana" << endl;
  
//   wait4key();
//   api->change_shape_color(b,"yellow");//zmienia kolor
//   cout << "zmiana koloru z zielonej na żółtą" << endl;

//   wait4key();
//   api->change_ref_time_ms(-1);//odświerzanie sceny zmienione na opcję "tylko za pomocą metody redraw()"

//   api->draw_polyhedron(vector<vector<Point3D> > {{
// 	drawNS::Point3D(0,0,0), drawNS::Point3D(0,1,0), drawNS::Point3D(1,1,0)
//       },{
// 	drawNS::Point3D(0,0,3), drawNS::Point3D(0,1,3), drawNS::Point3D(1,2,4)       
// 	  }},"blue");//rysuje niebieski graniastosłup
//   cout << "nie pojawiła się niebieski graniastosłup" << endl;
  
//   wait4key();

//   api->redraw();//odświerzenie sceny
//   cout << "dopiero teraz pojawiła się niebieski graniastosłup" << endl;

//   wait4key();
//   api->change_ref_time_ms(0);

//   api->draw_surface(vector<vector<Point3D> > {{
// 	drawNS::Point3D(-4,-2,-4), drawNS::Point3D(-4,0,-4), drawNS::Point3D(-4,2,-4)
// 	  },{
// 	drawNS::Point3D(-2,-2,-4), drawNS::Point3D(-2,0,-4), drawNS::Point3D(-2,2,-4)       
// 	  },{
// 	drawNS::Point3D(-0,-2,-4), drawNS::Point3D(-0,0,-3), drawNS::Point3D(-0,2,-4)       
// 	  },{
// 	drawNS::Point3D(2,-2,-4), drawNS::Point3D(2,0,-4), drawNS::Point3D(2,2,-4)       
// 	  },{
// 	drawNS::Point3D(4,-2,-4), drawNS::Point3D(4,0,-4), drawNS::Point3D(4,2,-4)       
// 	  }},"grey");//rysuje szarą powierzchnie
//   cout << "pojawiła się szara powierzchnia" << endl;

  
//   wait4key();
  
//   */
//   //delete api;//dla zwykłych wskaźników musimy posprzątać
// }





// #include <iostream>
// #include <unistd.h>
// #include "Dr3D_gnuplot_api.hh"
// #include "Prostopadloscian.hh"
// #include "Powierzchnia.hh"
// #include "Dno.hh"
// #include "Graniastoslup.hh"
// #include "Dron.hh"
// using std::vector;
// using drawNS::Point3D;
// using drawNS::APIGnuPlot3D;
// using std::cout;
// using std::endl;
// using namespace std;


// void wait4key() {
//   do {
//     std::cout << "\n Press a key to continue..." << std::endl;
//   } while(std::cin.get() != '\n');
// }





// class Dron : public Bryla 
// {

// public:

// Granaistoslup s1;
// Granaistoslup s2;
// Prostopadloscian a;


// Dron(std::shared_ptr<drawNS::Draw3DAPI> &api):Bryla(api){};


// void rysdr(){
// Granaistoslup s1(3,3,3,api);
// Granaistoslup s2(3,3,3,api);
// Prostopadloscian a(10,10,10,api);

//  a.ruch(0,0);

//  a.rysuj(); 
//   s2.przesun(a.get_wirz(0,3));
//   s2.ruch(0,0);

//  s2.rysuj();
//  s1.przesun(a.get_wirz(0,2));
//  s1.ruch(0,0);

//  s1.rysuj();
// }
//  void przod(std::shared_ptr<drawNS::Draw3DAPI> &api)
//  {
   
// Granaistoslup s1(3,3,3,api);
// Granaistoslup s2(3,3,3,api);
// Prostopadloscian a(10,10,10,api);
//      cout<<"Podaj przesuniecie"<<endl;
//  double przes; 
//  cin>>przes;
//  for(int i=0; i<przes; i++)
// {
//   s2.przesun(a.get_wirz(0,3));
//   s1.przesun(a.get_wirz(0,2));
//   a.ruch(1,0);
//   s1.ruch(1,0);
//   s1.rysuj();
//   s2.ruch(1,0);
//   s2.rysuj();
  
//   s1.osx(0,10);
//   s2.osx(0,-10);
//   a.rysuj();
  
//   usleep(120000);
// }
// }
// void obrut(std::shared_ptr<drawNS::Draw3DAPI> &api)
//  {
//    Granaistoslup s1(3,3,3,api);
// Granaistoslup s2(3,3,3,api);
// Prostopadloscian a(10,10,10,api);
//      std::cout<<"Podaj kat"<<std::endl;
//   double k;
//   std::cin>>k;

//    for(int i=0; i<k; i++)
// {
//     a.ruch(0,1);
    
//   s1.przesun(a.get_wirz(0,2));
//      s2.przesun(a.get_wirz(0,3));
//       s1.ruch(0,1);
//        s2.ruch(0,1);
//   s1.rysuj();
 
   
//   s2.rysuj();
//   a.rysuj(); 
//    usleep(60000);
// }
// }
// };



// int main() {
//   std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-60,60,-60,60,-60,60,0)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
//   //drawNS::Draw3DAPI * api = new APIGnuPlot3D(-5,5,-5,5,-5,5,1000); //alternatywnie zwykły wskaźnik
 
 
// //  Granaistoslup s1(3,3,3,api);
// //  Granaistoslup s2(3,3,3,api);
// //  Prostopadloscian a(10,10,10,api);

// Dron dro(api);
//  Powierzchnia po(api);
//  Dno d(api);

// po.rysuj();
// d.rysuj();

// // dro.rysdr();
// //  a.ruch(0,0);

// //  a.rysuj(); 
// //   s2.przesun(a.get_wirz(0,3));
// //   s2.ruch(0,0);

// //  s2.rysuj();
// //  s1.przesun(a.get_wirz(0,2));
// //  s1.ruch(0,0);

// //  s1.rysuj();
 
// char men = 'h';

// while(men!='q'){
// cout<<"wybierz opcje:"<<endl;
// cout<<"p - przesuniecie"<<endl;
// cout<<"o - obrot"<<endl;
// cout<<"g - przesuniecie gora/dol"<<endl;
// cout<<"q - koniec"<<endl;
//   std::cin>>men;

// switch(men){
// case 'p':
// {
//    dro.przod(api);
//   break;

// }


// // case 'g':
// // {
// // dro.goradol(api);
 
// //   break;


// // }

// case 'o':
// {  
  
// dro.obrut(api);
// break;
// }
// default:
// {
//   continue;
// }
// }
// }
// }
// }
// class Dron : public Bryla 
// {

// public:

// // Granaistoslup s1;
// // Granaistoslup s2;
// // Prostopadloscian a;


// Dron(std::shared_ptr<drawNS::Draw3DAPI> &api):Bryla(api)
// {
//   Prostopadloscian p(10,10,10,api);
//   Granaistoslup(3,3,3,api);
//   Granaistoslup(3,3,3,api);
// };
// void rysujdr()
// {
// Granaistoslup s1(3,3,3,api);
// Granaistoslup s2(3,3,3,api);
// Prostopadloscian a(10,10,10,api);

//  a.ruch(0,0);

//  a.rysuj(); 
//   s2.przesun(a.get_wirz(0,3));
//   s2.ruch(0,0);

//  s2.rysuj();
//  s1.przesun(a.get_wirz(0,2));
//  s1.ruch(0,0);

//  s1.rysuj();
// };


//  void przod(std::shared_ptr<drawNS::Draw3DAPI> &api)
//  {
// Granaistoslup s1(3,3,3,api);
// Granaistoslup s2(3,3,3,api);
// Prostopadloscian a(10,10,10,api);
//      cout<<"Podaj przesuniecie"<<endl;
//  double przes; 
//  cin>>przes;
//  for(int i=0; i<przes; i++)
// {

//   a.ruch(1,0);
//   s1.ruch(1,0);
//   s1.rysuj();
//   s2.ruch(1,0);
//   s2.rysuj();
  
//   s1.osx(0,10);
//   s2.osx(0,-10);
//   a.rysuj();
  
//   usleep(120000);
// }
// }


//  virtual void obrut(std::shared_ptr<drawNS::Draw3DAPI> &api)
//  {
//    Granaistoslup s1(3,3,3,api);
// Granaistoslup s2(3,3,3,api);
// Prostopadloscian a(10,10,10,api);
//      std::cout<<"Podaj kat"<<std::endl;
//   double k;
//   std::cin>>k;

//    for(int i=0; i<k; i++)
// {
//     a.ruch(0,1);
    
//   s1.przesun(a.get_wirz(0,2));
//      s2.przesun(a.get_wirz(0,3));
//       s1.ruch(0,1);
//        s2.ruch(0,1);
//   s1.rysuj();
 
   
//   s2.rysuj();
//   a.rysuj(); 
//    usleep(60000);
// }
// }

//  virtual void goradol(std::shared_ptr<drawNS::Draw3DAPI> &api)
//  {
//    Granaistoslup s1(3,3,3,api);
// Granaistoslup s2(3,3,3,api);
// Prostopadloscian a(10,10,10,api);
//      cout<<"Podaj przesuniecie"<<endl;
//  double przesu; 
//  cin>>przesu;
//  cout<<"Podaj kat"<<endl;
//  double kat; 
//  cin>>kat;
 
//  for(int i=0; i<przesu; i++)
// {
//   a.pion(1,kat);
//   s1.pion(1,kat);
//   s2.pion(1,kat);
//   s1.rysuj();
//  s2.rysuj();
//   a.rysuj();
//    usleep(100000);
//  }
//  }
//  };


 

