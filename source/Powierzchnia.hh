#include "Plaszczyzna.hh"


class Powierzchnia : public Plaszczyzna
{
/*!
* \brief konstruktor dla klasy powierzchnia

*/
public:
    Powierzchnia(std::shared_ptr<drawNS::Draw3DAPI> &api):Plaszczyzna(api)
    {
      
   
    
        int k=0,m=0;
        for (int i = -60; i <= 60; i+=10)//20
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
                if(k%2==0)
                kop_krzywa[m][k][2] = 30;
                else
                kop_krzywa[m][k][2] =35;
                k++;
            }
            m++;
        }

    }

    ~Powierzchnia(){};
};