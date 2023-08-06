/* Să se scrie un program care ordonează o secvență de maxim 20 de numere complexe.
Se va citi de la tastatură un număr întreg reprezentând numărul de numere complexe ce urmează a fi citit. Ulterior, de pe fiecare linie se citesc 2 valori reale, reprezentând partea reală, respectiv partea imaginară, separate
de un spațiu.
Să se afișeze pe ecran numerele complexe ordonate, câte unul pe linie. Afișarea unui număr complex se face sub forma "<partea_reala> <partea_imaginara>". */

#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>



//Clasa de Baza
class Complex{
    
    //Date membre
    private:
        float re;
        float im;
        float mod;
        
    //Constructor
    public:
        Complex(){}
        
        Complex(float re, float im): re(re), im(im){}
        
    //Functii
    public:
        void afisare(){
            std::cout<<re<<" "<<im<<std::endl;
            
        }
        
        
        void calcul(){
            mod=0;
            mod=re*re+im*im;
            mod=sqrt(mod);
        }
        
        float get_mod(){
            return mod;
        }
};


bool compara(Complex c1, Complex c2){
    return (c1.get_mod() < c2.get_mod());
}



//Functia main
int main(){
    
    int numar_numere;
    float re;
    float im;
    
    std::cin>>numar_numere;
    
    std::vector<Complex> numere;
    
    for(int i=0; i<numar_numere; i++){
        
        std::cin>>re;
        std::cin>>im;
        numere.push_back(Complex(re,im));
        numere[i].calcul();
    }
    
    
    std::sort(numere.begin(), numere.end(), compara);
    
    for(int i=0; i<numar_numere; i++){
        numere[i].afisare();
    }
    
    
    
    
    
    return 0;
}
