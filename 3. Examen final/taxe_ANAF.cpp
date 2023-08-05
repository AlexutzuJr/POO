#include <iostream>
#include <string>

class PlatitorTaxe
{
    protected:
        std::string tip;
        std::string nume;
        int suma_incasata;
        int suma_netaxabila;
        
    public:
        PlatitorTaxe(std::string tip, std::string nume, int suma_incasata, int suma_netaxabila): tip(tip), nume(nume), suma_incasata(suma_incasata), suma_netaxabila(suma_netaxabila) {}
        
    virtual void afisare() {}
    virtual void taxe_de_baza(float x) {}
    virtual void procent_venit() {}
    virtual float taxe_4(int x) { return 0; }
    virtual void afisare_nume(){ std::cout<<nume<<std::endl; }
    
    std::string get_tip(){ return this->tip; }
};


class PersoanaFizica: public PlatitorTaxe
{ //deoarece nu ni se spune nimic de datele membre ale claselor derivate, inseamna ca nu avem altele in plus
    public:
        PersoanaFizica(std::string tip, std::string nume, int suma_incasata, int suma_netaxabila): PlatitorTaxe(tip, nume, suma_incasata, suma_netaxabila) {}
        
    void afisare()
    {
        std::cout<<nume<<std::endl;
        std::cout<<suma_incasata<<std::endl;
    }
    
    void taxe_de_baza(float x)
    {
        int suma_platita;
        
        suma_platita=(suma_incasata-suma_netaxabila)*x/100; //variabila "100-procent_taxe" se refera clar la "x", deoarece nu mai avem o alta variabila de genul numita pe undeva
        
        std::cout<<nume<<std::endl;
        std::cout<<suma_platita<<std::endl;
    }
    
    void procent_venit() //deoarece in "optiunea" respectiva nu am mai citit nimic, nu putem avea un argument al acestei functii
    {
        float procent_netaxabil;
        
        if(suma_netaxabila>0.2*suma_incasata) //aici daca puneam 20*suma_incasata, nu mergea
        {
            procent_netaxabil=suma_netaxabila*100/(float)suma_incasata; //deoarece nu ni se spune nimic de formula, fie verificam daca cea de dinainte inca este valabila, iar daca nu este, incercam sa ne uitam la "input" si sa o deducem singuri; atentie ca "suma_incasata" trebuie sa o facem "float" (fiind initializata ca "int" initial), aici (pentru a putea obtine un rezultat cu virgula)
            
            std::cout<<nume<<std::endl;
            std::cout.precision(2); //fara "std::endl", cand scriem asta
            std::cout<<std::fixed<<procent_netaxabil<<std::endl;
        }
    }
    
    float taxe_4(int x)
    {
        float suma=0;
        float suma_finala=0;
        float diferenta=0;
            
        suma=suma_incasata-suma_netaxabila;
            
        if(suma>300000)
        {
            diferenta=suma-300000;
            suma_finala=(300000*x/100)+(diferenta*40/100);
        }
            
        if(suma<300000)
             suma_finala=(suma*20)/100;
            
            return suma_finala;
    }
};


class Firma: public PlatitorTaxe
{
    public:
        Firma(std::string tip, std::string nume, int suma_incasata, int suma_netaxabila): PlatitorTaxe(tip, nume, suma_incasata, suma_netaxabila) {}
        
    void afisare()
    {
        std::cout<<nume<<std::endl;
        std::cout<<suma_incasata<<std::endl;
    }
    
    void taxe_de_baza(float x)
    {
        int suma_platita;
        
        suma_platita=(suma_incasata-suma_netaxabila)*x/100;
        
        std::cout<<nume<<std::endl;
        std::cout<<suma_platita<<std::endl;
    }
    
    void procent_venit()
    {
        float procent_netaxabil;
        
        if(suma_netaxabila>0.2*suma_incasata)
        {
            procent_netaxabil=suma_netaxabila*100/(float)suma_incasata;
            
            std::cout<<nume<<std::endl;
            std::cout.precision(2);
            std::cout<<std::fixed<<procent_netaxabil<<std::endl;
        }
        else
            std::cout<<"Nicio potentiala frauda detectata"<<std::endl; //scriem doar intr-o clasa (altfel se va afisa de mai multe ori)
    }
    
