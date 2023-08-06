/* Se va crea o clasă Segment, care este definită în spațiu de o pereche de puncte în coordonate carteziene în plan tridimensional. Punctele sunt create ca instanțe ale clasei Punct. Să se definească un constructor cu 
6 argumente pentru clasa Segment și o funcție care să calculeze lungimea segmentului. În programul principal se va instanția un obiect de tipul Segment, prin citirea de la tastatură a celor 6 atribute, în ordinea x1, y1,
z1, x2, y2, z2 și se va afișa pe ecran lungimea segmentului, cu 2 zecimale. */


#include <iostream>
#include <math.h>
#include <iomanip>

//Clasa 
class Punct{
    
    friend class Segment;
    //Date membre
    private:
        float x;
        float y;
        float z;
        
    
    //Constructor (acopera toate cazurile de constructor)
    public:
    
        Punct(int x=0, int y=0, int z=0): x(x), y(y), z(z){}
    
    //Setters si Getters
    void set_x(float x){
        this->x = x;
    }
    float get_x(){
        return this->x;
    }
  
    void set_y(float y){
        this->y = y;
    }
    float get_y(){
        return this->y;
    }
    
    void set_z(float z){
        this->z = z;
    }
    float get_z(){
        return this->z;
    }
    
    
    
};


class Segment{
    
    
    //Obiecte 
    private:
        Punct p1;
        Punct p2;
     
        
    //Constructor care acopera 5 tipuri de constructor
    public:
        Segment(float x1=0, float x2=0, float y1=0, float y2=0, float z1=0, float z2=0): p1(x1,y1,z1), p2(x2,y2,z2){}
  

    //Functii
    public:
        void lungime_segment(){
            
            float lungime;
            
            lungime = sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y)+(p2.z-p1.z)*(p2.z-p1.z));
            
            
            //Afisam cu 2 zecimale
            std::cout << std::fixed;
            std::cout << std::setprecision(2);
            std::cout << lungime;
            
        }

};



//Functia main
int main(){
    
    //Initializam Date;
    float s_x1;
    float s_x2;
    float s_y1;
    float s_y2;
    float s_z1;
    float s_z2;
    
    //Citim Date
    std::cin>>s_x1;
    std::cin>>s_y1;
    std::cin>>s_z1;
    std::cin>>s_x2;
    std::cin>>s_y2;
    std::cin>>s_z2;
    
    //Initializare Obiect
    Segment s(s_x1, s_x2, s_y1, s_y2, s_z1, s_z2);
    
    //Lungime Segment
    s.lungime_segment();
    
    return 0;
}
