#include "Plaszczyzna.hh"
using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;


    void Plaszczyzna::rysuj()
    {  
       
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
          
 id=api->draw_surface(proste,"blue");   
 id=api->draw_surface(proste,"blue");
  id=api->draw_surface(proste,"blue");
    }



