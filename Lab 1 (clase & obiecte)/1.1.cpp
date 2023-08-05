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
        
    //Functii    
    public:

    
        //Functia de afisare
        void afisare(){
            
            std::cout << lungime << std::endl;
            std::cout << latime << std::endl;
            std::cout << inaltime << std::endl;
            
            
        }
    
    
};


//Functia main

int main(){
    
    //Initializare date
    float c_lungime;
    float c_latime;
    float c_inaltime;
    
    std::cin>>c_lungime;
    std::cin>>c_latime;
    std::cin>>c_inaltime;
    
    
    //Initializare Clasa
    Cutie c(c_lungime, c_latime, c_inaltime);

    c.afisare();
    
    return 0;
    
    
}
