/* Să se scrie o clasă Carte cu următoarele date membre: titlu, nume_autor, an_lansare, nr_pagini, pret. Se vor instanția obiecte din această clasă folosind un vector cu alocare dinamică de memorie. Se citește de la tastatură 
numărul de cărți pe care dorim să îl folosim. Ulterior, pentru fiecare carte se vor citi, de pe rânduri diferite datele membre în ordinea enunțată mai sus.
Se va citi o comandă de la tastatură. În funcție de valoarea acesteia se vor executa diferite acțiuni:
Se citește de la tastatură un nume de autor. Se afișează titlurile tuturor cărților scrise de acest autor, separate de virgulă și spațiu. Pentru simplitate, ultimul titlu va fi, de asemenea, urmat de virgulă și spațiu.
Se va afișa cartea cu numărul minim de pagini. 
Se va afișa cartea cel mai recent lansată. 
Prin afișarea cărții se înțelege afișarea tuturor datelor membre ale cărții, fiecare pe un rând nou. */

#include <iostream>
#include <string>

//Clasa
class Carte{
    
    //Date membre
    private:
        std::string titlu;
        std::string nume_autor;
        int an_lansare;
        int nr_pagini;
        int pret;
        
    //Constructori
    public:
        //Gol
        Carte(){
            this->titlu = " ";
            this->nume_autor = " ";
            this->an_lansare = 0;
            this->nr_pagini = 0;
            this->pret = 0;
            
        }
        
        //Cu elemente
        Carte(std::string titlu, std::string nume_autor, int an_lansare, int nr_pagini, int pret){
            this->titlu = titlu;
            this->nume_autor = nume_autor;
            this->an_lansare = an_lansare;
            this->nr_pagini = nr_pagini;
            this->pret = pret;
            
            
        }
        
    //Setters si Getters
    public:    
        void set_titlu(std::string titlu){
            this->titlu = titlu;
        }
        std::string get_titlu(){
            return this->titlu;
        }
        
        void set_nume_autor(std::string nume_autor){
            this->nume_autor = nume_autor;
        }
        std::string get_nume_autor(){
            return this->nume_autor;
        }
        
        void set_an_lansare(int an_lansare){
            this->an_lansare = an_lansare;
        }
        int get_an_lansare(){
            return this->an_lansare;
        }
        
        void set_nr_pagini(int nr_pagini){
            this->nr_pagini = nr_pagini;
        }
        int get_nr_pagini(){
            return this->nr_pagini;
        }
        
        void set_pret(int pret){
            this->pret = pret;
        }
        int get_pret(){
            return this->pret;
        }
    
    //Functii
    public:
        void afisare(){
            std::cout << titlu << std::endl;
            std::cout << nume_autor << std::endl;
            std::cout << an_lansare << std::endl;
            std::cout << nr_pagini << std::endl;
            std::cout << pret << std::endl;
            
            
        }
};



//Functia main
int main(){
    
    //Initializare Date
    int nr_obiecte;
    int optiune;
    
    std::string c_titlu;
    std::string c_nume_autor;
    int c_an_lansare;
    int c_nr_pagini;
    int c_pret;
    
    //Citim Date
    std::cin>>nr_obiecte;
    
    //Alocare Dinamica Vector
    Carte **carte_array = nullptr;
    carte_array = new Carte*[nr_obiecte];
    
    
    //Facem Obiectele
    for (int i=0; i<nr_obiecte; i++){
        std::cin.ignore(1000, '\n');
        std::getline(std::cin, c_titlu);
        std::getline(std::cin, c_nume_autor);
        std::cin>>c_an_lansare;
        std::cin>>c_nr_pagini;
        std::cin>>c_pret;
    
        *(carte_array + i) = new Carte(c_titlu, c_nume_autor, c_an_lansare, c_nr_pagini, c_pret);
        
        
    }
    
    std::cin>>optiune;
    
    
    //Optiunea 1
    if(optiune == 1){
        
        //Initializam Numele
        std::string nume_1;
        std::cin.ignore(1000, '\n');
        std::getline(std::cin, nume_1);
        
        std::cout<<nume_1<<"\n";
        
        for (int i=0; i<nr_obiecte; i++){
            
            if(nume_1 == (*(carte_array + i))->get_nume_autor())
                std::cout<<(*(carte_array + i))->get_titlu()<<", ";
        }
    }
    
    
    //Optiunea 2
    if(optiune == 2){
        
        int minim_2 = (*(carte_array + 0))->get_nr_pagini(); //Numarul minim de pagini
        
        //Aflam minimul
        for (int i=0; i<nr_obiecte; i++){
            
            if(minim_2 > (*(carte_array + i))->get_nr_pagini())
                minim_2 = (*(carte_array + i))->get_nr_pagini();
        }
        
        //Cautam egalul si afisam
        for (int i=0; i<nr_obiecte; i++){
            if(minim_2 == (*(carte_array + i))->get_nr_pagini())
                (*(carte_array + i))->afisare();
        } 
        
    }
    
    
    
    //Optiunea 3
    if(optiune == 3){
        
        int an_3 = (*(carte_array + 0))->get_an_lansare(); //Numarul minim de pagini
        
        //Aflam maximul (anul cel mai mare este cel mai recent)
        for (int i=0; i<nr_obiecte; i++){
            
            if(an_3 < (*(carte_array + i))->get_an_lansare())
                an_3 = (*(carte_array + i))->get_an_lansare();
        }
        
        //Cautam egalul si afisam
        for (int i=0; i<nr_obiecte; i++){
            if(an_3 == (*(carte_array + i))->get_an_lansare())
                (*(carte_array + i))->afisare();
        } 
        
    }
        
        

    //Destructor Obiecte
    for (int i=0; i<nr_obiecte; i++){
        delete *(carte_array + i);
    }
    
    
   return 0;
   
}
