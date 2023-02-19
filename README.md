# pipex

In this project I discovered a UNIX mechanism "pipe" in detail.


## Build
Run this command to build the library excluding the bonus functions:
```sh
$ make
```
Run this command to build the library including the bonus functions:
```sh
$ make bonus
```
##Mandatory Part
If you run pipex like this:
```sh
$> ./pipex file1 cmd1 cmd2 file2
```
It would behave exactly the same as the shell command below:
```sh
$> < file1 cmd1 | cmd2 > file2
```
And errors have been handled as well.

##Bonus Part

###Firt part of the Bonus
Pipex can handle multiple pipes if you run it like this:
```sh
$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
It would behave exactly the same as the shell command below:
```sh
$> < file1 cmd1 | cmd2 | cmd3 | ... | cmdn > file2
```
###Second part of the Bonus
Pipex will support « and » when the first parameter is "here_doc". You should run it like this:
```sh
$> ./pipex here_doc LIMITER cmd1 cmd2 file2
```
And it would behave exactly like this shell command:
```sh
$> cmd1 << LIMITER | cmd2 >> file2
```

**Note:** Francinette doesn't run against the original Makefile for bonus functions. For more details, see [Makefile](./Makefile#L33).
## Result
![Score: 125/100](./score.png)

## License
[MIT License](./LICENSE)
