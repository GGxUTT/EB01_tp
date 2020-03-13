#include <stdint.h>

#define NB_ELEM(t) (sizeof(t)/sizeof(*t));

#define _A _LATB15
#define _B _LBTB8;
#define _C _LATB10;
#define _D _LATB10;
#define _E _LATB10;
#define _F _LATB10;
#define _G _LATB10;


void Blanc(void){
    _A = 0;
    _B = 0;
    _C = 0;
    _D = 0;
    _E = 0;
    _F = 0;
    _G = 0;
    return;
}

void Zero(void){
    _A = 1;
    _B = 1;
    _C = 1;
    _D = 1;
    _E = 1;
    _F = 1;
    _G = 0;
    return;
}

void Un(void){
    _A = 1;
    _B = 1;
    _C = 0;
    _D = 0;
    _E = 0;
    _F = 0;
    _G = 0;
    return;
}

void Deux(void){
    _A = 1;
    _B = 0;
    _C = 1;
    _D = 1;
    _E = 0;
    _F = 1;
    _G = 1;
    return;
};

void Trois(void){
    _A = 1;
    _B = 1;
    _C = 1;
    _D = 0;
    _E = 0;
    _F = 1;
    _G = 1;
    return;
};

void Quatre(void){
    _A = 1;
    _B = 1;
    _C = 0;
    _D = 0;
    _E = 0;
    _F = 1;
    _G = 1;
    return;
};

void Cinq(void){
    _A = 1;
    _B = 0;
    _C = 1;
    _D = 1;
    _E = 0;
    _F = 1;
    _G = 1;
    return;
};

void Six(void){
    _A = 0;
    _B = 0;
    _C = 1;
    _D = 1;
    _E = 1;
    _F = 1;
    _G = 1;
    return;
};

void Sept(void){
    _A = 1;
    _B = 1;
    _C = 1;
    _D = 0;
    _E = 0;
    _F = 0;
    _G = 1;
    return;
};

void Huit(void){
    _A = 1;
    _B = 1;
    _C = 1;
    _D = 1;
    _E = 1;
    _F = 1;
    _G = 1;
    return;
};

void Neuf(void){
    _A = 1;
    _B = 1;
    _C = 1;
    _D = 1;
    _E = 0;
    _F = 1;
    _G = 1;
    return;
};

void chiffre(uint16_t c){
    static void (*tf[])(void) = {Zero, Un, Deux, Trois, Quatre, Cinq, Six, Sept, Huit, Neuf};
    if (c >= NB_ELEM(tf)){
        Blanc();
        return;
    };
    tf[c]();
}