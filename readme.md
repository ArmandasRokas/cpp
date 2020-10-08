### Create new project in Visual Studio Code
```
mkdir projects
cd projects
mkdir helloworld
cd helloworld
code .
```
- New file with `.cpp`/`.h` extention

# Build cmd

```
g++ *.cpp -o main.out
```

#### Build using visual studio
- `Terminal` -> `Configure default build tasks` -> `g++ build active file`
- Add `.sh` to `"${fileDirname}/${fileBasenameNoExtension}"`  in line 12
- Come back to `.cpp` file
- `Terminal` -> `Run build task`