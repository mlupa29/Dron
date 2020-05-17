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
        for (int i = -20; i <= 20; i+=5)
        {
            krzywa.resize(krzywa.size()+1);
            kop_krzywa.resize(krzywa.size()+1);
                 k=0;
            for (int j = -20; j <= 20; j+=5)
            {
                kop_krzywa[m].resize(krzywa[m].size()+1);
                krzywa[m].resize(krzywa[m].size()+1);
                kop_krzywa[m][k][0] = i;
                kop_krzywa[m][k][1] = j;
                kop_krzywa[m][k][2] = -20;
                k++;
            }
            m++;
        }

    }
};