#include <iostream>
#include <string>

class Zboruri
{
    private:
        std::string oras_plecare;
        std::string oras_sosire;
        int ora_plecare;
        int minut_plecare;
        int ora_sosire;
        int minut_sosire;
        
    public:
        void init(std::string oras_plecare, std::string oras_sosire, int ora_plecare, int minut_plecare, int ora_sosire, int minut_sosire)
        {
            this->oras_plecare=oras_plecare;
            this->oras_sosire=oras_sosire;
            this->ora_plecare=ora_plecare;
            this->minut_plecare=minut_plecare;
            this->ora_sosire=ora_sosire;
            this->minut_sosire=minut_sosire;
        }


        void afisare1()
        {
            std::cout<<oras_plecare<<" - "<<oras_sosire<<std::endl;
            std::cout<<ora_plecare<<":"<<minut_plecare<<" - "<<ora_sosire<<":"<<minut_sosire<<std::endl;
        }
        
        std::string get_oras_plecare(){ return this->oras_plecare=oras_plecare; }
        std::string get_oras_sosire(){ return this->oras_sosire=oras_sosire; }
        
        void afisare2(){}

        int get_ora_plecare(){ return this->ora_plecare=ora_plecare; }
        int get_ora_sosire(){ return this->ora_sosire=ora_sosire; }
        int get_minut_plecare(){ return this->minut_plecare=minut_plecare; }
        int get_minut_sosire(){ return this->minut_sosire=minut_sosire; }
        
        void afisare3(){}
        
        void afisare4()
        {
           std::cout<<oras_plecare<<" - "<<oras_sosire<<std::endl; 
        }    

};


class Aeroport //asta nu face nimic (dar ne cerea sa o avem)
{
    private:
        int zboruri;
        
    public:
        void init(int zboruri)
        {
            this->zboruri=zboruri;
        }


    void afisare() {}   

};



