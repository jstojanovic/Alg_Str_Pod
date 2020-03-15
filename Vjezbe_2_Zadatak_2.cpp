#include <iostream> //std::cout,    std::cin
#include <fstream> //            std::fstream
#include <string> //               std::string
#include <stack> //std::stack<std::string> STEK
void  ucitaj_u_stog(std::fstream &File, int br_REDK, std::stack<std::string> &Stog){
    std::string Redak;   //                     n==50
    while( br_REDK!=0 ){//Citaj dok ne procitas n redaka
        getline( File, Redak );  // u i-teraciji kupi i+1 redak i sprema na Stog
        Stog.push( Redak );
        br_REDK--;
    }
}
void ispis_stoga(std::stack<std::string> &Stog){
    while( !Stog.empty() ){
        std::cout << Stog.top();
        Stog.pop();
    }

}
/*-------------------------------------------------------------------*/
int main()  {
    std::stack<std::string> STEK;
    while( STEK.size() < 200 ){
        STEK.push("REDAK = STRING\n");//*kako da imaju redne brojeve?
        //STEK.size()== 0 ,1 ,2 ,3...
    }
    //1. Zapiso u Stog 200 redaka

    std::fstream file;
    file.open("podaci.txt", std::ios::out);//<--
    //2.Stvorio, otvorio file da prepisem sa stoga u file

    while(!STEK.empty()){
        file << STEK.top();
        STEK.pop();               //skidam s Stoga vec zapisani redak
    }                            //Stog nakon petlje prazan=STEK.size()==0
    file.close();
    //4. Sve retke sa Stoga u file

    std::fstream FILE;
    FILE.open("podaci.txt", std::ios::in);//<--
    int br_redaka=50;
    ucitaj_u_stog( FILE, br_redaka, STEK);
    //5. zapiso 50 redaka iz fajla u stog. zadnji zapisani je prvi citani

    ispis_stoga(STEK);//ispisuje 50...0
    ispis_stoga(STEK);//ispisuje 100...50

    FILE.close();
}
/*-------------------------------------------------------------------*/
