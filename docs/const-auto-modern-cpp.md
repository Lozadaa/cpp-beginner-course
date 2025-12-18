# Const, Constexpr, Auto y C++ Moderno

## Introducción

El C++ moderno introduce herramientas poderosas para escribir código más seguro, eficiente y mantenible. Tres conceptos clave son:

1. **`const`**: Valores que no deben cambiar (runtime)
2. **`constexpr`**: Valores calculables en compile-time
3. **`auto`**: Deducción automática de tipos

## Const - Inmutabilidad en Runtime

### ¿Qué es const?

`const` marca una variable como **inmutable**: una vez inicializada, su valor no puede cambiar.

```cpp
const int maximo = 100;
maximo = 200;  // ❌ ERROR: no puedes modificar una const
```

### Const con Punteros

Hay tres variantes:

```cpp
// 1. Puntero a constante (no puedes cambiar lo apuntado)
const int* ptr1 = &x;
*ptr1 = 10;  // ❌ ERROR
ptr1 = &y;   // ✅ OK

// 2. Puntero constante (no puedes cambiar el puntero)
int* const ptr2 = &x;
*ptr2 = 10;  // ✅ OK
ptr2 = &y;   // ❌ ERROR

// 3. Puntero constante a constante (nada puede cambiar)
const int* const ptr3 = &x;
*ptr3 = 10;  // ❌ ERROR
ptr3 = &y;   // ❌ ERROR
```

**Truco para leer:** Lee de derecha a izquierda:
- `const int*` = puntero a int constante
- `int* const` = puntero constante a int

### Const en Funciones

#### Parámetros Const

Indica que la función NO modificará el parámetro:

```cpp
void imprimir(const std::string& texto) {
    std::cout << texto;
    // texto = "otro";  // ❌ ERROR: es const
}

// Sin const (copia - ineficiente para tipos grandes)
void procesar1(std::string texto);  // Copia todo el string

// Con const ref (eficiente - no copia, no modifica)
void procesar2(const std::string& texto);  // ✅ Mejor

// Sin const (puede modificar)
void modificar(std::string& texto);  // OK si necesitas cambiar el original
```

**Regla de oro:**

| Tipo | Tamaño | Recomendación |
|------|--------|---------------|
| Primitivos (`int`, `char`, `bool`, `float`) | Pequeños | Por valor |
| Objetos (`std::string`, `std::vector`) | Grandes | `const &` (si no modificas) o `&` (si modificas) |

#### Return Const (menos común en C++ moderno)

```cpp
// Antiguo (evita modificación del retorno)
const std::string obtener_nombre();

// Moderno (no tan necesario por copy elision)
std::string obtener_nombre();
```

### ¿Por qué usar const?

1. **Seguridad**: Previene modificaciones accidentales
2. **Documentación**: Indica intención (este valor no cambia)
3. **Optimización**: El compilador puede hacer optimizaciones
4. **Corrección**: Permite pasar temporales a funciones

```cpp
void procesar(const std::string& s);

procesar("literal");  // ✅ OK: const ref acepta temporales

void modificar(std::string& s);

modificar("literal");  // ❌ ERROR: no-const ref NO acepta temporales
```

## Constexpr - Compile-Time Computation

### ¿Qué es constexpr?

`constexpr` indica que un valor puede calcularse en **tiempo de compilación** (compile-time).

```cpp
constexpr int dias_semana = 7;  // Calculado al compilar
constexpr int horas_semana = dias_semana * 24;  // También compile-time

// El compilador reemplaza esto como si escribieras:
// int horas_semana = 168;
```

### Const vs Constexpr

```cpp
const int x = 10;           // Runtime (aunque puede optimizarse)
constexpr int y = 10;       // Compile-time garantizado

int input;
std::cin >> input;

const int a = input;        // ✅ OK: const acepta valores runtime
constexpr int b = input;    // ❌ ERROR: constexpr requiere valor compile-time
```

**Diferencias clave:**

| | `const` | `constexpr` |
|---|---------|-------------|
| **Cuándo se evalúa** | Runtime (usualmente) | Compile-time (garantizado) |
| **Puede usar valores runtime** | Sí | No |
| **Puede usarse en arrays** | Solo enteros | Sí |
| **Funciones** | Solo lectura | Evaluables en compile-time |

### Constexpr Functions

Funciones que pueden ejecutarse en compile-time:

```cpp
constexpr int cuadrado(int n) {
    return n * n;
}

// Compile-time (constexpr argumento)
constexpr int x = cuadrado(5);  // x = 25, calculado al compilar

// Runtime (variable argumento)
int y = 10;
int z = cuadrado(y);  // Calculado al ejecutar
```

**Reglas para funciones constexpr:**

1. Solo puede tener `return` statements (C++11), más flexible en C++14+
2. No puede tener variables no-const (C++11)
3. Solo puede llamar otras funciones constexpr
4. Debe ser posible evaluarla en compile-time

