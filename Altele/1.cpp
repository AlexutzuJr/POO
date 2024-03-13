/* Vi se dă un număr întreg de două cifre n. Returnează suma cifrelor sale.

Exemplu:
Pentru n=29, rezultatul ar trebui să fie: soluție(n)=11.


Intrare/ieșire:
-timp limita de executie 4 secunde (cpp)

-intreg n:
Un întreg pozitiv de două cifre.
Constrângeri garantate: 10<=n<=99

-număr întreg de ieșire:
Suma primei și a doua cifre ale numărului introdus. */

#include <iostream>

int solution(int n) 
{
    int tensDigit = n / 10;
    int onesDigit = n % 10;
    
    int sum = tensDigit + onesDigit;
    
    return sum;
}

int main() 
{
    int n = 29;
    std::cout << solution(n) << std::endl;
    
    return 0;
}
