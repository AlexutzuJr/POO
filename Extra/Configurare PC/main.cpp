/* Scrieți o aplicație care să vă ajute să vă puteți configura propriul calculator, în funcție de performanțele componentelor sale și de bugetul disponibil. Aplicația va conține mai multe clase:

1. clasa Echipament_electronic - va servi drept interfață pentru restul echipamentelor;
2. clasa Placa_baza - placa de bază a calculatorului;
3. clasa CPU - procesorul calculatorului;
4. clasa GPU - procesorul grafic (placa video) al (a) calculatorului;
5. clasa Stocare - mediul de stocare (HDD/SSD) al calculatorului;
6. clasa PC - calculatorul propriu-zis. Această clasă va reuni toate componentele individuale.
7. clasa Manager - o clasă care va procesa toate informațiile și va manipula toate obiectele.


Aplicația va urma un model simplificat (fără RAM, sursă de curent, cooler, periferice, carcasă, etc.) și va trebui să îndeplinească mai multe funcționalități, în buclă, sub forma unui meniu, în funcție de o comandă 
citită de la tastatură, astfel:

1. Citire componente. Obiectul din clasa Manager va reține câte un vector pentru fiecare componentă diferită, mai puțin pentru placa de bază, unde se va citi doar o singură intrare. Pentru fiecare dintre componente se 
vor citi de pe linii succesive:
   1. pret: float - reprezintă prețul componentei;
   2. nume: std::string - reprezintă numele componentei;
   3. tip: std::string; tip poate fi una dintre valorile: placa_baza, cpu, gpu, stocare. În funcție de tipul citit se vor citi suplimentar următoarele informații:
   - placa_baza:
   4. socket: std::string - reprezintă tipul de socket suportat pentru procesor;
   - cpu:
   4. socket: std::string - reprezintă tipul de socket al procesorului;
   5. frecventa: int - reprezintă frecvența procesorului;
   - gpu:
   4. memorie: int - reprezintă memoria procesorului grafic, exprimată în GB;
   - stocare:
   4. memorie: float - reprezintă spațiul de stocare, exprimat în TB;
2. Afișare componente. Se vor afișa pe ecran atributele fiecărei componente stocate în obiectul Manager, în următoarea ordine a tipului componentei: placa de bază -> cpu -> gpu -> stocare, cu următoarele detalii pe câte 
un rând diferit: <tip>, <nume>, <alte date specifice categoriei de componente respective, în ordinea de la punctul 1>, <pret>. Exemplu rând: "gpu, 3080_Ti, 12, 10000".
3. Configurare PC. Se va citi suplimentar o listă de nume de componente (câte un nume din fiecare tip diferit, cu excepția plăcii de bază, care rămâne la fel ca la punctul 1), care se garantează că se găsește în lista 
stocată de către Manager și se va configura PC-ul cu aceste componente. Trebuie avut în vedere că placa de bază trebuie să aibă același socket cu cpu. În caz contrar, se va afișa pe ecran mesajul "Placa de baza este 
incompatibila cu CPU ales." și se va termina programul. Se vor afișa pe ecran componentele PC-ului configurat, sub forma prezentată la punctul 2. La finalul afișării tuturor componentelor se va afișa și prețul total al 
configurației, pe un rând diferit.
4. Configurare PC optimă pentru un buget anume. Se va citi suplimentar o valoare întreagă reprezentând bugetul maxim alocat pentru componente. Se vor selecta componentele cu cel mai bun raport calitate-preț pentru a 
configura PC-ul în limita bugetului alocat și se vor afișa pe ecran, ca la punctul 3. Algoritmul se va parcurge astfel:
   1. se vor ordona toate componentele per categoria din care fac parte, după raportul calitate-pret. Criteriul de calitate se consideră a fi astfel: cpu - frecvența, gpu - memoria, stocare - memoria. Indicație: dacă 
folosiți algoritmul std::sort, trebuie să supraîncărcați operator< pentru a avea o metodă de a stabili ierarhia elementelor în cadrul unui container;
   2. calculatorul se va configura la început doar cu componentele de preț minim din fiecare categorie, considerând acest punct ca fiind soluția "de buget";
   3. iterativ, se vor face îmbunătățiri ale sistemului schimbând componentele cu versiuni mai bune ale lor, adică cu următoarea variantă din lista ordonată de componente din categoria respectivă, cu condiția să nu se 
depășească bugetul. Se va stabili următoarea ordine a priorității upgrade-urilor: gpu >> cpu >> stocare. Altfel spus, se va încerca îmbunătățirea gpu-ului cu o poziție în lista ordonată, după aceea cpu și la final 
stocarea. Dacă există un buget suficient de mare se va relua algoritmul începând cu gpu, etc.
5. Ieșire program.

Se garantează că toate opțiunile care lucrează cu date deja existente se vor citi după ce au fost executate opțiunile predecesoare lor. */


  
#include "echipament_electronic.h"
#include <iostream>
#include <bits/stdc++.h>
#include <limits.h>

