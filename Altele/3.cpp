/* Imaginați-vă un joc video în care jucătorul controlează un personaj pentru a trece prin mai multe niveluri. Personajul are o valoare inițială de sănătate "initialHealth", iar această valoare se schimbă pe măsură ce 
jucătorul trece prin nivelurile jocului.

Vi se oferă o serie de numere întregi delta, definind fiecare modificare a valorii de sănătate. Mai exact, al "i"-lea nivel (indexat 0) modifică valoarea actuală a sănătății personajului cu deltas[i]. Rețineți că, ori de 
câte ori valoarea actuală a sănătății devine mai mică de 0, aceasta devine imediat setată la 0. În mod similar, ori de câte ori valoarea actuală a sănătății devine mai mare de 100, este imediat setată la 100.

Sarcina ta este să returnezi valoarea finală a sănătății personajului după ce jucătorul trece prin toate nivelurile jocului.

Notă: Nu se așteaptă să oferiți cea mai optimă soluție, dar o soluție cu o complexitate de timp nu mai slabă decât O(deltas.length^3) se va încadra în limita de timp de execuție.


Exemplu:

Pentru initialHealth = 12 și deltas = [-4, -12, 6, 2], rezultatul ar trebui să fie solution(initialHealth, deltas) = 8.

Să luăm în considerare fiecare nivel:
La început, valoarea actuală a sănătății este currentHealth = initialHealth = 12.
După finalizarea nivelului 0, valoarea actuală a sănătății devine currentHealth + deltas[0] = 12 + -4 = 8.
După finalizarea primului nivel, valoarea actuală de sănătate devine currentHealth + deltas[1] = 8 + -12 = -4, dar deoarece valoarea sănătății nu poate fi mai mică de 0, este setată la 0.
După finalizarea celui de-al doilea nivel, valoarea actuală a sănătății devine currentHealth + deltas[2] = 0 + 6 = 6.
După finalizarea nivelului 3, valoarea actuală a sănătății devine actualHealth + deltas[2] = 6 + 2 = 8, care este răspunsul final.


Intrare/ieșire:
- [limită de timp de execuție] 0,5 secunde (cpp)

- [limită de memorie] 1 GB

- [input] întreg initialHealth:
Un număr întreg care reprezintă valoarea inițială de sănătate a jucătorului.
Constrângeri garantate:
0 ≤ initialHealth ≤ 100.

- [intrare] array.integer deltas:
O serie de numere întregi care reprezintă modificări ale valorii actuale de sănătate după ce jucătorul finalizează fiecare nivel.
Constrângeri garantate:
1 ≤ deltas.lungime ≤ 100,
-100 ≤ deltas[i] ≤ 100.

- [ieșire] întreg:
Un număr întreg care reprezintă valoarea finală de sănătate a jucătorului. */

#include <vector>
#include <algorithm>

int solution(int initialHealth, std::vector<int> deltas) 
{
    int currentHealth = initialHealth;
  
    for (int delta : deltas) 
    {
        currentHealth += delta;
        currentHealth = std::max(0, std::min(currentHealth, 100)); 
    }
  
    return currentHealth;
}
