/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stddef.h>   
#include <stdint.h>   
#include <stdlib.h>  
/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);


/**
 * @brief Copia un bloque de memoria gestionando solapamientos.
 *
 * Copia @p length bytes desde la dirección @p src a la dirección @p dst.
 * Si las regiones se superponen, la copia se realiza en la dirección
 * adecuada para evitar corrupción de datos (comportamiento equivalente
 * a la función estándar memset()).
 *
 * @param[in]  src    Puntero al primer byte de la región origen.
 * @param[out] dst    Puntero al primer byte de la región destino.
 * @param[in]  length Número de bytes a mover.
 *
 * @return Puntero al inicio de la región destino (@p dst).
 *
 * @pre  Los punteros deben ser válidos (no NULL) o @p length igual a 0.
 * @post El contenido de los @p length bytes en @p dst coincide con el
 *       contenido original de @p src.  
 * @warning Esta rutina modifica la memoria apuntada por @p dst.
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copia un bloque de memoria sin comprobar solapamiento.
 *
 * Copia @p length bytes de @p src a @p dst siempre hacia adelante.
 * Si las regiones se solapan de forma destructiva, el comportamiento
 * es indefinido (equivalente a memcpy()).
 *
 * @param[in]  src    Puntero al origen de la copia.
 * @param[out] dst    Puntero al destino de la copia.
 * @param[in]  length Número de bytes a copiar.
 *
 * @return Puntero al inicio de la región destino (@p dst).
 *
 * @pre  Las dos regiones no deben solaparse de manera que @p dst quede
 *       dentro del intervalo [@p src, @p src + @p length).  
 * @post El destino contiene los datos copiados; el origen permanece
 *       inalterado.
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Rellena un bloque de memoria con un mismo byte.
 *
 * Escribe el valor @p value en cada una de las @p length posiciones
 * consecutivas a partir de @p src.
 *
 * @param[out] src    Puntero al primer byte de la región a rellenar.
 * @param[in]  length Número de bytes a modificar.
 * @param[in]  value  Byte con el que se rellenará la región.
 *
 * @return Puntero al inicio de la región modificada (@p src).
 *
 * @post Todos los bytes en el rango [@p src, @p src + @p length)
 *       valen @p value.
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Pone a cero un bloque de memoria.
 *
 * Escribe 0x00 en @p length bytes consecutivos empezando en @p src.
 *
 * @param[out] src    Puntero al bloque que se va a poner a cero.
 * @param[in]  length Número de bytes a limpiar.
 *
 * @return Puntero al inicio del bloque limpiado (@p src).
 *
 * @post Todos los bytes de la región contienen el valor 0.
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Invierte el orden de los bytes en una región de memoria.
 *
 * Intercambia in-place los bytes de tal forma que el primero pasa a ser
 * el último, el segundo penúltimo, etc.
 *
 * @param[in,out] src    Puntero al primer byte de la región a invertir.
 * @param[in]     length Número de bytes dentro de la región.
 *
 * @return Puntero al inicio de la misma región (@p src).
 *
 * @pre  La región debe ser accesible para lectura y escritura.
 * @post El orden de los @p length bytes queda invertido.
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Reserva memoria dinámica para un número de palabras de 32 bits.
 *
 * Solicita al sistema un bloque de @p length palabras (`int32_t`)
 * contiguas. El tamaño total en bytes es
 * @p length * sizeof(int32_t).
 *
 * @param[in] length Número de palabras de 32 bits a reservar.
 *
 * @return Puntero al bloque reservado, o `NULL` si la reserva falla
 *         o si @p length es 0.
 *
 * @post El llamador es responsable de liberar la memoria con
 *       free_words().
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Libera un bloque de memoria reservado con reserve_words().
 *
 * Devuelve al sistema la memoria previamente obtenida. Pasar `NULL`
 * es seguro y no tiene efecto.
 *
 * @param[in] src Puntero al inicio del bloque a liberar.
 *
 * @post El bloque deja de ser válido; cualquier acceso posterior a
 *       él produce comportamiento indefinido.
 */
void free_words(int32_t * src);

#endif /* __MEMORY_H__ */
