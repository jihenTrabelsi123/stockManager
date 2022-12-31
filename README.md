# stockManager
Dans ce programme : deux modes sont mises en place 
Le premier mode : mode manager qui donne l'accès au manager pour realiser différentes opérations y compris l'ajout d'un nouveau produit dans
la liste des produits avec ses caractéristiques (code produit qui est unique , référence,description et prix ) le manager peut aussi ajouter
des entrées c'est à dire ajouter des quantités aux produits déjà existants , ce mode permet aussi de savoir la liste des produits avec la quantité disponible
le manager peut assi supprimer et modifier un  produit la modification peut être réalisé selon le choix de manager (selon une caractéristique spécifique
(code produit ou reference ou prix ou description ) )
Le manager peut aussi chercher un produit (recherche par code ou par référence)
Ce mode permet à l'utilisateur d'afficher l'historique d'entrée avec les details suivants ; code produit ,date de l'entrée et quantité entrée ainsi que l'historique
de sortie avec les détails suivants code produit la date de l'achat quantité achetée code de la carte de client et finalement le montant total.
L'affichage de l'historique peut se voir par mois année et jour.
Le manager peut consulter la liste des clients qui ont effectué des opérations d'achat 

Le deuxieme mode est le mode client qui sera identifié par le code de son carte , son nom et son prénom, ce mode permet de consulter la liste
des produits disponibles, le client peut effectuer des recherches par code et par références ce dernier peut également effectuer des opérations
d'achat qui vont présenter les sorties de stock cette opération n'est réalisée que si la quantité de stock demandée est disponible et que si le montant 
de l'opération est inférieur ou égal au budget du client après la confirmation de client.