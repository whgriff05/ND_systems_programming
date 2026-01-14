# Basics and Beginning

Goal of the class: to gain familiarity with the Unix operating system

## The Unix Philosophy
1. Write programs that do __one thing__ and __do it well__
2. Write programs to __work together__
3. Write programs to handle __text streams__, as it is a universal interface

## How the student machines work
- Using a terminal on your local computer, use `ssh` to connect to a remote student machine
- Remote student machine opens a shell (bash), and commands only interact with that remote machine
- Student machines use a Network File System (nfs) so that each machine can function independently if one is affected, but still share contents (a user can use any student machine and have the same user data)
- Student machines have a firewall, they require a vpn to connect if you are not on the same network (eduroam)
