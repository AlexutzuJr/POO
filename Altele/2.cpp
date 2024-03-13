/* Să presupunem că un triplet (a, b, c) este un zigzag dacă, fie a < b > c, fie a > b < c.

Având în vedere o serie de numere întregi, sarcina ta este să verifici toate triplele elementelor sale consecutive pentru a fi în zig-zag. Mai formal, sarcina dvs. este să construiți o matrice de numere de lungime
numere.lungime - 2, unde elementul "i" al matricei de ieșire este egal cu 1 dacă tripletul (numere[i], numere[i + 1], numere[i + 2]) este un zigzag, iar 0 în caz contrar.


Exemplu:

Pentru numere = [1, 2, 1, 3, 4], rezultatul ar trebui să fie soluție(numere) = [1, 1, 0].

(numere[0], numere[1], numere[2]) = (1, 2, 1) este un zigzag, deoarece 1 < 2 > 1;
(numere[1], numere[2] , numere[3]) = (2, 1, 3) este un zig-zag, deoarece 2 > 1 < 3;
(numerele[2], numerele[3] , numere[4]) = (1, 3, 4) nu este zigzag, deoarece 1 < 3 < 4;

Pentru numere = [1, 2, 3, 4], rezultatul ar trebui să fie soluție(numere) = [0, 0];
Deoarece toate elementele numerelor cresc, nu există zigzaguri.

Pentru numere = [1000000000, 1000000000, 1000000000], rezultatul ar trebui să fie soluție(numere) = [0].
Deoarece toate elementele numerelor sunt aceleași, nu există zigzaguri.


Intrare/ieșire:
- [limită de timp de execuție] 4 secunde (cpp)

- [limită de memorie] 1 GB

- [intrare] matrice.intreg numere:
O matrice de numere întregi.
Constrângeri garantate:
3 ≤ numere.lungime ≤ 100,
1 ≤ numere[i] ≤ 10^9.

- [ieșire] matrice.intreg:
Returnează o matrice, în care elementul "i" este egal cu 1 dacă tripletul (numere[i], numere[i + 1], numere[i + 2]) este un zigzag, iar 0 în caz contrar. */

#include <iostream>
#include <vector>

std::vector<int> solution(std::vector<int>& numbers) 
{
    std::vector<int> result;
    
    for (int i = 0; i < numbers.size() - 2; i++) 
    {
        int a = numbers[i];
        int b = numbers[i + 1];
        int c = numbers[i + 2];
        
        if ((a < b && b > c) || (a > b && b < c)) 
        {
            result.push_back(1);
        } 
        else 
        {
            result.push_back(0);
        }
    }
    
    return result;
}

int main() 
{
    std::vector<int> numbers1 = {1, 2, 1, 3, 4};
    std::vector<int> result1 = solution(numbers1);
  
    for (int i = 0; i < result1.size(); i++) 
    {
        std::cout << result1[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> numbers2 = {1, 2, 3, 4};
    std::vector<int> result2 = solution(numbers2);
  
    for (int i = 0; i < result2.size(); i++) 
    {
        std::cout << result2[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> numbers3 = {1000000000, 1000000000, 1000000000};
    std::vector<int> result3 = solution(numbers3);
    
    for (int i = 0; i < result3.size(); i++) 
    {
        std::cout << result3[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