class Placa_de_baza : protected Echipament_electronic
{
  
protected:
    std::string socket;

public:
    Placa_de_baza(float pret = 0.0f, std::string nume = "", std::string tip = "", std::string socket = ""): Echipament_electronic(pret, nume, tip), socket(socket){}
  
    void afisare(){std::cout<<tip<<", "<<nume<<", "<<socket<<", "<<pret<<'\n';}
    
    float raport_calitate_pret(){return -1.0f;}
    
    std::string get_nume(){return nume;}
    float get_pret(){return pret;}
    std::string get_socket(){return socket;}

};


class CPU : protected Echipament_electronic
{
  
protected:
    std::string socket;
    int frecventa; // Ghz

public:
    CPU(float pret = 0.0f, std::string nume = "", std::string tip = "", std::string socket = "", int frecventa = 0): Echipament_electronic(pret, nume, tip), socket(socket), frecventa(frecventa){}
  
    void afisare(){std::cout<<tip<<", "<<nume<<", "<<socket<<", "<<frecventa<<", "<<pret<<'\n';}
    
    float raport_calitate_pret(){return (float)frecventa/pret;}
    
    std::string get_nume(){return nume;}
    float get_pret(){return pret;}
    std::string get_socket(){return socket;}
    
};


class GPU : protected Echipament_electronic
{
    
protected:
    int memorie; // in GB

public:
    GPU(float pret = 0.0f, std::string nume = "", std::string tip = "", int memorie = 0): Echipament_electronic(pret, nume, tip), memorie(memorie){}
    
    void afisare(){std::cout<<tip<<", "<<nume<<", "<<memorie<<", "<<pret<<'\n';}
    
    float raport_calitate_pret(){return (float)memorie/pret;}
    
    std::string get_nume(){return nume;}
    float get_pret(){return pret;}

};


class Stocare : protected Echipament_electronic
{
    
protected:
    float memorie;

public:
    Stocare(float pret = 0.0f, std::string nume = "", std::string tip = "", float memorie = 0.0f): Echipament_electronic(pret, nume, tip), memorie(memorie){}

    void afisare(){std::cout<<tip<<", "<<nume<<", "<<memorie<<", "<<pret<<'\n';}
    
    float raport_calitate_pret(){return memorie/pret;}
    
    std::string get_nume(){return nume;}
    float get_pret(){return pret;}

};


class Manager
{
    Placa_de_baza** V1;
    int index_v1;
    
    CPU** V2;
    int index_v2;
    
    GPU** V3;
    int index_v3;
    
    Stocare** V4;
    int index_v4;
    
public:
    Manager()
    {
        index_v1 = 0;
        index_v2 = 0;
        index_v3 = 0;
        index_v4 = 0;
        
        V1 = new Placa_de_baza*[100];
        V2 = new CPU*[100];
        V3 = new GPU*[100];
        V4 = new Stocare*[100];
    }
    
    void citire_date()
    {
        float pret;
        std::string nume;
        std::string tip;
        
        std::string socket;
        int frecventa;
        int memorie;
        float memorie_stocare;
        
        std::cin>>pret>>nume>>tip;
        if(tip == "placa_baza")
        {
            std::cin>>socket;
            V1[index_v1++] = new Placa_de_baza(pret, nume, tip, socket);
        }
        else if(tip == "cpu")
        {
            std::cin>>socket>>frecventa;
            V2[index_v2++] = new CPU(pret, nume, tip, socket, frecventa);
        }
        else if(tip == "gpu")
        {
            std::cin>>memorie;
            V3[index_v3++] = new GPU(pret, nume, tip, memorie);
        }
        else if(tip == "stocare")
        {
            std::cin>>memorie_stocare;
            V4[index_v4++] = new Stocare(pret, nume, tip, memorie_stocare);
        }
    }
    
    void afisare_componente()
    {
        for(int i=0; i<index_v1; i++) V1[i]->afisare();
        
        for(int i=0; i<index_v2; i++) V2[i]->afisare();
        
        for(int i=0; i<index_v3; i++) V3[i]->afisare();
        
        for(int i=0; i<index_v4; i++) V4[i]->afisare();
    }
    
    void configuratie_PC(std::string cpu, std::string gpu, std::string stocare)
    {
        float suma = 0.0f;
        int index_cpu=0, index_gpu=0, index_stocare=0;
        
        for(int i=0; i<index_v2; i++)
            if(V2[i]->get_nume() == cpu) index_cpu = i;
        
        for(int i=0; i<index_v3; i++)
            if(V3[i]->get_nume() == gpu) index_gpu = i;
        
        for(int i=0; i<index_v4; i++)
            if(V4[i]->get_nume() == stocare) index_stocare = i;
        
        if(V2[index_cpu]->get_socket() == V1[0]->get_socket())
        {
            suma += V1[0]->get_pret() + V2[index_cpu]->get_pret() + V3[index_gpu]->get_pret() + V4[index_stocare]->get_pret();
            V1[0]->afisare();
            V2[index_cpu]->afisare();
            V3[index_gpu]->afisare();
            V4[index_stocare]->afisare();
            std::cout<<suma<<'\n';
        }
    }
    
