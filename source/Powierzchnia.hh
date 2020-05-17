#include "Plaszczyzna.hh"


class Powierzchnia : public Plaszczyzna
{

public:
    Powierzchnia(std::shared_ptr<drawNS::Draw3DAPI> &api):Plaszczyzna(api)
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
                if(k%2==0)
                kop_krzywa[m][k][2] = 30;
                else
                kop_krzywa[m][k][2] =35;
                k++;
            }
            m++;
        }

    }
};