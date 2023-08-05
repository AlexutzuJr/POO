#include <iostream>
#include <string>

class Card_calatorie
{
    protected:
        std::string tip;
        int id;
    
    public: 
        Card_calatorie(std::string tip, int id): tip(tip), id(id) {}
        
    virtual void afisare() {}
    virtual void incarcare(int x) {}
    virtual void validare(int x) {}
    virtual void incarcare_4(int x) {}
    virtual void descarcare_4(int x) {}
    
    int get_id(){ return this->id; }
    std::string get_tip(){ return this->tip; }
    
    virtual int get_sc(){ return 0; } //GETTER pentru sold sau numar calatorii (aparent putem face un getter pentru o variabila care nu a fost declarata anterior)
};


class Card_autobuz: public Card_calatorie
{
    protected:
        int sold;
        int moment_ultima_validare; //"in ordinea in care au fost citite la tastatura", deci de aici deducem ca ar trebui sa fie dupa "sold", si nu in clasa de baza
        
    public:
        Card_autobuz(std::string tip, int id, int sold, int moment_ultima_validare): Card_calatorie(tip, id), sold(sold), moment_ultima_validare(moment_ultima_validare) {}
        
    int get_sc(){ return this->sold; } //cand declaram un getter de la 0 (cu "virtual") in clasa de baza, clasele derivate il mostenesc si el

    void afisare()
    {
        std::cout<<id<<" "<<tip<<" "<<sold<<" "<<moment_ultima_validare<<std::endl;
    }
    
    void incarcare(int x)
    {
        sold=sold+x; //aparent daca am initializat deja "int sold", programul tine minte deja aceasta variabila din clasa, si are valoarea prestabilita deja pentru el
    }
    
    void validare(int x)
    {
        if(sold>=3)
        {
            if(x-moment_ultima_validare>90) //"este debitat la momentul ..." ; daca a fost o facuta o validare a cardului cu cel mult 90 de minute inainte
            {
                sold=sold-3;
                moment_ultima_validare=x; //momentul ultimei validari ramane neschimbat (la fiecare validare se introduce momentul validarii) 
            }
        } //sa nu uitam sa inchidem bucla inainte de else!
            
        else
            std::cout<<"Sold insuficient"<<std::endl;
    }
    
    void incarcare_4(int x){ sold=sold+x; }
    void descarcare_4(int x){ sold=sold-x; }
};


class Card_metrou: public Card_calatorie
{
    protected:
        int nr_calatorii;
        int moment_ultima_validare;
        
    public:
        Card_metrou(std::string tip, int id, int nr_calatorii, int moment_ultima_validare): Card_calatorie(tip, id), nr_calatorii(nr_calatorii), moment_ultima_validare(moment_ultima_validare) {}
    
    int get_sc(){return this->nr_calatorii;}
    
    void afisare()
    {
        std::cout<<id<<" "<<tip<<" "<<nr_calatorii<<" "<<moment_ultima_validare<<std::endl;
    }
    
    void incarcare(int x)
    {
        nr_calatorii=nr_calatorii+x;
    }
    
    void validare(int x)
    {
        if(nr_calatorii>=1)
        {
            if(x-moment_ultima_validare>90)
            {
                nr_calatorii=nr_calatorii-1;
                moment_ultima_validare=x;
            }
        }
        
        else 
            std::cout<<"Numar calatorii insuficient"<<std::endl;
    }
    
    void incarcare_4(int x){ nr_calatorii=nr_calatorii+x; }
    void descarcare_4(int x){ nr_calatorii=nr_calatorii-x; }
};



int main()
{
    int nr_carduri;
    std::string tip;
    int id;
    int sold;
    int nr_calatorii;
    
    std::cin>>nr_carduri;
    
    Card_calatorie **card_array=nullptr; //atentie sa numim clasa din care se face "pointarea", la fel ca si clasa de baza!
    card_array=new Card_calatorie*[nr_carduri];
    
    int k=0;
    
    for(int i=0;i<nr_carduri;i++)
    {
        std::cin>>tip;
        std::cin>>id;
        
        if(tip=="a")
        {
            std::cin>>sold;
            
            (*(card_array+(k++)))=new Card_autobuz(tip, id, sold, 0); //pentru ca nu ni s-a spus sa citim "moment_ultima_validare", de asemenea se spune ca va lua valoarea "0", daca nu s-a facut nicio validare (adica daca nu s-a citit de la tastatura, practic)
        }
        
        if(tip=="m")
        {
            std::cin>>nr_calatorii;
            
            (*(card_array+(k++)))=new Card_metrou(tip, id, nr_calatorii, 0);
        }
    }
    
    int optiune;
    
    do
    {
        std::cin>>optiune;
        
        if(optiune==1)
        {
            for(int i=0;i<nr_carduri;i++)
                (*(card_array+i))->afisare();
        }
        
        if(optiune==2)
        {
            int id_2; //e folosit aici ca getter (ca sa stie de la ce "id" sa-si ia valoarea)
            int increment_2; //adica care ia fie "sold_2", fie "nr_calatorii_2" (e folosit aici ca o valoare prestabilita)
            
            std::cin>>id_2;
            std::cin>>increment_2;
            
            for(int i=0;i<nr_carduri;i++)
                if((*(card_array+i))->get_id()==id_2)
                    (*(card_array+i))->incarcare(increment_2); //adaugam incarcarea
        }
        
        if(optiune==3)
        {
            int id_3;
            int moment_3;
            
            std::cin>>id_3;
            std::cin>>moment_3;
            
            for(int i=0;i<nr_carduri;i++)
                if((*(card_array+i))->get_id()==id_3)
                    (*(card_array+i))->validare(moment_3);
        }
        
        if(optiune==4)
         {
            int id_4;
            int id_5;
            int transfer;
            
            std::cin>>id_4;
            std::cin>>id_5;
            std::cin>>transfer;
            
            int c1; //contor de lucru
            int c2;
            
            //salvam pozitia cardului 1 (deoarece avem 2 carduri, nu putem sa le salvam in "i" pe ambele, fiind independente)
            for(int i=0;i<nr_carduri;i++)
            {
                if((*(card_array+i))->get_id()==id_4)
                    c1=i;
            }
                    
            for(int i=0;i<nr_carduri;i++)
            {
                if((*(card_array+i))->get_id()==id_5)
                    c2=i;
            }
            
            if((*(card_array+c1))->get_tip()==(*(card_array+c2))->get_tip()) //verificam daca cardurile sunt de acelasi tip
            {
                if((*(card_array+c1))->get_sc()>=transfer)
                {
                    (*(card_array+c1))->descarcare_4(transfer);
                    (*(card_array+c2))->incarcare_4(transfer);
                }
                else
                    std::cout<<"Transfer nereusit"<<std::endl;
            }
            
            if((*(card_array+c1))->get_tip()!=(*(card_array+c2))->get_tip()) //verificam daca sunt de tip diferit
                std::cout<<"Transfer nereusit"<<std::endl;
        }
        
        if(optiune==5)
        {
            return 0; //pentru a opri bucla infinita, trebuie neaparat sa dam "return 0"
        }
    }
    
    while(1); //uneori se poate intampla sa asteptam mai mult la compilare, la "do - while-urile" astea, asta nu inseamna neaparat ca avem bucla infinita
}
