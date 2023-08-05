#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Participant
{ //tara care concureaza la Eurovision
private:
    std::string nume_tara;
    std::string nume_piesa;
    int punctaj;
    std::string vec_tari_votate[4];
    int nr_voturi;
    int nr_voturi_sapte;

public:
    Participant(std::string nume_tara, std::string nume_piesa): nume_tara(nume_tara), nume_piesa(nume_piesa), punctaj(0), nr_voturi(0), nr_voturi_sapte(0){}


    void afisare()
    {
        std::cout << nume_tara << " " << nume_piesa << " " << punctaj << std::endl;
    }
    
    void votare(std::string vec_tari[4])
    {
        for (int i=0; i<4; ++i){
            vec_tari_votate[i] = vec_tari[i];
        }
    }
    
    std::string get_nume() {return nume_tara;}
    
    void adauga_punctaj(int pct)
    {
        if (pct == 7) 
        {
            this->nr_voturi_sapte+=1;
        }
  
        this->punctaj += pct;
        this->nr_voturi += 1;
    }
    
    int get_punctaj()
    {
        return this->punctaj;
    }
    
    int get_nr_voturi()
    {
        return this->nr_voturi;
    }
    
    int get_nr_voturi_sapte()
    {
        return this->nr_voturi_sapte; //CTRL + space
    }
}; 


bool comparatie(Participant &p1, Participant &p2)
{
    // p1 > p2 , daca p1.get_punctaj() > p2.get_punctaj()
    // in caz de egalitate, p1 > p2, daca p1.get_nr_voturi_sapte() > p2.get_nr_voturi_sapte()
    // if (p1.get_punctaj() > p2.get_punctaj()){
    //     return true;
    // }
    // else if (p1.get_punctaj() == p2.get_punctaj()){
    //     if (p1.get_nr_voturi_sapte() > p2.get_nr_voturi_sapte()){
    //         return true;
    //     }
    //     else {
    //         return false;
    //     }
    // }
    // else {
    //     return false;
    // }
    
    if (p1.get_punctaj() == p2.get_punctaj())
    {
        return (p1.get_nr_voturi_sapte() > p2.get_nr_voturi_sapte());
    }
    else 
    {
        return (p1.get_punctaj() > p2.get_punctaj());
    }
}


class Eurovision
{ //concursul propriu-zis
private:
    std::vector<Participant> vec_tari;
    
public:
    //folosim constructorul default (fara argumente)
    void adauga_participant(Participant &p)
    {
        vec_tari.push_back(p);
    }
    
    //afisare tari participante
    void afisare()
    {
        for (Participant p:vec_tari)
        {
            p.afisare();
        }
    }
    
    int get_nr_participanti()
    {
        return vec_tari.size();
    }
    
    void votare(int index, std::string temp_vec_tari[4])
    {
        vec_tari[index].votare(temp_vec_tari);
      
        for (Participant &p:vec_tari)
        {
        // ------------------------------------------------
        // for (Participant p:vec_tari){ // este echivalent cu:
        // for (int i=0; i<vec_tari.size(); ++i){
        //     Participant p = vec_tari[i];
        //     p.adauga_punctaj(7);
        // }
        // ------------------------------------------------
            if (p.get_nume() == temp_vec_tari[0])
            {
                p.adauga_punctaj(7);
                // std::cout << p.get_nume() << " " << p.get_punctaj() << std::endl;
            }
            else if (p.get_nume() == temp_vec_tari[1])
            {
                p.adauga_punctaj(5);
            }
            else if (p.get_nume() == temp_vec_tari[2])
            {
                p.adauga_punctaj(3);
            }
            else if (p.get_nume() == temp_vec_tari[3])
            {
                p.adauga_punctaj(1);
            }
        }
    }
    
    void tara_populara()
    {
        int max = vec_tari[0].get_nr_voturi();
        int index_max = 0;
        
        for (int i=0; i<vec_tari.size(); ++i)
        {
            if (vec_tari[i].get_nr_voturi() > max)
            {
                max = vec_tari[i].get_nr_voturi();
                index_max = i;
            }
        }
        
        vec_tari[index_max].afisare();
    }
    
    void clasament()
    {
        std::sort(vec_tari.begin(), vec_tari.end(), comparatie);
        afisare();
    }
};



int main()
{
    int comanda;
    std::string temp_nume_tara;
    std::string temp_nume_piesa;
    Eurovision concurs;
    
    do
    {
        std::cin >> comanda;
        
        switch(comanda)
        {
            case 1:
            {
                std::cin >> temp_nume_tara;
                std::cin >> temp_nume_piesa;
                Participant temp_participant(temp_nume_tara, temp_nume_piesa);
                concurs.adauga_participant(temp_participant);
                break;
            }
            
            case 2:
            {
                concurs.afisare();
                break;
            }
            
            case 3:
            {
                std::string temp_voturi_tara[4];
              
                for (int i=0; i<concurs.get_nr_participanti(); ++i){
                    std::cin >> temp_voturi_tara[0]; //7 pct
                    std::cin >> temp_voturi_tara[1]; //5 pct
                    std::cin >> temp_voturi_tara[2]; //3 pct
                    std::cin >> temp_voturi_tara[3]; //1 pct
                    // for (int j=0; j<4; ++j)
                    // {
                    //     std::cout << temp_voturi_tara[j] << " ";
                    // }
                    // std::cout << std::endl;
                    concurs.votare(i, temp_voturi_tara);
                }
                break;
            }
            
            case 4:
            {
                concurs.tara_populara();
                break;
            }
            
            case 5:
            {
                concurs.clasament();
                break;
            }
            
            case 6:
            {
                // std::cout << comanda;
                // exit(0);
                break;
            }
        }
        
    }
    while (comanda != 6);
  
}
