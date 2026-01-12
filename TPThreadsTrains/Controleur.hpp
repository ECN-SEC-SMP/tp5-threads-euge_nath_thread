#ifndef CONTROLEUR_HPP
#define CONTROLEUR_HPP

#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std;

class Controleur
{
public:
    Controleur(int valeur_initiale) : val(valeur_initiale)
    {
    }

    bool controlinEnB(int numero)
    {
        if (this->val == 0)
        {
            this->val++;
            return true;
        }
        return false;
    }

    bool controlinEnA(int numero)
    {
        if (this->val == 0)
        {
            this->val++;
            return true;
        }
        return false;
    }

    bool controloutEnB(int numero)
    {
        this->val--;
        return true;
    }

    bool controloutEnA(int numero)
    {
        this->val--;
        return true;
    }

private:
    int val;
};

#endif // CONTROLEUR_HPP
