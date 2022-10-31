#ifndef ATTAQUE_H_INCLUDED
#define ATTAQUE_H_INCLUDED
#include <iostream>

class Attaque
{
protected:
    std::string m_nom ;
    int m_degats;

public:
    Attaque(std::string _nom, int _degats);
    Attaque();
    ~Attaque();
    std::string getNom()const;
    int getDegats()const;
    //int getCout()const;

    void setNom(std::string _nom);
    void setDegats(int _degats);
    void augmente();
    //void setCout(int _cout);
};


#endif // ATTAQUE_H_INCLUDED
