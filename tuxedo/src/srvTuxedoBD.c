
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[22];
};
static const struct sqlcxp sqlfpn =
{
    21,
    "../src/srvTuxedoBD.pc"
};


static unsigned int sqlctx = 105252667;


static struct sqlexd {
   unsigned long  sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
   unsigned char  **sqphsv;
   unsigned long  *sqphsl;
            int   *sqphss;
            short **sqpind;
            int   *sqpins;
   unsigned long  *sqparm;
   unsigned long  **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
            int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned int   sqlpfmem;
   unsigned char  *sqhstv[4];
   unsigned long  sqhstl[4];
            int   sqhsts[4];
            short *sqindv[4];
            int   sqinds[4];
   unsigned long  sqharm[4];
   unsigned long  *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {13,4};

/* SQLLIB Prototypes */
extern void sqlcxt (void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlcx2t(void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlbuft(void **, char *);
extern void sqlgs2t(void **, char *);
extern void sqlorat(void **, unsigned int *, void *);

/* Forms Interface */
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern void sqliem(unsigned char *, signed int *);

 static const char *sq0005 = 
"select idPeli ,nombrePeli ,generoPeli ,directorPeli  from Pelicula where nom\
brePeli=:b0           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,1,0,0,
5,0,0,0,0,0,27,60,0,0,4,4,0,2,9,66,82,65,78,68,79,78,68,66,1,97,0,0,1,97,0,0,1,
97,0,0,1,10,0,0,
45,0,0,2,0,0,30,70,0,0,0,0,0,2,9,66,82,65,78,68,79,78,68,66,
69,0,0,3,0,0,32,74,0,0,0,0,0,2,9,66,82,65,78,68,79,78,68,66,
93,0,0,4,89,0,3,139,0,0,4,4,0,2,9,66,82,65,78,68,79,78,68,66,1,3,0,0,1,97,0,0,
1,97,0,0,1,97,0,0,
133,0,0,5,98,0,9,207,0,0,1,1,0,2,9,66,82,65,78,68,79,78,68,66,1,97,0,0,
161,0,0,5,0,0,13,214,0,0,4,0,0,2,9,66,82,65,78,68,79,78,68,66,2,3,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,
201,0,0,5,0,0,13,227,0,0,4,0,0,2,9,66,82,65,78,68,79,78,68,66,2,3,0,0,2,97,0,0,
2,97,0,0,2,97,0,0,
241,0,0,5,0,0,15,231,0,0,0,0,0,2,9,66,82,65,78,68,79,78,68,66,
265,0,0,6,50,0,5,279,0,0,2,2,0,2,9,66,82,65,78,68,79,78,68,66,1,97,0,0,1,3,0,0,
297,0,0,7,38,0,2,335,0,0,1,1,0,2,9,66,82,65,78,68,79,78,68,66,1,3,0,0,
};


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <atmi.h>
#include <userlog.h>
#include <fml32.h>
#include <tx.h>
#include "biblioBD.fml.h"
#include <sqlca.h>
#include <sqlda.h>
#include <oraca.h>

/* EXEC SQL INCLUDE SQLCA;
 */ 
/*
 * $Header: sqlca.h 24-apr-2003.12:50:58 mkandarp Exp $ sqlca.h 
 */

/* Copyright (c) 1985, 2003, Oracle Corporation.  All rights reserved.  */
 
/*
NAME
  SQLCA : SQL Communications Area.
FUNCTION
  Contains no code. Oracle fills in the SQLCA with status info
  during the execution of a SQL stmt.
NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************

  If the symbol SQLCA_STORAGE_CLASS is defined, then the SQLCA
  will be defined to have this storage class. For example:
 
    #define SQLCA_STORAGE_CLASS extern
 
  will define the SQLCA as an extern.
 
  If the symbol SQLCA_INIT is defined, then the SQLCA will be
  statically initialized. Although this is not necessary in order
  to use the SQLCA, it is a good pgming practice not to have
  unitialized variables. However, some C compilers/OS's don't
  allow automatic variables to be init'd in this manner. Therefore,
  if you are INCLUDE'ing the SQLCA in a place where it would be
  an automatic AND your C compiler/OS doesn't allow this style
  of initialization, then SQLCA_INIT should be left undefined --
  all others can define SQLCA_INIT if they wish.

  If the symbol SQLCA_NONE is defined, then the SQLCA variable will
  not be defined at all.  The symbol SQLCA_NONE should not be defined
  in source modules that have embedded SQL.  However, source modules
  that have no embedded SQL, but need to manipulate a sqlca struct
  passed in as a parameter, can set the SQLCA_NONE symbol to avoid
  creation of an extraneous sqlca variable.
 
MODIFIED
    lvbcheng   07/31/98 -  long to int
    jbasu      12/12/94 -  Bug 217878: note this is an SOSD file
    losborne   08/11/92 -  No sqlca var if SQLCA_NONE macro set 
  Clare      12/06/84 - Ch SQLCA to not be an extern.
  Clare      10/21/85 - Add initialization.
  Bradbury   01/05/86 - Only initialize when SQLCA_INIT set
  Clare      06/12/86 - Add SQLCA_STORAGE_CLASS option.
*/
 
#ifndef SQLCA
#define SQLCA 1
 
struct   sqlca
         {
         /* ub1 */ char    sqlcaid[8];
         /* b4  */ int     sqlabc;
         /* b4  */ int     sqlcode;
         struct
           {
           /* ub2 */ unsigned short sqlerrml;
           /* ub1 */ char           sqlerrmc[70];
           } sqlerrm;
         /* ub1 */ char    sqlerrp[8];
         /* b4  */ int     sqlerrd[6];
         /* ub1 */ char    sqlwarn[8];
         /* ub1 */ char    sqlext[8];
         };

#ifndef SQLCA_NONE 
#ifdef   SQLCA_STORAGE_CLASS
SQLCA_STORAGE_CLASS struct sqlca sqlca
#else
         struct sqlca sqlca
#endif
 
#ifdef  SQLCA_INIT
         = {
         {'S', 'Q', 'L', 'C', 'A', ' ', ' ', ' '},
         sizeof(struct sqlca),
         0,
         { 0, {0}},
         {'N', 'O', 'T', ' ', 'S', 'E', 'T', ' '},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}
         }
#endif
         ;
#endif
 
#endif
 
/* end SQLCA */


/* EXEC SQL BEGIN DECLARE SECTION; */ 

/* EXEC SQL DECLARE BRANDONDB DATABASE; */ 

/* EXEC SQL END DECLARE SECTION; */ 


typedef struct paramConexion
{
   char usuario_DB[50];
   char password_DB[50];
   char name_DB[50];
}paramConexion;

char *ajustaCampos(char zaA_Campo[2000]);

int     ivG_errorCon = -1;
int     ivG_errorSel = -2;
int     ivG_salidaOK = 0;

void sqlError(const char *zpA_cadError)
{
   char zaL_errorOra[512];
   long unsigned int  ivL_longCadn;
   long unsigned int  ivL_longMens;

   sqlglm(zaL_errorOra, &ivL_longCadn, &ivL_longMens);
   printf("Error encontrado : %s \n", zpA_cadError);
   printf("Error de Oracle  : %s \n", zaL_errorOra);
   ivG_errorCon = -1;
}//sqlError

int conectando_aBD(paramConexion *spA_paramCon)
{
   int   iRetValue = 0;
   /* EXEC SQL BEGIN DECLARE SECTION; */ 

      char    zaO_usuario_[50];
      char    zaO_password[50];
      char    zaO_dbnameBD[50];
   /* EXEC SQL END DECLARE SECTION; */ 


   strcpy(zaO_usuario_,   spA_paramCon->usuario_DB);
   strcpy(zaO_password,   spA_paramCon->password_DB);
   strcpy(zaO_dbnameBD,   spA_paramCon->name_DB);

   /* EXEC SQL WHENEVER SQLERROR DO sqlError("Error conexion"); */ 
 
   iRetValue = -1;
   /* EXEC SQL CONNECT :zaO_usuario_ IDENTIFIED by :zaO_password AT BRANDONDB USING :zaO_dbnameBD; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 4;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )10;
   sqlstm.offset = (unsigned int  )5;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)zaO_usuario_;
   sqlstm.sqhstl[0] = (unsigned long )50;
   sqlstm.sqhsts[0] = (         int  )50;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)zaO_password;
   sqlstm.sqhstl[1] = (unsigned long )50;
   sqlstm.sqhsts[1] = (         int  )50;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)zaO_dbnameBD;
   sqlstm.sqhstl[2] = (unsigned long )50;
   sqlstm.sqhsts[2] = (         int  )50;
   sqlstm.sqindv[2] = (         short *)0;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlstm.sqlcmax = (unsigned int )100;
   sqlstm.sqlcmin = (unsigned int )2;
   sqlstm.sqlcincr = (unsigned int )1;
   sqlstm.sqlctimeout = (unsigned int )0;
   sqlstm.sqlcnowait = (unsigned int )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) sqlError("Error conexion");
}



   return iRetValue;
}//conectando_aBD

void cierraConexion()
{
   /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

   if ( !sqlca.sqlcode )
   {
      /* EXEC SQL AT BRANDONDB COMMIT WORK RELEASE; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 13;
      sqlstm.arrsiz = 4;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )45;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


   }
   else
   {
      /* EXEC SQL AT BRANDONDB ROLLBACK RELEASE; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 13;
      sqlstm.arrsiz = 4;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )69;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


   }
}//cierraConexion

int psvrinit(int argc, char *argv[]){
    int iRetValue = 0;
    paramConexion svL_paramCon;

    userlog ("Iniciando srvTuxedoBD01D");
    return(iRetValue);
}


void insert_Negocio_FML(TPSVCINFO *rqst){
    FLDLEN32 flen;
    paramConexion svL_paramCon;
    char msgbuf[256];

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    int t_idDir;
    char t_nombreDir[20];
    char t_nacionalidad[20];
    char t_estudioDir[20];
    /* EXEC SQL END DECLARE SECTION; */ 


    FBFR32* fbfr = (FBFR32*)rqst->data;
    strcpy(svL_paramCon.usuario_DB, "system");
    strcpy(svL_paramCon.password_DB, "Brand1739");
    strcpy(svL_paramCon.name_DB, "BRANDONDB");

    memset(&t_idDir, 0x00, sizeof(t_idDir));
    memset(t_nombreDir, 0x00, sizeof(t_nombreDir));
    memset(t_nacionalidad, 0x00, sizeof(t_nacionalidad));
    memset(t_estudioDir, 0x00, sizeof(t_estudioDir));

    userlog ("Servicio insert_Negocio_FML Invocado");

    if(Fget32 (fbfr, IDDIR, 0, (char*)&t_idDir, 0) < 0){
        userlog ("Error Fget32(CODIGO): %s", Fstrerror32(Ferror32));
        tpreturn (TPFAIL, 0, rqst->data, 0L, 0);
    }

    userlog (" IDDIR: [%d]", t_idDir);

    if(Fget32 (fbfr, NOMBREDIR, 0, t_nombreDir, 0) < 0){
        userlog ("Error Fget32(NOMBREDIR): %s", Fstrerror32(Ferror32));
        tpreturn (TPFAIL, 0, rqst->data, 0L, 0);
    }
    userlog ("nombreDir : [%s]", t_nombreDir) ;

    if(Fget32 (fbfr, NACIONALIDAD, 0, t_nacionalidad, 0) < 0){
        userlog ("Error Fget32(NACIONALIDAD): %s", Fstrerror32(Ferror32));
        tpreturn (TPFAIL, 0, rqst->data, 0L, 0);
    }
    userlog (" nacionalidad: [%s]", t_nacionalidad);

    if(Fget32 (fbfr, ESTUDIODIR, 0, t_estudioDir, 0) < 0){
        userlog ("Error Fget32(ESTUDIODIR): %s", Fstrerror32(Ferror32));
        tpreturn (TPFAIL, 0, rqst->data, 0L, 0);
    }
    userlog (" estudioDir : [%s]", t_estudioDir);

    userlog ("Conectando a la BD");
    conectando_aBD(&svL_paramCon);

    /* EXEC SQL AT BRANDONDB
    INSERT INTO Directores (idDir, nombreDir, nacionalidad, estudioDir)
    VALUES (:t_idDir, :t_nombreDir, :t_nacionalidad, :t_estudioDir); */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "insert into Directores (idDir,nombreDir,nacionalidad,estu\
dioDir) values (:b0,:b1,:b2,:b3)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )93;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&t_idDir;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)t_nombreDir;
    sqlstm.sqhstl[1] = (unsigned long )20;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)t_nacionalidad;
    sqlstm.sqhstl[2] = (unsigned long )20;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)t_estudioDir;
    sqlstm.sqhstl[3] = (unsigned long )20;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    if(sqlca.sqlcode != 0){
      sprintf(msgbuf, "Fallo insert: sqlcode = %d(%s)\n",
                     sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
      sqlError("Error al realizar Insert");
      Fchg32(fbfr, OUTPUT, 0, msgbuf, 0);
      cierraConexion();
      tpreturn(TPFAIL, 0, rqst->data, 0L, 0);
   }

   strcpy(msgbuf, "Insert exitoso!");
   userlog ("Insert exitoso");
   Fchg32(fbfr, OUTPUT, 0, msgbuf, 0);
   cierraConexion();
   tpreturn(TPSUCCESS, 0, rqst->data, strlen(rqst->data), 0);
}

