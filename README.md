# Peakasso Language

Peakasso is a small language for painting rectangles on a canvas, implemented with JavaCC.

This is the BIL 395 Programming Language course homework, completed on 21 March 2020.

- [M. Said Zengin](https://github.com/msaidzengin)
- [Berkay Ugur Senocak](https://github.com/4turkuaz)

## What is here

- `peakasso/` is the base language. `EXHIBIT-CANVAS` prints the canvas as spaces and `*`.
- `extendedPeakasso/` adds brush colors, `if` / `else`, `while`, and opens the canvas in a Swing window.
- `composePeakasso/` reads an ASCII painting and prints a Peakasso program that redraws it.

Sample programs are `peakasso/code.txt` and `extendedPeakasso/code.txt`. Lines that start with `!!` are comments.

## Requirements

- JDK 11 or newer
- JavaCC 7.0.13 (the commands below download the jar)
- GCC, only for `composePeakasso`
- A desktop session with Swing available, only for `extendedPeakasso`

## Run the base language

`code.txt` paints a smiley. `RENEW-BRUSH` reads a new brush width and height from standard input. The comment in the sample says to enter `1 1`.

```bash
cd peakasso
curl -fsSL -o javacc.jar https://repo1.maven.org/maven2/net/java/dev/javacc/javacc/7.0.13/javacc-7.0.13.jar
java -cp javacc.jar javacc peakasso.jj
javac *.java
printf '1 1\n' | java PEAKASSO code.txt
```

## Run the extended language

`RENEW-BRUSH` reads width, height, and a color: `BLACK`, `RED`, `GREEN`, `BLUE`, `YELLOW`, `PINK`, or `ORANGE`. The sample expects `1 1 BLUE`. `EXHIBIT-CANVAS` opens a window; close it to exit.

```bash
cd extendedPeakasso
curl -fsSL -o javacc.jar https://repo1.maven.org/maven2/net/java/dev/javacc/javacc/7.0.13/javacc-7.0.13.jar
java -cp javacc.jar javacc PEAKASSO.jj
javac *.java
printf '1 1 BLUE\n' | java PEAKASSO code.txt
```

## Compose a program from a painting

`composePeakasso/input.txt` starts with `width height`. Each following line is one row of the canvas: `*` is painted and a space is empty.

```bash
cd composePeakasso
gcc -o peakasso peakasso.c
./peakasso < input.txt
```

`findRectangles.c` and `findRectangles.py` are earlier rectangle-finding sketches. The composer that prints Peakasso source is `peakasso.c`.
