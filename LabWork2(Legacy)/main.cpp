//
//  main.cpp
//  nasledie
//
//  Created by parinovK on 16.11.2019.
//  Copyright © 2019 parinovK. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

class complex
{
protected:
    double mnim;
    double deistv;
public:
    complex(double deistv = 0, double mnim = 0)
    {
        this->mnim = mnim;
        this->deistv = deistv;
    }
    ~complex(){}
};

class nasled:public complex
{
private:
    double uglovaya_chastota;
public:
    nasled(double deistv,double mnim, double uglovaya_chastota = 0):complex(deistv,mnim)
    {
        this->uglovaya_chastota = uglovaya_chastota;
    }
    
    double absComplex()
    {
        double module = 0;
        module = sqrt(deistv + mnim); //находит модуль комплексного числа
        return abs(module);
    }
    
    double
    
    ~nasled(){}
};

int main(int argc, const char * argv[])
{
    setlocale(0, "");
    
    nasled komp_chislo(2,4,6); //(сопротивление резистора (deistv), значение индуктивности(mnim)
    
    cout << "Модуль комплексного числа = "<<komp_chislo.absComplex() << endl;
    
    
    return 0;
}
