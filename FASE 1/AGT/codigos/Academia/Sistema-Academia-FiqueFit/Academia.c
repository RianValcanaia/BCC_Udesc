#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>

void limparTerminal() {
    printf("\033[H\033[J"); 
    //Sequencia de ANSI
    // \033 inicia a sequencia de ANSI
    // [H joga o mouse para a posição inicial (1,1) "Home"
    // \033 inicia novamente
    //[J deleta da posição do pause até o final do terminal
}

//protótipo da função
int valor (char plano, char tipoAdesao[10], char periodo[8]);

int main()
{
    setlocale(LC_ALL,""); //funcao para permitir caracteres especiais

    //variáveis globais
    char plano; // tipo primitivo
    char periodo[8], nome[200], tipoAdesao[10], nomePlano[50], outro[10];// estrutura de dados

	//Tela Inicial
    limparTerminal();
    printf("⠀⠀⠀⠀⠀⠀⣀⣀⣀⠀⣴⣿⣿⣿⣷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⣿⣿⣷⡄⠀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⠶⠿⢶⣄⠀⢸⡿⠿⠀⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡿⠿⠀⡆⠀⣤⠀\n⠀⠀⠀⠀⠀⢸⣿⣿⣿⡇⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⡇⣾⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡿⠀⣴⠶⡶⠹⡄⢸⡇⠀⠀⡄⠀⣴⣤⡄⢠⡄⢠⡄⠀⣤⣦⠀⢸⡇⠀⠀⡄⠠⣿⠤\n⠀⠀⠀⠀⠀⢸⣿⣿⣿⡇⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⡇⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠁⣸⠃⢰⡇⠀⡇⢸⡟⠛⠀⡇⢸⡇⠀⡇⢸⡇⢸⡇⢸⣇⣸⡇⢸⡟⠛⠀⡇⠀⣿⠀\n⠀⠀⠀⢸⣿⢸⣿⣿⣿⡇⣿⣿⣿⣿⣿⡇⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⣿⣿⣿⣿⣿⡇⣿⣿⣿⣿⡇⣿⡇⠀⠀⠀⠀⠀⠀⠀⢸⡄⠹⣦⠾⣀⠾⠀⢸⡇⠀⠀⡇⢸⡇⠀⡇⢸⡇⢸⡇⢸⡇⢠⡄⢸⡇⠀⠀⡇⠀⣿⠀\n⠀⠀⠀⢸⣿⢸⣿⣿⣿⡇⣿⣿⣿⣿⣿⡇⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⣿⣿⣿⣿⣿⡇⣿⣿⣿⣿⡇⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠿⣄⣀⣀⣀⠀⠀⠘⠃⠀⠀⠃⠀⠛⠛⡇⠀⠛⠙⠃⠀⠛⠛⠀⠘⠃⠀⠀⠃⠀⠛⠛\n⠀⠀⠀⠀⠀⢸⣿⣿⣿⡇⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⡇⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⢸⣿⣿⣿⡇⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⡇⢿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀Bem-vindo(a)!\n⠀⠀⠀⠀⠀⠀⠉⠉⠉⠀⠻⣿⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⣿⡿⠃⠀⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀Aperte enter para entrar no programa:\n");
	
    getchar();
	
	//entrada escolha do plano
    while(1){
    limparTerminal();
    //printf("Bem vindo a @FiqueFit (:\n");
    printf("Escolha um dos planos:\na) Natação \nb) Musculação\nc) Treinamento Funcional\nd) Plano seco: musculação + funcional\ne) Plano molhado: musculação + natação\n");
    
    //Enquanto a entrada não ser uma das opções desejadas ele irá retornar opção inválida
    while(1){
        scanf (" %c",&plano);
        if((plano == 'a' || plano == 'b' || plano == 'c' || plano == 'd' || plano == 'e')){
                break;
            } else {
                printf("Opção inválida. Tente novamente.\n");
            }
    }
    
    limparTerminal();

    //processamento do input do plano
    switch (plano){
        case 'a':
           strcpy(nomePlano,  "Natação");
           break;
        
        case 'b':
           strcpy(nomePlano,  "Musculação");
           break;
        
        case 'c':
           strcpy(nomePlano,  "Treinamento Funcional");
           break;
        
        case 'd':
           strcpy(nomePlano,  "Plano seco: musculação + funcional");
           break;
        
        case 'e':
           strcpy(nomePlano,  "Plano molhado: musculação + natação");
           break;
        
        default:
            printf("Opção inválida! Tente novamente.");
            system("cls");
            break;
        
    }
    
    //entrada de dados
    
    //Enquanto o periodo for diferente de dia e noite ele retorna opção invalida
    printf("Digite o período desejado (dia ou noite)\n"); 
    while(1){
        scanf (" %s", periodo);
        if (strcmp(periodo, "dia") == 0 || strcmp(periodo, "noite") == 0){
            break;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }
    
    printf("Digite o nome do cliente\n");
    scanf ("\n%[^\n]s",nome);
    
    /*Como os planos 'd' e 'e' nao possuem plano mensal, ja processamos eles
    como 'anual' aqui para economizar memória e linhas nas condicionais posteriores*/
    if ((plano == 'd') || (plano == 'e')){
        strcpy(tipoAdesao, "anual");
    }else{
        printf("Digite o tipo da adesão desejada (mensal ou anual)\n");
        while(1){
            scanf (" %s",tipoAdesao);
            if (strcmp(tipoAdesao, "mensal") == 0 || strcmp(tipoAdesao, "anual") == 0){
                break;
            } else {
                printf("Opção inválida. Tente novamente.\n");
            }
        }
        
    }
    
    //calculo do valor da mensalidade, chamando a funcao valor
    int valorMensal = valor(plano, tipoAdesao, periodo);

    //saida de dados
    limparTerminal();
    printf("Cliente: %s\n", nome);
    printf("%s ( %s )\n", nomePlano, periodo);
    printf("Pagamento %s\n", tipoAdesao);

    //processamento dos pagamentos baseado na escolha do tipo de adesao 
    if (strcmp(tipoAdesao, "anual") == 0) {
        int total = valorMensal * 12;
        printf("12 x R$ %i\n", valorMensal);
        printf("Total: %i\n", total);
    }else{
        printf("R$ %i\n", valorMensal);
    }

    //Cadastrar outro cliente
    printf("Outro cliente? (sim/nao): ");
    while(1){
        scanf("%s", outro);
        if (strcmp(outro, "sim") == 0 || strcmp(outro, "nao") == 0){
            break;
        }else{
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    if (strcmp(outro, "nao") == 0){
        break;   
    }
    }
    return 0;
}

//função preco
int valor (char plano, char tipoAdesao[10], char periodo[8]){

    int valor, total;

    switch(plano){

        case 'a':
           if ((strcmp(tipoAdesao, "mensal") == 0) && (strcmp(periodo, "dia") == 0)) {
               valor = 220;
           }else if((strcmp(tipoAdesao, "mensal") == 0) && (strcmp(periodo, "noite") == 0)) {
               valor = 270;
           }else if(strcmp(tipoAdesao, "anual") == 0) {
               valor = 198;
           }else{
               printf("Erro!\n");
           }

           break;
        
        case 'b':
           if (strcmp(tipoAdesao, "mensal") == 0) {
               valor = 110;
           } else if (strcmp(tipoAdesao, "anual") == 0) {
               valor = 100;
           } else {
               printf("Erro!\n");
           }

           break;

       case 'c':
          if (strcmp(tipoAdesao, "mensal") == 0) {
              valor = 200;
          }else if(strcmp(tipoAdesao, "anual") == 0) {
              valor = 180;
          }else{
              printf("Erro!\n");
          }

          break;

        case 'd':
           if (strcmp(tipoAdesao, "mensal") == 0) {
               printf("Não há plano mensal para esta assinatura!");
           }else if(strcmp(tipoAdesao, "anual") == 0) {
               valor = 280;
           }else{
               printf("Erro!\n");
           }

           break;
        
        case 'e':
        
           if(strcmp(tipoAdesao, "mensal") == 0){
              printf("Não há plano mensal para esta assinatura!");
           }else if(strcmp(tipoAdesao, "anual") == 0){
              valor = 298;
           }else{
              printf("Erro\n");
	   }

           break;
        
        default:
           printf("Opção inválida! Tente novamente.\n");
       
           break;
        
    }
    
    return valor;

}