int main()
{
    std::string oras_plecare_n, oras_sosire_n;
    int ora_plecare_n, minut_plecare_n, ora_sosire_n, minut_sosire_n;
    
    int n;
    std::cin>>n;
    std::cin.ignore();
    
    Zboruri z[20];
    
    int i;
    
    for(i=0;i<n;i++)
    {
        std::cin>>oras_plecare_n;
        std::cin>>oras_sosire_n;
        std::cin>>ora_plecare_n;
        std::cin>>minut_plecare_n;
        std::cin>>ora_sosire_n;
        std::cin>>minut_sosire_n;
        std::cin.ignore();
        z[i].init(oras_plecare_n, oras_sosire_n, ora_plecare_n, minut_plecare_n, ora_sosire_n, minut_sosire_n);
    }

  
    int optiune;
    std::cin>>optiune;
    std::cin.ignore();
    
    if(optiune==1)
    {
        int numar;
        std::cin>>numar;
        std::cin.ignore();
        
        for(i=0;i<n;i++)
        { //avand 2 "if-uri", neaparat punem bucla
            if(numar==0 && z[i].get_oras_plecare()=="Bucuresti")
                z[i].afisare1();
                
            if(numar==1 && z[i].get_oras_sosire()=="Bucuresti")
                z[i].afisare1();
        }
    }
    
    if(optiune==2)
    {
        int t1_ora; //trebuie un t1 pentru ora si alt t1 pentru minute (vezi la afisare, dupa "2")
        int t1_minut;
        int t2_ora;
        int t2_minut;
        std::cin>>t1_ora;
        std::cin>>t1_minut;
        std::cin>>t2_ora;
        std::cin>>t2_minut;
        
        for(i=0;i<n;i++)
            if(z[i].get_oras_plecare()=="Bucuresti")
                if(z[i].get_ora_plecare()>=t1_ora && z[i].get_minut_plecare()>=t1_minut)
                    if(z[i].get_ora_sosire()<=t2_ora && z[i].get_minut_sosire()<=t2_minut)   
                        z[i].afisare1();
    }
    
    if(optiune==3)
    {
        int d[20]; //facem un vector pentru distante, astfel incat sa le putem afisa pe rand, cu un "for"
        float minut1, minut2, minute_totale;
        float viteza[20]; //si acesta va fi vector, pentru ca il afisam intr-un "for" la final
        
        for(i=0;i<n;i++)
        {
            std::cin>>d[i]; //il citim (deoarece dupa "3", sunt afisate distantele); daca il citeam direct ca "std::cin>>d[20]" acesta nu ar fi avut niciun efect, deoarece este in afara "for-ului", si nu ar fi stiut ce element sa ia din acesta (cum e cazul aici); practic noi parcurgem vectorul "d[i]", pe rand (d[0], d[1], d[2]...), cu acest "for"
            minut1=(z[i].get_ora_plecare()*60)+z[i].get_minut_plecare(); //transformam orele in minute, astfel incat sa putem stii timpul total; nu putem transforma direct in ore, deoarece nu exista, de exemplu, 1.2 (o ora si 2), astfel, pentru a putea stii exact diferenta dintre ore si minute (timpul total), trebuie sa transformam orele in minute, si sa le adunam la minutele deja existente 
            minut2=(z[i].get_ora_sosire()*60)+z[i].get_minut_sosire(); //nu putem lua, de exemplu, "ora_sosire_n", pentru ca va avea valoarea prestabilita din "for-ul" facut in "main" 
            minute_totale=minut2-minut1; //timpul total (in minute)
            viteza[i]=d[i]/(minute_totale/60); //distanta (data in afisare) impartita la timpul total (exprimat in ore), astfel incat sa putem avea viteza exprimata in km/h
        }
        
        for(i=0;i<n;i++)
        {
            z[i].afisare1(); //intai afisam orasele, apoi vitezele (vezi afisare)
            std::cout.precision(2);
            std::cout<<std::fixed<<viteza[i]<<std::endl; //nu uitam ca aici e "viteza[i]", pentru ca e un vector
        }
    }
    
    if(optiune==4)
    {
        Aeroport a; //l-am pus asa sa fie (nu face nimic), pentru ca nu avem nevoie de clasa "Aeroport" aici, dar ne punea sa o folosim
        int d[20];
        float suma_totala_bilete; //in alte cazuri poate da si cu virgula; daca chiar nu ne iese din cauza ca am pus "int" in prea multe locuri (adica unele din ele unde nu trebuie) si nu ne dam seama care e cel pus gresit, putem pune "float" peste tot (desi nu e cel mai corect, rezultatul final va fi corect mereu)
        float pret_mediu=0.15;
        int pasageri=400;
        float cost_combustibil;
        float minut1, minut2, timp_total;
        int consum_avion=10000;
        int cost_litru=1;
        float profit[20];
        
        for(i=0;i<n;i++)
        {
            std::cin>>d[i];
            
            suma_totala_bilete=pret_mediu*d[i]*pasageri; //puteam face si "suma_totala_bilete" si "cost_combustibil" ca vectori, dar cel mai corect e sa nu fie (insa daca nu vrem sa gandim prea mult, daca sunt vectori si ei sau nu, ii putem face si pe ei)
            
            minut1=(z[i].get_ora_plecare()*60)+z[i].get_minut_plecare();  
            minut2=(z[i].get_ora_sosire()*60)+z[i].get_minut_sosire();
            timp_total=(minut2-minut1)/60; //pentru ca e exprimat in ore in cerinta
            
            cost_combustibil=timp_total*consum_avion*cost_litru; //desi asa ar parea, timpul total nu este vector, pentru ca nu ne-a pus sa-l citim dupa; cu alte cuvinte, va stii la ce timpi sa se duca, cu ajutorul vectorului de distante
            
            profit[i]=suma_totala_bilete-cost_combustibil; //deoarece avem acel d[i], vom avea si profit[i], pentru ca va calcula pentru fiecare element din vector, profitul, deci pentru toate cazurile (in plus, il afisam intr-un "for" la final)
        }
        
        for(i=0;i<n;i++)
        {
            z[i].afisare4();
            std::cout.precision(2);
            std::cout<<std::fixed<<profit[i]<<std::endl;
        }
    }
       
};
