
//     #include "Graniastoslup.hh"
    
//     Granaistoslup::Granaistoslup(double x, double y, double z,std::shared_ptr<drawNS::Draw3DAPI> &api):Bryla(api)
//     {
//         kat=0;
//         kat_sm=0;
//         krzywa.resize(2);
//         kop_krzywa.resize(2);
//         for (int i = 0; i < krzywa.size(); i++){
//             krzywa[i].resize(6);
//                kop_krzywa[i].resize(6);
//         }
//         for (int i = 0; i < krzywa.size(); i++)
//             for (int j = 0; j < krzywa.at(i).size(); j++)
//             {
//                 krzywa[i][j][0] -= x / 2;
//                 krzywa[i][j][1] -= y / 2;
//                 krzywa[i][j][2] -= z / 2;
//             }
      

//         krzywa[0][1][1] += y;

//         krzywa[0][2][1] += y+y/2;
//         krzywa[0][2][2] += z/2;

//         krzywa[0][3][1] += y;
//         krzywa[0][3][2] += z;
      
     
//         krzywa[0][4][2] += z;

//          krzywa[0][5][1] -= y/2;
//         krzywa[0][5][2] += z/2;


  

// krzywa[1][0][0] += x;
// krzywa[1][1][0] += x;
//           krzywa[1][1][1] += y;

// krzywa[1][2][0] += x;
//         krzywa[1][2][1] += y+y/2;;
//         krzywa[1][2][2] += z/2;

// krzywa[1][3][0] += x;
//         krzywa[1][3][1] += y;
//         krzywa[1][3][2] += z;
      
//      krzywa[1][4][0] += x;
//         krzywa[1][4][2] += z;

// krzywa[1][5][0] += x;
//          krzywa[1][5][1] -= y/2;
//         krzywa[1][5][2] += z/2;

//     }

//     void Granaistoslup::przesun(Wektor3D przesuniecie) 
//     {
      
//         przes=(przesuniecie);
//         for(uint i=0; i<krzywa.size(); i++)
//         {
//             for(uint j=0; j<krzywa.at(i).size(); j++)
//             {
//                 kop_krzywa[i][j]=(krzywa[i][j])+przes;
//             } 
//         }

//     }
