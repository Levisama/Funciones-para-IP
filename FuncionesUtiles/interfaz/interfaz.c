
//FUNCION PARA INICIALIZAR LOS DATOS DE FORMA AUTOMATICA
void inicializarDatos(Provincia provincias[], int *cant) {
    *cant = 4; // ejemplo con 4 provincias

    strcpy(provincias[0].nombre, "La Habana");
    provincias[0].vacunadosAnterior = 1000;
    provincias[0].vacunadosActual = 1200;
    provincias[0].cantAlergicos = 2;
    strcpy(provincias[0].alergicos[0].id, "20151234567");
    provincias[0].alergicos[0].anioNacimiento = 2015;
    strcpy(provincias[0].alergicos[1].id, "20161234567");
    provincias[0].alergicos[1].anioNacimiento = 2016;

    strcpy(provincias[1].nombre, "Santiago de Cuba");
    provincias[1].vacunadosAnterior = 800;
    provincias[1].vacunadosActual = 750;
    provincias[1].cantAlergicos = 1;
    strcpy(provincias[1].alergicos[0].id, "20141234567");
    provincias[1].alergicos[0].anioNacimiento = 2014;

    strcpy(provincias[2].nombre, "Villa Clara");
    provincias[2].vacunadosAnterior = 600;
    provincias[2].vacunadosActual = 900;
    provincias[2].cantAlergicos = 0;


    strcpy(provincias[3].nombre, "Cienfuegos");
    provincias[3].vacunadosAnterior = 500;
    provincias[3].vacunadosActual = 700;
    provincias[3].cantAlergicos = 1;
    strcpy(provincias[3].alergicos[0].id, "20151234568");
    provincias[3].alergicos[0].anioNacimiento = 2015;

}







//FUNCION PARA ENTRDA MANUAL (PENDIENTE MENU DE SELECCION DE PROVINCIA Y VALIDACION DE CI)
void entradaManual(Provincia provincias[], int *cant) {

    printf("Ingrese cantidad de provincias: ");
    scanf("%d", cant);
    int i,j;
    for(i=0; i<*cant; i++) {
        printf("\nProvincia %d:\n", i+1);

        printf("Nombre: ");
        scanf("%s", provincias[i].nombre);

        printf("Vacunados campa\244a anterior: ");
        scanf("%d", &provincias[i].vacunadosAnterior);

        printf("Vacunados campa\244a actual: ");
        scanf("%d", &provincias[i].vacunadosActual);

        printf("Cantidad de ni\244os al\202rgicos: ");
        scanf("%d", &provincias[i].cantAlergicos);


        for(j=0; j<provincias[i].cantAlergicos; j++) {

            printf(" - ID ni\244o %d: ", j+1);
            scanf("%s", provincias[i].alergicos[j].id);

            printf(" A\244o de nacimiento: ");
            scanf("%d", &provincias[i].alergicos[j].anioNacimiento); }
    }
}





//FUNCION PARA MOSTRAT DATOS
void mostrarDatos(Provincia provincias[], int cant) {
    int i,j;
    for(i=0; i<cant; i++) {

        printf("\nProvincia: %s\n", provincias[i].nombre);
        printf("Vacunados anterior: %d\n", provincias[i].vacunadosAnterior);
        printf("Vacunados actual: %d\n", provincias[i].vacunadosActual);
        printf("Ni\244os al\202rgicos: %d\n", provincias[i].cantAlergicos);
        for(j=0; j<provincias[i].cantAlergicos; j++) {
            printf(" - ID: %s (Nacido %d)\n", provincias[i].alergicos[j].id, provincias[i].alergicos[j].anioNacimiento);
        }
    }
}









//REPORTE Q DICE LAS PROVINCIAS CON NIÑOS ALERGICOS
void reporteAlergicos(Provincia provincias[], int cant) {
    int i ,j;
    printf("\n--- REPORTE DE PROVINCIAS CON NI\245OS ALÉRGICOS ---\n");
    for(i=0; i<cant; i++) {
        printf("\nProvincia: %s\n", provincias[i].nombre);
        printf("Vacunados anterior: %d\n", provincias[i].vacunadosAnterior);
        printf("Vacunados actual: %d\n", provincias[i].vacunadosActual);
        printf("Cantidad de ni\245os alérgicos: %d\n", provincias[i].cantAlergicos);
        for(j=0; j<provincias[i].cantAlergicos; j++) {
            printf(" - ID: %s (Nacido %d)\n",
                   provincias[i].alergicos[j].id,
                   provincias[i].alergicos[j].anioNacimiento);
        }
    }
}






//REPORTE Q DICE LAS PROVINCIAS Q SUPERAN CAMPAÑA ANTERIOR
void reporteSuperanAnterior(Provincia provincias[], int cant) {
    int i;
    for(i=0; i<cant; i++) {
        if(provincias[i].vacunadosActual > provincias[i].vacunadosAnterior) {
            printf("Provincia %s supera la campa\244a anterior.\n", provincias[i].nombre);
        }
    }
}




//REPORTE Q DICE LA PROVINCIA CON MAS NIÑOS VACUNADOS
void provinciaMasVacunados(Provincia provincias[], int cant) {
    int max = provincias[0].vacunadosActual;
    int i;
    char nombre[30];
    strcpy(nombre, provincias[0].nombre);

    for(i=1; i<cant; i++) {
        if(provincias[i].vacunadosActual > max) {
            max = provincias[i].vacunadosActual;
            strcpy(nombre, provincias[i].nombre);
        }
    }
    printf("\nLa provincia con más vacunados es %s (%d ni\245os).\n", nombre, max);
}




//REPORTE Q DADA UNA PROVINCIA <DIC SI TIENE AL MENOS UN NIÑO ALERGICO NACIDO EN 2015
void tieneAlergico2015(Provincia provincias[], int cant, char nombreProv[]) {
    int i,j;
    for(i=0; i<cant; i++) {
        if(strcmp(provincias[i].nombre, nombreProv) == 0) {
            for(j=0; j<provincias[i].cantAlergicos; j++) {
                if(provincias[i].alergicos[j].anioNacimiento == 2015) {
                    printf("\nLa provincia %s tiene al menos un ni\245o alérgico nacido en 2015.\n", nombreProv);
                    return;
                }
            }
            printf("\nLa provincia %s NO tiene ni\245os alérgicos nacidos en 2015.\n", nombreProv);
            return;
        }
    }
    printf("\nProvincia no encontrada.\n");
}
