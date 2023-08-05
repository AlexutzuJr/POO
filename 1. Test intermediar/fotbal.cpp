#include <iostream>
#include <string>

class Echipa
{
    private: 
        std::string nume_echipa; 
        int v, e, inf; 
        
    public: 
        void init(std::string nume_echipa, int v, int e, int inf) //functia de initializare (constructorul)
        {
            this->nume_echipa=nume_echipa; //accesam din clasa Echipa, data membra "nume_echipa"
            this->v=v;
            this->e=e;
            this->inf=inf;
        }


    void afisare1() //putem numi oricum vrem functia "void"
    {
        std::cout<<nume_echipa<<" "; //afisam echipele, apoi victoriile s.a.m.d., pe rand (cum se specifica in enunt)
        std::cout<<v<<" "; //deoarece numele echipei, victoriile, egalurile si infrangerile trebuie sa le afisam pe aceeasi linie cu spatiu, va trebui sa punem " " (adica spatiu intre ele)
        std::cout<<e<<" "; //daca puneam "endl" dupa fiecare, le-ar fi afisat unele sub altele
        std::cout<<inf<<std::endl;
    }
    
    void afisare2()
    {
        int nr_puncte; //trebuie neaparat aici initializat pentru a putea fi citit, impreuna cu numele echipei (care este deja creat in clasa (nu in "main"))
        nr_puncte=v*3+e*1+inf*0; //calculam nr total de puncte; putem scrie cu ajutorul variabilelor "v" si "e", pentru ca sunt initializate deja in clasa
      
        std::cout<<nume_echipa<<" ";
        std::cout<<nr_puncte<<std::endl;
    }
    
    void afisare3(){} //aici nu avem nevoie de "void afisare3" (l-am pus doar sa vad mai usor ce am mai adaugat pentru acest caz)
    
    //deoarece la punctul 3 trebuie sa modificam, ceea ce vom afisa ulterior, vom folosi getteri si setteri 
    //pag 22 din curs; sunt la fel ca acolo, doar ca fara "void set_v(int get _v)", vom scrie direct void set_v() (deoarece daca scriem cu "int" intre paranteze, nu va merge afisarea) 
    std::string get_nume_echipa(){ return this->nume_echipa; } //deoarece numele echipei nu se modifica, folosim doar getter-ul, pentru a-l putea apela ulterior in "main"
    
    void set_v(){ this->v=v+1; } //deoarece nu avem alta variabila noua data in cerinta, va trebui sa setam direct victoria adaugata
    
    int get_v(){ return this->v*3+e*1+inf*0; } //pentru ca la afisarea 5.v1 ne va calcula castigatoarea in functie de puncte (mai intuitiv era sa facem alt getter cu alta denumire)

    void set_e(){ this->e=e+1; } //ne uitam la input si output (la afisare), si observam ca avem un egal adaugat 
    
    void set_inf(){ this->inf=inf+1; } 
    
    void afisare4()
    {
        std::cout<<"Locul 1: "<<nume_echipa<<std::endl; //in cerinta, ce nu e intre ghilimele e text (deci noi il vom pune intre ghilimele), iar ce este intre ghilimele este o variabila (deci nu o vom pune intre ghilimele)
    }
    
    int s; //s=v+e+inf (numarul de meciuri jucate); putem crea alte variabile si in afara clasei

    int get_s(){ return this->v+e+inf; } //pentru a-l putea apela pentru cazul 4, in "main", avem nevoie de getter
    
    void afisare5()
    {
        std::cout<<nume_echipa<<" a castigat!"<<std::endl; //nu uitam sa lasam spatiu inainte de "a castigat"
    }

}; //inchidem bucla pt clasa echipa    


class Liga //irelevanta pentru rezolvare, dar trebuie sa o facem ca asa ne spune in cerinta (nu conteaza ce scriem in ea)
{
    private:
        int mj;
        Echipa ec[100];
        
    public:   
        void init(int mj)
        {
            this->mj=mj;
        }
        
    void afisare()
    {
        for (int i=0;i<5;i++)
            ec[i].afisare1(); 
    }
    
};
    


