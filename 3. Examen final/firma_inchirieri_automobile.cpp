#include <iostream>
#include <string.h>
#include <iomanip>
#include <tgmath.h>
using namespace std;

class Automobil
{
    protected:
        string tip;
        string nume;
        int cap;
        int viteza_med;

    public:
        Automobil(string tip, string nume,int cap,int viteza_med):tip(tip), nume(nume), cap(cap), viteza_med(viteza_med) {} 

    virtual void afisare() {}
    virtual void grup_pers(int g) {}
    virtual void durata_drum(int lung,int durata) {}
    virtual float coeficient_poluare(int g)=0;
    string getter() {return nume;}

};


class Masina: public Automobil 
{
    public:    
        Masina(string tip, string nume,int cap,int viteza_med): Automobil(tip,nume,cap,viteza_med) {}

    void afisare()
    {
        cout<<nume<<endl;
        cout<<cap<<endl;
        cout<<viteza_med<<endl;
    }
    
    void grup_pers(int g)
    {
        int a=0;
      
          if(g%cap!=0)
            a++;
            a=a+g/cap;
      
            cout<<nume<<endl;
            cout<<a<<endl;
    }
    
    void durata_drum(int lung,int durata)
    {
        if(lung/durata <= viteza_med)
        {  
            float durata_noua;
            durata_noua =(float) lung/viteza_med;
          
            cout<<nume<<endl;
            cout<<fixed<<setprecision(2)<<durata_noua<<endl;
        }
    }

    float coeficient_poluare(int g) 
    {
        float coef;
        int nr;
        nr = g/cap;
      
        if(g%cap==0) 
        {
          coef =nr*((float)viteza_med/100 + 1.0);
        }
        else 
          coef = nr*((float)viteza_med/100 + 1.0)+(float)viteza_med/100 + (float)(g%cap)/cap;
      
        return coef;
    }
    
};


class Autocar: public Automobil{
  
public:
  
    Autocar(string tip, string nume,int cap,int viteza_med): Automobil(tip,nume,cap,viteza_med) {}

    void afisare()
    {
        cout<<nume<<endl;
        cout<<cap<<endl;
        cout<<viteza_med<<endl;
    }

    void grup_pers(int g)
    {
        int a=0;
      
        if(g%cap!=0)
          a++;
          a=a+g/cap;
      
          cout<<nume<<endl;
          cout<<a<<endl;
    }

    void durata_drum(int lung,int durata)
    {  
        if(lung/durata <= viteza_med)
        {   
            float durata_noua;
            durata_noua =(float) lung/viteza_med;
          
            cout<<nume<<endl;
            cout<<fixed<<setprecision(2)<<durata_noua<<endl;
        }
    }

    float coeficient_poluare(int g) 
    {
        float coef;
        float e;
        int nr = g/cap;
      
        if(g%cap!=0) nr++;

        e=(2.0*g)/cap;
        coef = nr*(float)viteza_med/20.0 + pow(2.71,e); 
   
        return coef;
    }
    
};

class FirmaInchieri
{
    private:
        Automobil **a ;
        int nr_masini;

    public:
        FirmaInchieri ( Automobil **aut, int nr_masini) :nr_masini(nr_masini)
    {
        
        a = new Automobil *[nr_masini];
      
        for(int i=0; i<nr_masini;i++)
            *(a+i) = *(aut+i);
    }
       
};



int main()
{      
    int t;
    int nr_masini;  
    string tip;
    string nume;
    int cap;
    int viteza_med; //km/h
        
    cin>>t;
    cin>>nr_masini;
        
    Automobil **aut =nullptr;
    aut = new Automobil *[nr_masini];
      
        for(int i=0;i<nr_masini;i++)
        {    
            
            cin>>tip;
            cin.ignore();
            getline(cin,nume);
            cin>>cap;
            cin>>viteza_med;
            
            if(tip=="Masina")
            {
                *(aut+i) = new Masina(tip,nume,cap,viteza_med);
            }
          
            if(tip=="Autocar")
            {
                *(aut+i) = new Autocar(tip,nume,cap,viteza_med);
            }
        }

  
    if(t==1)
    {
        for(int i=0;i<nr_masini;i++)
        {
            (*(aut+i))->afisare();
        }
    }
    
    if(t==2)
    {
        int grup;
        cin>>grup;
        
         for(int i=0;i<nr_masini;i++)
        {
            (*(aut+i))->grup_pers(grup);
        }
         
    }
    
    if(t==3)
    {
        int lungime; //km
        int durata; //ore
        cin>>lungime;
        cin>>durata;
           
        for(int i=0;i<nr_masini;i++)
        {
            (*(aut+i))->durata_drum(lungime,durata);
        }
    }
    
    if(t==4)
    {
        int grup;
        cin>>grup;
        float v[10][2];
      
        for(int i=0;i<nr_masini;i++)
        {
            v[i][0] = (*(aut+i))->coeficient_poluare(grup);
            v[i][1] =(float) i;
        }
            
        for(int i=1;i<nr_masini;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(v[i][0]<v[j][0])
                {
                    int copie;
                    copie=v[i][0];
                    v[i][0]=v[j][0];
                    v[j][0]=copie;
                     copie=v[i][1];
                    v[i][1]=v[j][1];
                    v[j][1]=copie;
                }
            }
        }
           
         for(int i=0;i<nr_masini;i++)
         {
         cout<<(*(aut+(int)v[i][1]))->getter()<<endl;
         }
    }      
    
    return 0;
}
