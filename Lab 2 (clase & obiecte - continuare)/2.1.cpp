/* Să se scrie două clase distincte, Vector și Matrice care să conțină drept date membre un vector de maxim 20 de întregi, respectiv un tablou bidimensional, de dimensiune maximă 20 x 20. Se vor scrie constructorii aferenți celor 2 clase și o funcție membră de afișare 
a elementelor (cel puțin pentru clasa Vector). Se va scrie o funcție de tip friend care să execute înmulțirea dintre un Vector și o Matrice. Funcția va verifica mai întâi dacă operația poate avea loc (numărul de coloane ale vectorului să coincidă cu numărul de linii 
ale matricei). În caz contrar, va afișa mesajul “EROARE” pe ecran. Vectorul este considerat de tipul linie. Toate inițializările din constructori vor fi făcute cu ajutorul listei de inițializare.
Se citesc de la tastatură, de pe linii diferite, următoarele date:
1. un întreg n, reprezentând numărul de elemente ale vectorului;
2. n valori întregi, reprezentând valorile vectorului;
3. doi întregi, m și n, reprezentând numărul de linii, respectiv coloane ale matrice;
4. m x n valori întregi, reprezentând valorile matricei.

Se va afișa pe ecran rezultatul obținut în urma înmulțirii vectorului cu matricea, respectiv "EROARE", în cazul în care înmulțirea nu poate avea loc.

Extensie: funcția friend va întoarce în programul apelant un obiect de tipul Vector drept rezultat.
Extensie 2: atât Vectorul, cât și Matricea, vor stoca valorile în mod dinamic.
Extensie 3: separați declarațiile claselor și definițiile funcțiilor membre în fișiere diferite. Notă: trebuie avute în vedere declarațiile în avans (forward declaration) ale claselor și a funcției friend - discutăm împreună. */


#include <iostream>


//Clasa

class Matrice;

class Vector{
    
    friend class Matrice;
    
    //Date membre
    private:
        int *v;
        int nr_elemente;
    
    //Constructor
    public:
        Vector(int nr_elemente, int *v):nr_elemente(nr_elemente){
            this->v = new int[nr_elemente];
            for(int i=0; i<nr_elemente; i++){
                *(this->v+i)=*(v+i);
            }
        }
        
            
    //Functii
    public:
        void afisare(){
            if(nr_elemente == 0)
                std::cout<<"EROARE";
            
            else{
                for(int i=0; i<this->nr_elemente; ++i){
                std::cout<<*(this->v+i)<<" ";
                }
            }   
        }
        
    //Functii
    friend Vector inmultire(Vector &vec, Matrice &mat);
};



class Matrice{
    
    friend class Vector;
    
    //Date membre
    private:
        int *m;
        int nr_linii;
        int nr_coloane;
    
    //Constructor
    public:
        Matrice(int nr_linii, int nr_coloane, int *m): nr_linii(nr_linii), nr_coloane(nr_coloane){
            this->m = new int[nr_linii*nr_coloane];
            
            for(int i=0; i<nr_linii*nr_coloane; i++){
                *(this->m+i)= *(m+i);
            }
                    
        }
            
    //Functii
    friend Vector inmultire(Vector &vec, Matrice &mat);
    
    
};



//Functia inmultire
Vector inmultire(Vector &vec, Matrice &mat){
    
    if(vec.nr_elemente != mat.nr_linii){
        Vector A(0,NULL);
        return A;
    }
    
    int *vec_new = new int[vec.nr_elemente];
    
    for(int i=0; i<mat.nr_coloane; i++){
        
        int s=0;
        int x=i;
        int a;
        int b;
        
        for(int j=0; j<=mat.nr_coloane; j++){
            
            a=*(vec.v+j);
            b=*(mat.m+j*mat.nr_coloane+i);
            s=s+a*b;
            
        }
        *(vec_new+i)=s;
        
        std::cout<<std::endl;
    }
    
    Vector A(mat.nr_coloane, vec_new);
    return A;
    
    
    
}

//Functia main
int main()
{
    int nr_elemente;
    std::cin>>nr_elemente;
    int *v1=new int[nr_elemente];
    
    for(int i=0;i<nr_elemente;i++)
    std::cin>>*(v1+i);
    Vector v(nr_elemente,v1);
    int linii,coloane;
    std::cin>>linii>>coloane;
    
    int *m1=new int[linii*coloane+10];
    for(int i=0;i<linii;i++)
   { int u=0;
       for(int j=0;j<coloane;j++)
    { 
    std::cin>>*(m1+i*linii+j+i);
    
        
    }
       u++;
       
   }
    Matrice m(linii,coloane,m1);
    
    Vector x=inmultire(v,m);
    
    x.afisare();
       return 0;
}
