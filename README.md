# C++ Course - Mi Repositorio de Aprendizaje

Este repositorio contiene todo el código que escribo mientras sigo mi curso de C++. Cada capítulo representa una clase del curso con ejemplos prácticos.

<!-- LEARNING_GUIDE_START -->
## 📚 Learning Guide

### 🔢 Roadmap de capítulos

- [Capítulo 01 – Hello World](#capítulo-01--hello-world) → Tu primer programa en C++
- [Capítulo 02.1 – Tipos de Datos Primitivos](#capítulo-021--tipos-de-datos-primitivos) → Integers, floats, bool, char
- [Capítulo 02.2 – Enumeraciones](#capítulo-022--enumeraciones) → Enum class y switch statements
- [Capítulo 02.3 – Estructuras](#capítulo-023--estructuras) → Structs y type casting
- [Capítulo 02.4 – Bucles](#capítulo-024--bucles) → For, while, do-while loops
- [Capítulo 02.5 – Booleanos y Condicionales](#capítulo-025--booleanos-y-condicionales) → If-else y operador ternario
- [Capítulo 02.6 – Funciones](#capítulo-026--funciones) → Declaración y definición de funciones
- [Capítulo 02.7 – Sobrecarga de Funciones](#capítulo-027--sobrecarga-de-funciones) → Function overloading
- [Capítulo 02.8 – Variables Static Locales](#capítulo-028--variables-static-locales) → Static keyword en variables locales
- [Capítulo 02.9 – Auto e Inicialización](#capítulo-029--auto-e-inicialización) → AAA, conversiones y uniform initialization
- [Capítulo 02.10 – Const y Constexpr](#capítulo-0210--const-y-constexpr) → Constantes en tiempo de compilación vs ejecución

---

### 📖 Capítulos

#### Capítulo 01 – Hello World

- **Archivo(s):** [Chapter1/Main.cc](Chapter1/Main.cc)
- **Objetivo:** Escribir, compilar y ejecutar tu primer programa en C++.

**Conceptos clave:**
- Función `main()` como punto de entrada del programa
- Uso de `std::cout` para imprimir en consola
- El namespace `std`
- `std::endl` para nueva línea
- Valor de retorno de `main()`

**Explicación corta:**

Todo programa en C++ comienza ejecutándose desde la función `main()`. Esta función siempre retorna un entero (`int`), donde `0` indica que el programa terminó exitosamente. Para imprimir texto en la consola, usamos `std::cout` (character output) seguido del operador `<<` y lo que queremos imprimir. `std::endl` inserta una nueva línea y "vacía" el buffer de salida. El prefijo `std::` indica que estamos usando elementos de la biblioteca estándar (standard library) de C++.

**Checklist:**
- [ ] Sé compilar este programa desde la línea de comandos
- [ ] Sé ejecutar el binario generado
- [ ] Entiendo qué hace `std::cout`
- [ ] Puedo explicar por qué `main()` retorna `int`
- [ ] Sé qué significa el namespace `std::`

**Preguntas para repasar:**
1. ¿Qué valor debe retornar `main()` para indicar éxito? (Respuesta: 0)
2. ¿Verdadero o Falso? Puedo tener múltiples funciones `main()` en un programa. (Falso)
3. ¿Qué hace el operador `<<` con `std::cout`?
4. ¿Cuál es la diferencia entre `\n` y `std::endl`?
5. ¿Es obligatorio escribir `return 0;` en `main()`? (En C++ moderno, no, pero es buena práctica)

**Resumen rápido:** `main()` es el punto de entrada de todo programa C++. Usa `std::cout <<` para imprimir a consola y retorna 0 para indicar éxito.

---

#### Capítulo 02.1 – Tipos de Datos Primitivos

- **Archivo(s):** [Chapter2/integers_float.cc](Chapter2/integers_float.cc)
- **Objetivo:** Conocer los tipos de datos básicos en C++ y sus tamaños específicos.

**Conceptos clave:**
- Tipos enteros con tamaño fijo: `std::int8_t`, `std::int16_t`, `std::int32_t`, `std::int64_t`
- Versiones sin signo: `std::uint8_t`, `std::uint16_t`, etc.
- Tipos de punto flotante: `float` (32 bits) y `double` (64 bits)
- Tipo booleano: `bool` (true/false)
- Tipo carácter: `char`
- Header `<cstdint>` para tipos con tamaño garantizado

**Explicación corta:**

En C++, los tipos primitivos como `int` pueden tener diferentes tamaños dependiendo del compilador y la plataforma. Para garantizar portabilidad, usamos tipos de `<cstdint>` que especifican exactamente cuántos bits ocupa la variable: `std::int32_t` siempre es un entero de 32 bits con signo. Las versiones `uint` son sin signo (solo números positivos). Los números de punto flotante se declaran con `float` (precisión simple, sufijo `f`) o `double` (precisión doble, sin sufijo). Los literales numéricos sin signo llevan el sufijo `u` (ej: `42u`). `bool` almacena valores lógicos y `char` almacena un único carácter.

**Checklist:**
- [ ] Sé declarar variables de diferentes tipos enteros
- [ ] Entiendo la diferencia entre signed y unsigned
- [ ] Conozco cuántos bits ocupan `float` y `double`
- [ ] Sé usar los sufijos `f` y `u` correctamente
- [ ] Puedo incluir `<cstdint>` cuando lo necesito

**Preguntas para repasar:**
1. ¿Cuántos bytes ocupa un `std::int64_t`? (8 bytes)
2. ¿Verdadero o Falso? Un `unsigned int` puede almacenar números negativos. (Falso)
3. ¿Qué tipo es más preciso: `float` o `double`?
4. ¿Qué header necesitas incluir para usar `std::uint32_t`?
5. ¿Qué valor tiene por defecto un `bool` si no lo inicializas? (Indefinido - siempre debes inicializar)

**Resumen rápido:** Usa tipos de `<cstdint>` para garantizar el tamaño exacto de tus enteros. `float` es 32 bits, `double` es 64 bits. Siempre inicializa tus variables.

---

#### Capítulo 02.2 – Enumeraciones

- **Archivo(s):** [Chapter2/enum.cc](Chapter2/enum.cc)
- **Objetivo:** Usar enumeraciones para representar conjuntos de valores con nombre y trabajar con switch statements.

**Conceptos clave:**
- `enum class` para crear tipos enumerados con scope
- Valores enumerados como alternativas con nombre
- `switch` statement para control de flujo basado en valores
- `case`, `break`, y `default` en switch
- Riesgos del "fall-through" (olvidar `break`)

**Explicación corta:**

Las enumeraciones (`enum class`) te permiten definir un tipo que solo puede tener ciertos valores específicos con nombres descriptivos. Por ejemplo, `Status::Connected` es más legible que usar números mágicos como `1` o `2`. El `class` después de `enum` crea un "scoped enum" que evita colisiones de nombres: no puedes confundir `Status::Unknown` con `UserPermissions::Unknown`. Los switch statements evalúan una expresión y ejecutan código diferente según cada `case`. Es crucial usar `break` al final de cada caso, o el código "caerá" al siguiente caso (fall-through), lo cual suele ser un bug.

**Checklist:**
- [ ] Sé declarar un `enum class` propio
- [ ] Entiendo la notación `NombreEnum::Valor`
- [ ] Puedo escribir un switch statement completo
- [ ] Entiendo por qué necesito `break` en cada `case`
- [ ] Sé cuándo usar la cláusula `default`

**Preguntas para repasar:**
1. ¿Verdadero o Falso? Puedo asignar `Status::Unknown` a una variable de tipo `UserPermissions`. (Falso)
2. ¿Qué pasa si olvido el `break` en un `case`?
3. ¿Es obligatorio incluir un `default` en todo switch? (No, pero es recomendable)
4. ¿Cuál es la diferencia entre `enum` y `enum class`?
5. ¿Qué valor numérico tiene `Status::Unknown` si no especifico nada? (0)

**Resumen rápido:** `enum class` crea tipos con valores con nombre específicos. Usa switch para evaluar enums y no olvides los `break` para evitar fall-through.

---

#### Capítulo 02.3 – Estructuras

- **Archivo(s):** [Chapter2/struct.cc](Chapter2/struct.cc)
- **Objetivo:** Agrupar datos relacionados usando structs y aprender a hacer casting de tipos.

**Conceptos clave:**
- `struct` para agrupar variables relacionadas
- Miembros de una estructura (campos)
- Inicialización agregada (aggregate initialization)
- Designated initializers (C++20)
- Type casting: estilo C `(tipo)valor` vs C++ `static_cast<tipo>(valor)`
- Acceso a miembros con el operador `.`

**Explicación corta:**

Un `struct` (estructura) agrupa variables relacionadas bajo un mismo tipo. Por ejemplo, `User` puede tener un `status` y un `id`. Defines la estructura una vez y luego creas instancias. Para inicializar, puedes usar llaves `{valor1, valor2}` (orden importa) o la sintaxis C++20 `{.miembro = valor}` (más clara). Accedes a los miembros con el punto: `user1.id`. Para convertir tipos (casting), evita el estilo C `(tipo)valor` porque es peligroso. Usa `static_cast<tipo>(valor)` que es más seguro y explícito. Esto es especialmente útil para convertir enums a enteros.

**Checklist:**
- [ ] Sé declarar mi propio `struct`
- [ ] Puedo crear instancias e inicializarlas
- [ ] Entiendo la sintaxis de designated initializers
- [ ] Sé acceder a los miembros con `.`
- [ ] Prefiero `static_cast<>` sobre casting estilo C

**Preguntas para repasar:**
1. ¿Verdadero o Falso? En C++, `struct` y `class` son básicamente lo mismo. (Verdadero, solo difieren en acceso por defecto)
2. ¿Qué ventaja tiene `.status = valor` sobre solo `{valor}`?
3. ¿Por qué es mejor `static_cast<int>(x)` que `(int)x`?
4. ¿Puedo tener funciones dentro de un struct? (Sí)
5. ¿Qué operador uso para acceder a miembros de un struct?

**Resumen rápido:** Los structs agrupan datos relacionados. Inicializa con llaves, accede con `.`, y usa `static_cast<>` para conversiones de tipo seguras.

---

#### Capítulo 02.4 – Bucles

- **Archivo(s):** [Chapter2/loops.cc](Chapter2/loops.cc)
- **Objetivo:** Dominar las estructuras de repetición en C++ y entender la diferencia entre pre y post incremento.

**Conceptos clave:**
- Bucle `for` con inicialización, condición e incremento
- Pre-incremento `++i` vs post-incremento `i++`
- Pre-decremento `--i` vs post-decremento `i--`
- Bucle `while` (verifica condición antes)
- Bucle `do-while` (ejecuta al menos una vez)
- `break` para salir de un bucle

**Explicación corta:**

Los bucles repiten código. El `for` tiene tres partes: inicialización (`i = 0`), condición (`i < 3`), y paso (`i++`). El bucle se ejecuta mientras la condición sea verdadera. **Importante:** `i++` (post-incremento) devuelve el valor actual y luego incrementa; `++i` (pre-incremento) incrementa primero y luego devuelve. Por ejemplo, `int x = i++` asigna el valor viejo de `i` a `x`, pero `int x = ++i` asigna el nuevo valor. En bucles, `++i` es ligeramente más eficiente. El `while` evalúa la condición antes de cada iteración. El `do-while` ejecuta el cuerpo al menos una vez antes de verificar. Usa `break` para salir anticipadamente de cualquier bucle.

**Checklist:**
- [ ] Puedo escribir un bucle `for` que cuente de 0 a 10
- [ ] Entiendo cuándo usar pre vs post incremento
- [ ] Sé la diferencia entre `while` y `do-while`
- [ ] Puedo usar `break` para salir de un bucle
- [ ] Entiendo por qué `++i` puede ser más eficiente

**Preguntas para repasar:**
1. Si `i = 5`, ¿cuánto vale `x` después de `int x = i++;`? (5, luego i=6)
2. Si `i = 5`, ¿cuánto vale `x` después de `int x = ++i;`? (6)
3. ¿Verdadero o Falso? Un `do-while` siempre se ejecuta al menos una vez. (Verdadero)
4. ¿Qué hace `break` dentro de un bucle?
5. En un `for`, ¿puedo omitir la inicialización o el incremento? (Sí, todas las partes son opcionales)

**Resumen rápido:** `for`, `while` y `do-while` repiten código. Pre-incremento (`++i`) incrementa antes de usar el valor; post-incremento (`i++`) después. Usa `break` para salir.

---

#### Capítulo 02.5 – Booleanos y Condicionales

- **Archivo(s):** [Chapter2/bool_if_ternary.cc](Chapter2/bool_if_ternary.cc)
- **Objetivo:** Trabajar con valores booleanos, operadores lógicos y estructuras condicionales.

**Conceptos clave:**
- Tipo `bool` con valores `true` y `false`
- Operadores lógicos: `&&` (AND), `||` (OR), `!` (NOT)
- Estructura `if-else if-else`
- Operador ternario `condición ? valor_si_true : valor_si_false`
- Precedencia de operadores lógicos

**Explicación corta:**

Los booleanos (`bool`) representan verdadero/falso. Puedes combinarlos con operadores: `&&` requiere que ambos lados sean verdaderos, `||` requiere que al menos uno lo sea, y `!` invierte el valor. Por ejemplo, `(b1 || b2) && b1` evalúa primero el paréntesis (OR), luego hace AND con `b1`. Las estructuras `if` ejecutan código solo si la condición es verdadera; `else if` verifica otra condición solo si la anterior fue falsa; `else` captura todo lo demás. El operador ternario es una forma compacta de if-else: `b1 ? 10 : -10` retorna 10 si `b1` es true, caso contrario -10. Es útil para asignaciones simples.

**Checklist:**
- [ ] Sé usar los operadores `&&`, `||` y `!`
- [ ] Puedo escribir una cadena `if-else if-else`
- [ ] Entiendo cuándo usar el operador ternario
- [ ] Conozco la precedencia básica de operadores lógicos
- [ ] Sé que `!false` es `true`

**Preguntas para repasar:**
1. ¿Verdadero o Falso? La expresión `true && false` evalúa a `true`. (Falso)
2. ¿Qué evalúa `false || true`? (true)
3. ¿Cuándo se ejecuta el bloque `else` en un if-else?
4. Reescribe `int x = condición ? 5 : 10;` usando if-else.
5. ¿Qué hace el operador `!` con un booleano?

**Resumen rápido:** Los `bool` almacenan true/false. Usa `&&`, `||`, `!` para lógica. `if-else` para bifurcaciones. El ternario `? :` es un if-else compacto.

---

#### Capítulo 02.6 – Funciones

- **Archivo(s):** [Chapter2/functions.cc](Chapter2/functions.cc)
- **Objetivo:** Crear y usar funciones para organizar y reutilizar código.

**Conceptos clave:**
- Declaración vs definición de funciones
- Forward declaration (prototipo de función)
- Tipo de retorno de una función
- Parámetros de función
- Llamada a función (invocación)
- `void` como tipo de retorno cuando no hay valor de retorno

**Explicación corta:**

Una función es un bloque de código reutilizable con un nombre. La **declaración** (o prototipo) solo dice que la función existe: `void my_function();`. La **definición** incluye el cuerpo (implementación). Puedes declarar una función antes de `main()` y definirla después, o definirla directamente antes de usarla. El tipo antes del nombre es el tipo de retorno (`void` significa que no retorna nada). Entre paréntesis van los parámetros (datos de entrada). Para usar una función, escribes su nombre seguido de paréntesis: `my_function()`. Esto se llama "invocar" o "llamar" la función.

**Checklist:**
- [ ] Sé declarar una función (forward declaration)
- [ ] Puedo definir una función con su cuerpo
- [ ] Entiendo qué significa `void` como tipo de retorno
- [ ] Sé llamar/invocar una función desde `main()`
- [ ] Entiendo que debo declarar antes de usar (o definir antes)

**Preguntas para repasar:**
1. ¿Verdadero o Falso? Puedo llamar una función antes de declararla. (Falso)
2. ¿Qué significa que una función tenga tipo de retorno `void`?
3. ¿Cuál es la diferencia entre declaración y definición?
4. ¿Qué va entre los paréntesis de una función?
5. ¿Puedo tener una función sin parámetros? (Sí)

**Resumen rápido:** Las funciones organizan código reutilizable. Declara antes de usar o define antes. `void` significa sin retorno. Llama con `nombre()`.

---

#### Capítulo 02.7 – Sobrecarga de Funciones

- **Archivo(s):** [Chapter2/function_overload.cc](Chapter2/function_overload.cc)
- **Objetivo:** Entender cómo C++ permite múltiples funciones con el mismo nombre pero diferentes parámetros.

**Conceptos clave:**
- Function overloading (sobrecarga de funciones)
- Signature de una función (nombre + tipos de parámetros)
- Resolución de sobrecarga en tiempo de compilación
- Alternativa: templates (mencionado en comentarios)

**Explicación corta:**

En C++, puedes tener varias funciones con el mismo nombre si tienen **diferentes parámetros** (distinto número o tipos). Esto se llama "sobrecarga" (overloading). El compilador decide cuál función llamar basándose en los argumentos que pasas. Por ejemplo, `print_my_number(123U)` llama a la versión que recibe `uint32_t`, mientras que `print_my_number(12.4)` llama a la versión que recibe `double`. Esto es útil para hacer código más legible, pero si el cuerpo es idéntico, las templates son mejor opción (tema avanzado). La "signature" de una función es su nombre + tipos de parámetros; el tipo de retorno NO cuenta para sobrecarga.

**Checklist:**
- [ ] Sé crear dos funciones con el mismo nombre y diferentes parámetros
- [ ] Entiendo cómo el compilador elige qué versión llamar
- [ ] Conozco que el tipo de retorno no cuenta para sobrecarga
- [ ] Sé que las templates son una alternativa (tema futuro)
- [ ] Puedo identificar cuándo usar overloading

**Preguntas para repasar:**
1. ¿Verdadero o Falso? Puedo sobrecargar funciones solo cambiando el tipo de retorno. (Falso)
2. ¿Qué es la "signature" de una función?
3. ¿Cómo decide el compilador qué función sobrecargada llamar?
4. ¿Por qué las templates pueden ser mejor que overloading en algunos casos?
5. ¿Puedo tener tres funciones con el mismo nombre y tres tipos de parámetros diferentes? (Sí)

**Resumen rápido:** Overloading permite múltiples funciones con igual nombre pero distintos parámetros. El compilador elige la correcta según los argumentos. Templates pueden evitar duplicación.

---

#### Capítulo 02.8 – Variables Static Locales

- **Archivo(s):** [Chapter2/local_static.cc](Chapter2/local_static.cc)
- **Objetivo:** Aprender cómo las variables `static` locales mantienen su valor entre llamadas a función.

**Conceptos clave:**
- Palabra clave `static` en variables locales
- Inicialización en tiempo de compilación vs tiempo de ejecución
- Persistencia de valores entre llamadas
- Diferencia entre variables locales normales y static
- Usos del keyword `static` (local, global, member)

**Explicación corta:**

Normalmente, las variables locales dentro de una función se crean cada vez que la función se llama y se destruyen al salir. Una variable `static` local es diferente: se inicializa **una sola vez** la primera vez que se ejecuta esa línea, y **mantiene su valor entre llamadas**. Por ejemplo, `static std::uint32_t counter = 1;` se inicializa solo en la primera llamada; en las siguientes, `counter` conserva el valor de la llamada anterior. Es útil para contadores o cachés dentro de funciones. El keyword `static` tiene varios usos: variables locales (como aquí), variables globales (linkage interno), y miembros de clase (tema futuro).

**Checklist:**
- [ ] Sé declarar una variable `static` dentro de una función
- [ ] Entiendo que se inicializa solo una vez
- [ ] Puedo explicar cuándo se inicializa (primera llamada)
- [ ] Conozco un caso de uso práctico (ej: contador)
- [ ] Sé que `static` tiene otros usos en C++

**Preguntas para repasar:**
1. ¿Verdadero o Falso? Una variable `static` local se reinicializa en cada llamada. (Falso)
2. ¿Cuándo se inicializa una variable `static` local?
3. ¿Qué pasa con el valor de una variable `static` entre llamadas?
4. Menciona un caso de uso para variables `static` locales.
5. ¿Es lo mismo `static` en una variable local que en una global? (No, tienen significados diferentes)

**Resumen rápido:** Variables `static` locales se inicializan una vez y mantienen su valor entre llamadas. Útiles para contadores o datos persistentes en funciones.

---

#### Capítulo 02.9 – Auto e Inicialización

- **Archivo(s):** [Chapter2/auto_init.cc](Chapter2/auto_init.cc)
- **Objetivo:** Usar `auto` para deducción de tipos y aprender sobre conversiones implícitas vs explícitas.

**Conceptos clave:**
- Keyword `auto` para deducción automática de tipo
- AAA: Almost Always Auto (principio de código moderno)
- DRY: Don't Repeat Yourself
- Conversiones implícitas (peligrosas)
- Conversiones explícitas con `static_cast<>`
- Uniform initialization con `{}`
- Promoción de tipos en expresiones mixtas

**Explicación corta:**

El keyword `auto` deduce automáticamente el tipo de una variable desde su inicializador: `auto x = 10;` hace que `x` sea `int`. Esto sigue el principio AAA (Almost Always Auto) que hace el código más limpio y mantenible (DRY). Sin embargo, debes tener cuidado con conversiones **implícitas**: `float a = 10.5; int b = a;` convierte silenciosamente el float a int (perdiendo decimales), lo cual puede ser un bug oculto. Usa conversiones **explícitas** con `static_cast<tipo>(valor)` para dejar clara tu intención. La uniform initialization `auto x = tipo{valor}` puede detectar conversiones peligrosas en tiempo de compilación. Cuando mezclas tipos en expresiones (`10 + 10.5`), C++ promueve al tipo "más grande" (aquí `double`).

**Checklist:**
- [ ] Sé usar `auto` para declarar variables
- [ ] Entiendo los riesgos de conversiones implícitas
- [ ] Prefiero `static_cast<>` para conversiones explícitas
- [ ] Conozco la sintaxis de uniform initialization `{}`
- [ ] Sé que en expresiones mixtas se usa el tipo más grande

**Preguntas para repasar:**
1. ¿Verdadero o Falso? `auto x = 10.5f;` hace que `x` sea de tipo `float`. (Verdadero)
2. ¿Por qué es peligroso `int b = float_var;`?
3. ¿Qué hace `auto x = std::int32_t{};`? (Inicializa x a 0)
4. ¿Qué tipo tiene `auto x = 10 + 10.5;`? (double)
5. ¿Qué significa el principio AAA?

**Resumen rápido:** `auto` deduce tipos automáticamente (AAA). Evita conversiones implícitas; usa `static_cast<>` explícito. Uniform init `{}` detecta errores. Expresiones mixtas usan el tipo mayor.

---

#### Capítulo 02.10 – Const y Constexpr

- **Archivo(s):** [Chapter2/const_constexpr.cc](Chapter2/const_constexpr.cc)
- **Objetivo:** Distinguir entre valores constantes en tiempo de ejecución (`const`) y tiempo de compilación (`constexpr`).

**Conceptos clave:**
- `const` para valores de solo lectura (runtime)
- `constexpr` para valores/funciones en tiempo de compilación (C++11/17)
- Funciones `constexpr` que pueden evaluarse en compile-time
- Parámetros `const` en funciones (input de solo lectura)
- Optimizaciones del compilador con `constexpr`
- Ejemplo práctico: factorial

**Explicación corta:**

`const` indica que una variable es de **solo lectura**: una vez inicializada, no puedes cambiarla. Sin embargo, su valor se calcula en **tiempo de ejecución** (aunque para enteros simples el compilador puede optimizar). `constexpr` (C++11) indica que el valor debe calcularse en **tiempo de compilación**, lo que permite optimizaciones mayores y uso en contextos que requieren constantes compile-time (como tamaños de arrays). Puedes marcar funciones como `constexpr`: si las llamas con argumentos constantes, el compilador las evalúa en compile-time; si los argumentos son variables, se evalúan en runtime. Los parámetros de funciones suelen ser `const` para indicar que son input de solo lectura. Ejemplo: `faculty(5)` calcula 5! = 120.

**Checklist:**
- [ ] Sé declarar variables `const` y `constexpr`
- [ ] Entiendo la diferencia entre compile-time y runtime
- [ ] Puedo escribir funciones `constexpr`
- [ ] Sé cuándo usar `const` en parámetros de función
- [ ] Conozco ejemplos donde `constexpr` es ventajoso

**Preguntas para repasar:**
1. ¿Verdadero o Falso? `constexpr` siempre se evalúa en tiempo de compilación. (Falso, depende del contexto)
2. ¿Qué garantiza `const` en una variable?
3. ¿Puede una función `constexpr` ejecutarse en runtime? (Sí)
4. ¿Por qué marcarías un parámetro como `const`?
5. ¿Qué versión de C++ introdujo `constexpr`? (C++11)

**Resumen rápido:** `const` = solo lectura en runtime. `constexpr` = evaluable en compile-time. Funciones `constexpr` pueden ejecutarse en ambos contextos según los argumentos.

<!-- LEARNING_GUIDE_END -->

---

## 🛠️ Compilación y Ejecución

Cada capítulo puede compilarse individualmente. Ejemplo:

```bash
cd Chapter2
g++ -std=c++20 -Wall -Wextra -o programa const_constexpr.cc
./programa
```

## 📝 Notas

Este es mi repositorio personal de aprendizaje. Lo actualizo constantemente según avanzo en el curso.
