#include <stdio.h>
#include <string.h>
#include <atmi.h>
#include <fml32.h>
#include "biblioBD.fml.h"

typedef struct streaming{
    int  idDir;
    char nombreDir[20];
    char nacionalidad[20];
    char estudioDir[20];
}streaming;

int main(int argc, char **argv)
{
    int ivL_resLlamd;
    long ivL_tamLongt;
    float fvL_recValor;
    FBFR32 *fbfr;
    FBFR32 *recv;
    FLDLEN32 flen;
    char msgbuf[64];

    streaming str;

    printf("\n*************************************************\n");
    printf("id del director :"); scanf("%d", &str.idDir);
    printf("Nombre          :"); scanf("%s", str.nombreDir);
    printf("Nacionalidad    :"); scanf("%s", str.nacionalidad);
    printf("Estudio         :"); scanf("%s", str.estudioDir);

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
    if(Fadd32 (fbfr, IDDIR, (char *)&str.idDir, 0) < 0){
        printf ("\n\tError insertando campo FML (idDir)");
        tpfree((char*)fbfr);
        tpterm();
        return (0);
    }

    if(Fadd32 (fbfr, NOMBREDIR, str.nombreDir, 0) < 0){
        printf ("\n\tError insertando campo FML (nombreDir)");
        tpfree((char*)fbfr);
        tpterm();
        return (0);
    }

    if(Fadd32 (fbfr, NACIONALIDAD, str.nacionalidad, 0) < 0){
        printf ("\n\tError insertando campo FML (nacionalidad)");
        tpfree((char*)fbfr);
        tpterm();
        return (0);
    }

    if(Fadd32 (fbfr, ESTUDIODIR, str.estudioDir, 0) < 0){
        printf ("\n\tError insertando campo FML (estudioDir)");
        tpfree((char*)fbfr);
        tpterm();
        return (0);
    }

    //Invocamos al servicio    
    printf("Llamada al servicio 'insert_Negocio_FML'\n");
    if(tpcall("insert_Negocio_FML", (char *)fbfr, 0, (char **)&recv, &ivL_tamLongt, 0L) == -1){
        printf("\n Error en la llamada al servicio: tperrno = %d\n", tperrno);
        tpfree((char *)fbfr);
        tpfree((char *)recv);
        tpterm();
        return (1);
    }

    flen = sizeof(msgbuf);
    Fget32(recv, OUTPUT, 0, (char *)msgbuf, &flen);
    printf("Respuesta del servidor: %s\n", msgbuf);

    // Liberamos el buffer y desconectamos de la aplicacion
    printf("Liberamos Buffer y desconectamos de la aplicacion\n");
    tpfree((char *)fbfr);
    tpfree((char *)recv);
    tpterm();
    return 0;
}




