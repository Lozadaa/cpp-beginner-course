# Code Snippets Extraction Report

## Summary
All code snippets have been successfully extracted from chapter files (capitulo-01.astro through capitulo-11.astro) into separate .js files.

## Statistics
- **Total code snippet files created:** 180
- **Total chapters processed:** 11
- **All parsing errors eliminated:** ✅

## Files Created Per Chapter

### Chapter 1 (Fundamentos)
- Files: 6
- Examples: helloWorldCode, mainVariants, namespaceExample, usingNamespace, compilationStages, memoryLayout

### Chapter 2 (Tipos de Datos Primitivos)
- Files: 19
- Examples: byteAnatomyCode, bitValuesCode, fixedSizeTypesCode, signedVsUnsignedCode, overflowCode, floatBasicCode, ieee754Code, and more

### Chapter 3 (Tipos de Datos)
- Files: 17
- Examples: Various code blocks and data type demonstrations

### Chapter 4 (Enumeraciones)
- Files: 14
- Examples: Enumerations and switch statements

### Chapter 5 (Estructuras de Control)
- Files: 15
- Examples: ifElseCode, forLoopCode, whileLoopCode, breakContinueCode, rangeBasedForCode, and more

### Chapter 6 (Arrays y Punteros)
- Files: 20
- Examples: arrayBasicCode, pointerBasicCode, pointerArithmeticCode, stackVsHeapCode, vtableIntroCode, and more

### Chapter 7 (Strings y Manejo de Memoria)
- Files: 19
- Examples: cStringCode, stdStringCode, dynamicMemoryCode, raiiIntroCode, uniquePtrCode, sharedPtrCode, and more

### Chapter 8 (Funciones)
- Files: 28
- Examples: functionBasicCode, passByValueCode, passByReferenceCode, recursionCode, stackFrameCode, lambdaIntroCode, and more

### Chapter 9 (Structs y Clases)
- Files: 13
- Examples: structBasicCode, classBasicCode, constructorCode, destructorCode, thisPointerCode, staticMembersCode, and more

### Chapter 10 (Templates Básicos)
- Files: 14
- Examples: functionTemplateCode, classTemplateCode, vectorCode, mapCode, setCode, iteratorCode, algorithmCode, and more

### Chapter 11 (C++ Moderno)
- Files: 15
- Examples: autoCode, rangeForCode, nullptrCode, smartPointersCode, lambdaCode, constexprCode, optionalCode, variantCode, and more

## File Structure

### Original Structure (BEFORE)
```
html/src/pages/
├── capitulo-01.astro  (contained inline code with const variables)
├── capitulo-02.astro  (contained inline code with const variables)
├── ...
└── capitulo-11.astro  (contained inline code with const variables)
```

### New Structure (AFTER)
```
html/src/
├── pages/
│   ├── capitulo-01.astro  (imports code from code-snippets/)
│   ├── capitulo-02.astro  (imports code from code-snippets/)
│   ├── ...
│   └── capitulo-11.astro  (imports code from code-snippets/)
└── code-snippets/
    ├── cap01-helloWorldCode.js
    ├── cap01-mainVariants.js
    ├── cap02-byteAnatomyCode.js
    ├── cap02-floatBasicCode.js
    ├── ... (180 total files)
    └── cap11-variantCode.js
```

## Changes Made

### 1. Created Individual .js Files
Each code variable from the chapter files was extracted into its own .js file with the naming pattern:
```
cap{XX}-{variableName}.js
```

Example:
```javascript
// cap05-ifElseCode.js
export default `#include <iostream>

int main() {
    int age = 25;
    
    if (age >= 18) {
        std::cout << "Eres mayor de edad\n";
    } else {
        std::cout << "Eres menor de edad\n";
    }
    
    return 0;
}`;
```

### 2. Updated Chapter Files
Each chapter file's frontmatter was updated to:
- Remove all `const variableName = \`...\`;` declarations
- Add import statements for each code snippet

Example transformation:
```astro
// BEFORE
---
import ChapterLayout from '../layouts/ChapterLayout.astro';
import Code from '../components/Code.astro';

const ifElseCode = `#include <iostream>
...
`;
---

// AFTER
---
import ChapterLayout from '../layouts/ChapterLayout.astro';
import Code from '../components/Code.astro';
import ifElseCode from '../code-snippets/cap05-ifElseCode.js';
---
```

### 3. Preserved All Content
- All code content was preserved exactly as-is
- All emojis (❌, ✅, etc.) were kept intact
- All special characters and formatting maintained
- No modifications to the actual code examples

## Benefits

### 1. Parsing Error Elimination
- **Before:** Special characters in code (like emojis, backticks, Unicode) caused Astro parsing errors
- **After:** All code is in separate .js files, completely eliminating parsing issues

### 2. Improved Maintainability
- Each code snippet is now in its own file
- Easier to find and edit specific code examples
- Better version control (smaller diffs, easier to track changes)
- Can be reused across multiple chapters if needed

### 3. Better Organization
- Clear separation between content and code
- Standardized naming convention (cap{XX}-{name}.js)
- All code snippets in one dedicated directory

### 4. Performance
- Astro can process the simpler chapter files faster
- Code files can be cached and optimized separately

## Verification

All chapters verified to have:
- ✅ Zero remaining `const` declarations with backticks
- ✅ All imports properly added
- ✅ All code snippets extracted
- ✅ No parsing errors

## Files Modified
- 11 chapter files (capitulo-01.astro through capitulo-11.astro)
- 180 new code snippet files created
- 1 extraction script created (extract_code_snippets.py)

## Automation Script
A Python script was created to automate this process:
- Location: `/Users/user/courses/cpp_course/extract_code_snippets.py`
- Processes all chapters automatically
- Generates detailed summary reports
- Can be reused for future code extractions

## Date Completed
December 8, 2025

---
**Result:** All code snippets successfully extracted. Zero parsing errors remaining.
