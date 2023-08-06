/* Pentru clasa Punctaj se va defini un destructor, un constructor de copiere și o funcție membră care modifică nota de la un index dat. Se va instanția un obiect de tip Punctaj folosind constructorul cu 2 parametri, se va 
crea o nouă instanță prin copierea acestuia, se va modifica nota de la un anumit index cu o nouă valoare citită de la tastatură, după care se vor afișa pe ecran notele celui de-al doilea obiect.
Se va apela în mod explicit destructorul primului obiect, după care se vor afișa din nou pe ecran notele celui de-al doilea obiect.
Comentați constructorul de copiere și repetați pașii de mai sus. */

#include <iostream>


class Punctaj{
    
    //Date membre
    private:
        int nr_note;
        int *note;
       
    
    //Constructori
    public:   
    
        //Constructor
        Punctaj(int nr_note, int *note){
            this->nr_note = nr_note;
            this->note = new int[nr_note];
            for(int i=0; i<nr_note; i++){
                *(this->note+i) = *(note+i);
            }
        }
        
        //Destructor
        ~Punctaj(){
            delete [] note;
        }
        
        //Constructor de Copiere
        Punctaj(const Punctaj &p){
            this->nr_note = p.nr_note;
            this->note = new int[this->nr_note];
            for(int i=0; i<nr_note; i++){
                *(this->note+i) = *(p.note+i);
            }
        }
    
    //Functii
    public:
    
        //Aifsare
        void afisare(){
            for(int i=0; i<nr_note; i++){
                std::cout << *(note+i) << " ";
            }
        }
        
        //Incrementare
        void schimb(int index){
            
            for(int i=0; i<nr_note; i++){
                
                if(i == index){
                    
                    std::cin >> *(note+i);
                }
            }
        }
   
};

//Functia main
int main(){
    
    //Initializare Date
    int nr_note;
    std::cin >> nr_note;
    
    int *note = new int[nr_note];
    for(int i=0; i<nr_note;i++){
        std::cin >> *(note+i);
    }
    
    
    //Initializare Obiecte
    Punctaj p1(nr_note, note);
    Punctaj p2(p1);
    
    p1.afisare();
    
    std::cout<<std::endl;
    p2.schimb(2);
    
    p2.afisare();
    
    return 0;
}

// Apelul explicit pentru destructorul obiectului p din clasa Punctaj 
// (coincide cu apelul oricarei alte functii membre):
// p.~Punctaj();
