# Requirements:

	sudo apt-get install rar
	sudo apt-get install unrar
 	sudo apt-get install libgtk-3-dev
Quickly install using the command: ```make```
# USAGE

If you install gi.repository, it gives you the GUI.

	bash attack.sh
Run it normal

	bash atck.sh

# THE SUBJECT 

- File rar(zip)

# THE TARGET 

- Have the password of file rar

# THE APPROACH

- Dictionary attack
- Bruteforce attack

# WHY I USE THAT METHOD

- File rar: don't limit the time you input the password.
- Although it takes a long time, it is effective.

# The information you should give me

- The name of file rar
- The file inside file rar(if you know)
 
**If you give the file inside file rar, it will speed up the calculation.**

# My work

- I generate the dictionary based on the owner of the file rar; it includes: name and birthday. And the other file is a commond password.
- First, I try the password with the lenght from 1 to 2.
- Next, I do with the dictionary.
- Afterwards, I bruteforce with the larger length.


