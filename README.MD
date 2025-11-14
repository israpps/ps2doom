# PS2 DOOM
![GitHub Downloads (all assets, all releases)](https://img.shields.io/github/downloads/israpps/ps2doom/total?style=for-the-badge&logo=github&label=Downloads&labelColor=black)


This repository originally corresponded to ps2 port of SDL DOOM made by @lukaszdk

However, he personally [linked in his website](http://lukasz.dk/2008/02/11/doom-playstation-2-port/) to another version by [Jason Yu](http://www.jasonyu.net/), wich has audio support and other toys (eg: USB support)

the new code comes from update 2 at the webside of lukaszdk

## What's new
I have made a few tweaks to it:

- Usage of FILEXIO and IOMANX modules: fixes a very weird bug I had where doom would fail to obtain all the lumps from WAD files (each wad had it's last 3 lumps corrupt/null/mixed with lumps from begining of wad)
- Support for arcade PS2: it should run on NAMCO System246/System256 as well as Konami Python1. the design of the arcade version was made mimicking the file layout of original System246 games, so you could make a DOOM dongle :D
- compiled with PS2DEV v1.0: wich brings up 15 years of PS2SDK enhancements while also allowing CI with github actions
- reboot the I/O processor on boot: more stability, less hangs due to IRX modules from the program that ran the game staying when they should not
- `I_Error` function will no longer exit the program into OSDSYS, instead, error is printed on screen and thread sleeps

## WAD files

get them yourself

## Compiling

to compile the source code, you need PS2DEV v1.0 docker image (`ps2dev/ps2dev:v1.0`)

as well as a modified version of PS2 SDL I made (only if you plan on compiling the arcade version), to get that SDL run `make arcade-sdl`

for compiling PS2DOOM do

```
make clean all -C src
```

for compiling PS2DOOM for Arcade PS2 do 

```
make clean all -C src ARCADE=1
```

(binary will be called `ACDOOM` instead of `DOOM` to avoid overlap with retail targeted binaries)

## arcade dist

the boot.bin file provided in the release package for arcade doom is an already encrypted proverb bootloader, it expects the game ELF to be located at `mc0:ACDOOM`. use it if you prefer Arcade DOOM to be a standalone dongle mimicking the layout of original games

> [!NOTE]
> System2x6 users: if you want to make Arcade DOOM part of a standalone dongle, remember to also provide `ACJVLOAD.IRX` file on the dongle root so that DOOM may load it to initialize the VGA output!