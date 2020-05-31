#ifndef PPRZESZKODA_HH
#define PPRZESZKODA_HH


#include "Przeszkoda.hh"

#include "Prostopadloscian.hh"

class P_Prostopadloscian :public Prostopadloscian , public Przeszkoda
{


public:

P_Prostopadloscian(double x,double y,double z,std::shared_ptr<drawNS::Draw3DAPI> &api):Prostopadloscian(x,y,z,api)
{


}
bool czy_kolizja(Wektor3D srodek,double promien_drona,double przesuniecie){
if(sqrt(pow((get_srodek()[0]-srodek[0]),2)+pow((get_srodek()[1]-srodek[1]),2)+pow((get_srodek()[2]-srodek[2]),2)) <promien_drona+przesuniecie+this->promien() )
{

  cout<<"Kolizja"<<endl;
  return true;
}
else{
  cout<<"."<<endl;
  return false;
}

}




};







#endif


