#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class Animal
{
protected:
    static int numar_de_animale;
    string animal_name;
public:
    static void incl()
    {
        numar_de_animale++;
    }
    static int Numarul_de_animale()
    {
        return numar_de_animale;
    }

    Animal() {}
    Animal(string nume) : animal_name(nume){}
    virtual ~Animal() {}
    string get_name()
    {
        return animal_name;
    }
    void set_name(string nume)
    {
        animal_name = nume;
    }

    friend ostream &operator<<(ostream &g, Animal &Animalut);

    virtual void Afisare()
    {
        cout << animal_name;
    }
    friend istream &operator>>(istream &g, Animal &Animalut);

};
int Animal:: numar_de_animale=0;
ostream &operator<<(ostream &g, Animal &Animalut)
{
    cout << Animalut.animal_name<<endl;
    return g;
}

istream &operator>>(istream &g,Animal &Animalut)
{
    cout<<"Introduceti numele animalului";
    g>>Animalut.animal_name;
    return g;
}
class Vertebrate : public Animal
{
public:
    Vertebrate() : Animal() {}
    Vertebrate(string nume) : Animal(nume) {}
    virtual ~Vertebrate() {}
};


class Fishes : public Vertebrate
{
private:
    string Culoare_Peste;
    string dimensiune;
public:
    Fishes() : Vertebrate() {}
    Fishes(string nume) : Vertebrate(nume)
    {
        Culoare_Peste = "Nu se cunoaste";
        dimensiune = "Nu se cunoaste";
    }
    ~Fishes() {}
    /* Fishes ()
     {
         Nume_Peste="Nu se cunosc date despre nume";
         Culoare_Peste="Nu se cunosc date despre culoare";
         dimensiune="Nu se cunosc date despre dimensiune";
     }
     */

    Fishes(string numele, string culoarea, string dimensiunea) : Vertebrate(numele), Culoare_Peste(culoarea), dimensiune(dimensiunea) {}
    void set_color(string color)
    {
        this->Culoare_Peste = color;
    }
    void set_dimension(string dimensiunea)
    {
        this->dimensiune = dimensiunea;
    }
    string get_color() const
    {
        return Culoare_Peste;
    }
    string get_dimension() const
    {
        return dimensiune;
    }
    friend istream& operator>>(istream&, Fishes&);
    friend ostream &operator<<(ostream &s, const Fishes &pestisor);
    virtual void Afisare () const
    {
        cout << "Nume peste: " << animal_name << endl;
        cout << "Culoare peste: " << Culoare_Peste << endl;
        cout << "Dimensiune peste: " << dimensiune<< endl;
    }
};

istream &operator>>(istream &s, Fishes &pestisor)
{
    string x, y, z;
    Animal::incl();
    cout << "Date peste: Nume, Culoare, Dimensiune: " << endl;
    cout << "Numele: ";
    cin >> x;
    cout << "Culoare: ";
    cin >> y;
    cout << "Dimensiune: ";
    cin >> z;
    pestisor.animal_name = x;
    pestisor.Culoare_Peste = y;
    pestisor.dimensiune = z;
    return s;
}
ostream &operator<<(ostream &s, const Fishes &pestisor)
{
    s << "Nume peste: " << pestisor.animal_name << endl;
    s << "Culoare peste: " << pestisor.Culoare_Peste << endl;
    s << "Dimensiune peste: " << pestisor.dimensiune << endl;
    return s;
}
class Birds : public Vertebrate
{
private:
    string Culoare_Pasare;
    string dimensiune_pasare;
public:
    Birds() : Vertebrate() {}
    Birds(string nume) : Vertebrate(nume)
    {
        Culoare_Pasare = "Nu se cunoaste";
        dimensiune_pasare = "Nu se cunoaste";
    }
    ~Birds() {}


