#include <iostream>
#include <string>

class Hotel
{
    protected:
        int nr;
        std::string tip;
        int nr_persoane;
        float pret;
        
    public:
        Hotel(int nr, std::string tip, int nr_persoane, float pret): nr(nr), tip(tip), nr_persoane(nr_persoane), pret(pret) {}
    
    int get_nr_persoane(){ return this->nr_persoane; }
    float get_pret(){ return this->pret; }
    
    virtual void afisare() {} //in clasa de baza facem neaparat functia de afisare care este de tip "virtual", adica este mostenit implicit de clasele derivate
    virtual int capacitate(){ return 0; } //functie pur virtuala (curs 3, pag. 48), deci trebuie suprascrisa in clasele derivate
};


class Single: public Hotel
{
    public:
        Single(int nr, std::string tip, int nr_persoane, float pret): Hotel(nr, tip, nr_persoane, pret) {}
        
    void afisare()
    {
        std::cout<<nr<<" "<<tip<<" "<<nr_persoane<<" "<<pret<<std::endl;
    }
    
    int capacitate()
    {
        return 1; //returneaza valoarea 1, corespunzatoare camerei Single
    }
};


class Twin: public Hotel
{
    public:
        Twin(int nr, std::string tip, int nr_persoane, float pret): Hotel(nr, tip, nr_persoane, pret) {}
        
    void afisare()
    {
        std::cout<<nr<<" "<<tip<<" "<<nr_persoane<<" "<<pret<<std::endl;
    }
    
    int capacitate()
    {
        return 2; //de astea nu ni se spunea nimic (cat ar trebui sa returneze) pana la ultimul subpunct, asa ca puteam pune orice valoare (nu afecta cu nimic restul subpunctelor; in plus nu aveam de unde sa stim cat trebuie sa returnam)
    }
};


class Double: public Hotel
{
    public:
        Double(int nr, std::string tip, int nr_persoane, float pret): Hotel(nr, tip, nr_persoane, pret) {}
        
    void afisare()
    {
        std::cout<<nr<<" "<<tip<<" "<<nr_persoane<<" "<<pret<<std::endl;
    }
    
    int capacitate()
    {
        return 2;
    }
};


class Triple: public Hotel
{
    public:
        Triple(int nr, std::string tip, int nr_persoane, float pret): Hotel(nr, tip, nr_persoane, pret) {}
        
    void afisare()
    {
        std::cout<<nr<<" "<<tip<<" "<<nr_persoane<<" "<<pret<<std::endl;
    }
    
    int capacitate()
    {
        return 3;
    }
};



