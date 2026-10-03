# Peakasso Language

Peakasso is a small language for painting rectangles on a canvas, implemented with JavaCC.

This is the BIL 395 Programming Language course homework, completed on 21 March 2020. The commits run from 9 February 2020 through that day.

- [M. Said Zengin](https://github.com/msaidzengin)
- [Berkay Ugur Senocak](https://github.com/4turkuaz)

A program sets the canvas size and a cursor, declares rectangular brushes, paints those brushes, then exhibits the canvas. Brush size is width, then height. Cursor positions start at 1. `!!` comments run to the end of the line.

```
PROGRAM picture;
CANVAS-INIT-SECTION :
CONST CanvasX = 20 ; CONST CanvasY = 20 ; CursorX = 1 ; CursorY = 1 ;
BRUSH-DECLARATION-SECTION :
BRUSH box = 2 3 ;
DRAWING-SECTION :
MOVE CursorX TO 4 ;
PAINT-CANVAS box;
EXHIBIT-CANVAS;
```

`MOVE` can also add or subtract with `PLUS` and `MINUS`, as in `MOVE CursorX TO CursorX PLUS 2`.

- `peakasso/` prints the canvas as spaces and `*`.
- `extendedPeakasso/` adds colors, `if` / `else`, `while`, and a Swing window. A brush with no color is black.
- `composePeakasso/` reads an ASCII painting and prints a Peakasso program.

The samples `peakasso/code.txt` and `extendedPeakasso/code.txt` draw a smiley. The brush names are Turkish words: `goz` (eye), `agiz` (mouth), `kas` (eyebrow), and `burun` (nose). Each sample replaces `goz` from the keyboard before painting.

You need JDK 11 or newer (`java` and `javac`). JavaCC writes extra `.java` files beside the grammar; `.gitignore` already ignores them.

```bash
git clone https://github.com/msaidzengin/peakassoLanguage.git
cd peakassoLanguage
```

If you already have the repository, `cd` to its root instead. That is the directory that contains this README. Each section below starts there.

## Run the base language

```bash
cd peakasso
curl -fsSL -o javacc.jar https://repo1.maven.org/maven2/net/java/dev/javacc/javacc/7.0.13/javacc-7.0.13.jar
java -cp javacc.jar javacc peakasso.jj
javac *.java
printf '1 1\n' | java PEAKASSO code.txt
cd ..
```

`code.txt` prints a Turkish prompt and waits for a new width and height for `goz`. The `printf` line answers `1 1`. Output is that prompt, then a 50 by 50 smiley made of `*`.

## Run the extended language

Use a full JDK that includes Swing, and a graphical session. This program creates its window as soon as it starts. From the repository root:

```bash
cd extendedPeakasso
curl -fsSL -o javacc.jar https://repo1.maven.org/maven2/net/java/dev/javacc/javacc/7.0.13/javacc-7.0.13.jar
java -cp javacc.jar javacc PEAKASSO.jj
javac *.java
printf '1 1 BLUE\n' | java PEAKASSO code.txt
```

`RENEW-BRUSH` reads width, height, and one color: `BLACK`, `RED`, `GREEN`, `BLUE`, `YELLOW`, `PINK`, or `ORANGE`. The sample answers `1 1 BLUE`. `EXHIBIT-CANVAS` opens a 600 by 600 window. Closing the window does not stop the process; press Ctrl+C in the terminal, then run `cd ..` before the next section.

`if` / `else` sits in the brush section and chooses one brush definition. `while` sits in the drawing section and changes a brush side, for example `burun.x--` or `goz.x += 3`.

## Compose a program from a painting

`composePeakasso/input.txt` starts with `width height`. The sample is `12 3`: three rows of exactly 12 characters. `*` is painted and a space is empty, including spaces used as padding. From the repository root:

```bash
cd composePeakasso
gcc -o peakasso peakasso.c
./peakasso < input.txt
cd ..
```

`findRectangles.py` is an earlier sketch with a grid written at the bottom of the file. From `composePeakasso/`, `python3 findRectangles.py` prints the rectangles of zeros in that grid. `findRectangles.c` is the same sketch in C. The program that prints Peakasso source is `peakasso.c`.
