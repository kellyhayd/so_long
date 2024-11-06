<h1 align="center"> 🎮 So_long </h1>

<p align="center">
<img alt="Static Badge" src="https://img.shields.io/badge/42-S%C3%A3o_Paulo-orange"> <img alt="Static Badge" src="https://img.shields.io/badge/MiniLibX-required-blue"> <img alt="Static Badge" src="https://img.shields.io/badge/language-c-green">
<img alt="Static Badge" src="https://img.shields.io/badge/submitted_in-fev%2F24-orange"></p>

>This project involves creating a game where the player collects items and escapes using the shortest possible route.

<h2> ✏ About </h2>

```
A game project where the player navigates a map, collects items, and reaches the exit while
avoiding obstacles, featuring graphic management and error handling.
```

<h2> ⚙ Requirements </h2>

- The project must use the MiniLibX library, either the version available on the school machines or installed using its sources.
- A Makefile must be provided to compile the source files without relinking.
- The program must take a map description file with a .ber extension as a parameter.

<h2>  🕹️ Game Instructions </h2>

- The player's goal is to collect every collectible present on the map, then escape by choosing the shortest possible route.
- Movement: W, A, S, D keys or ZQSD or arrow keys.
- The player cannot move into walls.
- The current number of movements must be displayed in the shell after each move.
- Use a 2D view (top-down or profile).
- The game does not have to be real-time.

<h2> 🖥️ Graphic Management </h2>

- The program must display the game image in a window.
- Window management must be smooth.
- Pressing ESC or clicking the cross on the window's frame must close the window and quit the program cleanly.

<h2> 🗺️ Map </h2>

- The map consists of walls, collectibles, and free space.
- Map characters: 0 (empty space), 1 (wall), C (collectible), E (exit), P (player's starting position).
- The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
- The map must be rectangular and closed/surrounded by walls.
- Ensure a valid path in the map; otherwise, return an error.
- Parse any map respecting the above rules.
- Handle errors and display explicit error messages.

![Screen-recording-2024-11-06-07 16 04](https://github.com/user-attachments/assets/1f78102f-37cd-4139-aa16-e40e1afa5880)

  

<h2> 🌟 Bonus Part </h2>

- Extra points for implementing:
  - Player losing when touching an enemy patrol.
  - Sprite animation.
  - Displaying movement count directly on screen.
  
![so_long_bonus_2](https://github.com/user-attachments/assets/d6783359-fc38-400a-8525-f287f6a14dbc)


</markdown>

