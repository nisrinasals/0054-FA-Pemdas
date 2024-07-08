/**
 * @mainpage Sistem Penilaian Mata Kuliah
 *
 * @section intro_sec Pendahuluan
 * Program ini untuk menggambarkan sistem dari Penilaian Mata Kuliah
 *  
 * @section note_sec Struktur program
 * Program ini terdiri dari tiga kelas utama:
 * - \b MataKuliah: Merupakan Base Class
 * - \b Pemrograman: Menangani informasi dari Mata Kuliah Pemrograman
 * - \b Jaringan: Menangani informasi dari Mata Kuliah Jaringan
 * 
 */

/**
 * @file ucp3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
using namespace std;

class MataKuliah {
protected: 
    float presensi; ///Menyimpan Nilai dari Presensi
    float activity; ///Menyimpan Nilai dari Activity
    float exercise; ///Menyimpan Nilai dari Exercise
    float tugasAkhir;   ///Menyimpan Nilai dari Tugas Akhir
    int nilaiAkhir; ///Menyimpan Nilai Akhir yang telah dihitung

public:
    MataKuliah(){
        presensi = 0.0; ///Mengisi nilai awal Presensi
        activity = 0.0; ///Mengisi nilai awal Activity
        exercise = 0.0; ///Mengisi nilai awal Exercise
        tugasAkhir = 0.0;   ///Mengisi nilai awal Tugas Akhir
    }

    virtual void namaMataKuliah() {
         return; 
    }

    virtual void inputNilai(){
        return;
    }

    virtual void hitungNilaiAkhir(){
        return;
    }
    virtual void cekKelulusan(){
        return;
    }

    void setPresensi(float nilai){  ///Mengatur nilai Presensi
        this->presensi = nilai;
    }

    float getPresensi(){
    return presensi;
    }

    void setActivity(float nilai){  ///Mengatur nilai Activity
        this->activity = nilai;
    }

    float getActivity(){
    return activity;
    }

    void setExercise(float nilai){  ///Mengatur nilai Exercise
        this->exercise = nilai;
    }

    float getExercise(){
    return exercise;
    }

    void setTugasAkhir(float nilai){  ///Mengatur nilai Tugas Akhir
        this->tugasAkhir = nilai;
    }

    float getTugasAkhir(){
    return tugasAkhir;
    }
};

class Pemrograman : public MataKuliah{
public:
    void MataKuliah() {
        cout << "Mata Kuliah Pemrograman";
    }

    void inputNilai() { ///Input Nilai untuk Mata Kuliah Pemrograman
        cout << "Masukkan Nilai Presensi Mata Kuliah Pemrograman: ";
        cin >> presensi;

        cout << "Masukkan Nilai Activity Mata Kuliah Pemrograman: ";
        cin >> activity;

        cout << "Masukkan Nilai Exercise Mata Kuliah Pemrograman: ";
        cin >> exercise;

        cout << "Masukkan Nilai Tugas Akhir Mata Kuliah Pemrograman: ";
        cin >> tugasAkhir;
    }

    void hitungNilaiAkhir(){    ///Menghitung Nilai Akhir untuk Mata Kuliah Pemrograman
        nilaiAkhir = (presensi + activity + exercise + tugasAkhir)/4;
        cout << "Nilai akhir : " << nilaiAkhir << endl;
    }

    void cekKelulusan() {   ///Mengecek Kelulusan untuk Mata Kuliah Pemrograman
        if (nilaiAkhir >= 75) {
            cout << "Selamat Anda dinyatakan Lulus" << endl << endl;
        } else {
            cout << "Anda dinyatakan Tidak Lulus" << endl << endl;
        }
    }
};

class Jaringan : public MataKuliah{
public:
    void MataKuliah() {
        cout << "Mata Kuliah Jaringan";
    }

    void inputNilai() { ///Input Nilai untuk Mata Kuliah Jaringan
        cout << "Masukkan Nilai Activity Mata Kuliah Jaringan: ";
        cin >> activity;

        cout << "Masukkan Nilai Exercise Mata Kuliah Jaringan: ";
        cin >> exercise;
    }

    void hitungNilaiAkhir(){    ///Menghitung Nilai Akhir untuk Mata Kuliah Jaringan
        nilaiAkhir = (activity + exercise)/2;
        cout << "Nilai akhir : " << nilaiAkhir << endl;
    }

    void cekKelulusan(){    ///Mengecek Kelulusan untuk Mata Kuliah Jaringan
        if (nilaiAkhir >= 75) {
            cout << "Selamat Anda dinyatakan Lulus" << endl << endl;
        } else {
            cout << "Anda dinyatakan Tidak Lulus" << endl << endl;
        }
    }
};

int main(){
char pilih;
MataKuliah *mataKuliah;
Pemrograman pemrograman;
Jaringan jaringan;

	do {
        ///Membuat Menu Awal
		cout << "Pilih Mata Kuliah :" << endl;
		cout << "1. Pemrograman " << endl;
		cout << "2. Jaringan " << endl;
		cout << "3. Keluar" << endl;
		cout << "Pilih :" << endl;
		cin >> pilih;


	switch (pilih) {
	case '1':   ///Pilihan 1: Pemrograman
		pemrograman.inputNilai();
        pemrograman.hitungNilaiAkhir();
        pemrograman.cekKelulusan();
		break;
        
	case '2':   ///Pilihan 2: Jaringan
		jaringan.inputNilai();
        jaringan.hitungNilaiAkhir();
        jaringan.cekKelulusan();
		break;

	case '3':   ///Pilihan 3: Keluar
		break;

	default:
		cout << "Pilihan tidak ada" << endl;    ///Pilihan tidak tersedia
		system("pause");
		break;
	}
	system("pause");
	} while (pilih = 1 || 2 || 3);
}
