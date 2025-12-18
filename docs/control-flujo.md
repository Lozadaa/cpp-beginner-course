# Control de Flujo en C++

## Introducción

El control de flujo te permite decidir qué código ejecutar (condicionales) y repetir código (bucles).

## Condicionales

### If-Else Básico

```cpp
int edad = 18;

if (edad >= 18) {
    std::cout << "Eres mayor de edad\n";
} else {
    std::cout << "Eres menor de edad\n";
}
```

### If-Else If-Else (Cascada)

```cpp
int nota = 85;

if (nota >= 90) {
    std::cout << "A - Excelente\n";
} else if (nota >= 80) {
    std::cout << "B - Muy bien\n";
} else if (nota >= 70) {
    std::cout << "C - Bien\n";
} else if (nota >= 60) {
    std::cout << "D - Aprobado\n";
} else {
    std::cout << "F - Reprobado\n";
}
```

**Importante:** Solo se ejecuta el primer bloque que sea verdadero, luego sale.

### Operador Ternario

Forma compacta de if-else para asignaciones:

```cpp
// Forma larga
int resultado;
if (condicion) {
    resultado = 10;
} else {
    resultado = -10;
}

// Forma corta (ternario)
int resultado = condicion ? 10 : -10;
```

**Sintaxis:** `condición ? valor_si_true : valor_si_false`

**Cuándo usar:**
- ✅ Asignaciones simples
- ✅ Return statements simples
- ❌ Lógica compleja (usa if-else normal)

```cpp
// Ejemplo bueno
auto mensaje = (edad >= 18) ? "adulto" : "menor";

// Ejemplo malo (difícil de leer)
auto x = (a > b) ? (c > d ? 1 : 2) : (e > f ? 3 : 4);  // ❌ NO hagas esto
```

### Switch Statement

Para múltiples comparaciones de igualdad:

```cpp
enum class Dia {
    Lunes, Martes, Miercoles, Jueves, Viernes, Sabado, Domingo
};

Dia hoy = Dia::Lunes;

switch (hoy) {
    case Dia::Lunes:
    case Dia::Martes:
    case Dia::Miercoles:
    case Dia::Jueves:
    case Dia::Viernes:
        std::cout << "Día laboral\n";
        break;
    case Dia::Sabado:
    case Dia::Domingo:
        std::cout << "Fin de semana\n";
        break;
    default:
        std::cout << "Día inválido\n";
        break;
}
```

**Reglas importantes:**

1. **SIEMPRE usa `break`** al final de cada caso (a menos que quieras fall-through intencional)
2. `default` captura todos los casos no manejados (opcional pero recomendado)
3. Solo funciona con tipos enteros, chars y enums (no strings ni floats)

**Fall-through (caída):**

```cpp
int numero = 2;

switch (numero) {
    case 1:
        std::cout << "Uno\n";
        // No hay break - cae al siguiente caso
    case 2:
        std::cout << "Dos\n";
        // No hay break - cae al siguiente caso
    case 3:
        std::cout << "Tres\n";
        break;
}

// Output: "Dos\nTres\n" (imprime ambos porque falta break)
```

⚠️ **Warning:** Fall-through sin intención es un bug común. El compilador puede advertir con `-Wimplicit-fallthrough`.

## Bucles

### For Loop

Estructura clásica para repetir N veces:

```cpp
for (inicialización; condición; incremento) {
    // código a repetir
}

// Ejemplo
for (std::uint32_t i = 0; i < 10; ++i) {
    std::cout << i << ' ';
}
// Output: 0 1 2 3 4 5 6 7 8 9
```

**Partes del for:**

1. **Inicialización**: Ejecuta UNA vez al inicio (`i = 0`)
2. **Condición**: Se verifica ANTES de cada iteración (`i < 10`)
3. **Incremento**: Se ejecuta DESPUÉS de cada iteración (`++i`)

**Todas las partes son opcionales:**

```cpp
// Bucle infinito
for (;;) {
    // corre para siempre
}

// Solo condición
int i = 0;
for (; i < 10; ) {
    std::cout << i << ' ';
    ++i;
}
```

