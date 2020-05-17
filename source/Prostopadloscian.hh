#include "Bryla.hh"

class Prostopadloscian : public Bryla
{

public:
  
    Prostopadloscian(double x, double y, double z,std::shared_ptr<drawNS::Draw3DAPI> &api):Bryla(api)
    {
        kat=0;
        krzywa.resize(2);
        kop_krzywa.resize(2);
        for (int i = 0; i < krzywa.size(); i++){
            krzywa[i].resize(4);
               kop_krzywa[i].resize(4);
        }
        for (int i = 0; i < krzywa.size(); i++)
            for (int j = 0; j < krzywa.at(i).size(); j++)
            {
                krzywa[i][j][0] -= x / 2;
                krzywa[i][j][1] -= y / 2;
                krzywa[i][j][2] -= y / 2;
            }
        //////////////////////////////
      

        krzywa[0][1][1] += y;

        krzywa[0][2][1] += y;
        krzywa[0][2][2] += z;


        krzywa[0][3][2] += z;
      
/////////////////////////////////////////////////
  
  krzywa[1][0][0] += x;

    krzywa[1][1][0] += x;
        krzywa[1][1][1] += y;
        krzywa[1][2][0] += x;
        krzywa[1][2][1] += y;
        krzywa[1][2][2] += z;

        krzywa[1][3][0] += x;
        krzywa[1][3][2] += z;
        /////////////////////////////////
    }
};