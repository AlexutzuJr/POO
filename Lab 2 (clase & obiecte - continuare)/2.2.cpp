/* Să se scrie două clase distincte, Părinte și Copil. Clasa Copil va conține datele membre vârstă și nume și va declara (toată) clasa Părinte drept prietenă. Clasa Părinte va conține o funcție membră care îi permite să 
modifice numele Copilului doar dacă acesta din urmă are vârsta <18 ani, iar Copilul conține o funcție membră care îi permite să își modifice numele doar dacă are >=18 ani. Toate inițializările din constructori vor fi 
făcute cu ajutorul listei de inițializare.
În programul principal se vor citi de la tastatură, de pe linii diferite, următoarele date:
1. un întreg m, reprezentând vârsta Copilului;
2. un șir de caractere s, reprezentând numele Copilului (șirul de caractere poate fi format din mai mult de un cuvânt);
3. un șir de caractere new_s, reprezentând noul nume al Copilului (șirul de caractere poate fi format din mai mult de un cuvânt);
4. un întreg x, reprezentând persoana care va solicita schimbarea: 0 - Părintele; 1 - Copilul.

Se va afișa pe ecran noul nume al Copilului, sau “EROARE” în cazul în care persoana desemnată să modifice numele nu are permisiunea să facă acest lucru, conform regulii enunțate mai sus.
Extensie: separați declarațiile claselor și definițiile funcțiilor membre în fișiere diferite. Notă: trebuie avute în vedere declarația în avans a clasei care este accesată de o altă clasă. */


#include <iostream>
#include <limits>
#include <string>



//Clasa
class Parinte;


class Copil{
    
    friend class Parinte;
    
    //Date membre
    private:
        int varsta;
        std::string nume;
    
    //Constructor
    public:
        Copil(int varsta=0, std::string nume=" "): varsta(varsta), nume(nume){}
    
    //Functii
    public:
        void modifica_copil(int m, std::string new_s){
            if(m >= 18){
                nume = new_s;
                std::cout<<nume<< std::endl;
            }
            
            else
                std::cout<<"EROARE"<<std::endl;
            
            
        }
    
};


class Parinte{
    
    //Declaram obiectul copil pentru a folosi elementele din clasa Copil
    Copil obiect_copil;
    
    //Functii
    public:
        void modifica_parinte(int m, std::string new_s){
            if(m < 18){
                obiect_copil.nume = new_s;
                std::cout<<obiect_copil.nume<< std::endl;
            }
            
            else
                std::cout<<"EROARE"<<std::endl;
        }
    
};


int main(){
    
    //Initializam Date
    int m;                      //varsta copil
    std::string s;              //nume copil
    std::string new_s;          //nume nou copil
    int x;                      //persoana care solicita
    
    //Citim Date
    std::cin>>m;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, s);
    std::getline(std::cin, new_s);
  
    
    std::cin>>x;
    
    //Initializare Obiecte
    Copil c(m, s);              //Are 2 elemente
    Parinte p;                  //Nu are elemente
 
    //Conditie Parinte
    if(x == 0){
        p.modifica_parinte(m, new_s);
    }
    
    if(x == 1){
        c.modifica_copil(m, new_s);
    }
    
    return 0;
}
