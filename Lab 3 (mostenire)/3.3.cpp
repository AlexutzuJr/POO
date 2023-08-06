/* Să se implementeze următoarea secvență UML:

Persoana:
#nume std::string

Student (public to Persoana): 
-serie: char
-nota: int
+display(void): void

Serie:
-serie: char
-p_studenti: Student**
-nr_studenti: int

+display(void): void
+ nota_max(void): int
+ nota_medie(void): float

În urma rulării codului din funcția main() se vor afișa pe ecran nota maximă a studenților seriei selectate, respectiv media notelor lor. Constructorul clasei Serie are rolul de a prelua din vectorul de intrare și a 
reține doar studenții care aparțin seriei selectate ('A'). */

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

//Clasa de Baza

class Persoana{
    
    //Date membre
    protected:
        std::string nume;
    
    //Constructor
    public:
        
        //Constructor Gol
        Persoana(){}
    
        //Consctructor cu Lista de Initializare
        Persoana(std::string nume):nume(nume){}
        
};


//Clasa Derivata
class Student:public Persoana{
    
    //Date membre
    private:
        char serie;
        int nota;
        
        
    //Constructor
    public:
    
        //Constructor Gol
        Student(){}
    
        //Consctructor cu Lista de Initializare
        Student(std::string nume, char serie, int nota):Persoana(nume), serie(serie), nota(nota){}
    
    //Functii
    public:
        void display(){
            std::cout<<Persoana::nume<<std::endl;
            std::cout<<serie<<std::endl;
            std::cout<<nota<<std::endl;
        }
    
    //Getteri si Setteri
    
        void set_nume(std::string nume){this->nume=nume;}
        std::string get_nume(){return this->nume;}
        
        void set_serie(char serie){this->serie=serie;}
        char get_serie(){return this->serie;}
        
        void set_nota(int nota){this->nota=nota;}
        int get_nota(){return this->nota;}
        

};


//Clasa Separata
class Serie{
    
    //Date membre
    private: 
        char serie;
        Student** p_studenti;
        int nr_studenti;
    
    
    //Constructor
    public:

        //Consctructor cu Lista de Initializare
        Serie(char serie, Student studenti[], int nr_studenti):serie(serie){
            int contor=0;
            
            this->p_studenti = new Student*[nr_studenti];
            
            for(int i=0; i<nr_studenti; i++){
                if (studenti[i].get_serie()==serie){
                    p_studenti[contor++] = new Student(studenti[i].get_nume(), 
                                                            studenti[i].get_serie(), 
                                                            studenti[i].get_nota());
                }
            }
            
            this->nr_studenti=contor;
        }
     
     
    //Functii
    public:
        
        //Functie Afisare
        void display(){
            for(int i=0; i<nr_studenti; i++){
               (*(p_studenti+i))->display();    
             }
        }
        
        //Getters
        int get_nota_index(int index){return (*p_studenti[index]).get_nota();}
        
        //Functie Nota Maxima
        int nota_max(){
            
            int nota_maxima=0;
            
            for(int i=0; i<nr_studenti; i++){
                if((*(p_studenti+i))->get_nota() > nota_maxima)
                    nota_maxima=(*(p_studenti+i))->get_nota();
            }
            
            return nota_maxima; 
        }
        
        //Functie Medie Note
        float nota_medie(){
            
            int suma=0;
            float medie;
            
            for(int i=0; i<nr_studenti; i++){
                    suma=suma+(*(p_studenti+i))->get_nota();

            }
            
            medie = (float)suma/nr_studenti;
            return medie;
            
        }
    
    
};



//Functia main
int main(){
    Student studenti[] = {Student("Costache", 'A', 9),
                          Student("Dobre", 'B', 10),
                          Student("Enache", 'A', 8),
                          Student("Faur", 'A', 5),
                          Student("Georgescu", 'B', 2),
                          Student("Harapu", 'A', 10),
                          Student("Ionescu", 'C', 7),
                          Student("Jianu", 'B', 9),
                          Student("Konstantinos", 'A', 10),
                          Student("Laica", 'B', 3),
                          Student("Manea", 'A', 9)};
    Serie s('A', studenti, sizeof(studenti)/sizeof(Student));
    
    
    std::cout<<s.nota_max()<<std::endl;
    std::cout<<std::fixed<<std::setprecision(2)<<s.nota_medie()<<std::endl;
    
    
    return 0;
}
