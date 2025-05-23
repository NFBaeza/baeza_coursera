#include "data.h"
#include "memory.h"

uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base)
{
    if (!ptr || base < 2 || base > 16)
        return 0;                             

    uint8_t *start = ptr;                      

    int32_t value = data;
    if (value == 0)                           
    {
        *ptr++ = '0';
        *ptr    = '\0';
        return (uint8_t)(ptr - start + 1);   
    }

    if (value < 0)                             
    {
        *ptr++ = '-';
        value  = -value;
    }

    /* 2. Obtener los dígitos (en orden inverso) --------------------------- */
    uint8_t *digits_begin = ptr;
    do {
        uint32_t rem = (uint32_t)(value % base);
        *ptr++ = (uint8_t)(rem < 10 ? ('0' + rem)
                                    : ('A' + (rem - 10)));
        value /= (int32_t)base;
    } while (value);

    /* 3. Invertir sólo la sección de dígitos ------------------------------ */
    size_t digits_len = (size_t)(ptr - digits_begin);

    my_reverse(digits_begin, digits_len); 

    /* 4. Terminar la cadena y devolver longitud --------------------------- */
    *ptr = '\0';
    return (uint8_t)(ptr - start + 1);         /* +1 para el '\0'      */
}


int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base)
{
    if (!ptr || digits == 0 || base < 2 || base > 16)
        return 0;

    int32_t sign = 1;
    if (*ptr == '-') { sign = -1; ++ptr; --digits; }
    else if (*ptr == '+') { ++ptr; --digits; }

    /* --- NUEVO: si el último carácter es '\0', no lo proceses --- */
    if (digits && ptr[digits - 1] == '\0')
        --digits;


    int32_t result = 0;
    while (digits--) {
        uint8_t c = *ptr++;
        uint32_t value;

        if (c >= '0' && c <= '9')
            value = (uint32_t)(c - '0');
        else if (c >= 'A' && c <= 'F')
            value = (uint32_t)(c - 'A' + 10);
        else if (c >= 'a' && c <= 'f')
            value = (uint32_t)(c - 'a' + 10);
        else
            value = 0;                 /* carácter no válido → comportamiento indefinido según enunciado */

        /* Acumulación usando sólo operaciones escalares ------------------ */
        result = (int32_t)(result * (int32_t)base + (int32_t)value);
    }

    return result * sign;
}