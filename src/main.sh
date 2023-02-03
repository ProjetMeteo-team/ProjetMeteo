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
fichier=0
fic=''

for i in "$@" ; do
  echo "$i"
  if (( $date == 1 )) ; then
    if grep -qE '^[0-9]{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1])$' <<< "$i" ; then #i have no idea what this does so i'm trusting stackoverflow
      date_min="$i"
      date=2
    else
      echo "error"
      exit 1
    fi
  elif (( $date == 2 )) ; then
    if grep -qE '^[0-9]{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1])$' <<< "$i" ; then
       date_max="$i"
       date=3
    else
      echo "error"
      exit 1
    fi
  elif (( $fichier == 1 )) ; then
    if [ -f $i ] && [ -r $i ] ; then
       fic="$i"
       fichier=2
    else
      echo "error"
      exit 1
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
        exit 1 ;;
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
          exit 1
        fi;;
      '-G')
        if (( $lieu == O )) ; then
          lieu=2
        else
          echo "error"
          exit 1
        fi;;
      '-S')
        if (( $lieu == O )) ; then
          lieu=3
        else
          echo "error"
          exit 1
        fi;;
      '-A')
        if (( $lieu == O )) ; then
          lieu=4
        else
          echo "error"
          exit 1
        fi;;
      '-O')
        if (( $lieu == O )) ; then
          lieu=5
        else
          echo "error"
          exit 1
        fi;;
      '-Q')
        if (( $lieu == O )) ; then
          lieu=6
        else
          echo "error"
          exit 1
        fi;;
      '--tab')
        if (( $tri == O )) ; then
          tri=1
        else
          echo "error"
          exit 1
        fi;;
      '--abr')
        if (( $tri == O )) ; then
          tri=2
        else
          echo "error"
          exit 1
        fi;;
      '--avl')
        if (( $tri == O )) ; then
          tri=3
        else
          echo "error"
          exit 1
        fi;;
      '-d')
        if (( $date > 2 )) ; then
          echo "error"
          exit 1
        else
          date=1
        fi;;
      '-f')
        if (( $fichier > 0 )) ; then
          echo "error"
          exit 1
        else
          fichier=1
        fi;;
    esac
   fi
done

if (( $t1 == 0 )) && (( $t2 == 0 )) && (( $t3 == 0 )) && (( $p1 == 0 )) && (( $p2 == 0 )) && (( $p3 == 0 )) && (( $w == 0 )) && (( $h == 0 )) && (( $m == 0 )) ; then
  echo "error: no parameter to sort"
  exit 1
fi

if (( $date > 0 )) ; then
  if [[ "$date_min" = "" ]] || [[ "$date_max" = "" ]] ; then
    echo "error: invalid dates"
    exit 1
  fi
fi

if (( $fichier < 1 )) || [[ "$fic" = "" ]] ; then
  echo "error: no file specified"
  exit 1
fi

#echo "copie"
cp -f "$fic" "${fic%.*}_test.${fic##*.}"
sed -i '1d' "${fic%.*}_test.${fic##*.}"

#thanks chatgpt for explaining how awk works
case $lieu in
  0)
    echo "no area selected";;
  1)
    echo "France"
    awk -F ';' '{split($10,x,","); if ((x[1]>41 && x[1]<51) && (x[2]>-5 && x[2]<9)) print $0;}' "${fic%.*}_test.${fic##*.}" > "${fic%.*}_test2.${fic##*.}";;
  2)
    echo "Guyane Francaise"
    #awk -F ';' '{split($10,x,","); if ((x[1]>41 && x[1]<51) && (x[2]>-5 && x[2]<9)) print $0;}' "${fic%.*}_test.${fic##*.}" > "${fic%.*}_test2.${fic##*.}"
    ;;
  3)
    echo "Saint-Pierre et Miquelon"
    #awk -F ';' '{split($10,x,","); if ((x[1]>41 && x[1]<51) && (x[2]>-5 && x[2]<9)) print $0;}' "${fic%.*}_test.${fic##*.}" > "${fic%.*}_test2.${fic##*.}"
    ;;
  4)
    echo "Antilles"
    #awk -F ';' '{split($10,x,","); if ((x[1]>41 && x[1]<51) && (x[2]>-5 && x[2]<9)) print $0;}' "${fic%.*}_test.${fic##*.}" > "${fic%.*}_test2.${fic##*.}"
    ;;
  5)
    echo "Ocean Indien"
    #awk -F ';' '{split($10,x,","); if ((x[1]>41 && x[1]<51) && (x[2]>-5 && x[2]<9)) print $0;}' "${fic%.*}_test.${fic##*.}" > "${fic%.*}_test2.${fic##*.}"
    ;;
  6)
    echo "Antartique"
    #awk -F ';' '{split($10,x,","); if ((x[1]>41 && x[1]<51) && (x[2]>-5 && x[2]<9)) print $0;}' "${fic%.*}_test.${fic##*.}" > "${fic%.*}_test2.${fic##*.}"
    ;;
esac

if (( $date == 3 )) ; then
  awk -F ";" -v min="$date_min" -v max="$date_max" '{split($2,x,"T"); if (x[1] >= min && x[1] <= max) print $0;}' "${fic%.*}_test2.${fic##*.}" > "${fic%.*}_test3.${fic##*.}"
fi
