#include <stdint.h>
#include <stddef.h>   

#ifndef BASE_16
#define BASE_16 16u      /* la “u” deja claro que es unsigned */
#endif

#ifndef BASE_10
#define BASE_10 10u      /* la “u” deja claro que es unsigned */
#endif

/**
 * @brief Convierte un entero con signo a una cadena ASCII.
 *
 * Convierte @p data a la base @p base (2 – 16) y deposita la
 * representación ASCII resultante en el búfer apuntado por @p ptr.
 * La salida siempre termina en ‘\0’.  
 * Sólo se emplea aritmética de punteros; no se usan funciones de
 * biblioteca ni indexación con corchetes.
 *
 * @param[in]  data  Número entero con signo a convertir.
 * @param[out] ptr   Puntero donde se copiará la c-string resultante.
 *                   Debe ser lo bastante grande (máx. 34 bytes:
 *                   signo + 32 dígitos en base 2 + null).
 * @param[in]  base  Base destino (entre 2 y 16 inclusive).
 *
 * @return Longitud TOTAL de la cadena generada, incluyendo el signo
 *         (si lo hay) y el terminador nulo ‘\0’.
 *
 * @warning Si @p base está fuera del rango [2, 16], la función devuelve 0
 *          y no escribe nada.
 */
uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base);

/**
 * @brief Convierte una cadena ASCII (base 2 – 16) a entero con signo.
 *
 * Toma @p digits caracteres a partir de @p ptr y los interpreta como un
 * número en la base indicada por @p base. Se admite un signo inicial
 * (‘-’ o ‘+’).  No se usan funciones de biblioteca ni acceso por índice;
 * sólo aritmética de punteros.
 *
 * @param[in] ptr    Puntero al primer carácter de la cadena.
 * @param[in] digits Número total de caracteres a procesar
 *                   (incluyendo el signo si existe).
 * @param[in] base   Base numérica (entre 2 y 16).
 *
 * @return El valor convertido como `int32_t`.  
 *         Si @p base está fuera de rango se devuelve 0.
 *
 * @warning No se validan caracteres fuera del rango de la base; si se
 *          encuentran, el comportamiento es indefinido según la consigna.
 */
int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base);