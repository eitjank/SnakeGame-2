# SnakeGame 2
Console snake game (version 2)

Fixed screen updating glitch, added colors and other improvements.

Made from [version 1](https://github.com/eitjank/SnakeGame)


# Game objective
Control the snake (with WASD), avoid hitting your snake tail and eat as many fruit as you can (fruit are represented as red blocks). Each fruit gives 10 score points.
 
# Game screenshot
![image](https://user-images.githubusercontent.com/70910743/163727825-318264e6-fd00-4991-99ab-5a08f3e2cbb3.png)

# Game modes
* With walls (by default)
  * When you hit a wall game over
  * To switch to it uncomment line 141 and comment lines 144, 145:
    ```
    //Game with walls
    if(x > width || x <= 0 || y > height-1 || y <= 0) gameOver = true;

    //Game without walls
    //if(x >= width + 1)x = 1; else if(x <= 0)x = width - 1;
    //if(y >= height)y = 1; else if(y <= 0)y = height - 1;
    ```
* Without walls (by default)
  * When you go out of bounds you loop back on the other side
  * To switch to it uncomment lines 144,145 and comment line 141:
    ```
    //Game with walls
    //if(x > width || x <= 0 || y > height-1 || y <= 0) gameOver = true;

    //Game without walls
    if(x >= width + 1)x = 1; else if(x <= 0)x = width - 1;
    if(y >= height)y = 1; else if(y <= 0)y = height - 1;
    ```
 
 # Unfixed bugs
 * Missing gray block in top left corner
 * Fruit can spawn inside of snake tail
