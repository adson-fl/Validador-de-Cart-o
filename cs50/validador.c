#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long cartao = 0;

    do
    {
        cartao = get_long("digite o numero do cartão: ");
    }
    while (cartao == 0);

    int dig0, dig1, dig2, dig3, dig4, dig5, dig6, dig7, dig8, dig9, dig10, dig11, dig12, dig13, dig14, dig15;
    // digitos pegues de maneira unitaria
     dig0 = cartao % 10;
     dig1 = ((cartao % 100) / 10) * 2; //
     dig2 = (cartao % 1000) / 100;
     dig3 = ((cartao % 10000) / 1000) * 2; //
     dig4 = (cartao % 100000) / 10000;
     dig5 = ((cartao % 1000000) / 100000) * 2;//
     dig6 = (cartao % 10000000) / 1000000;
     dig7 = ((cartao % 100000000) / 10000000) * 2; //
     dig8 = (cartao % 1000000000) / 100000000;
     dig9 = ((cartao % 10000000000) / 1000000000) * 2; //
     dig10 = (cartao % 100000000000) / 10000000000;
     dig11 = ((cartao % 1000000000000) / 100000000000) * 2; //
     dig12 = (cartao % 10000000000000) / 1000000000000; // primeiro valor visa
     dig13 = ((cartao % 100000000000000) / 10000000000000) * 2;
     dig14 = (cartao % 1000000000000000) / 100000000000000;  // priro valor do American Express
     dig15 = ((cartao % 10000000000000000) / 1000000000000000) * 2; //primeiro valor matercard ou visa

     // separador de digitos para a soma
     dig1 = (dig1 % 100 / 10) + (dig1 % 10);
     dig3 = (dig3 % 100 / 10) + (dig3 % 10);
     dig5 = (dig5 % 100 / 10) + (dig5 % 10);
     dig7 = (dig7 % 100 / 10) + (dig7 % 10);
     dig9 = (dig9 % 100 / 10) + (dig9 % 10);
     dig11 = (dig11 % 100 / 10) + (dig11 % 10);
     dig13 = (dig13 % 100 / 10) + (dig13 % 10);
     dig15 = (dig15 % 100 / 10) + (dig15 % 10);

    // calculo de validação
    int calc = dig1 + dig3 + dig5 + dig7 + dig9 + dig11 + dig13 + dig15;
    int resu = calc + dig0 + dig2 + dig4 + dig6 + dig8 + dig10 + dig12 + dig14;


    if (resu % 10 != 0)
    {
        printf("INVALID\n");

        return 0;
    }

    int cont = 0;
    long master = cartao;
    long amex = cartao;
    long visa = cartao;

    while (cartao > 0)
    {
        cartao /= 10;
        cont ++;
    }
    while (visa >=10)
    {
        visa /= 10;
    }
    if (visa == 4 && (cont == 13 || cont == 16))
    {
        printf("VISA\n");
        return 0;
    }
    while (amex >= 10000000000000)
    {
        amex /= 10000000000000;
    }
    if (cont == 15 && (amex == 34 || amex == 37))
    {
        printf("AMEX\n");
        return 0;
    }
    while (master >= 100000000000000)
    {
        master /= 100000000000000;
    }
    if (cont == 16 && (master >= 51 && master <= 55))
    {
        printf("MASTERCARD\n");
        return 0;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}