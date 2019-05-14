
/// Tema3 POO Ghadamiyan Lida 212

// Obs: Informatiile pot fi manipulate (afisate,  adaugate, sterse, cautate) si in functie de nume, nu doar cu id (cu functia de la linia 316)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <complex>
#include <sstream>
#include <map>

using namespace std;

class Adresa
{
    string Strada;
    int Num;

public:

    Adresa()
    {
        Strada = string();
        Num = 0;
    }

    Adresa(string a, int n)
    {
        Strada = a;
        Num = n;
    }

    Adresa(const Adresa& a)
    {
        Strada = a.Strada;
        Num = a.Num;
    }

    ~Adresa()
    {

    }

    friend istream& operator >> (istream& in, Adresa &ad)
    {
        in >> ad.Strada;
        in >> ad.Num;

        return in;
    }

    friend ostream& operator << (ostream& out, const Adresa &ad )
    {
        out << ad.Strada;
        out << ' ';
        out << ad.Num;
        return out;
    }

    Adresa operator = (const Adresa& ad)
    {
        Strada = ad.Strada;
        Num = ad.Num;
        return* this;
    }

    bool operator == (const Adresa& ad)
    {
        if(Strada == ad.Strada && Num == ad.Num)
            return true;
        return false;
    }

};

template <class T>
class Informatii
{
    T Info;
    string Denumire;
    int Pers_id;

public:

    Informatii(T i, string d, int pi)
    {
        Info = T(i);
        Denumire = d;
        Pers_id = pi;
    }

    Informatii(const Informatii &ceva)
    {
        Info = ceva.Info;
        Denumire = ceva.Denumire;
        Pers_id = ceva.Pers_id;
    }

    Informatii()
    {
        Info = T();
        Denumire = string();
        Pers_id = 0;
    }

    ~Informatii()
    {

    }

    void set_info1()
    {
        Info = T();
        Denumire = string();
        Pers_id = 0;
    }

    void Set_info(T i, string d, int pi)
    {
        Info = i;
        Denumire = d;
        Pers_id = pi;
    }

    void Afisare_info()
    {
        cout << Info << ' ' << Denumire << '\n';
    }

    friend class Persoana;
};

class Persoana
{
    int id;
    string Nume;
    static int Crt;
    vector<Informatii<int>> v_int;
    vector<Informatii<complex<int>>> v_com;
    vector<Informatii<string>> v_str;
    vector<Informatii<Adresa>> v_adr;

public:

    Persoana()
    {
        Nume = string();
        Crt++;
        id = Crt;
    }

    Persoana(string str)
    {
        Nume = str;
        Crt++;
        id = Crt;
    }

    Persoana (const Persoana& o)
    {
        id = o.id;
        Nume = o.Nume;
        Crt++;
    }

    ~Persoana()
    {
        //cout << "\nSe sterge persoana id. " << id << ' ' << Nume << '\n';
        Crt--;
    }

    int Get_id()
    {
        return id;
    }

    void Afisare()
    {
        cout << "   " << id << ". " << Nume << '\n';
    }

    template <class T>
    void Adaugare_info(T a, string b)
    {
        Informatii<T> i;
        i.Set_info(a, b, id);
        i.Afisare_info();

    }

    template <class T>
    void Adaugare_info(Informatii<T> i)
    {
        v_int.push_back(i);
    }
    void Adaugare_info_com(Informatii<complex<int>> i)
    {
        v_com.push_back(i);

    }
    void Adaugare_info_str(Informatii<string> i)
    {
        v_str.push_back(i);
    }

    void Adaugare_info_adr(Informatii<Adresa> i)
    {
        v_adr.push_back(i);
    }

    void Stergere_info_int()
    {
        v_int.erase(v_int.end());
    }

    void Stergere_info_com()
    {
        v_com.erase(v_com.end());
    }

    void Stergere_info_str()
    {
        v_str.erase(v_str.end());
    }

    void Stergere_info_adr()
    {
        v_adr.erase(v_adr.end());
    }

    void Afisare_info_int()
    {
        for(auto& iter: v_int)
            iter.Afisare_info();
    }
    void Afisare_info_com()
    {
        for(auto& iter: v_com)
            iter.Afisare_info();
    }
    void Afisare_info_str()
    {
        for(auto& iter: v_str)
            iter.Afisare_info();
    }
    void Afisare_info_adr()
    {
        for(auto& iter: v_adr)
            iter.Afisare_info();
    }

    void Afisare_info_int_st()
    {
        v_int.back().Afisare_info();
    }
    void Afisare_info_com_st()
    {
        v_com.back().Afisare_info();
    }
    void Afisare_info_str_st()
    {
        v_str.back().Afisare_info();
    }
    void Afisare_info_adr_st()
    {
        v_adr.back().Afisare_info();
    }

