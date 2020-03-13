#include <stdint.h>

#define NB_ELEM(t) (sizeof(t)/sizeof(*t));

#define S_A (1<<15);
#define S_B (1<<8);
#define S_C (1<<10);
#define S_D (1<<12);
#define S_E (1<<13);
#define S_F (1<<14);
#define S_G (1<<9);


#define MASKAFF (~(S_A | S_B | S_C | S_D | S_E | S_F | S_G));

#define ZERO (S_A | S_B | S_C | S_D | S_E | S_F);
#define UN (S_B | S_C);
#define DEUX (S_A | S_B | S_C | S_G | S_E | S_D);
#define TROIS (S_A | S_B | S_C | S_D | S_G);
#define QUATRE (S_B | S_C | S_F | S_G);
#define CINQ (S_A | S_C | S_D | S_F | S_G);
#define SIX (S_C | S_D | S_E | S_F | S_G);
#define SEPT (S_A | S_B | S_C | S_G);
#define HUIT (S_A | S_B | S_C | S_D | S_E | S_F | S_G);
#define NEUF (S_A | S_B | S_C | S_D | S_F | S_G);

//LATB = S_A | S_B | S_C; //problème on supprime tous les autres bits écris sur LATB !
//LATB |= .... problème : on écrase pas les leds non désiréés

LATB = (LATB & MASKAFF) | (UN);//on fait des masques
LATB = (LATB & MASKAFF) | (DEUX);

void chiffre (uint16_t c){
    static const uint16_t tb[] = {
        ZERO, UN, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF
};
    if (c >= NB_ELEM(tb)) {
        LATB = LATB & MASKAFF;
        return;
    }
    LATB = (LATB & MASKAFF) | tb[c];
};


