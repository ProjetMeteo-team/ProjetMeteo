#!/bin/bash

t1=0
t2=0
t3=0
p1=0
p2=0
p3=0

for i in "$@" ; do
  echo "$i"
  case $i in
    '--help')
      echo -e "Utilisation: ./main.sh [OPTION]... [FICHIER]...

  -t[MODE]  affiche les données sur la température, en fonction du MODE. Avec MODE 1,
            le minimum, maximum, et la moyenne sont affiché pour chaque"
      return 0 ;;
    'test') ;;
  esac
done