### Pre-incremento vs Post-incremento

```cpp
int i = 5;

int a = i++;  // Post: a = 5, luego i = 6
int b = ++i;  // Pre:  i = 7 primero, luego b = 7
```

**En bucles:**

```cpp
// Ambos funcionan igual en bucles simples
for (int i = 0; i < 10; i++) { }   // Post
for (int i = 0; i < 10; ++i) { }   // Pre - ligeramente más eficiente
```

**Regla:** Prefiere `++i` en bucles (evita copia temporal innecesaria en tipos complejos).

### While Loop

Repite mientras la condición sea verdadera. Verifica ANTES de cada iteración:

```cpp
int contador = 0;

while (contador < 5) {
    std::cout << contador << '\n';
    ++contador;
}
// Output: 0 1 2 3 4
```

**Diferencia con for:**
- `while`: Cuando no sabes cuántas iteraciones necesitas
- `for`: Cuando sabes exactamente cuántas veces repetir

```cpp
// Leer hasta encontrar un valor
int valor = 0;
while (valor != 42) {
    std::cin >> valor;
}

// Bucle infinito
while (true) {
    // código
    if (condicion_salida) {
        break;
    }
}
```

### Do-While Loop

Similar a `while`, pero verifica DESPUÉS de cada iteración (ejecuta al menos una vez):

```cpp
int x = 10;

// While normal: NO se ejecuta
while (x < 5) {
    std::cout << "No verás esto\n";
}

// Do-while: se ejecuta UNA vez
do {
    std::cout << "Esto se ejecuta una vez\n";
} while (x < 5);
```

**Caso de uso típico:** Validación de input

```cpp
int opcion;
do {
    std::cout << "Elige opción (1-3): ";
    std::cin >> opcion;
} while (opcion < 1 || opcion > 3);
```

### Range-based For Loop (C++11)

Para iterar sobre colecciones:

```cpp
std::vector<int> numeros = {1, 2, 3, 4, 5};

// Forma tradicional
for (std::size_t i = 0; i < numeros.size(); ++i) {
    std::cout << numeros[i] << ' ';
}

// Range-based (más limpio)
for (int numero : numeros) {
    std::cout << numero << ' ';
}

// Con referencia (para modificar)
for (int& numero : numeros) {
    numero *= 2;  // Duplica cada elemento
}

// Const reference (eficiente, no modifica)
for (const auto& numero : numeros) {
    std::cout << numero << ' ';
}
```

## Control de Bucles

### Break

Sale del bucle inmediatamente:

```cpp
for (int i = 0; i < 100; ++i) {
    if (i == 5) {
        break;  // Sale cuando i = 5
    }
    std::cout << i << ' ';
}
// Output: 0 1 2 3 4
```

### Continue

Salta a la siguiente iteración:

```cpp
for (int i = 0; i < 10; ++i) {
    if (i % 2 == 0) {
        continue;  // Salta números pares
    }
    std::cout << i << ' ';
}
// Output: 1 3 5 7 9 (solo impares)
```

### Bucles Anidados

```cpp
// Tabla de multiplicar
for (int i = 1; i <= 5; ++i) {
    for (int j = 1; j <= 5; ++j) {
        std::cout << i * j << '\t';
    }
    std::cout << '\n';
}
```

**Break en bucles anidados:**

```cpp
bool encontrado = false;
for (int i = 0; i < 10 && !encontrado; ++i) {
    for (int j = 0; j < 10; ++j) {
        if (condicion) {
            encontrado = true;
            break;  // Solo sale del bucle interno
        }
    }
}
```

## Operadores Lógicos

### AND (&&)

Verdadero solo si AMBOS son verdaderos:

```cpp
bool a = true, b = false;

if (a && b) { }  // Falso (ambos deben ser true)
if (a && true) { }  // Verdadero
```

**Short-circuit:** Si el primer operando es falso, no evalúa el segundo:

```cpp
if (ptr != nullptr && ptr->valor > 0) {  // Seguro: solo accede si ptr válido
    // código
}
```

### OR (||)

