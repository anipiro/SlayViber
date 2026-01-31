# SlayViber (SlayVibe) — User Simulation Model (OOP)

## 📌 Overview

**SlayViber** is a C++ OOP simulation project inspired by the rise of social video platforms during the COVID era (e.g., TikTok).
Instead of building a full platform, this project models the **core user behavior** of a fictional app called **SlayVibe** using a `SlayViber` class and a **driver program** (`driver.cpp`) to test and demonstrate functionality.

The simulation supports:

* registered vs. unregistered users
* visiting profiles and tracking visitors
* subscribing/following behavior
* going live with randomized follower changes
* automatic restrictions when suspicious activity is detected

---

## 🎯 Project Goals

* Implement a full-featured **User class** (`SlayViber`)
* Apply **OOP principles**: constructors, encapsulation, const-correctness, getters/setters
* Create a **driver** that tests every method with clear console output
* Model a “live streaming” event with random outcomes and rule-based restrictions

---

## 🧱 Class: `SlayViber`

### Member Variables

* `std::string username`
* `std::string password`
* `bool streaming`
* `int followers`
* `bool isRegistered`
* `bool hasRestriction`
* `std::vector<std::string> visitors` *(any container is allowed)*

---

## 🛠️ Core Features (Member Functions)

### ✅ Constructors

* **Default Constructor**

  * Creates an **unregistered** user (viewer-only).
  * Has a default/generated username (example: `user4352123412`)
  * No password, cannot subscribe, etc.

* **Parameterized Constructor**

  * Sets `username`, `password`
  * Optional/default values:

    * `followers = 0`
    * `hasRestriction = false`

---

### 🖨️ `print()`

Displays user information in a clean, organized format:

* username, followers, registration status
* streaming status
* restriction status
* recent visitors (optional)

---

### 👀 `visit(otherUser)`

A user visits another user's profile.

Behavior:

* Shows **limited info** about the visited user *(restriction format is your design)*
* Adds the visitor’s username to `otherUser.visitors`
* Visitor chooses whether to **subscribe/follow** the visited user

  * If yes → visited user’s `followers` increases

---

### 📝 `registration()`

Interactive registration method for unregistered users:

* prompts user for username/password
* handles invalid input (e.g., username already taken)
* changes:

  * `isRegistered = true`
  * sets valid `username`, `password`

---

### 🔴 `goLive()`

Starts a livestream session (if allowed):

* sets `streaming = true`
* randomly changes followers:

  * **increase** by **5%–40%**
  * OR **decrease** by **0%–30%**
* if followers drop by **more than 25%**:

  * `hasRestriction = true`
  * `streaming = false`

❗ Rule: if `hasRestriction == true`, `goLive()` must **fail safely** (do nothing + print explanation).

---

### ⭐ Custom Function (Student-Designed)

You must implement **one extra function** with:

* your own idea + logic
* must affect **at least 2 member variables**

Examples (choose one concept):

* `resetPasswordAndRestrict()` → changes password + restriction
* `banForSpam()` → restriction + registration state + streaming off
* `boostProfile()` → followers increase + streaming on/off toggle
  *(Your final choice is up to your implementation.)*

---

## ✅ Input Handling Requirements

During interactive input, ensure:

* usernames are unique
* empty/invalid input is rejected
* restricted users can’t perform forbidden actions
* subscription is not allowed if visitor is unregistered (recommended rule)

---

## 🧪 Testing (Driver Program)

The file `driver.cpp` must:

* create multiple `SlayViber` objects (registered + unregistered)
* call **every single member function**
* print step-by-step what happens:

  * before/after state changes
  * follower counts change
  * restriction triggers
  * visitor logs update

A good driver prints messages like:

* “User A visits User B”
* “User A subscribed / did not subscribe”
* “User B went live → followers +18%”
* “Restriction applied → streaming stopped”

---

## 📂 Suggested Project Structure

```
SlayViber/
│
├── SlayViber.h
├── SlayViber.cpp
├── driver.cpp
└── README.md
```

---

## 🧠 Concepts Demonstrated

* OOP class design
* constructors (default + parameterized)
* encapsulation (getters/setters)
* const-correctness
* vectors/containers
* input validation (interactive mode)
* randomness in simulation logic
* rule-based state transitions (restriction/live logic)

---
