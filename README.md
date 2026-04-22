# Dungeon Run

## Overview
Dungeon Run is a text-based role-playing game (RPG) developed in C++. In this game, the player progresses through a dungeon from start to finish while encountering enemies, shops, and random mystery events. The goal is to survive the journey, strengthen the character through equipment and upgrades, and successfully complete the run.

This project was originally planned as a university group assignment and demonstrates object-oriented programming, class design, inheritance, polymorphism, and basic game logic implementation in C++.

## Game Concept
The game is structured around a series of dungeon scenes. As the player moves forward, they may encounter:

- **Encounter** scenes, where the player fights one or more enemies
- **Shop** scenes, where the player can purchase equipment
- **Mystery** scenes, where random events may occur, including healing, combat, or shopping opportunities

Combat outcomes are influenced by the player’s stats, equipped items, and the strength of the enemies. Equipment and progression mechanics are designed to improve the player’s chances of surviving deeper into the dungeon. :contentReference[oaicite:1]{index=1}

## Features
- Text-based dungeon progression system
- Turn-based enemy encounters
- Shop system with purchasable equipment
- Mystery events with random outcomes
- Player stat system including health, strength, and speed
- Enemy system with both normal enemies and boss enemies
- Equipment system with different effect types
- Session tracking through a run-based structure
- Input validation and planned testing for safer gameplay experience :contentReference[oaicite:2]{index=2}

## Object-Oriented Design
This project was designed using an object-oriented approach with multiple related classes.

### Main Classes
- **Run**: tracks the current game session, including score, scenes, and player progress
- **Scene**: base class for the different types of scenes in the dungeon
- **Encounter**: combat scene involving enemies
- **Shop**: allows the player to purchase equipment
- **Mystery**: triggers a random event such as healing, combat, or a shop
- **Character**: base class for all living entities
- **Player**: the main controllable character
- **Enemy**: base class for enemies
- **Boss**: stronger enemy type
- **Equipment**: base class for items that improve the player
- **ContinuousEquipment**, **AfterBattleEquipment**, **ConditionalEquipment**: different equipment effect types :contentReference[oaicite:3]{index=3}

### Design Principles Used
- **Inheritance** for extending base classes such as `Scene`, `Character`, and `Equipment`
- **Polymorphism** through virtual functions like `execute()` and `doAttack()`
- **Composition and aggregation** to model relationships between runs, scenes, enemies, and equipment
- **Encapsulation** for managing character stats and equipment safely within classes :contentReference[oaicite:4]{index=4}

## My Contribution
This project was completed as part of a group assignment. My responsibilities included contributing to the implementation and testing of core gameplay systems, particularly around character-related functionality and debugging.

Based on the project plan, I contributed to:
- implementation of derived character classes
- debugging and testing of the game
- collaborative development of the gameplay structure with teammates

This project helped me strengthen my understanding of collaborative software development and applying object-oriented programming concepts in a larger program structure. :contentReference[oaicite:5]{index=5}

## User Interaction
Dungeon Run uses a simple text-based interface that guides the player through the game using prompts and menu selections.

Examples of user interactions include:
- starting the game
- viewing player stats
- choosing actions during combat
- purchasing equipment in the shop
- responding to mystery events
- re-entering input if an invalid command is entered

The interaction design focuses on clarity and ease of use, with prompts and feedback shown throughout the game. :contentReference[oaicite:6]{index=6}

## Testing and Debugging
The project plan included both unit testing and input/output testing to improve reliability.

Planned testing approaches included:
- testing each function individually
- checking unexpected or invalid input cases
- validating edge cases such as large values
- using input validation to prevent incorrect commands
- applying safe coding practices such as null pointer handling with `nullptr`

The project also planned to use a Makefile and README to provide clear instructions for compiling, running, and testing the program. :contentReference[oaicite:7]{index=7}

## Technologies Used
- **C++**
- **Object-Oriented Programming**
- **Makefile**
- **Command-line / terminal-based interface**
- **Unit testing and debugging practices**

## How to Compile and Run
run the following commands in the terminal:

```bash
make