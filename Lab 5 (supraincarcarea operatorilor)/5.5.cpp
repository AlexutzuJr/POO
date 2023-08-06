/* Pornind de la o clasă de bază Poligon, se vor crea două derivate: Triunghi și Paralelogram. De asemenea, se cunoaște că există funcția virtual float Poligon::aria()=0;
Se citește de la tastatură o valoare întreagă reprezentând numărul de Triunghiuri și numărul de Paralelograme ale căror laturi urmează a fi citite. Să se afișeze pe ecran Poligoanele, în ordinea ariei lor, câte un Poligon pe 
rând. Afișarea unui Poligon coincide cu afișarea valorilor laturilor sale, în aceeași ordine în care au fost citite, separate de un spațiu liber. */

#include<iostream>
#include<vector>
#include<algorithm>



class Poligon{

   
public:
Poligon(){};
    virtual float aria()=0;
    virtual void afisare()=0;
   
};


class Triunghi:public Poligon{
    
    
    private:
    
        int h;
        int b;
    public:
       Triunghi(int h,int b):b(b),h(h){};
       float aria(){
           return(h*b/2);
       }
       void afisare()
       {
           std::cout<<h<<' '<<b<<std::endl;
       }
};

class Paralelogram:public Poligon
{ private:
    int l1;
    int l2;
    public:
    Paralelogram(int l1,int l2):l1(l1),l2(l2){};
    float aria(){
        return(l1*l2);
    }
        void afisare(){       std::cout<<l1<<' '<<l2<<std::endl;
       }
};
 
 bool comp(Poligon *a,Poligon  *b)
 {
     return(a->aria()<b->aria());
 }
int main()
{
    int n;
    float a,b;std::cin>>n;
    std::vector<Poligon*> x;
    for(int i=0;i<n;i++)
    {    std::cin>>a>>b;
        Poligon *X=new Triunghi(a,b);
        x.push_back(X);
       // x[0]->afisare();
        
    }
    for(int i=0;i<n;i++)
    {
        std::cin>>a>>b;
        Poligon *Y=new Paralelogram(a,b);
        x.push_back(Y);
    }
    
    sort(x.begin(),x.end(),comp);
    for(auto a:x)
    {
        a->afisare();
    }
    
    
    return 0;
}
