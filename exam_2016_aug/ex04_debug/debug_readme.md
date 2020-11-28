- Terminal -> Configure Default Build tasks -> g++ build active file
- In `task.json`

```json
			"args": [
				"-g",
				"${workspaceFolder}/*.cpp",
				"-o",
				"${fileDirname}/${fileBasenameNoExtension}"
			]
```

- Run -> Start debugging 
- In `launch.json`

```json
"program": "${fileDirname}/${fileBasenameNoExtension}",
```
