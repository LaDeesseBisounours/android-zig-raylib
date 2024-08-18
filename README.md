# Android zig raylib
A simple example of running a zig raylib app in android studio.
This project could run on all architectures but raylib 5.0 does not compile for all of them (zig however is setup to compile to all of them, regardless).

## Running 
### Dependencies
This project depends on:
- zig 0.13.0
- AndroidStudio

### Cloning
Clone this repository in your `AndroidStudioProjects` directory.
Then init submodules (for recursiive cloning of raylib sources).
If you wish to change version of raylib, 
```
cd app/src/main/cpp/
rm -rf raylib/
git clone --depth 1 --branch VERSION_YOU_WANT https://github.com/raysan5/raylib.git
```

### Running
Open your AndroidStudio app, import the project and run it.

