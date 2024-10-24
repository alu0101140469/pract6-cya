# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Práctica 6: Diseño e implementación de un simulador de autómatas finitos
# Autor: Daniel Palenzuela Álvarez
# Correo: alu0101140469@ull.edu.es
# Fecha: 22/10/2024 
# Archivo: Makefile
# Descripción: Archivo Makefile para la compilación del proyecto de simulador de autómatas finitos en C++.
# Compilación: make
# Ejecución: ./p06_automata_simulator input.fa input.txt

CXX = g++
CXXFLAGS = -Wall -std=c++11

# Regla principal para compilar el programa
all: p06_automata_simulator

# Regla para enlazar el programa final
p06_automata_simulator: main.o automata.o utils.o
	$(CXX) $(CXXFLAGS) -o p06_automata_simulator main.o automata.o utils.o

# Regla para compilar main.cc
main.o: main.cc automata.h utils.h
	$(CXX) $(CXXFLAGS) -c main.cc

# Regla para compilar automata.cc
automata.o: automata.cc automata.h
	$(CXX) $(CXXFLAGS) -c automata.cc

# Regla para compilar utils.cc
utils.o: utils.cc utils.h
	$(CXX) $(CXXFLAGS) -c utils.cc

# Regla para limpiar los archivos objeto y el binario
clean:
	rm -f *.o p06_automata_simulator
