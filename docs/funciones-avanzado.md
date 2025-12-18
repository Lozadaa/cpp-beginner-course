# Funciones en C++ - Guía Avanzada

## Anatomía de una Función

Una función en C++ tiene esta estructura:

```cpp
tipo_retorno nombre_funcion(tipo_param1 param1, tipo_param2 param2) {
    // cuerpo de la función
    return valor;
}
```

**Componentes:**

1. **Tipo de retorno**: Qué devuelve la función (`int`, `void`, `double`, etc.)
2. **Nombre**: Identificador único (sigue reglas de variables)
3. **Lista de parámetros**: Input de la función (puede estar vacía)
4. **Cuerpo**: Código entre `{}`
5. **Return**: Devuelve el valor (omitido si es `void`)

## Declaración vs Definición

### Declaración (Forward Declaration)

Dice al compilador que la función existe:

```cpp
void procesar_datos(int x, int y);  // Solo firma, termina en ;
```

### Definición

Incluye el cuerpo completo:

```cpp
void procesar_datos(int x, int y) {
    std::cout << x + y << '\n';
}
```

### ¿Por qué separar?

```cpp
// ❌ Esto NO compila
int main() {
    calcular(5);  // Error: calcular no existe todavía
}

void calcular(int n) {
    std::cout << n * 2 << '\n';
}

// ✅ Solución 1: Definir antes de usar
void calcular(int n) {
    std::cout << n * 2 << '\n';
}

int main() {
    calcular(5);  // OK
}

// ✅ Solución 2: Declarar antes, definir después
void calcular(int n);  // Declaración

int main() {
    calcular(5);  // OK, el compilador sabe que existe
}

void calcular(int n) {  // Definición
    std::cout << n * 2 << '\n';
}
```

## Paso de Parámetros

### Por Valor (Pass by Value)

Copia el argumento. Cambios no afectan al original:

```cpp
void incrementar(int x) {
    x = x + 1;  // Solo afecta a la copia local
}

int main() {
    int numero = 10;
    incrementar(numero);
    std::cout << numero;  // Imprime 10 (no cambió)
}
```

### Por Referencia (Pass by Reference)

Usa el original. Cambios SÍ afectan:

```cpp
void incrementar(int& x) {  // Nota el &
    x = x + 1;  // Modifica el original
}

int main() {
    int numero = 10;
    incrementar(numero);
    std::cout << numero;  // Imprime 11 (cambió)
}
```

### Por Const Reference

Usa el original PERO sin permitir modificarlo (eficiente para tipos grandes):

```cpp
void imprimir(const std::string& texto) {  // No copia el string
    std::cout << texto;
    // texto = "otro";  // ERROR: es const
}
```

**Regla general:**

- Tipos pequeños (`int`, `char`, `bool`, `float`): por valor
- Tipos grandes (strings, vectors, structs): por const reference
- Si necesitas modificar el original: por referencia (sin const)

## Sobrecarga de Funciones (Overloading)

Varias funciones, mismo nombre, diferentes parámetros:

```cpp
void imprimir(int x) {
    std::cout << "Entero: " << x << '\n';
}

void imprimir(double x) {
    std::cout << "Double: " << x << '\n';
}

void imprimir(const std::string& x) {
    std::cout << "Texto: " << x << '\n';
}

int main() {
    imprimir(42);      // Llama a la versión int
    imprimir(3.14);    // Llama a la versión double
    imprimir("Hola");  // Llama a la versión string
}
```

**Reglas de sobrecarga:**

- Deben diferir en número o tipo de parámetros
- El tipo de retorno NO cuenta para sobrecarga
- Const/non-const cuenta como sobrecarga

```cpp
// ✅ OK - diferentes parámetros
void funcion(int x);
void funcion(double x);
void funcion(int x, int y);

// ❌ ERROR - solo cambia retorno
int funcion(int x);
void funcion(int x);

// ✅ OK - const cuenta
void procesar(std::string& s);
void procesar(const std::string& s);
```

## Valores de Retorno

### Return Simple

```cpp
int sumar(int a, int b) {
    return a + b;
}
```

### Return Múltiple (con Struct)

```cpp
struct Resultado {
    int suma;
    int producto;
};

Resultado calcular(int a, int b) {
    return {a + b, a * b};  // Aggregate initialization
}

int main() {
    auto res = calcular(3, 4);
    std::cout << res.suma << ", " << res.producto;  // 7, 12
}
```

### Return Múltiple (con std::pair o std::tuple - avanzado)

```cpp
#include <utility>

std::pair<int, int> calcular(int a, int b) {
    return {a + b, a * b};
}

int main() {
    auto [suma, producto] = calcular(3, 4);  // C++17 structured binding
    std::cout << suma << ", " << producto;
}
```

## Parámetros por Defecto

```cpp
void saludar(const std::string& nombre, int veces = 1) {
    for (int i = 0; i < veces; ++i) {
        std::cout << "Hola " << nombre << '\n';
    }
}

int main() {
    saludar("Ana");       // veces = 1 (default)
    saludar("Bob", 3);    // veces = 3
}
```

**Reglas:**

- Los parámetros con default deben estar al final
- Solo en la declaración (no repetir en definición)

## Inline Functions

Sugerencia al compilador para insertar el código directamente (evita overhead de llamada):

```cpp
inline int cuadrado(int x) {
    return x * x;
}
```

Útil para funciones pequeñas llamadas frecuentemente. El compilador decide si realmente hace inline.

## Constexpr Functions

Funciones evaluables en compile-time:

```cpp
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main() {
    constexpr int f5 = factorial(5);  // Calculado en compile-time
    int x = 5;
    int f_x = factorial(x);  // Calculado en runtime (x no es constante)
}
```

## Ejercicios

### Ejercicio 1
Escribe una función `es_par` que retorne `true` si un número es par.

<details>
<summary>Solución</summary>

```cpp
bool es_par(int numero) {
    return numero % 2 == 0;
}
```
</details>

### Ejercicio 2
Sobrecarga una función `maximo` para `int` y `double` que retorne el mayor de dos números.

<details>
<summary>Solución</summary>

```cpp
int maximo(int a, int b) {
    return (a > b) ? a : b;
}

double maximo(double a, double b) {
    return (a > b) ? a : b;
}
```
</details>

### Ejercicio 3
Crea una función `intercambiar` que intercambie los valores de dos variables (debe modificar los originales).

<details>
<summary>Solución</summary>

```cpp
void intercambiar(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
```
</details>

## Mejores Prácticas

1. **Nombres descriptivos**: `calcular_promedio()` mejor que `calc()`
2. **Una responsabilidad**: Cada función hace UNA cosa bien
3. **Parámetros const**: Marca como `const` lo que no modificas
4. **Funciones pequeñas**: Si tiene >50 líneas, probablemente debe dividirse
5. **Documentación**: Comenta qué hace la función (especialmente parámetros y retorno)

```cpp
/**
 * Calcula el factorial de un número.
 * @param n Número entero positivo
 * @return n! (factorial de n)
 */
std::uint64_t factorial(std::uint8_t n) {
    // implementación...
}
```

## Resumen

- **Declaración**: firma de la función (forward declaration)
- **Definición**: implementación completa
- **Parámetros**: por valor (copia), por referencia (original), por const ref (eficiente)
- **Sobrecarga**: mismo nombre, diferentes parámetros
- **Default args**: parámetros opcionales al final
- **Constexpr**: funciones evaluables en compile-time
