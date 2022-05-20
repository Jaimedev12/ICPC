#include <iostream>
#include <vector>

using namespace std;

int main() {

  float g = 9.81;
  int T, L, W, H, volume;
  double upForce, downForce, netForce;

  vector<double> volumes, forces; 

  while (scanf("%d", &T)){

    if (T == 0){
      break;
    }

    volumes.clear();
    forces.clear();
    
    for (int i = 0; i < T; i++){
      scanf("%d %d %d", &L, &W, &H);
    
      //upForce = (L * W * g) / 2; 
      downForce = g - (g / (2 * H));
      //netForce = downForce - upForce;

      volume = L * W * H;

      /*
      cout << "upF: " << upForce << endl;
      cout << "downF: " << downForce << endl;
      cout << "netF: " << netForce << endl << endl;
      */

      volumes.push_back(volume);
      forces.push_back(downForce);
    
    }

    int index = 0; 
    double fuerzaMayor = 0, volumenMayor = 0;

    for (int i = 0; i < forces.size(); i++){

      if (forces[i] == fuerzaMayor){
        if (volumes[i] > volumenMayor){
          fuerzaMayor = forces[i];
          volumenMayor = volumes[i];
          index = i;
          continue;
        }
      }
      
      if (forces[i] > fuerzaMayor){
        fuerzaMayor = forces[i];
        volumenMayor = volumes[i];
        index = i;
        //cout << "mayor: " << mayor << endl;
      }
    }

    //cout << index << endl;
    cout << volumenMayor << endl;

    /*
    for (int i = 0; i < volumes.size(); i++){
      cout << volumes[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < forces.size(); i++){
      cout << forces[i] << " ";
    }
    */

  }
}