/* Să se implementeze următoarea secvență UML:

Echipament_electronic:
#tensiune: float
#intensitate: float

Telefon (private to Echipament_electronic):
#nr_tel: std::string
+suna(std::string): void

Telefon_mobil (protected to Telefon):
-baterie: int
+suna(std::string, int): void

Se va instanția un obiect din clasa Telefon_mobil cu următoarele date, citite de la tastatură, de pe rânduri diferite:
1. o valoare reală, reprezentând tensiunea;
2. o valoare reală, reprezentând intensitatea;
3. un șir de caractere, reprezentând numărul de telefon;
4. un număr întreg, reprezentând procentul de baterie disponibil;

Separat, se vor mai citi următoarele date, de pe linii diferite, pentru a utiliza funcția suna:
5. un șir de caractere, reprezentând numărul apelat;
6. un număr întreg, reprezentând durata apelului, exprimată în minute.

Funcția suna din clasa Telefon primește ca argument un șir de caractere și afișează mesajul "Calling: <numar de telefon transmis ca argument>". Funcția suna din clasa Telefon_mobil primește un argument în plus reprezentând 
durata apelului în minute și afișează mesajul "Outgoing number: <numar de telefon propriu>", urmat de mesajul funcției cu același nume din clasa Telefon, și reduce bateria direct proporțional cu puterea consumată de 
dispozitivul electronic. Bateria scade cu <putere>/100 pentru fiecare minut de conversație.

În programul principal se apelează funcția suna cu argumentele citite de la tastatură și se afișează pe ecran, pe un rând separat, procentul de baterie rămas disponibil, după efectuarea apelului. */

#include <iostream>
#include <string>
#include <limits>


//Clasa de Baza
class Echipament_electronic{
    
    //Date membre
    protected:
        float tensiune;
        float intensitate;
    
    //Constructor
    public:
        
        //Constructor Gol
        Echipament_electronic(){}
        
        //Constructor cu Lista de Initializare
        Echipament_electronic(float tensiune, float intensitate): tensiune(tensiune), intensitate(intensitate){}
    
    

};

//Daca este PROTECTED in cea de BAZA este PRIVATE in derivata 

//Clasa Derivata
class Telefon:private Echipament_electronic{
    
    //Date membre
    protected:
        std::string nr_tel;
        
    //Constructor
    public:
        
        //Constructor Gol
        Telefon(){}
        
        //Constructor cu Lista de Initializare
        Telefon(float tensiune, float intensitate, std::string nr_tel):Echipament_electronic(tensiune, intensitate), nr_tel(nr_tel){}
    
    //Functii
    public:
    
        //Functie cu parametru din main
        void suna(std::string nr_apelat){
            
            std::cout<<"Calling: "<<nr_apelat<<std::endl;

        }
    
    //Getteri
    float get_tensiune(){return this->tensiune;}
    float get_intensitate(){return this->intensitate;}
    
};


//Clasa Derivata din Prima Derivata
class Telefon_mobil:protected Telefon{
    
    //Date membre
    private:
        int baterie;
    
    //Constructor
    public:
        
        //Constructor Gol
        Telefon_mobil(){}
        
        //Constructor cu Lista de Initializare
        Telefon_mobil(float tensiune, float intensitate, std::string nr_tel, int baterie):Telefon(tensiune, intensitate, nr_tel), baterie(baterie){}
    
    
    //Functii
    public:
    
        //Functie cu parametru din main
        void suna(std::string nr_apelat, int minute){
            
            Telefon::suna(nr_apelat);
            std::cout<<"Outgoing number: "<<nr_tel<<std::endl;
            
            
            //Baterie ramasa
            int baterie_ramasa = baterie-((Telefon::get_tensiune()*Telefon::get_intensitate())/100)*minute;
            
            if(baterie_ramasa>0){
                std::cout<<baterie_ramasa<<std::endl;
            }
            else{
                std::cout<<"0"<<std::endl;
            }
            
                
        }
        
};


//Functia main
int main(){
    
    //Initializam Date
    float tensiune;
    float intensitate;
    std::string nr_tel;
    int baterie;
    std::string nr_apelat;
    int minute;
    
    //Citim Date
    std::cin>>tensiune;
    std::cin>>intensitate;
    std::cin>>nr_tel;
    std::cin>>baterie;
    std::cin>>nr_apelat;
    std::cin>>minute;
    
    //Initializam Obiecte
    Telefon_mobil tm(tensiune, intensitate, nr_tel, baterie);
    
    //Functii
    tm.suna(nr_apelat, minute);
    
    return 0;
    
}
