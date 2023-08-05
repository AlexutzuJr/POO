#include <iostream>
#include <string>

class Angajat //clasa de baza
{
    protected: //date membre
        std::string nume; //"#" este pentru protected (vezi curs 3, pag 14)
        float salariu_baza;
        std::string functie;
        float procent_taxe_salariu;
        
    public: //constructor cu lista de initializare
        Angajat(std::string nume, float salariu_baza, std::string functie, float procent_taxe_salariu): nume(nume), salariu_baza(salariu_baza), functie(functie), procent_taxe_salariu(procent_taxe_salariu) {}

    //setters, getters si functii
    virtual float get_salariu_net(float x) { return 0; } //"+" corespunde functiilor membre; fata de exemplul din laboratoare, nu uitam sa punem "virtual" in fata (fiind in clasa de baza), "x" dupa "float" in paranteza, si bineinteles "return 0" la final
    virtual float get_salariu_brut() { return 0; } 
    virtual std::string get_nume() { return nume; } //la "string" returnam numele variabilei
    virtual void marire_salariu(float x) {} //deoarece e functie "void", nu returneaza nimic; aici avem nevoie de acel "float x", pentru a ne putea folosi de acele valori abia citite (prestabilite)
    
    virtual void afisare() {}
    virtual void calcul_salarii() {}
    
    std::string get_functie(){ return this->functie; }

    virtual ~Angajat(){ std::cout<<"Destructor Angajat"<<std::endl; } //destructor
};


class Analist: public Angajat //clasa derivata 1 din baza
{
    public:
        Analist(std::string nume, float salariu_baza, std::string functie, float procent_taxe_salariu): Angajat(nume, salariu_baza, functie, procent_taxe_salariu) {}
        
    void afisare()
    {
        std::cout<<nume<<std::endl;
        std::cout<<functie<<std::endl;
    }
    
    void calcul_salarii() //atentie mare, sa numim la fel functiile din clasele derivate
    {
        int salariu_brut;
        int salariu_net;
        
        salariu_brut=salariu_baza; //pe baza formulei generale data in cerinta, inlocuim (evident) cu ce variabile avem, in functie de clasa in care scriem functia; de asemenea, deoarece valoarea de la "input" este aceeasi cu cea de la "output", nu mai trebuie sa adunam cu nimic, aici
        salariu_net=salariu_baza*(100-40)/100; //inlocuim variabila "procent_taxe_salariu" cu "40" pentru ca asa ni se specifica in cerinta
        
        std::cout<<nume<<std::endl; //pentru chestiile astea ne uitam la ce este afisat la "output", deoarece in cerinta (nu stiu de ce), nu ni se spune explicit ca asta ar trebui sa se afiseze
        std::cout<<"Salariu brut: "<<salariu_brut<<std::endl; //"salariu_brut" e pus ca sa isi poata lua valoarea din variabila
        std::cout<<"Salariu Net: "<<salariu_net<<std::endl;
    }
    
    void marire_salariu(float x) //"x" tine locul aici, lui "procent_marire_analist"
    {
        int salariu_vechi;
        int salariu_nou;
        
        salariu_vechi=salariu_baza;
        salariu_nou=salariu_baza+(salariu_baza*x)/100; //practic se pastreaza formula (deoarece nu se spune nimic de ea), doar ca se mai aduna "salariu_baza", iar in loc de acele procente date, folosim "x" 
        
        std::cout<<nume<<std::endl;
        std::cout<<"Salariu de baza vechi: "<<salariu_vechi<<std::endl;
        std::cout<<"Salariu de baza nou: "<<salariu_nou<<std::endl;
    }
    
    ~Analist(){ std::cout<<"Destructor Analist"<<std::endl; } //destructor
};


class Programator: public Analist //clasa derivata 2 din clasa derivata 1
{
    protected:
        float procent_deducere_salariu_it;
        
    public: //aici se mostenesc datele membre clasei anterioare, la care se adauga cele noi (in caz ca exista), iar cele noi trebuie initializate de la 0
        Programator(std::string nume, float salariu_baza, std::string functie, float procent_taxe_salariu, float procent_deducere_salariu_it): Analist(nume, salariu_baza, functie, procent_taxe_salariu), procent_deducere_salariu_it(procent_deducere_salariu_it) {}
    
    void afisare()
    {
        std::cout<<nume<<std::endl;
        std::cout<<functie<<std::endl; 
    }
    
