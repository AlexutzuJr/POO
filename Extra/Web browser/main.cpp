/* Să se scrie o aplicație de tip web browser pentru gestiunea funcționalității de navigare între diferite pagini web. În acest sens, se vor "genera" mai multe pagini web și se va implementa un browser care va putea accesa 
o pagină prin intermediul URL-ului și a butoanelor back/forward. 

O pagină web este caracterizată de câmpurile:
- url
- titlu
-conținut

Oricare dintre paginile web poate accesa oricare dintre celelalte pagini web (are link direct) și accesul se poate face dintr-o clasă Browser, printr-una dintre funcțiile:
- link(std::string)
- back(void)
- forward(void)

Browser-ul poate utiliza o referință/pointer la pagina curentă, care se va muta la diferite pagini, pe măsură ce sunt accesate. De asemenea, navigarea între paginile web va fi stocată în memorie pentru a putea reface 
istoricul navigării prin funcțiile back/forward. Această istorie poate fi implementată sub forma unei liste dublu înlănțuite, cu o modificare: accesarea unei noi pagini prin funcția link(std::string) va șterge din listă 
toate paginile reținute după punctul curent și va introduce în listă noul link. De exemplu, următoarea succesiune de apelări va avea efectele menționate - pagina curentă este indicată îngroșat:
1. link(pag_1) - introduce pag_1 în memorie: pag_1
2. link(pag_2) - introduce pag_2 în memorie: pag_1 -> pag_2
3. link(pag_3) - introduce pag_3 în memorie: pag_1 -> pag_2 -> pag_3
4. link(pag_4) - introduce pag_4 în memorie: pag_1 -> pag_2 -> pag_3 -> pag_4
5. back() - se mută cu o poziție în memorie: pag_1 -> pag_2 -> pag_3 -> pag_4
6. back() - se mută cu o poziție în memorie: pag_1 -> pag_2 -> pag_3 -> pag_4
7. forward() - se mută cu o poziție în memorie: pag_1 -> pag_2 -> pag_3 -> pag_4
8. back() - se mută cu o poziție în memorie: pag_1 -> pag_2 -> pag_3 -> pag_4
9. link(pag_5) - se șterg toate intrările din memorie care urmează după pagina curentă și se introduce pag_5 în memorie: pag_1 -> pag_2 -> pag_5

Dacă nu mai există nicio pagină în spate/față când se apelează funcțiile back()/forward(), respectiv, pagina curentă nu se modifică.

De la tastatură se va citi un întreg. În funcție de valoarea lui, se vor executa următoarele comenzi:
1. Generare pagină. Se vor citi, suplimentar, următoarele date, fiecare de tipul std::string:
   1. url
   2. titlu
   3. conținut
2. Accesare pagină (funcția link) după url. Se introduce de la tastatură un std::string suplimentar și se va naviga către pagina respectivă, reținându-se, în același timp, în memoria browser-ului. Se garantează că pagina 
respectivă există și este unică.
3. Afișare pagină. Se vor afișa, pe rânduri diferite:
   1. url
   2. titlu
   3. conținut
4. Navigare în spate: funcția back()
5. Navigare în față: funcția forward()
6. Ieșire din program. */


#include "clase.cpp"

int main()
{
    Browser vlad;
    
    std::list<Pagina_Web> P;
    int comanda;
    
    std::string url, titlu, content;
    
    while(true)
    {
        std::cin>>comanda;
        
        if(comanda == 1)
        {
            std::cin>>url>>titlu;
            std::cin.get();
            getline(std::cin, content);
            
            P.push_back(Pagina_Web(url, titlu, content));
        }
        
        if(comanda == 2)
        {
            std::cin>>url;
            vlad.link(P, url);
        }
        
        if(comanda == 3) vlad.afisare_pagina();
        
        if(comanda == 4) vlad.back();
        
        if(comanda == 5) vlad.forward();
    
        if(comanda == 6) break;
    }
        
    return 0;
}
