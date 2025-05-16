# Advanced Casino Game in C++

## Overview

This is a console-based casino game written in C++. It features three exciting games you can play with virtual currency:

- **Vegas Slot Game [7.7.7]** — Spin the slot reels and win based on matching numbers and patterns.
- **Guess The Number** — Guess the computer’s number between 1 and 5 to double your bet.
- **Roulette** — Bet on one or more numbers and win big if the winning number matches your bets.

The game includes:

- Real-time balance tracking
- Input validation to ensure bets are within balance and valid ranges
- Randomized game outcomes using a secure random generator
- User-friendly menu interface
- Game loop allowing continuous play or quitting anytime

## Features

- Multiple casino games integrated into one program
- Dynamic betting system with winnings and losses applied to user balance
- Simple yet engaging text-based user interface
- Use of modern C++ features such as `<random>` for better randomness
- Cross-platform compatibility (tested on Windows and Linux)

## How to Run

1. Clone or download this repository.
2. Compile the source code using a C++ compiler supporting C++11 or later. For example:

   ```bash
   g++ -std=c++11 -o CasinoGame main.cpp
