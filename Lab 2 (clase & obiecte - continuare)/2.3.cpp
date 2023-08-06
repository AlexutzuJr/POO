/* Să se scrie o clasă Pantof cu datele membre stil și mărime. Suplimentar, aceasta va conține o dată membră de tip întreg cu rolul de contor, ce va reține numărul de obiecte create, și o dată membră care reține numărul 
maxim de obiecte ce pot fi create din această clasă (se presupune că sunt în ediție limitată). Dacă la tentativa de instanțiere a unui obiect se constată că s-a atins deja numărul maxim de obiecte ce pot fi instanțiate 
se va afișa pe ecran mesajul “S-a atins pragul maxim din editia limitata!”. Toate inițializările din constructori vor fi făcute cu ajutorul listei de inițializare.
În programul principal se vor citi de la tastatură, de pe linii diferite, următoarele date:
1. un întreg m, reprezentând numărul maxim de Pantofi pe care îi putem instanția;
2. un întreg n, reprezentând numărul de obiecte pe care le vom instanția;
3. n perechi de date de tipul std::string și int, reprezentând stilul și mărimea, câte o pereche pe fiecare rând. Stilul este reprezentat de un singur cuvânt.

După fiecare instanțiere se vor afișa pe ecran stilul și marimea, separate de un spațiu și urmate de caracterul newline.

Extensie: separați declarația clasei și definițiile funcțiilor membre în fișiere diferite.
Extensie 2: cele n instanțe ale clasei Pantof vor fi reținute sub forma unui vector static de obiecte.
Extensie 3: cele n instanțe ale clasei Pantof vor fi reținute sub forma unui vector dinamic de obiecte. */


#include <iostream>
#include <limits>
#include <string>

//Clasa
class Pantof{
    
    //Date membre
    private:
        std::string stil;
        int marime;
        int numar_maxim;        //numar maxim obiecte
        
    public:
        // static int numar_maxim;        //numar maxim obiecte
        static int contor;
    
    //Constructor
    public:
        Pantof(std::string stil=" ", int marime=0, int numar_maxim=0): stil(stil), marime(marime), numar_maxim(numar_maxim){
        // Pantof(std::string stil=" ", int marime=0): stil(stil), marime(marime){
            
            //Creste mereu cand este creat un obiect
            contor++;
        }
    
    //Functii
    public:
        void afisare(){
            std::cout<<stil<<" "<< marime<<"\n";
            
        }

};

//Definim contor in fisier
int Pantof::contor = 0;


//Functia main
int main(){
    
    //Initializare Date
    int m;          //Numar maxim pantofi
    int n;          //Nr. Obiecte
    
    std::string p_stil;
    int p_marime;
    
    //Citim Date
    std::cin>>m;
    // std::cin>>Pantof::numar_maxim;
    std::cin>>n;
    
    //Alocare Dinamica Vector
    Pantof **pantof_array = nullptr;
    pantof_array = new Pantof*[n];
    
    //Facem Obiectele
    for (int i=0; i<n; i++){
        
        std::cin>>p_stil;
        std::cin>>p_marime;

        *(pantof_array + i) = new Pantof(p_stil, p_marime, m);
        // *(pantof_array + i) = new Pantof(p_stil, p_marime);
        
    }
    
    //Afisam
    for (int i=0; i<n; i++){
        if(i<m){
            (*(pantof_array + i))->afisare();
        }
        else
            std::cout<<"S-a atins pragul maxim din editia limitata!"<<"\n";
    }
    
    //Destructor Obiecte
    for(int i=0; i<n; i++){
        delete *(pantof_array + i);
    }
    
    delete pantof_array;
    
    return 0;
}
