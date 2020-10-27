# flappy_bird

A Flappy Bird recreation implemented in C and SDL2 graphics library.

Requires SDL2 and SDL_image installed in ~/.brew. To run do `make run` or `make re` then run `./flappy_bird`. Controls are tapping spacebar. you can configure [window_config.h](https://github.com/ASSERT-game/flappy_bird/blob/master/includes/window_config.h) to change the speed of the game. I
made all the assets using the pixel editor [aseprite](https://www.aseprite.org/), they can be found in this [texture map](https://github.com/ASSERT-game/flappy_bird/blob/master/resources/flappy_bird.png) and the numbers [font](https://github.com/ASSERT-game/flappy_bird/blob/master/resources/pixel_numbers_white.png).

<br>
<img height="500" src="https://github.com/ASSERT-game/flappy_bird/blob/master/resources/cookie.gif" />
<br>

This project was made to get a feel for simple collisions, a realtime game, and the SDL2.0 Library. This was made after programing [Chess](https://github.com/ASSERT-game/chess) and [Tic Tac Toe](https://github.com/ASSERT-game/tic_tac_toe). Sprite rotation was made possible through the use of [SDL_RenderCopyEx](https://wiki.libsdl.org/SDL_RenderCopyEx) function provided by SDL2.0, and special thanks to [SDL_HasIntersection](https://wiki.libsdl.org/SDL_HasIntersection). Based on the git history this took three days to make. This was thanks to the previous projects and having created tools like [Penteract](https://github.com/MrColour/penteract) and [SDL_2D_init](https://github.com/MrColour/SDL_2D_init).
