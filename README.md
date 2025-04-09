
# Seam Carving Image Resizer (C++)

A content-aware image resizer built in C++ using the seam carving technique. This tool intelligently removes the least important vertical and horizontal pixel seams from an image, preserving key visual content and avoiding distortion caused by traditional scaling methods.

## ✨ Features

- ✅ Loads and validates `.ppm` (Portable Pixmap) image files
- 🧮 Calculates pixel "energy" using a dual-gradient energy function
- 🔎 Identifies vertical and horizontal seams with minimum energy
- ✂️ Removes low-energy seams to shrink image dimensions
- 💾 Outputs resized `.ppm` image files with preserved visual quality
- ⚙️ Implements exception handling and robust stream state checks

## 📷 How It Works

Seam carving resizes images by iteratively removing connected paths (seams) of least "importance." Pixel importance is determined using an energy function, which measures the color difference between neighboring pixels. Low-energy seams are unlikely to impact the image visually.

Steps:
1. **Load Image** – Parses `.ppm` image files into a 2D array of pixels
2. **Compute Energy** – Calculates the energy of each pixel based on color gradients
3. **Find Minimum Seam** – Greedy algorithm walks top-down (or left-right) to find the lowest energy seam
4. **Remove Seam** – Removes the seam and updates the image dimensions
5. **Output Image** – Saves the resized image as a valid `.ppm` file

## 📁 File Structure

