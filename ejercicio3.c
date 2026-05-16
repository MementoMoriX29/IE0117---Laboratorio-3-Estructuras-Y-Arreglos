#include <stdio.h>
#include <math.h>
#define MAX_SENSORES 10

typedef enum { NORMAL, ALERTA, FALLO } EstadoSensor;

typedef struct {
    int id;
    float valor;
    EstadoSensor estado;
} Lectura;

EstadoSensor clasificar(float valor);
int contar_estado(Lectura s[], int n, EstadoSensor e);
int lectura_extrema(Lectura s[], int n);

/* Clasifica un valor segun los umbrales definidos */
EstadoSensor clasificar(float valor) {
    if (valor >= 40.0f && valor <= 60.0f)
        return NORMAL;
    else if ((valor >= 20.0f && valor < 40.0f) || (valor > 60.0f && valor <= 80.0f))
        return ALERTA;
    else
        return FALLO;
}

/* Retorna la cantidad de lectura */
int contar_estado(Lectura s[], int n, EstadoSensor e) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (s[i].estado == e) count++;
    return count;
}

int lectura_extrema(Lectura s[], int n) {
    int idx = 0;
    float max_dist = fabsf(s[0].valor - 50.0f);
    for (int i = 1; i < n; i++) {
        float dist = fabsf(s[i].valor - 50.0f);
        if (dist > max_dist) {
            max_dist = dist;
            idx = i;
        }
    }
    return idx;
}

/* Convierte EstadoSensor a string */
const char *estado_str(EstadoSensor e) {
    switch (e) {
        case NORMAL: return "NORMAL";
        case ALERTA: return "ALERTA";
        case FALLO:  return "FALLO";
        default:     return "?";
    }
}

int main(void) {
    Lectura sensores[MAX_SENSORES];

    /* Ingreso de lecturas */
    for (int i = 0; i < MAX_SENSORES; i++) {
        printf("Sensor %d - Ingrese id y valor: ", i + 1);
        scanf("%d %f", &sensores[i].id, &sensores[i].valor);
        sensores[i].estado = clasificar(sensores[i].valor);
    }

    /* Tabla de resultados */
    printf("\n%-10s %-10s %-10s\n", "ID", "Valor", "Estado");
    printf("------------------------------\n");
    for (int i = 0; i < MAX_SENSORES; i++)
        printf("%-10d %-10.2f %-10s\n",
               sensores[i].id, sensores[i].valor, estado_str(sensores[i].estado));

    /* Conteo por estado */
    printf("\nConteo de estados:\n");
    printf("  NORMAL: %d\n", contar_estado(sensores, MAX_SENSORES, NORMAL));
    printf("  ALERTA: %d\n", contar_estado(sensores, MAX_SENSORES, ALERTA));
    printf("  FALLO:  %d\n", contar_estado(sensores, MAX_SENSORES, FALLO));

    /* Lectura extrema */
    int idx = lectura_extrema(sensores, MAX_SENSORES);
    printf("\nLectura mas extrema:\n");
    printf("  ID: %d  Valor: %.2f  Estado: %s\n",
           sensores[idx].id, sensores[idx].valor, estado_str(sensores[idx].estado));

    return 0;
}


