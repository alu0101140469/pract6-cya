// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de autómatas finitos
// Autor: Daniel Palenzuela Álvarez
// Correo: alu0101140469@ull.edu.es
// Fecha: 22/10/2024 
// Archivo: automata.cc 
// Descripción: Implementación de los métodos de la clase Automata, incluyendo la carga de autómatas desde archivo y la simulación de su comportamiento.

#include "automata.h"
#include <fstream>
#include <iostream>
#include <sstream>

// Constructor por defecto
Automata::Automata() {
    estadoInicial = -1; // Inicializamos el estado inicial a un valor no válido
    esDeterminista = true; // Por defecto asumimos que el autómata es determinista
}

// Método para cargar un autómata desde un archivo .fa
bool Automata::cargarDesdeArchivo(const std::string &rutaArchivo) {
    std::ifstream archivo(rutaArchivo); // Abrimos el archivo
    if (!archivo.is_open()) {
        // En caso de error al abrir el archivo, mostramos un mensaje de error
        std::cerr << "Error al abrir el archivo " << rutaArchivo << std::endl;
        return false;
    }

    std::string linea;
    // Leer la primera línea: alfabeto
    std::getline(archivo, linea);
    std::istringstream ss(linea); // Convertimos la línea en un flujo para leer los símbolos
    char simbolo;
    while (ss >> simbolo) {
        alfabeto.insert(simbolo); // Añadimos cada símbolo al conjunto del alfabeto
    }

    // Leer el número de estados del autómata
    int numEstados;
    archivo >> numEstados;

    // Leer el estado inicial del autómata
    archivo >> estadoInicial;

    // Leer cada estado y sus transiciones
    for (int i = 0; i < numEstados; i++) {
        int estado, esFinal, numTransiciones;
        archivo >> estado >> esFinal >> numTransiciones; // Leer el identificador del estado, si es final, y el número de transiciones

        // Si el estado es de aceptación, lo añadimos al conjunto de estados finales
        if (esFinal == 1) {
            estadosFinales.insert(estado);
        }

        // Leer cada transición
        for (int j = 0; j < numTransiciones; j++) {
            char simboloTransicion;
            int estadoDestino;
            archivo >> simboloTransicion >> estadoDestino; // Leer el símbolo de transición y el estado destino

            // Comprobamos si ya existe una transición con el mismo símbolo
            if (transiciones[{estado, simboloTransicion}].size() > 0) {
                esDeterminista = false; // Si hay más de una transición, no es determinista
            }

            // Añadimos la transición al mapa de transiciones
            transiciones[{estado, simboloTransicion}].insert(estadoDestino);
        }
    }

    return true; // Autómata cargado correctamente
}

// Simulación para verificar si una cadena es aceptada
bool Automata::esCadenaAceptada(const std::string &cadena) {
    // Comenzamos desde el estado inicial
    std::set<int> estadosActuales = {estadoInicial};
    
    // Procesamos cada símbolo de la cadena
    for (char simbolo : cadena) {
        std::set<int> nuevosEstados; // Conjunto para los nuevos estados a los que podemos transitar
        
        // Para cada estado actual, verificamos si existe una transición con el símbolo actual
        for (int estado : estadosActuales) {
            auto it = transiciones.find({estado, simbolo});
            if (it != transiciones.end()) {
                // Añadimos los estados destino al conjunto de nuevos estados
                nuevosEstados.insert(it->second.begin(), it->second.end());
            }
        }

        // Actualizamos los estados actuales con los nuevos estados
        estadosActuales = nuevosEstados;
        
        // Si no hay estados a los que transitar, la cadena es rechazada
        if (estadosActuales.empty()) {
            return false;
        }
    }

    // Verificamos si al finalizar estamos en un estado de aceptación
    for (int estado : estadosActuales) {
        if (estadosFinales.count(estado)) {
            return true; // La cadena es aceptada
        }
    }

    return false; // La cadena es rechazada
}

// Procesar una cadena (utiliza el método esCadenaAceptada)
bool Automata::procesarCadena(const std::string &cadena) {
    return esCadenaAceptada(cadena);
}

// Método para mostrar los resultados (puede ser ampliado para mostrar más detalles)
void Automata::mostrarResultados() {
    // Aquí se puede implementar la lógica para mostrar los resultados
}
