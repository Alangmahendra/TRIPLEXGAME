#include <iostream>
#include <ctime>

void PrintIntroduction (int Difficulty)
{
    std::cout << "Anda Adalah Seorang Stalker Pemula "; //Print This Sentences On Terminal
    std::cout << "Dan Target Stalk Anda Adalah Gebetan Anda\n";
    std::cout << "Akan Tetapi Ponsel Gebetan Anda Di Proteksi Oleh Sistem Keamanan BERLAPIS Dan Sekarang Anda Di Level " << Difficulty << "\n";
    std::cout << "Tugas Anda Adalah Untuk Memacahkan Kode Keamanan Berlapis Tersebut\n" ;

}

bool PlayGame(int Difficulty) 
{
    PrintIntroduction(Difficulty);

    const int FirstNumber  = rand() % Difficulty + Difficulty;
    const int SecondNumber = rand() % Difficulty + Difficulty;
    const int ThirdNumber  = rand() % Difficulty + Difficulty;

    const int CodeSum = FirstNumber + SecondNumber + ThirdNumber;
    const int CodeMultiply = FirstNumber * SecondNumber * ThirdNumber;

    std::cout << "Ada TIGA ANGKA" ;
    std::cout << "\n+ Jumlah Total Penambahan Angka Adalah : " << CodeSum ;
    std::cout << "\n+ Jumlah Total Perkalian Angka Adalah : " << CodeMultiply << "\n" ; 

    //Store Player Guess
    int TebakanA, TebakanB, TebakanC;
    std::cin >> TebakanA;
    std::cin >> TebakanB;
    std::cin >> TebakanC;
    std::cout << "+ Tebakan Anda : " << TebakanA << " " << TebakanB << " " << TebakanC ;

    int GuessSum = TebakanA + TebakanB + TebakanC ;
    int GuessProduct = TebakanA * TebakanB * TebakanC ;

    //Check Player Guess
    if (GuessSum == CodeSum && GuessProduct == CodeMultiply)
    {
        std::cout << " YEP !!! Lapisan Ke "<< Difficulty << " Berhasil Kamu Lewati,Lanjutkan Ke Lapisan Selanjutnya !!!\n";
        return true ;
    }else
    {
        std::cout << " Kode Pin Yang Anda Masukkan Salah,Coba Lagi !!!\n";
        return false ;
    }


}

const int main()
{ 
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxLevel = 5 ;

    while (LevelDifficulty <= MaxLevel)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }

    std::cout << "\nSELAMAT ANDA STALKER!!!" ;
    return 0;
}

