#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct dados1
{
    char nome[30];
    char autor[30];
};

struct dados2
{
    char nome[30];
    int tel;
};

struct dados1 livros[6];
struct dados2 clientes[6];
FILE *pArq;
int v[6],j=0;

void infoclientes()
{
    strcpy(clientes[0].nome,"Pedro");
    strcpy(clientes[1].nome,"Roger");
    strcpy(clientes[2].nome,"Gabriela");
    strcpy(clientes[3].nome,"Marcos");
    strcpy(clientes[4].nome,"Jair");
    strcpy(clientes[5].nome,"Fernanda");

    clientes[0].tel=999999999;
    clientes[1].tel=888888888;
    clientes[2].tel=777777777;
    clientes[3].tel=666666666;
    clientes[4].tel=555555555;
    clientes[5].tel=444444444;
}

int random ()
{
    int i,aux,cont=0;
rdm:
        aux=rand()%6;

        for (i=0; i<5; i++)
            if (aux==v[i])
                cont++;
        if (cont!=0)
        {
            cont=0;
            goto rdm;
        }
        else
        {
            v[j]=aux;
            cont=0;
            j++;
            return aux;
        }
}

void clientesorteado(int num)
{
    fprintf(pArq,"%s\n51 %d\n",clientes[num].nome,clientes[num].tel);
}

int empilhar(top)
{
    strcpy(livros[top].nome,"Chapeuzinho Vermelho");
    strcpy(livros[top].autor,"Charles Perrault");
    top++;
    strcpy(livros[top].nome,"Branca de Neve");
    strcpy(livros[top].autor,"Irmaos Grimm");
    top++;
    strcpy(livros[top].nome,"Ursinho Pooh");
    strcpy(livros[top].autor,"Walt Disney");
    top++;
    strcpy(livros[top].nome,"Mickey Mouse");
    strcpy(livros[top].autor,"Walt Disney");
    top++;
    strcpy(livros[top].nome,"PicaPau");
    strcpy(livros[top].autor,"Walter Lantz");
    top++;
    strcpy(livros[top].nome,"Alice in Wonderland");
    strcpy(livros[top].autor,"Lewis Carroll");
    return top;
}

int desempilhar(top)
{
    fprintf(pArq,"%s - %s\n\n",livros[top].nome,livros[top].autor);
    top--;
    return top;
}

int main()
{
    int top=0,rando,i;
    srand(time(NULL));
    if((pArq = fopen("brindes.txt","w+")) == NULL)
    {
        printf("Erro ao abrir arquivo!!!\n");
        exit(1);
    }

    infoclientes();
    top=empilhar(top);

    for (i=0;i<6;i++)
    {
    rando=random();
    clientesorteado(rando);
    top=desempilhar(top);
    }
}
