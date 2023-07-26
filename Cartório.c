#include <stdio.h>  //biblioteca de comunica�ao com o usuario
#include <stdlib.h> //biblioteca de aloca�ao de espa�o em memoria 
#include <locale.h> //biblioteca de aloca�oes de texto por regi�o
#include <string.h> //biblioteca responsalvel por cuidar da string

int registro() //fun�ao responsavel por registrar os usuarios
{
	setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
	char arquivo [40]; //inicio da cria�ao de variaveis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];  //final da cria�ao de variaveis
	
	printf("Digite o cpf: "); //coletando as informa�oes do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por criar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo "w" para escrever uma informa�ao
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" � pra atualizar uma informa�ao
	fprintf(file, ","); //adiciona uma virgula ao arquivo
	fclose(file); //fecha arquivo
	
	printf("Digite o nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, nome);
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, ",");
	fclose(file); //fecha arquivo
	
	printf("Digite o sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, sobrenome);
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, ",");
	fclose(file); //fecha arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, cargo);
	fclose(file); //fecha arquivo
	
	system("pause");	
}

int consulta() // fun�ao responsavel por consultar os usuarios 
{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //abre o arquivo "r" � de "ler"
	
	
	if (file == NULL) //caso o usuario nao seja encontrado
	{
		printf("Esse cpf nao foi localizado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("\nEssas sao as informa�oes do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system ("pause");
	
}
int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usuario a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //caso o usuario nao seja encontrado
	{
		printf("O usuario nao se encontra no arquivo\n");
		system("pause");
	}
	
	if(file != NULL) //caso o usuario seja deletado
	{
		printf("O usuario foi deletado com sucesso!\n");
		system("pause");
	}
	
}

int main()
{
	
	int opcao=0; 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); //responsavel por limpar a tela 
	    
		setlocale(LC_ALL, "portuguese");
	
		printf("|---------Cart�rio da Ebac---------|\n\n"); //inicio do menu
		printf("|Escolha a op��o desejada no menu: |\n\n");
		printf("|\t1 - Registrar Nomes:       |\n");
		printf("|\t2 - Consultar  Nomes:      |\n");
		printf("|\t3 - Deletar  Nomes:        |\n");
		printf("|\t4 - Sair do menu           |\n");
		printf("|opc�o:                            |\n");
		printf("|----------------------------------|\n");
		
		scanf("%d", &opcao); // armazenando a escolha do usuario
	
		system("cls");
		
		switch (opcao) //inicio da sele�ao do menu
		{
			case 1:
			registro(); //chama a fun�ao registro
			break;
				
			case 2:
			consulta(); //chama a fun�ao consulta
			break;
				
			case 3:
			deletar(); //chama a fun�ao deletar
			break;
			
			case 4:
			printf("Obrigado por utilizar nosso sistema");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o esta disponivel\n");
			system("pause");
			break;	
						
		} //fim da sele�ao
	
    }
} 

