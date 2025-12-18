// Para responder, construa algoritmo para fazer uma varredura pela matriz e escreva:
// a) qual a media das temperaturas maxima, media e minima mensais.
// b) qual o mes de menor precipitacao ? 
// c) qual a temperatura media para precipitacoes superiores a 200mm

// Se necessitar indicar o mes, use apenas o indice da matriz apenas ( nao escrever a palavra ).

#include <stdio.h>
#include <stdlib.h>
#define L 4
#define C 12

char* mes(int mes){

    static char meses[C][20] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro","Dezembro"};
    return meses[mes];
}

int main(){
double matriz[L][C] = 
{{29.3, 28.2, 29.1, 26 , 23.8 , 22.1 , 21.3 , 21.7 , 22.6 , 24.2 , 26.3 , 27.7},
{25.1 , 25.1 , 24.1 , 21.8 , 19.5 , 18 , 17.1 , 17.6 , 18.8 , 20.6 , 22.4 , 23.6},
{21 , 21.1 , 20.1 , 17.61 , 15.3 , 14 , 12.9 , 13.6 , 15.1 , 17 , 18.5 , 19.5},
{258 , 234 , 216 , 122.1 , 111.3 , 98.6 , 107.7 , 98 , 137 , 173.4 , 159 , 208.1}};

double mediaMaxima=0, mediaMinima=0, mediaMedia=0, menorPrecipitacao = 1000000, mediaP200 = 0;
int mesMenorPrecipitacao, elementos=0;
//temperatura media
for(int i = 0; i < C; i++){
    mediaMaxima += matriz[0][i];
    mediaMedia += matriz[1][i];
    mediaMinima += matriz[2][i];
    if(matriz[3][i] < menorPrecipitacao){
        menorPrecipitacao = matriz[3][i];
        mesMenorPrecipitacao = i;
    }
    if(matriz[3][i] > 200){
        mediaP200 += matriz[3][i];
        elementos++; 
    }
    
}
char *mesMenorP = mes(mesMenorPrecipitacao);

printf("Media Maxima: %lf\nMedia Media: %lf\nMedia Minima: %lf\n", (mediaMaxima/C), (mediaMedia/C), (mediaMinima/C));
printf("%s eh o mes de menor precipitacao\n", mesMenorP);
printf("%lf eh a media da precipitacao acima de 200mm.\n", (mediaP200/elementos));

return 0;
}