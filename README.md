# TP5 

Nathan ANDRE  
Eugénie ROQUAIN  

## Build / Compilation

```sh
cmake -Bbuild TPLecteursEcrivains/
cmake -Bbuild TPThreadsTrains/
```

```sh
cmake --build build/
```

## Lecteur/Ecrivains

Le code fourni est tel que les accès (en lecture ou en écriture) à une ressource partagée ne
sont pas synchronisés de telle façon que des lectures de la valeur de cette ressource peuvent
être incohérentes.

Les règles de cohérence à respecter sont :

    1 - Plusieurs lecteurs peuvent lire en même temps
    2 - Un écrivain doit être seul
        → pas d’autre écrivain
        → pas de lecteur en même temps
    3 - Aucun lecteur ne doit lire pendant qu’un écrivain écrit

La solution implémentée correspond à une politique de priorité aux lecteurs.

Le principe est le suivant :
    - Les lecteurs peuvent accéder à la ressource en concurrence
    - Le premier lecteur bloque l’accès aux écrivains
    - Le dernier lecteur libère l’accès aux écrivains
    - Les écrivains accèdent seuls à la ressource

On utilise deux variables globales : 
    - ressourcePartagee : données partagées entre Lecteur et Ecrivain
    - nbrLecteur : nombre de Lecteur en train de lire

On utilise deux sémaphores :
    - semLecteur : garantie l'accès exclusif au compteur nbrLecteur
    - accesRessource : garantie l'exclusion mutuelle de la ressource paratagée

## Threads Trains
