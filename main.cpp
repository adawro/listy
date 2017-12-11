#include <iostream>
#include <string>
#include <cstdlib>
#include <new>
using namespace std;

struct Lista
{
    string imie;
    Lista *nastepny;
    void dodaj_koniec();
    void dodaj_poczatek();
    void dodaj_za_wskazany();

};
Lista *head = NULL;
Lista *nastepny;
void dodaj_koniec(string imie)
{
    Lista *p, *e;
    e=new Lista;
    e->nastepny=NULL;
    e->imie = imie;
    p=head;
    if(p)
    {
        while(p->nastepny) p=p->nastepny;
        p->nastepny =e;
    }
    else head=e;
}
void dodaj_poczatek( string imie)
{

    Lista * p =new Lista;
    p->imie=imie;
    p->nastepny = head;
    head = p;
}
void dodaj_za_wskazany(Lista *e, string imie)
{

    Lista *p = new Lista;
    p->nastepny = e->nastepny;
    p->imie=imie;
    e->nastepny = p;

}
int main()
{

   dodaj_poczatek("pierwsza");
   dodaj_koniec("druga");
   dodaj_poczatek("Trzecia");
   int n=3,i=1; // n - wyraz za ktorym wstawiamy element;
   Lista *t;
   t=head;
   for(i=1; i<n; i++)
    {
        t=t->nastepny;
    }
   dodaj_za_wskazany(t,"czwarty");
    cout<<"LITSAA"<<endl;
    Lista *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->imie<<endl;
        temp=temp->nastepny;
    }
    return 0;
}