    Birds(string numele, string culoarea, string dimensiunea) : Vertebrate(numele), Culoare_Pasare(culoarea), dimensiune_pasare(dimensiunea) {}
    void set_color_pasare(string color)
    {
        this->Culoare_Pasare = color;
    }
    void set_dimension_pasare(string dimensiunea)
    {
        this->dimensiune_pasare = dimensiunea;
    }
    string get_color_pasare() const
    {
        return Culoare_Pasare;
    }
    string get_dimension_pasare() const
    {
        return dimensiune_pasare;
    }
    friend istream& operator>>(istream&, Birds& pasarica);
    friend ostream &operator<<(ostream &s, const Birds &pasarica);
    \
    virtual void Afisare()
    {
        cout << "Nume peste: " << animal_name << endl;
        cout << "Culoare peste: " << Culoare_Pasare << endl;
        cout << "Dimensiune peste: " << dimensiune_pasare<< endl;
    }
};



istream &operator>>(istream &s, Birds &pasarica)
{
    string x, y, z;
    Animal::incl();
    cout << "Date pasare: Nume, Culoare, Dimensiune: " << endl;
    cout << "Numele: ";
    cin >> x;
    cout << "Culoare: ";
    cin >> y;
    cout << "Dimensiune: ";
    cin >> z;
    pasarica.animal_name = x;
    pasarica.Culoare_Pasare = y;
    pasarica.dimensiune_pasare = z;
    return s;
}
ostream &operator<<(ostream &s, const Birds &pasarica)
{
    s << "Nume pasare: " << pasarica.animal_name << endl;
    s << "Culoare pasare: " << pasarica.Culoare_Pasare << endl;
    s << "Dimensiune pasare: " << pasarica.dimensiune_pasare<< endl;
    return s;
}
class Reptile : public Vertebrate
{
};
class Mamifere : public Vertebrate
{
};
class NeVertebrate
{

};

template <class T>
class ZooAtlas
{
    int NoPages;
    vector <T*> Atlas_book;

public:
    ZooAtlas()
    {
        NoPages = 0;
    }
    ZooAtlas(int length) // atlas cu numar prestabilit de pagini
    {
        NoPages = length;
    }
    void incl_set_length(int valoare)
    {
        NoPages=valoare+1;
    }
    int get_length()
    {
        return NoPages;
    }
    ~ZooAtlas()
    {
        T* p;
        int size = this->Atlas_book.size();
        while(!this->Atlas_book.empty())
        {
            p = this->Atlas_book[size - 1];
            this->Atlas_book.pop_back();
            size--;
            delete p;
        }
    }
    ZooAtlas<T> &operator+=(T *data)
    {
        this->NoPages++;
        this->Atlas_book.push_back(data);
        return *this;
    }

    int get_pages() const
    {
        return NoPages;
    }
    vector<T*> get_Atlas_book()
    {
        return Atlas_book;
    }

    void Afisare_atlas_zoo()
    {
        vector <Animal>::iterator it;
        for (it = Atlas_book.begin(); it != Atlas_book.end(); ++it)
            cout << *it << endl;
    }
    ZooAtlas<T> &operator=(const ZooAtlas <T>& data)
    {
        while (Atlas_book.empty() != 0)
        {
            Atlas_book.pop_back();
        }
        T *pointer;
        for (T *it : data.Atlas_book)
        {
            pointer = new T(*it);
            this->Atlas_book.push_back(pointer);
        }
        return *this;
    }

    Animal &operator [](int index)
    {
        int contor=1;
        int ok=0;
        for (T *it : Atlas_book)
        {
            if(contor==index)
            {
                if (Fishes *fishu = dynamic_cast<Fishes *>(it))
                {
                    cout<<*fishu;
                    ok=1;

                }
                else if(Birds *birdu = dynamic_cast<Birds *>(it))
                {
                    cout<<*birdu;
                    ok=1;
                }
                else cout<<*it;

            }
            contor++;

        }
        if(ok==0)
            cout<<"Nu am gasit pagina cu numarul "<<index<<endl;
    }
    template <class U>
    friend std::ostream &operator<<(ostream &g, const ZooAtlas<U> &atlasul);
};
template <class T>
std::ostream &operator<<(ostream &g, const ZooAtlas<T> &atlasul)
{
    cout<<"Nr. de pagini din atlas este : "<<atlasul.NoPages<<endl;
    int contor = 1;
    for (T *it : atlasul.Atlas_book)
    {

        if (Vertebrate *p = dynamic_cast<Vertebrate *>(it))
        {
            if (Fishes *fishu = dynamic_cast<Fishes *>(p))
            {
                cout<<"Pagina cu numarul "<<contor <<" contine animalul urmatorul animal:"<<endl;
                cout<< *fishu;
                cout<<endl;
            }
        }
        if (Vertebrate *p = dynamic_cast<Vertebrate *>(it))
        {
            if (Birds *birdu = dynamic_cast<Birds *>(p))
            {
                cout<<"Pagina cu numarul "<<contor <<" contine animalul urmatorul animal:"<<endl;
                cout<< *birdu;
                cout<<endl;
            }

        }
        else
            cout<<"Pagina cu numarul "<<contor <<" contine animalul "<<*it<<endl;
        contor++;
    }
    return g;
}