    void calcul_salarii()
    {
        int salariu_brut;
        int salariu_net;  
        
        salariu_brut=salariu_baza; 
        salariu_net=salariu_baza*(100-40+10)/100; 
        
        std::cout<<nume<<std::endl;
        std::cout<<"Salariu brut: "<<salariu_brut<<std::endl;
        std::cout<<"Salariu Net: "<<salariu_net<<std::endl;
    }
    
    void marire_salariu(float x)
    {
        int salariu_vechi;
        int salariu_nou;
        
        salariu_vechi=salariu_baza;
        salariu_nou=salariu_baza+(salariu_baza*x)/100;
        
        std::cout<<nume<<std::endl;
        std::cout<<"Salariu de baza vechi: "<<salariu_vechi<<std::endl;
        std::cout<<"Salariu de baza nou: "<<salariu_nou<<std::endl;
    }
    
    ~Programator(){ std::cout<<"Destructor Programator"<<std::endl; } //destructor
};


class LiderEchipaProgramare: public Programator //clasa derivata 3 din derivata 2
{
    protected:
        float bonus_vechime_functie;
        int vechime_functie;
        
    public:
        LiderEchipaProgramare(std::string nume, float salariu_baza, std::string functie, float procent_taxe_salariu, float procent_deducere_salariu_it, float bonus_vechime_functie, int vechime_functie): Programator(nume, salariu_baza, functie, procent_taxe_salariu, procent_deducere_salariu_it), bonus_vechime_functie(bonus_vechime_functie), vechime_functie(vechime_functie) {}
        
    void afisare()
    {
        std::cout<<nume<<std::endl;
        std::cout<<functie<<std::endl;  
    }
    
    void calcul_salarii()
    {
        int salariu_brut;
        int salariu_net;
        
        salariu_brut=salariu_baza+(500*vechime_functie); //inlocuim "bonus_vechime_functie" cu "500"  
        salariu_net=(salariu_baza+500*vechime_functie)*(100-40+10)/100;
        
        std::cout<<nume<<std::endl;
        std::cout<<"Salariu brut: "<<salariu_brut<<std::endl;
        std::cout<<"Salariu Net: "<<salariu_net<<std::endl;
    }
    
    void marire_salariu(float x)
    {
        int salariu_vechi;
        int salariu_nou;
        
        salariu_vechi=salariu_baza;
        salariu_nou=salariu_baza+(salariu_baza*x)/100;
        
        std::cout<<nume<<std::endl;
        std::cout<<"Salariu de baza vechi: "<<salariu_vechi<<std::endl;
        std::cout<<"Salariu de baza nou: "<<salariu_nou<<std::endl;
    }
    
    ~LiderEchipaProgramare(){ std::cout<<"Destructor LiderEchipaProgramare"<<std::endl; } //destructor
};


class FirmaProgramare
{ //clasa asta nu face nimic, dar ne cere s-o scriem
    private:
        Angajat **angajati; //curs 2, pag 40 (doar ca in loc de int *note avem Note **note)
        int nr_angajati;
        
    public:
        FirmaProgramare(Angajat **angajati, int nr_angajati)
        {
            this->nr_angajati=nr_angajati;
            this->angajati=new Angajat*[nr_angajati]; //in loc de new int[nr_note], vom avea new Note*[nr_note] (pentru ca avem dublu pointer, nu pointer simplu)
            //practic "int-ul" tine locul lui "Angajat*", iar restul ramane neschimbat (ex: int[nr_angajati]<=>Angajat*[nr_angajati] sau int* angajati<=>Angajat** angajati) 
            for(int i=0;i<nr_angajati;i++)
                *(this->angajati+i)=*(angajati+i);
        }
        
    void afiseaza_angajati() {} //aici nu mai e "virtual", pentru ca functia nu se mosteneste si in restul claselor (nu e scrisa in clasa de baza)
    void mareste_salarii(float x, float y, float z) {}
    void promoveaza(std::string x) {}
};