    float taxe_4(int x)
    {
        float suma=0;
        float suma_finala=0;
        float diferenta=0;
            
        suma=suma_incasata-suma_netaxabila;
            
        if(suma>300000)
            suma_finala=(suma)*(x+19)/100;
                
        if(suma<300000)
            suma_finala=(suma*20)/100;
        
            return suma_finala;
    }    
};



int main()
{
    int optiune;
    int nr_entitati;
    std::string tip;
    std::string nume;
    int suma_incasata;
    int suma_netaxabila;
    
    std::cin>>optiune;
    std::cin>>nr_entitati;
    
    PlatitorTaxe **platitori_array=nullptr;
    platitori_array=new PlatitorTaxe*[nr_entitati];
    
    int k=0;
    
    for(int i=0;i<nr_entitati;i++)
    {
        std::cin.ignore();
        getline(std::cin, tip);
        getline(std::cin, nume);
        std::cin>>suma_incasata;
        std::cin>>suma_netaxabila;
        
            if(tip=="Persoana Fizica") //neaparat cu acest spatiu intre!!!, cum e scris si la "input"
                *(platitori_array+(k++))=new PersoanaFizica(tip, nume, suma_incasata, suma_netaxabila);
                
            if(tip=="Firma")
                *(platitori_array+(k++))=new Firma(tip, nume, suma_incasata, suma_netaxabila);
    }

  
    if(optiune==1)
    {
        for(int i=0;i<nr_entitati;i++)
            (*(platitori_array+i))->afisare();
    }
    
    if(optiune==2)
    {
        int taxe_persoana;
        int taxe_firma;
        
        std::cin>>taxe_persoana;
        std::cin>>taxe_firma;
        
        for(int i=0;i<nr_entitati;i++)
        {
            if((*(platitori_array+i))->get_tip()=="Persoana Fizica") //aici ne uitam la "input" la cum se numeste tipul, de asemenea aici nu am putut egala getter-ul "tip" cu o alta variabila, pentru ca nu am citit-o pe undeva (asadar singura optiune ramasa este sa scriem numele variabilei la care ne referim)
                (*(platitori_array+i))->taxe_de_baza(taxe_persoana);
            
            if((*(platitori_array+i))->get_tip()=="Firma")
                (*(platitori_array+i))->taxe_de_baza(taxe_firma);
        }
    }
    
    if(optiune==3)
    {
        for(int i=0;i<nr_entitati;i++)
            (*(platitori_array+i))->procent_venit();
    }
    
    if(optiune==4)
    {
        float procent_persoana;
        float procent_firma;
        
        float taxe_persoana=0;
        float taxe_persoana_lucru=0;
        
        float taxe_firma=0;
        float taxe_firma_lucru=0;
        
        std::cin>>procent_persoana;
        std::cin>>procent_firma;
        
        for(int i=0;i<nr_entitati;i++)
        {
            taxe_persoana_lucru=0;
            taxe_firma_lucru=0;
            
                if((*(platitori_array+i))->get_tip()=="Persoana Fizica") 
                {
                    taxe_persoana_lucru=(*(platitori_array+i))->taxe_4(procent_persoana);
                    taxe_persoana=taxe_persoana+taxe_persoana_lucru;
                
                    (*(platitori_array+i))->afisare_nume();
                    std::cout.precision(2);
                    std::cout<<std::fixed<<taxe_persoana_lucru<<std::endl;
                }
        
                if((*(platitori_array+i))->get_tip()=="Firma")
                {
                    taxe_firma_lucru=(*(platitori_array+i))->taxe_4(procent_firma);
                    taxe_firma=taxe_firma+taxe_firma_lucru;
                
                    (*(platitori_array+i))->afisare_nume();
                    std::cout.precision(2);
                    std::cout<<std::fixed<<taxe_firma_lucru<<std::endl;
                }
        }
        
        std::cout.precision(2);
        std::cout<<std::fixed<<taxe_persoana+taxe_firma<<std::endl;
    }
}
