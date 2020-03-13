#include <xcc.h>
#define OUT(b) (~(1<<b));
#define OFF 0xFFFF; // AN0 à AN20 dans le pire cas.
#define ANA(b) (b==OFF)? 0xFFFF : ~(1<<(b));

#define _LED_VERTE _LATB0;
#define _LED_ORANGE _LATB1;
/* 
*utiliser les _RBi est à prioris la même chose mais le CPU qui est x16 
*fais l'opération de masquage puis écriture. RB0 fais un front qui peut être trop long et la 
*seconde instruction peut manger la première écriture potentiellement.
*Toute les sorties dans les LATch !
*/
#define K2 _LATA0 // afficheur K2


void Init(void){
    //Registres d'entrées
    /* 
    *1 à la fois :
    *_TRISA0 = 0;
    *_TRISB0 = 0; 
    * Ecriture clair mais trop rébarbatif.
    */

    /* 
    *Pour faire tout d'un coup:
    *TRISA = 0b01010;
    *Cette écriture est peu lisible et le gain en efficacité est faible. 
    */
    

    TRISA = OUT(0) & OUT(2) & OUT(4);
    TRISB = OUT(0) & OUT(1) & OUT(3) & ...;

    AD1PCFG = ANA(1) & ANA(4);
}

void main(void)
{
    Init();
    while (1)
    //Allumer la led verte
    _LED_VERTE=1;
    _LED_ORANGE=1;
    _K2 = 1;
    chiffre(2);
    {

    }
    
    return;
}