int main() //functia main
{
    //initializam date
    int nr_angajati;
    std::string nume;
    std::string functie; //adica "rolul", oricum putem denumi si altfel variabilele in "main" (doar sa nu facem confuzie)
    float salariu_baza;
    
    std::cin>>nr_angajati;

    
    Angajat **angajat_array=nullptr; //facem array de obiecte (toate pot sa fie de o clasa diferita)
    angajat_array=new Angajat*[nr_angajati]; //folosim alocare dinamica

    int k=0;  //variabila de lucru care pune pe pozitii

    for(int i=0;i<nr_angajati;i++)
    { //generam fiecare obiect
        std::cin.ignore(); //aici il punem in "for" si nu inafara acestuia, pentru ca mai avem niste "if-uri" care se executa in aceeasi bucla
        getline(std::cin, nume);
        std::cin>>functie;
        std::cin>>salariu_baza;
        
        if(functie=="Analist") //cautam functiile care apar la "input"; stim ca "if-ul" e in functie de "functie", uitandu-ne la "input", la a cata variabila e citita acolo
            *(angajat_array+(k++))=new Analist(nume, salariu_baza, functie, 0); //punem 0 unde nu este citita in "main", functia din clasa de baza
            
        if(functie=="Programator")
            *(angajat_array+(k++))=new Programator(nume, salariu_baza, functie, 0, 0); //punem elementele in obiect
            
        if(functie=="LiderEchipaProgramare")
        {
            int vechime_functie;
            std::cin>>vechime_functie;
            
            *(angajat_array+(k++))=new LiderEchipaProgramare(nume, salariu_baza, functie, 0, 0, 0, vechime_functie); //punem 0 unde nu am citit variabilele respective, si tinem cont de pozitia variabilelor citite, din clasa respectiva (fiind o matrice/vector)
        }
    }
    
    int optiune;
    std::cin>>optiune;

    
    if(optiune==1)
    {
        for(int i=0;i<nr_angajati;i++)
            (*(angajat_array+i))->afisare();
    }
    
    if(optiune==2)
    {
        for(int i=0;i<nr_angajati;i++)
            (*(angajat_array+i))->calcul_salarii(); //nu e in functie de ceva pentru ca nu am citit nimic de la tastatura in aceasta "optiune" 
    }
    
    if(optiune==3)
    {
        std::string functie_analist; //acolo zice "functie_in_firma", deci trebuie sa deducem noi ca pentru fiecare functie trebuie sa scriem cate un "string"; aici e folosit pe post de getter
        std::string functie_programator; //de asemenea putem vedea ca sunt mai multe, si din "input"
        std::string functie_lider;
        
        int procent_analist; //la fel si pentru procent; aici e folosit pe post de (float) "x"
        int procent_programator;
        int procent_lider;
        
        std::cin>>functie_analist;
        std::cin>>procent_analist;
        
        std::cin>>functie_programator;
        std::cin>>procent_programator;
        
        std::cin>>functie_lider;
        std::cin>>procent_lider;
        
        for(int i=0;i<nr_angajati;i++)
        { //fiecare functie are procent diferit 
            if((*(angajat_array+i))->get_functie()==functie_analist) //pentru a putea apela "functie" avem nevoie de getter, pentru ca e "protected" (nu degeaba ne-a pus sa citim acel "functie_analist" pentru optiunea asta), asadar d-aia nu am scris "if(functie=="Programator")", ca inainte (plus ca acum apare ceva gen "Programator 10", pe langa acel "Programator" deja citit)
                (*(angajat_array+i))->marire_salariu(procent_analist); //functia_creata(functia_citita)
                
            if((*(angajat_array+i))->get_functie()==functie_programator) //trebuie sa iteram prin matrice, de aceea nu putem scrie, de exemplu, ca la inceput "if(functie=="Programator")"  
                (*(angajat_array+i))->marire_salariu(procent_programator); //argumentul functiei "marire_salariu" e ca sa stie pentru cine sa calculeze salariul
                
            if((*(angajat_array+i))->get_functie()==functie_lider)
                (*(angajat_array+i))->marire_salariu(procent_lider);
        }
    }
    
    if(optiune==4)
    {
        std::string nume_a;
        std::string functie_a;
        
        std::cin.ignore();
        getline(std::cin, nume_a);
        std::cin>>functie_a;
        
        int c; //folosit pe post de contor pentru a cauta persoana promovata
        
        for(int i=0;i<nr_angajati;i++)
            if((*(angajat_array+i))->get_nume()==nume_a) //selectam doar ce e nume, pentru ca la afisare din acea matrice, apare doar numele 
                c=i; //iteram prin matrice
                
        delete (*(angajat_array+c)); //prin asta, setam noua functia si apelam destructorul        
        
        //facem obiect de noua functie promovata, in locul celui sters
        if(functie_a=="Analist")
            *(angajat_array+(c))=new Analist(nume_a, 0, functie_a, 0); //punem elementele in obiect
            
        if(functie_a=="Programator")
            *(angajat_array+(c))=new Programator(nume_a, 0, functie_a, 0, 0);
            
        if(functie_a=="LiderEchipaProgramare")
            *(angajat_array+(c))=new LiderEchipaProgramare(nume_a, 0, functie_a, 0, 0, 0, 0);

        //afisam angajatii
        for(int i=0;i<nr_angajati;i++)
            (*(angajat_array+i))->afisare();
    }
}
