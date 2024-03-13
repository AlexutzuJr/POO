/* Pentru o gamă dată de recenzii șiruri de caractere care reprezintă recenzii despre produse, determinați sentimentul fiecărei recenzii - indiferent dacă este pozitiv, negativ sau neutru. Pentru a procesa sentimentul 
recenziilor, vi se oferă trei matrice de șiruri: "cuvintePozitive" care conțin toate cuvintele care sunt considerate pozitive, "cuvinteNegative" care conțin toate cuvintele care sunt considerate negative și intensificatoare 
care conțin cuvinte care măresc impactul următorului cuvânt întâlnit din cuvintePozitive sau cuvinteNegative câte unul. Specific:
O recenzie este considerată pozitivă dacă conține mai multe cuvinte pozitive decât cuvinte negative.
O recenzie este considerată negativă dacă conține mai multe cuvinte negative decât cuvinte pozitive.
O recenzie este considerată neutră dacă are un număr egal de cuvinte pozitive și negative.

Este garantat că fiecare recenzie conține numai cuvinte (formate din litere mici) care sunt separate prin spații unice și că toate recenziile nu vor începe sau se vor termina cu un spațiu. De asemenea, este garantat că 
cuvintele pozitive, cuvintele negative și intensificatoarele vor conține cuvinte distincte (adică, dacă un cuvânt este într-unul, nu va fi în celălalt), iar toate cuvintele din matrice constau numai din litere mici.

Returnează o matrice de șiruri de caractere, unde șirul "i" este „pozitiv”, „negativ” sau „neutru”, în funcție de sentimentul revizuirii "i", așa cum este definit mai sus.

Notă: Nu se așteaptă să oferiți cea mai optimă soluție, dar se va potrivi o soluție cu o complexitate în timp nu mai rea decât O(reviews.length × (positiveWords.length + negativeWords.length + intensifiers.length) × 
x longestWord.length^2) in termenul de executie.


Exemplu:

Pentru recenzii = [„foarte violet și bun”, „foarte foarte rău unul dintre cele mai rele”, „bun, dar mai rău decât analogul”, „”], pozitivWords = [„bun”, „cel mai bun”], negativWords = [”rău ", "mai rău", "cel mai rău"] și 
intensificatori = ["foarte"], rezultatul ar trebui să fie soluție(recenzii, cuvinte pozitive, cuvinte negative, intensificatoare) = ["pozitiv", "negativ", "neutru", "neutru"].

Explicaţie:
Prima recenzie constă din cuvintele „foarte” și „bine”. Cuvântul „foarte” intensifică următorul cuvânt bun sau rău. Cuvintele „violet” și „și” nu sunt în niciuna dintre listele de cuvinte, așa că sunt ignorate. Următorul 
cuvânt este „bun”, care este intensificat cu „foarte”, așa că această recenzie are 2 sentimente pozitive și 0 sentimente negative. Deoarece 2 > 0, această evaluare este considerată „pozitivă”.

A doua recenzie începe cu „foarte” și „foarte”, astfel încât următorul cuvânt de sentiment va fi crescut cu 2. Următorul sentiment este rău, deci este considerat a fi 3 afirmații negative. Recenzia conține, de asemenea, 
cuvântul „cel mai rău”, astfel încât sentimentul negativ final este 4. Nu există cuvinte pozitive, deci recenzia este considerată „negativă”.

A treia recenzie are 1 cuvânt negativ și 1 cuvânt pozitiv, deci această recenzie este considerată „neutră”.
Ultima recenzie nu are deloc cuvinte, ceea ce este considerat a fi „neutru”.


Intrare ieșire:
- [limită de timp de execuție] 0,5 secunde (cpp)

- [limită de memorie] 1 GB

- [intrare] recenzii array.string:
O serie de recenzii. Este garantat că fiecare recenzie constă numai din litere și spații engleze mici.
Constrângeri garantate:
1 ≤ recenzii.lungime ≤ 100,
0 ≤ recenzii[i].lungime ≤ 500.

- [intrare] array.string pozitiveWords:
O serie de cuvinte pozitive. Este garantat că fiecare cuvânt constă numai din litere mici engleze.
Constrângeri garantate:
1 ≤ Cuvinte pozitive.lungime ≤ 100,
1 ≤ Cuvinte pozitive[i].lungime ≤ 10.

- [intrare] array.string negativeWords:
O serie de cuvinte negative. Este garantat că fiecare cuvânt constă numai din litere mici engleze.
Constrângeri garantate:
1 ≤ cuvinte negative.lungime ≤ 100,
1 ≤ Cuvinte negative[i].lungime ≤ 10.

- [intrare] intensificatoare array.string:
O serie de cuvinte intensificatoare. Este garantat că fiecare cuvânt constă numai din litere mici engleze.
Constrângeri garantate:
0 ≤ intensificatoare.lungime ≤ 100,
1 ≤ intensificatoare[i].lungime ≤ 10.

- [ieșire] array.string:
O serie de șiruri care conțin fie un verdict pozitiv, negativ sau neutru pentru fiecare recenzie. */

#include <vector>
#include <string>
#include <unordered_set>
#include <sstream>

using namespace std;

bool isIntensifier(const string& word, const unordered_set<string>& intensifiers) 
{
    return intensifiers.count(word) > 0;
}

string determineSentiment(const string& review, const unordered_set<string>& positiveWords, const unordered_set<string>& negativeWords, const unordered_set<string>& intensifiers) 
{
    int positiveCount = 0, negativeCount = 0;
    string word;
    bool intensified = false;
    
    for (char c : review) 
    {
        if (c == ' ') 
        {
            if (!word.empty()) 
            {
                if (positiveWords.count(word)) 
                {
                    if (intensified)
                        positiveCount += 2;
                    else
                        positiveCount++;
                } 
                else if (negativeWords.count(word)) 
                {
                    if (intensified)
                        negativeCount += 2;
                    else
                        negativeCount++;
                }
                word.clear();
                intensified = false;
            }
        } 
        else 
        {
            word += c;
          
            if (isIntensifier(word, intensifiers)) 
            {
                intensified = true;
                word.clear(); 
            }
        }
    }
    
    if (!word.empty()) 
    {
        if (positiveWords.count(word)) 
        {
            if (intensified)
                positiveCount += 2;
            else
                positiveCount++;
        } 
        else if (negativeWords.count(word)) 
        {
            if (intensified)
                negativeCount += 2;
            else
                negativeCount++;
        }
    }

    if (positiveCount > negativeCount)
        return "positive";
    else if (positiveCount < negativeCount)
        return "negative";
    else
        return "neutral";
}

vector<string> solution(vector<string> reviews, vector<string> positiveWords, vector<string> negativeWords, vector<string> intensifiers) 
{
    unordered_set<string> positiveSet(positiveWords.begin(), positiveWords.end());
    unordered_set<string> negativeSet(negativeWords.begin(), negativeWords.end());
    unordered_set<string> intensifierSet(intensifiers.begin(), intensifiers.end());

    vector<string> result;
    for (const string& review : reviews) 
    {
        if (review.empty()) 
        {
            result.push_back("neutral"); 
        } 
        else 
        {
            result.push_back(determineSentiment(review, positiveSet, negativeSet, intensifierSet));
        }
    }
    return result;
}