int functie (string c)
{
    int numar=0;
    for(int i=0; i<c.length(); i++)
    {
        numar=numar*10+int(c[i]);
    }
    return numar;
}
template <>
class ZooAtlas<Fishes>
{
    vector<Fishes*> Lista_peste_1m;
    vector<Fishes*> Lista_peste;
public:

    ZooAtlas<Fishes> &operator+=(Fishes *data)
    {
        int nr=functie(data->get_dimension());
        if(nr>=1)

            this->Lista_peste_1m.push_back(data);
        else
            this->Lista_peste.push_back(data);
        return *this;
    }
    friend ostream &operator<<(ostream &g, const ZooAtlas<Fishes> &atlasul);




};
std::ostream &operator<<(ostream &g, const ZooAtlas<Fishes> &atlasul)
{
    bool ok=0;
    cout<<"Pesti din atlasul specialization cu dimensiunea >=1m: "<<endl;
    for (Fishes *it : atlasul.Lista_peste_1m)
    {
        ok=1;
        cout<<*it;

    }
    if(ok==0)
        cout<<"Nu exista pesti care au dimensiunea peste un metru in atlas"<<endl;
    ok=0;

    cout<<"Pesti din atlasul specialization care au dimensiunea <1m "<<endl;
    for (Fishes *it : atlasul.Lista_peste)
    {
        ok=1;
        cout<<*it;

    }
    if(ok==0)
        cout<<"Nu exista pesti care au dimensiunea sub un metru in atlas"<<endl;


}
int main()
{
    cout<<"1. STOP!"<<endl<<"2. ADAUGARE PESTE"<<endl<<"3. ADAUGARE PASARE"<<endl<<"4. AFISARE ATLAS"<<endl<<"5. ADAUGARE IN ATLASUL SPECIALIZAT PENTRU PESTI"<<endl;
   cout<<"6. AFISARE ATLAS CU SPECIALIZAREA PESTI"<<endl;
    int choice;
    int Numar=1;
    ZooAtlas<Animal> AtlasAnimal;
    ZooAtlas<Fishes> Atlasdepesti;


    do
    {
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            cout<<"Ati iesit"<<endl;
            return 0;
        }
        case 2:
        {
            Fishes *F=new Fishes;
            cin>>*F;
            // F->Afisare();
            AtlasAnimal += F;
            cout<<endl;
            cout<<"Animalul citit: "<<endl;
            AtlasAnimal[Numar];
            Numar++;
            cout<<endl;
            break;

        }
        case 3:
        {

            Birds *B=new Birds;
            cin>>*B;
            AtlasAnimal += B;
            cout<<endl;
            cout<<"Animalul citit: "<<endl;
            AtlasAnimal[Numar];
            Numar++;
            cout<<endl;
            break;
        }
        case 4:
        {
            cout<<AtlasAnimal;
            cout<<"Numarul de animale citite: "<<Animal::Numarul_de_animale()<<endl;
            break;
        }
        case 5:
            {
               Fishes *pe=new Fishes;
        cin>>*pe;
        Atlasdepesti += pe;
        break;
            }
        case 6:
            {

                cout<<Atlasdepesti;
                break;
            }


        }

    }
    while(choice!=0);


}
