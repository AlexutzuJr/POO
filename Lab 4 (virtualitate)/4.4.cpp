/* Se dă codul din funcția main. De asemenea, se dă și clasa abstractă Poligon. Să se implementeze toate clasele necesare, conform diagramei UML de mai jos.

Triunghi către Poligon
Patrat către Dreptunghi care merge către Patrulater care merge către Poligon

Rularea programului principal trebuie să afișeze următoarele rezultate:
2.90474 9
9 12
24 22 */


#include <iostream>
#include <cmath>
#include <string>
#include <limits>

//Clasa de Baza
class Poligon{
    
    //Functii
    public:
        virtual float aria()=0;
        virtual float perimetru()=0;
        virtual ~Poligon(){}
};


// TODO: adaugati clasele aici


//Clasa Derivata din Poligon
class Triunghi:public Poligon{
    
    //Date membre
    protected:
        int latura_1;
        int latura_2;
        int latura_3;
    
    //Constructor
    public:
        
        //Constructor Gol
        Triunghi(){}
        
        //Constructor cu Lista de Initializare
        Triunghi(int latura_1, int latura_2, int latura_3): latura_1(latura_1), latura_2(latura_2), latura_3(latura_3){}
    
    //Functii
    float aria(){
        
        float semiper;
        semiper=(latura_1+latura_2+latura_3)/2.0;
        
        //Formula Heron
        return sqrt(semiper*(semiper-latura_1)*(semiper-latura_2)*(semiper-latura_3));
        
    }
    
    float perimetru(){
        
        return float(latura_1+latura_2+latura_3);
    }
    
    ~Triunghi(){}
    
};

//Clasa Derivata din Poligon
class Patrulater:public Poligon{
    
    //Date membre
    protected:
        int latura_1;
        int latura_2;
        int latura_3;
        int latura_4;
    
    //Constructor
    public:
    
        //Constructor Gol
        Patrulater(){}
        
        //Constructor cu Lista de Initializare
        Patrulater(int latura_1, int latura_2, int latura_3, int latura_4): latura_1(latura_1), latura_2(latura_2), latura_3(latura_3), latura_4(latura_4){}
    
    //Functii
    virtual float aria()=0;
    virtual float perimetru()=0;
    virtual ~Patrulater(){}
    
};


//Clasa Derivata din Patrulater
class Dreptunghi:public Patrulater{
    
    
    //Constructor
    public:
    
        //Constructor Gol
        Dreptunghi(){}
        
        //Constructor cu Lista de Initializare
        Dreptunghi(int latura_1, int latura_2): Patrulater(latura_1, latura_2, latura_1, latura_2){}
    
    //Functii
    float aria(){
        return float(latura_1*latura_2);
    }
    
    float perimetru(){
        return float(2*(latura_1+latura_2));
    }
    
    ~Dreptunghi(){}
    
    
};



//Clasa Derivata din Dreptunghi
class Patrat:public Dreptunghi{
    
    
    //Constructor
    public:
    
        //Constructor Gol
        Patrat(){}
        
        //Constructor cu Lista de Initializare
        Patrat(int latura_1): Dreptunghi(latura_1, latura_1){}
    
    //Functii
    float aria(){
        return float(latura_1*latura_1);
    }
    
    float perimetru(){
        return float(4*latura_1);
    }
    
    ~Patrat(){}
};



//Functia main
int main(){
    Poligon *p[3] = {new Triunghi(2, 3, 4), new Patrat(3), new Dreptunghi(3, 8)};
    for (int i=0; i<3; i++){
        std::cout << p[i]->aria() << " " << p[i]->perimetru() << std::endl;
        delete p[i];
    }
    return 0;
}