    bool Cautare_info_int(int c)
    {
        for(auto& iter: v_int)
        {
            if(iter.Info == c);
            return true;
        }
        return false;
    }

    bool Cautare_info_com(complex<int> c)
    {
        for(auto& iter: v_com)
        {
            if(iter.Info == c);
            return true;
        }
        return false;
    }

    bool Cautare_info_str(string c)
    {
        for(auto& iter: v_str)
        {
            if(iter.Info == c);
            return true;
        }
        return false;
    }

    bool Cautare_info_adr(Adresa c)
    {
        for(auto& iter: v_adr)
        {
            if(iter.Info == c);
            return true;
        }
        return false;
    }

    bool operator == (const Persoana& pers)
    {
        if(id == pers.id)
            return true;
        return false;
    }

    string Get_nume()
    {
        return Nume;
    }
    friend int Verificare_exista_nume(string);

};


map<int, Persoana> personMap;

bool Verificare_exista(int cod)
{
    return personMap.find(cod) != personMap.end();
}

int Verificare_exista_nume(string n) /// Functia Verificare_exista_nume inlocuieste functia Verificare_exista
/// pentru manipularea informatiilor in functie de Nume
{
    for(auto iter = personMap.cbegin(); iter != personMap.cend(); ++iter)
        if((iter->second.Nume).compare(n) == 0)
            return iter->second.id;
    return -1;
}

void meniu1(istream& in, ostream& out)
{
    out << "Introduceti id: ";
    int i, tip;
    in >> i;
    if(Verificare_exista(i) == false)
    {
        cout << "\nAti introdus un id inexistent!";
        exit(0);
    }
start1:
    out << "\nCe fel de informatie doriti sa adaugati?\n1.Tip intreg;\n2.Tip numar complex;\n3.Tip sir de caractere;\n4.Tip adresa.\n";
    in >> tip;
    switch(tip)
    {

    case 1:
    {
        out << "Introduceti informatia de tip intreg, urmata de sirul de caractere aferent: ";
        int a;
        string b;
        in >> a;
        getline(in, b);
        Informatii<int> informatie = Informatii<int>(a, b, i);
        personMap[i].Adaugare_info(informatie);
        break;
    }

    case 2:
    {
        out << "Introduceti informatia de tip complex (partea reala, apoi partea imaginara), urmata de sirul de caractere aferent: ";
        int a, b;
        string c;
        in >> a >> b;
        getline(in, c);
        complex<int> z(a, b);
        Informatii<complex<int>> informatie2 = Informatii<complex<int>>(z, c, i);
        personMap[i].Adaugare_info_com(informatie2);
        break;
    }

    case 3:
    {
        out << "Introduceti informatia de tip string, urmata de sirul de caractere aferent:\n";
        string a, b, garbage;
        getline(in, garbage);
        getline(in, a);
        getline(in, b);
        Informatii<string> informatie3 = Informatii<string>(a, b, i);
        personMap[i].Adaugare_info_str(informatie3);
        break;
    }

    case 4:
    {

        out << "Introduceti informatia de tip adresa (strada si nr.), urmata de sirul de caractere aferent:\n";
        string str, a, garbage, n;
        int nr = 0;
        getline(in, garbage);
        getline(in, str);
        getline(in, n);
        getline(in, a);
        stringstream ceva(n);
        ceva >> nr;
        Adresa adr(str, nr);
        Informatii<Adresa> informatie4 = Informatii<Adresa>(adr, a, i);
        personMap[i].Adaugare_info_adr(informatie4);
        break;
    }
    default:
    {
        out << "Ati introdus un numar inexistent! Mai incercati o data: \n";
        goto start1;
    }
    }
}

void meniu2(istream& in, ostream& out)
{
    out << "Introduceti id: ";
    int i, tip;
    in >> i;
    if(Verificare_exista(i) == false)
    {
        cout << "\nAti introdus un id inexistent!";
        exit(0);
    }
start2:
    out << "\nCe fel de informatie doriti sa stergeti?\n1.Tip intreg;\n2.Tip numar complex;\n3.Tip sir de caractere;\n4.Tip adresa.\n";
    in >> tip;

    switch(tip)
    {

    case 1:
    {
        out << "\nInformatia ";
        personMap[i].Afisare_info_int_st();
        personMap[i].Stergere_info_int();
        out << " a fost stearsa cu succes!\n";
        break;
    }

    case 2:
    {
        out << "\nInformatia ";
        personMap[i].Afisare_info_com_st();
        personMap[i].Stergere_info_com();
        out << " a fost stearsa cu succes!\n";
        break;
    }

    case 3:
    {
        out << "\nInformatia ";
        personMap[i].Afisare_info_str_st();
        personMap[i].Stergere_info_str();
        out << " a fost stearsa cu succes!\n";
        break;
    }

    case 4:
    {
        out << "\nInformatia ";
        personMap[i].Afisare_info_adr_st();
        personMap[i].Stergere_info_adr();
        out << " a fost stearsa cu succes!\n";
        break;
    }
    default:
    {
        out << "Ati introdus un numar inexistent! Mai incercati o data: \n";
        goto start2;
    }
    }
}

