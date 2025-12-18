# Guía Completa: Tipos de Datos en C++

## Introducción

Los tipos de datos son la base de todo programa. Definen qué clase de información puede almacenar una variable y qué operaciones puedes hacer con ella.

## Tipos Fundamentales

### Enteros (Integers)

En C++, los enteros pueden tener diferentes tamaños. El problema con `int`, `short`, `long` es que su tamaño varía según la plataforma:

- `int` puede ser 16, 32 o incluso 64 bits dependiendo del sistema
- `long` puede ser 32 o 64 bits

**Solución: Fixed-width integers**

El header `<cstdint>` proporciona tipos con tamaño garantizado:

```cpp
#include <cstdint>

std::int8_t   valor1;  // 8 bits  con signo (-128 a 127)
std::uint8_t  valor2;  // 8 bits  sin signo (0 a 255)
std::int16_t  valor3;  // 16 bits con signo (-32,768 a 32,767)
std::uint16_t valor4;  // 16 bits sin signo (0 a 65,535)
std::int32_t  valor5;  // 32 bits con signo (~-2 mil millones a 2 mil millones)
std::uint32_t valor6;  // 32 bits sin signo (0 a ~4 mil millones)
std::int64_t  valor7;  // 64 bits con signo (números enormes)
std::uint64_t valor8;  // 64 bits sin signo (números positivos enormes)
```

**¿Cuándo usar cada uno?**

- **int8_t**: Contadores pequeños, flags
- **int16_t**: Datos de red, protocolos binarios
- **int32_t**: El más común, para la mayoría de enteros
- **int64_t**: Timestamps, grandes cantidades, IDs únicos

**Signed vs Unsigned:**

- **Signed** (`int32_t`): Puede ser negativo. Usa un bit para el signo.
- **Unsigned** (`uint32_t`): Solo positivos. Usa todos los bits para magnitud, rango 2x mayor.

⚠️ **Cuidado**: Las operaciones con unsigned pueden dar resultados inesperados:

```cpp
std::uint32_t a = 5;
std::uint32_t b = 10;
std::uint32_t resultado = a - b;  // ¡No es -5! Es un número enorme (wrap-around)
```

### Punto Flotante (Floating Point)

Representan números con decimales:

```cpp
float  f1 = 3.14f;     // 32 bits, ~7 dígitos de precisión
double f2 = 3.14159;   // 64 bits, ~15 dígitos de precisión
```

**Reglas importantes:**

1. Los literales `float` deben llevar sufijo `f`: `3.14f`
2. Los literales sin sufijo son `double` por defecto: `3.14`
3. Nunca compares floats con `==` (usa rangos/tolerancia)

**¿Cuándo usar float vs double?**

- **float**: Cuando memoria es limitada (gráficos, arrays enormes)
- **double**: El estándar para la mayoría de cálculos científicos

### Booleanos

```cpp
bool verdadero = true;
bool falso = false;
```

Ocupa típicamente 1 byte. En expresiones, cualquier número diferente de 0 se convierte a `true`.

### Caracteres

```cpp
char letra = 'A';
char simbolo = '\n';  // Escape sequence para nueva línea
```

Un `char` es realmente un entero pequeño (típicamente 8 bits) que representa un carácter ASCII.

## Sufijos Literales

Para evitar ambigüedades, usa sufijos:

```cpp
auto a = 42;      // int
auto b = 42u;     // unsigned int
auto c = 42ul;    // unsigned long
auto d = 42ll;    // long long
auto e = 3.14f;   // float
auto f = 3.14;    // double
```

## Inicialización

**Tres formas principales:**

```cpp
// 1. Inicialización por copia (copy initialization)
int a = 10;

// 2. Inicialización directa
int b(10);

// 3. Inicialización uniforme (uniform initialization) - RECOMENDADA
int c{10};
auto d = int{10};
```

**Ventajas de uniform initialization `{}`:**

- Detecta conversiones peligrosas (narrowing) en compile-time
- Previene conversiones implícitas indeseadas
- Funciona igual para todos los tipos

```cpp
float f = 10.5;
int a = f;       // OK pero peligroso (pierde decimales)
int b{f};        // ERROR en compile-time ✅ Detecta el problema
int c = int{};   // Inicializa a 0 (valor por defecto)
```

## Ejercicio Práctico

Declara variables para un sistema de inventario:

1. ID del producto (número positivo grande)
2. Cantidad en stock (número positivo pequeño)
3. Precio (con decimales)
4. Está disponible (sí/no)
5. Código de categoría (letra)

<details>
<summary>Solución</summary>

```cpp
#include <cstdint>

std::uint64_t producto_id = 123456789ULL;
std::uint16_t stock = 50U;
double precio = 19.99;
bool disponible = true;
char categoria = 'A';
```
</details>

## Resumen

- Usa tipos de `<cstdint>` para portabilidad garantizada
- `float` = 32 bits, `double` = 64 bits
- Unsigned solo para valores siempre positivos
- Prefiere uniform initialization `{}`
- Usa sufijos para clarificar tipos literales
