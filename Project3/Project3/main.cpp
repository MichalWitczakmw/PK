#include <iostream>
using namespace std;
int funkcja(int* tab, int szukana, const int ROZMIAR)
{
	int index=0;

	for (int i = 0; i < ROZMIAR; i++)
	{
		int raz = 0;
		for (int j = 0; j < ROZMIAR; j++)
		{

			if (*tab[i][j]=szukana)
			{
				raz = 1;

				break;
			}
		}
		if (raz=1)
		{
			break;
		}
	}

	return index;
}


int funkcja(int & tab, int szukana, const int ROZMIAR)
{
	int index = 0;


	return index;
}

struct DlaTab
{
	int cos;
	const char* tam;
};
struct szukana
{
	int szukanaINT;
	char szukanaCHAR;
};

int main()
{
	
	DlaTab tablica[6];

	tablica[0] = { 1, "a"};
	tablica[1] = { 2, "b"};
	tablica[2] = { 3, "c"};
	tablica[3] = { 4, "d"};
	tablica[4] = { 5, "e"};
	tablica[5] = { 6, "f"};

	szukana szuka;
	cout << "Podaj liczbe(1-6)" << endl;
	cin >> szuka.szukanaINT;
	cout << "podaj znak (a-f)" << endl;
	cin >> szuka.szukanaCHAR;

	fujnkcja(tablica,szuka , 6);
	
}

#include <cstdint>
#include <iostream>

using namespace std;

struct struktura
{
    int    calkowita;
    double rzeczywista;
};

int szukaj(struktura* tablica, const int rozmiar, struktura szukana)
{
    for (int i = 0; i < rozmiar; i++)
    {
        if (tablica->calkowita == szukana.calkowita &&
            tablica->rzeczywista == szukana.rzeczywista)
        {
            return i;
        }
    }
    throw std::runtime_error("Elementu nie znaleziono");
}

int szukaj(struktura* tablica, const int rozmiar, struktura szukana)
{
    int ostatni_indeks = -1;
    for (int i = 0; i < rozmiar; i++)
    {
        if (tablica->calkowita == szukana.calkowita &&
            tablica->rzeczywista == szukana.rzeczywista)
        {
            ostatni_indeks = i;
        }
    }
    if (ostatni_indeks == -1)
        throw std::runtime_error("Elementu nie znaleziono");
}

namespace Testy
{

    bool Test1()
    {
        try
        {
            struktura* tablica = new struktura[10];
            for (int i = 0; i < 10; i++)
            {
                tablica[i].calkowita = i;
                tablica[i].rzeczywista = double(i) / 3;
            }
            struktura szukana;
            szukana.calkowita = 11;
            szukana.rzeczywista = 0.1;
            szukaj(tablica, 10, szukana);
            return false;
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return true;
        }
    }
    bool Test2()
    {
        try
        {
            struktura* tablica = new struktura[10];
            for (int i = 0; i < 10; i++)
            {
                tablica[i].calkowita = i;
                tablica[i].rzeczywista = double(i) / 3.0;
            }
            struktura szukana;
            szukana.calkowita = 1;
            szukana.rzeczywista = 1.0 / 3.0;
            szukaj(tablica, 10, szukana);
            return true;
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return false;
        }
    }
    bool Test3()
    {
        try
        {
            struktura* tablica = new struktura[10];
            for (int i = 0; i < 10; i++)
            {
                tablica[i].calkowita = i;
                tablica[i].rzeczywista = double(i) / 3;
            }
            tablica[3].calkowita = 0;
            tablica[3].rzeczywista = 0.0;
            struktura szukana;
            szukana.calkowita = 0;
            szukana.rzeczywista = 0.0;
            szukaj(tablica, 10, szukana);
            return true;
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return false;
        }
    }

}; // namespace Testy

struct tablica_dynamiczna
{
    double* tablica = nullptr;
    uint32_t rozmiar = 0;
};

void alokuj(
    tablica_dynamiczna* tab,
    const uint32_t
    rozmiar) // w teorii uint32_t to bêdzie najprawdopodobniej unsigned int,
    // ale standard nie okreœla konkretnie ile bitów ma mieæ int
{
    delete[] tab->tablica;
    tab->tablica = new double[rozmiar];

    uint32_t zmiany =
        tab->rozmiar & 255; // 255 bo to 8 bitów w stanie "1", z operatorem "&"
    // zwracaj¹ AND, w tym przypadku kopiuj¹ wszystkie
    // jedynki z pierwszych oœmiu bitów rozmiaru;
    tab->rozmiar = (rozmiar << 24);
    tab->rozmiar += ++zmiany;
}

void dealokuj(tablica_dynamiczna* tab)
{
    tab->rozmiar =
        tab->rozmiar & 255; // 255 bo to 8 bitów w stanie "1", z operatorem "&"
    // zwracaj¹ AND, w tym przypadku kopiuj¹ wszystkie
    // jedynki z pierwszych oœmiu bitów rozmiaru;
    delete[] tab->tablica;
}

void czytajZPliku(tablica_dynamiczna* tab, const char* nazwa_pliku)
{
    /*nie pamiêtam jak sie to robilo z tymi FILE, ale powinieneœ to zrobiæ na
     * zasadzie przejechania przez plik i zliczenia danych, przewiniêcia g³owicy
     * na start, alokacji tablicy a nastêpnie jeszcze raz przejdŸ przez plik i
     * wczytaj dane do tablicy*/
}

int main() {}


#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

struct Tablica {
    double* tab = nullptr;
    int rozmiar = 0;
    int zmiany = 0;
};

void alokacja(Tablica& t, int rozmiar) {
    if (t.tab != nullptr) {
        delete[] t.tab;
    }
    t.rozmiar = rozmiar;
    t.zmiany++;
    t.tab = new double[rozmiar];
}
void delalokacja(Tablica& t) {
    delete[] t.tab;
    t.tab = nullptr;
    t.rozmiar = 0;
    t.zmiany = 0;
}

int main()
{
    int rozmiar = 0;
    double liczba;
    Tablica t;
    FILE* plik = nullptr;
    plik = fopen("text.txt", "r");
    while (fscanf(plik, "%lf,", &liczba) == 1) {
        rozmiar++;
    }
    fclose(plik);
    alokacja(t, rozmiar);
    plik = fopen("text.txt", "r");
    for (int i = 0; i < t.rozmiar; i++) {
        fscanf(plik, "%lf,", &t.tab[i]);
        cout << t.tab[i] << ", ";
    }
    fclose(plik);
    delalokacja(t);
    return 0;
}
