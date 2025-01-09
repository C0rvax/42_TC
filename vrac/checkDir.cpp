
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h> // Pour getpwuid, getuid
#include <pwd.h> // Pour struct passwd

std::string expandTilde(const std::string& path) {
    if (path.empty() || path[0] != '~') {
        return path; // Ne pas faire le remplacement si pas de tilde
    }

    std::string expandedPath;
    if (path.length() == 1 || path[1] == '/') { // Cas de ~ ou ~/chemin
        struct passwd *pw = getpwuid(getuid());
        if (pw != NULL) {
           expandedPath = pw->pw_dir;
           if (path.length() > 1)
           {
               expandedPath += path.substr(1);
           }

        } else {
            //On a pas trouvé l'utilisateur, on retourne le chemin original
            return path;
        }
    } else { // Cas de ~utilisateur/chemin
       size_t pos = path.find("/", 1);
       std::string username = path.substr(1, pos == std::string::npos ? std::string::npos : pos -1 );
       struct passwd *pw = getpwnam(username.c_str());
        if (pw != NULL) {
           expandedPath = pw->pw_dir;
            if (pos != std::string::npos) {
                expandedPath += path.substr(pos);
            }

        } else {
            //On a pas trouvé l'utilisateur, on retourne le chemin original
            return path;
        }
    }

    return expandedPath;
}

std::vector<std::string> listFiles(const std::string& nomdedossier) {
    std::vector<std::string> fichiers;
    DIR* dir;
    struct dirent* ent;
    std::string expand = expandTilde(nomdedossier);
    std::cout << expand << std::endl;

    // Ouverture du dossier
    if ((dir = opendir(expand.c_str())) != NULL) {
        // Lecture des entrées du dossier
        while ((ent = readdir(dir)) != NULL) {
            // Ignorer "." et ".."
            if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                // On teste que c'est un fichier
                if (ent->d_type == DT_REG) {
                // Construction du chemin relatif (nomdedossier/nomdefichier)
                    std::string cheminRelatif = nomdedossier + "/" + ent->d_name;
                    fichiers.push_back(cheminRelatif);
                }
            }
        }
        closedir(dir); // Fermeture du dossier
    } else {
       // Gestion d'erreur si l'ouverture du dossier échoue
        perror(("Impossible d'ouvrir le dossier : " + nomdedossier).c_str());
        // On pourrait lever une exception à la place
    }
    return fichiers;
}


int main() {
    std::string dossier = "~/Documents"; // Exemple : nom du dossier à scanner
//    std::string dossier = "bitShift"; // Exemple : nom du dossier à scanner

    std::vector<std::string> listeFichiers = listFiles(dossier);

    if (listeFichiers.empty()){
        std::cout << "Aucun fichier trouve" << std::endl;
    }else{
        std::cout << "Fichiers trouves :" << std::endl;
        for (size_t i = 0; i < listeFichiers.size(); ++i) {
            std::cout << listeFichiers[i] << std::endl;
        }
    }


    return 0;
}
