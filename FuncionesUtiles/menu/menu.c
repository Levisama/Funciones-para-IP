#include <datos/datos.h>
#include <stdio.h>
#include <interfaz/interfaz.h>
#include <logica/logica.h>



//MENU PRICIPAL DE SELECCION DE LA APLICACION
void menu(Provincia provincias[], int cant) {
    int opcion;


    do {
        printf("\n=== CAMPA\245A DE VACUNACI\242N ANTIPOLIO ===\n");
        printf("1. Entrada manual de datos\n");
        printf("2. Inicializaci\242n autom\240tica con datos de prueba\n");
        printf("0. Salir\n"); printf("Seleccione una opci\242n: ");
        scanf("%d", &opcion);

        switch(opcion) {

        case 1:
            entradaManual(provincias, &cant);
            printf("\n--- Datos insertados manualmente ---\n");
            mostrarDatos(provincias, cant); menuReportes(provincias, cant);
            break;

        case 2:
            inicializarDatos(provincias, &cant);
            printf("\n--- Datos inicializados autom\240ticamente ---\n");
            mostrarDatos(provincias, cant);
            menuReportes(provincias, cant);
            break;
        case 0: printf("Saliendo del programa...\n");
            break;

        default: printf("Opci\242n inv\240lida. Intente de nuevo.\n");
        }

    } while(opcion != 0);
}





//MENU DE REPORTES
void menuReportes(Provincia provincias[], int cant) {
    int opcion,total;
    char nombreProv[30];

    do { printf("\n\n\n\n\n\n\n\n\n\n\n");

        printf("\n--- MENU DE REPORTES ---\n");
        printf("1. Total de ni\244os vacunados en esta campa\244a\n");
        printf("2. Reporte de provincias con ni\244os al\202rgicos\n");
        printf("3. Provincias que superan campa\244a anterior\n");
        printf("4. Provincia con m\240s vacunados\n");
        printf("5. Verificar si provincia tiene al\202rgico nacido en 2015\n");
        printf("0. Volver al menú principal\n");
        printf("Seleccione: ");
        scanf("%d", &opcion);

        switch(opcion) {
        case 1: {
           total=totalVacunados(provincias, cant);
            printf("Total vacunados: %d\n", total);
            break;
        }
        case 2:
            reporteAlergicos(provincias, cant);
            break;
        case 3:reporteSuperanAnterior (provincias,cant);
            break;
        case 4:
            provinciaMasVacunados(provincias, cant);
            break;
        case 5:
            printf("Ingrese nombre de la provincia: ");
            scanf("%s", nombreProv);
            tieneAlergico2015(provincias, cant, nombreProv);
            break;
        }
    } while(opcion != 0);
}
