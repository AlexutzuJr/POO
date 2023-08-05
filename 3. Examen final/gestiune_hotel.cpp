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
        
    virtual void afisare() {}
    virtual int capacitate(){ return 0; } 
    
    int get_nr_persoane(){ return this->nr_persoane; }
    float get_pret(){ return this->pret; }
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
        return 1;
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
    
    Hotel **camera_array=nullptr;
    camera_array=new Hotel*[30]; //nr corespunde clasei Hotel, deci vom stoca efectiv un numar in vector, nu o variabila
    
    int k=0;
    
    int optiune;
    
    do
    {
        std::cin>>optiune;
        
        if(optiune==1)
        {
            std::cin>>nr;
            std::cin>>tip;
            std::cin>>nr_persoane;
            std::cin>>pret;
        
                if(tip=="single")
                    (*(camera_array+(k++)))=new Single(nr, tip, nr_persoane, pret);
                
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
            s=s/k*100; //k reprezinta numarul maxim de camere citite, aici 7 (vezi "for")
            
            std::cout.precision(2);
            std::cout<<std::fixed<<s<<std::endl;
        }
        
        if(optiune==4)
        {
            int s=0;
            
            for(int i=0;i<k;i++)
                if((*(camera_array+i))->get_nr_persoane()==0) //cautam camerele disponibile (adica cu 0 persoane, vezi la "input" si motivul pentru care ni s-au dat fix alea)
                {
                    s=s+(*(camera_array+i))->capacitate(); //prin apelul functiei ne luam valorile, iar adunarea lui "s" este folosita ca un fel de "buffer"
                }
                    
            std::cout<<s<<std::endl; //neaparat trebuie sa afisam valoarea, nefiind una prestabilita
        }
        
        if(optiune==5)
        {//sortare
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
            return 0;
        }
    }
    
    while(1==1);
}
