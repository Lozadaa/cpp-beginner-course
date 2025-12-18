# 📚 Documentación del Curso de C++

Bienvenido a la documentación extendida de tu curso de C++. Aquí encontrarás guías detalladas sobre cada tema que estás aprendiendo.

## 📖 Guías Disponibles

### [Guía de Tipos de Datos](guia-tipos-datos.md)
Aprende sobre todos los tipos primitivos en C++:
- Enteros con tamaño fijo (`std::int32_t`, etc.)
- Punto flotante (`float` vs `double`)
- Booleanos y caracteres
- Inicialización uniforme
- Conversiones de tipo

**Ideal para:** Capítulo 02.1

---

### [Funciones Avanzado](funciones-avanzado.md)
Todo sobre funciones en C++:
- Declaración vs definición
- Paso de parámetros (valor, referencia, const reference)
- Sobrecarga de funciones
- Valores de retorno múltiples
- Parámetros por defecto
- Funciones inline y constexpr

**Ideal para:** Capítulos 02.6, 02.7, 02.8, 02.10

---

### [Control de Flujo](control-flujo.md)
Estructuras de control completas:
- If-else y operador ternario
- Switch statements (¡cuidado con fall-through!)
- Bucles: for, while, do-while
- Range-based for loops
- Break y continue
- Pre vs post incremento
- Operadores lógicos (&&, ||, !)

**Ideal para:** Capítulos 02.2, 02.4, 02.5

---

### [Const, Auto y C++ Moderno](const-auto-modern-cpp.md)
Características del C++ moderno:
- `const` para inmutabilidad
- `constexpr` para compile-time
- `auto` y el principio AAA
- Uniform initialization `{}`
- Conversiones seguras con `static_cast`
- Mejores prácticas de C++ moderno

**Ideal para:** Capítulos 02.9, 02.10

---

## 🎯 Cómo Usar Esta Documentación

### Si estás empezando un nuevo capítulo:
1. Lee la sección correspondiente en el [README principal](../README.md)
2. Consulta la guía detallada relacionada aquí en `docs/`
3. Escribe tu código siguiendo los ejemplos
4. Completa el checklist del capítulo
5. Responde las preguntas de autoevaluación

### Si tienes dudas sobre un concepto:
1. Usa la búsqueda de tu editor (Cmd+F / Ctrl+F) en estas guías
2. Revisa los ejemplos de código
3. Prueba los ejercicios prácticos
4. Compara con tu propio código

### Si quieres profundizar:
- Cada guía tiene secciones "avanzado" para cuando domines lo básico
- Los ejercicios tienen soluciones ocultas (despliégalas cuando necesites)
- Experimenta con variaciones de los ejemplos

## 🗺️ Mapa de Conceptos

```
C++ Fundamentals
│
├─── Tipos de Datos (Ch 2.1)
│    ├─ Primitivos (int, float, bool, char)
│    ├─ Fixed-width integers (<cstdint>)
│    └─ Conversiones y casting
│
├─── Estructuras de Datos Básicas (Ch 2.2, 2.3)
│    ├─ Enumeraciones (enum class)
│    └─ Estructuras (struct)
│
├─── Control de Flujo (Ch 2.4, 2.5)
│    ├─ Condicionales (if-else, ternario, switch)
│    ├─ Bucles (for, while, do-while)
│    └─ Operadores lógicos
│
├─── Funciones (Ch 2.6, 2.7, 2.8)
│    ├─ Declaración y definición
│    ├─ Parámetros y retorno
│    ├─ Sobrecarga
│    └─ Variables static locales
│
└─── C++ Moderno (Ch 2.9, 2.10)
     ├─ auto (AAA principle)
     ├─ const y constexpr
     ├─ Uniform initialization
     └─ Static cast
```

## 📌 Conceptos Clave Transversales

### Siempre recuerda:
- ✅ **Inicializa todas las variables** antes de usarlas
- ✅ **Usa `const` para todo** lo que no cambie
- ✅ **Prefiere `auto`** para deducción de tipos (AAA)
- ✅ **Usa uniform initialization `{}`** para detectar errores
- ✅ **`static_cast<>` sobre C-style cast** siempre
- ✅ **Pasa objetos grandes por `const &`**
- ✅ **Usa `++i` en bucles**, no `i++`
- ✅ **SIEMPRE `break` en switch**, a menos que quieras fall-through explícito

## 🔗 Recursos Adicionales

### Para profundizar:
- [cppreference.com](https://en.cppreference.com/) - Referencia técnica completa
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/) - Mejores prácticas oficiales
- [Compiler Explorer](https://godbolt.org/) - Ve qué genera el compilador

### Para practicar:
- [LeetCode](https://leetcode.com/) - Problemas de algoritmos
- [HackerRank C++](https://www.hackerrank.com/domains/cpp) - Ejercicios específicos de C++
- [Exercism C++ Track](https://exercism.org/tracks/cpp) - Ejercicios con mentores

## 📝 Glosario Rápido

| Término | Significado |
|---------|-------------|
| **Declaración** | Decir que algo existe (forward declaration) |
| **Definición** | Implementación completa con cuerpo |
| **Inicialización** | Dar valor inicial a una variable |
| **Signature** | Nombre de función + tipos de parámetros |
| **Overloading** | Múltiples funciones con mismo nombre, diferentes parámetros |
| **Narrowing** | Conversión que pierde información (float→int) |
| **Compile-time** | Durante la compilación (antes de ejecutar) |
| **Runtime** | Durante la ejecución del programa |
| **AAA** | Almost Always Auto - principio de usar `auto` |
| **DRY** | Don't Repeat Yourself - evita duplicación |

## 🆘 Errores Comunes y Soluciones

### Error: "variable 'x' is uninitialized"
```cpp
// ❌ Mal
int x;
std::cout << x;  // Valor indefinido

// ✅ Bien
int x = 0;  // o auto x = int{};
std::cout << x;
```

### Error: "narrowing conversion"
```cpp
// ❌ Mal
float f = 10.5;
int x{f};  // Error de narrowing

// ✅ Bien
auto x = static_cast<int>(f);  // Explícito
```

### Error: "case label not followed by break"
```cpp
// ❌ Mal (fall-through accidental)
switch (x) {
    case 1:
        std::cout << "Uno\n";  // Falta break
    case 2:
        std::cout << "Dos\n";
        break;
}

// ✅ Bien
switch (x) {
    case 1:
        std::cout << "Uno\n";
        break;  // ✅
    case 2:
        std::cout << "Dos\n";
        break;
}
```

---

**¡Éxito en tu aprendizaje de C++!** 🚀

Recuerda: la práctica constante es la clave. Escribe código todos los días, experimenta, rompe cosas, y aprende de los errores.
