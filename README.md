# SlayViber

A C++ class that models a user of a made-up short-video app called SlayVibe: registration, profile visits, followers, livestreams and restrictions. Written for a university assignment.

Method names and console messages are partly Georgian written in Latin letters.

## What it does

- **Guests and registered users.** The default constructor makes an unregistered guest with a generated name such as `user 4821`. The other constructor takes a username, a password and, optionally, a follower count and a restriction flag.
- **Unique usernames.** Every username is kept in a list shared by all objects. A constructor call with a taken name prints a warning and gives the user a generated name instead.
- **Visit.** `visit(other)` adds the visitor's username to the other user's visitor list. A registered, unrestricted visitor is then asked `y/n` whether to follow, and `y` adds one follower.
- **Registration.** `registracia()` asks a guest for a username of at least 3 characters that is not taken and a password of at least 4 characters, and repeats each question until the answer is valid.
- **Go live.** `goLive()` flips a coin: followers grow by 5 to 40 percent or fall by 0 to 30 percent. A fall of more than 25 percent puts a restriction on the account. Guests and restricted users cannot go live.
- **Collaboration.** `kolaboracia(partner)` gives each of two registered, unrestricted users 2 to 12 percent of the other's follower count and adds each to the other's visitor list.

## How it works

Everything is in one class, `SlayViber`. Its fields are the username, the password, the follower count, the visitor list and three flags: `streaming`, `isRegistered` and `hasShezgudva` (has a restriction).

The taken usernames are in a static `vector<string>`, and the random numbers come from one static `mt19937` seeded with the current time, so follower changes differ from run to run. Percentage changes are rounded to the nearest whole follower and the count never goes below zero.

`goLive()` sets `streaming` to true, applies the follower change and sets it back to false before it returns, so a livestream starts and ends inside one call. `setShezgudva(true)` also turns `streaming` off. `visit` and `kolaboracia` refuse to act on the same object, and a guest or restricted visitor is still recorded as a visitor but is not offered the follow question.

`print()` writes the username, the two status flags, the follower count, the streaming flag and the visitor list. The getters and `setFollowers`, `setStreaming` and `setShezgudva` are defined in the header.

## Example

Shortened from `driver.cpp`:

```cpp
SlayViber stumari;                     // guest with a generated username
SlayViber nia("nia", "nia123", 2005);
SlayViber ani("ani", "ani123", 2020);

stumari.visit(nia);                    // recorded as a visitor, cannot follow
nia.goLive();                          // random follower change
nia.kolaboracia(ani);                  // both gain followers

ani.setShezgudva(true);
ani.goLive();                          // refused, the account is restricted

nia.print();
```

`driver.cpp` runs without keyboard input. It does not call `registracia()`, and the only visits it makes are by a guest and by a user visiting themselves, neither of which reaches the follow question.

## Build and run

The repository is a Visual Studio solution: open `SlayViber.sln` and run it. With g++:

```
g++ -std=c++17 SlayViber/SlayViber.cpp SlayViber/driver.cpp -o slayviber
./slayviber
```
