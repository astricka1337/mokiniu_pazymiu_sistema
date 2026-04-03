#include <iostream>
#include <string>
#include <iomanip>

using namespace std;// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

const int MAX_MOKINIAI = 100;
const int MAX_PAZYMIAI = 10;

int main() {
    string vardai[MAX_MOKINIAI];
    int pazymiai[MAX_MOKINIAI][MAX_PAZYMIAI];
    int pazymiuKiekis[MAX_MOKINIAI] = {0}; // Sekti, kiek kiekvienas turi pazymiu
    int esamasMokiniuSkaicius = 0;

    int pasirinkimas;

    do {
        cout << "\n--- MOKINIU PAZYMIU SISTEMA ---\n";
        cout << "1. Prideti nauja mokini\n";
        cout << "2. Perziureti visus mokinius\n";
        cout << "3. Atnaujinti konkretu pazymi\n";
        cout << "4. Pasalinti mokini\n";
        cout << "0. Iseiti\n";
        cout << "Pasirinkite veiksma: ";
        cin >> pasirinkimas;

        if (pasirinkimas == 1) {
            if (esamasMokiniuSkaicius < MAX_MOKINIAI) {
                cout << "Iveskite mokinio varda: ";
                cin >> vardai[esamasMokiniuSkaicius];

                int kiek;
                cout << "Kiek pazymiu (iki " << MAX_PAZYMIAI << ") norite ivesti? ";
                cin >> kiek;

                if (kiek > MAX_PAZYMIAI) kiek = MAX_PAZYMIAI;

                pazymiuKiekis[esamasMokiniuSkaicius] = kiek;
                for (int i = 0; i < kiek; i++) {
                    cout << "Iveskite " << i + 1 << "-aji pazymi: ";
                    cin >> pazymiai[esamasMokiniuSkaicius][i];
                }
                esamasMokiniuSkaicius++;
                cout << "Mokinys sekmingai pridetas!\n";
            } else {
                cout << "Sarasas pilnas!\n";
            }
        }
        else if (pasirinkimas == 2) {
            if (esamasMokiniuSkaicius == 0) {
                cout << "Sarasas tuscias.\n";
            } else {
                cout << "\nID | Vardas      | Pazymiai\n";
                cout << "---------------------------\n";
                for (int i = 0; i < esamasMokiniuSkaicius; i++) {
                    cout << i << "  | " << setw(10) << left << vardai[i] << " | ";
                    for (int j = 0; j < pazymiuKiekis[i]; j++) {
                        cout << pazymiai[i][j] << " ";
                    }
                    cout << endl;
                }
            }
        }
        else if (pasirinkimas == 3) {
            int id, p_indeksas, naujas_pazymys;
            cout << "Iveskite mokinio ID (is saraso): ";
            cin >> id;

            if (id >= 0 && id < esamasMokiniuSkaicius) {
                cout << "Mokinys: " << vardai[id] << ". Pazymiai: ";
                for (int j = 0; j < pazymiuKiekis[id]; j++) cout << pazymiai[id][j] << " ";

                cout << "\nKuri pazymi keisti (1-" << pazymiuKiekis[id] << ")? ";
                cin >> p_indeksas;

                if (p_indeksas >= 1 && p_indeksas <= pazymiuKiekis[id]) {
                    cout << "Iveskite nauja pazymi: ";
                    cin >> naujas_pazymys;
                    pazymiai[id][p_indeksas - 1] = naujas_pazymys;
                    cout << "Atnaujinta!\n";
                } else {
                    cout << "Neteisingas pazymio numeris.\n";
                }
            } else {
                cout << "Mokinys nerastas.\n";
            }
        }
        else if (pasirinkimas == 4) {
            int id;
            cout << "Iveskite mokinio ID, kuri norite pasalinti: ";
            cin >> id;

            if (id >= 0 && id < esamasMokiniuSkaicius) {
                // Perstumiame visus elementus kairėn, kad užpildytume skylę
                for (int i = id; i < esamasMokiniuSkaicius - 1; i++) {
                    vardai[i] = vardai[i + 1];
                    pazymiuKiekis[i] = pazymiuKiekis[i + 1];
                    for (int j = 0; j < MAX_PAZYMIAI; j++) {
                        pazymiai[i][j] = pazymiai[i + 1][j];
                    }
                }
                esamasMokiniuSkaicius--;
                cout << "Mokinys pasalinamas.\n";
            } else {
                cout << "Neteisingas ID.\n";
            }
        }
    } while (pasirinkimas != 0);

    return 0;
}