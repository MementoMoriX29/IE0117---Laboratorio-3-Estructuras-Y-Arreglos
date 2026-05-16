#include <stdio.h>

int potencia (int base, int exp) {
    int resultado = 1;
    while (exp > 0) {
       resultado = resultado * base;
       exp = exp - 1;
    }
    return resultado; 
}

int es_par(int n) {
    if (n %2 == 0) {
       return 1;
    } 
    return 0;
}

int main(void) {
    int base, exponente, resultado;

    do {
       printf("Por favor, ingrese la base: ");
       scanf("%d", &base);
       printf("Por favor, ingrese el exponente: ");
       scanf("%d", &exponente);

       //Validar
       if (base == 0 || exponente < 0) {
           printf("Por favor, verifique que la base sea distinta de 0 y que el exponente no sea negativo");
       }
       } while (base == 0 || exponente < 0);

    
   resultado = potencia(base, exponente);
   printf("\nResultado: %d\n", resultado);

   if (es_par(resultado)) {
      printf("El resultado es par\n");
   }else{
      printf("El resultado es impar\n");
   }
   return 0;
}

