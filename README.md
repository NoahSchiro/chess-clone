# Chess clone

The absolutely novel idea of creating a chess clone. Target language is C++ and I will attempt to keep it as true to C++ standards as possible. Part of the emphasis of this project is good documentation, code structure, and good practices all around. Extensive unit testing will be written.

What this repository currently can do.

Once build and ran, starts a chess game in the normal state. Players take turns selecting pieces and then moving these pieces to valid move locations. Currently the game does not register checks, checkmates, en passant, pawn promotion, castling, or any notion of a game being over. The board also does not yet flip to the perspective of the person who goes next. These will be addressed in the immediate future.

## Dependencies
One of the design philosophies of this project is to make it fast, close to hardware, and with minimal dependencies. That being said, playing chess in the terminal isn't too fun. SDL2 is GUI libarary which provides a compromise. SDL2_Image is also required. If you don't have it already:
    
    sudo apt install libsdl2
    sudo apt install libsdl2-image-2.0-0-dev
    
    # Make is also used to build this project (many systems have this already!)
    sudo apt install make

## Download and run
---

Long term goals:

 - [ ] Create chess game that can be played in a standard way. Two players
 - [ ] Create an A* search algorithm AI
 - [ ] Experiment with other AI ideas  
