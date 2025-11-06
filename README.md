# Minecraft Stronghold Calculator
## Why use this?
Idk, there are other programs that do this, i just wanted to make it.
This is command line though, if that sounds nice to you.

## How to build
run build.sh or do
```sh
mkdir build
gcc main.c -o build/minecraft_stronghold_calc -lm
```

## How to run
1. Throw eye of ender and look at it when you throw it (low fov makes this more accurate)
2. Press F3+C to copy location and look data to clipboard
3. Paste it as an argument to the command from the command line (do not run it yet)
4. Run some distance perpendicular to the thrown angle
5. Run steps 1-3 again, pasting after the existing command

Now your command should look something like this:
```sh
./minecraft_stronghold_calc /execute in minecraft:overworld run tp @s 9234.58 63.00 1884.17 811.04 -31.83 /execute in minecraft:overworld run tp @s 9248.20 67.00 1634.48 82.69 -31.64
```

When you run the command, it will tell you the stronghold coordinates in the overworld and the nether.

## Thanks
Thanks to **[CoPokBl](https://github.com/CoPokBl/)** for helping with the maths!
