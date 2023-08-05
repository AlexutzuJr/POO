#include <iostream>
#include <string>

class Portofel
{
    private:
        float sold_disponibil;
        
    public:
        void init(float sold_disponibil)
        {
            this->sold_disponibil=sold_disponibil;
        }


    void afisare()
    {
        std::cout<<sold_disponibil<<std::endl; 
    }
    
    float get_sold_disponibil(){ return this->sold_disponibil; }
    
};


class Criptomoneda
{
    private:
        std::string nume_criptomoneda;
        float valoare_fractionara;
        float valoare_curenta;
        
    public:
        void init1(std::string nume_criptomoneda, float valoare_fractionara, float valoare_curenta)
        {//atentie la numele lui "void init1" (trebuie sa fie diferit fata de cel din clasa Portofel)
            this->nume_criptomoneda=nume_criptomoneda;
            this->valoare_fractionara=valoare_fractionara;
            this->valoare_curenta=valoare_curenta;
        }
        
    void afisare1() //acelasi lucru si pentru functiile de afisare
    {
        std::cout<<nume_criptomoneda<<" ";
        std::cout<<valoare_fractionara<<" ";
        std::cout<<valoare_curenta<<std::endl;
    }
    
    void afisare2(){}
    
    std::string get_nume_criptomoneda(){ return this->nume_criptomoneda; }
    float get_valoare_fractionara(){ return this->valoare_fractionara; }
    float get_valoare_curenta(){ return this->valoare_curenta; }
    
    void set_valoare_fractionara(float valoare_fractionara){ this->valoare_fractionara=valoare_fractionara; } 

};



