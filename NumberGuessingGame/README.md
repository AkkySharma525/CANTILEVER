# 🎯 Number Guessing Game – C++

A simple and interactive console-based game written in **C++** where the user tries to guess a randomly generated number within limited attempts.

---

## 📌 Features

- 🔢 Random number generation
- 🎚️ Three difficulty levels:
  - **Easy (E)** → Guess between 1–20
  - **Medium (M)** → Guess between 1–40
  - **Hard (H)** → Guess between 1–60
- 🔁 5 attempts per game
- ❌ Option to quit anytime by entering `0`
- 💡 Optional smart hint system (like binary search logic)
- ✅ Replay support

---

## 🧠 Hint System

After selecting difficulty, you’re asked:
> 💡 Press `T` if you want a hint before you start guessing.

If you press `T`, a smart strategy hint is shown:
> 🧠 _Hint_: Try guessing somewhere in the middle... then narrow it down like a pro.  
> (It's like cutting the range in half — over and over 😉)

---

## ⚙️ How to Compile and Run

### 🔸 Windows

Open terminal inside the `NumberGuessingGame` folder and run:

```bash
g++ main.cpp -o game
game
