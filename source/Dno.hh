#include "Plaszczyzna.hh"


class Dno : public Plaszczyzna
{
/*!
* \brief konstruktor dla klasy dno

*/
public:
    Dno(std::shared_ptr<drawNS::Draw3DAPI> &api):Plaszczyzna(api)
    {
      
   
    
        int k=0,m=0;
        for (int i = -60; i <= 60; i+=10)
        {
            krzywa.resize(krzywa.size()+1);
            kop_krzywa.resize(krzywa.size()+1);
                 k=0;
            for (int j = -60; j <= 60; j+=10)
            {
                kop_krzywa[m].resize(krzywa[m].size()+1);
                krzywa[m].resize(krzywa[m].size()+1);
                kop_krzywa[m][k][0] = i;
                kop_krzywa[m][k][1] = j;
                kop_krzywa[m][k][2] = -40;
                k++;
            }
            m++;
        }

    }
};