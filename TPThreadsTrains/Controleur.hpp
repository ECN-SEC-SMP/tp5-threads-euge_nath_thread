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
        if ((this->val <= 0) && (this->val > -2))
        {
            this->val--;
            // std::cout << "inB Val = " << this->val << "\n";
            return true;
        }
        return false;
    }

    bool controlinEnA(int numero)
    {
        if ((this->val >= 0) && (this->val < 2))
        {
            this->val++;
            // std::cout << "inA Val = " << this->val << "\n";
            return true;
        }
        return false;
    }

    bool controloutEnB(int numero)
    {
        if (this->val > 0) {
            // std::cout << "outB Val = " << this->val << "\n";
            this->val--;
            return true;
        }
        return false;
    }

    bool controloutEnA(int numero)
    {
        if (this->val < 0) {
            // std::cout << "outA Val = " << this->val << "\n";
            this->val++;
            return true;
        }
        return false;
    }

private:
    int val;
};

#endif // CONTROLEUR_HPP
