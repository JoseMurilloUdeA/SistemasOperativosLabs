#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../types/utils.h"

#define BUFFER_SIZE 256

int es_numero(const char *str) {
    if (str == NULL || *str == '\0') return 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit((unsigned char)str[i])) {
            return 0;
        }
    }
    return 1;
}

int validar_correo(const char *correo) {
    if (correo == NULL) return 0;

    return strchr(correo, '@') != NULL;
}

void limpiar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

char* leer_cadena(const char *mensaje) {
    char buffer[BUFFER_SIZE];

    printf("%s", mensaje);

    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
        return NULL;
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    if (strlen(buffer) == 0) {
        return NULL;
    }

    char *cadena = (char*) malloc(strlen(buffer) + 1);
    if (cadena == NULL) {
        return NULL;
    }

    strcpy(cadena, buffer);
    return cadena;
}