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
# directorio y clase para semáforos
QUICK_LIB=./QuickSort
QUICK=${QUICK_LIB}/Quicksort
MERGE_LIB=./MergeSort
MERGE=${MERGE_LIB}/Mergesort
RADIX_LIB=./Radixsort
RADIX=${RADIX_LIB}/Radixsort
#---------------------------------------------------------
#directorio y clase para manejo de logs

all: ${EJEC}
#---------------------------------------------------------
# "linkar"
${EJEC}: ${EJEC}.o ${QUICK}.o ${MERGE}.o #${RADIX}.o 
	${CC} ${EJEC}.o ${QUICK}.o ${MERGE}.o -o ${EJEC} ${CPPFLAGS} ${LDFLAGS}

#---------------------------------------------------------
# compilar

${QUICK}.o: ${QUICK}.hpp ${QUICK}.cpp
	${CC} -c ${QUICK}.cpp -o ${QUICK}.o ${CPPFLAGS}

${MERGE}.o: ${MERGE}.hpp ${MERGE}.cpp
	${CC} -c ${MERGE}.cpp -o ${MERGE}.o ${CPPFLAGS}

#${RADIX}.o: ${RADIX}.hpp ${RADIX}.cpp
#	${CC} -c ${RADIX}.cpp -o ${RADIX}.o ${CPPFLAGS}
#---------------------------------------------------------
# Cuidado con lo que se pone aquí, que se borra sin preguntar
clean:
	$(RM) ${EJEC}.o ${MERGE}.o ${QUICK}.o ${RADIX}.o ${EJEC}