#ifndef FRACCIONES_H
#define MI_HEADER_H
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int num;
    int den;

}Fraction;

Fraction* fraction_new (int num, int den)
{
     if (den == 0) {
        printf("Error: El denominador no puede ser cero.\n");
        return NULL;
    }

    Fraction* f=(Fraction*)malloc(sizeof(Fraction));
    f->num=num;
    f->den=den;

    return f;
}


void fraction_destroy(Fraction* f)
{

    free(f);

}

void fraction_print(Fraction* f)
{

    if(f==NULL)
    {
        printf("No hay ninguna fraccion");
    }else{

        printf("\n %d/%d",f->num,f->den);
    }

}

int fraction_get_num(Fraction* f)
{
    if (f==NULL)
    {
        return -9999;

    }else{

        return f->num;
    }
}

int fraction_get_den(Fraction* f)
{
    if (f==NULL)
    {
        return -9999;

    }else{

        return f->den;
    }
}


Fraction* fraction_add(Fraction* f1, Fraction* f2)
{

    int num = fraction_get_num(f1) * fraction_get_den(f2) + fraction_get_num(f2) * fraction_get_den(f1);
    int den = fraction_get_den(f1) * fraction_get_den(f2);

    return fraction_new(num, den);

}

Fraction* fraction_sub(Fraction* f1, Fraction* f2)
{


    int num = fraction_get_num(f1) * fraction_get_den(f2) - fraction_get_num(f2) * fraction_get_den(f1);
    int den = fraction_get_den(f1) * fraction_get_den(f2);

    return fraction_new(num, den);


}

Fraction* fraction_mul(Fraction* f1, Fraction* f2)
{


    int num = fraction_get_num(f1) * fraction_get_num(f2);
    int den = fraction_get_den(f1) * fraction_get_den(f2);

    return fraction_new(num, den);


}

Fraction* fraction_div(Fraction* f1, Fraction* f2)
{


    int num = fraction_get_num(f1) * fraction_get_den(f2);
    int den = fraction_get_den(f1) * fraction_get_num(f2);

    return fraction_new(num, den);


}


int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return (a < 0) ? -a : a; // Asegurar que el MCD sea positivo
}

// Función para simplificar una fracción
void fraction_simplify(Fraction* f) {
    if (!f) {
        printf("Error: Fracción NULL.\n");
        return;
    }
    if (f->den == 0) {
        printf("Error: Denominador cero no permitido.\n");
        return;
    }

    int divisor = gcd(f->num, f->den);
    f->num /= divisor;
    f->den /= divisor;

    // Asegurar que el denominador siempre sea positivo
    if (f->den < 0) {
        f->num = -f->num;
        f->den = -f->den;
    }
}


#endif