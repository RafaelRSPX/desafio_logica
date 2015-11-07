//Ex13: Desenvolver um programa que resolva o desafio de lógica: Guerra de Carros

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXM 5
#define MAXCAT1 3
#define MAXCAT2 4

typedef struct
{
    int M[MAXCAT1][MAXCAT2][MAXM][MAXM];    //Tabela quadridimensional contendo as categorias, objetos e a relação entre os objetos
                                            //Tabela M12, M13, M13, M23, M24, M34 e todas são 5x5

}dados;

/*Protótipos das funções*/

void imprimemenu(dados d);
dados preenche0(dados d);

int main(void)
{
    dados d;
    char r;
    int i, j;  
    int z, y; 

    preenche0(d); //preenchimento da Matriz M com o valor de vazio->0

    for(i=0;i<MAXCAT1;i++)
        for(j=1;j<MAXCAT2;j++)
            if(i!=j)
                for(y=0;y<MAXM;y++)
                    for(z=0;z<MAXM;z++)
                        printf("M[%d][%d][%d][%d]=%d\n", i, j, y, z, d.M[i][j][y][z]);

    /*Entrada de dados*/
   
    printf("\nDesafio Guerra de carro.\n\nPreencha a tabela indicando as categorias que voce quer relacionar e os objetos\n\n");
    printf("Por favor, digite o valor da categoria e tecle enter.\n\n");

    do
    {
        imprimemenu(d); //Chamada da função imprimemenu
        printf("\nEste foi o ultimo relacionamento? (S/N)\n");
        getchar();
        r=getchar();
        getchar();
    }while(r!='S');
        
    return EXIT_SUCCESS;
}

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

    return d; //não está retornando o valor da matriz com 0, mas está preenchendo a matriz com 0 Porque?
}

void imprimemenu(dados d) //deve retornar a matriz, por enquanto deixe void
{
    int i, j;   //Contadores para as categorias 
    int y, z;   //Contadores para os objetos
    int opt, naovale;

    /*Primeiro laço para preencher o valor de i e y*/
   
    //Laço para receber o valor de i
    do  //Laço "do" para evitar que i receba um valor inválido
    {
        printf("Categoria:\n1- Comprador\n2- Carro\n3- Estilo\n4- Ano\n");
        scanf("%d", &i);
        naovale=0;    
        if(!(i==1 || i==2 || i==3 || i==4)) 
        {
            printf("\nNão entendi o que voce escreveu.\nPor favor, digite um valor das opçoes dadas.\n\n");
            naovale=1;
        }
        opt=i;
        i-=1;
    }while((naovale));

    //Switch para receber o valor de y
    switch(opt)
    {
        case 1:
            do  //Laço "do" para evitar que y receba um valor inválido
            {
                printf("Digite o valor do objeto e tecle enter.\n\n");
                printf("Objeto:\n1- Eduardo\n2- Ilana\n3- Jose\n4- Luciana\n5- Rui\n");
                scanf("%d", &y);
                naovale=0;
                if(!(y==1|| y==2 || y==3 || y==4 || y==5))
                {
                    printf("Não entendi o que você digitou.\nPor favor, digite um valor das opçoes dadas.\n");
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
                    printf("Não entendi o que você digitou.\nPor favor, digite um valor das opçoes dadas.\n");
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
                    printf("Não entendi o que você digitou.\nPor favor, digite um valor das opçoes dadas.\n");
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
                    printf("Não entendi o que você digitou.\nPor favor, digite um valor das opçoes dadas.\n");
                    naovale=1;
                }
                y-=1;
            }while((naovale));
            break;
    }      

    printf("\nAgora selecione a segunda categoria e o objeto na qual voce quer relacionar com o objeto anterior\n\n");

    /*Segundo laço para receber o valor de j e z*/

    //Laço para receber o valor de j
    do
    {
        printf("Categoria:\n1- Comprador\n2- Carro\n3- Estilo\n4- Ano\n");
        scanf("%d", &j);
        naovale=0;    
        if(!(j==1 || j==2 || j==3 || j==4))
        {
            printf("\nNão entendi o que voce escreveu.\nPor favor, digite um valor das opçoes dadas.\n\n");
            naovale=1;
        }
        opt=j;
        j-=1;
    }while((naovale));

    //Switch para receber o valor de z
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
                    printf("Não entendi o que você digitou.\nPor favor, digite um valor das opçoes dadas.\n");
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
                    printf("Não entendi o que você digitou.\nPor favor, digite um valor das opçoes dadas.\n");
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
                    printf("Não entendi o que você digitou.\nPor favor, digite um valor das opçoes dadas.\n");
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
                    printf("Não entendi o que você digitou.\nPor favor, digite um valor das opçoes dadas.\n");
                    naovale=1;
                }
                z-=1;
            }while((naovale));
            break;
    }

    /*Relacionamento dos objetos das categorias*/

    return;
}
