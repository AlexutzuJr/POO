#include <iostream>
#include <string>
#include <limits>

//Clasa de Baza
class Vehicul{
    
    //Date membre
    private:
        std::string nume;
        float pret;
        float greutate;
        
    //Constructor
    public:
        
        //Constructor Gol
        Vehicul(){}
        
        //Constructor cu Lista de Initializare
        Vehicul(std::string nume, float pret, float greutate):nume(nume),pret(pret),greutate(greutate){}
        
        
    //Setters si Getters
    public:
        void set_nume(std::string nume){this->nume=nume;}
        std::string get_nume(){return this->nume;}
        
        void set_pret(float pret){this->pret=pret;}
        float get_pret(){return this->pret;}
        
        void set_greutate(float greutate){this->greutate=greutate;}
        float get_greutate(){return this->greutate;}
    
        
    //Functii
    public:
        void afisare_vehicul(){
            std::cout<<"nume: "<<nume<<std::endl;
            std::cout<<"pret: "<<pret<<std::endl;
            std::cout<<"greutate: "<<greutate<<std::endl;
        }
        
};

//Clasa Derivata
class AutoVehicul:public Vehicul{
    
    //Date membre
    private:
        int putere;


    //Constructor
    public:
    
        //Constructor Gol
        AutoVehicul(){}
        
        
        //Constructor cu Lista de Initializare
         AutoVehicul(std::string nume, float pret, float greutate, int putere):Vehicul(nume,pret,greutate), putere(putere){}
         
         
    //Functii
    public:
        void afisare_autovehicul(){
            Vehicul::afisare_vehicul();
            std::cout<<"putere: "<<putere<<std::endl;
        }
};


//Functia main
int main(){
    
    
    //Initializam Date
    std::string nume_vehicul;
    float pret_vehicul;
    float greutate_vehicul;
    
    std::string nume_autovehicul;
    float pret_autovehicul;
    float greutate_autovehicul;
    int putere_autovehicul;
    
    //Citim Date
    std::cin>>nume_vehicul;
    std::cin>>pret_vehicul;
    std::cin>>greutate_vehicul;
    
    std::cin>>nume_autovehicul;
    std::cin>>pret_autovehicul;
    std::cin>>greutate_autovehicul;
    std::cin>>putere_autovehicul;

    
    //Initializam Obiect
    Vehicul v(nume_vehicul,pret_vehicul,greutate_vehicul);
    AutoVehicul a(nume_autovehicul, pret_autovehicul, greutate_autovehicul, putere_autovehicul);
    
    //Afisam Obiectele
    v.afisare_vehicul();
    a.afisare_autovehicul();
    return 0;
}
