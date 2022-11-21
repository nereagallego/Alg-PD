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
LIB=./minisat/minisat
LIB1=core
SOLVER2=${LIB}/${LIB1}/Solver
THROW=${LIB}/${LIB1}/ThrowOOMException
LIB2=utils
OPTIONS=${LIB}/${LIB2}/Options 
SYSTEM=${LIB}/${LIB2}/System
LIB3=simp
SIMP=${LIB}/${LIB3}/SimpSolver
OUT=${LIB}/${LIB1}/OutOfMemoryException
TYPES=${LIB}/${LIB1}/SolverTypes
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
	${CC} ${SOLVER}.cpp -o ${SOLVER}.o ${CPPFLAGS}

# ${SOLVER2}.o: ${SOLVER2}.h ${SOLVER2}.cc
# 	${CC}  ${SOLVER2}.cc -o ${SOLVER2}.o ${CPPFLAGS}

# ${THROW}.o: ${THROW}.h ${THROW}.cc
# 	${CC} ${THROW}.cc -o ${THROW}.o ${CPPFLAGS}

# ${OPTIONS}.o: ${OPTIONS}.h ${OPTIONS}.cc
# 	${CC} ${OPTIONS}.cc -o ${OPTIONS}.o ${CPPFLAGS}

# ${SYSTEM}.o: ${SYSTEM}.h ${SYSTEM}.cc
# 	${CC} ${SYSTEM}.cc -o ${SYSTEM}.o ${CPPFLAGS}

# ${SIMP}.o: ${SIMP}.h ${SIMP}.cc
# 	${CC} ${SIMP}.cc -o ${SIMP}.o ${CPPFLAGS}

# ${OUT}.o: ${OUT}.h ${OUT}.cc
# 	${CC} ${OUT}.cc -o ${OUT}.o ${CPPFLAGS}

# ${TYPES}.o: ${TYPES}.h ${TYPES}.cc
# 	${CC} ${TYPES}.cc -o ${TYPES}.o ${CPPFLAGS}

${EJEC}.o: ${EJEC}.cpp 
	${CC} -c ${EJEC}.cpp ${CPPFLAGS}

#---------------------------------------------------------
# Cuidado con lo que se pone aquí, que se borra sin preguntar
clean:
	$(RM) ${TABLERO}.o ${EJEC}.o ${EJEC} ${SOLVER}.o ${SOLVER2}.o ${THROW}.o ${OPTIONS}.o ${SYSTEM}.o ${SIMP}.o ${OUT}.o ${TYPES}.o