int main()
{
    int nr;
    std::string tip;
    int nr_persoane;
    float pret;
    
    Hotel **camera_array=nullptr; //facem un array de obiecte (toate pot sa fie de o clasa diferita)
    camera_array=new Hotel*[30]; //folosim alocare dinamica (curs 2, pag 61); nr corespunde clasei Hotel, deci vom stoca efectiv un numar in vector, nu o variabila
    
    int k=0; //variabila de lucru care pune pe pozitii; practic acest k va pointa catre numarul de elemente din matrice (30, aici); deoarece aceasta merge dintre catre pointer, nu mai trebuie citita separat
    
    int optiune;

    
    do
    { //trebuie sa facem cu "do", pentru ca avem acel "-1" care corespunde opririi programului
        std::cin>>optiune; //trebuie neaparat citit inauntru (altfel vom avea bucla infinita)
        
        if(optiune==1)
        { 
            std::cin>>nr;
            std::cin>>tip;
            std::cin>>nr_persoane;
            std::cin>>pret;
        
                if(tip=="single") //cu "s" mic, deoarece asa apare la "input"
                    (*(camera_array+(k++)))=new Single(nr, tip, nr_persoane, pret); //punem elementele in obiect
                
                if(tip=="twin")
                    (*(camera_array+(k++)))=new Twin(nr, tip, nr_persoane, pret);
                
                if(tip=="double")
                    (*(camera_array+(k++)))=new Double(nr, tip, nr_persoane, pret);
                
                if(tip=="triple")
                    (*(camera_array+(k++)))=new Triple(nr, tip, nr_persoane, pret);
        }
        
        if(optiune==2)
        {
            for(int i=0;i<k;i++)
                (*(camera_array+i))->afisare();
        }
        
        if(optiune==3)
        {
            float s=0; //il declaram in afara buclei, pentru a il putea apela si pentru afisare
            
            for(int i=0;i<k;i++)
            {
                if((*(camera_array+i))->get_nr_persoane()>0) //o camera este considerata ocupata daca in ea este cazata cel putin o persoana (vezi cerinta); iar noi asta cautam sa calculam (camerele ocupate)
                    {
                        s++; //daca numarul de persoane e mai mare ca 0, atunci s se incrementeaza (va fi diferit de 0); practic va fi 5, deoarece va lua la rand toate camerele care au nr de persoane mai mare ca 0, si le va aduna pe rand
                    }
            }
            //in bucla "for", pentru fiecare camera din vectorul "camera_array", se verifica daca exista cel putin o persoana cazata in camera, cu ajutorul getter-ului, daca exista cel putin o persoana cazata in camera respectiva, "s" se incrementeaza cu 1, dupa parcurgerea tuturor camerelor din vector, valoare "s" reprezinta numarul de camere ocupate (5)
            s=s/k*100; //"k" reprezinta numarul maxim de camere citite, aici 7 (vezi "for")
            
            std::cout.precision(2);
            std::cout<<std::fixed<<s<<std::endl;
        }
        
        if(optiune==4)
        {
            int s=0;
            
            for(int i=0;i<k;i++)
                if((*(camera_array+i))->get_nr_persoane()==0) //cautam camerele disponibile (adica cu 0 persoane, vezi la "input" si motivul pentru care ni s-au dat fix alea)
                { //putem privi "(*(camera_array+i))->returnare()" ca un "c[i].returnare()", e acelasi lucru doar ca este o matrice
                    s=s+(*(camera_array+i))->capacitate(); //prin apelul functiei ne luam valorile, iar adunarea lui "s" este folosita ca un fel de "buffer"
                }
                    
            std::cout<<s<<std::endl; //neaparat trebuie sa afisam valoarea, nefiind una prestabilita
        }
        
        if(optiune==5)
        { //sortare
            int v[30][3];
        
            for(int i=0;i<k;i++)
            {
                v[i][2]=i;
                v[i][0]=(*(camera_array+i))->capacitate();
                v[i][1]=(*(camera_array+i))->get_pret();
            }
                  
            for(int i=1;i<k;i++)
            {
                for(int j=0;j<i;j++)
                {
                    if(v[i][0]<v[j][0])
                    {
                        int cop;
                        cop=v[i][0];
                        v[i][0]=v[j][0];
                        v[j][0]=cop;
                        cop=v[i][1];
                        v[i][1]=v[j][1];
                        v[j][1]=cop;
                        cop=v[i][2];
                        v[i][2]=v[j][2];
                        v[j][2]=cop;
                    }
                    
                    if(v[i][0]==v[j][0])
                        if(v[i][1]<v[j][1])
                        {
                            int cop;
                            cop=v[i][0];
                            v[i][0]=v[j][0];
                            v[j][0]=cop;
                            cop=v[i][1];
                            v[i][1]=v[j][1];
                            v[j][1]=cop;
                            cop=v[i][2];
                            v[i][2]=v[j][2];
                            v[j][2]=cop;
                        }
                }
            }
            
            for(int i=0;i<k;i++)
                (*(camera_array+v[i][2]))->afisare();
        }
        
        if(optiune==-1)
        {
            return 0; //oprim programul
        }
    } 
    
    while(1); //cu acest "while", terminam "do-ul", si deci programul
}