```cpp
// ✅ OK - función constexpr válida
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

// ❌ ERROR - no puede hacer I/O
constexpr int leer_archivo() {
    std::cin >> x;  // No es compile-time
    return x;
}
```

### Usos de Constexpr

#### 1. Tamaños de arrays

```cpp
constexpr int tamano = 10;
int array[tamano];  // ✅ OK

const int tam2 = 10;
int array2[tam2];  // ✅ OK en C++ (no en C)

int tam3 = 10;
int array3[tam3];  // ❌ ERROR: debe ser constante compile-time
```

#### 2. Template parameters

```cpp
template<int N>
struct Array {
    int data[N];
};

constexpr int size = 5;
Array<size> arr;  // ✅ OK

const int size2 = 5;
Array<size2> arr2;  // ✅ OK (tratado como constexpr si es literal)

int size3 = 5;
Array<size3> arr3;  // ❌ ERROR
```

#### 3. Optimización (cálculos pesados)

```cpp
constexpr uint64_t fibonacci(int n) {
    return (n <= 1) ? n : fibonacci(n-1) + fibonacci(n-2);
}

// Calculado DURANTE LA COMPILACIÓN (no al ejecutar)
constexpr auto fib30 = fibonacci(30);
// Es como escribir: const auto fib30 = 832040;
```

## Auto - Deducción de Tipos

### ¿Qué es auto?

`auto` le dice al compilador que deduzca el tipo automáticamente desde el inicializador.

```cpp
auto x = 10;          // int
auto y = 10.5;        // double
auto z = 10.5f;       // float
auto s = "hola";      // const char*
auto str = std::string("hola");  // std::string
```

### ¿Por qué usar auto?

#### 1. DRY (Don't Repeat Yourself)

```cpp
// Sin auto (repetitivo)
std::vector<std::pair<std::string, int>> vec;
std::vector<std::pair<std::string, int>>::iterator it = vec.begin();

// Con auto (limpio)
std::vector<std::pair<std::string, int>> vec;
auto it = vec.begin();
```

#### 2. Corrección

```cpp
std::vector<int> vec = {1, 2, 3};

// ❌ Bug sutil: size() retorna size_t, no int
for (int i = 0; i < vec.size(); ++i) { }  // Comparación signed/unsigned

// ✅ Correcto: auto deduce el tipo correcto
for (auto i = 0u; i < vec.size(); ++i) { }

// ✅ Mejor: range-based for
for (auto elem : vec) { }
```

#### 3. Refactoring

Si cambias el tipo de retorno, código con `auto` sigue funcionando:

```cpp
auto resultado = obtener_datos();  // Funciona sin importar qué retorne
```

### AAA: Almost Always Auto

Principio de C++ moderno: **Usa `auto` casi siempre**.

```cpp
// Tradicional
int x = 5;
double y = 3.14;
std::string nombre = "Ana";

// AAA
auto x = 5;
auto y = 3.14;
auto nombre = std::string("Ana");
```

**Excepciones:** Cuando el tipo no es obvio o quieres ser explícito:

```cpp
auto x = foo();  // ¿Qué retorna foo()? No está claro

// Mejor:
Player jugador = crear_jugador();  // Tipo explícito, intención clara
```

### Auto con Referencias

```cpp
std::string texto = "Hola";

auto copia = texto;         // std::string (copia)
auto& ref = texto;          // std::string& (referencia)
const auto& cref = texto;   // const std::string& (const ref)
```

**En bucles:**

```cpp
std::vector<std::string> nombres = {"Ana", "Bob", "Carlos"};

// Copia (ineficiente)
for (auto nombre : nombres) { }

// Referencia (eficiente, puede modificar)
for (auto& nombre : nombres) { }

// Const reference (eficiente, no modifica)
for (const auto& nombre : nombres) { }  // ✅ Preferido
```

### Auto y Tipos Complejos

```cpp
// Mapas
std::map<std::string, int> mapa;

// Sin auto (horrible)
for (std::pair<const std::string, int>& par : mapa) {
    std::cout << par.first << ": " << par.second << '\n';
}

// Con auto (limpio)
for (auto& par : mapa) {
    std::cout << par.first << ": " << par.second << '\n';
}

// C++17: structured bindings (aún mejor)
for (auto& [clave, valor] : mapa) {
    std::cout << clave << ": " << valor << '\n';
}
```

## Uniform Initialization (Inicialización Uniforme)

### Sintaxis `{}`

C++11 introduce una forma consistente de inicializar todo:

```cpp
// Primitivos
int x{5};
auto y = int{10};

// Objetos
std::string nombre{"Ana"};
auto texto = std::string{"Hola"};

// Agregados
struct Punto { int x; int y; };
Punto p{10, 20};

// Containers
std::vector<int> vec{1, 2, 3, 4, 5};
```

### Ventajas

#### 1. Detecta Narrowing Conversions

