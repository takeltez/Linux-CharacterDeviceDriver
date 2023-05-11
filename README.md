# Linux Character Device Driver

## About
Character device driver for GNU/Linux with user-kernel interraction.

## How to use
<details>
<summary><i>see all Makefile features</i></summary>

	make/make all - build driver
	make dir - create build/modules directories
	make rdir - remove build/modules directories
	make clean - cleanup build/modules directories
	make install - copy driver into modules directory
</details>

- build driver:<br>
`$ make`

- upload driver into kernel:<br>
`$ sudo insmod ./modules/char_dev.ko`

- create character device file associated with driver:<br>
`$ sudo mknod -m 666 /dev/char_dev c 255 0`

## Usage
`$ echo "data" > /dev/char_dev`<br>
`$ cat /dev/char_dev`<br>
`$ data`<br>
`$ echo "new data" > /dev/char_dev`<br>
`$ cat /dev/char_dev`<br>
`$ new data`
