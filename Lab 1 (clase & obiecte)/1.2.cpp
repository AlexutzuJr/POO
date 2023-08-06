/* Scrieți o clasă Cutie cu 3 date membre publice: lungime, lățime, înălțime, de tip real și o funcție membră care întoarce volumul cutiei.

Definiți o funcție membră care calculează volumul rămas în cutia inițială dacă în ea se va introduce o altă cutie transmisă ca argument în funcție. Se va verifica, mai întâi, dacă cea de-a doua cutie poate fi introdusă 
în prima cutie (considerăm că cele 3 dimensiuni respectă aceeași ordine și nu putem roti nicio cutie). În caz contrar, se va afișa volumul cutiei inițiale.

În programul principal se va instanția un obiect de tipul Cutie, se vor citi de la tastatură cele 3 atribute și se va citi o comandă, în funcție de valoarea căreia se vor executa diferite acțiuni:
1. Se afișează pe ecran volumul cutiei.
2. Se instanțiază o a doua cutie, se citesc de la tastatură cele 3 atribute și se afișează pe ecran volumul rămas liber în prima cutie după introducerea celei de-a doua cutii (dacă este posibil). */ 


#include <iostream>
#include <string>


//Clasa
class Cutie{
    
    //Date membre
    private:
        float lungime;
        float latime;
        float inaltime;
        
    //Setters si Getters
    public:
        
        void set_lungime(float lungime){
            this->lungime = lungime;
        }
        
        float get_lungime(){
            return this->lungime;
        }
        
        void set_latime(float latime){
            this->latime = latime;
        }
        
        float get_latime(){
            return this->latime;
        }
        
        void set_inaltime(float inaltime){
            this->inaltime = inaltime;
        }
        
        float get_inaltime(){
            return this->inaltime;
        }
    
    
    //Constructor
    public:
        Cutie(float lungime, float latime, float inaltime){
            this->lungime = lungime;
            this->latime = latime;
            this->inaltime = inaltime;
        }
    
    
    //Funcctii
    public:
    
        //Functia de afisare
        void afisare(){
            
            std::cout << lungime << std::endl;
            std::cout << latime << std::endl;
            std::cout << inaltime << std::endl;
            
            
        }
        
        
        //Functie calculare Volum
        float volum(){
            return this->lungime*this->latime*this->inaltime;
        }
        
        
        //Functia pentru calculare Diferente Volum Cutii
        float diferenta_volum(Cutie c){
            if((this->lungime >= c.lungime) && (this->latime >= c.latime) && (this->inaltime >= c.inaltime))
                return this->volum() - c.volum();
            else
                return this->volum();
        }
    
};


//Functia main
int main(){
    //Initializare date
    int optiune;
    //Cutie 1
    float c1_lungime;
    float c1_latime;
    float c1_inaltime;
    //Cutie 2
    float c2_lungime;
    float c2_latime;
    float c2_inaltime;

    std::cin>>c1_lungime;
    std::cin>>c1_latime;
    std::cin>>c1_inaltime;
    
    std::cin>>optiune;

    Cutie c1(c1_lungime, c1_latime, c1_inaltime);
    
    if(optiune == 1){
        //Calculare Volum
        std::cout << c1.volum() << std::endl;        
    }
    if(optiune == 2){
        //Cutie 2
        std::cin>>c2_lungime;
        std::cin>>c2_latime;
        std::cin>>c2_inaltime;
    
        //Calculare Diferenta Volum Cutii
        Cutie c2(c2_lungime, c2_latime, c2_inaltime);
        std::cout << c1.diferenta_volum(c2) << std::endl; 
        
    }

    
}
