#include <iostream>
#include <string>
#include <iomanip>

class Criptomoneda{
private:
    std::string nume;
    float val_frac; //cantitatea de criptomonede detinuta
    float val_crt; //valoarea unei unitati din criptomoneda respectiva - pret de referinta
public:
    Criptomoneda(std::string nume, float val_frac, float val_crt):nume(nume), val_frac(val_frac), val_crt(val_crt){}
    void afisare(){
        std::cout << this->nume << " " << this->val_frac << " " << this->val_crt << std::endl;
    }
    std::string get_nume(){return this->nume;}
    float get_val_crt(){return this->val_crt;}
    float get_val_frac(){return this->val_frac;}
    void increment_val_frac(float val){
        this->val_frac = this->val_frac + val;
    }
};

class Portofel{
private:
    float sold;
    int nr_monede;
    Criptomoneda** monede;
public:
    Portofel(float sold, int nr_monede):sold(sold), nr_monede(nr_monede){
        this->monede = new Criptomoneda*[nr_monede];
    }
    void insert_moneda(Criptomoneda c, int index){
        *(this->monede+index) = new Criptomoneda(c);
    }
    void afisare(){
        std::cout << this->sold << std::endl;
        for (int i=0; i<this->nr_monede; ++i){
            (*(monede+i)) -> afisare();
        }
    }
    void cumparare(std::string nume, float val_frac, int display){
        for (int i=0; i<this->nr_monede; ++i){
            if ((*(monede+i)) -> get_nume() == nume){
                float temp_suma_necesara = val_frac * (*(monede+i)) -> get_val_crt();
                if (temp_suma_necesara <= this->sold){
                    this->sold = this->sold - temp_suma_necesara;
                    (*(monede+i)) -> increment_val_frac(val_frac);
                }
                else{
                    float frac_max = this->sold / (*(monede+i)) -> get_val_crt();
                    this->sold = 0;
                    (*(monede+i)) -> increment_val_frac(frac_max);
                }
                if (display){
                    (*(monede+i)) -> afisare();
                }
            }
        }
    }
    
    void vanzare(std::string nume, float val_frac, int display){
        for (int i=0; i<this->nr_monede; ++i){
            if ((*(monede+i)) -> get_nume() == nume){
                float temp_val_frac_max = (*(monede+i)) -> get_val_frac();
                if (val_frac <= temp_val_frac_max){
                    this->sold = this->sold + val_frac * (*(monede+i)) -> get_val_crt();
                    (*(monede+i)) -> increment_val_frac(val_frac*(-1));
                }
                else{
                    this->sold = this->sold +  (*(monede+i)) -> get_val_frac() * (*(monede+i)) -> get_val_crt();
                    (*(monede+i)) -> increment_val_frac((*(monede+i)) -> get_val_frac()*(-1));
                }
                if (display){
                    (*(monede+i)) -> afisare();
                }
            }
        }
    }
};




int main(){
    float temp_sold;
    int temp_nr_monede;
    std::string temp_nume;
    float temp_val_frac;
    float temp_val_crt;
    int comanda;
    std::string tranzactie;
    int nr_tranzactii;
    
    std::cin >> temp_sold;
    std::cin >> temp_nr_monede;
    Portofel portofel(temp_sold, temp_nr_monede);
    
    for (int i=0; i<temp_nr_monede; ++i){
        std::cin >> temp_nume;
        std::cin >> temp_val_frac;
        std::cin >> temp_val_crt; //CTRL + space
        Criptomoneda temp_moneda = Criptomoneda(temp_nume, temp_val_frac, temp_val_crt);
        portofel.insert_moneda(temp_moneda, i);
    }
    
    std::cin >> comanda;
    std::cout << std::fixed << std::setprecision(2);
    switch(comanda){
        case 1:{ // afisare
            portofel.afisare();
            break;
        }
        case 2:{
            std::cin >> temp_nume;
            std::cin >> temp_val_frac;
            portofel.cumparare(temp_nume, temp_val_frac, 1);
            break;
        }
        case 3:{
            std::cin >> temp_nume;
            std::cin >> temp_val_frac;
            portofel.vanzare(temp_nume, temp_val_frac, 1);
            break;
        }
        case 4:{
            
            std::cin >> nr_tranzactii;
            
            for (int i=0; i<nr_tranzactii; ++i){
                
                std::cin >> tranzactie;
                std::cin >> temp_val_frac;
                std::cin >> temp_nume;
                if (tranzactie == "cumpara"){
                    //std::cout << tranzactie << " " << temp_nume << " " << temp_val_frac << std::endl;
                    portofel.cumparare(temp_nume, temp_val_frac, 0);
                }
                else{
                    portofel.vanzare(temp_nume, temp_val_frac, 0);
                }
            }
            portofel.afisare();
            break;
        }
        
    }
    
}
