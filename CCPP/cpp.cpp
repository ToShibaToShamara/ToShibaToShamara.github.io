#include <iostream> 

struct Radnik {
    char ime[20];
    char prezime[20];
    char bolovanje;
    int plata[5];
};

void UnesiPodatke(Radnik radnici[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << ">>> Unos podataka za radnika broj " << i + 1 << " <<<\n";

        std::cout << "Ime: ";
        std::cin >> radnici[i].ime;

        std::cout << "Prezime: ";
        std::cin >> radnici[i].prezime;

        std::cout << "Bolovanje (d - da, n - ne): ";
        std::cin >> radnici[i].bolovanje;

        std::cout << "Unesite 5 mesecnih plata:\n";
        for (int j = 0; j < 5; j++) {
            std::cout << "Plata [" << j + 1 << "]: ";
            std::cin >> radnici[i].plata[j];
        }
        std::cout << "-----------------------------\n";
    }
}

bool ImaBolovanje(Radnik radnik) {
    return (radnik.bolovanje == 'd' || radnik.bolovanje == 'D');
}

double IzracunajProsek(Radnik radnik) {
    double zbir = 0;
    for (int i = 0; i < 5; i++) {
        zbir += radnik.plata[i];
    }
    return zbir / 5;
}

int main() {
    int n;

    std::cout << "Koliko radnika zelite da unesete? ";
    std::cin >> n;

    Radnik* radnici = new Radnik[n];

    UnesiPodatke(radnici, n);

    int brojSaBolovanjem = 0;
    int indeksNajbolji = 0;
    double najboljiProsek = IzracunajProsek(radnici[0]);

    for (int i = 0; i < n; i++) {
        double prosek = IzracunajProsek(radnici[i]);
        if (prosek > najboljiProsek) {
            najboljiProsek = prosek;
            indeksNajbolji = i;
        }

        if (ImaBolovanje(radnici[i])) {
            brojSaBolovanjem++;
        }
    }

    std::cout << "\n*** REZULTATI ***\n";
    std::cout << "Radnik sa najvecim prosekom plata: " << radnici[indeksNajbolji].ime << " "  radnici[indeksNajbolji].prezime " (prosek: " << najboljiProsek << ")\n";

    std::cout << "Ukupan broj radnika koji su koristili bolovanje: " << brojSaBolovanjem << "\n";

    delete[] radnici;
    system("pause");
    return 0;
}
