/* Să se scrie un program care afișează pe ecran numele studenților citiți de la tastatură, ordonați după un anumit criteriu definit mai jos.

Se citesc de la tastatură până la apariția cuvântului STOP:
- un std::string, reprezentând numele studentului;
- un întreg, n, reprezentând numărul de note ce urmează a fi citit de la tastatură;
- n întregi reprezentând notele studentului;

După cuvântul STOP se mai citește o valoare întreagă de test, în funcție de a cărei valoare se execută:
1. Ordonarea studenților după nume. Se afișează pe ecran numele studenților în ordine lexicografică, câte unul pe un rând diferit. Fiecare nume este urmat de caracterul '\n'.
2. Ordonarea studenților după media notelor. Se afișează pe ecran numele studenților în ordinea mediilor notelor, câte unul pe un rând. Fiecare nume este urmat de caracterul '\n'. */


#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

//Clasa de Baza
class Student{
    
    //Date membre
    private:
        std::string nume;
        int numar_note;
        std::vector<int> note;
        float medie_student;
    
    //Constructor
    public:
        Student(std::string nume, int numar_note, std::vector<int> note): nume(nume), numar_note(numar_note), note(std::move(note)){}

    //Functii
    public:
   
          
        void afisare(){
            std::cout<<nume<<"\n";
        }
        
        void medie(){
            medie_student=0;
            for(std::vector<int>::iterator it=note.begin(); it!=note.end(); ++it){
                medie_student=medie_student+ (*it);
            }
            medie_student=medie_student/numar_note;
        }
        
        float get_medie(){
            return medie_student;
        }
        
        std::string get_nume(){
            return nume;
        }
        
   
};


//Functii pentru STL
bool medie(Student s1, Student s2){
    return(s1.get_medie()<s2.get_medie());
}

bool lexicografic(Student s1, Student s2){
    const char *cstr1=s1.get_nume().c_str();
    const char *cstr2=s2.get_nume().c_str();
    return strcmp(cstr1,cstr2);
}


//Functia Main
int main(){
    
    //Initializam Date
    std::string nume;
    int numar_note;
    int numar_studenti=0;
    std::vector<int> note;
    
    std::vector<Student> studenti;
    
    //Citim pana la STOP    
    for(int i=0; ;i++){
        
        std::cin>>nume;
        
        //Punem conditia
        if(nume !="STOP"){
            
            std::cin>>numar_note;
            
            for(int j=0; j<numar_note; j++){
                int x;
                std::cin>>x;
                note.push_back(x);
            }
            
            //Punem elementele in obiect cu STL
            studenti.push_back(Student(nume, numar_note, note));
            studenti[i].medie();
            numar_studenti++;
            note.clear();
        }
        
        if(nume == "STOP"){
            break;
        }
    }
    
    
    //Optiuni
    int optiune;
    std::cin>>optiune;
    
    if(optiune==1){
        std::sort(studenti.begin(), studenti.end(), lexicografic);
        for(int i=0; i<numar_studenti;i++){
            studenti[i].afisare();
        }
    }
    
    if(optiune==2){
        std::sort(studenti.begin(), studenti.end(), medie);
        for(int i=0; i<numar_studenti;i++){
            studenti[i].afisare();
        }
    }  
    return 0;
   
}
