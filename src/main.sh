#!/bin/bash

t1=0
t2=0
t3=0
p1=0
p2=0
p3=0
w=0
h=0
m=0

for i in "$@" ; do
  echo "$i"
  case $i in
    '--help')
      echo -e "Utilisation: ./main.sh [OPTION]... [FICHIER]...

  -t[MODE]  affiche les données sur la température, en fonction du
            MODE. Avec MODE 1, le minimum, maximum, et la moyenne sont affiché
            pour chaque"
      return 0 ;;
    '-t1')
      t1=1;;
    '-t2')
      t2=1;;
    '-t3')
      t3=1;;
    '-p1')
      p1=1;;
    '-p2')
      p2=1;;
    '-p3')
      p3=1;;
    '-w')
      w=1;;
    '-h')
      h=1;;
    '-m')
      m=1;;
  esac
done