int main() //pentru a putea apela functiile create in clasa (deci pentru a le putea afisa), avem nevoie de functia "main"
{ 
    std::string nume_echipa_n; 
    int v_n, e_n, inf_n; 
    
    int n; //mereu in "main" avem nevoie si de un "n", pe care il vom folosi ulterior intr-un "for", pentru a-l compara cu "i"
    std::cin>>n; //citim n-ul
    
    Echipa e[10]; //aici creez obiectul clasei Echipa (reprezinta nr maxim de echipe care vor fi introduse (putem pune si 20 si 30, atat timp cat e mai mare ca 10)); ne vom folosi de el pentru a putea afisa anumite informatii despre echipe
    
    int i; 
    
    for(i=0;i<n;i++) //parcurgem citirea cu un "for" 
    {
        std::cin>>nume_echipa_n; //citim elementele clasei in ordine
        std::cin>>v_n;
        std::cin>>e_n;
        std::cin>>inf_n;
        e[i].init(nume_echipa_n, v_n, e_n, inf_n); //apelam prin obiect, argumentele clasei Echipa cu ajutorul functiei de initializare
    }
    
    int caz; //deoarece trebuie sa facem mai multe afisari, vom avea nevoie de mai multe cazuri (si oricum ne cerea sa avem un numar de valori in [1,5] in functie de care se realizeaza operatiile)
    std::cin>>caz; //nr. de val intregi in [1,5], adica cazurile pentru care trebuie sa facem afisarile 
    
    if(caz==1) 
        for(i=0;i<n;i++) //pentru ceea ce tocmai am citit, vom face afisarea cu ajutorul functiei de mai sus
            e[i].afisare1(); //apelam functia creata, "void afisare1", folosindu-ne de vectorul e[i]
        
    if(caz==2)
        for(i=0;i<n;i++)
            e[i].afisare2();
        
    if(caz==3)
    { //pentru ca trebuie sa executam mai multe instructiuni simultan, mai avem nevoie de o "{"
        int mj; //initializam meciurile jucate
        int ng1, ng2;
        std::string ne1, ne2; //numele echipei e un cuvant, atentie!

        std::cin>>mj; //citim de la tastatura meciurile jucate (in afara "for-ului")
        
        int x; //vom avea nevoie de alt intreg, pentru ca vom avea nevoie de mai multe "for-uri"
    
        for(x=0;x<mj;x++) //merge pana la meciuri jucate (deoarece avem acel "3", la afisare)
        {
            std::cin>>ne1; //atentie la citire, trebuie neaparat in ordine, cum apare la afisare
            std::cin>>ng1;
            std::cin>>ng2;
            std::cin>>ne2;
            //atentie, nu inchidem bucla "for-ului", altfel nu se vor afisa setterii si getterii, deoarece "if-urile" de dupa, lucreaza impreuna cu "for-ul" de mai sus
        
            if(ng1>ng2) //trebuie sa luam in calcul cazurile in care echipa castiga, face egal, sau pierde (pentru a putea afisa punctajul si noile victorii/egaluri/infrangeri adaugate)
            {
                for(i=0;i<n;i++)
                { //cu alte cuvinte: daca iau toate echipele la rand, si am gasit-o pe FCSB, adauga-i 1 punct
                    if(ne1.compare(e[i].get_nume_echipa())==0) //compara valoarea string-ului "ne1" cu numele obiectului "e" si seteaza valoarea unui membru din obiectul respectiv, daca comparatia e adevarata; mai simplu era sa facem: "if(ne1==e[i].get_nume_echipa())"
                    e[i].set_v(); //daca acest lucru se intampla, ii adaugam echipei victoria
                  //ambele "if-uri" merg in acelasi "for", deoarece conditiile trebuie sa fie respectate simultan    
                    if(ne2.compare(e[i].get_nume_echipa())==0)
                    e[i].set_inf(); //apelam inf, adica adaugam infrangerea
                }
            }
        
            if(ng1<ng2)
            {
                for(i=0;i<n;i++)
                {
                    if(ne1.compare(e[i].get_nume_echipa())==0) //daca compare e 1, ii seteaza infrangere
                    e[i].set_inf();
            
                    if(ne2.compare(e[i].get_nume_echipa())==0) //numele (sirurile) sunt identice, deci seteaza victorie
                    e[i].set_v();
                }
            }
        
            if(ng1==ng2)
            {
                for(i=0;i<n;i++)
                {
                    if(ne1.compare(e[i].get_nume_echipa())==0) 
                    e[i].set_e(); 
        
                    if(ne2.compare(e[i].get_nume_echipa())==0)
                    e[i].set_e();
                }
            }
    }
        
    int j; 
    std::cin>>j; //citim un nr intreg
        
    if(j==1) //afisam ca la subpunctul 1 (neaparat scriem ca este egal cu 1, la fel cum facem si cu cazurile)
        for(i=0;i<n;i++)
            e[i].afisare1();
        
    if(j==2) //afisam ca la subpunctul 2
        for(i=0;i<n;i++)
            e[i].afisare2();
    }  
    
    if(caz==4)
    {
        Echipa campioana; //declaram clasa Echipa si obiectul numit "campioana" (care reprezinta obiectul clasei Echipa)
        //pentru a afisa locul 1 din clasament, ne vom folosi de algoritmul de maxim
        campioana=e[1]; //presupunem maximul, ca fiind primul element din vector 
         
        for(i=1;i<n;i++) //atentie, ne uitam de la 1 incolo, si nu de la 0, deoarece am presupus primul element din vector ca fiind maxim
        {
            if(e[i].get_v()>campioana.get_v()) //daca echipa are cele mai multe victorii => campioana
                campioana=e[i]; //elementul actual "e[i]" devine maxim
         
            if(e[i].get_v()==campioana.get_v()) //daca nr de victorii este egal, echipa cu cele mai putine meciuri jucate => campioana
                if(e[i].get_s()<campioana.get_s()) //cand ai "if" in "if", e ca si cum ai avea un singur "if", cu o conditie, care le contine pe ambele printr-un "&&"
                    campioana=e[i];
        }
        
        campioana.afisare4(); //afisam campioana dupa ce toate conditiile sunt respectate simultan (altfel nu merge, deoarece nu putem sa apelam printr-un getter, "nume_echipa" (de exemplu), cand facem "cout")
    }
    
    if(caz==5)
    {
        Liga l; //apelam clasa liga (mergea si fara ea, dar respectam cerinta)
        Echipa campioana;
        int meciuri=(n-1)*2; //fiecare echipa joaca cu celelalte echipe din liga (evident, fara ea insasi); puteam scrie si intai "int meciuri"; meciuri=(n-1)*2; (e acelasi lucru)
        int p; //numarul maxim de puncte ramase
        p=(meciuri-e[i].get_s())*3; //numarul maxim de puncte care pot fi obtinute din meciurile ramase (deci nu inmultim cu 1, deoarece un egal nu ar aduce un numar maxim de puncte), totul inmultit cu 3
        
        campioana=e[1];
        
        for(i=1;i<n;i++) //algoritmul de maxim
        {
            if(e[i].get_v()>campioana.get_v())
                campioana=e[i]; //alegem campionul
        }
        
        int z=campioana.get_v();
        int ok=1; //ii dam (direct) lui "ok" valoarea 1 pentru a putea apela functia "campioana" (valoarea 0 a lui "ok" o putem lua din "if-uri", la final, insa pentru 1, nu putem altfel)
        
        for(i=0;i<n;i++)
        {
            if(campioana.get_nume_echipa().compare(e[i].get_nume_echipa())!=0)  //numele campioanei e diferit de numele echipei actuale
                if(e[i].get_v()+p>z) //ia victoriile tuturor echipelor din campionat si il aduna cu numarul maxim de puncte posibile ramase, si daca e mai mare ca numarul de puncte al campioanei, atunci inseamna ca nu putem afirma ca exista un castigator (din punct de vedere matematic) inca
                    ok=0; //ii dam lui "ok" valoarea 0 pentru a afisa ca nu exista castigator
        }
        
        if(ok==0) //trebuie neaparat sa-l scriem separat, deoarece daca il scriam in acele "if-uri", intra si in "for", deci ne afisa de mai multe ori acelasi mesaj, ceea ce nu ar fi fost corect
        std::cout<<"Nu exista castigator!"<<std::endl; //ii dam direct "cout", pentru ca asa zice si in cerinta (nu mergea sa apelam functia "void" pentru ca nu era definita si in "main")
        
        if(ok==1)
            e[i].afisare5();
    }
    
};
