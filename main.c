#include <stdio.h>
#include <string.h>

void cripto(char *fra);
void decripto(char *fra);

main (){
    char frase[100], opcao;
    int a;
    do{
    printf("Digite a opção - c criptografar, d - decriptografar, s - sair:");
    scanf("%c", &opcao);
    getchar();
    switch (opcao){
    case 'c': {
        printf("Digite a frase:");
        gets(frase);
        cripto(frase);
        printf("Frase criptografada: %s \n",frase);
    }
    break;
    case 'd': {
        printf("Digite a frase:");
        gets(frase);
        decripto(frase);
        printf("Frase decriptografada: %s \n",frase);
    }
    break;
    case 's': printf("fim");
    break;
    default:  printf("Opção inválida");
    }
    }while (opcao !='s');
}

void cripto(char *fra){
  int x, aux, menos, tam;
  tam = strlen(fra);
  for(x = 0; x < tam; x++){
    aux = (int) *(fra + x);
    aux = aux + 6;
    if(aux >= 119){
      aux++;
    }
    if(aux > 122){
      menos = aux - 122;
      aux = 96 + menos;
    }
    *(fra + x) = (char) aux;
  }
}

void decripto(char *fra){
  int x, aux, menos, tam;
  tam = strlen(fra);
  for(x = 0; x < tam; x++){
    aux = (int) *(fra + x);
    if(aux >= 119){
      aux = aux - 1;
    }
    if(aux <= 99){
      aux = aux - 1;
    }
    aux = aux - 6;
    if(aux < 97){
      menos = 96 - aux;
      aux = 122 - menos;
    }
    *(fra + x) = (char) aux;
  }
}
