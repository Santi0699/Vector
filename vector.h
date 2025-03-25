#ifndef MI_HEADER_H
#define MI_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#define T_Elem int


typedef struct {
    
    T_Elem* a;
    int size;
    int maxsize;

}vector;


vector* vector_init(int dim)
{
    vector* v = (vector*)malloc(sizeof(vector));
    v->a=(int*)malloc(dim*sizeof(int));
    v->size=0;
    v->maxsize=dim;
    return v;
}

void vector_free(vector* v)
{
    free(v->a);
    free(v);
}

int vector_size(vector*v)
{
    if (v==NULL) return -1;

    return v->size;
}

int vector_max_size(vector*v)
{
    if (v==NULL) return -1;

    return v->maxsize;
}

int vector_isfull(vector* v)
{
    if (v==NULL) return -1;

    if(v->size==v->maxsize)
    {
        return 1;
    }
    return 0;
}

int vector_isempty(vector* v)
{
    if (v==NULL) return -1;

    if(v->size==0)
    {
        return 1;
    }
    return 0;
}


T_Elem vector_get(vector* v, int index)
{
    if(v==NULL)return -1;
    if(index >= v->maxsize)return -2;
    if(index<0)return -3;

    return v->a[index];
}

T_Elem vector_set(vector* v, int index, int value) 
{
    if(v==NULL)return -1;
    if(index >= v->maxsize)return -2;
    if(index<0)return -3;

    v->a[index]=value;

    return 0;

}

int vector_add(vector* v, int value)
{
    if(v==NULL)return -1;

    int i=vector_size(v);
    if(vector_isfull(v))
    {
        vector* temp = (vector*) realloc(v, sizeof(vector) + (v->maxsize + 1) * sizeof(int));
        v=temp;
        v->maxsize=v->maxsize+1;
        vector_set(v,i,value);
        return 1;
    }

    return 0;

}

void vector_resize(vector** v)
{
    if(*v==NULL) return;

    int i=vector_size(*v);

    if(vector_isfull(*v))
    {
        vector* temp = (vector*) realloc(*v, sizeof(vector) + ((*v)->maxsize + 1) * sizeof(int));
        *v=temp;
        (*v)->maxsize=(*v)->maxsize+1;
    

    }
}

void vector_remove(vector*v, int index)
{
    if(v==NULL)return ;

    for(int i = index; i < v->size - 1; i++)
    {
        v->a[i] = v->a[i + 1];
    }

    v->size--;
    
}

int vector_insert(vector* v, int value, int index)
{
    if(v==NULL)return -1;
    int dim=vector_size(v);
    if(vector_isfull(v))
    {
        vector_resize(&v);
        for(int j=dim; j>index; j--)
        {
         v->a[j]=v->a[j-1];
        }
    }else{
        for(int i = dim; i>index; i--)
        {
            v->a[i]=v->a[i-1];
        }
        vector_set(v,index,value);
    }



    return 1;

}

int vector_value_pos(vector* v, int index)
{
    if(v==NULL) return -1;
    int i=0;
    vector* aux=v;
    int flag=0;

    while(i!=v->size && flag==0)
    {
        if(aux->a[i]!=v->a[index])
        {
            flag=1;

        }
        i++;
    }

    if(flag)
    {
        return i-1;
    }
    return 0;
}



#endif