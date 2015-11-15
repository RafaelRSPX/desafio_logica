/*Ex3: Desenvolver um programa que resolva o desafio de logica: Guerra de Carros*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXM 5
#define MAXCAT1 3 
#define MAXCAT2 4

typedef struct
{
    int M[MAXCAT1][MAXCAT2][MAXM][MAXM];    //Tabela quadridimensional contendo as categorias, objetos e a relacao entre os objetos
                                            //Tabela M12, M13, M13, M23, M24, M34 e todas sao 5x5

}dados;

/*Prototipos das funcoes*/
dados imprimemenu(dados d);
dados preenche0(dados d);

/*Prototipos das regras*/
dados regra1(dados d);
dados regra2(dados d);
dados regra3(dados d);

int main(void)
{
    dados d;
    char r;
    int i, j;  
    int z, y; 
    int temzero, tentativa=0;
       
    d=preenche0(d); /*preenchimento da Matriz M com o valor de vazio->0*/
   
    /*Entrada de dados*/   
    printf("\nDesafio Guerra de carro.\n\nPreencha a tabela indicando as categorias que voce quer relacionar e os objetos\n\n");
    printf("Por favor, digite o valor da categoria e tecle enter.\n\n");

    /*Preenchimento com os relacionametnos digitados pelo usuario*/
    do
    {
        d=imprimemenu(d);   /*Chamada da funcao imprimemenu*/
        printf("\nEste foi o ultimo relacionamento? (S/N)\n");
        getchar();
        r=getchar();
        getchar();
    }while(r!='S');

    /*Processamento - aplicacao das regras*/
    /*O processamento vai durar ate a matriz nao ter 0 ou o incremento da variaevl 'tentativa' for menor que 1000
     * Ou seja o processamento fazer o trabalho 100 vezes*/
    do
    {
        d=regra1(d);
        d=regra2(d);
        /*d=regra3(d);*/

        for(i=0;i<MAXCAT1;i++)
            for(j=1;j<MAXCAT2;j++)
                if(i!=j)
                    for(y=0;y<MAXM;y++)
                        for(z=0;z<MAXM;z++)
                            if(d.M[i][j][y][z]==0)
                                temzero=1;
                            else
                                temzero=0;
        tentativa+=1;
        if(tentativa==1000)
            printf("\nNao foi possivel resolver este problema com a quantidade de informacoes que voce forneceu.\nPor favor, tente novamente fornecendo mais informacoes ao programa.\n\n");

    }while(tentativa<1000 && temzero==1);
    
    /* TODO:
     * Completar as regras;
     * Fazer uma funcao que imprima o resultado
     */

    /*Impressao da matriz*/
    for(i=0;i<MAXCAT1;i++)
        for(j=1;j<MAXCAT2;j++)
            if(i!=j)
                for(y=0;y<MAXM;y++)
                    for(z=0;z<MAXM;z++)
                        printf("M[%d][%d][%d][%d]=%d\n", i, j, y, z, d.M[i][j][y][z]);

    return EXIT_SUCCESS;
}

/*Corpo da funcao preenche*/
dados preenche0(dados d)
{
    int i, j;
    int y, z;

    for(i=0;i<MAXCAT1;i++)
        for(j=1;j<MAXCAT2;j++)
            if(i!=j)
                for(y=0;y<MAXM;y++)
                    for(z=0;z<MAXM;z++)
                        d.M[i][j][y][z]=0;

    return d;
}

