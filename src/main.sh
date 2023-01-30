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
lieu=0
tri=0
date_min=''
date_max=''
date=0

for i in "$@" ; do
  echo "$i"
  if (( $date == 1 )) ; then
    re='^[0-9]+$'
    if [[ $i =~ $re ]] ; then
      date_min="$i"
      date=2
    else
      echo "error"
      exit 0
    fi
  elif (( $date == 2 )) ; then
    re='^[0-9]+$'
    if [[ $i =~ $re ]] ; then
       date_max="$i"
       date=3
    else
      echo "error"
      exit 0
    fi
  else
    case $i in
      '--help')
        echo -e "Utilisation: ./main.sh [OPTION]... [FICHIER]...

  -t[MODE]        Affiche les données sur la température, en fonction du
                  MODE. Avec MODE 1, le minimum, maximum, et la moyenne sont
                  affiché pour chaque station. Avec MODE 2, la moyenne a chaque
                  heure entre toute les stations est affiché. Avec MODE 3, les
                  données sont affiché par heure et par station
  -p[MODE]        Affiche les données sur la pression, en fonction du
                  MODE. Avec MODE 1, le minimum, maximum, et la moyenne sont
                  affiché pour chaque station. Avec MODE 2, la moyenne a chaque
                  heure entre toute les stations est affiché. Avec MODE 3, les
                  données sont affiché par heure et par station
  -F              Utilise uniquement les données de France métropolitaine ou Corse
  -G              Utilise uniquement les données de Guyane Française
  -S              Utilise uniquement les données de Saint-Pierre et Miquelon
  -A              Utilise uniquement les données des Antilles
  -O              Utilise uniquement les données de l'Ocean Indien
  -Q              Utilise uniquement les données d'Antartique
  -d [min] [max]
                  "
        exit 0 ;;
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
      '-F')
        if (( $lieu == O )) ; then
          lieu=1
        else
          echo "error"
          exit 0
        fi;;
      '-G')
        if (( $lieu == O )) ; then
          lieu=2
        else
          echo "error"
          exit 0
        fi;;
      '-S')
        if (( $lieu == O )) ; then
          lieu=3
        else
          echo "error"
          exit 0
        fi;;
      '-A')
        if (( $lieu == O )) ; then
          lieu=4
        else
          echo "error"
          exit 0
        fi;;
      '-O')
        if (( $lieu == O )) ; then
          lieu=5
        else
          echo "error"
          exit 0
        fi;;
      '-Q')
        if (( $lieu == O )) ; then
          lieu=6
        else
          echo "error"
          exit 0
        fi;;
      '--tab')
        if (( $tri == O )) ; then
          tri=1
        else
          echo "error"
          exit 0
        fi;;
      '--abr')
        if (( $tri == O )) ; then
          tri=2
        else
          echo "error"
          exit 0
        fi;;
      '--avl')
        if (( $tri == O )) ; then
          tri=3
        else
          echo "error"
          exit 0
        fi;;
      '-d')
        if (( $date > 2 )) ; then
          echo "error"
          exit 0
        else
          date=1;
        fi
    esac
   fi
done

if (( $t1 == 0 )) && (( $t2 == 0 )) && (( $t3 == 0 )) && (( $p1 == 0 )) && (( $p2 == 0 )) && (( $p3 == 0 )) && (( $w == 0 )) && (( $h == 0 )) && (( $m == 0 )) ; then
  echo "error: no parameter to sort"
  exit 0
fi

if (( $date > 0 )) ; then
  if [[ "$date_min" = "" ]] || [[ "$date_max" = "" ]] ; then
    echo "error: invalid dates"
    exit 0
  fi
fi
