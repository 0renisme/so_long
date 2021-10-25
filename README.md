You must create a small 2D game where a dolphin
escapes earth after eating some fish.  Or any hero
collects any valuables before leaving the place.

• The map will be constructed with 3 components walls, collectibles, and free space.
• The player’s goal is to collect all collectibles present on the map then escape with minimal movement.
• At every move the current number of movements must be displayed in the shell.
• The player must be able to move: up, down, left, right.
• You will use a 2D view (top-down or profile).
• The game doesn’t need to be real-time.
• player cannot move into walls.
• The program displays the image in a window and respects the following rules:
◦ The W, A, S, and D keys will be used to move the main character.
◦ Pressing ESC must close the window and quit the program cleanly.
◦ Clicking on the red cross on the window’s frame must close the window and quit the program cleanly.
◦ The use of images of the minilibX is strongly recommended.
• Your program must take as a first argument a map description file with the .ber
extension.
◦ The map must be composed of only 5 possible characters: 0 for an empty space, 1 for a wall, C for a collectible, E for map exit and P for the player’s starting position.
This is a simple valid map:

1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111

◦ The map must be closed/surrounded by walls, if not the program must return an error.
◦ Map must have at least one exit, one collectible, and one starting position.
◦ You don’t need to check if there’s a valid path in the map.
◦ The map must be rectangular.
◦ You must be able to parse any kind of map, as long as it respects the rules of the map.

