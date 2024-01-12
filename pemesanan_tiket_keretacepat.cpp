// Script by Adi Maulana
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

// Function to get the current time
string getCurrentTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    stringstream ss;
    ss << setfill('0') << setw(2) << ltm->tm_hour << ":" << setw(2) << ltm->tm_min;

    return ss.str();
}

int main() {
    int hargaTiket, pilihanKereta, pilihanKelas, jumlahTiket, totalBayar, uangDibayar, kembalian;
    
    // Daftar kereta yang tersedia, harga tiket, dan jadwal
    const string trains[] = {"Arjuna Express", "Harina Fast", "Gajayana Express"};
    const double economyPrices[] = {80000, 120000, 100000};
    const double businessPrices[] = {120000, 180000, 150000};
    const string schedules[] = {"08:00", "12:30", "15:45"};
    
    // Input pilihan kereta
    cout << "\n---- SISTEM PEMESANAN TIKET KERETA CEPAT ----\n";

    cout << "Daftar kereta:\n";
    for (int i = 0; i < sizeof(trains) / sizeof(trains[0]); ++i) {
        cout << i + 1 << ". " << trains[i] << " - Jadwal: " << schedules[i] << endl;
    }

    int choice;
    cout << "\nPilih kereta (1-" << sizeof(trains) / sizeof(trains[0]) << "): ";
    cin >> choice;

    if (choice < 1 || choice > sizeof(trains) / sizeof(trains[0])) {
        cout << "Pilihan tidak valid.\n";
        return 1;
    }

    // Input kelas tiket
    cout << "Pilih kelas tiket:\n";
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << ". " << ((i == 0) ? "Economy" : "Business") << endl;
    }

    cout << "Pilih kelas (1-2): ";
    cin >> pilihanKelas;

    if (pilihanKelas < 1 || pilihanKelas > 2) {
        cout << "Pilihan tidak valid.\n";
        return 1;
    }

    // Input jumlah tiket yang dibeli
    cout << "Masukkan jumlah tiket yang dibeli: ";
    cin >> jumlahTiket;

    // Menggunakan indeks kereta yang dipilih untuk mendapatkan harga tiket yang sesuai
    hargaTiket = (pilihanKelas == 1) ? economyPrices[choice - 1] : businessPrices[choice - 1];

    // Hitung total pembayaran
    totalBayar = hargaTiket * jumlahTiket;

    // Tampilkan total pembayaran
    cout << "Total pembayaran: Rp " << totalBayar << endl;

    // Tampilkan jadwal dan hitung waktu keberangkatan
    cout << "Jadwal keberangkatan: " << schedules[choice - 1] << endl;
    
    string currentTime = getCurrentTime();
    cout << "Waktu saat ini: " << currentTime << endl;
    
    // Hitung waktu keberangkatan
    // (asumsi waktu keberangkatan selalu setelah waktu saat ini)
    // (asumsi format waktu adalah HH:MM)
    int departureHour = stoi(schedules[choice - 1].substr(0, 2));
    int departureMinute = stoi(schedules[choice - 1].substr(3, 2));
    
    int currentHour = stoi(currentTime.substr(0, 2));
    int currentMinute = stoi(currentTime.substr(3, 2));
    
    int minutesToDeparture = (departureHour - currentHour) * 60 + (departureMinute - currentMinute);
    
    cout << "Waktu hingga keberangkatan: " << minutesToDeparture << " menit\n";

    // Input uang yang dibayarkan
    cout << "Masukkan uang yang dibayarkan: ";
    cin >> uangDibayar;

    // Hitung kembalian
    kembalian = uangDibayar - totalBayar;

    // Tampilkan kembalian
    if (kembalian >= 0) {
        cout << "Kembalian: Rp " << kembalian << endl;
    } else {
        cout << "Uang yang dibayarkan kurang!" << endl;
    }

    return 0;
}
