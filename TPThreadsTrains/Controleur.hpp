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
        this->count = 0;
        this->waitingInA = false;
        this->waitingInB = false;
    }

    bool controlinEnB(int numero)
    {
        if ((this->val == 0) && (this->val > -2) && ((this->waitingInA) || (this->count < 3)))
        {
            this->count++;
            waitingInB = false;
            this->val--;
            // std::cout << "inB Val = " << this->val << "\n";
            return true;
        }
        waitingInB = true;
        return false;
    }

    bool controlinEnA(int numero)
    {
        if ((this->val == 0) && (this->val < 2) && ((this->waitingInA) || (this->count < 3)))
        {
            this->count++;
            waitingInA = false;
            this->val++;
            // std::cout << "inA Val = " << this->val << "\n";
            return true;
        }
        waitingInA = true;
        return false;
    }

    bool controloutEnB(int numero)
    {
        if (this->val > 0) {
            // std::cout << "outB Val = " << this->val << "\n";
            this->val--;

            if (val == 0) {
                this->count = 0;
            }
            return true;
        }
        return false;
    }

    bool controloutEnA(int numero)
    {
        if (this->val < 0) {
            // std::cout << "outA Val = " << this->val << "\n";
            this->val++;

            if (val == 0) {
                this->count = 0;
            }
            return true;
        }
        return false;
    }

private:
    int val;
    unsigned int count;
    bool waitingInA;
    bool waitingInB;
};

#endif // CONTROLEUR_HPP
