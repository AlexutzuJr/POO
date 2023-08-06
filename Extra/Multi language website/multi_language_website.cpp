/* Să se scrie o aplicație de tip poliglot pentru conținutul unui site web. O aplicație poliglot presupune traducerea conținutului în mai multe limbi. Site-ul conține 2 elemente (hello_message, page_content) care au 
asociat câte un mesaj. La schimbarea limbii site-ului, se dorește schimbarea tuturor mesajelor din elementele site-ului în limba dorită. Se vor citi de la tastatură numele utilizatorului, limba și mesajele propriu-zise, 
până la întâlnirea cuvântului STOP și se vor memora într-o clasă Website, în felul următor:
- <nume_utilizator>
- <identificator_limba_1>
- <hello_message_1>
- <page_content_1>
- <identificator_limba_2>
- <hello_message_2>
- <page_content_2>
- …
- <identificator_limba_n>
- <hello_message_n>
- <page_content_n>
- STOP

Meniul site-ului rulează în buclă și oferă funcționalități diferite, în funcție de comanda introdusă, astfel:
1. alegere limbă - afișează limbile posibile și așteaptă introducerea unui string care specifică limba în care se va schimba site-ul (default: prima limbă introdusă).
2. afișează mesajul de întâmpinare al paginii și numele utilizatorului, astfel: <hello_message>, <nume_utilizator>!
3. afișează conținutul paginii în limba curentă
4. ieșire */


#include <iostream>
#include <string>
#include <limits>

//Clasa de Baza
class Website{
    
    //Date membre:
    protected:
        std::string utilizator;
        std::string identificator_limbaj;
        std::string hello_message;
        std::string page_content;
    
    //Constructor
    public:
        
        //Constructor Gol
        Website(){}
        
        //Constructor cu Lista de Initializare
        Website(std::string utilizator, std::string identificator_limbaj, std::string hello_message, std::string page_content):
                    utilizator(utilizator), identificator_limbaj(identificator_limbaj), hello_message(hello_message), page_content(page_content){}
    
    //Functii
    public:
        
        
        //Setters si Getters
        void set_utilizator(std::string utilizator){this->utilizator = utilizator;}
        std::string get_utilizator(){return this->utilizator;}
        
        void set_identificator_limbaj(std::string identificator_limbaj){this->identificator_limbaj = identificator_limbaj;}
        std::string get_identificator_limbaj(){return this->identificator_limbaj;}
        
        void set_hello_message(std::string hello_message){this->hello_message = hello_message;}
        std::string get_hello_message(){return this->hello_message;}
        
        void set_page_content(std::string page_content){this->page_content = page_content;}
        std::string get_page_content(){return this->page_content;}
        
        
        
        
        //Functie pentru afisare limba
        void afisare_limba(){
            std::cout<<identificator_limbaj<<std::endl;
        }
    
        //Functia pentru afisare mesaj intampinare
        void afisare_mesaj_intampinare(){
            std::cout<<hello_message<<", "<<utilizator<<"!"<<std::endl;
        }
        
        //Functia pentru afisare continut
        void afisare_continut(){
            std::cout<<page_content<<std::endl;
        }
        
        //Destructor
        ~Website(){}
    
};


//Functia main
int main(){
    
    //Initializam Date
    std::string utilizator;
    std::string identificator_limbaj;
    std::string hello_message;
    std::string page_content;
    
    int numar_obiecte = 0;
    
    std::cin>>utilizator;
    
    //Facem Obiectele cu Alocare Dinamica
    Website **website_array = nullptr;
    website_array = new Website*[100];
    
    //Citim pana la STOP
    for(int i=0; ;i++){
        
        std::cin>>identificator_limbaj;
        
        //Punem conditia
        if(identificator_limbaj != "STOP"){
            
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::getline(std::cin, hello_message);
            std::getline(std::cin, page_content);
        
            *(website_array+i) = new Website(utilizator, identificator_limbaj, hello_message, page_content);
            
            numar_obiecte = numar_obiecte+1;
        }
        
        if(identificator_limbaj == "STOP"){
            break;
        }
        
        
    }
    
    
    //Optiuni CU BUCLA
    int optiune;
    int k=1;
    
    
    //Identificator care va lua valoarea din Optiunea 1 pentru a afisa pe parcurs Obiectul cerut
    int limba_aleasa=0;
    
    do{
        
        std::cin>>optiune;
        if(optiune == 1){
        
            //Limba in care vrem sa afisam
            std::string identificator_bucla;
            std::cin>>identificator_bucla;
        
            for (int i=0; i<numar_obiecte; i++){
                
                if(identificator_bucla == (*(website_array+i))->get_identificator_limbaj()){
                    limba_aleasa=i;
                    break;
                }
            }
            

        }
        
        if(optiune == 2){
            (*(website_array+limba_aleasa))->afisare_mesaj_intampinare();
            
        }
        
        if(optiune == 3){
            (*(website_array+limba_aleasa))->afisare_continut();
            
        }
        
        if(optiune == 4){
            k=0;
        }
        
        
    }while(k);
    
    
    //Destructor Obiecte
    for(int i=0; i<numar_obiecte; i++){
        delete *(website_array+i);
    }
    
    
    return 0;
    
}
