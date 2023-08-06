/* Să se scrie un program care execută operațiile de adunare, scădere și înmulțire între două matrice. Operația se va alege în funcție de o valoare de test citită de la tastatură.
Se citesc de la tastatură:
- doi întregi, m și n, reprezentând dimensiunile primei matrice
- m x n întregi, reprezentând elementele primei matrice
- doi întregi, q și p, reprezentând dimensiunile celei de-a doua matrice
- q x p întregi, reprezentând elementele celei de-a doua matrice
- un întreg, test, reprezentând valoarea în funcție de care se execută diverse funcții:
1. adunare matrice - se afișează pe ecran elementele matricei obținută prin adunarea celor două matrice de intrare.
2. scădere matrice -  se afișează pe ecran elementele matricei obținută prin scăderea celei de-a doua matrice din prima matrice.
3. înmulțire matrice - se afișează pe ecran elementele matricei obținută prin înmulțirea primei matrice cu cea de-a doua matrice. */
    
#include <stdio.h>
#include <iostream>

class Matrice
{
public:
    int n, m;
    int M[100][100];

public:
    Matrice() {}
    Matrice(int n, int m) : n(n), m(m)
    {
    }
    void citire()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                std::cin >> this->M[i][j];
    }
    void afisare()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                std::cout << this->M[i][j] << " ";
            std::cout << "\n";
        }
    }
    Matrice operator+(const Matrice &m)
    {
        Matrice C = Matrice(m.n, m.m);
        for (int i = 0; i < m.n; i++)
            for (int j = 0; j < m.m; j++)
                C.M[i][j] = this->M[i][j] + m.M[i][j];
        return C;
    }
    Matrice operator-(const Matrice &m)
    {
        Matrice C = Matrice(m.n, m.m);
        for (int i = 0; i < m.n; i++)
            for (int j = 0; j < m.m; j++)
                C.M[i][j] = this->M[i][j] - m.M[i][j];
        return C;
    }

    Matrice operator*(const Matrice &m)
    {
        Matrice C = Matrice(this->n, m.m);

        for (int i = 0; i < this->n; i++)
        {
            for (int j = 0; j < m.m; j++)
            {
                C.M[i][j] = 0;
                for (int k = 0; k < m.n; k++)
                {
                    C.M[i][j] += this->M[i][k] * m.M[k][j];
                }
            }
        }
        return C;
    }
};

int main()
{
    int n, m;
    std::cin >> n >> m;
    Matrice A = Matrice(n, m);
    A.citire();
    std::cin >> n >> m;
    Matrice B = Matrice(n, m);
    B.citire();
    std::cin >> n;
    if (n == 1)
        (A + B).afisare();
    if (n == 2)
        (A - B).afisare();
    if (n == 3)
        (A * B).afisare();
    return 0;
}
