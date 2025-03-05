Le projet **My Find** est une réimplémentation simplifiée de la commande UNIX `find`, qui permet de rechercher des fichiers et des répertoires selon divers critères.  

### 🔹 **Objectifs du projet**  
1. **Parcourir un système de fichiers** : Explorer récursivement une arborescence en partant d’un répertoire donné.  
2. **Filtrer les résultats** selon certains critères comme :  
   - Nom du fichier (`-name`)  
   - Type de fichier (`-type`)  
   - Taille (`-size`)  
   - Droits d’accès (`-perm`)  
3. **Respecter la structure et les options UNIX** :  
   - Gérer plusieurs options combinées  
   - Suivre une approche efficace avec des appels système (`opendir`, `readdir`, `stat`, etc.)  
   - Prendre en charge les liens symboliques et les permissions  

### 🔹 **Compétences développées**  
✅ Manipulation des fichiers en C (API POSIX)  
✅ Gestion des structures de données (listes chaînées, tableaux dynamiques)  
✅ Optimisation des parcours récursifs  
✅ Compréhension du fonctionnement des systèmes de fichiers  