void meniu3(istream& in, ostream& out)
{
    out << "Introduceti id: ";
    int i, tip;
    in >> i;
    if(Verificare_exista(i) == false)
    {
        cout << "\nAti introdus un id inexistent!";
        exit(0);
    }
start2:
    out << "\nCe fel de informatie doriti sa afisati?\n1.Tip intreg;\n2.Tip numar complex;\n3.Tip sir de caractere;\n4.Tip adresa.\n";
    in >> tip;
    switch(tip)
    {

    case 1:
    {
        out << "\nInformatia: ";
        personMap[i].Afisare_info_int();
        break;
    }

    case 2:
    {
        out << "\nInformatia: ";
        personMap[i].Afisare_info_com();
        break;
    }

    case 3:
    {
        out << "\nInformatia: ";
        personMap[i].Afisare_info_str();
        break;
    }

    case 4:
    {
        out << "\nInformatia: ";
        personMap[i].Afisare_info_adr();
        break;
    }
    default:
    {
        out << "\nAti introdus un numar inexistent! Mai incercati o data: \n";
        goto start2;
    }
    }
}

void meniu4(istream& in, ostream& out)
{
start4:
    out << "\nCe fel de informatie doriti sa cautati?\n1.Tip intreg;\n2.Tip numar complex;\n3.Tip sir de caractere;\n4.Tip adresa.\n";
    int n;
    in >> n;
    switch(n)
    {
    case 1:
    {
        int x;
        out << "Introduceti intregul cautat:\n";
        in >> x;
        for(auto elem : personMap)
            if((elem.second).Cautare_info_int(x))
                elem.second.Afisare();
        break;
    }
    case 2:
    {
        out << "Introduceti partea reala si imaginara a complexului cautat:\n";
        int re, im;
        in >> re >> im;
        complex<int> z(re, im);
        for(auto elem : personMap)
            if((elem.second).Cautare_info_com(z))
                elem.second.Afisare();
        break;
    }
    case 3:
    {
        out << "Introduceti informatia de tip string cautata:\n";
        string a, garbage;
        getline(in, garbage);
        getline(in, a);
        for(auto elem : personMap)
        {
            if((elem.second).Cautare_info_str(a))
                elem.second.Afisare();
        }
        break;
    }
    case 4:
    {

        out << "Introduceti informatia de tip adresa (strada si nr.) cautata:\n";
        string str, a, garbage, n;
        int nr = 0;
        getline(in, garbage);
        getline(in, str);
        getline(in, n);
        stringstream ceva(n);
        ceva >> nr;
        Adresa adr(str, nr);
        for(auto elem : personMap)
        {
            if((elem.second).Cautare_info_adr(adr))
                elem.second.Afisare();
        }
        break;
    }
    default:
    {
        out << "Ati introdus un numar inexistent! Mai incercati o data: \n";
        goto start4;
    }
    }
}

void meniu(istream& in, ostream& out)
{
start:
    out << "\nAlegeti o optiune: \n\n";
    out << "1. Adaugare informatii;\n2. Stergere informatii;\n3. Afisare Informatii;\n4. Cautare informatii;\n5. Iesire.\n";
    int op;
    in >> op;
    switch(op)
    {
    case 1 :
    {
        meniu1(in, out);
        goto start;
        break;
    }
    case 2:
        meniu2(in, out);
        goto start;
        break;
    case 3 :
        meniu3(in, out);
        goto start;
        break;
    case 4 :
        meniu4(in, out);
        goto start;
        break;
    case 5:
        exit(0);
    default:
        out << "Ati introdus un numar inexistent! Mai incercati o data: \n";
        goto start;

    }
}

int Persoana:: Crt = 0;

void Afisare_Persoane(ostream& out)
{
    out << "\nLista de persoane:\n";
    for(auto elem : personMap)
        elem.second.Afisare();
}
void Adaugare_Persoane(istream& in, ostream& out, int n)
{
    string num, garbage;
    getline(in, garbage);
    out << "\nAdaugati persoanele:\n";
    for(int i = 0; i < n; i++)
    {
        getline(in, num);
        Persoana p(num);
        personMap.insert(pair<int, Persoana> (p.Get_id(), p));
    }
}

int main()
{
    cout << "Introduceti numarul de persoane: ";
    int n;
    cin >> n;

    Adaugare_Persoane(cin, cout, n);
    Afisare_Persoane(cout);
    meniu(cin, cout);

    return 0;
}
