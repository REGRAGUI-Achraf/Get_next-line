# 📜 get_next_line — 42/1337 Project

> A project that challenges you to read from a file descriptor line by line, building a `fgets()`-like function entirely from scratch.

**get_next_line** is one of the most famous projects in the 42 curriculum, designed to sharpen your understanding of **file I/O**, **static variables**, **memory management**, and **buffer manipulation**.

---

## 🧩 Concept

The goal is simple (but not easy 😅):

**Write a function that returns one line at a time from a given file descriptor — every time it's called.**

Each call to:

```c
get_next_line(fd);
```

should:

- ✅ Return the next line (ending with `\n` if there is one)
- ✅ Keep track of what's been read (using a **static variable**)
- ✅ Handle different file descriptors (bonus part)

---

## 📁 Project Overview

### 🧠 Mandatory Part

You must create:

```c
char *get_next_line(int fd);
```

**It:**

- Reads from the file descriptor `fd`
- Returns the next line (including `\n`)
- Returns `NULL` when there's nothing left to read

**You also use:**

- `read()` for file reading
- `malloc()` for dynamic allocation
- `free()` to avoid memory leaks

---

### ⚡ Bonus Part

If you finish the mandatory part, add support for:

- **Multiple file descriptors at once**  
  _(e.g., you can read from `fd1` and `fd2` in parallel)_

- **Proper handling of buffers and leftover data**

---

## ⚙️ Usage

### Compilation

Compile it with:

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=42
```

or build it into a project.

### Example Code

Then use it like this:

```c
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

### 📤 Output Example

```
This is line 1
This is line 2
This is line 3
```

---

## 🧠 Key Concepts & Skills

- 📚 **File descriptors** and how they work
- 🧵 **Static variables** to keep track of leftovers
- 💾 **Efficient memory management**
- 🧱 **String manipulation** and buffer handling
- ⚙️ **System call** `read()`
- 🧠 **Edge cases** & debugging

---

## 🏫 Project Information

| Property | Value |
|----------|-------|
| 🏠 **School** | 1337 (42 Network) |
| 💻 **Language** | C |
| 🧩 **Function name** | `get_next_line` |
| 📦 **Header** | `get_next_line.h` |
| ✅ **Status** | Completed |
| 🧾 **Evaluation** | 100/100 |
| 👨‍💻 **Author** | Achraf REGRAGUI |

---

**Happy coding! 🚀**
