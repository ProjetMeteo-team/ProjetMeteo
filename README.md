Météorograph
de Eyal LEVY et Finaritra ANDRIANAJAINA

Il n'a jamais été aussi simple d'illustrer le temps!
Météorograph est une application vous permettant de représenter les données météorologiques en fonction de vos lieux

Comment l'utiliser?

Pour lancer le programme, saisissez la commande suivante dans votre terminal: ./script_meteo.sh

A cela, ajouter au moins une option à afficher parmi:
-t pour représenter la température (voir *)
-p pour représenter la pression atmosphérique (voir *)
-w pour représenter l'orientation et vitesse moyenne du vent
-h pour représenter l'altitude de la localisation dite
-m pour représenter l'humidité maximale de la localisation dite
-d pour repésenter un intervalle entre deux dates
* Ajouter parmi ces options après -t et -p:
°1 pour les températures (ou pressions) minimales, maximales et moyennes par localisation dans l’ordre croissant
°2 pour les températures (ou pressions) moyennes par date/heure, triées dans l’ordre chronologique. La moyenne se fait sur toutes les localisations
°3 pour les températures (ou pressions) par date/heure selon la localisation. Elles seront triées d’abord par ordre chronologique, puis par ordre croissant de l’identifiant de la localisation

Pour sélectionner la localisation, ajouter une option parmi:
-F pour la France métropolitaine
-G pour la Guyane française
-S pour Saint-Pierre et Miquelon
-A pour les Antilles
-O pour l'Océan Indien
-Q pour l'Antarctique

Par exemple si l'utilisateur souhaite afficher un graphique représentant la vitesse moyenne du vent en Guyane française une commande peut ressembler à la suivante: ./script_meteo.sh -w -G