```cpp
float f = 10.5;

int a = f;       // ✅ Compila (pero pierde decimales - peligroso)
int b{f};        // ❌ ERROR: narrowing conversion detectado
int c = int{f};  // ❌ ERROR: detectado
```

#### 2. Evita "Most Vexing Parse"

```cpp
// Esto NO es una variable, es una declaración de función:
std::string nombre();

// Esto SÍ es una variable:
std::string nombre{};  // string vacío
```

#### 3. Inicialización por Defecto

```cpp
int x{};         // 0
double y{};      // 0.0
bool b{};        // false
std::string s{}; // "" (vacío)
```

### Cuándo Usar Cada Estilo

```cpp
// 1. Uniform initialization (preferido en C++ moderno)
auto x = int{10};
auto vec = std::vector<int>{1, 2, 3};

// 2. Copy initialization (común, simple)
int y = 10;
auto z = 10;

// 3. Direct initialization (para constructores con parámetros)
std::string s("Hola");
```

## Conversiones de Tipo

### Conversiones Implícitas (Peligrosas)

```cpp
double d = 10.9;
int x = d;  // x = 10 (pierde .9 sin advertencia)

unsigned int a = 5;
int b = -3;
auto resultado = a + b;  // ⚠️ Conversión peligrosa signed/unsigned
```

### Conversiones Explícitas

#### C-style Cast (❌ Evitar)

```cpp
double d = 10.5;
int x = (int)d;  // Funciona, pero es peligroso
```

**Problemas:**
- Hace cualquier conversión (incluso inseguras)
- No verificable por el compilador
- Difícil de encontrar en código

#### Static Cast (✅ Usar)

```cpp
double d = 10.5;
int x = static_cast<int>(d);  // Explícito y seguro

// Con enums
enum class Color { Rojo, Verde, Azul };
Color c = Color::Rojo;
int valor = static_cast<int>(c);  // Explícito
```

**Ventajas:**
- Intención clara
- Buscable en código
- Verificable en compile-time
- Solo permite conversiones válidas

#### Otros Casts (Avanzado)

```cpp
// const_cast: Quitar const (raro, peligroso)
const int x = 10;
int& y = const_cast<int&>(x);

// dynamic_cast: Para polimorfismo (runtime)
Base* b = new Derivada();
Derivada* d = dynamic_cast<Derivada*>(b);

// reinterpret_cast: Reinterpretación binaria (muy peligroso)
int x = 65;
char* c = reinterpret_cast<char*>(&x);
```

## Mejores Prácticas

### 1. Const Everywhere

```cpp
// ✅ Marca const todo lo que no cambie
const int max_usuarios = 100;

void procesar(const std::string& input) {
    const auto resultado = calcular(input);
    // ...
}
```

### 2. Constexpr para Literales

```cpp
// ❌ Mal
#define PI 3.14159  // Macro (no tiene tipo)

// ✅ Bien
constexpr double PI = 3.14159;
```

### 3. AAA (Almost Always Auto)

```cpp
// ❌ Repetitivo
std::vector<int> vec = std::vector<int>{1, 2, 3};

// ✅ Limpio
auto vec = std::vector<int>{1, 2, 3};
```

### 4. Static Cast para Conversiones

```cpp
// ❌ Mal
enum class Status { OK, Error };
int x = (int)Status::OK;

// ✅ Bien
int x = static_cast<int>(Status::OK);
```

### 5. Uniform Initialization

```cpp
// ✅ Preferido
auto x = int{10};
auto vec = std::vector<int>{1, 2, 3};
```

## Ejercicios

### Ejercicio 1
Identifica errores:

```cpp
const int x;  // ¿Error?
x = 10;

constexpr int y = x;  // ¿Error?

auto z;  // ¿Error?
z = 5;
```

<details>
<summary>Respuesta</summary>

1. `const int x;` - ❌ ERROR: const debe inicializarse
2. `x = 10;` - ❌ ERROR: no puedes modificar const
3. `constexpr int y = x;` - ❌ ERROR: x no es constexpr
4. `auto z;` - ❌ ERROR: auto necesita inicializador
</details>

### Ejercicio 2
Convierte este código a estilo moderno:

```cpp
std::vector<std::string> nombres;
for (std::vector<std::string>::iterator it = nombres.begin();
     it != nombres.end();
     ++it) {
    std::string copia = *it;
    std::cout << copia << '\n';
}
```

<details>
<summary>Solución</summary>

```cpp
auto nombres = std::vector<std::string>{};
for (const auto& nombre : nombres) {
    std::cout << nombre << '\n';
}
```
</details>

## Resumen

- **`const`**: Inmutable en runtime, usa para todo lo que no cambia
- **`constexpr`**: Calculable en compile-time, para literales y funciones puras
- **`auto`**: Deducción de tipos, úsalo casi siempre (AAA)
- **Uniform init `{}`**: Detecta errores, consistente
- **`static_cast<>`**: Conversiones explícitas seguras
- **Const references**: Eficiente para parámetros grandes
