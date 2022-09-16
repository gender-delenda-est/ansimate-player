# ansimate-player
a small program for reading and playing back ascii/ansi animations in the terminal

ansimate reads in a file containing the frames of the animation formatted as follows:

- the file should start with a single newline
- each frame should be separated by a line containing a single '%' character

# requirements
- an ANSI- and VT100-compliant terminal

# usage
use `ansimate [FILE]` to play the file back

the `sprite.ans` file provided is an example in the correct format