    void sort_raport_calitate_pret()
    {
        
        Placa_de_baza* tmp1;
        for(int i=0; i<index_v1-1; i++)
        {
            for(int j = i+1; j<index_v1; j++)
            {
                if(V1[i]->raport_calitate_pret() > V1[j]->raport_calitate_pret())
                {
                    tmp1 = V1[i];
                    V1[i] = V1[j];
                    V1[j] = tmp1;
                }
            }
        }
        
        CPU* tmp2;
        for(int i=0; i<index_v2-1; i++)
        {
            for(int j = i+1; j<index_v2; j++)
            {
                if(V2[i]->raport_calitate_pret() > V2[j]->raport_calitate_pret())
                {
                    tmp2 = V2[i];
                    V2[i] = V2[j];
                    V2[j] = tmp2;
                }
            }
        }
        
        GPU* tmp3;
        for(int i=0; i<index_v3-1; i++)
        {
            for(int j = i+1; j<index_v3; j++)
            {
                if(V3[i]->raport_calitate_pret() > V3[j]->raport_calitate_pret())
                {
                    tmp3 = V3[i];
                    V3[i] = V3[j];
                    V3[j] = tmp3;
                }
            }
        }
        
        Stocare* tmp4;
        for(int i=0; i<index_v4-1; i++)
        {
            for(int j = i+1; j<index_v4; j++)
            {
                if(V4[i]->raport_calitate_pret() > V4[j]->raport_calitate_pret())
                {
                    tmp4 = V4[i];
                    V4[i] = V4[j];
                    V4[j] = tmp4;
                }
            }
        }
    }
    
    void configuratie_optima_PC(int buget)
    {
        int index_motherboard=0;
        int index_cpu=0;
        int index_gpu=0;
        int index_stocare=0;
        
        int min = INT_MAX;
        
        for(int i=0; i<index_v2; i++)
        {
            if(V2[i]->get_pret()<min)
            {
                min = V2[i]->get_pret();
                index_cpu = i;
            }
        }
        
        min = INT_MAX;
        
        for(int i=0; i<index_v3; i++)
        {
            if(V3[i]->get_pret()<min)
            {
                min = V3[i]->get_pret();
                index_gpu = i;
            }
        }
        
        min = INT_MAX;
        
        for(int i=0; i<index_v4; i++)
        {
            if(V4[i]->get_pret()<min)
            {
                min = V4[i]->get_pret();
                index_stocare = i;
            }
        }
        
        int sum = V1[index_motherboard]->get_pret() + V2[index_cpu]->get_pret() + V3[index_gpu]->get_pret() + V4[index_stocare]->get_pret();
        
        int ok;
        while(sum <= buget)
        {
            ok = 0;
            
            if(index_gpu < index_v3-1)
            {
                if(sum + (V3[index_gpu+1]->get_pret() - V3[index_gpu]->get_pret()) > buget) ok++;
                else 
                {
                    sum += V3[index_gpu+1]->get_pret() - V3[index_gpu]->get_pret();
                    index_gpu++;
                }
            }
            else ok++;
            
            if(index_cpu < index_v2-1)
            {
                if(sum + (V2[index_cpu+1]->get_pret() - V2[index_cpu]->get_pret()) > buget) ok++;
                else 
                {
                    sum += V2[index_cpu+1]->get_pret() - V2[index_cpu]->get_pret();
                    index_cpu++;
                }
            }
            else ok++;
            
            if(index_stocare < index_v4-1)
            {
                if(sum + (V4[index_stocare+1]->get_pret() - V4[index_stocare]->get_pret()) > buget) ok++;
                else 
                {
                    sum += V4[index_stocare+1]->get_pret() - V4[index_stocare]->get_pret();
                    index_stocare++;
                }
            }
            else ok++;
            
            if(ok == 3) break;
        }
        
        V1[index_motherboard]->afisare();
        V2[index_cpu]->afisare();
        V3[index_gpu]->afisare();
        V4[index_stocare]->afisare();
    }
};



int main(){

    Manager Alex;
    
    int comanda;
    
    while(true)
    {
        std::cin>>comanda;    
        if(comanda  == 1) Alex.citire_date();
        
        if(comanda == 2) Alex.afisare_componente();
        
        if(comanda == 3)
        {
            std::string cpu, gpu, stocare;
            std::cin>>cpu>>gpu>>stocare;
            
            Alex.configuratie_PC(cpu, gpu, stocare);
        }
        
        if(comanda == 4)
        {
            Alex.sort_raport_calitate_pret();
            
            int buget;
            std::cin>>buget;
            
            Alex.configuratie_optima_PC(buget);
        }
        
        if(comanda == 5) break;
    }
    
    return 0;
}
