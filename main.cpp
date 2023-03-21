#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int i=0;
class BonDeMasa
{
private:
    int id;
    string emitent;
    float valoare;

public:
    BonDeMasa()
    {
        id=-1;
        emitent="??";
        valoare=0;
    }
    BonDeMasa(const int nr,const string emitent1,const float pret)
    {
        id = nr;
        emitent = emitent1;
        valoare = pret;
    }
    BonDeMasa& operator=(const BonDeMasa& other)
    {
        id = other.id;
        emitent = other.emitent;
        valoare = other.valoare;
        return *this;
    }
    string getEmitent()
    {
        return emitent;
    }

    friend ostream& operator<<(ostream& os, const BonDeMasa& bonDeMasa);
    friend istream& operator>>(istream& os, BonDeMasa& bonDeMasa);
    ~BonDeMasa()
    {

    }
    void Verificare()
    {
        cout<<id<<" "<<emitent<<" "<<valoare<<endl;
    }

};

istream& operator>>(istream& os, BonDeMasa& bonDeMasa)
{
    cout<<"ID:";
    os>>bonDeMasa.id;
    cout<<"Emitent:";
    os>>bonDeMasa.emitent;
    cout<<"Valoare:";
    os>>bonDeMasa.valoare;

    return os;
}
ostream& operator<<(ostream& os, const BonDeMasa& bonDeMasa)
{
    os << "Emitent: "<< bonDeMasa.emitent << " cu ID-ul " << bonDeMasa.id<<" are valoarea "<<bonDeMasa.valoare<<endl;

}

class Angajat
{
private:
    int id, nrBonuri;
    string nume;
    BonDeMasa bonuri[100];
public:
    Angajat()
    {
        id = i++;
        nume="";
        nrBonuri=0;
    }
    Angajat(const int nrBonuri1,const char n[50])
    {
        id=i++;
        nrBonuri= nrBonuri1;
        nume=n;
    }
    Angajat(const Angajat& angajat1)
    {
        id=angajat1.id;
        nrBonuri=angajat1.nrBonuri;
        nume=angajat1.nrBonuri;
    }


    friend ostream& operator<<(ostream& os, const Angajat& angajat);
    friend istream& operator>>(istream& os, Angajat& angajat1);

    Angajat& operator=(const Angajat& other)
    {

        id=other.id;
        nrBonuri = other.nrBonuri;
        nume=other.nume;
        return *this;

    }
    bool operator<(const Angajat& other)
    {
        return (id<other.id);
    }
    Angajat& operator *=(const BonDeMasa& bonDeMasa)
    {
        bonuri[nrBonuri+1]=bonDeMasa;

        return *this;

    }


    void afiseaza()
    {
        cout<<id<<" "<<nume<<" "<<nrBonuri;
        for(int j=0; j<nrBonuri; j++)
        {
            cout<<bonuri[j]<<endl;

        }
    }
    string getNume()
    {
        return nume;
    }

    ~Angajat()
    {
    }

};
ostream& operator<<(ostream& os, const Angajat& angajat)
{
    os << "Angajatul: "<< angajat.nume << " are bonuri " << angajat.nrBonuri<<endl;

}

istream& operator>>(istream& os, Angajat& angajat1)
{
    cout<<"ID:";
    os>>angajat1.id;
    cout<<"Nume:";
    os>>angajat1.nume;
    cout<<"nrBonuri:";
    os>>angajat1.nrBonuri;
    return os;
}

int main()
{
    BonDeMasa b1(1,"GustoPass",9.35), b2, b3;
    b3=b1;
    b3.Verificare();
    Angajat a1(22,"Ionescu"), a2;
    cout<<a1;//afisarea tuturor informatiilor despre un angajat
    cin>>b2;
    cin>>a2;//citirea tuturor informatiilor despre un angajat
    Angajat a3(a2), a4;
    a3 *= b1; //atribuie bonul de masa b1 angajatului a3 prin salvarea lui b1 in vectorul bonuri din a3
    a4 = a3;
    if (a1 < a2) cout<<"Angajatul "<<a1.getNume()<<" are id-ul mai mic decat "<<a2.getNume();
    cout<<endl;
    a3.afiseaza(); //afisarea tuturor informatiilor despre un angajat.

}
