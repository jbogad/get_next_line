# Get_Next_Line 📜

Welcome to my sleek and efficient `get_next_line` function! Crafted as part of the 42 Madrid journey, this project is all about reading files line by line with finesse.

---

## 🌟 Overview

`get_next_line` is a custom C function that reads a line from a file descriptor and returns it to you, one at a time. It’s like a librarian handing you a single page from a book whenever you ask—perfect for parsing files without overwhelming your memory.

---

## ⚙️ How It Works

Here’s the magic behind my implementation:

| Component       | What It Does                                          |
|-----------------|-------------------------------------------------------|
| Line Reader     | Grabs text up to a newline (`\n`) or end of file.     |
| Buffer Wizard   | Manages a `BUFFER_SIZE` chunk for smooth reading.     |
| Memory Keeper   | Uses a static variable to hold leftover data.         |
| Leak Protector  | Frees memory!                |

---

## 🗺️ Roadmap

[Start] ---> [Open FD] ---> [Read Buffer] ---> [Find \n] ---> [Return Line] ---> [Repeat]

- **Step 1**: Open your file descriptor.
- **Step 2**: Read a chunk into the buffer.
- **Step 3**: Spot that precious `\n`.
- **Step 4**: Deliver the line, save the rest.

---
📂 **File Content**: "Hello\nWorld\n42"<br>
📖 **Buffer Reads**: "Hello\nWor"<br>
✂️ **Line Output**: "Hello"<br>
💾 **Static Stash**: "Wor"<br>
🔄 **Next Call**: "World"
