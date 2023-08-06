/* Menținerea specificatorului de acces “public” este o potențială breșă de securitate. Pentru a asigura ascunderea datelor, cele 3 date membre ale clasei Cutie vor avea specificatorul de acces “private”.
Pentru clasa Cutie se vor scrie o serie de funcții care modifică (setter), respectiv accesează (getter) valorile datelor membre. În programul principal se va instanția un obiect de tipul Cutie, se vor citi de la tastatură 
cele 3 atribute și se vor asigna obiectului respectiv cu ajutorul funcțiilor setter. Ulterior, se vor afișa pe ecran cu ajutorul funcțiilor getter în ordinea precizată, fiecare pe un rând nou. */


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
        
    
};

//Functia main
int main(){
    
    //Initializam Obiect
    Cutie c;
    
    //Initializam Date
    float c_lungime;
    float c_latime;
    float c_inaltime;
    
    //Citim Date
    std::cin>>c_lungime;
    std::cin>>c_latime;
    std::cin>>c_inaltime;
    
    //Stabilim valori cu Setter
    c.set_lungime(c_lungime);
    c.set_latime(c_latime);
    c.set_inaltime(c_inaltime);
    
    //Afisam valori cu Getter
    std::cout<<c.get_lungime()<<'\n';
    std::cout<<c.get_latime()<<'\n';
    std::cout<<c.get_inaltime()<<'\n';
    
    
    return 0;
        
}
