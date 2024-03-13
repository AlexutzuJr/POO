/* Imaginați-vă o masă de dimensiunea numRows × numColumns cu niște lasere plasate pe ea. Aceste lasere sunt plasate la coordonatele specificate în matricea bidimensională "laserCoordinates", unde "laserCoordinates[i]" 
este o matrice cu două elemente care conține coordonatele pentru centrul al celui de-al "i-lea" laser. Laserele cu un centru într-o celulă (rând, coloană) distrug totul în același rând (adică rânduri cu rând index) și 
aceeași coloană (adică coloane cu coloană index).

Acum imaginați-vă că există un robot la coordonate (curRow, curColumn). Robotul se poate mișca doar în linie dreaptă, fie la stânga, la dreapta, în sus sau în jos în cadrul acestei mese. Sarcina ta este să numeri 
numărul maxim de celule prin care robotul se poate deplasa în siguranță (în orice direcție) înainte de a fi distrus de lasere.

Notă: Puteți presupune că celula inițială este protejată, iar laserele nu pot distruge robotul acolo chiar dacă acopera această celulă în zona lor de distrugere.

Notă: Nu se așteaptă să oferiți cea mai optimă soluție, dar o soluție cu o complexitate de timp nu mai slabă decât O(numRows · numColumns · laserCoordinates.length) se va încadra în limita de timp de execuție.


Exemplu:
Pentru numRows = 8, numColumns = 8, curRow = 5, curColumn = 3 și laserCoordinates = [[1, 6], [2, 8]], rezultatul ar trebui să fie soluție(numRows, numColumns, curRow, curColumn, laserCoordinates) = 3.

Explicaţie:
Având în vedere placa 8 × 8, există două lasere cu centre la celulele (1, 6) și (2, 8). Animația de mai jos arată că cea mai lungă cale sigură pentru robot este 3.


Intrare/ieșire:
- [limită de timp de execuție] 0,5 secunde (cpp)

- [limită de memorie] 1 GB

- [intrare] număr întreg numRows:
Un număr întreg care reprezintă numărul de rânduri dintr-un tablou.
Constrângeri garantate:
8 ≤ numRows ≤ 20.

- [intrare] număr întreg numColumns:
Un număr întreg care reprezintă numărul de coloane dintr-un panou.
Constrângeri garantate:
8 ≤ numColumns ≤ 20.

- [intrare] întreg curRow:
Un număr întreg care reprezintă rândul inițial în care se află robotul.
Constrângeri garantate:
1 ≤ curRow ≤ numRows.

- [intrare] întreg curColumn:
Un număr întreg reprezentând coloana inițială în care se află robotul.
Constrângeri garantate:
1 ≤ curColumn ≤ numColumns.

- [intrare] array.array.integer laserCoordinates:
O matrice de matrice de 2 elemente reprezentând coordonatele centrelor laser. Începând din centru, laserele vor trage în toate direcțiile (nediagonale) până când vor atinge marginile tablei. Este garantat că robotul 
va porni de la o celulă diferită de toate centrele laser.
Constrângeri garantate:
0 ≤ laserCoordonate.lungime ≤ 5,
laserCoordinates[i].lungime = 2,
1 ≤ laserCoordonate[i][0] ≤ numRows,
1 ≤ laserCoordonate[i][1] ≤ numColumns.

- [ieșire] întreg:
Returnați numărul maxim de celule prin care robotul se poate deplasa (în orice direcție), respectând cerințele descrise mai sus. */ 

#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool withinBoard(int row, int col, int numRows, int numColumns) 
{
    return row >= 1 && row <= numRows && col >= 1 && col <= numColumns;
}

bool isHitByLaser(int row, int col, const vector<vector<int>>& laserCoordinates) 
{
    for (const auto& laser : laserCoordinates) 
    {
        int laserRow = laser[0];
        int laserCol = laser[1];
        if (row == laserRow || col == laserCol) 
        {
            return true;
        }
    }
    return false;
}

int solution(int numRows, int numColumns, int curRow, int curColumn, vector<vector<int>> laserCoordinates) 
{
    int maxDistance = 0;

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (const auto& dir : directions) 
    {
        int dx = dir.first;
        int dy = dir.second;
        int row = curRow;
        int col = curColumn;
        int distance = 0;

        while (withinBoard(row + dx, col + dy, numRows, numColumns) && !isHitByLaser(row + dx, col + dy, laserCoordinates)) 
        {
            row += dx;
            col += dy;
            distance++;
        }

        maxDistance = max(maxDistance, distance);
    }

    return maxDistance;
}
