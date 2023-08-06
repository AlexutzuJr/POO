/* Atunci când se definește un constructor cu parametri, constructorul implicit este suprimat și trebuie definit în mod explicit sau încorporat într-un constructor cu parametri sub forma unui constructor cu argumente 
implicite.

Pentru clasa Pisica cu datele membre nume, vârstă, greutate să se scrie toți constructorii cu parametri posibili. Toate valorile numerice implicite vor fi egale cu 0, iar șirurile de caractere implicite nu vor conține 
niciun caracter. În programul principal se vor instanția mai întâi un obiect cu niciun parametru, apoi cu un parametru, cu doi parametri, respectiv 3 parametri - parametrii vor fi transmiși în ordinea menționată anterior,
fiecare dintre ei fiind citit de pe un rând nou. Pentru fiecare obiect menționat se vor afișa toate datele membre, în ordinea menționată, separate de un spațiu. După fiecare set de date membre aparținând unui obiect se 
va trece pe următorul rând (caracterul newline). */


#include <iostream>
#include <limits>
#include <string>


//Clasa
class Pisica{
    
    //Date membre
    private:
        std::string nume;
        int varsta;
        float greutate;
        
    
    //Constructori
    public:
        //0 parametri
        Pisica(){
            this->nume = "";
            this->varsta = 0;
            this->greutate = 0;
        
        }
    
        //1 parametru
        Pisica(std::string nume){
            this->nume = nume;
            this->varsta = 0;
            this->greutate = 0;
        
        }
    
        //2 parametri
        Pisica(std::string nume, int varsta){
            this->nume = nume;
            this->varsta = varsta;
            this->greutate = 0;
        
        }
    
        //3 parametri
        Pisica(std::string nume, int varsta, float greutate){
            this->nume = nume;
            this->varsta = varsta;
            this->greutate = greutate;
        
        }
    
    
    
    //Functii
    public:
        void afisare(){
            std::cout << nume << " ";
            std::cout << varsta << " ";
            std::cout << greutate << std::endl;
        }
    
    
};


//Functia main
int main(){
    
    //Initializam Date
    std::string b_nume;
    std::string c_nume;
    int c_varsta;
    std::string d_nume;
    int d_varsta;
    float d_greutate;
    
    //Citim Date
    std::getline(std::cin, b_nume);
    
    std::getline(std::cin, c_nume);
    std::cin>>c_varsta;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //CONDITIE PENTRU CUVINTE CU SPATIU
    std::getline(std::cin, d_nume);
    std::cin>>d_varsta;
    std::cin>>d_greutate;


    //Constructori Parametrizati
    
    //0 parametri
    Pisica a;
    a.afisare();
    
    //1 parametru
    Pisica b(b_nume);
    b.afisare();
    
    //2 parametrii
    Pisica c(c_nume, c_varsta);
    c.afisare();
    
    //3 parametrii
    Pisica d(d_nume, d_varsta, d_greutate);
    d.afisare();
    
    
    
    return 0;
    
}