/**********************************************************************************************************/
/*Corpo da funcao imprimemenu*/
dados imprimemenu(dados d) 
{
    int i, j;           /*Contadores para as categorias */
    int y, z;           /*Contadores para os objetos*/
    int opt, naovale;   /* opt para o switch
                         * naovale para evitar que o usuario escreva uma opcao invalida
                         */
    int relacionamento;  /*Recebe o valor 1 (SIM) ou 2 (NAO) para o relacionamento entre os objetos*/

    /*Primeiro laco para preencher o valor de i e y*/
   
    /*Laco para receber o valor de i*/
    /*Laco "do" para evitar que i receba um valor invalido*/

    do
    {
        printf("Categoria:\n1- Comprador\n2- Carro\n3- Estilo\n4- Ano\n");
        scanf("%d", &i);
        naovale=0;    
        if(!(i==1 || i==2 || i==3 || i==4)) 
        {
            printf("\nOpcao invalida.\nPor favor, digite um valor das opcoes dadas.\n\n");
            naovale=1;
        }
        opt=i;
        i-=1;
    }while((naovale));

    /*Switch para receber o valor de y*/
    switch(opt)
    {
        case 1:
            do  /*Laco "do" para evitar que y receba um valor invalido*/
            {
                printf("Digite o valor do objeto e tecle enter.\n\n");
                printf("Objeto:\n1- Eduardo\n2- Ilana\n3- Jose\n4- Luciana\n5- Rui\n");
                scanf("%d", &y);
                naovale=0;
                if(!(y==1|| y==2 || y==3 || y==4 || y==5))
                {
                    printf("Nao entendi o que voce digitou.\nPor favor, digite um valor das opcoes dadas.\n");
                    naovale=1;
                }
                y-=1;
            }while((naovale));
            break;
        
        case 2:
            do
            {
                printf("Digite o valor do objeto e tecle enter.\n\n");
                printf("Objeto:\n1- Corsa\n2- Escorte\n3- Palio\n4- Astra\n5- Blazer\n");
                scanf("%d", &y);
                naovale=0;
                if(!(y==1|| y==2 || y==3 || y==4 || y==5))
                {
                    printf("Nao entendi o que voce digitou.\nPor favor, digite um valor das opcoes dadas.\n");
                    naovale=1;
                }
                y-=1;
            }while((naovale));
            break;

        case 3:
            do
            {
                printf("Digite o valor do objeto e tecle enter.\n\n");
                printf("Objeto:\n1- Conversivel\n2- Caminhonete\n3- Hatch\n4- Sedan\n5- Station Wagon\n");
                scanf("%d", &y);
                naovale=0;
                if(!(y==1|| y==2 || y==3 || y==4 || y==5))
                {
                    printf("Nao entendi o que voce digitou.\nPor favor, digite um valor das opcoes dadas.\n");
                    naovale=1;
                }
                y-=1;
            }while((naovale));
            break;

        case 4:
            do
            {
                printf("Digite o valor do objeto e tecle enter.\n\n");
                printf("Objeto:\n1- 1992\n2- 1993\n3- 1994\n4- 1995\n5- 1996\n");
                scanf("%d", &y);
                naovale=0;
                if(!(y==1|| y==2 || y==3 || y==4 || y==5))
                {
                    printf("Nao entendi o que voce digitou.\nPor favor, digite um valor das opcoes dadas.\n");
                    naovale=1;
                }
                y-=1;
            }while((naovale));
            break;
    }      

    printf("\nAgora selecione a segunda categoria e o objeto na qual voce quer relacionar com o objeto anterior\n\n");

    /*Segundo laco para receber o valor de j e z*/

    /*Laco para receber o valor de j*/
    do
    {
        printf("Categoria:\n1- Comprador\n2- Carro\n3- Estilo\n4- Ano\n");
        scanf("%d", &j);
        naovale=0;    
        if(!(j==1 || j==2 || j==3 || j==4))
        {
            printf("\nNao entendi o que voce escreveu.\nPor favor, digite um valor das opcoes dadas.\n\n");
            naovale=1;
        }
        opt=j;
        j-=1;
    }while((naovale));

    /*Switch para receber o valor de z*/
    switch(opt)
    {
        case 1:
            do
            {
                printf("Digite o valor do objeto e tecle enter.\n\n");
                printf("Objeto:\n1- Eduardo\n2- Ilana\n3- Jose\n4- Luciana\n5- Rui\n");
                scanf("%d", &z);
                naovale=0;
                if(!(z==1|| z==2 || z==3 || z==4 || z==5))
                {
                    printf("Nao entendi o que voce digitou.\nPor favor, digite um valor das opcoes dadas.\n");
                    naovale=1;
                }
                z-=1;
            }while((naovale));
            break;
        
        case 2:
            do
            {
                printf("Digite o valor do objeto e tecle enter.\n\n");
                printf("Objeto:\n1- Corsa\n2- Escorte\n3- Palio\n4- Astra\n5- Blazer\n");
                scanf("%d", &z);
                naovale=0;
                if(!(z==1|| z==2 || z==3 || z==4 || z==5))
                {
                    printf("Nao entendi o que voce digitou.\nPor favor, digite um valor das opcoes dadas.\n");
                    naovale=1;
                }
                z-=1;
            }while((naovale));
            break;

        case 3:
            do
            {
                printf("Digite o valor do objeto e tecle enter.\n\n");
                printf("Objeto:\n1- Conversivel\n2- Caminhonete\n3- Hatch\n4- Sedan\n5- Station Wagon\n");
                scanf("%d", &z);
                naovale=0;
                if(!(z==1|| z==2 || z==3 || z==4 || z==5))
                {
                    printf("Nao entendi o que voce digitou.\nPor favor, digite um valor das opcoes dadas.\n");
                    naovale=1;
                }
                z-=1;
            }while((naovale));
            break;

        case 4:
            do
            {
                printf("Digite o valor do objeto e tecle enter.\n\n");
                printf("Objeto:\n1- 1992\n2- 1993\n3- 1994\n4- 1995\n5- 1996\n");
                scanf("%d", &z);
                naovale=0;
                if(!(z==1|| z==2 || z==3 || z==4 || z==5))
                {
                    printf("Nao entendi o que voce digitou.\nPor favor, digite um valor das opcoes dadas.\n");
                    naovale=1;
                }
                z-=1;
            }while((naovale));
            break;
    }

    /*Relacionamento dos objetos das categorias*/
    do
    {
        printf("\nQual o relacionamento entre os objetos?\n1- Sim\n2- Nao\n");
        scanf("%d", &relacionamento);
        naovale=0;
        if(relacionamento!=1 && relacionamento!=2)
        {
            printf("\nOpcao invalida!!!\nPor favor, digite um valor das opcoes dadas.\n");
            naovale=1;
        }
        else
            d.M[i][j][y][z]=relacionamento;
    }while((naovale));
        
    return d;
}
/******************************************************************************************************************/

