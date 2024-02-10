#include <stdio.h>
#include <string.h>
#include <atmi.h>
#include <fml32.h>
#include "biblioBD.fml.h"

typedef struct streaming{
    int idPeli;
    char nombrePeli[20];
    char generoPeli[20];
    char directorPeli[20];
}streaming;

int main(int argc, char **argv)
{
    int ivL_resLlamd;
    int ivL_numOcurr;
    int ivL_iterador;
    long ivL_tamLongt;
    float fvL_recValor;
    FBFR32 *fbfr;
    FBFR32 *recv;
    FLDLEN32 flen;
    char msgbuf[64];
    char zaL_strnombrePeli[20];
    streaming *spL_strRegis;

    streaming str;

    printf("*************************************************\n");
    printf("Nombre de la pelicula: "); scanf("%s", zaL_strnombrePeli);
    printf("*************************************************\n");

    printf("Conectamos con la aplicación");
    if(tpinit((TPINIT *) NULL) == -1){
        printf("Error en la conexión, tperrno = %d \n", tperrno);
        return(1);
    }

    //Reservamos espacio para el buffer FML
    printf("Reservamos espacio para los buffers FML\n");
    if ((fbfr = (FBFR32 *) tpalloc("FML32", NULL, 1024)) == NULL){
        printf("Error reservando espacio para Buffer fbfrn");
        tpterm();
        return(1);
    }

    if ((recv = (FBFR32 *) tpalloc("FML32", NULL, 1024)) == NULL){
        printf("Error Reservando espacio para Buffer recv\n");
        tpterm();
        return(1);
    }

    /*Manejo del Buffer FML*/
    printf ("\nInsertamos datos en buffer FML.");
    if(Fadd32 (fbfr, NOMBREPELI, zaL_strnombrePeli, 0) < 0){
        printf ("\n\tError insertando campo FML (nombrePeli)");
        tpfree((char*)fbfr);
        tpterm();
        return (0);
    }

    printf("Nombre de la pelicula insertado en el buffer FML: %s\n", zaL_strnombrePeli);


    //Invocamos al servicio    
    printf("Llamada al servicio 'select_Negocio_FML'\n");
    if(tpcall("select_Negocio_FML", (char *)fbfr, 0, (char **)&recv, &ivL_tamLongt, 0L) == -1){
        printf("\n Error en la llamada al servicio: tperrno = %d\n", tperrno);
        tpfree((char *)fbfr);
        tpfree((char *)recv);
        tpterm();
        return (1);
    }

    if((ivL_numOcurr = Foccur32(recv, NOMBREPELI)) < 0)
    {
        printf("Error en Foccur32\n");
        tpfree((char *)fbfr);
        tpfree((char *)recv);
        tpterm();
        return (1); 
    }

    printf("Numero de ocurrencias: %d\n", ivL_numOcurr);
    spL_strRegis = (streaming *) malloc(sizeof(streaming) * ivL_numOcurr);

    flen = sizeof(msgbuf);
    printf("Respuesta del servidor para la pelicula: %s\n", zaL_strnombrePeli);
    for(ivL_iterador = 0;ivL_iterador < ivL_numOcurr; ivL_iterador++)
    {
        printf("Numero de registro: %d\n", (ivL_iterador + 1));

        Fget32(recv, IDPELI, ivL_iterador, (char *)&spL_strRegis[ivL_iterador].idPeli,0);
        printf("Id de la pelicula: %d\n", spL_strRegis[ivL_iterador].idPeli);
        
        Fget32(recv, NOMBREPELI, ivL_iterador, (char *)spL_strRegis[ivL_iterador].nombrePeli,0);
        printf("Nombre: %s\n", spL_strRegis[ivL_iterador].nombrePeli);
        
        Fget32(recv, GENEROPELI, ivL_iterador, (char *)spL_strRegis[ivL_iterador].generoPeli,0);
        printf("Genero: %s\n", spL_strRegis[ivL_iterador].generoPeli);

        Fget32(recv, DIRECTORPELI, ivL_iterador, (char *)spL_strRegis[ivL_iterador].directorPeli,0);
        printf("Director: %s\n", spL_strRegis[ivL_iterador].directorPeli);
        
    }

    // Liberamos el buffer y desconectamos de la aplicacion
    printf("Liberamos Buffer y desconectamos de la aplicacion\n");
    tpfree((char *)fbfr);
    tpfree((char *)recv);
    tpterm();
    return 0;
}

