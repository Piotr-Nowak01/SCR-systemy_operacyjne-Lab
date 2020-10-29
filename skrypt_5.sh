#!/bin/sh
trap " echo SIGINT" INT
trap " echo SIGHUP" HUP
trap " echo SIGQUIT" QUIT
trap " echo SIGILL" ILL
trap " echo SIGTRAP" TRAP
trap " echo SIGABRT" ABRT
trap " echo SIGBUS" BUS
trap " echo SIGFPE" FPE
trap " echo DIGKILL" KILL
trap " echo SIGUSR!" USR1
trap " echo SIGSEGV" SEGV
trap " echo SIGUSR2" USR2
trap " echo SIGPIPE" PIPE
trap " echo SIGALRM" ALRM
trap " echo SIGTERM" TERM
while :
do
    date
    sleep 1
done
