#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../type/ticket.h"
#include "../type/utils.h"

int main(void) {

    Ticket *ticket = crear_ticket();
    if (ticket == NULL) {
        return EXIT_FAILURE;
    }

    char *entrada_id = NULL;

    do {
        entrada_id = leer_cadena("Ingrese su identificacion: ");
        if (entrada_id == NULL || !es_numero(entrada_id)) {
            printf("Error: La identificacion debe ser numerica.\n");
            free(entrada_id);
            entrada_id = NULL;
        }
    } while (entrada_id == NULL);

    ticket->identificacion = (long) atol(entrada_id);
    free(entrada_id);

    do {
        ticket->correo = leer_cadena("Ingrese su correo: ");
        if (ticket->correo == NULL || !validar_correo(ticket->correo)) {
            printf("Error: Correo invalido.\n");
            free(ticket->correo);
            ticket->correo = NULL;
        }
    } while (ticket->correo == NULL);

    do {
        ticket->tipo_reclamacion = leer_cadena("Ingrese tipo de reclamacion: ");
        if (ticket->tipo_reclamacion == NULL) {
            printf("Error: El campo no puede estar vacio.\n");
        }
    } while (ticket->tipo_reclamacion == NULL);

    generar_radicado(ticket);

    if (!guardar_ticket(ticket)) {
        liberar_ticket(ticket);
        return EXIT_FAILURE;
    }

    printf("\nTicket registrado exitosamente.\n");
    printf("Numero de radicado: %ld\n", ticket->radicado);

    liberar_ticket(ticket);

    return EXIT_SUCCESS;
}