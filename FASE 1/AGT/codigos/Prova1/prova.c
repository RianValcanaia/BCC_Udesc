#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

void limpaTela(){
	system("cls");
	system("clear");
}

int main() {

	int uc, segundoEnd, valorGer, valorConsumido, dia, mes, ano, diaV, mesV, anoV;

	char nome [200], endereco[200], segEndereco[200], pessoa[15], bandeira[20], geracaoPropria[20], outro[10];

	float valorFinal;
	
	limpaTela();
	//Lampada
    printf("\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⢶⣷⣄⠀⠀⠀⠀⠀⠀⠀⠻⠟⠀⠀⠀⠀⠀⠀⠀⣠⣾⡶⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠙⢿⣷⡄⠀⠀⠀⣀⣠⣤⣤⣄⣀⠀⠀⠀⢠⣾⡿⠋⠀⠀⠀⠀⠀     ⣾⣿⣿⣿⣷⣤⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⠻⠟⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⣿⡇⡀⡀⡀⡀⡀⡀⡀⡀\n⠀⠀⠀⠀⠀⠀⠀⠉⠀⣠⣶⣿⣿⣿⣿⣿⣿⣿⣿⣶⣄⠀⠉⠀⠀⠀⠀⠀⠀⠀     ⣿⣿⡀⡀⡀⣿⠇⡀⡀⢀⣀⣀⡀⡀⡀⢀⡀⢀⣀⡀⡀⣀⣀⡀⡀⡀⡀⡀⡀⢀⡀⡀⡀⡀⣀⡀⡀⢀⡀⡀⡀⢀⡀⢀⣀⣀⡀⡀⡀⡀⣀⣀⡀⣿⡇⡀⡀⡀⣀⣀⣀⡀⡀\n⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⠟⠛⠉⠙⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀     ⣿⣿⣤⣶⣾⠋⡀⡀⣾⡟⠉⠙⣿⡀⡀⣿⡿⠉⠻⣿⠟⠉⢿⣧⡀⡀⡀⡀⡀⢻⣷⡀⡀⢠⣿⡀⡀⣿⣿⡀⡀⣿⣿⠋⠉⢻⣷⡀⢀⣿⠟⠉⠛⣿⡇⡀⢀⣿⠟⠉⠙⣿⡄\n⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⣿⠁⢀⣴⣶⣾⣿⣿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀     ⣿⣿⡀⡀⠉⣿⣆⡀⣿⣤⣤⣤⣿⡇⡀⣿⡇⡀⡀⣿⡀⡀⢸⣿⡀⡀⡀⡀⡀⡀⣿⡄⡀⣿⠇⡀⡀⣿⣿⡀⡀⣿⡇⡀⡀⢸⣿⡀⢸⣿⡀⡀⡀⣿⡇⡀⣾⣿⡀⡀⡀⢹⣿\n⢾⣿⣿⣿⣿⠆⠀⣿⣿⣿⣷⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠰⣿⣿⣿⣿⡷     ⣿⣿⡀⡀⡀⣿⡿⡀⣿⡀⡀⡀⡀⡀⡀⣿⡇⡀⡀⣿⡀⡀⢸⣿⡀⡀⡀⡀⡀⡀⢹⣷⢠⣿⡀⡀⡀⣿⣿⡀⡀⣿⡇⡀⡀⢸⣿⡀⠸⣿⡀⡀⡀⣿⡇⡀⢹⣿⡀⡀⡀⣾⡿\n⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠀⠀⠀⠀⠀⠀⠀     ⢿⣿⣿⣿⡿⠟⡀⡀⠙⠿⣶⣶⣶⡀⡀⢿⠇⡀⡀⣿⡀⡀⢸⡿⡀⡀⡀⡀⡀⡀⡀⢿⣾⠃⡀⡀⡀⢿⡿⡀⡀⢿⠇⡀⡀⠸⣿⡀⡀⠻⣿⣶⠿⢻⡇⡀⡀⠻⣿⣶⣾⠟⡀\n⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀     Desenvolvido por Rian Carlos Valcanaia.\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠉⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀     Aperte enter para entrar no programa!\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣶⣶⣶⣶⣶⣶⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n\n");
    
	getchar();
	
	while(1){
	limpaTela();
	//entrada de dados
	printf("Nome do cliente: ");
	scanf("\n%[^\n]s", nome);
	
	//ester eggs
	if(strcmp(nome, "Karl Marx") == 0){
		printf(" ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⡿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n ⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⠛⡺⣺⣪⣽⣫⣳⡼⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n ⣿⣿⣿⣿⣿⣿⣿⣿⠋⢻⣰⣿⣿⣿⣿⣿⣿⣿⣷⣟⢾⣽⣿⣿⣿⣿⣿⣿⣿⣿\n ⣿⣿⣿⣿⣿⣿⡩⠱⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⠎⢻⡿⣿⣿⣿⣿⣿⣿⣿\n ⣿⣿⣿⣿⡿⣭⠂⠀⠀⢸⣿⣿⣿⣿⣿⢿⣿⣿⣿⠛⠕⡯⢒⠾⣿⢿⣿⣿⣿⣿\n ⣿⣿⣿⣿⡂⠀⣎⠇⠀⠡⠀⠉⠉⣏⠀⠐⠒⠽⣻⣿⠄⡡⡴⢕⡈⠉⡏⣿⣿⣿\n ⣿⣿⣿⡟⡄⠀⡨⠑⠀⢠⣤⣴⢼⣿⣿⣿⣿⣿⣿⣗⠄⠀⠀⡈⠐⠲⠀⠹⣿⣿\n ⣿⣿⣿⡠⠀⠂⠀⡤⠀⢸⢿⡇⠙⠛⠛⣿⢿⣿⣿⡇⠠⠎⠀⠀⠀⠠⠕⢩⣿⣿\n ⣿⣿⣿⡦⠀⠀⠀⡅⠀⠀⠗⠐⠑⠈⠁⠑⠡⠉⠋⠘⢁⣒⠀⠀⠀⢀⣴⣿⣿⣿\n ⣿⣿⣿⣿⣷⡄⡀⠀⡉⠐⡀⠀⠀⣀⣀⣀⢀⠄⡀⢀⡧⣵⣠⠀⣤⣿⣿⣿⣿⣿\n ⣿⣿⣿⣿⣿⡬⠁⠀⠁⠀⠀⠀⠥⢌⡅⢓⣼⠠⡃⡘⣹⣿⢾⣸⣟⡏⠸⢻⢻⣿\n ⣿⣿⣿⣿⣿⣿⣅⢠⠼⢃⠠⢤⠶⠄⠵⢝⣻⢗⣮⣙⣿⠏⠐⠀⠈⠐⠉⠬⢛⣻\n ⣿⣿⣿⣯⣯⡿⠙⠀⠢⠠⠆⣊⣂⠐⢱⡜⣿⣩⡧⠗⠍⠀⠀⠀⠀⡀⢄⣀⣀⣾\n ⣿⣿⠟⠈⠂⠀⠀⠀⠀⠀⠀⠁⠥⠖⠫⠌⠐⠁⠁⠀⠀⢀⠀⠐⢀⡱⢶⣬⣿⣿\n ⣯⠡⠁⠀⠀⠀⠀⠀⢀⣡⠄⡀⠀⠀⠀⠂⠀⠀⡀⠀⠀⢂⢔⢹⣝⢿⣿⣶⣿⣿\n");
	} else if(strcmp(nome, "Shrek") == 0){
		printf("⢋⣴⠒⡝⣿⣿⣿⣿⣿⡿⢋⣥⣶⣿⣿⣿⣿⣿⣿⣶⣦⣍⠻⣿⣿⣿⣿⣿⣷⣿\n⢾⣿⣀⣿⡘⢿⣿⡿⠋⠄⠻⠛⠛⠛⠻⠿⣿⣿⣿⣿⣿⣿⣷⣌⠻⣿⣿⣿⣿⣿\n⠄⠄⠈⠙⢿⣦⣉⡁⠄⠄⣴⣶⣿⣿⢷⡶⣾⣿⣿⣿⣿⡛⠛⠻⠃⠙⢿⣿⣿⣿\n⠄⠄⠄⠄⠄⠈⠉⣀⣀⣴⡟⢩⠁⠩⣝⢂⢨⣿⣿⣿⣿⢟⡛⣳⣶⣤⡘⠿⢋⣡\n⠄⠄⠄⠄⠄⠄⠘⣿⣿⣿⣿⣾⣿⣶⣿⣿⣿⣿⣿⣿⣿⣆⣈⣱⣮⣿⣷⡾⠟⠋\n⠄⠄⠄⠄⠄⠄⠄⠈⠿⠛⠛⣻⣿⠉⠛⠋⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠸⣿\n⠄⠄⠄⠄⢀⡠⠄⢒⣤⣟⠿⣿⣿⣿⣷⣤⣤⣀⣀⣉⣉⣠⣽⣿⣟⠻⣿⣿⡆⢻\n⠄⣀⠄⠄⠄⠄⠈⠋⠉⣿⣿⣶⣿⣟⣛⡿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣼⣿⡇⣸\n⣿⠃⠄⠄⠄⠄⠄⠄⠠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣾⣿⣿⣿⣿⣿⣿⠁⢿\n⡋⠄⠄⠄⠄⠄⠄⢰⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠄⠄\n⠋⠄⠄⠄⠄⠄⠄⠄⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠂⠠\n⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠙⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢿⣿⡿⠄⢈\n⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⠛⠛⠿⠿⠿⢿⣿⡿⠟⢋⣴⣿⢿⡋⠄⠄\n⣠⣴⠶⠖⠂⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣠⣴⣾⣿⡿⢫⠞⠄⠄⠄\n⣿⣿⣿⣿⣾⣆⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⣀⣤⣶⣿⣿⣿⢿⣧⣶⠏⠄\n\n");
	} else if(strcmp(nome, "Lula") == 0){
		printf(" ⣿⣿⡟⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⢿⣿⣿\n ⡟⠉⠄⠄⠄⠄⠄⢀⣤⣶⣦⣤⣶⣾⣷⣷⣄⡄⣄⡀⠄⠄⠄⠄⠄⠹⢿⣿\n ⡀⠄⠄⠄⠄⠄⢠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⠄⠄⠄⠄⠄⠄⠏\n ⡇⠄⠄⠄⠄⠄⢘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠄⠄⠄⠄⠄⠐\n ⠄⠄⠄⠄⠄⠄⢨⡿⠿⠻⠿⠿⢿⠿⣿⠿⠿⠟⠛⠛⠛⢿⡀⠄⠄⠄⠄⠄\n ⠄⠄⠄⠄⠄⢀⣰⡕⠲⠄⢀⠄⢸⣾⣿⣷⣂⢈⠄⢩⣛⣾⣿⡅⠄⠄⠄⠄\n ⣄⡀⠄⠄⠄⢸⣿⣿⣿⣧⣬⣭⣾⣿⣿⣿⣿⣮⣷⣿⣿⣿⣿⡇⠄⠄⠄⣼\n ⣿⣷⡄⠄⠄⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠄⠄⣠⣿\n ⣿⣿⣿⣊⠇⠄⢿⣿⣿⣿⣿⣿⣷⠦⠽⠵⣶⣿⣿⣿⣿⣿⡿⠄⠄⢰⣿⣿\n ⣿⣿⣿⣿⠄⠄⠈⢿⣿⣿⠟⠉⠁⠄⠄⠄⠄⠉⠙⠿⣿⣿⠁⠄⢠⣿⣿⣿\n ⣿⣿⣿⣿⣷⠄⠄⠄⠙⠁⠄⠄⠄⠄⢀⠄⠄⠄⠄⠄⠈⠄⠄⠄⠰⣿⣿⣿\n ⣿⣿⣿⣿⣷⠄⠄⠄⠄⠄⠄⠄⠈⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣿⣿⣿\n ⣿⣿⣿⡿⣿⡄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠠⡨⣕⣿⣿\n ⣿⣿⣻⣿⣷⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣾⣾⣿⣴⣯⣿\n\n");
	} else if(strcmp(nome, "URSS") == 0){
		printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣯⡙⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡀⠙⠿⣿⣿⣿⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠉⠉⠛⠛⠛⢛⣿⣿⣿⣦⠄⠈⢿⣿⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⡿⠋⠄⠄⠄⠄⠄⢀⣴⣿⣿⣿⣿⣿⣇⠄⠄⠹⣿⣿⣿⣿\n⣿⣿⣿⣿⡿⠋⠄⠄⠄⠄⠄⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⡇⠄⠄⠸⣿⣿⣿\n⣿⣿⣿⠋⠄⠄⠄⠄⠄⠄⠄⠄⠙⢻⣿⣿⣿⣿⣿⣿⣿⣿⠄⠄⠄⢻⣿⣿\n⣿⣿⣿⣷⣆⠄⠄⢀⣴⣿⣦⡀⠄⠄⠙⢿⣿⣿⣿⣿⣿⣿⠄⠄⠄⠘⣿⣿\n⣿⣿⣿⣿⣿⣿⣶⣿⣿⣿⣿⣿⣦⡀⠄⠄⠈⠻⣿⣿⣿⣿⠄⠄⠄⠄⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡀⠄⠄⠈⠻⡿⠃⠄⠄⠄⢰⣿⣿\n⣿⣿⣿⣿⣿⣿⡿⠛⠋⠛⢿⣿⣿⣿⣿⣿⣦⡀⠄⠄⠄⠄⠄⠄⢀⣿⣿⣿\n⣿⣿⣿⣿⣿⠋⠄⠄⣀⠄⠄⠈⠉⠛⠛⠛⠉⠉⠄⠄⠄⠄⠄⠠⢾⣿⣿⣿\n⣿⡿⠛⠋⠄⠄⣤⣾⣿⣷⣤⣀⠄⠄⠄⠄⠄⠄⠄⠄⢀⡀⠄⠄⠄⠛⢿⣿\n⠏⠄⠄⠄⠄⣾⣿⣿⣿⣿⣿⣿⣿⣶⣶⣶⣴⣶⣶⣾⣿⣷⣤⠄⠄⠄⠄⠙\n⠄⠄⢀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠄⠄⣠\n\n");
	} else if(strcmp(nome, "Katiau") == 0){
		printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⠿⠿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⣉⣁⣤⣤⣶⣾⣿⣿⣶⡄⢲⣯⢍⠁⠄⢀⢹⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⢯⣾⣿⣿⣏⣉⣹⠿⠇⠄⠽⠿⢷⡈⠿⠇⣀⣻⣿⡿⣻\n⣿⣿⡿⠿⠛⠛⠛⢛⡃⢉⢣⡤⠤⢄⡶⠂⠄⠐⣀⠄⠄⠄⠄⠄⡦⣿⡿⠛⡇⣼\n⡿⢫⣤⣦⠄⠂⠄⠄⠄⠄⠄⠄⠄⠄⠠⠺⠿⠙⠋⠄⠄⠄⠢⢄⠄⢿⠇⠂⠧⣿\n⠁⠄⠈⠁⠄⢀⣀⣀⣀⣀⣠⣤⡤⠴⠖⠒⠄⠄⠄⠄⠄⠄⠄⠄⠄⠘⢠⡞⠄⣸\n⡀⠄⠄⠄⠄⠄⠤⠭⠦⠤⠤⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣂⣿\n⣷⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢳⠄⠄⢀⠈⣠⣤⣤⣼⣿\n⣿⣿⣷⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣴⣶⣶⣶⣄⡀⠄⠈⠑⢙⣡⣴⣿⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n\n");	
	}

	printf("Digite a unidade consumidora: ");
	scanf("%i", &uc); 
	
	//ester eggs
	if (uc == 69){
		printf(";)\n");
	} else if(uc == 13){
	   	printf(" ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠉⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠄⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠄⠄⠄⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠄⠄⠄⠄⠄⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n ⣟⠛⠛⠛⠛⠛⠛⠛⠛⠛⠁⠄⠄⠄⠄⠄⠈⠛⠛⠛⠛⠛⠛⠛⠛⠛⣻\n ⣿⣿⣦⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣴⣿⣿\n ⣿⣿⣿⣿⣷⣦⣀⠄⠄⠄⡏⠉⢹⣷⠈⠉⣿⠉⠁⠄⣀⣴⣾⣿⣿⣿⣿\n ⣿⣿⣿⣿⣿⣿⣿⣷⠄⠄⡿⠿⠟⠋⠄⠄⣿⠄⠠⣾⣿⣿⣿⣿⣿⣿⣿\n ⣿⣿⣿⣿⣿⣿⣿⡟⠄⠄⠁⠄⠄⠄⠄⠄⠉⠄⠄⢹⣿⣿⣿⣿⣿⣿⣿\n ⣿⣿⣿⣿⣿⣿⡿⠁⠄⠄⠄⣠⣤⣶⣤⣄⠄⠄⠄⠈⢿⣿⣿⣿⣿⣿⣿\n ⣿⣿⣿⣿⣿⣿⠃⠄⢀⣠⣾⣿⣿⣿⣿⣿⣷⣄⡀⠄⠘⣿⣿⣿⣿⣿⣿\n ⣿⣿⣿⣿⣿⢏⣴⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣦⡹⣿⣿⣿⣿⣿\n");

	}

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
 	printf("Digite o endereço: ");
 	scanf("\n%[^\n]s", endereco);
	
 	if ((strcmp(pessoa, "fisica") == 0) && (strcmp(geracaoPropria, "sim") == 0)){
 		printf("Digite o segundo endereço: ");
 		scanf("\n%[^\n]s" , segEndereco);
 	}

	printf("Digite o valor consumido (em kwh): ");
 	scanf("%i", &valorConsumido);

 	if (strcmp(geracaoPropria, "sim") == 0){
 	 	printf("Digite o valor gerado (em kwh): ");
 	 	scanf("%i", &valorGer);
	}

	//data 
	printf("Digite a data da leitura (dd/mm/aaaa): ");
 	scanf("%i/%i/%i", &dia, &mes, &ano);

   	//bandeira
   while(1){
		printf("Digite a bandeira (verde/amarela/vermelha 1/vermelha 2): ");
      		scanf("\n%[^\n]s", bandeira);
		
		if ((strcmp(bandeira, "verde") == 0) || (strcmp(bandeira, "amarela") == 0) || (strcmp(bandeira, "vermelha 1") == 0) || (strcmp(bandeira, "vermelha 2") == 0)){
			break;
		}else {
			printf("Escolha inválida. Tente novamente.\n");
		}
   }
 	
   	//Valor Final
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

   	//Vencimento
	
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

   	//saida
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
	
   	if (strcmp(bandeira, "verde") == 0){
		printf("Bandeira: VERDE.\n");
	} else if(strcmp(bandeira, "amarela") == 0){
		printf("Bandeira: AMARELA.\n");
	} else if(strcmp(bandeira, "vermelha 1") == 0){
		printf("Bandeira: VERMELHA 1.\n");
	}else if(strcmp(bandeira, "vermelha 2") == 0){
		printf("Bandeira: VERMELHA 2.\n");
	}

	printf("Vencimento: %02i/%02i/%i\n", diaV, mesV, anoV);

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
//twitch spam
//patorjk
