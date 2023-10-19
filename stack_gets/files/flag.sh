#!/bin/bash
echo $FLAG > /home/ctf/flag
export FLAG=not_flag
FLAG=not_flag
chmod 444 /home/ctf/flag
chmod 777 /home/ctf/pwn
