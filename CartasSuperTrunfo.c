#include <stdio.h>
#include <string.h>
#include <math.h>
#include <locale.h>

struct CartasSuperTrunfo //armazenar dados das cartas
{
    char Estado[50];
    char Codigo[50]; //código da carta
    char Nome[50];   //nome da cidade
    int Populacao;
    float Area;
    float PIB; 
    int Pontos; //número de pontos turísticos
    float densidade;
    float percapita;
    float superPoder;
};

void exibirDiferenca(const char* atributo, float val1, float val2, int isInt) {
    float diff = fabsf(val1 - val2);
    const char* vencedor;
    if (val1 > val2) {
        vencedor = "Carta 1";
    } else if (val2 > val1) {
        vencedor = "Carta 2";
    } else {
        vencedor = "Empate";
    }

    if(isInt) {
        printf("%s: %s venceu por diferenca de %.0f\n", atributo, vencedor, diff);
    } else {
        printf("%s: %s venceu por diferenca de %.2f\n", atributo, vencedor, diff);
    }
}

int main(){
    struct CartasSuperTrunfo cartas[2];

    for (int i = 0; i < 2; i++)
    {
        printf("Digite os dados da carta %d:\n", i + 1);

        printf("Digite o estado: \n");
        fgets(cartas[i].Estado, sizeof(cartas[i].Estado), stdin);

        printf("Digite o codigo da carta: \n");
        fgets(cartas[i].Codigo, sizeof(cartas[i].Codigo), stdin);

        printf("Digite o nome da cidade: \n");
        fgets(cartas[i].Nome, sizeof(cartas[i].Nome), stdin);

        printf("Digite a populacao da cidade: \n");
        scanf("%d", &cartas[i].Populacao);

        printf("Digite a area da cidade: \n");
        scanf("%f", &cartas[i].Area);

        printf("Digite o PIB(em bilhoes): \n");
        scanf("%f", &cartas[i].PIB);

        printf("Quantos pontos turisticos tem a cidade: \n");
        scanf("%d", &cartas[i].Pontos);
        //calcular densidade
        if (cartas[i].Area > 0) {
            cartas[i].densidade = cartas[i].Populacao / cartas[i].Area;
        } else {
            cartas[i].densidade = 0;
        }
        //calcular per capits
        if (cartas[i].Populacao > 0) {
            cartas[i].percapita = cartas[i].PIB * 1e9 / cartas[i].Populacao;
        } else {
            cartas[i].percapita = 0;
        }
        //quanto menos a densidade maior o poder
        float densidadePeso = 0.0f;
        if (cartas[i].densidade > 0) {
            densidadePeso = 1.0f / (cartas[i].densidade + 0.0001f);
        } else {
            densidadePeso = 1000000.0f;
        }
        //calcular Super poder
        cartas[i].superPoder = (float)cartas[i].Populacao + cartas[i].Area + cartas[i].PIB + (float)cartas[i].Pontos + densidadePeso;

        while (getchar() != '\n');
    }

    // Exibir dados das cartas
    for (int i = 0; i < 2; i++) {
        printf("\nDados da carta %d:\n", i + 1);
        printf("Estado: %s", cartas[i].Estado);
        printf("Codigo: %s", cartas[i].Codigo);
        printf("Nome: %s", cartas[i].Nome);
        printf("Populacao: %d\n", cartas[i].Populacao);
        printf("Area: %.2f\n", cartas[i].Area);
        printf("PIB: %.2f\n", cartas[i].PIB);
        printf("Pontos Turisticos: %d\n", cartas[i].Pontos);
        printf("Densidade populacional: %.2f habitantes/km²\n", cartas[i].densidade);
        printf("PIB per capita: %.2f por pessoa\n", cartas[i].percapita);
        printf("Super poder da carta: %.2f\n", cartas[i].superPoder);
        printf("\n");
    }

    // Comparações dos atributos numéricos
    printf("Comparacao dos atributos entre as cartas:\n");
    exibirDiferenca("Populacao", (float)cartas[0].Populacao, (float)cartas[1].Populacao, 1);
    exibirDiferenca("Area", cartas[0].Area, cartas[1].Area, 0);
    exibirDiferenca("PIB", cartas[0].PIB, cartas[1].PIB, 0);
    exibirDiferenca("Pontos Turisticos", (float)cartas[0].Pontos, (float)cartas[1].Pontos, 1);
    exibirDiferenca("Densidade populacional", cartas[0].densidade, cartas[1].densidade, 0);
    exibirDiferenca("PIB per capita", cartas[0].percapita, cartas[1].percapita, 0);
    exibirDiferenca("Super poder", cartas[0].superPoder, cartas[1].superPoder, 0);

    // Indicar carta vencedora
    if (cartas[0].superPoder > cartas[1].superPoder) {
        printf("\nCarta 1 é a vencedora!\n");
    } else if (cartas[1].superPoder > cartas[0].superPoder) {
        printf("\nCarta 2 é a vencedora!\n");
    } else {
        printf("\nEmpate entre as cartas!\n");
    }

    return 0;
}

