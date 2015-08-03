# renderer.gua
Software 3D Renderer in C++ on Windows, OSX and Linux or other popular flavors of Unix that SDL supports

## Screenshots
![Jelly Cube](https://raw.githubusercontent.com/guaxiao/renderer.gua/dev/screenshots/jellycube.png)
![Illidan Wireframe](https://raw.githubusercontent.com/guaxiao/renderer.gua/dev/screenshots/illidan_wireframe.png)
![Illidan](https://raw.githubusercontent.com/guaxiao/renderer.gua/dev/screenshots/illidan.png)


## Usage

### OS X
```
open projects/Xcode6/renderer.gua.xcodeproj
build and run

```
or
```shell
# install library
sh install_mac_sdl.sh 

# build from command line
make osx

# run
./gua3d
```

### Windows (MinGW32)
```shell
build_win_mingw.bat
gua3d
```

### Windows (Visual Studio 2013 / Visual Studio 2015)
double click `projects/vs2013/renderer.gua.sln` or `projects/vs2015/renderer.gua.sln`

then press `F5` or `Ctrl + F5` to lunch it

note: 

1. `Release` is much faster

2. `Debug` config will have a console window, `Release` config won't

tested with `vs2013` under `winodws 8.1` and `vs2015` under `windows 10`

### Linux
```shell
# Depends on libsdl1.2-dev. For Ubuntu: sudo apt-get install libsdl1.2-dev.
make linux
./gua3d
```

## Licence
Apache 2.0

