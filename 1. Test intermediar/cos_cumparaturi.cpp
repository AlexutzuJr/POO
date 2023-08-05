#include <iostream>
#include <string>
#include <cmath>

class Produse //"pentru fiecare dintre cele n produse se citesc", deci vom avea intai o clasa Produse
{
    private:
        std::string nume;
        std::string categorie;
        float pret; //e float pentru ca e un numar real pozitiv (deci poate fi si cu virgula); putem vedea asta si la afisare
        float greutate;
        
    public:
        void init(std::string nume, std::string categorie, float pret, float greutate)
    {
        this->nume=nume;
        this->categorie=categorie;
        this->pret=pret;
        this->greutate=greutate;
    }


    void afisare1()
    {
        std::cout<<nume<<", "; //nu punem std::endl, deoarece la output ne spune sa afisam in continuarea acestora; mare atentie si la spatiul de dupa virgula, trebuie pus neaparat
        std::cout<<categorie<<", ";
        std::cout<<pret<<" lei, "; //atentie la spatiul de dinaintea lui "lei", si de dupa virgula pusa 
        std::cout<<greutate<<" kg"<<std::endl;
    }
    
    void afisare2(){}
    
    std::string get_categorie(){ return this->categorie; } //facem un getter pentru a stoca intr-o alta variabila, o valoare
    
    void afisare3()
    {
        std::cout<<nume<<", ";
        std::cout<<categorie<<", ";
        std::cout<<pret<<" lei, ";
        std::cout<<greutate<<" kg"; //atentie, nu punem std::endl la final, pentru a putea afisa numarul de bucati in continuare (cum scrie si in exemplul din cerinta) 
    }
    
    std::string get_nume(){ return this->nume; }
    float get_greutate(){ return this->greutate; }
    float get_pret(){ return this->pret; }
    
    void afisare4(){}
    
    void afisare5(){}
    
};


class Cos //doar asa sa fie
{
    private:
        int p;
        Produse pr[100];

    public:
        void init(int p)
    {
        this->p=p;
    }


    void afisare()
    {
        for(int i=0;i<5;i++)
            pr[i].afisare1();
    }
    
};



