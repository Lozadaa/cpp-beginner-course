# 🚀 Cómo Usar Tu Documentación de C++

Tienes **3 formas** de acceder a tu contenido de aprendizaje:

---

## 1️⃣ README.md (Libro de Texto)

**📍 Ubicación:** `/README.md`

### ✨ Características:
- ✅ Guía completa en un solo archivo
- ✅ 11 capítulos + 3 apéndices
- ✅ Fácil de leer en GitHub, VS Code, o cualquier editor Markdown
- ✅ Ideal para revisión rápida
- ✅ Se puede imprimir como PDF

### 🎯 Mejor para:
- Estudio offline
- Impresión
- Lectura lineal de principio a fin
- Búsqueda rápida con Ctrl+F

### 📖 Cómo usar:
```bash
# En VS Code:
code README.md

# En navegador (si subes a GitHub):
# Solo abre el repositorio y se renderiza automáticamente
```

---

## 2️⃣ Guías Detalladas en docs/

**📍 Ubicación:** `/docs/`

### ✨ Características:
- ✅ Archivos separados por tema
- ✅ Explicaciones en profundidad
- ✅ Ejemplos de código extensos
- ✅ Ejercicios con soluciones

### 📂 Archivos:
- `docs/README.md` - Índice general
- `docs/01-tipos-datos.md` - Guía completa de tipos
- `docs/02-control-flujo.md` - Condicionales y bucles
- `docs/03-funciones.md` - Todo sobre funciones
- `docs/04-cpp-moderno.md` - Const, auto, constexpr

### 🎯 Mejor para:
- Profundizar en un tema específico
- Referencia detallada
- Aprendizaje por temas

---

## 3️⃣ Libro Interactivo HTML (✨ RECOMENDADO)

**📍 Ubicación:** `/html/`

### ✨ Características:
- ✅ **Interfaz moderna y hermosa**
- ✅ **Tema claro/oscuro** 🌙☀️
- ✅ **Navegación fluida** (sidebar + botones + teclado)
- ✅ **Barra de progreso** visual
- ✅ **Checkboxes persistentes** (tu progreso se guarda)
- ✅ **Responsive** (funciona en móvil)
- ✅ **Preguntas interactivas** (clic para ver respuestas)
- ✅ **Accesible** (ARIA labels, navegación por teclado)
- ✅ **Sin dependencias** (solo HTML/CSS/JS)

### 🚀 Cómo abrir:

#### Opción A: Servidor local (RECOMENDADO)
```bash
cd html
python3 -m http.server 8000
```
Luego abre: **http://localhost:8000**

#### Opción B: Directamente
```bash
cd html
open index.html           # macOS
xdg-open index.html       # Linux
start index.html          # Windows
```

### 🎮 Navegación:
- **Sidebar:** Clic en cualquier capítulo
- **Botones:** "← Anterior" / "Siguiente →"
- **Teclado:** Flechas ← y →
- **Tema:** Botón 🌙/☀️ arriba a la derecha

### 📱 Móvil:
- Botón de menú flotante (☰)
- Swipe gestures
- Diseño responsive

### 🎯 Mejor para:
- Experiencia de lectura óptima
- Seguimiento de progreso
- Estudio interactivo
- Presentaciones

---

## 📊 Comparación Rápida

| Característica | README.md | docs/ | HTML |
|----------------|-----------|-------|------|
| **Velocidad de acceso** | ⚡ Inmediata | ⚡ Inmediata | 🌐 Requiere servidor |
| **Interactividad** | ❌ No | ❌ No | ✅ Sí |
| **Búsqueda** | ✅ Ctrl+F | ✅ Ctrl+F | ✅ Navegación |
| **Offline** | ✅ Sí | ✅ Sí | ✅ Sí (con servidor) |
| **Progreso guardado** | ❌ Manual | ❌ Manual | ✅ Automático |
| **Estética** | 📝 Texto | 📝 Texto | 🎨 Diseño moderno |
| **Impresión** | ✅ Fácil | ✅ Fácil | ⚠️ Complicado |

---

## 💡 Recomendación Personal

### Para estudio diario:
👉 **Usa el HTML interactivo** (`html/index.html`)

### Para revisión rápida:
👉 **Usa el README.md**

### Para profundizar:
👉 **Usa las guías en docs/**

---

## 🗂️ Estructura del Proyecto

```
cpp_course/
│
├── README.md                    # 📘 Libro completo en un archivo
│
├── docs/                        # 📚 Guías detalladas
│   ├── README.md
│   ├── 01-tipos-datos.md
│   ├── 02-control-flujo.md
│   ├── 03-funciones.md
│   └── 04-cpp-moderno.md
│
├── html/                        # 🌐 Libro interactivo
│   ├── index.html              # ← ABRE ESTE
│   ├── assets/
│   │   ├── styles.css
│   │   └── app.js
│   ├── chapters/
│   │   ├── ch01.html
│   │   ├── ch02.html
│   │   └── ...
│   └── README.md
│
├── Chapter1/                    # 💻 Tu código
│   └── Main.cc
│
└── Chapter2/                    # 💻 Tu código
    ├── integers_float.cc
    ├── enum.cc
    └── ...
```

---

## 🎓 Flujo de Estudio Recomendado

### Día a día:
1. **Abre `html/index.html`** en tu navegador
2. Lee el capítulo del día
3. **Marca los checkboxes** a medida que aprendes
4. **Responde las preguntas** de autoevaluación
5. **Abre el código** correspondiente en tu editor
6. **Prueba los ejemplos** compilando y ejecutando

### Para repasar:
1. Abre `README.md`
2. Lee los "Resumen rápido" de cada capítulo
3. Revisa las "Preguntas para repasar"

### Para profundizar:
1. Abre las guías en `docs/`
2. Lee las secciones avanzadas
3. Haz los ejercicios prácticos

---

## 🔧 Personalizaci ón

### Cambiar colores del HTML:
Edita `html/assets/styles.css`:
```css
:root {
    --accent: #5b67ea;     /* Tu color favorito */
    --bg-primary: #fafbfc; /* Color de fondo */
}
```

### Agregar más capítulos:
1. Copia `html/chapters/ch01.html`
2. Renombra a `ch15.html`, `ch16.html`, etc.
3. Edita el contenido
4. Agrega al menú en `html/index.html`

---

## 🆘 Solución de Problemas

### El HTML no carga los estilos:
```bash
# Asegúrate de usar un servidor local:
cd html
python3 -m http.server 8000
```

### Los checkboxes no se guardan:
- Verifica que localStorage esté habilitado
- No uses modo incógnito

### Los capítulos están vacíos:
- Los capítulos 3-14 son plantillas
- Puedes completarlos copiando del README.md
- O simplemente usa el README.md y docs/

---

## ⭐ Ventajas de esta Estructura

✅ **Flexibilidad** - Elige la forma que prefieras
✅ **Sin duplicación** - El contenido está sincronizado
✅ **Mantenible** - Fácil de actualizar
✅ **Escalable** - Agrega capítulos cuando quieras
✅ **Profesional** - Documentación de calidad

---

**¡Disfruta aprendiendo C++!** 🚀

> **Tip:** Empieza con `html/index.html` para la mejor experiencia