/*Regras*/
/*Aplicacao do nao nas celulas adjacentes*/
/*Se uma celula da matriz receber 1, os adjacentes rebem 2*/
dados regra1(dados d)
{
    int i, j;   /*Contadores para as categorias*/
    int y, z;   /*Contadores para os objetos
                 *y para os objetos na vertical
                 *z para os objetos na horizontal
                 */
    int y1, z1; /*contadores auxiliares*/
    
    for(i=0;i<MAXCAT1;i++)
        for(j=1;j<MAXCAT2;j++)
            if(i!=j)
                for(y=0;y<MAXM;y++)
                    for(z=0;z<MAXM;z++)
                        if((d.M[i][j][y][z]==1))                /*Se um valor da matriz for 1(sim), os adjacentes receberao 2*/
                            for(y1=0;y1<MAXM;y1++)              
                                for(z1=0;z1<MAXM;z1++)
                                {
                                    if(y1!=y)
                                        d.M[i][j][y1][z]=2;
                                    if(z1!=z)
                                        d.M[i][j][y][z1]=2;
                                }
    return d;
}

/*Regra da simetria*/
/* Procura o 1 e quais as categorias e obejtos que estao com relacionados com 1
 * Depois, procure o 2 na linha do objeto que recebeu 1 e faca a simetria com o objeto relacionado
 * Depois, procure 2 na coluna do objeto que recebeu 1 e faca a simetria com o objeto relacionado[
 */

/*AINDA NAO ESTA FUNCIONANDO*/
dados regra2(dados d)
{
    int i, j;
    int y, z;
    int i1, j1;
    int y1, z1;
    
    /*Primeiro laco para a procura do 1 nas celulas da matriz*/
    for(i=0;i<MAXCAT1;i++)
        for(j=1;j<MAXCAT2;j++)
            if(i!=j)
                for(y=0;y<MAXM;y++)
                    for(z=0;z<MAXM;z++)
                        if((d.M[i][j][y][z]==1))
                            /*Segundo laço para a procura do 2 nas celulas*/
                            for(j1=1;j1<j;j1++)
                                for(z1=0;z1<MAXM;z1++)
                                    if(d.M[i][j1][y][z1]==2)
                                        d.M[j1][j][y][z1]=2;
     for(i=0;i<MAXCAT1;i++)
        for(j=1;j<MAXCAT2;j++)
            if(i!=j)
                for(y=0;y<MAXM;y++)
                    for(z=0;z<MAXM;z++)
                        if((d.M[i][j][y][z]==1))
                            /*Segundo laço para a procura do 2 nas celulas*/
                            for(i1=1;i1<i;i1++)
                                for(z1=0;z1<MAXM;z1++)
                                    if(d.M[i1][j][y][z1]==2)
                                        d.M[i][i1][y][z1]=2;
     return d;
}

