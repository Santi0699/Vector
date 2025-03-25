#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

void vector_add_random(vector* v);

int main ()
{
    vector* vectorsito=vector_init(50);
    vector_add_random(vectorsito);
    int dim=vector_size(vectorsito);
    for(int i=0; i<dim;i++)
    {
        int value=vector_get(vectorsito,i);
        printf("%d ",value);
    }
    return 0;
}


void vector_add_random(vector* v)
{
    if (v==NULL)return;

    int i=0;
    while(!vector_isfull(v))
    {
        int value=rand()%100;
        int temp=vector_set(v,i,value);
        v->size++;
        i++;
    }

}
