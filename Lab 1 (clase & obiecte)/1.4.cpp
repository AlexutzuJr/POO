/* Pentru a evita utilizarea a 3 funcții diferite pentru inițializarea datelor membre ale unui obiect din clasa Cutie, se va crea un constructor ce primește 3 argumente, în această ordine: lungime, lățime, înălțime. 
În programul principal se vor citi de la tastatură cele 3 atribute și se va instanția un obiect cu ajutorul lor. Ulterior, se vor afișa pe ecran atributele respective în ordinea precizată, fiecare pe un rând nou. */

#include <iostream>
#include <string>

//Clasa
class Cutie{
    
    //Date membre
    private:
        float lungime;
        float latime;
        float inaltime;
        
        
    //Constructor
    public:
        Cutie(float lungime, float latime, float inaltime){
            this->lungime = lungime;
            this->latime = latime;
            this->inaltime = inaltime;
        }
    
    //Functii
    public:
        void afisare(){
            std::cout << lungime << std::endl;
            std::cout << latime << std::endl;
            std::cout << inaltime << std::endl;
        }
        
    
};

//Functia main
int main(){
    

    //Initializam Date
    float c_lungime;
    float c_latime;
    float c_inaltime;
    
    //Citim Date
    std::cin>>c_lungime;
    std::cin>>c_latime;
    std::cin>>c_inaltime;
    
    //Initializare Obiect
    Cutie c(c_lungime, c_latime, c_inaltime);
    
    //Afisam
    c.afisare();
    
    return 0;
        
}