int main()
{
    float sold_disponibil_n;
    std::string nume_criptomoneda_n;
    float valoare_fractionara_n;
    float valoare_curenta_n;
    
    Portofel p; //nu e vector, pentru ca are doar un element, si nu il citim intr-un "for"
    Criptomoneda c[20];
    
    std::cin>>sold_disponibil_n; //apare separat la afisare, deci nu il punem in "for"
    p.init(sold_disponibil_n);
    
    int n;
    std::cin>>n;
    
    int i;
    
    for(i=0;i<n;i++)
    {
        std::cin>>nume_criptomoneda_n; //citim in ordinea initializarii, de obicei, dar pot fi cazuri in care, la afisare (input) sa nu apara in ordinea citirii, deci trebuie sa vedem noi, in ce ordine trebuie citite
        std::cin>>valoare_fractionara_n;
        std::cin>>valoare_curenta_n;
        c[i].init1(nume_criptomoneda_n, valoare_fractionara_n, valoare_curenta_n); //pentru a putea afisa toate elementele vectorului din "for" (si a nu se citi doar primul de "n" ori), avem nevoie de un "[i]" la initializare, si deci obiectul clasei Criptomoneda va fi si el un vector; avem "[i]" si nu altceva (de exemplu, "[j]") pentru ca avem "for i=0..." 
    }//functia de initializare o facem respectand ordinea citirii 
    
    int comanda;
    std::cin>>comanda;

    //totul se executa "in main", deci nu inchidem bucla     
    if(comanda==1)
    {//atentie la bucla
        std::cout<<std::fixed;
        std::cout.precision(2);
        p.afisare();
        
        for(i=0;i<n;i++)
            c[i].afisare1();
    }
    
    if(comanda==2)
    {
        std::string nume_cripto; //nu degeaba il citim, cel mai probabil trebuie folosit intr-o conditie, pentru a identifica tipul criptomonedei
        float val_frac; //desi par nefolositoare, trebuie neaparat initializate si citite, deoarece daca ne uitam la afisari, apar si ele, si, de asemenea, ne vom folosi de ele pentru a le stoca in alte variabile (cel mai probabil)
        
        std::cin>>nume_cripto;
        std::cin>>val_frac;
        
        for(i=0;i<n;i++)
        {
            if(nume_cripto==c[i].get_nume_criptomoneda()) //cauta numele criptomonezii din lista, de care avem nevoie (Ethereal/Maincoin); pentru a stii sa se duca la acestea, va trebui sa treaca prin urmatoarele "if-uri" (impuse si in cerinta)
            {
                if(val_frac*c[i].get_valoare_curenta()<=p.get_sold_disponibil()) //ne uitam la afisari si vedem ca "12" apare la "input" dupa "Ethereal" la final, ceea ce inseamna clar ca acesta va fi "val_frac", acesta este inmultit cu "426", care daca ne uitam sub "Ethereal" este dupa acesta si "78.3", ceea ce inseamna ca este "valoare_fractionara" din clasa, acesta va fi comparat cu soldul disponibil din clasa Portofel (deoarece ni se spune ca soldul este suficient)
                {
                    float r; //vom stoca noua valoare a valorii fractionare in "r"
                    r=c[i].get_valoare_fractionara()+val_frac; //la valoarea fractionara curenta, se adauga noua valoare 
                    c[i].set_valoare_fractionara(r); //setam noua valoare fractionara prin "r-ul" tocmai calculat
                    //mergea si sa facem "c[i].set_valoare_fractionara()" (si sa ii returnam direct in setter +12), dar aici nu este eficient, deoarece vom modifica aceasta valoare ulterior, pentru urmatoarea afisare
                    //aici nu merge sa ii dam "cout" lui "r" direct, deoarece nu cautam doar o valoare, ci ne intereseaza si textul, care este dat doar de afisarea in sine, iar ceea ce va fi afisat, va fi gasit exact, deoarece avem conditiile impuse
                    std::cout<<std::fixed;
                    std::cout.precision(2);
                    c[i].afisare1();
                }
                else //puteam scrie si "if(val_frac*c[i".get_valoare_curenta()>p.get_sold_disponibil())", dar acest lucru practic se subintelege (de asemenea, daca scriem doar "else", scriem mai putin)
                {
                    float a; //valoarea achizionata o vom stoca in "a"
                    a=p.get_sold_disponibil()/c[i].get_valoare_curenta(); //mare atentie, la ce avem exact la "input", pentru fiecare valoare
                    float x; //noua valoare fractionara o vom stoca in "x"
                    x=a+c[i].get_valoare_fractionara();
                    c[i].set_valoare_fractionara(x);
                    std::cout<<std::fixed;
                    std::cout.precision(2);
                    c[i].afisare1();
                }
            }
        }
    }
    
    if(comanda==3)
    {
        std::string nume_cripto;
        float val_frac;
        
        std::cin>>nume_cripto;
        std::cin>>val_frac;
        
        for(i=0;i<n;i++)
        {
            if(nume_cripto==c[i].get_nume_criptomoneda())
            {
                if(val_frac>c[i].get_valoare_fractionara()) //deoarece se doreste a se vinde mai multe decat sunt 
                {//daca nu afiseaza ceea ce trebuie, sau afiseaza prea multe variante, cel mai probabil am uitat sa punem o conditie
                    c[i].set_valoare_fractionara(0); //puteam egala si "val_frac" (atentie, trebuie sa il facem pe "val_frac" float, pentru acest lucru) cu "get_valoare_fractionara" (nu si invers, deoarece nu putem avea intai un getter in stanga egalului), apoi sa facem un "float" in care le scadem intre ele, iar apoi sa facem setter-ul in functie de "float-ul" calculat 
                    std::cout<<std::fixed;
                    std::cout.precision(2);
                    c[i].afisare1();
                }
                else
                {
                    float u;
                    u=c[i].get_valoare_fractionara()-val_frac; //se vede clar ca 200 reprezinta "val_frac", fiind ultimul care apare la "input" si ultimul citit 
                    c[i].set_valoare_fractionara(u);
                    std::cout<<std::fixed;
                    std::cout.precision(2);
                    c[i].afisare1();
                }
            }
        }
    }
    
};
