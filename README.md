# CFS23SaveTool
**Tool for decrypting/encrypting save files** (`gamesaves.cfs23`) for Car For Sale Simulator 2023.

## Features
- 🔓 **Two-way conversion**: Auto-detects and processes both encrypted and decrypted saves
- 🔑 **Game-compatible encryption**: Uses the exact same XOR cipher as the original game
- 🛡️ **Safe modifications**: Preserves all file structure and metadata
- 💻 **CLI & Interactive modes**: Flexible usage for all user levels

## Installation
1. Download the latest release
2. Or compile from source:
   ```powershell
   cl /EHsc /std:c++17 /Fe:CFS23_SaveTool.exe main.cpp
