# 🧵 Seam Carving Image Resizer (C++)

A content-aware image resizing tool built in C++. This project implements the seam carving technique to intelligently shrink images by removing the least visually significant vertical and horizontal paths — preserving key visual features better than traditional scaling or cropping.

---

## ✨ Features

- 📥 Loads and validates `.ppm` (Portable Pixmap) image files
- 🧮 Calculates pixel "energy" using the dual-gradient energy function
- 🔎 Identifies seams (paths of least visual importance)
- ✂️ Removes low-energy vertical and horizontal seams to reduce dimensions
- 🧼 Handles edge cases and provides exception-based error handling
- 💾 Outputs a resized `.ppm` image that preserves important content

---

## 🧠 How It Works

The seam carving algorithm works in three main steps:

1. **Energy Calculation** – Computes each pixel's "energy" based on surrounding color gradients
2. **Seam Identification** – Greedily finds a path of adjacent pixels with the lowest total energy
3. **Seam Removal** – Removes that path, effectively shrinking the image without noticeable distortion

### Why Seam Carving?
Unlike cropping or resizing, seam carving avoids shrinking or cutting out important visual content by identifying and preserving high-energy regions in the image.

---
File Structure
.
├── Fishing40X27.ppm               # Example output PPM file (resized)
├── FishingNeg175X117.ppm         # Example output PPM file (invalid size case)
├── functions.cpp                 # Core image processing logic (Part 1)
├── functions.h                   # Function declarations and Pixel struct
├── seamcarving.cpp              # Main driver: loads image, handles input/output
├── seamcarving                  # Compiled binary (after build)
├── pictures/                    # Sample input PPM images
│   ├── Fishing1080X720.ppm
│   ├── Fishing175X117.ppm
│   ├── HJoceanSmall507X285.ppm
│   ├── blocks38X36.ppm
│   ├── sunset1080X673.ppm
│   └── sunset200X125.ppm
├── seamcavingpt2/               # Part 2 code (seam identification and removal)
│   ├── functions.cpp            # Implements seam finding/removal
│   ├── functions.h              # Shared declarations for Part 2
│   ├── metadata.yml             # Autograder or project metadata (if applicable)
│   └── seamcarving.cpp          # Updated main file for Part 2


## 🧪 Sample Workflow

```bash
# Compile the project
g++ -std=c++17 -Wall -Wextra -pedantic-errors *.cpp -o seamcarving

# Run the program
./seamcarving

# Input prompts:
# 1. Path to a .ppm file
# 2. Target width and height
