# Character Device Driver

## About
Character device driver for GNU/Linux.

## Build
From root directory:
- execute `make` command:<br>
	`make`

<details>
<summary><i>See other Makefile features</i></summary>

	make/make all - build project
	make dir - create build/modules directories
	make rdir - remove build/modules directories
	make clean - cleanup build/modules directories
	make install - copy driver file into modules directory
</details>

## Usage
From root directory:
- upload driver `char_dev.ko` into kernel:<br>
`sudo insmod ./modules/char_dev.ko`

- create character device file `char_dev` in `/dev` directory:<br>
`sudo mknod -m 666 /dev/char_dev c 255 0`

- Try to read/write `/dev/char_dev` file:<br>
`cat /dev/char_dev`<br>
`echo 1 > /dev/char_dev`

- extract driver `char_dev.ko` from kernel:<br>
`sudo rmmod char_dev`

- check latests messages from `/var/log/syslog` file:<br>
`tail /var/log/syslog`

<details>
<summary>Output of <i>/var/log/syslog</i> should look like:</summary>

	... ...
	... Function module_upload is being executed
	... Function char_dev_open is being executed
	... Function char_dev_read is being executed
	... Function char_dev_release is being executed
	... Function char_dev_open is being executed
	... Function char_dev_write is being executed
	... Function char_dev_release is being executed
	... Function module_extract is being executed
	... ...
</details>
