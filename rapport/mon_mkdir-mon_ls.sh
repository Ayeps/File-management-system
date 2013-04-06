(ssh) aroquemaurel@Garp : ~/cours/L2/systeme4/sgf
[0] % mon_mkdir /dir1 ; mon_mkdir /dir2 ; mon_mkdir /dir3 ; mon_mkdir /dir4 ; mon_mkdir /dir5 

(ssh) aroquemaurel@Garp : ~/cours/L2/systeme4/sgf
[0] % mon_ls /
   0 '/' :
   0 '.' :
   1 'dir1' :
   2 'dir2' :
   3 'dir3' :
   4 'dir4' :
   5 'dir5' :
 
(ssh) aroquemaurel@Garp : ~/cours/L2/systeme4/sgf
[0] % mon_affiche_SGF
**********************************
* Systeme de Gestion de Fichiers *
**********************************
Superbloc
nb_max_inoeuds    : 10
taille_du_SF      : 64
taille_bloc       : 64
premier_bloc_libre: 22
Table des inoeuds
0  type  :  2  taille:168 o,  blocs:  9, 12, 19, -1, -1, -1, -1, -1, -1, -1,
1  type  :  2  taille: 72 o,  blocs: 10, 11, -1, -1, -1, -1, -1, -1, -1, -1,
2  type  :  2  taille: 72 o,  blocs: 13, 14, -1, -1, -1, -1, -1, -1, -1, -1,
3  type  :  2  taille: 72 o,  blocs: 15, 16, -1, -1, -1, -1, -1, -1, -1, -1,
4  type  :  2  taille: 72 o,  blocs: 17, 18, -1, -1, -1, -1, -1, -1, -1, -1,
5  type  :  2  taille: 72 o,  blocs: 20, 21, -1, -1, -1, -1, -1, -1, -1, -1,
6  type  :  0  taille:  0 o,  blocs: -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
7  type  :  0  taille:  0 o,  blocs: -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
8  type  :  0  taille:  0 o,  blocs: -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
9  type  :  0  taille:  0 o,  blocs: -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
Liste des blocs libres :
22  23  24  25  26  27  28  29  30  31  32  33  34  35  36  37  38  39  40  
41  42  43  44  45  46  47  48  49  50 51  52  53  54  55  56  57  58  59  
60  61  62  63 

#(ssh) aroquemaurel@Garp : ~/cours/L2/systeme4/sgf
#[0] % mon_mkdir /dir1/sdir1 && mon_mkdir /dir1/sdir1/ssdir1 && mon_mkdir /dir1/sdir1/ssdir1/sssdir1

#(ssh) aroquemaurel@Garp : ~/cours/L2/systeme4/sgf
#[0] % mon_ls /dir1/sdir1/ssdir1
   7 '/dir1/sdir1/ssdir1' :
   7 '.' :
   6 '..' :
   8 'sssdir1' :

#(ssh) aroquemaurel@Garp : ~/cours/L2/systeme4/sgf
#[0] % mon_ls -l /              
   0	  168 o		'/' :
   0 	  168 o		'.' :
   1	   96 o		'dir1' :
   2	   72 o		'dir2' :
   3	   72 o		'dir3' :
   4	   72 o		'dir4' :
   5	   72 o		'dir5' :

