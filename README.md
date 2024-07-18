# So_long
A Small 2d Game With a Changable Map, The Goal of the game is collecting all the collectibles in the map and finding the exit!
It is made using the Graphics Library MLX42.
## USAGE
To start the program you have to download and compile necessary files, you can do so by using:
```
$make
```
it will download the MLX42 library for you
If you don't have glfw you can use the follwoing command to instll it since its needed by the MLX42 library:
```
$make install
```
Then to run the game you can just run the excutible and you have to give it a .ber file which a map as an arguments:
```
./so_long map.ber
```
Please make sure to put any new map in the maps folder!

### MAPS
You can make up your own maps as long as it follows certain rules which are:
- The map has to be in a rectangular/square shape.
- The map can only contain these characters: 1(walls),0(Walking space),E(exit),C(collectible),P(player).
- There always should be Only one player and one exit and at least one collectibe.
- The map Has to be a solvable one, meaning the player has to be able to reach all the collectibles nd the exit.
- There can't be any openings in the map!

### CONTROLS
You can move through the map using the arrow keys!

### TEXTURES
You can change the textures for the game by replacing the existing textures(It has to be of the format .xpm42).
