#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

//Observação: se rodar o programa no GDB online a imagem inicial irá travar, pode ser por conta do UTF-8 no qual utilizei texto em Braille para fazer a tela Inicial, para melhor proveito do programa sujiro rodar no terminal.

void limpaTela(){
	printf("\033[H\033[J"); 
	//Sequencia ANSI:
	// \033 - inicia a sequencia ANSI
	// [H - move o cursor para a posição (1,1)  no terminal "Home"
	// \033 - novamente para indicar outra função 
	// [J - limpa a tela do terminal
}

int main() {

	int uc, segundoEnd, valorGer, valorConsumido, dia, mes, ano, diaV, mesV, anoV;

	char nome [200], endereco[200], segEndereco[200], pessoa[15], bandeira[20], geracaoPropria[20], outro[10];

	float valorFinal;
	
	limpaTela();
	//Lampada
    printf("\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⢶⣷⣄⠀⠀⠀⠀⠀⠀⠀⠻⠟⠀⠀⠀⠀⠀⠀⠀⣠⣾⡶⠀⠀⠀⠀     ⢰⣶⣶⣶⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⣶⠀⠀⠀⠀⠀⠀⠀⠀⣴⡷⠀⠀⠀⠀⠀⠀⢿⣦⠀⠀⣶\n⠀⠀⠀⠀⠀⠙⢿⣷⡄⠀⠀⠀⣀⣠⣤⣤⣄⣀⠀⠀⠀⢠⣾⡿⠋⠀⠀⠀⠀⠀     ⢸⣿⠀⠀⢻⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⣿     \n⠀⠀⠀⠀⠀⠀⠀⠉⠀⣠⣶⣿⣿⣿⣿⣿⣿⣿⣿⣶⣄⠀⠉⠀⠀⠀⠀⠀⠀⠀     ⢸⣿⠀⠀⣾⠇⠀⣰⣿⠿⣷⠀⠀⣿⡴⠛⣿⡴⠛⣿⡄⠀⠀⠀⠀⠀⣿⠀⠀⣿⠁⣿⣿⠀⣿⣧⠾⣿⣆⠀⣰⣿⠿⣿⣿⠀⣠⣿⠿⣷⡀⠀⣿⡇⠀⠀⣶⡿⢿⣷⠀⠀⢸⣿⠀⣿\n⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⠟⠛⠉⠙⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀     ⢸⣿⠿⠿⣷⡄⠀⣿⡇⠀⣿⡇⠀⣿⠀⠀⣿⡇⠀⣿⡇⠀⠀⠀⠀⠀⣿⡇⢠⣿⠀⣿⣿⠀⣿⡇⠀⣿⣿⠀⣿⡇⠀⣿⣿⠀⣿⡇⠀⣿⡇⠀⣿⡇⠀⠀⠛⠀⠀⣿⠀⠀⢸⣿⠀⣿     \n⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⣿⠁⢀⣴⣶⣾⣿⣿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀     ⢸⣿⠀⠀⢸⣿⠀⣿⡟⠛⠛⠃⠀⣿⠀⠀⣿⡇⠀⣿⡇⠀⠿⠿⠟⠀⢸⣿⢸⡟⠀⣿⣿⠀⣿⡇⠀⣿⣿⠀⣿⡇⠀⣿⣿⠀⣿⡇⠀⣿⡇⠀⣿⡇⠀⠀⣠⡿⠛⣿⠀⠀⢸⣿⠀⣿     \n⢾⣿⣿⣿⣿⠆⠀⣿⣿⣿⣷⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠰⣿⣿⣿⣿⡷     ⢸⣿⠀⠀⣸⣿⠀⣿⡇⠀⣿⡇⠀⣿⠀⠀⣿⡇⠀⣿⡇⠀⠀⠀⠀⠀⠀⣿⣿⠃⠀⣿⣿⠀⣿⡇⠀⣿⣿⠀⣿⣇⠀⣿⣿⠀⣿⡇⠀⣿⡇⠀⣿⡇⠀⠀⣿⠀⢀⣿⠀⠀⢸⣿⠀⠉     \n⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠀⠀⠀⠀⠀⠀⠀     ⠸⠿⠿⠿⠛⠀⠀⠈⠿⠿⠟⠀⠀⠿⠀⠀⠿⠇⠀⠿⠇⠀⠀⠀⠀⠀⠀⠿⠿⠀⠀⠿⠿⠀⠿⠇⠀⠿⠿⠀⠘⠿⠿⠿⠿⠀⠈⠿⠿⠟⠀⠀⢻⣇⠀⠀⠻⠿⠋⠿⠀⠀⣼⡏⠀⠿     \n⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀      ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣄⠀⠀⠀⠀⠀⠀⣠⣿⠁⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀      Desenvolvido por Rian Carlos Valcanaia⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠀⠀⠀⠀⠀⠀⠉⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠉⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀      Aperte enter para entrar no programa.\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣶⣶⣶⣶⣶⣶⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\n");
	getchar();
	
	while(1){
		limpaTela();
	
		//ENTRADA DE DADOS:
		printf("Nome do cliente: ");
		scanf("\n%[^\n]s", nome);
	
		printf("Digite o numero da unidade consumidora: ");
		scanf("%i", &uc); 
	
		//FISICA OU JURIDICA
		while (1) {
       			printf("Pessoa física ou jurídica (fisica/juridica): ");
    			scanf("\n%s", pessoa);

    			if (strcmp(pessoa, "fisica") == 0 || strcmp(pessoa, "juridica") == 0) {
    				break;
        		} else {
        			printf("Escolha inválida. Tente novamente.\n");
        		}
    		}
		
		//GERAÇÃO PRÓPRIA
		while(1){
			printf("Geração própria (sim/nao): ");
			scanf("%s", geracaoPropria);
		
			if (strcmp(geracaoPropria, "sim") == 0 || strcmp(geracaoPropria, "nao") == 0){
				break;
			} else {
				printf("Escolha inválida. Tente novamente.\n");
			}
		}		

		if (strcmp(geracaoPropria, "nao") == 0){
			valorGer = 0;
		}
		
		// ENDEREÇO
	
 		printf("Digite o endereço: ");
 		scanf("\n%[^\n]s", endereco);
	
 		if ((strcmp(pessoa, "fisica") == 0) && (strcmp(geracaoPropria, "sim") == 0)){
 			printf("Digite o segundo endereço: ");
 			scanf("\n%[^\n]s" , segEndereco);
 		}

		//VALOR CONSUMIDO

		printf("Digite o valor consumido (em kwh): ");
 		scanf("%i", &valorConsumido);
		
		//VALOR GERADO
 		if (strcmp(geracaoPropria, "sim") == 0){
 	 		printf("Digite o valor gerado (em kwh): ");
 	 		scanf("%i", &valorGer);
		}

		//DATA
		printf("Digite a data da leitura (dd/mm/aaaa): ");
 		scanf("%i/%i/%i", &dia, &mes, &ano);

   		//BANDEIRA
  		while(1){
			printf("Digite a bandeira (VERDE/AMARELA/VERMELHA 1/VERMELHA2): ");
      			scanf("\n%[^\n]s", bandeira);
		
			if ((strcmp(bandeira, "VERDE") == 0) || (strcmp(bandeira, "AMARELA") == 0) || (strcmp(bandeira, "VERMELHA 1") == 0) || (strcmp(bandeira, "VERMELHA 2") == 0)){
				break;
			}else {
				printf("Escolha inválida. Tente novamente.\n");
			}
  		}
 	
   		//VALOR FINAL
		if (valorConsumido > valorGer){
			if(strcmp(bandeira, "verde") == 0) {
				valorFinal = ((float)(valorConsumido - valorGer) * 0.45);
			}else if(strcmp(bandeira, "amarela") == 0){
				valorFinal = ((float)(valorConsumido - valorGer)/(float)100) * 1.5 + (float)(valorConsumido - valorGer) * 0.45;
			}else if (strcmp(bandeira, "vermelha 1") == 0){
				valorFinal = ((float)(valorConsumido - valorGer)/(float)100) * 3.0 + (float)(valorConsumido - valorGer) * 0.45;
			}else if(strcmp(bandeira, "vermelha 2") == 0){
				valorFinal = ((float)(valorConsumido - valorGer)/(float)100) * 4.5 + (float)(valorConsumido - valorGer) * 0.45;
			}
		} else { 
			valorFinal = 0.00;
		}

   		//VENCIMENTO
   		if (mes == 1 && dia == 29){
   			mesV = 2;
   			diaV = 28;
			anoV = ano;
   		} else if(mes == 12){
   			anoV = ano + 1;
   			mesV = 1;
			diaV = dia;
   		}else {
   			mesV = mes + 1;
			diaV = dia;
			anoV = ano;
   		}

		limpaTela();

   		//SAIDA
		printf("----------------------------");
   		printf("\nNome: %s.\n", nome);
		printf("UC: %i.\n" , uc);
	
		if (strcmp(pessoa, "fisica") == 0){
			printf ("Pessoa: Física.\n");
		} else if(strcmp(pessoa, "juridica") == 0){
			printf("Pessoa: Juridica.\n");
		}

		if (strcmp(geracaoPropria, "sim")){
			printf("Geração própria: sim.\n");
		} else {
			printf("Geração própria: nao.\n");
		}

		printf("Endereço: %s.\n", endereco);
		printf("Data da coleta: %i/%i/%i\n", dia, mes, ano);

 		if ((strcmp (geracaoPropria, "sim") == 0) && valorConsumido < valorGer){
  			printf("Valor da Fatura: R$ %.2f.\n", valorFinal);
  			printf("Saldo de energia transferido para segundo endereço.\n");
  		}else {
  			printf("Valor da Fatura: R$ %.2f.\n", valorFinal);
  		}
	
   		if (strcmp(bandeira, "VERDE") == 0){
			printf("Bandeira: VERDE.\n");
		} else if(strcmp(bandeira, "AMARELA") == 0){
			printf("Bandeira: AMARELA.\n");
		} else if(strcmp(bandeira, "VERMELHA 1") == 0){
			printf("Bandeira: VERMELHA 1.\n");
		}else if(strcmp(bandeira, "VERMELHA 2") == 0){
			printf("Bandeira: VERMELHA 2.\n");
		}

		printf("Vencimento: %02i/%02i/%i\n", diaV, mesV, anoV);

		//OUTRO CLIENTE
		while(1){
			printf("----------------------------");
			printf("\nOutro cliente? (sim/nao): ");
			scanf("%s", outro);

			if (strcmp (outro, "sim") == 0 || strcmp(outro, "nao") == 0){
				break;
			}else {
				printf("Escolha inválida. Tente novamente.\n");
			}
		}
	
		if (strcmp(outro, "nao") == 0){
			break;
		}

	}
	return 0;
}
