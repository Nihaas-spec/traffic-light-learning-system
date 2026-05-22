# Traffic Light Learning & Assessment System

A console-based C++ application that teaches users about traffic signals and road safety rules, then tests their knowledge through an interactive quiz with dynamic question management.

**Course:** Programming Fundamentals — 1st Semester  
**Language:** C++

---

## Features

| Feature | Description |
|---|---|
| **Learn Module** | Covers traffic light phases, road safety tips, and custom admin instructions |
| **Admin Panel** | Add, delete, and view quiz questions dynamically at runtime |
| **Quiz Engine** | Randomised question order, configurable number of questions per attempt |
| **Score History** | Tracks up to 10 quiz attempts per session |
| **Input Validation** | All user inputs are validated with clear, helpful error messages |

---

## Demo

```
=== Traffic Light Learning & Assessment System ===
1. Admin Panel
2. User Panel
3. Learn About Traffic Signals
4. Exit
Enter your choice: 3

--- Learn About Traffic Signals ---

Traffic Light Phases:
  1. Red    : Stop
  2. Yellow : Prepare to stop
  3. Green  : Go

--- Road Safety Tips ---
  - Always follow traffic signals to ensure safety.
  - Use zebra crossings for safe pedestrian crossings.
  - Make way for emergency vehicles by moving to the side.
  ...
```

```
--- User Panel ---
1. Take Quiz
2. View Quiz History
3. Exit to Main Menu
Enter your choice: 1

Enter the number of questions you want to attempt (1-5): 3

Question 1: What should you do when the light is red?
  1. Go
  2. Stop
  3. Slow Down
Enter your answer (1-3): 2
Correct!

Your final score: 3/3
```

---

## Getting Started

### Prerequisites
- A C++ compiler that supports C++11 or later (GCC, Clang, MSVC)

### Compile & Run

```bash
# Clone the repository
git clone https://github.com/YOUR_USERNAME/traffic-light-learning-system.git
cd traffic-light-learning-system

# Compile
g++ -std=c++11 -o traffic_quiz src/main.cpp

# Run
./traffic_quiz
```

On Windows (MinGW):
```bash
g++ -std=c++11 -o traffic_quiz.exe src/main.cpp
traffic_quiz.exe
```

---

## Project Structure

```
traffic-light-learning-system/
├── src/
│   └── main.cpp          # Full application source
├── docs/
│   └── report.md         # ICT Lab report — problem statement, methodology, results
├── screenshots/          # Sample output screenshots
└── README.md
```

---

## How It Works

The program is structured around three independent modules:

**1. Learn Module**  
Displays traffic light meanings and road safety rules. An admin can append custom instructions that appear here at runtime.

**2. Admin Panel**  
Allows a privileged user to add new quiz questions (with up to 3 options each), delete existing ones, view the full question bank, and add extra learning instructions — all without recompiling.

**3. Quiz Engine**  
Fetches questions from the bank, applies a Fisher-Yates partial shuffle to randomise order, presents the chosen number of questions, gives immediate right/wrong feedback, and saves the result to the session history.

---

## Concepts Demonstrated

- Arrays and multi-dimensional arrays
- Functions and modular program design
- Input validation with `cin.fail()` and stream recovery
- String handling with `getline`
- Random number generation (`rand`, `srand`)
- Loops, switch statements, and menu-driven architecture

---

## Authors

| Name | Student ID |
|---|---|
| M. Nihaas Bhatti | F2024266196 |
| Hafiz M. Ibrahim | F2024266162 |

---

## Acknowledgements

Submitted to **Miss Jaweria Amir** — ICT Lab, V4