Verdadero si AL MENOS UNO es verdadero:

```cpp
bool a = true, b = false;

if (a || b) { }  // Verdadero (al menos uno es true)
if (false || false) { }  // Falso
```

**Short-circuit:** Si el primer operando es verdadero, no evalúa el segundo:

```cpp
if (input == "salir" || procesar_largo(input)) {
    // No llama procesar_largo() si input == "salir"
}
```

### NOT (!)

Invierte el valor:

```cpp
bool activo = true;

if (!activo) {  // Si NO está activo
    std::cout << "Inactivo\n";
}

if (!(x > 5)) {  // Equivalente a: x <= 5
    // código
}
```

### Precedencia

De mayor a menor:
1. `!` (NOT)
2. `&&` (AND)
3. `||` (OR)

```cpp
bool resultado = !false && true || false;
// Se evalúa: ((!false) && true) || false
// = (true && true) || false
// = true || false
// = true
```

**Usa paréntesis para claridad:**

```cpp
// Confuso
if (a || b && c) { }

// Claro
if (a || (b && c)) { }
if ((a || b) && c) { }
```

## Ejercicios Prácticos

### Ejercicio 1: FizzBuzz
Imprime números del 1 al 100, pero:
- Si es múltiplo de 3: imprime "Fizz"
- Si es múltiplo de 5: imprime "Buzz"
- Si es múltiplo de ambos: imprime "FizzBuzz"
- Si no: imprime el número

<details>
<summary>Solución</summary>

```cpp
for (int i = 1; i <= 100; ++i) {
    if (i % 3 == 0 && i % 5 == 0) {
        std::cout << "FizzBuzz\n";
    } else if (i % 3 == 0) {
        std::cout << "Fizz\n";
    } else if (i % 5 == 0) {
        std::cout << "Buzz\n";
    } else {
        std::cout << i << '\n';
    }
}
```
</details>

### Ejercicio 2: Encontrar Primo
Escribe código que determine si un número es primo.

<details>
<summary>Solución</summary>

```cpp
bool es_primo(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
```
</details>

### Ejercicio 3: Menú Interactivo
Crea un menú que se repita hasta que el usuario elija salir.

<details>
<summary>Solución</summary>

```cpp
int opcion;
do {
    std::cout << "\n=== MENÚ ===\n";
    std::cout << "1. Opción 1\n";
    std::cout << "2. Opción 2\n";
    std::cout << "3. Salir\n";
    std::cout << "Elige: ";
    std::cin >> opcion;

    switch (opcion) {
        case 1:
            std::cout << "Ejecutando opción 1...\n";
            break;
        case 2:
            std::cout << "Ejecutando opción 2...\n";
            break;
        case 3:
            std::cout << "¡Adiós!\n";
            break;
        default:
            std::cout << "Opción inválida\n";
            break;
    }
} while (opcion != 3);
```
</details>

## Mejores Prácticas

1. **Prefiere range-based for** cuando iteres sobre colecciones
2. **Usa `++i` en bucles** (no `i++`)
3. **SIEMPRE usa `break` en switch** (a menos que quieras fall-through explícito)
4. **Usa paréntesis** en expresiones lógicas complejas
5. **Evita bucles infinitos accidentales** (verifica condiciones de salida)
6. **Prefiere `while` sobre `for`** si no sabes el número de iteraciones
7. **Inicializa variables** antes de usarlas en condiciones

```cpp
// ❌ Mal
int x;
if (x > 0) { }  // x no inicializado

// ✅ Bien
int x = 0;
if (x > 0) { }
```

## Resumen

- **If-else**: Decisiones basadas en condiciones
- **Ternario**: If-else compacto para asignaciones
- **Switch**: Múltiples comparaciones de igualdad (usa `break`)
- **For**: Repetir N veces
- **While**: Repetir mientras condición sea verdadera (verifica antes)
- **Do-while**: Repetir al menos una vez (verifica después)
- **Break**: Sale del bucle
- **Continue**: Salta a siguiente iteración
- **&&, ||, !**: Operadores lógicos AND, OR, NOT
