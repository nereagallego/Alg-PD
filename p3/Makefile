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
EJEC = Karger
#---------------------------------------------------------
# directorio y clase para semáforos

#---------------------------------------------------------
#directorio y clase para manejo de logs

all: ${EJEC}
#---------------------------------------------------------
# "linkar"
${EJEC}: ${EJEC}.o 
	${CC} ${EJEC}.o -o ${EJEC} ${CPPFLAGS} ${LDFLAGS}

#---------------------------------------------------------
# compilar

${EJEC}.o: ${EJEC}.cpp 
	${CC} -c ${EJEC}.cpp ${CPPFLAGS}

#---------------------------------------------------------
# Cuidado con lo que se pone aquí, que se borra sin preguntar
clean:
	$(RM) ${EJEC}.o ${EJEC}