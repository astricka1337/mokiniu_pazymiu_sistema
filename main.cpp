#include <iostream>
#include <string>
#include <iomanip>

using namespace std;// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

const int MAX_MOKINIAI = 100;
const int MAX_PAZYMIAI = 10;

int main() {
    string vardai[MAX_MOKINIAI];
    int pazymiai[MAX_MOKINIAI][MAX_PAZYMIAI];
    int pazymiuKiekis[MAX_MOKINIAI] = {0}; // sekti kiek kiekvienas turi pazymiu
    int esamasMokiniuSkaicius = 0;

    int pasirinkimas;
    do {
        cout << "Meniu";
        cout << "1. Prideti nauja mokini";
        cout << "2. Perziureti visus mokiniu";
        cout << "3. Atnaujinti konkretu pazymi";
        cout << "4. Pasalinti mokini";
        cout << "0. Iseiti";
        cout << "Pasirinkite veiksma: ";
        cin >> pasirinkimas;
    }
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.

    const auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";

    for (int i = 1; i <= 5; i++) {
        // TIP Press <shortcut actionId="Debug"/> to start debugging your code. We have set one <icon src="AllIcons.Debugger.Db_set_breakpoint"/> breakpoint for you, but you can always add more by pressing <shortcut actionId="ToggleLineBreakpoint"/>.
        std::cout << "i = " << i << std::endl;
    }

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}