int main()
{
    std::string nume_n, categorie_n;
    float pret_n, greutate_n;
    
    int n;
    std::cin>>n;
    std::cin.ignore(); //trebuie pus neaparat inaintea citirii unui sir de caractere (si in afara "for-ului", daca e cazul)
    
    Produse p[20]; //20 produse diferite (puteam scrie si 30, de ex, dar sa fie macar mai mare ca 20)
    
    int i;
    
    for(i=0;i<n;i++)
    {
        getline(std::cin, nume_n); //trebuie citit cu getline cand avem un sir de caractere (adica mai multe cuvinte pe acelasi rand!!!)
        getline(std::cin, categorie_n); //aici nu mai trebuie inca un "std::cin.ignore()" , fiind in continuarea celuilalt sir de caractere (daca am mai pune unul, ar sterge prima litera din acesta)
        std::cin>>pret_n;
        std::cin>>greutate_n;
        std::cin.ignore(); //mai punem inca un "std::cin.ignore()" si la final, deoarece "for-ul" va parcurge toate elementele din nou, deci dupa citirea lui "greutate_n" va incepe iar cu "nume_n"
        p[i].init(nume_n, categorie_n, pret_n, greutate_n);
    }

    
    int optiune;
    std::cin>>optiune;
    std::cin.ignore();
    
    if(optiune==1)
        for(i=0;i<n;i++)
            p[i].afisare1();
    
    if(optiune==2)
    {
        std::string categorie_anume; //initializam
        getline(std::cin, categorie_anume); //citim
        
        int ok=0;
        
        for(int i=0;i<n;i++) //pentru a le citi in ordine
            if(categorie_anume==p[i].get_categorie()) //"p[i].get_categorie()" apeleaza "categorie" din clasa Produse, folosindu-ne de getter
            { //trebuie neaparat bucla, deoarece se executa 2 instructiuni simultan (deci nu se mai subintelege, ca si cand am avea doar una)
                ok++; //ok++ (echivalent cu ok=1), este folosit pentru a-i da alta valoare lui "ok", astfel incat sa afiseze doar mesajul dorit (separat de "N/A"); acesta trebuie intai incrementat cu un "for" si "if" (pentru a-i da sansa sa se modifice cat mai repede), apoi folosim valoarea data lui "ok" initial, pentru a afisa "N/A" separat 
                p[i].afisare1(); //facem acest "aritifciu", deoarece intai vrem sa afisam ceva ce nu este text, si dupa sa afisam DOAR textul
            }
    
        if(ok==0)
        std::cout<<"N/A"<<std::endl;
    }
    
    if(optiune==3)
    {
        int d[20]; //stocam numarul de bucati intr-un vector (trebuie sa fie de minim 20 de elemente, ca si produsele)
        
        for(i=0;i<20;i++) //merge pana la 20, atentie!
            d[i]=1; //deoarece la afisare avem doar 1 bucata pe linii, o initializam cu 1
            
        for(i=0;i<n;i++) //parcurgem liniile
        { //neaparat bucla, pentru ca avem alt "for" dupa (care este inclus in cel actual)
            if(d[i]!=0) //deoarece vectorul primeste valori in interiorul "if-ului", trebuie sa scriem cu ceva "!=" in if, pentru a nu-i atribui direct valoarea 
                for(int j=0;j<n;j++) //parcurgem coloanele
                    if(d[j]!=0 && i!=j) //numarul de linii este diferit de numarul de coloane
                        if(p[i].get_nume()==p[j].get_nume() && p[i].get_categorie()==p[j].get_categorie() && p[i].get_pret()==p[j].get_pret() && p[i].get_greutate()==p[j].get_greutate()) //pentru ca produsele se repeta
                        {
                            d[i]=2; //pentru a afisa pe a 2 linie, 2 bucati (ca in exemplu)
                            d[j]=0; //deoarece nu avem nicio coloana; daca punem 1, ne va adauga o bucata in plus, pe o linie random (ceea ce nu este cazul aici)
                        }
        }
        
        for(i=0;i<n;i++) //afisam produsele unice
            if(d[i]!=0) //deoarece in acest "if", am afisat toate detaliile despre matrice (care este, de fapt, un vector linie)
            {
                p[i].afisare3();
                std::cout<<", "<<d[i]<<" buc"<<std::endl; //afisam textul de dupa
            }
    }
    
    if(optiune==4)
    {
        Cos c; //doar sa fie
        float s=0; //vom face un "float", in care vom stoca greutatea
        
        for(i=0;i<n;i++) //calculam greutatea totala
            s=s+p[i].get_greutate(); //pentru a prelua valoarea greutatii, avem nevoie de un getter; daca nu ne zice absolut nimic in cerinta de cum se calculeaza, cel mai probabil doar trebuie sa facem un "float" in care sa o stocam si sa il adunam cu un getter
        
        for(i=0;i<n;i++) //afisam greutatea totala
        {
            std::cout.precision(2); //pentru a afisa valoarea cu 2 zecimale exacte, avem nevoie de aceasta instructiune 
            std::cout<<s<<std::endl; //afisam direct aici, deoarece in clasa nu avem o variabila "s" (si nici nu o putem calcula acolo, daca am vrea, deoarece pentru a calcula greutatea avem nevoie de "for-ul" acela care il contine pe "n", iar acesta este declarat in "main") 
        }
    }
    
    if(optiune==5)
    {
        Cos c; //doar sa fie
        float prag_greutate; 
        float cost_aditional; //in cerinta ne spune gresit ca e intreg, daca ne uitam la afisare, e "float"
        std::cin>>prag_greutate;
        std::cin>>cost_aditional;
        
        float s=0;
        
        for(int i=0;i<n;i++)
            s=s+p[i].get_greutate(); //deoarece la explicatii ne spune ca pornim de la greutatea totala a cosului, va trebui sa copiem ce am scris mai sus (pentru a ajunge la aceeasi greutate)
        //restul valorilor nu trebuie sa intre neaparat in "for", deoarece nu apartin clasei, si sunt niste numere aleatoare
        float x; //aici vom stoca kg taxate suplimentar
        x=s-prag_greutate; //prin deductie observam ca trebuie sa scadem pragul (deoarece este exprimat in kg)
        float ceil(float x); //uneori nu merge sa rotunjim folosind comanda asta, deci folosim alta variabila "float r=ceil(x)", si mai departe vom folosi variabila "r" in calcule (fiind ceea rotunjita cu ajutorul lui "x", in acest caz)
    
        float taxa_greutate;
        taxa_greutate=prag_greutate*cost_aditional; //putem face si prin deductie: pragul este exprimat in kg, iar costul in lei/kg, deci kg*lei/kg trebuie sa fie exprimat in lei
        
        float cost_produse=0; //mereu cand vrem sa adunam cu o valoare curenta (si getter), vom initializa cu 0 variabila
        
        for(int i=0;i<n;i++) //este mult mai corect sa luam costul produselor cu un getter, dar puteam scrie si "float cost_produse=50" direct
            cost_produse=cost_produse+p[i].get_pret(); //adunam cu pretul, fiind exprimat in lei 
        
        float cost_final;
        cost_final=cost_produse+taxa_greutate;
        std::cout.precision(2); 
        std::cout<<std::fixed<<cost_final<<std::endl; //afisam costul final
    }
    
};
