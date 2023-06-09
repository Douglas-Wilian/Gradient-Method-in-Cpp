#include <iostream>
#include <cmath>

using namespace std;


int main(){
double x[2], pd[2]={0}, pd2[2] = {0}, r0[2]={0}, save[2] ={0};
double A[2][2] = {{4,1}, {1,3}};
double b[2] = {5,4}, norma[2] ={0};
double alpha=0, verify=0, prec =0;
int n;

cout << "Digite o chute inicial\n";
 
  for(int i=0; i<2; i++){
        cin >> x[i];
    }

cout << "Digite o numero de iteracoes\n";
cin >> n;

cout << "Digite a precisao\n";
cin >> prec;

for(int k=0; k<n; k++){

double numerador=0, denominador = 0;
    for(int i=0; i<2; i++){
        save[i] = x[i];
        pd[i] = 0;
        pd2[i] = 0;
    }

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            pd[i] = pd[i] + (A[i][j]*x[j]);
        }
    }

    for(int i=0; i<2; i++){
        r0[i] = b[i] - pd[i];
    }


    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            pd2[i] = pd2[i] + (A[i][j]*r0[j]);
        }
    }

    for(int i=0; i<2; i++){
        numerador = numerador + r0[i]*r0[i];
        denominador = denominador + r0[i]*pd2[i];
    }

    alpha = numerador/denominador;

    for(int i=0; i<2; i++){
        x[i] = x[i] + alpha*r0[i];
        cout << x[i] << endl;
    }
    for(int j=0; j<2; j++){
        norma[j] = x[j] - save[j];
        verify = verify + pow(norma[j], 2);
    }
    if(sqrt(verify) <= prec){
        cout << "A SOLUCAO E:\n";
        for(int i=0; i<2; i++){
            cout << "x[" << i << "] = " << x[i] << endl;
        }
        break;
    }else{
        verify =0;
    }
}

if(verify ==0){
    cout << "AS RAIZES SAO:\n";
    for(int i=0; i<2; i++){
        cout << "x[" << i << "] = " << x[i] << endl;
    }
}

return 0;   
}