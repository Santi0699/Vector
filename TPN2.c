#include <stdlib.h>
#include <stdio.h>
#include "vector.h"
#include <time.h>
//#include "Fracciones.h"

//void vector_add_random(vector* v);
void vector_add_random2(vector* v);
t_elem_vector vector_sum_total(vector* v);
t_elem_vector vector_sum_vectors(vector* v1,vector* v2);
t_elem_vector vector_get_max_value(vector* v );
int vector_count_value_appear(vector* v, t_elem_vector value);
vector* vector_in_order(vector *v);
void swap(int* a, int* b);
void bubble_sort_v2(vector* v, int n);
vector* vector_with_ocurrences(vector* v);

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

    int major=vector_get_max_value(vectorsito);
    printf ("Mayor de vectorsito: %d\n",major);
    int major2=vector_get_max_value(vectorsin);
    printf ("Mayor de vectorsin: %d\n",major2);

    vector* pepin=vector_init(10);
    vector_add_random2(pepin);

    t_elem_vector value_found=rand()%10;
    int same_value=vector_count_value_appear(pepin,value_found);
    vector_print2(pepin);
    printf("En pepin el numero se repite: %d \n",same_value);

    vector* pepon=vector_init(10);
    pepon=vector_in_order(pepin);
    puts("El vector pepon es:\n");
    vector_print2(pepon);

    vector* pepinero=vector_init(10);
    pepinero=vector_with_ocurrences(pepon);
    puts("pepinero quedo asi:");
    vector_print2(pepinero);

    vector_free(vectorsito);
    vector_free(vectorsin);
    vector_free(pepin);
    return 0;


}
//3)
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
//2)
void vector_add_random2(vector* v)
{
    if (v==NULL)return;

    while(!vector_isfull(v))
    {
        int value1=rand()%10;
        vector_add(v,value1);
    }

}
    
//4)
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
//5)
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
            result+=value1+value2;
        }
    }
    return result;

}
//6)
t_elem_vector vector_get_max_value(vector* v)
{
    int size= vector_size(v);
    t_elem_vector major=vector_get(v,0);
    for(int i=1; i<size;i++)
    {
        t_elem_vector temp = vector_get(v,i);
        if(major<temp)
        {
            major=temp;
        }

    }


    return major;

}
//7)
int vector_count_value_appear(vector* v, t_elem_vector value)
{
    int count=0;
    int size=vector_size(v);
    for(int i=0; i<size; i++)
    {
        t_elem_vector comp=vector_get(v,i);
        if(comp==value)
        {
            count++;
        }
    }

    return count;
}

//8)

vector* vector_in_order(vector *v)
{
    int size=vector_size(v);
    vector* result=vector_init(size);
    bubble_sort_v2(v,size);
    for(int i=0; i<size;i++)
    {
        t_elem_vector temp=vector_get(v,i);
        vector_add(result,temp);

    }

    return result;
}

void swap(t_elem_vector* a, t_elem_vector* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}


void bubble_sort_v2(vector* v, int n) {
    char swapped = 1;
    while ((swapped != 0) && (n > 0)) {
        swapped = 0;
        for (int i = 1; i < n; i++) {

            t_elem_vector value1=vector_get(v,i - 1);
            t_elem_vector value2=vector_get(v,i);
            if (value1 > value2) {
                swap(&v->a[i - 1], &v->a[i]);
                swapped = 1;
            }
        }
        n--;
    }
}

int vector_is_order(vector* v)
{
    int size=vector_size(v);
    int in_order=0;
    for(int i=1; i<size;i++)
    {
        t_elem_vector temp1 = vector_get(v,i-1);
        t_elem_vector temp2 = vector_get(v,i);

        if(temp1<temp2)
        {
            in_order=1;
        }
    }

    return in_order;
}

vector* vector_with_ocurrences(vector* v)
{   /*
    int size=vector_size(v);
    vector* result= vector_init(size);
    int cant_ocurrences=0;
    int j=0;
    bubble_sort_v2(v,size);
    if(vector_is_order(v))
    {
        
        for(int i=1; i<size; i++)
        {
            int temp1=vector_get(v,i-1);
            int temp2=vector_get(v,i);
            if(temp1==temp2)
            {
                cant_ocurrences=vector_count_value_appear(v,temp1);
                vector_set(result,j,cant_ocurrences);
                j++;
            }

        }

    }  
    return result;
    */


    if (v == NULL || vector_isempty(v)) return NULL;

    int size = vector_size(v);
    vector* result = vector_init(size);
    
    bubble_sort_v2(v, size); // Ordenamos el vector

    int i = 0;
    while (i < size)
    {
        t_elem_vector temp = vector_get(v, i);
        int count = vector_count_value_appear(v, temp);
        vector_add(result, count); // Guardamos la cantidad de veces que aparece  
        i += count; // Saltamos todas las ocurrencias de ese número
    }
    
    return result;
}