void select_Negocio_FML(TPSVCINFO *rqst){
    FLDLEN32       flen;
    paramConexion  svL_paramCon;
    char           msgbuf[256];

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

	    int t_idPeli;
	    char t_nombrePeli[20];
	    char t_generoPeli[20];
	    char t_directorPeli[20];
    /* EXEC SQL END DECLARE SECTION; */ 


    FBFR32* fbfr = (FBFR32*)rqst->data;

    strcpy(svL_paramCon.usuario_DB, "system");
    strcpy(svL_paramCon.password_DB, "Brand1739");
    strcpy(svL_paramCon.name_DB, "BRANDONDB");
    t_idPeli = 0;
    memset(t_nombrePeli, 0x00, sizeof(t_nombrePeli));
    memset(t_generoPeli, 0x00, sizeof(t_generoPeli));
    memset(t_directorPeli, 0x00, sizeof(t_directorPeli));

    userlog ("Servicio select_Negocio_FML Invocado");

    /* Obtenemos los campos FML del buffer de entrada */
   if(Fget32 (fbfr, NOMBREPELI, 0, t_nombrePeli, 0) < 0) {
      userlog ("Error Fget32(NOMBREPELI): %s", Fstrerror32(Ferror32)) ;
      tpreturn (TPFAIL, 0, rqst->data, 0L,0);
   }
   userlog ("Buscar pelicula: [%s]", t_nombrePeli);
   

   Finit32 (fbfr, Fsizeof32 (fbfr));

   userlog ("Conectando a la BD");
   conectando_aBD(&svL_paramCon);

   /* Declaramos y Abrimos Cursor */
   /* EXEC SQL AT BRANDONDB DECLARE cu_bibAutor CURSOR FOR
      SELECT idPeli, nombrePeli, generoPeli, directorPeli
      FROM Pelicula
      WHERE nombrePeli = :t_nombrePeli; */ 

   if(sqlca.sqlcode != 0) {
      userlog ("Error Declare Cursor: %d-%s", 
        	sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc) ;
      tpreturn (TPFAIL, 0, rqst->data, 0L, 0) ;
   }

   /* EXEC SQL AT BRANDONDB OPEN cu_bibAutor; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 4;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = sq0005;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )133;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.sqlpfmem = (unsigned int  )0;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqcmod = (unsigned int )0;
   sqlstm.sqhstv[0] = (unsigned char  *)t_nombrePeli;
   sqlstm.sqhstl[0] = (unsigned long )20;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


   if(sqlca.sqlcode != 0) {
     userlog ("Error Open Cursor: %d-%s", 
            sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
      tpreturn (TPFAIL, 0, rqst->data, 0L, 0);
   }

   /* EXEC SQL AT BRANDONDB FETCH cu_bibAutor
   INTO :t_idPeli, :t_nombrePeli, :t_generoPeli, :t_directorPeli; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 4;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )161;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.sqlpfmem = (unsigned int  )0;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&t_idPeli;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)t_nombrePeli;
   sqlstm.sqhstl[1] = (unsigned long )20;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)t_generoPeli;
   sqlstm.sqhstl[2] = (unsigned long )20;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)0;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)t_directorPeli;
   sqlstm.sqhstl[3] = (unsigned long )20;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)0;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



   while (sqlca.sqlcode == 0) {
      Fadd32 (fbfr, IDPELI, (char *) &t_idPeli, 0);
      userlog (" Id de pelicula: [%d]", t_idPeli);
      Fadd32 (fbfr, NOMBREPELI, ajustaCampos(t_nombrePeli), 0);
      userlog (" nombrePeli : [%s]", ajustaCampos(t_nombrePeli));
      Fadd32 (fbfr, GENEROPELI, ajustaCampos( t_generoPeli), 0);
      userlog (" GENEROPELI: [%s]", ajustaCampos(t_generoPeli));
      Fadd32 (fbfr, DIRECTORPELI, ajustaCampos(t_directorPeli), 0) ;
      userlog (" DIRECTORPELI : [%s]", ajustaCampos(t_directorPeli)) ;
		
      /* EXEC SQL AT BRANDONDB FETCH cu_bibAutor 
      INTO :t_idPeli, :t_nombrePeli, :t_generoPeli, :t_directorPeli; */ 

{
      struct sqlexd sqlstm;
      sqlstm.sqlvsn = 13;
      sqlstm.arrsiz = 4;
      sqlstm.sqladtp = &sqladt;
      sqlstm.sqltdsp = &sqltds;
      sqlstm.iters = (unsigned int  )1;
      sqlstm.offset = (unsigned int  )201;
      sqlstm.selerr = (unsigned short)1;
      sqlstm.sqlpfmem = (unsigned int  )0;
      sqlstm.cud = sqlcud0;
      sqlstm.sqlest = (unsigned char  *)&sqlca;
      sqlstm.sqlety = (unsigned short)4352;
      sqlstm.occurs = (unsigned int  )0;
      sqlstm.sqfoff = (         int )0;
      sqlstm.sqfmod = (unsigned int )2;
      sqlstm.sqhstv[0] = (unsigned char  *)&t_idPeli;
      sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
      sqlstm.sqhsts[0] = (         int  )0;
      sqlstm.sqindv[0] = (         short *)0;
      sqlstm.sqinds[0] = (         int  )0;
      sqlstm.sqharm[0] = (unsigned long )0;
      sqlstm.sqadto[0] = (unsigned short )0;
      sqlstm.sqtdso[0] = (unsigned short )0;
      sqlstm.sqhstv[1] = (unsigned char  *)t_nombrePeli;
      sqlstm.sqhstl[1] = (unsigned long )20;
      sqlstm.sqhsts[1] = (         int  )0;
      sqlstm.sqindv[1] = (         short *)0;
      sqlstm.sqinds[1] = (         int  )0;
      sqlstm.sqharm[1] = (unsigned long )0;
      sqlstm.sqadto[1] = (unsigned short )0;
      sqlstm.sqtdso[1] = (unsigned short )0;
      sqlstm.sqhstv[2] = (unsigned char  *)t_generoPeli;
      sqlstm.sqhstl[2] = (unsigned long )20;
      sqlstm.sqhsts[2] = (         int  )0;
      sqlstm.sqindv[2] = (         short *)0;
      sqlstm.sqinds[2] = (         int  )0;
      sqlstm.sqharm[2] = (unsigned long )0;
      sqlstm.sqadto[2] = (unsigned short )0;
      sqlstm.sqtdso[2] = (unsigned short )0;
      sqlstm.sqhstv[3] = (unsigned char  *)t_directorPeli;
      sqlstm.sqhstl[3] = (unsigned long )20;
      sqlstm.sqhsts[3] = (         int  )0;
      sqlstm.sqindv[3] = (         short *)0;
      sqlstm.sqinds[3] = (         int  )0;
      sqlstm.sqharm[3] = (unsigned long )0;
      sqlstm.sqadto[3] = (unsigned short )0;
      sqlstm.sqtdso[3] = (unsigned short )0;
      sqlstm.sqphsv = sqlstm.sqhstv;
      sqlstm.sqphsl = sqlstm.sqhstl;
      sqlstm.sqphss = sqlstm.sqhsts;
      sqlstm.sqpind = sqlstm.sqindv;
      sqlstm.sqpins = sqlstm.sqinds;
      sqlstm.sqparm = sqlstm.sqharm;
      sqlstm.sqparc = sqlstm.sqharc;
      sqlstm.sqpadto = sqlstm.sqadto;
      sqlstm.sqptdso = sqlstm.sqtdso;
      sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


   }

   /* EXEC SQL CLOSE cu_bibAutor; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 4;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )241;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



   strcpy(msgbuf, "Select exitoso!");
   userlog ("Select exitoso");
   Fchg32(fbfr, OUTPUT, 0, msgbuf, 0);
   cierraConexion();
   tpreturn(TPSUCCESS, 0,(char *)fbfr, sizeof(fbfr), 0);
}

void update_Negocio_FML(TPSVCINFO *rqst)
{
   FLDLEN32 flen;
   paramConexion svL_paramCon;
   char msgbuf[256];

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

   int t_idAct;
   char t_estudioAct[20];
   /* EXEC SQL END DECLARE SECTION; */ 

   
   FBFR32* fbfr = (FBFR32*)rqst->data;
   strcpy(svL_paramCon.usuario_DB, "system");
   strcpy(svL_paramCon.password_DB, "Brand1739");
   strcpy(svL_paramCon.name_DB, "BRANDONDB");

   memset(&t_idAct, 0x00, sizeof(t_idAct));
   memset(t_estudioAct, 0x00, sizeof(t_estudioAct));

   userlog("Servicio update_Negocio_FML Invocado");

   if (Fget32(fbfr, IDACT, 0, (char*)&t_idAct, 0) < 0)
   {
      userlog("Error Fget32(IDACT): %s", Fstrerror32(Ferror32));
      tpreturn(TPFAIL, 0, rqst->data, 0L, 0);
   }

   userlog("ID de habitación: [%d]", t_idAct);

   if (Fget32(fbfr, ESTUDIOACT, 0, t_estudioAct, 0) < 0)
   {
      userlog("Error Fget32(ESTUDIOACT): %s", Fstrerror32(Ferror32));
      tpreturn(TPFAIL, 0, rqst->data, 0L, 0);
   }
   userlog("estudioAct : [%s]", t_estudioAct);

   userlog("Conectando a la BD");
   conectando_aBD(&svL_paramCon);

   /* EXEC SQL AT BRANDONDB
   UPDATE Actores
   SET estudioAct = :t_estudioAct
   WHERE idAct = :t_idAct; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 4;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "update Actores  set estudioAct=:b0 where idAct=:b1";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )265;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)t_estudioAct;
   sqlstm.sqhstl[0] = (unsigned long )20;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&t_idAct;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



   userlog("Update hecho");

   if (sqlca.sqlcode != 0)
   {
      userlog("Error SQL: %s", sqlca.sqlerrm.sqlerrmc);
      sprintf(msgbuf, "Fallo update: sqlcode = %d(%s)\n",
              sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
      sqlError("Error al realizar Update");
      Fchg32(fbfr, OUTPUT, 0, msgbuf, 0);
      cierraConexion();
      tpreturn(TPFAIL, 0, rqst->data, 0L, 0);
   }


   strcpy(msgbuf, "Update exitoso!");
   userlog ("Update exitoso");
   Fchg32(fbfr, OUTPUT, 0, msgbuf, 0);
   cierraConexion();
   tpreturn(TPSUCCESS, 0,(char *)fbfr, sizeof(fbfr), 0);
}

void delete_Negocio_FML(TPSVCINFO *rqst)
{
   FLDLEN32 flen;
   paramConexion svL_paramCon;
   char msgbuf[256];

   /* EXEC SQL BEGIN DECLARE SECTION; */ 

   int t_idEst;
   /* EXEC SQL END DECLARE SECTION; */ 

   
   FBFR32* fbfr = (FBFR32*)rqst->data;
   strcpy(svL_paramCon.usuario_DB, "system");
   strcpy(svL_paramCon.password_DB, "Brand1739");
   strcpy(svL_paramCon.name_DB, "BRANDONDB");

   memset(&t_idEst, 0x00, sizeof(t_idEst));

   userlog("Servicio delete_Negocio_FML Invocado");

   if (Fget32(fbfr, IDEST, 0, (char*)&t_idEst, 0) < 0)
   {
      userlog("Error Fget32(IDEST): %s", Fstrerror32(Ferror32));
      tpreturn(TPFAIL, 0, rqst->data, 0L, 0);
   }

   userlog("ID de Estudio: [%d]", t_idEst);

   userlog("Conectando a la BD");
   conectando_aBD(&svL_paramCon);

   /* EXEC SQL AT BRANDONDB
   DELETE FROM Estudios
   WHERE idEst = :t_idEst; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 13;
   sqlstm.arrsiz = 4;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "delete  from Estudios  where idEst=:b0";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )297;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)&t_idEst;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqphsv = sqlstm.sqhstv;
   sqlstm.sqphsl = sqlstm.sqhstl;
   sqlstm.sqphss = sqlstm.sqhsts;
   sqlstm.sqpind = sqlstm.sqindv;
   sqlstm.sqpins = sqlstm.sqinds;
   sqlstm.sqparm = sqlstm.sqharm;
   sqlstm.sqparc = sqlstm.sqharc;
   sqlstm.sqpadto = sqlstm.sqadto;
   sqlstm.sqptdso = sqlstm.sqtdso;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



   userlog("DELETE hecho");

   if (sqlca.sqlcode != 0)
   {
      userlog("Error SQL: %s", sqlca.sqlerrm.sqlerrmc);
      sprintf(msgbuf, "Fallo update: sqlcode = %d(%s)\n",
              sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);
      sqlError("Error al realizar delete");
      Fchg32(fbfr, OUTPUT, 0, msgbuf, 0);
      cierraConexion();
      tpreturn(TPFAIL, 0, rqst->data, 0L, 0);
   }

   strcpy(msgbuf, "Delete exitoso!");
   userlog ("Delete exitoso");
   Fchg32(fbfr, OUTPUT, 0, msgbuf, 0);
   cierraConexion();
   tpreturn(TPSUCCESS, 0,(char *)fbfr, sizeof(fbfr), 0);
}

char *ajustaCampos(char zaA_Campo[2000])
{
   int   ivL_obtenTam;
   int   ivL_contIter;
   int   ivL_siEspacs;
   int   ivL_noEspacs;

   ivL_obtenTam   = strlen(zaA_Campo);
   ivL_contIter   = 0;
   ivL_siEspacs   = 0;
   ivL_noEspacs   = 0;

   for(ivL_contIter = 0; ivL_contIter < ivL_obtenTam && zaA_Campo[ivL_contIter] == ' '; ivL_contIter++)
   {
      ivL_siEspacs++;
   }

   if(ivL_siEspacs == ivL_obtenTam)
   {
      return (char *)"\0";
   }
   else
   {
      if(ivL_siEspacs < ivL_obtenTam)
      {
         for(ivL_contIter = ivL_obtenTam - 1; ivL_contIter >= 0 && zaA_Campo[ivL_contIter] == ' '; ivL_contIter--)
         {
            ivL_noEspacs++;
         }
         zaA_Campo[ivL_obtenTam - ivL_noEspacs] = '\0';
         return (char *) zaA_Campo;
      }
   }
}//ajustaCampos

