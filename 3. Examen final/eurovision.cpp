#include <iostream>
#include <string>

class Participant
{ //tara care concureaza la Eurovision
    protected:
        std::string nume_tara;
        std::string nume_piesa;
        int punctaj; //o putem declara si sa nu o initializam, si nu va interfera cu citirea/afisarea; sau puteam scrie (..., int punctaj): ..., punctaj(0) {} si e aceeasi chestie
        std::string vec_tari_votate[4]; //lista de 4 tari votate (retinute sub forma unui vector)
        int nr_voturi;
        int nr_voturi_sapte;
        
    public:
        Participant(std::string nume_tara, std::string nume_piesa): nume_tara(nume_tara), nume_piesa(nume_piesa) {}


    void afisare() //aici nu mai e nevoie de "virtual void afisare() {}", si nici nu merge folosit (fiind vorba doar de 2 clase)
    {
        std::cout<<nume_tara<<" "<<nume_piesa<<" "<<punctaj<<std::endl;
    }

}; 


class Eurovision: public Participant
{ //concursul propriu-zis
    protected:
    //nu avem nicio data membra de adaugat
    public:
         Eurovision(std::string nume_tara, std::string nume_piesa): Participant(nume_tara, nume_piesa) {}
    
    //afisare tari participante
    void afisare()
    {
        std::cout<<nume_tara<<" "<<nume_piesa<<" "<<punctaj<<std::endl;
    }

};



int main()
{
    std::string nume_tara;
    std::string nume_piesa;
    
    int k=0;
    int optiune;
    
    Participant **participanti_array=nullptr;
    participanti_array=new Participant*[9]; //neaparat stocam in vector un numar, nu putem citi o variabila si sa o stocam in vector aici, deoarece nu apare la "input" (plus ca nu ni se spune sa citim acel numar de la tastatura) 

  
    do
    {
        std::cin>>optiune;

      
        if(optiune==1)
        {
            std::cin>>nume_tara;
            std::cin>>nume_piesa;

            *(participanti_array+(k++))=new Participant(nume_tara, nume_piesa); //punem elementele participantilor in obiect
        }
            
        if(optiune==2)
        {
            for(int i=0;i<k;i++)
                (*(participanti_array+i))->afisare();
        }
            
        if(optiune==6)
        {
            return 0;
        }
    }
        
    while(1);
}
