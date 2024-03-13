/* Având în vedere o matrice goală care ar trebui să conțină numere întregi, sarcina dvs. este să procesați o listă de interogări pe aceasta. Mai exact, există două tipuri de interogări:
„+x” - adăugați x numerelor. Numerele pot conține mai multe instanțe ale aceluiași număr întreg.
"-x" - elimina toate instanțele lui x din numere.
După procesarea fiecărei interogări, numărați numărul de triplete (x, y, z) în numere care îndeplinesc această condiție: atât x - y, cât și y - z sunt egale cu o diferență dată. Rețineți că elementele din numere pot fi 
rearanjate pentru a forma triplete pentru a îndeplini condiția. Rezultatul final ar trebui să fie o matrice de numărări după fiecare interogare în interogări.

Notă:
Toate numerele întregi din interogări sunt garantate a fi în intervalul [-10^9, 10^9]. De asemenea, este garantat că pentru fiecare interogare „-x”, x-ul specificat există în numere.
Este garantat că răspunsul pentru fiecare interogare se încadrează într-un tip întreg de 32 de biți.

Exemplu:
Pentru interogări = ["+4", "+5", "+6", "+4", "+3", "-4"] și diff = 1, rezultatul ar trebui să fie soluție(interogări, dif) = [0, 0, 1, 2, 4, 0].

Mai întâi, procesați interogările[0] = „+4” și adăugați 4 numerelor, rezultând numere = [4]. Nu există încă triplete, așa că adăugați 0 la ieșire.
Apoi, procesați interogările[1] = „+5” și adăugați 5 numerelor, rezultând numere = [4, 5]. Nu există încă triplete, așa că adăugați 0 la ieșire.
Procesați interogările[2] = „+6” și adăugați 6 numerelor, rezultând numere = [4, 5, 6]. Acestea pot forma tripletul (6, 5, 4) care îndeplinește condiția (6 - 5 = 5 - 4 = 1 = dif), așa că adăugați 1 la ieșire.
Procesați interogările[3] = „+4” și adăugați 4 la numere, rezultând numere = [4, 5, 6, 4]. Acum, există două moduri de a forma tripletul (6, 5, 4) care îndeplinește condiția, așa că adăugați 2 la ieșire.
Procesați interogările[4] = „+3” și adăugați 3 la numere, rezultând numere = [4, 5, 6, 4, 3]. Acum, există două moduri de a forma tripletul (6, 5, 4) și două moduri de a forma tripletul (5, 4, 3) care îndeplinesc condiția,
așa că adăugați 4 la ieșire.
Procesați interogările[5] = „-4” și eliminați toate instanțele lui 4 din numere, rezultând numere = [5, 6, 3]. Nu există nicio modalitate de a forma triplete care pot îndeplini condiția, așa că adăugați 0 la ieșire.

În cele din urmă, rezultatul este [0, 0, 1, 2, 4, 0].


Intrare/ieșire:
- [limită de timp de execuție] 0,5 secunde (cpp)

- [limită de memorie] 1 GB

- [intrare] interogări array.string:
O matrice de șiruri reprezentând interogări în formatul descris mai sus. Este garantat că toate numerele sunt numere întregi între -10^9, 10^9. De asemenea, este garantat că pentru fiecare interogare de eliminare, întregul
eliminat există în matricea de numere curentă.
Constrângeri garantate:
1 ≤ interogări.lungime ≤ 10^5.

- [intrare] diferență între întregi:
O valoare întreagă pozitivă reprezentând diferența așteptată în triplete.
Constrângeri garantate:
1 ≤ dif ≤ 10^9.

- [ieșire] array.integer:
După procesarea fiecărei interogări, numărați numărul de triple (x, y, z) în numere care îndeplinesc această condiție: x - y = y - z = dif. Este garantat că numărul se va potrivi întotdeauna într-un tip întreg semnat pe 
32 de biți. Returnează o serie de astfel de valori pentru toate interogările. */

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> queries, int diff) 
{
    vector<int> numbers;
    unordered_map<int, int> freq;

    auto countTriples = [&]() 
    {
        int tripleCount = 0;
    
        for (int num : numbers) 
        {
            if (freq.find(num - diff) != freq.end() && freq.find(num + diff) != freq.end()) 
            {
                tripleCount += freq[num - diff] * freq[num + diff];
            }
        }
        return tripleCount;
    };

    vector<int> result;
    for (const string& query : queries) 
    {
        char op = query[0];
        int num = stoi(query.substr(1));
      
        if (op == '+') {
            numbers.push_back(num);
            freq[num]++;
        } 
        else 
        {
            freq[num]--;
          
            if (freq[num] == 0)
                freq.erase(num);
            numbers.erase(remove(numbers.begin(), numbers.end(), num), numbers.end());
        }
        result.push_back(countTriples());
    }

    return result;
}
