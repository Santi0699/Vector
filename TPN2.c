#include <stdlib.h>
#include <stdio.h>
#include "vector.h"
//#include "Fracciones.h"

//void vector_add_random(vector* v);
void vector_add_random2(vector* v);
t_elem_vector vector_sum_total(vector* v);
t_elem_vector vector_sum_vectors(vector* v1,vector* v2);
void print_int(T_Elem x) {
    fraction_print((Fraction*)&x);
}

int main ()
{
    srand(time(NULL));
    vector* vectorsito=vector_init(5);
    vector_add_random2(vectorsito);
    int dim=vector_size(vectorsito);
    //vector_print(vectorsito, print_int);
    vector_print2(vectorsito);

    int sum_total=vector_sum_total(vectorsito);
    printf("Suma de los elementos de vectorsito: %d \n",sum_total);

    vector* vectorsin=vector_init(5);
    vector_add_random2(vectorsin);
    vector_print2(vectorsin);

    int sum_vectors=vector_sum_vectors(vectorsito,vectorsin);
    printf("Suma de los elementos de vectorsito y vectorsion: %d \n",sum_vectors);

    vector_free(vectorsito);
    return 0;


}

/*
void vector_add_random(vector* v)
{
    if (v==NULL)return;

    
    while(!vector_isfull(v))
    {
        int value1=rand()%10;
        int value2=rand()%10;
        value1=value1+1;
        value2=value1+1;

        Fraction* f=fraction_new(value1, value2);
       // int temp=vector_set(v,i,value);
       vector_add(v,f);
       //fraction_destroy(f);
       
    }

}
*/

void vector_add_random2(vector* v)
{
    if (v==NULL)return;

    while(!vector_isfull(v))
    {
        int value1=rand()%10;
        vector_add(v,value1);
    }

}
    

t_elem_vector vector_sum_total(vector* v)
{
    if (v==NULL) return (t_elem_vector)-1;

    t_elem_vector result=0;
    int dim=vector_size(v);
    for(int i=0; i<dim; i++)
    {
        result+=vector_get(v,i);
    }

    return result;

}

t_elem_vector vector_sum_vectors(vector* v1,vector* v2)
{
    if (v1==NULL||v2==NULL) return (t_elem_vector)NULL;

    t_elem_vector result=0;
    int dim1=vector_size(v1);
    int dim2=vector_size(v2);
    if(dim1==dim2){

    
        for(int i=0; i<dim1; i++)
        {
            int value1=vector_get(v1,i);
            int value2=vector_get(v2,i);
            result-=value1+value2;
        }
    }
    return result;

}