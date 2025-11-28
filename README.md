## 🔍 Lexical Analyzer in C

### 🧩 Project Overview

The **Lexical Analyzer Project** is a C-based application that performs **tokenization of C source code** — the first phase of a compiler’s front-end. It scans a `.c` file and extracts meaningful **tokens** such as keywords, identifiers, numeric constants, operators, symbols, string literals, and character constants. This project demonstrates **state-based scanning**, **character classification**, and **token recognition** using C, making it ideal for compiler design learning.

---

### 🚀 Features

* 🔑 Identifies all **32 C keywords**
* 🆔 Detects **identifiers** and validates naming rules
* 🔢 Supports **integer & float constants**
* ➕ Recognizes **operators** (arithmetic, relational, logical, increment/decrement, etc.)
* 🔣 Handles **symbols** like `{ } ( ) ; ,`
* 🧵 Extracts **string literals**
* ✴️ Reads **character constants**
* 🧽 Skips whitespace and special characters
* 🖥️ Simple command-line interface (CLI) for usage

---

### ⚙️ Technologies Used

* **Language:** C
* **Concepts:** Compiler design, tokenization, state-based scanning, file handling
* **Platform:** Linux / Windows (GCC Compiler)

---

### 📚 Learning Outcomes

* Understanding **lexical analysis** in compiler design
* Implementing **tokenization logic** in C
* Working with **file I/O**, **character streams**, and **buffer handling**
* Building a foundation for later compiler stages like parsing & syntax analysis

---

### 🧪 Example Usage

```bash
# Compile
gcc lexical.c -o lexer

# Run with input file
./lexer sample.c
```

---

### 🧰 Project Structure

```
├── lexical.c        # Main lexical analysis logic
├── tokenizer.c      # (Optional) Token scanning functions
├── main.c           # Entry point
├── main.h           # Structure definitions & declarations
├── sample.c         # Test input file
└── README.md        # Documentation
```

---

### 📄 Future Enhancements

* Add **token table output** as a CSV or JSON
* Include **line number tracking** for better debugging
* Implement **comment handling** (single & multi-line)
* Extend support for **preprocessor directives**
* Build a **mini-compiler front-end** with parser integration


