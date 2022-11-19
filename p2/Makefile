#*****************************************************************
# File:   Makefile
# Author: Nerea Gallego Sánchez y Victor Gallardo Sánchez
# Date:   septiembre 2022
# Coms:   Ejecutar "make" para compilar 
#         Ejecutar "make clean" para limpiar (borrar lo que genere)
#*****************************************************************

#---------------------------------------------------------
# macros
RM = /bin/rm -f  # para limpiar
CC = g++         # compilador
#---------------------------------------------------------
# opciones compilación y enlazado ("linkado")
CPPFLAGS = -std=c++11 # opciones compilación  # opciones de "linkado"
#---------------------------------------------------------
# vars
EJEC = main
#---------------------------------------------------------
# directorio y clase para semáfo
TABLERO_LIB=./tablero
TABLERO=${TABLERO_LIB}/Tablero
SOLVER=Solver
INCLUDE = -IC:minisat
#---------------------------------------------------------
#directorio y clase para manejo de logs
all: ${EJEC}
#---------------------------------------------------------
# "linkar"
${EJEC}: ${EJEC}.o  ${TABLERO}.o ${SOLVER}.o
	${CC} ${EJEC}.o ${TABLERO}.o ${SOLVER}.o -o ${EJEC} -L minisat ${CPPFLAGS}

#---------------------------------------------------------
# compilar
${TABLERO}.o: ${TABLERO}.hpp ${TABLERO}.cpp
	${CC} -c ${TABLERO}.cpp -o ${TABLERO}.o ${CPPFLAGS}

${SOLVER}.o: ${SOLVER}.hpp ${SOLVER}.cpp
	${CC} ${INCLUDE} -c ${SOLVER}.cpp -o ${SOLVER}.o ${CPPFLAGS}

#---------------------------------------------------------
# Cuidado con lo que se pone aquí, que se borra sin preguntar
clean:
	$(RM) ${TABLERO}.o ${EJEC}.o ${EJEC} ${SOLVER}.o
