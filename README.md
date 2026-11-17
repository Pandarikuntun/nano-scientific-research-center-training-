# Nano Scientific Research Center (NSRC) — Embedded Systems Training

Welcome to my **Embedded Systems & Linux Training Repository**. This repository contains all the **C, C++, Linux, Python, and Microcontroller** programs, along with virtual hardware simulations, that I practiced and built during my hands-on training at the **Nano Scientific Research Center (NSRC)**.

---

## 🛠️ Tools & Software Stack

| Tool / Environment | Purpose & Hardware Target |
| :--- | :--- |
| **Linux (Ubuntu / Terminal & GCC)** | Linux CLI commands, shell scripting, file permissions, process management, and `gcc`/`g++` compilation |
| **Keil µVision** | Embedded C programming & `.hex` generation for **8051** microcontrollers |
| **STM32CubeIDE** | Firmware development & peripheral configuration for **STM32** (ARM Cortex-M) |
| **Arduino IDE** | Rapid prototyping, sensor integration, and C/C++ sketches for **Arduino** |
| **Proteus Design Suite** | Circuit schematic design and real-time virtual hardware simulation |
| **Dev-C++** | Core **C** and **C++** programming practice on Windows |
| **Python** | Scripting, logic building, and automation fundamentals |

---

## 📂 Repository Folders Overview

* **`linux/`** — Linux environment practice including essential terminal commands, file system navigation, permissions (`chmod`/`chown`), Bash shell scripting, and compiling C/C++ programs via `gcc`/`g++`.
* **`C-language/`** — Core C programs covering loops, arrays, functions, structures, pointers, memory allocation, and bitwise operations.
* **`C++ -language/`** — Object-Oriented Programming (OOP) concepts, classes, constructors, inheritance, and polymorphism practiced in Dev-C++ and Linux.
* **`microcontrollers/`** — Bare-metal and HAL-based firmware written in **Keil µVision (8051)** and **STM32CubeIDE**, including:
  * **GPIO Control:** LED patterns, push-button switches, relays, and TRIAC interfacing
  * **Display Interfacing:** 16x2 Alphanumeric LCD, single & 4-digit 7-segment displays
  * **Input & Actuators:** 4x4 Matrix Keypad, DC Motor control, square wave generation
  * **Peripherals & Protocols:** Hardware Timers, External Interrupts, UART serial communication
* **`arduino/`** — Embedded C/C++ projects for sensor reading, actuator control, and serial monitoring.
* **`proteus projects/`** — Virtual circuit diagrams and simulation files used to test and debug microcontroller code.
* **`python/`** — Python fundamentals and logic practice scripts.
* **`workers world prject pages/`** — Supporting project web pages and documentation.

---

## 🚀 How to Run These Projects

1. **Linux & Shell Scripts (`linux/`):** Open a Linux terminal (or WSL), grant execute permission using `chmod +x script.sh`, and run `./script.sh`. Compile C/C++ files using `gcc filename.c -o output && ./output`.
2. **8051 Projects (`microcontrollers/keil(8051)`):** Open the `.c` source files in **Keil µVision**, compile to generate the `.hex` file, and load it into an 8051 microcontroller in **Proteus** or physical hardware.
3. **STM32 Projects:** Import the project folder into **STM32CubeIDE**, build the binary, and flash via ST-Link or simulate.
4. **C / C++ Programs:** Open any `.c` or `.cpp` file in **Dev-C++** (Windows) or compile with `gcc`/`g++` on Linux.
5. **Simulations (`proteus projects/`):** Open the `.DSN` / `.pdsprj` files in **Proteus Design Suite**, attach the compiled `.hex` file to the microcontroller, and click **Play**.

---

## 📌 GitHub Repository About Section (Quick Copy)
> *Practiced C, C++, Linux, Python, and Embedded Systems code (8051, STM32, Arduino) using Linux GCC, Keil µVision, STM32CubeIDE, Dev-C++, and Proteus during NSRC training.*
